#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modbus-tcp.h"
#include "modbus.h"


#include <QIntValidator>
#include <QSettings>
#include <QScrollBar>
#include <QDebug>
#include <errno.h>
#include <qcustomplot.h>
#include <QFile>

const int DataTypeColumn = 0;
const int AddrColumn = 1;
const int DataColumn = 2;

extern MainWindow * globalMainWin;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_tcpModbus(NULL),
    m_tcpActive(false),
    m_poll(false)
{
    ui->setupUi(this);

    refreshRate = new QTimer(this);
    connect(refreshRate, SIGNAL(timeout()), this, SLOT(sendTcpRequest()));

    distanceUpdate = new QTimer (this);
    graphXCount = 0;
    connect(distanceUpdate, SIGNAL(timeout()), this, SLOT(updateGraphDistance()));

    headingUpdate = new QTimer (this);
    connect(headingUpdate, SIGNAL(timeout()), this, SLOT(updateGraphHeading()));

    frontUpdate = new QTimer (this);
    connect(frontUpdate, SIGNAL(timeout()), this, SLOT(updateGraphFront()));

    outWriteTimer = new QTimer (this);
    connect(outWriteTimer, SIGNAL(timeout()), this, SLOT(logOut()));

    autoTimer = new QTimer(this);
    connect(autoTimer, SIGNAL(timeout()), this, SLOT(controlCenter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tcpEnable_clicked(bool checked)
{
    enableTCPEdit(true);
    if(checked)
    {
        refreshRate->setInterval(ui->refreshRateEdit->text().toInt());
        refreshRate->start();
        m_tcpActive = true;
        enableTCPEdit(false);
    }
    else
    {
        refreshRate->stop();
        enableTCPEdit(false);
    }
}


void MainWindow::enableTCPEdit(bool checked)
{
    ui->edNetworkAddress->setEnabled(checked);
    ui->edPort->setEnabled(checked);
    ui->refreshRateEdit->setEnabled(checked);
}

void MainWindow::tcpConnect()
{
    int portNbr = ui->edPort->text().toInt();
    changeModbusInterface(ui->edNetworkAddress->text(), portNbr);
}

int MainWindow::setupModbusPort()
{
    return 0;
}

static QString descriptiveDataTypeName( int funcCode )
{
    switch( funcCode )
    {
    case MODBUS_FC_READ_COILS:
    case MODBUS_FC_WRITE_SINGLE_COIL:
    case MODBUS_FC_WRITE_MULTIPLE_COILS:
        return "Coil (binary)";
    case MODBUS_FC_READ_DISCRETE_INPUTS:
        return "Discrete Input (binary)";
    case MODBUS_FC_READ_HOLDING_REGISTERS:
    case MODBUS_FC_WRITE_SINGLE_REGISTER:
    case MODBUS_FC_WRITE_MULTIPLE_REGISTERS:
        return "Holding Register (16 bit)";
    case MODBUS_FC_READ_INPUT_REGISTERS:
        return "Input Register (16 bit)";
    default:
        break;
    }
    return "Unknown";
}


void MainWindow::changeModbusInterface(const QString& address, int portNbr )
{
    if (m_tcpModbus)
    {
        modbus_close(m_tcpModbus);
        modbus_free(m_tcpModbus);
        m_tcpModbus = NULL;
    }

    m_tcpModbus = modbus_new_tcp( address.toLatin1().constData(), portNbr);
    if(modbus_connect(m_tcpModbus) == -1)
    {
        if (m_tcpModbus)
        {
            emit connectionError(tr ("Could not connect to TCP/IP Port!"));

            modbus_close(m_tcpModbus);
            modbus_free(m_tcpModbus);
            m_tcpModbus = NULL;
        }
    }

}

void MainWindow::sendTcpRequest(void)
{

    if(m_tcpActive)
    {
        tcpConnect();
    }
    if(m_tcpModbus == NULL)
    {
        ui->connectionStatus->setText("Not Connected");
        return;
    }

    ui->connectionStatus->setText("Connection Established");
    const int slave = ui->slaveId->value();
    const int func = 04;
    const int addr = ui->addressReg->value();
    int num = ui->coilNum->value();
    uint8_t dest[1024];
    uint16_t * dest16 = (uint16_t *) dest;

    memset(dest, 0, 1024);

    int ret = -1;
    bool is16Bit = false;
    const QString dataType = descriptiveDataTypeName(func);

    modbus_set_slave(m_tcpModbus, slave);

    ret = modbus_read_registers( m_tcpModbus, addr, num, dest16);
    is16Bit = true;
    //ui->debugLabel->setText();
    if(ret == num)
    {
        bool b_hex = ui->checkBoxHexDisplay->isChecked();
        QString qs_num;
        ui->regTable->setRowCount( num );

        for(int i = 0; i < num; ++i)
        {
            int16_t data = is16Bit ? static_cast<int16_t>(dest16[i]) : static_cast<int8_t>(dest[i]);

            QTableWidgetItem * dtItem =
                new QTableWidgetItem( dataType );
            QTableWidgetItem * addrItem =
                new QTableWidgetItem ( QString::number( addr+i ) );
            qs_num = QString::asprintf( b_hex ? "0x%04x" : "%d", data);
            QTableWidgetItem * dataItem =
                new QTableWidgetItem( qs_num );
            dtItem->setFlags(dtItem->flags() &
                             ~Qt::ItemIsEditable);
            addrItem->setFlags(addrItem->flags() &
                             ~Qt::ItemIsEditable);
            dataItem->setFlags( dataItem->flags() &
                              ~Qt::ItemIsEditable);

            ui->regTable->setItem(i, DataTypeColumn, dtItem);
            ui->regTable->setItem(i, AddrColumn, addrItem);
            ui->regTable->setItem(i, DataColumn, dataItem);
            //ui->textBrowser->append(QString(qs_num));

        }

        ui->regTable->resizeColumnToContents(0);
        ui->debugLabel->setText("Receive Success");
    }
    else
    {
    ui->debugLabel->setText("Receive Error");
    }
}

void MainWindow::setStatusError(const QString &msg)
{
    m_statusText->setText( msg );
    m_statusInd->setStyleSheet("background: red");
    m_statusTimer->start( 2000 );
}


//---------------Basic Functions (individual motors)---------------
void MainWindow::stop()
{
    modbus_write_register(m_tcpModbus, 40, 0);
}

void MainWindow::forward()
{
    modbus_write_register(m_tcpModbus, 40, 1);
}

void MainWindow::backward()
{
    modbus_write_register(m_tcpModbus, 40, 2);
}

void MainWindow::straight()
{
    modbus_write_register(m_tcpModbus, 50, 0);
}

void MainWindow::right()
{
    modbus_write_register(m_tcpModbus, 50, 1);
}

void MainWindow::left()
{
    modbus_write_register(m_tcpModbus, 50, 2);
}


//--------------------Movement Buttons--------------------
void MainWindow::on_radioGo_0_clicked(bool checked)
{
    stop();
}

void MainWindow::on_radioGo_1_clicked(bool checked)
{
    forward();
}

void MainWindow::on_radioGo_2_clicked(bool checked)
{
    backward();
}

void MainWindow::on_radioTurn_0_clicked(bool checked)
{
    straight();
}

void MainWindow::on_radioTurn_1_clicked(bool checked)
{
    right();
}

void MainWindow::on_radioTurn_2_clicked(bool checked)
{
    left();
}


//---------------Forward until Wall button---------------
void MainWindow::on_pushButton_2_clicked()
{
    modbus_write_register(m_tcpModbus, 60, 1);
}


//-----------------------------------Graph Plottings-----------------------------------
void MainWindow::updateGraphDistance()
{
    const int slave = ui->slaveId->value();
    int16_t distance;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 70, 1, reinterpret_cast<uint16_t*>(&distance));

    if (check == 1)
    {
        ui->widget->graph(0)->addData(graphXCount, distance);
        ui->widget->graph(0)->rescaleAxes();
        ui->widget->replot();
        graphXCount++;

        if (graphXCount >= 100)
        {
            distanceUpdate->stop();
        }
    }

}

void MainWindow::updateGraphHeading()
{
    const int slave = ui->slaveId->value();
    int16_t heading;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 80, 1, reinterpret_cast<uint16_t*>(&heading));

    if (check == 1)
    {
        ui->widget->graph(0)->addData(graphXCount, heading);
        ui->widget->graph(0)->rescaleAxes();
        ui->widget->replot();
        graphXCount++;

        if (graphXCount >= 100)
        {
            headingUpdate->stop();
        }
    }

}

void MainWindow::updateGraphFront()
{
    const int slave = ui->slaveId->value();
    int16_t front;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 17, 1, reinterpret_cast<uint16_t*>(&front));

    if (check == 1)
    {
        ui->widget->graph(0)->addData(graphXCount, front);
        ui->widget->graph(0)->rescaleAxes();
        ui->widget->replot();
        graphXCount++;

        if (graphXCount >= 100)
        {
            frontUpdate->stop();
        }
    }

}

