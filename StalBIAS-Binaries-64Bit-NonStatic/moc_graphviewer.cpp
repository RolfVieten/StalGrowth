/****************************************************************************
** Meta object code from reading C++ file 'graphviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/graphviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphViewer_t {
    QByteArrayData data[10];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphViewer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphViewer_t qt_meta_stringdata_GraphViewer = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 21),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 15),
QT_MOC_LITERAL(4, 51, 15),
QT_MOC_LITERAL(5, 67, 16),
QT_MOC_LITERAL(6, 84, 12),
QT_MOC_LITERAL(7, 97, 3),
QT_MOC_LITERAL(8, 101, 18),
QT_MOC_LITERAL(9, 120, 10)
    },
    "GraphViewer\0on_pushButton_clicked\0\0"
    "on_yrmk_clicked\0on_ssmk_clicked\0"
    "onMouseMoveGraph\0QMouseEvent*\0evt\0"
    "on_cseason_clicked\0oncsaccept\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    1,   47,    2, 0x08,
       8,    0,   50,    2, 0x08,
       9,    0,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphViewer *_t = static_cast<GraphViewer *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_yrmk_clicked(); break;
        case 2: _t->on_ssmk_clicked(); break;
        case 3: _t->onMouseMoveGraph((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->on_cseason_clicked(); break;
        case 5: _t->oncsaccept(); break;
        default: ;
        }
    }
}

const QMetaObject GraphViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GraphViewer.data,
      qt_meta_data_GraphViewer,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphViewer.stringdata))
        return static_cast<void*>(const_cast< GraphViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int GraphViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
