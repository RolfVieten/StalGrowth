/****************************************************************************
** Meta object code from reading C++ file 'plotselect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/plotselect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotselect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlotSelect_t {
    QByteArrayData data[11];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlotSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlotSelect_t qt_meta_stringdata_PlotSelect = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlotSelect"
QT_MOC_LITERAL(1, 11, 9), // "fgclicked"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "clicked"
QT_MOC_LITERAL(4, 30, 3), // "row"
QT_MOC_LITERAL(5, 34, 9), // "sgclicked"
QT_MOC_LITERAL(6, 44, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 66, 23), // "on_customSeason_clicked"
QT_MOC_LITERAL(8, 90, 15), // "season_accepted"
QT_MOC_LITERAL(9, 106, 23), // "on_Sbias_button_clicked"
QT_MOC_LITERAL(10, 130, 18) // "on_savepng_clicked"

    },
    "PlotSelect\0fgclicked\0\0clicked\0row\0"
    "sgclicked\0on_pushButton_clicked\0"
    "on_customSeason_clicked\0season_accepted\0"
    "on_Sbias_button_clicked\0on_savepng_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotSelect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    2,   54,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlotSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotSelect *_t = static_cast<PlotSelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fgclicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sgclicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_customSeason_clicked(); break;
        case 4: _t->season_accepted(); break;
        case 5: _t->on_Sbias_button_clicked(); break;
        case 6: _t->on_savepng_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PlotSelect::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PlotSelect.data,
      qt_meta_data_PlotSelect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlotSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlotSelect.stringdata0))
        return static_cast<void*>(const_cast< PlotSelect*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PlotSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_mycheck_t {
    QByteArrayData data[6];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mycheck_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mycheck_t qt_meta_stringdata_mycheck = {
    {
QT_MOC_LITERAL(0, 0, 7), // "mycheck"
QT_MOC_LITERAL(1, 8, 7), // "toggled"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "checked"
QT_MOC_LITERAL(4, 25, 3), // "row"
QT_MOC_LITERAL(5, 29, 9) // "togcustom"

    },
    "mycheck\0toggled\0\0checked\0row\0togcustom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mycheck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void mycheck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mycheck *_t = static_cast<mycheck *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggled((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->togcustom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mycheck::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mycheck::toggled)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject mycheck::staticMetaObject = {
    { &QCheckBox::staticMetaObject, qt_meta_stringdata_mycheck.data,
      qt_meta_data_mycheck,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mycheck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mycheck::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mycheck.stringdata0))
        return static_cast<void*>(const_cast< mycheck*>(this));
    return QCheckBox::qt_metacast(_clname);
}

int mycheck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCheckBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void mycheck::toggled(bool _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
