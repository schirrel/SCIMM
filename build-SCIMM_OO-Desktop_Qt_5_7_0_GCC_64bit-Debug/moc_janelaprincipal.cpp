/****************************************************************************
** Meta object code from reading C++ file 'janelaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SCIMM/janelaprincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'janelaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JanelaPrincipal_t {
    QByteArrayData data[13];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JanelaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JanelaPrincipal_t qt_meta_stringdata_JanelaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 15), // "JanelaPrincipal"
QT_MOC_LITERAL(1, 16, 18), // "ComboObjetoChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 12), // "BotaoIniciar"
QT_MOC_LITERAL(5, 55, 11), // "BotaoSalvar"
QT_MOC_LITERAL(6, 67, 16), // "BotaoSalvarFundo"
QT_MOC_LITERAL(7, 84, 15), // "BotaoConfigurar"
QT_MOC_LITERAL(8, 100, 14), // "BotaoFinalizar"
QT_MOC_LITERAL(9, 115, 12), // "BotaoExtrair"
QT_MOC_LITERAL(10, 128, 15), // "ComboCorChanged"
QT_MOC_LITERAL(11, 144, 19), // "IniciarCameraManual"
QT_MOC_LITERAL(12, 164, 23) // "IniciarCameraAutomatico"

    },
    "JanelaPrincipal\0ComboObjetoChanged\0\0"
    "index\0BotaoIniciar\0BotaoSalvar\0"
    "BotaoSalvarFundo\0BotaoConfigurar\0"
    "BotaoFinalizar\0BotaoExtrair\0ComboCorChanged\0"
    "IniciarCameraManual\0IniciarCameraAutomatico"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JanelaPrincipal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    0,   67,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    0,   72,    2, 0x0a /* Public */,
      10,    1,   73,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void JanelaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JanelaPrincipal *_t = static_cast<JanelaPrincipal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        //case 0: _t->ComboObjetoChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->BotaoIniciar(); break;
        case 2: _t->BotaoSalvar(); break;
        case 3: _t->BotaoSalvarFundo(); break;
        case 4: _t->BotaoConfigurar(); break;
        case 5: _t->BotaoFinalizar(); break;
        case 6: _t->BotaoExtrair(); break;
        case 7: _t->ComboCorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        //case 8: _t->IniciarCameraManual(); break;
        case 9: _t->IniciarCameraAutomatico(); break;
        default: ;
        }
    }
}

const QMetaObject JanelaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JanelaPrincipal.data,
      qt_meta_data_JanelaPrincipal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *JanelaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JanelaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_JanelaPrincipal.stringdata0))
        return static_cast<void*>(const_cast< JanelaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JanelaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
