/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "ipaddressctrl.h"

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
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1091, 600);
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
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(490, 190, 112, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1091, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

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
        radioButton->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