void MainWindow::on_radioButton_clicked(bool checked)
{
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("Time (seconds)");
    ui->widget->yAxis->setLabel("Distance (cm)");
    ui->widget->xAxis->setRange(0, 100);
    ui->widget->yAxis->setRange(0, 50);

    graphXCount = 0;
    distanceUpdate->start(1000);
}




void MainWindow::on_radioButton_2_clicked(bool checked)
{
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("Time (seconds)");
    ui->widget->yAxis->setLabel("Heading (cm)");
    ui->widget->xAxis->setRange(0, 100);
    ui->widget->yAxis->setRange(0, 50);

    graphXCount = 0;
    headingUpdate->start(1000);
}


void MainWindow::on_radioButton_3_clicked()
{
    ui->widget->clearGraphs();
    graphXCount = 0;
    headingUpdate->stop();
    distanceUpdate->stop();
    frontUpdate->stop();
    ui->widget->replot();
}


void MainWindow::on_radioButton_4_clicked(bool checked)
{
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("Time (seconds)");
    ui->widget->yAxis->setLabel("Front Distance (mm)");
    ui->widget->xAxis->setRange(0, 100);
    ui->widget->yAxis->setRange(0, 50);

    graphXCount = 0;
    frontUpdate->start(1000);
}



//-------------------Auto Steer------------------------
void MainWindow::on_radioButton_6_clicked(bool checked)
{
    modbus_write_register(m_tcpModbus, 90, 1);
}

