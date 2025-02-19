/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
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
#error "This file was generated using the moc from 6.7.2. It"
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
    "orderEspresso",
    "",
    "orderCappuccino",
    "orderLatte",
    "addFunds",
    "refillInventory",
    "checkMaintenance",
    "performMaintenance",
    "showLogs",
    "updateUI",
    "appendLog",
    "entry",
    "appendBrewingStep",
    "step",
    "updateMenuResources",
    "updateCoffeeCup",
    "level",
    "toggleLogs"
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
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    1,  107,    2, 0x08,   10 /* Private */,
      13,    1,  110,    2, 0x08,   12 /* Private */,
      15,    0,  113,    2, 0x08,   14 /* Private */,
      16,    1,  114,    2, 0x08,   15 /* Private */,
      18,    0,  117,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

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
        // method 'orderEspresso'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'orderCappuccino'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'orderLatte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFunds'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refillInventory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkMaintenance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'performMaintenance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showLogs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'appendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'appendBrewingStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateMenuResources'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateCoffeeCup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'toggleLogs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->orderEspresso(); break;
        case 1: _t->orderCappuccino(); break;
        case 2: _t->orderLatte(); break;
        case 3: _t->addFunds(); break;
        case 4: _t->refillInventory(); break;
        case 5: _t->checkMaintenance(); break;
        case 6: _t->performMaintenance(); break;
        case 7: _t->showLogs(); break;
        case 8: _t->updateUI(); break;
        case 9: _t->appendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->appendBrewingStep((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->updateMenuResources(); break;
        case 12: _t->updateCoffeeCup((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->toggleLogs(); break;
        default: ;
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
