/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "tcpPortActive",
    "",
    "val",
    "connectionError",
    "msg",
    "on_tcpEnable_clicked",
    "checked",
    "sendTcpRequest",
    "setStatusError",
    "on_radioGo_0_clicked",
    "on_radioGo_1_clicked",
    "on_radioGo_2_clicked",
    "on_radioTurn_0_clicked",
    "on_radioTurn_1_clicked",
    "on_radioTurn_2_clicked",
    "on_pushButton_2_clicked",
    "on_radioButton_clicked",
    "updateGraphDistance",
    "updateGraphHeading",
    "updateGraphFront",
    "forward",
    "backward",
    "right",
    "left",
    "straight",
    "stop",
    "outWrite",
    "filename",
    "output",
    "logOut",
    "writeUSF",
    "writeUSR",
    "writeTOF",
    "moveLogic",
    "action",
    "controlCenter",
    "writeDistance",
    "writeHeading",
    "outRead",
    "on_radioButton_2_clicked",
    "on_radioButton_3_clicked",
    "on_radioButton_4_clicked",
    "on_radioButton_6_clicked",
    "on_radioButton_5_clicked",
    "on_checkBox_6_clicked",
    "on_checkBox_7_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  248,    2, 0x06,    1 /* Public */,
       4,    1,  251,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,  254,    2, 0x08,    5 /* Private */,
       8,    0,  257,    2, 0x08,    7 /* Private */,
       9,    1,  258,    2, 0x08,    8 /* Private */,
      10,    1,  261,    2, 0x08,   10 /* Private */,
      11,    1,  264,    2, 0x08,   12 /* Private */,
      12,    1,  267,    2, 0x08,   14 /* Private */,
      13,    1,  270,    2, 0x08,   16 /* Private */,
      14,    1,  273,    2, 0x08,   18 /* Private */,
      15,    1,  276,    2, 0x08,   20 /* Private */,
      16,    0,  279,    2, 0x08,   22 /* Private */,
      17,    1,  280,    2, 0x08,   23 /* Private */,
      18,    0,  283,    2, 0x08,   25 /* Private */,
      19,    0,  284,    2, 0x08,   26 /* Private */,
      20,    0,  285,    2, 0x08,   27 /* Private */,
      21,    0,  286,    2, 0x08,   28 /* Private */,
      22,    0,  287,    2, 0x08,   29 /* Private */,
      23,    0,  288,    2, 0x08,   30 /* Private */,
      24,    0,  289,    2, 0x08,   31 /* Private */,
      25,    0,  290,    2, 0x08,   32 /* Private */,
      26,    0,  291,    2, 0x08,   33 /* Private */,
      27,    2,  292,    2, 0x08,   34 /* Private */,
      30,    0,  297,    2, 0x08,   37 /* Private */,
      31,    0,  298,    2, 0x08,   38 /* Private */,
      32,    0,  299,    2, 0x08,   39 /* Private */,
      33,    0,  300,    2, 0x08,   40 /* Private */,
      34,    1,  301,    2, 0x08,   41 /* Private */,
      36,    0,  304,    2, 0x08,   43 /* Private */,
      37,    0,  305,    2, 0x08,   44 /* Private */,
      38,    0,  306,    2, 0x08,   45 /* Private */,
      39,    2,  307,    2, 0x08,   46 /* Private */,
      40,    1,  312,    2, 0x08,   49 /* Private */,
      41,    0,  315,    2, 0x08,   51 /* Private */,
      42,    1,  316,    2, 0x08,   52 /* Private */,
      43,    1,  319,    2, 0x08,   54 /* Private */,
      44,    1,  322,    2, 0x08,   56 /* Private */,
      45,    1,  325,    2, 0x08,   58 /* Private */,
      46,    1,  328,    2, 0x08,   60 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   28,   29,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'tcpPortActive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'connectionError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_tcpEnable_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sendTcpRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setStatusError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_radioGo_0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioGo_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioGo_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioTurn_0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioTurn_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioTurn_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateGraphDistance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateGraphHeading'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateGraphFront'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'forward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'backward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'right'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'left'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'straight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'outWrite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'logOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeUSF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeUSR'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeTOF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveLogic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'controlCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeDistance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeHeading'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'outRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_radioButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_checkBox_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_checkBox_7_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tcpPortActive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->connectionError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_tcpEnable_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->sendTcpRequest(); break;
        case 4: _t->setStatusError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_radioGo_0_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_radioGo_1_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_radioGo_2_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_radioTurn_0_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->on_radioTurn_1_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->on_radioTurn_2_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->on_pushButton_2_clicked(); break;
        case 12: _t->on_radioButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->updateGraphDistance(); break;
        case 14: _t->updateGraphHeading(); break;
        case 15: _t->updateGraphFront(); break;
        case 16: _t->forward(); break;
        case 17: _t->backward(); break;
        case 18: _t->right(); break;
        case 19: _t->left(); break;
        case 20: _t->straight(); break;
        case 21: _t->stop(); break;
        case 22: _t->outWrite((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 23: _t->logOut(); break;
        case 24: _t->writeUSF(); break;
        case 25: _t->writeUSR(); break;
        case 26: _t->writeTOF(); break;
        case 27: _t->moveLogic((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->controlCenter(); break;
        case 29: _t->writeDistance(); break;
        case 30: _t->writeHeading(); break;
        case 31: _t->outRead((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 32: _t->on_radioButton_2_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 33: _t->on_radioButton_3_clicked(); break;
        case 34: _t->on_radioButton_4_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 35: _t->on_radioButton_6_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->on_radioButton_5_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 37: _t->on_checkBox_6_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: _t->on_checkBox_7_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(bool );
            if (_t _q_method = &MainWindow::tcpPortActive; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::connectionError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IModbus"))
        return static_cast< IModbus*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::tcpPortActive(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::connectionError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
