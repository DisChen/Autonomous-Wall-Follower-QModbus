#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "imodbus.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IModbus
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // IModbus Interface
    virtual modbus_t *modbus() { return m_tcpModbus; }
    virtual int setupModbusPort();
    void tcpConnect();


protected:
    void changeModbusInterface(const QString& address, int portNbr);
    void releaseTcpModbus();
    void enableTCPEdit(bool checked);

private slots:
    void on_tcpEnable_clicked(bool checked);
    void sendTcpRequest( void );
    void setStatusError(const QString &msg);

    //void on_radioButton_clicked();

    //void on_radioButton_clicked(bool checked);

    void on_radioGo_0_clicked(bool checked);

    void on_radioGo_1_clicked(bool checked);

    void on_radioGo_2_clicked(bool checked);

    void on_radioTurn_0_clicked(bool checked);

    void on_radioTurn_1_clicked(bool checked);

    void on_radioTurn_2_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_radioButton_clicked(bool checked);

    void updateGraphDistance();

    void updateGraphHeading();

    void updateGraphFront();

    void forward();

    void backward();

    void right();

    void left();

    void straight();

    void stop();

    void outWrite(QString filename, int output);

    void logOut();

    void writeUSF();

    void writeUSR();

    void writeTOF();

    void moveLogic(int action);

    void controlCenter();

    void writeDistance();

    void writeHeading();

    void outRead(QString filename, int output);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked(bool checked);

    void on_radioButton_6_clicked(bool checked);

    void on_radioButton_5_clicked(bool checked);

    void on_checkBox_6_clicked(bool checked);

    void on_checkBox_7_clicked(bool checked);

signals:
    void tcpPortActive(bool val);
    void connectionError(const QString &msg);

private:
    Ui::MainWindow *ui;
    modbus_t*   m_tcpModbus;
    modbus_t* m_modbus;
    QTimer *refreshRate;
    QTimer *distanceUpdate;
    QTimer *headingUpdate;
    QTimer *frontUpdate;
    QTimer *outWriteTimer;
    QTimer *autoTimer;
    int graphXCount;

    QWidget * m_statusInd;
    QLabel * m_statusText;
    QTimer * m_pollTimer;
    QTimer * m_statusTimer;
    bool m_tcpActive;
    bool m_poll;




};
#endif // MAINWINDOW_H
