/****************************************************************************
** Meta object code from reading C++ file 'handgesturedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/video/handgesturedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handgesturedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HandGestureDialog_t {
    QByteArrayData data[16];
    char stringdata0[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandGestureDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandGestureDialog_t qt_meta_stringdata_HandGestureDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HandGestureDialog"
QT_MOC_LITERAL(1, 18, 17), // "grabImageFinished"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "IplImage*"
QT_MOC_LITERAL(4, 47, 3), // "img"
QT_MOC_LITERAL(5, 51, 9), // "readFarme"
QT_MOC_LITERAL(6, 61, 32), // "on_pushButton_OpenCamera_clicked"
QT_MOC_LITERAL(7, 94, 31), // "on_pushButton_SnapImage_clicked"
QT_MOC_LITERAL(8, 126, 33), // "on_pushButton_CloseCamera_cli..."
QT_MOC_LITERAL(9, 160, 31), // "on_pushButton_ShowPause_clicked"
QT_MOC_LITERAL(10, 192, 32), // "on_pushButton_StartTrain_clicked"
QT_MOC_LITERAL(11, 225, 37), // "on_pushButton_StartRecongnise..."
QT_MOC_LITERAL(12, 263, 31), // "on_comboBox_ShowDelay_activated"
QT_MOC_LITERAL(13, 295, 5), // "index"
QT_MOC_LITERAL(14, 301, 31), // "on_comboBox_ImageMode_activated"
QT_MOC_LITERAL(15, 333, 37) // "on_pushButton_StartGestureReg..."

    },
    "HandGestureDialog\0grabImageFinished\0"
    "\0IplImage*\0img\0readFarme\0"
    "on_pushButton_OpenCamera_clicked\0"
    "on_pushButton_SnapImage_clicked\0"
    "on_pushButton_CloseCamera_clicked\0"
    "on_pushButton_ShowPause_clicked\0"
    "on_pushButton_StartTrain_clicked\0"
    "on_pushButton_StartRecongnise_clicked\0"
    "on_comboBox_ShowDelay_activated\0index\0"
    "on_comboBox_ImageMode_activated\0"
    "on_pushButton_StartGestureReg_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandGestureDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      14,    1,   82,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void HandGestureDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HandGestureDialog *_t = static_cast<HandGestureDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->grabImageFinished((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 1: _t->readFarme(); break;
        case 2: _t->on_pushButton_OpenCamera_clicked(); break;
        case 3: _t->on_pushButton_SnapImage_clicked(); break;
        case 4: _t->on_pushButton_CloseCamera_clicked(); break;
        case 5: _t->on_pushButton_ShowPause_clicked(); break;
        case 6: _t->on_pushButton_StartTrain_clicked(); break;
        case 7: _t->on_pushButton_StartRecongnise_clicked(); break;
        case 8: _t->on_comboBox_ShowDelay_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_comboBox_ImageMode_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_StartGestureReg_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HandGestureDialog::*_t)(IplImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HandGestureDialog::grabImageFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject HandGestureDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HandGestureDialog.data,
      qt_meta_data_HandGestureDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HandGestureDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandGestureDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HandGestureDialog.stringdata0))
        return static_cast<void*>(const_cast< HandGestureDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int HandGestureDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void HandGestureDialog::grabImageFinished(IplImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