void MainWindow::on_radioButton_5_clicked(bool checked)
{
    modbus_write_register(m_tcpModbus, 90, 0);
}


//----------------Output to File-----------------------
void MainWindow::outWrite(QString filename, int output)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        qDebug() << "failed to open: " << filename << "Error: " << file.errorString();
        return;
    }

    QTextStream out(&file);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    out << timestamp << "   -   " << "This sensor reads: " << output << "\n";
}

void MainWindow::outRead(QString filename, int output)
{

}


void MainWindow::writeUSF()
{
    QString outUSF = "outUSF.txt";
    qDebug() << outUSF;
    const int slave = ui->slaveId->value();
    int16_t usf;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 15, 1, reinterpret_cast<uint16_t*>(&usf));

    if (check == 1)
    {
        outWrite(outUSF, usf);
    }
}


void MainWindow::writeUSR()
{
    QString outUSR = "outUSR.txt";
    const int slave = ui->slaveId->value();
    int16_t usr;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 16, 1, reinterpret_cast<uint16_t*>(&usr));

    if (check == 1)
    {
        outWrite(outUSR, usr);
    }
}


void MainWindow::writeTOF()
{
    QString outFront = "outFront.txt";
    const int slave = ui->slaveId->value();
    int16_t front;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 17, 1, reinterpret_cast<uint16_t*>(&front));

    if (check == 1)
    {
        outWrite(outFront, front);
    }
}


void MainWindow::writeDistance()
{
    QString outDistance = "outDistance.txt";
    const int slave = ui->slaveId->value();
    int16_t distance;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 70, 1, reinterpret_cast<uint16_t*>(&distance));

    if (check == 1)
    {
        outWrite(outDistance, distance);
    }
}


void MainWindow::writeHeading()
{
    QString outHeading = "outHeading.txt";
    const int slave = ui->slaveId->value();
    int16_t heading;
    modbus_set_slave(m_tcpModbus, slave);

    int check = modbus_read_registers(m_tcpModbus, 80, 1, reinterpret_cast<uint16_t*>(&heading));

    if (check == 1)
    {
        outWrite(outHeading, heading);
    }
}

