/****************************************************************************
** Meta object code from reading C++ file 'board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_board_t {
    QByteArrayData data[8];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_board_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_board_t qt_meta_stringdata_board = {
    {
QT_MOC_LITERAL(0, 0, 5), // "board"
QT_MOC_LITERAL(1, 6, 17), // "tellAiToTakeATurn"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "runResize"
QT_MOC_LITERAL(4, 35, 7), // "newSize"
QT_MOC_LITERAL(5, 43, 10), // "resetBoard"
QT_MOC_LITERAL(6, 54, 6), // "dieHit"
QT_MOC_LITERAL(7, 61, 11) // "diePosition"

    },
    "board\0tellAiToTakeATurn\0\0runResize\0"
    "newSize\0resetBoard\0dieHit\0diePosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_board[] = {

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
       3,    1,   40,    2, 0x0a /* Public */,
       3,    0,   43,    2, 0x2a /* Public | MethodCloned */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QPoint,    7,

       0        // eod
};

void board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        board *_t = static_cast<board *>(_o);
        switch (_id) {
        case 0: _t->tellAiToTakeATurn(); break;
        case 1: _t->runResize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->runResize(); break;
        case 3: _t->resetBoard(); break;
        case 4: { int _r = _t->dieHit((*reinterpret_cast< QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (board::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&board::tellAiToTakeATurn)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject board::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_board.data,
      qt_meta_data_board,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *board::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_board.stringdata))
        return static_cast<void*>(const_cast< board*>(this));
    return QWidget::qt_metacast(_clname);
}

int board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void board::tellAiToTakeATurn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
