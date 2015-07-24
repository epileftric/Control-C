/****************************************************************************
** Meta object code from reading C++ file 'guiHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/guiHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_guiHandler_t {
    QByteArrayData data[9];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_guiHandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_guiHandler_t qt_meta_stringdata_guiHandler = {
    {
QT_MOC_LITERAL(0, 0, 10), // "guiHandler"
QT_MOC_LITERAL(1, 11, 12), // "reloadSystem"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "reloadController"
QT_MOC_LITERAL(4, 42, 7), // "addPlot"
QT_MOC_LITERAL(5, 50, 13), // "doubleVector&"
QT_MOC_LITERAL(6, 64, 9), // "time_base"
QT_MOC_LITERAL(7, 74, 4), // "axis"
QT_MOC_LITERAL(8, 79, 9) // "clearPlot"

    },
    "guiHandler\0reloadSystem\0\0reloadController\0"
    "addPlot\0doubleVector&\0time_base\0axis\0"
    "clearPlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_guiHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    2,   36,    2, 0x06 /* Public */,
       8,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,

       0        // eod
};

void guiHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        guiHandler *_t = static_cast<guiHandler *>(_o);
        switch (_id) {
        case 0: _t->reloadSystem(); break;
        case 1: _t->reloadController(); break;
        case 2: _t->addPlot((*reinterpret_cast< doubleVector(*)>(_a[1])),(*reinterpret_cast< doubleVector(*)>(_a[2]))); break;
        case 3: _t->clearPlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (guiHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&guiHandler::reloadSystem)) {
                *result = 0;
            }
        }
        {
            typedef void (guiHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&guiHandler::reloadController)) {
                *result = 1;
            }
        }
        {
            typedef void (guiHandler::*_t)(doubleVector & , doubleVector & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&guiHandler::addPlot)) {
                *result = 2;
            }
        }
        {
            typedef void (guiHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&guiHandler::clearPlot)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject guiHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_guiHandler.data,
      qt_meta_data_guiHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *guiHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *guiHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_guiHandler.stringdata))
        return static_cast<void*>(const_cast< guiHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int guiHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void guiHandler::reloadSystem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void guiHandler::reloadController()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void guiHandler::addPlot(doubleVector & _t1, doubleVector & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void guiHandler::clearPlot()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
