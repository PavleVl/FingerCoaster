/****************************************************************************
** Meta object code from reading C++ file 'Thread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FingerCoaster/Server/Thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Thread_t {
    const uint offsetsAndSize[24];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Thread_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Thread_t qt_meta_stringdata_Thread = {
    {
QT_MOC_LITERAL(0, 6), // "Thread"
QT_MOC_LITERAL(7, 18), // "setClientsUsername"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 7), // "qintptr"
QT_MOC_LITERAL(35, 14), // "clientSocketFd"
QT_MOC_LITERAL(50, 8), // "username"
QT_MOC_LITERAL(59, 12), // "deleteThread"
QT_MOC_LITERAL(72, 9), // "readyRead"
QT_MOC_LITERAL(82, 13), // "onSendMessage"
QT_MOC_LITERAL(96, 7), // "message"
QT_MOC_LITERAL(104, 15), // "targetSocketPtr"
QT_MOC_LITERAL(120, 12) // "disconnected"

    },
    "Thread\0setClientsUsername\0\0qintptr\0"
    "clientSocketFd\0username\0deleteThread\0"
    "readyRead\0onSendMessage\0message\0"
    "targetSocketPtr\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Thread[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,
       6,    1,   49,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   52,    2, 0x0a,    6 /* Public */,
       8,    2,   53,    2, 0x0a,    7 /* Public */,
      11,    0,   58,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3,    9,   10,
    QMetaType::Void,

       0        // eod
};

void Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Thread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setClientsUsername((*reinterpret_cast< qintptr(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->deleteThread((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 2: _t->readyRead(); break;
        case 3: _t->onSendMessage((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 4: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Thread::*)(qintptr , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::setClientsUsername)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Thread::*)(qintptr );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread::deleteThread)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Thread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Thread.offsetsAndSize,
    qt_meta_data_Thread,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Thread_t
, QtPrivate::TypeAndForceComplete<Thread, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qintptr, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qintptr, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<qintptr, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Thread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Thread::setClientsUsername(qintptr _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Thread::deleteThread(qintptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
