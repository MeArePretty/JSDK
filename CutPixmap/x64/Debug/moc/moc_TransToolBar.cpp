/****************************************************************************
** Meta object code from reading C++ file 'TransToolBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TransToolBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransToolBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TransToolBar_t {
    QByteArrayData data[12];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransToolBar_t qt_meta_stringdata_TransToolBar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TransToolBar"
QT_MOC_LITERAL(1, 13, 13), // "SendDrawcheck"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "SendShow_Hide"
QT_MOC_LITERAL(4, 42, 9), // "ShowFlash"
QT_MOC_LITERAL(5, 52, 10), // "CloseFlash"
QT_MOC_LITERAL(6, 63, 21), // "ModifyCloseFlashValue"
QT_MOC_LITERAL(7, 85, 8), // "OnBtnCut"
QT_MOC_LITERAL(8, 94, 14), // "CutWindowclose"
QT_MOC_LITERAL(9, 109, 9), // "OnBtnLock"
QT_MOC_LITERAL(10, 119, 9), // "OnBtnDraw"
QT_MOC_LITERAL(11, 129, 16) // "ModifyCloseFlash"

    },
    "TransToolBar\0SendDrawcheck\0\0SendShow_Hide\0"
    "ShowFlash\0CloseFlash\0ModifyCloseFlashValue\0"
    "OnBtnCut\0CutWindowclose\0OnBtnLock\0"
    "OnBtnDraw\0ModifyCloseFlash"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    0,   70,    2, 0x06 /* Public */,
       5,    0,   71,    2, 0x06 /* Public */,
       6,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   73,    2, 0x08 /* Private */,
       8,    0,   74,    2, 0x08 /* Private */,
       9,    0,   75,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TransToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransToolBar *_t = static_cast<TransToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendDrawcheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SendShow_Hide((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ShowFlash(); break;
        case 3: _t->CloseFlash(); break;
        case 4: _t->ModifyCloseFlashValue(); break;
        case 5: _t->OnBtnCut(); break;
        case 6: _t->CutWindowclose(); break;
        case 7: _t->OnBtnLock(); break;
        case 8: _t->OnBtnDraw(); break;
        case 9: _t->ModifyCloseFlash(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TransToolBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransToolBar::SendDrawcheck)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TransToolBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransToolBar::SendShow_Hide)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TransToolBar::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransToolBar::ShowFlash)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TransToolBar::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransToolBar::CloseFlash)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TransToolBar::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransToolBar::ModifyCloseFlashValue)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject TransToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_TransToolBar.data,
      qt_meta_data_TransToolBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TransToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TransToolBar.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int TransToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
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
void TransToolBar::SendDrawcheck(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TransToolBar::SendShow_Hide(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TransToolBar::ShowFlash()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TransToolBar::CloseFlash()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TransToolBar::ModifyCloseFlashValue()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
