
#include <Adafruit_VL53L0X.h>

/*
#include <vl53l0x_api.h>
#include <vl53l0x_api_calibration.h>
#include <vl53l0x_api_core.h>
#include <vl53l0x_api_ranging.h>
#include <vl53l0x_api_strings.h>
#include <vl53l0x_def.h>
#include <vl53l0x_device.h>
#include <vl53l0x_i2c_platform.h>
#include <vl53l0x_interrupt_threshold_settings.h>
#include <vl53l0x_platform.h>
#include <vl53l0x_platform_log.h>
#include <vl53l0x_tuning.h>
#include <vl53l0x_types.h>
*/



#include <Network.h>
#include <NetworkClient.h>
#include <NetworkEvents.h>
#include <NetworkInterface.h>
#include <NetworkManager.h>
#include <NetworkServer.h>
#include <NetworkUdp.h>


/*
#include <Modbus.h>
#include <ModbusIP_ESP32.h>
*/


#include <Modbus.h>
#include <ModbusAPI.h>
#include <ModbusEthernet.h>
#include <ModbusIP_ESP8266.h>
#include <ModbusRTU.h>
#include <ModbusSettings.h>
#include <ModbusTCP.h>
#include <ModbusTCPTemplate.h>
#include <ModbusTLS.h>
#include <darray.h>


#include <Arduino.h>
#include <WiFi.h>

//const int HREG = 10;
//const int SENSOR_IREG = 20;
const int HREG_US_F = 15;
const int HREG_US_R = 16;
const int HREG_TOF = 17;

// Motor Pins: assume IN1&2 for drive, IN3&4 for steering
#define IN1 14
#define IN2 27
#define IN3 26
#define IN4 25

// Modbus Registers Offsets
const int driveMotorReg = 40;
const int steerMotorReg = 50;

const int stopWallReg = 60;
const int autoSteerReg = 90;
const int usDistanceReg = 70;
const int usHeadingReg = 80;

// ModbusIP object
ModbusIP mb;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int PIN_TRIG_F = 19;
const int PIN_ECHO_F = 18;

const int PIN_TRIG_R = 17;
const int PIN_ECHO_R = 16;

int readUltrasonic(int PIN_TRIG, int PIN_ECHO, int a) 
{
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
 
  int duration_us = pulseIn(PIN_ECHO, HIGH);
  int distance_cm = 0.017 * duration_us;
  
  //Serial.println("distance (cm) measured by US ");
  /*
  if (a == 1)
  {
    Serial.println("distance (cm) measured by front US sensor is :");
  }
  else if (a == 2)
  {
    Serial.println("distance (cm) measured by rear US sensor is :");
  }
  //Serial.printF(" is : ")
  Serial.println(distance_cm);
  Serial.println(" ");
 */

  return distance_cm;
}

int averageUltrasonic(int PIN_TRIG, int PIN_ECHO, int a, int count)
{
  long total = 0;
  
  for (int i = 0; i < count; i++)
  {
    total += readUltrasonic(PIN_TRIG, PIN_ECHO, a);
    delay(5);
  }

  return total / count;
}

// Drive control

void steer_control(int status)
{
  switch (status)
  {
    case 0:
    // STOP
    Serial.println("Drive motor: Stop");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    break;
    case 1:
    // Direction 1
    Serial.println("Drive motor: Dir_1");
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    break;
    case 2:
    // Direction 2
    Serial.println("Drive motor: Dir_2");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    break;
  }
}

// Steer control 

void drive_control(int status)
{
  switch (status)
  {
    case 0:
    // STOP
    Serial.println("Steer motor: Stop");
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    break;
    case 1:
    // Direction 1
    Serial.println("Steer motor: Dir_1");
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    break;
    case 2:
    // Direction 2
    Serial.println("Steer motor: Dir_2");
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    break;
  }
}

void stopWall()
{
  if (mb.Hreg(driveMotorReg) == 0 && mb.Hreg(steerMotorReg) == 0)
  {
    drive_control(1);

    while (true)
    {
      if (lox.readRange() <= 450)
      {
        drive_control(2);
        delay(20);
        drive_control(0);
        break;
      }
    }
    
  }
}


void setup() 
{
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  
  WiFi.begin("BRILLAPTOP", "figureitout");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("Wifi not connected yet. ");
  }

  Serial.println("");
  Serial.println("Wifi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  mb.server();

    // Setup Motor pins as output : to provide control signal to the motor driver
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Setup ModBus : For Remote Control
  mb.addHreg(driveMotorReg, 0);
  mb.addHreg(steerMotorReg, 0);

  mb.addHreg(stopWallReg, 0);
  mb.addHreg(autoSteerReg, 0);
  mb.addHreg(usDistanceReg, 0);
  mb.addHreg(usHeadingReg, 0);

  

  pinMode(PIN_TRIG_F, OUTPUT);
  pinMode(PIN_ECHO_F,INPUT);
  pinMode(PIN_TRIG_R, OUTPUT);
  pinMode(PIN_ECHO_R,INPUT);

  mb.addHreg(HREG_US_F, readUltrasonic(PIN_TRIG_F,PIN_ECHO_F, 1));
  mb.addHreg(HREG_US_R, readUltrasonic(PIN_TRIG_R,PIN_ECHO_R, 2));
  mb.addHreg(HREG_TOF, 0);

    // wait until serial port opens for native USB devices
  while (! Serial) 
  {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) 
  {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();
}

void loop() {
  // put your main code here, to run repeatedly:

  mb.task();

  //if (!lox.begin())
  //{
  //  lox.startRangeContinuous();
  //}

  mb.Hreg(HREG_US_F, readUltrasonic(PIN_TRIG_F,PIN_ECHO_F, 1));
  mb.Hreg(HREG_US_R, readUltrasonic(PIN_TRIG_R,PIN_ECHO_R, 2));

  int usDistance = (readUltrasonic(PIN_TRIG_F,PIN_ECHO_F, 1) + readUltrasonic(PIN_TRIG_R,PIN_ECHO_R, 2))/2;
  int usHeading = readUltrasonic(PIN_TRIG_F,PIN_ECHO_F, 1) - readUltrasonic(PIN_TRIG_R,PIN_ECHO_R, 2);

  mb.Hreg(usDistanceReg, usDistance);
  mb.Hreg(usHeadingReg, usHeading);

  /*
  Serial.println("this is heading : ");
  Serial.println(usHeading);
  Serial.println(" ");
  */                                                      
                    
  if (lox.isRangeComplete()) 
  {
    Serial.print("Distance in mm: ");
    Serial.println(lox.readRange());
  }
  
  mb.Hreg(HREG_TOF, lox.readRange());

  drive_control(mb.Hreg(driveMotorReg));
  
  if (mb.Hreg(autoSteerReg) == 0)
  {
    steer_control(mb.Hreg(steerMotorReg));
  }
  
  if (mb.Hreg(stopWallReg) == 1)
  {
    stopWall();
    mb.Hreg(stopWallReg, 0);
  }

  if (mb.Hreg(autoSteerReg) == 1)
  {
    if (usHeading < -1)
    {
      steer_control(2);
    }
    else if(usHeading > 1)
    {
      steer_control(1);
    }
    else
    {
      steer_control(0);
    }
  }

  delay(10);
}




