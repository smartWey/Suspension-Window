/****************************************************************************
** Meta object code from reading C++ file 'suspensionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../suspensionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'suspensionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SuspensionWindow_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SuspensionWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SuspensionWindow_t qt_meta_stringdata_SuspensionWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SuspensionWindow"
QT_MOC_LITERAL(1, 17, 12), // "rightClicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "onExitActionClicked"
QT_MOC_LITERAL(4, 51, 19), // "onHideActionClicked"
QT_MOC_LITERAL(5, 71, 8), // "showMenu"
QT_MOC_LITERAL(6, 80, 19), // "showStatisticsCount"
QT_MOC_LITERAL(7, 100, 5) // "count"

    },
    "SuspensionWindow\0rightClicked\0\0"
    "onExitActionClicked\0onHideActionClicked\0"
    "showMenu\0showStatisticsCount\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SuspensionWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void SuspensionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SuspensionWindow *_t = static_cast<SuspensionWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rightClicked(); break;
        case 1: _t->onExitActionClicked(); break;
        case 2: _t->onHideActionClicked(); break;
        case 3: _t->showMenu(); break;
        case 4: _t->showStatisticsCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SuspensionWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SuspensionWindow::rightClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SuspensionWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SuspensionWindow.data,
      qt_meta_data_SuspensionWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SuspensionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SuspensionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SuspensionWindow.stringdata0))
        return static_cast<void*>(const_cast< SuspensionWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SuspensionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SuspensionWindow::rightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_MainWindowIcon_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowIcon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowIcon_t qt_meta_stringdata_MainWindowIcon = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MainWindowIcon"
QT_MOC_LITERAL(1, 15, 6), // "onQuit"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "iconActivated"
QT_MOC_LITERAL(4, 37, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(5, 71, 6), // "reason"
QT_MOC_LITERAL(6, 78, 10), // "MaxRestore"
QT_MOC_LITERAL(7, 89, 7) // "Minsize"

    },
    "MainWindowIcon\0onQuit\0\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0MaxRestore\0Minsize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowIcon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindowIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowIcon *_t = static_cast<MainWindowIcon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onQuit(); break;
        case 1: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 2: _t->MaxRestore(); break;
        case 3: _t->Minsize(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindowIcon::staticMetaObject = {
    { &SuspensionWindow::staticMetaObject, qt_meta_stringdata_MainWindowIcon.data,
      qt_meta_data_MainWindowIcon,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindowIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowIcon.stringdata0))
        return static_cast<void*>(const_cast< MainWindowIcon*>(this));
    return SuspensionWindow::qt_metacast(_clname);
}

int MainWindowIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SuspensionWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
