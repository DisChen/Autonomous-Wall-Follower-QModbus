/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "ipaddressctrl.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *ipBox;
    IPAddressCtrl *edNetworkAddress;
    QLineEdit *edPort;
    QCheckBox *tcpEnable;
    QLabel *label;
    QLabel *label_2;
    QLabel *connectionStatus;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *refreshRateEdit;
    QSpinBox *slaveId;
    QSpinBox *addressReg;
    QSpinBox *coilNum;
    QTableWidget *regTable;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *debugLabel;
    QCheckBox *checkBoxHexDisplay;
    QGroupBox *groupBox;
    QRadioButton *radioGo_2;
    QRadioButton *radioGo_1;
    QRadioButton *radioGo_0;
    QGroupBox *groupBox_2;
    QRadioButton *radioTurn_2;
    QRadioButton *radioTurn_0;
    QRadioButton *radioTurn_1;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QLabel *label_8;
    QCustomPlot *widget;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLabel *label_9;
    QCheckBox *checkBox_7;
    QMenuBar *menubar;
    QMenu *menuBrilliant_Richard_Mikha_Adalrico;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1091, 765);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ipBox = new QGroupBox(centralwidget);
        ipBox->setObjectName("ipBox");
        ipBox->setGeometry(QRect(10, 10, 611, 141));
        edNetworkAddress = new IPAddressCtrl(ipBox);
        edNetworkAddress->setObjectName("edNetworkAddress");
        edNetworkAddress->setGeometry(QRect(10, 60, 341, 41));
        edPort = new QLineEdit(ipBox);
        edPort->setObjectName("edPort");
        edPort->setGeometry(QRect(360, 60, 81, 41));
        tcpEnable = new QCheckBox(ipBox);
        tcpEnable->setObjectName("tcpEnable");
        tcpEnable->setGeometry(QRect(10, 110, 93, 26));
        label = new QLabel(ipBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 121, 20));
        label_2 = new QLabel(ipBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 40, 41, 20));
        connectionStatus = new QLabel(ipBox);
        connectionStatus->setObjectName("connectionStatus");
        connectionStatus->setGeometry(QRect(120, 110, 171, 20));
        label_6 = new QLabel(ipBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(560, 70, 41, 20));
        label_7 = new QLabel(ipBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(450, 50, 101, 20));
        refreshRateEdit = new QLineEdit(ipBox);
        refreshRateEdit->setObjectName("refreshRateEdit");
        refreshRateEdit->setGeometry(QRect(450, 70, 101, 28));
        slaveId = new QSpinBox(centralwidget);
        slaveId->setObjectName("slaveId");
        slaveId->setGeometry(QRect(20, 190, 51, 29));
        slaveId->setMinimum(1);
        addressReg = new QSpinBox(centralwidget);
        addressReg->setObjectName("addressReg");
        addressReg->setGeometry(QRect(100, 190, 51, 29));
        addressReg->setMaximum(999);
        coilNum = new QSpinBox(centralwidget);
        coilNum->setObjectName("coilNum");
        coilNum->setGeometry(QRect(230, 190, 51, 29));
        coilNum->setMinimum(1);
        regTable = new QTableWidget(centralwidget);
        if (regTable->columnCount() < 3)
            regTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        regTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        regTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        regTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        regTable->setObjectName("regTable");
        regTable->setGeometry(QRect(20, 230, 381, 192));
        regTable->setColumnCount(3);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 170, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 170, 111, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(230, 170, 111, 20));
        debugLabel = new QLabel(centralwidget);
        debugLabel->setObjectName("debugLabel");
        debugLabel->setGeometry(QRect(20, 430, 111, 20));
        checkBoxHexDisplay = new QCheckBox(centralwidget);
        checkBoxHexDisplay->setObjectName("checkBoxHexDisplay");
        checkBoxHexDisplay->setGeometry(QRect(307, 430, 91, 22));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(430, 170, 141, 171));
        radioGo_2 = new QRadioButton(groupBox);
        radioGo_2->setObjectName("radioGo_2");
        radioGo_2->setGeometry(QRect(10, 90, 91, 22));
        radioGo_1 = new QRadioButton(groupBox);
        radioGo_1->setObjectName("radioGo_1");
        radioGo_1->setGeometry(QRect(10, 60, 91, 22));
        radioGo_0 = new QRadioButton(groupBox);
        radioGo_0->setObjectName("radioGo_0");
        radioGo_0->setGeometry(QRect(10, 30, 91, 22));
        radioGo_0->setChecked(true);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(600, 170, 141, 171));
        radioTurn_2 = new QRadioButton(groupBox_2);
        radioTurn_2->setObjectName("radioTurn_2");
        radioTurn_2->setGeometry(QRect(10, 90, 91, 22));
        radioTurn_2->setAutoExclusive(true);
        radioTurn_0 = new QRadioButton(groupBox_2);
        radioTurn_0->setObjectName("radioTurn_0");
        radioTurn_0->setGeometry(QRect(10, 30, 91, 22));
        radioTurn_0->setChecked(true);
        radioTurn_0->setAutoExclusive(true);
        radioTurn_1 = new QRadioButton(groupBox_2);
        radioTurn_1->setObjectName("radioTurn_1");
        radioTurn_1->setGeometry(QRect(10, 60, 91, 22));
        radioTurn_1->setAutoExclusive(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(630, 100, 151, 41));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(790, 50, 121, 91));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(790, 30, 91, 16));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 460, 851, 261));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(770, 170, 120, 171));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(10, 30, 91, 22));
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(10, 60, 91, 22));
        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(10, 120, 91, 22));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(10, 90, 91, 22));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(630, 30, 151, 61));
        radioButton_5 = new QRadioButton(groupBox_4);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(10, 30, 91, 22));
        radioButton_5->setChecked(true);
        radioButton_6 = new QRadioButton(groupBox_4);
        radioButton_6->setObjectName("radioButton_6");
        radioButton_6->setGeometry(QRect(80, 30, 91, 22));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(430, 350, 281, 91));
        groupBox_5->setCheckable(false);
        groupBox_5->setChecked(false);
        checkBox = new QCheckBox(groupBox_5);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 30, 78, 22));
        checkBox_2 = new QCheckBox(groupBox_5);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(10, 60, 78, 22));
        checkBox_3 = new QCheckBox(groupBox_5);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(100, 30, 91, 22));
        checkBox_4 = new QCheckBox(groupBox_5);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(100, 60, 78, 22));
        checkBox_5 = new QCheckBox(groupBox_5);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(200, 30, 78, 22));
        checkBox_6 = new QCheckBox(groupBox_5);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(120, 0, 78, 22));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(720, 370, 311, 51));
        label_9->setWordWrap(true);
        checkBox_7 = new QCheckBox(centralwidget);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(920, 160, 141, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1091, 21));
        menuBrilliant_Richard_Mikha_Adalrico = new QMenu(menubar);
        menuBrilliant_Richard_Mikha_Adalrico->setObjectName("menuBrilliant_Richard_Mikha_Adalrico");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBrilliant_Richard_Mikha_Adalrico->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ipBox->setTitle(QCoreApplication::translate("MainWindow", "IP Address", nullptr));
        edPort->setText(QCoreApplication::translate("MainWindow", "502", nullptr));
        tcpEnable->setText(QCoreApplication::translate("MainWindow", "Activate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Network Address", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        connectionStatus->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Refresh Rate", nullptr));
        refreshRateEdit->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        QTableWidgetItem *___qtablewidgetitem = regTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Data Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = regTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = regTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Slave ID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Register Address", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Coil Number", nullptr));
        debugLabel->setText(QCoreApplication::translate("MainWindow", "Data Packet", nullptr));
        checkBoxHexDisplay->setText(QCoreApplication::translate("MainWindow", "Hex Display", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "MOTOR", nullptr));
        radioGo_2->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        radioGo_1->setText(QCoreApplication::translate("MainWindow", "FORWARD", nullptr));
        radioGo_0->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "SERVO", nullptr));
        radioTurn_2->setText(QCoreApplication::translate("MainWindow", "LINKS", nullptr));
        radioTurn_0->setText(QCoreApplication::translate("MainWindow", "HALTEN", nullptr));
        radioTurn_1->setText(QCoreApplication::translate("MainWindow", "RECHT", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Forward untl Wall", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Debug Output", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Show Graph", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Heading", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Front Sensor", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Auto Steer", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Save output into file", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "US Front", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "US Rear", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Front Sensor", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Heading", nullptr));
        checkBox_6->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "NOTE : output file is usually in \"SBR_Monitor/build/Desktop_Qt_6_8_0_llvm_mingw_64_bit-Debug\" folder", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "Autonomous Testing", nullptr));
        menuBrilliant_Richard_Mikha_Adalrico->setTitle(QCoreApplication::translate("MainWindow", "Brilliant - Richard - Mikha - Adalrico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
