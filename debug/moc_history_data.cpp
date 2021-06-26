/****************************************************************************
** Meta object code from reading C++ file 'history_data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../history_data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'history_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_History_data_t {
    QByteArrayData data[12];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_History_data_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_History_data_t qt_meta_stringdata_History_data = {
    {
QT_MOC_LITERAL(0, 0, 12), // "History_data"
QT_MOC_LITERAL(1, 13, 9), // "Data_Show"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "message"
QT_MOC_LITERAL(4, 32, 11), // "Data_Finish"
QT_MOC_LITERAL(5, 44, 15), // "Chart_Data_Save"
QT_MOC_LITERAL(6, 60, 6), // "direct"
QT_MOC_LITERAL(7, 67, 8), // "double[]"
QT_MOC_LITERAL(8, 76, 5), // "datas"
QT_MOC_LITERAL(9, 82, 17), // "Chart_Data_Choose"
QT_MOC_LITERAL(10, 100, 8), // "filename"
QT_MOC_LITERAL(11, 109, 12) // "pB_Open_Slot"

    },
    "History_data\0Data_Show\0\0message\0"
    "Data_Finish\0Chart_Data_Save\0direct\0"
    "double[]\0datas\0Chart_Data_Choose\0"
    "filename\0pB_Open_Slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_History_data[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   43,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      11,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void History_data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<History_data *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Data_Show((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Data_Finish(); break;
        case 2: _t->Chart_Data_Save((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)[]>(_a[2]))); break;
        case 3: _t->Chart_Data_Choose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->pB_Open_Slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (History_data::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&History_data::Data_Show)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (History_data::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&History_data::Data_Finish)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject History_data::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_History_data.data,
    qt_meta_data_History_data,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *History_data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *History_data::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_History_data.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int History_data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void History_data::Data_Show(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void History_data::Data_Finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
