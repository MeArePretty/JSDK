/****************************************************************************
** Meta object code from reading C++ file 'QDockToolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QDockToolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDockToolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDockToolbar_t {
    QByteArrayData data[15];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDockToolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDockToolbar_t qt_meta_stringdata_QDockToolbar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QDockToolbar"
QT_MOC_LITERAL(1, 13, 13), // "SendDrawcheck"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "ChangedofTrans"
QT_MOC_LITERAL(4, 43, 14), // "OnAnimationEnd"
QT_MOC_LITERAL(5, 58, 9), // "ShowFlash"
QT_MOC_LITERAL(6, 68, 10), // "CloseFlash"
QT_MOC_LITERAL(7, 79, 17), // "WidthvalueChanged"
QT_MOC_LITERAL(8, 97, 5), // "value"
QT_MOC_LITERAL(9, 103, 17), // "TransvalueChanged"
QT_MOC_LITERAL(10, 121, 20), // "GetCurrentBrushColor"
QT_MOC_LITERAL(11, 142, 23), // "GetCurrentPen_TextColor"
QT_MOC_LITERAL(12, 166, 14), // "GetMessageDraw"
QT_MOC_LITERAL(13, 181, 7), // "QLayer*"
QT_MOC_LITERAL(14, 189, 5) // "layer"

    },
    "QDockToolbar\0SendDrawcheck\0\0ChangedofTrans\0"
    "OnAnimationEnd\0ShowFlash\0CloseFlash\0"
    "WidthvalueChanged\0value\0TransvalueChanged\0"
    "GetCurrentBrushColor\0GetCurrentPen_TextColor\0"
    "GetMessageDraw\0QLayer*\0layer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDockToolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   68,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void QDockToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDockToolbar *_t = static_cast<QDockToolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendDrawcheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ChangedofTrans(); break;
        case 2: _t->OnAnimationEnd(); break;
        case 3: _t->ShowFlash(); break;
        case 4: _t->CloseFlash(); break;
        case 5: _t->WidthvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->TransvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->GetCurrentBrushColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->GetCurrentPen_TextColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 9: _t->GetMessageDraw((*reinterpret_cast< QLayer*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QDockToolbar::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QDockToolbar::SendDrawcheck)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QDockToolbar::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QDockToolbar::ChangedofTrans)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QDockToolbar::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_QDockToolbar.data,
      qt_meta_data_QDockToolbar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDockToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDockToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDockToolbar.stringdata0))
        return static_cast<void*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int QDockToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QDockToolbar::SendDrawcheck(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDockToolbar::ChangedofTrans()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
