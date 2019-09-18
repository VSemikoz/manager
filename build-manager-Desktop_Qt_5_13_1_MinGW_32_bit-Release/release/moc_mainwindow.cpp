/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../manager/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_updatePushButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 27), // "on_incomePushButton_clicked"
QT_MOC_LITERAL(4, 68, 29), // "on_spendingPushButton_clicked"
QT_MOC_LITERAL(5, 98, 22), // "slotIncomeUpdateModels"
QT_MOC_LITERAL(6, 121, 24), // "slotSpendingUpdateModels"
QT_MOC_LITERAL(7, 146, 20), // "slotEditIncomeRecord"
QT_MOC_LITERAL(8, 167, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 179, 5), // "index"
QT_MOC_LITERAL(10, 185, 22), // "slotEditSpendingRecord"
QT_MOC_LITERAL(11, 208, 23), // "slotIncomeMenuRequested"
QT_MOC_LITERAL(12, 232, 3), // "pos"
QT_MOC_LITERAL(13, 236, 25), // "slotSpendingMenuRequested"
QT_MOC_LITERAL(14, 262, 26), // "slotRemoveRecordFromIncome"
QT_MOC_LITERAL(15, 289, 28), // "slotRemoveRecordFromSpending"
QT_MOC_LITERAL(16, 318, 27), // "on_categoryAction_triggered"
QT_MOC_LITERAL(17, 346, 25), // "on_periodAction_triggered"
QT_MOC_LITERAL(18, 372, 32) // "on_periodBalanceAction_triggered"

    },
    "MainWindow\0on_updatePushButton_clicked\0"
    "\0on_incomePushButton_clicked\0"
    "on_spendingPushButton_clicked\0"
    "slotIncomeUpdateModels\0slotSpendingUpdateModels\0"
    "slotEditIncomeRecord\0QModelIndex\0index\0"
    "slotEditSpendingRecord\0slotIncomeMenuRequested\0"
    "pos\0slotSpendingMenuRequested\0"
    "slotRemoveRecordFromIncome\0"
    "slotRemoveRecordFromSpending\0"
    "on_categoryAction_triggered\0"
    "on_periodAction_triggered\0"
    "on_periodBalanceAction_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_updatePushButton_clicked(); break;
        case 1: _t->on_incomePushButton_clicked(); break;
        case 2: _t->on_spendingPushButton_clicked(); break;
        case 3: _t->slotIncomeUpdateModels(); break;
        case 4: _t->slotSpendingUpdateModels(); break;
        case 5: _t->slotEditIncomeRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->slotEditSpendingRecord((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->slotIncomeMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 8: _t->slotSpendingMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 9: _t->slotRemoveRecordFromIncome(); break;
        case 10: _t->slotRemoveRecordFromSpending(); break;
        case 11: _t->on_categoryAction_triggered(); break;
        case 12: _t->on_periodAction_triggered(); break;
        case 13: _t->on_periodBalanceAction_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