void MainWindow::logOut()
{
    if (ui->checkBox->isChecked())
    {
        writeUSF();
    }

    if(ui->checkBox_2->isChecked())
    {
        writeUSR();
    }

    if(ui->checkBox_3->isChecked())
    {
        writeTOF();
    }

    if(ui->checkBox_4->isChecked())
    {
        writeDistance();
    }

    if(ui->checkBox_5->isChecked())
    {
        writeHeading();
    }
}


void MainWindow::on_checkBox_6_clicked(bool checked)
{
    if (checked)
    {
        outWriteTimer->start(500);
    }
    else
    {
        outWriteTimer->stop();
    }
}

//------------------------------------Autonomous Testing------------------------------------

/*
 *      FRONT       |       HEADING     |       DISTANCE        |       ACTION
 *      > Save      |       > 0         |       > Target        |       forwardRight()
 *                  |                   |       < Target        |       forwardLeft()
 *                  |                   |       == Target       |       forwardStraight()
 *                  |       < 0         |       > Target        |       forwardRight()
 *                  |                   |       < Target        |       forwardLeft()
 *                  |                   |       == Target       |       forwardStraight()
 *                  |       == 0        |       > Target        |       forwardRight()
 *                  |                   |       < Target        |       forwardLeft()
 *                  |                   |       == Target       |       forwardStraight()
 *      < Save      |                   |       > WallCheck     |       forwardRight()
 *                  |                   |       <= WallCheck    |       stop()                 
 */


void MainWindow::moveLogic(int action)
{
    switch (action)
    {
    case 0:
        stop();
        break;
    case 1:
        forward();
        right();
        break;
    case 2:
        forward();
        left();
        break;
    case 3:
        forward();
        straight();
        break;
    case 4:
        backward();
        right();
        break;
    case 5:
        backward();
        left();
        break;
    case 6:
        backward();
        straight();
        break;
    }
}

void MainWindow::controlCenter()
{
    const int slave = ui->slaveId->value();
    int16_t front, distance, heading;
    modbus_set_slave(m_tcpModbus, slave);
    
    int stopsafe = 1000;
    int safe = 1500;
    int target = 30;
    int notsafetarget = 15;
    int wallCheck = 50;
    
    int checkFront = modbus_read_registers(m_tcpModbus, 17, 1, reinterpret_cast<uint16_t*>(&front));
    int checkDistance = modbus_read_registers(m_tcpModbus, 70, 1, reinterpret_cast<uint16_t*>(&distance));
    int checkHeading = modbus_read_registers(m_tcpModbus, 80, 1, reinterpret_cast<uint16_t*>(&heading));
    
    if (checkFront == 1 && checkDistance == 1 && checkHeading == 1)
    {
        if (front > safe)
        {
            if (heading > 0)
            {
                if (distance > (target + 2))
                {
                    moveLogic(1);
                }

                if (distance < (target - 2) && distance > notsafetarget)
                {
                    moveLogic(2);
                }

                if (distance >= (target - 2) && distance <= (target + 2))
                {
                    moveLogic(3);
                }

                if (distance < notsafetarget)
                {
                    moveLogic(0);
                }
            }

            if (heading < 0)
            {
                if (distance > (target + 2))
                {
                    moveLogic(1);
                }

                if (distance < (target - 2) && distance > notsafetarget)
                {
                    moveLogic(2);
                }

                if (distance >= (target - 2) && distance <= (target + 2))
                {
                    moveLogic(3);
                }

                if (distance < notsafetarget)
                {
                    moveLogic(0);
                }
            }

            if (heading == 0)
            {
                if (distance > (target + 2))
                {
                    moveLogic(1);
                }

                if (distance < (target - 2) && distance > notsafetarget)
                {
                    moveLogic(2);
                }

                if (distance >= (target - 2) && distance <= (target + 2))
                {
                    moveLogic(3);
                }

                if (distance < notsafetarget)
                {
                    moveLogic(0);
                }
            }
        }

        if (front < safe && front > stopsafe)
        {
            if (distance > wallCheck)
            {
                moveLogic(1);
            }

            if (distance <= wallCheck)
            {
                moveLogic(0);
            }
        }

        if (front < stopsafe)
        {
            moveLogic(0);
        }
    }
    
}

void MainWindow::on_checkBox_7_clicked(bool checked)
{
    if(checked)
    {
        autoTimer->start(10);
    }
    else
    {
        autoTimer->stop();
    }
}

