/****************************************************************************
** Meta object code from reading C++ file 'QShapeToolBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QShapeToolBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QShapeToolBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QShapeToolBar_t {
    QByteArrayData data[6];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QShapeToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QShapeToolBar_t qt_meta_stringdata_QShapeToolBar = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QShapeToolBar"
QT_MOC_LITERAL(1, 14, 23), // "SelectCurrentBrushColor"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "SendCurrentBrushColor"
QT_MOC_LITERAL(4, 61, 13), // "ColorSelected"
QT_MOC_LITERAL(5, 75, 12) // "UsuallyColor"

    },
    "QShapeToolBar\0SelectCurrentBrushColor\0"
    "\0SendCurrentBrushColor\0ColorSelected\0"
    "UsuallyColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QShapeToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x08 /* Private */,
       5,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QShapeToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QShapeToolBar *_t = static_cast<QShapeToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectCurrentBrushColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->SendCurrentBrushColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->ColorSelected(); break;
        case 3: _t->UsuallyColor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QShapeToolBar::*_t)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QShapeToolBar::SelectCurrentBrushColor)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QShapeToolBar::*_t)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QShapeToolBar::SendCurrentBrushColor)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QShapeToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_QShapeToolBar.data,
      qt_meta_data_QShapeToolBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QShapeToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QShapeToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QShapeToolBar.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int QShapeToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
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
void QShapeToolBar::SelectCurrentBrushColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QShapeToolBar::SendCurrentBrushColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
