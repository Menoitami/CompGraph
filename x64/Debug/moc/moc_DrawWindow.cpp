/****************************************************************************
** Meta object code from reading C++ file 'DrawWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DrawWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawWindow_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawWindow_t qt_meta_stringdata_DrawWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DrawWindow"
QT_MOC_LITERAL(1, 11, 14), // "mouseMove_slot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 40, 5), // "event"
QT_MOC_LITERAL(5, 46, 18), // "mouseStartPos_slot"
QT_MOC_LITERAL(6, 65, 16), // "mouseScroll_slot"
QT_MOC_LITERAL(7, 82, 12), // "QWheelEvent*"
QT_MOC_LITERAL(8, 95, 20), // "objPointChanged_slot"
QT_MOC_LITERAL(9, 116, 6), // "size_t"
QT_MOC_LITERAL(10, 123, 4), // "objN"
QT_MOC_LITERAL(11, 128, 6), // "pointN"
QT_MOC_LITERAL(12, 135, 19), // "std::vector<double>"
QT_MOC_LITERAL(13, 155, 6) // "values"

    },
    "DrawWindow\0mouseMove_slot\0\0QMouseEvent*\0"
    "event\0mouseStartPos_slot\0mouseScroll_slot\0"
    "QWheelEvent*\0objPointChanged_slot\0"
    "size_t\0objN\0pointN\0std::vector<double>\0"
    "values"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    3,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    4,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 12,   10,   11,   13,

       0        // eod
};

void DrawWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMove_slot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseStartPos_slot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseScroll_slot((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 3: _t->objPointChanged_slot((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< std::vector<double>(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DrawWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DrawWindow.data,
    qt_meta_data_DrawWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DrawWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
