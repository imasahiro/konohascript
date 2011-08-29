/****************************************************************************
** Meta object code from reading C++ file 'gwt.hpp'
**
** Created: Mon Aug 29 16:02:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/gwt.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gwt.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Connector[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Connector[] = {
    "Connector\0\0val\0slot_func(qreal)\0"
};

const QMetaObject Connector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Connector,
      qt_meta_data_Connector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Connector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Connector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Connector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Connector))
        return static_cast<void*>(const_cast< Connector*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< Connector*>(this));
    return QObject::qt_metacast(_clname);
}

int Connector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slot_func((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_KScene[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KScene[] = {
    "KScene\0"
};

const QMetaObject KScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_KScene,
      qt_meta_data_KScene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KScene))
        return static_cast<void*>(const_cast< KScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int KScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KRect[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KRect[] = {
    "KRect\0"
};

const QMetaObject KRect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KRect,
      qt_meta_data_KRect, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KRect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KRect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KRect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KRect))
        return static_cast<void*>(const_cast< KRect*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< KRect*>(this));
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(const_cast< KRect*>(this));
    if (!strcmp(_clname, "KRigidBody"))
        return static_cast< KRigidBody*>(const_cast< KRect*>(this));
    return QObject::qt_metacast(_clname);
}

int KRect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KEllipse[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KEllipse[] = {
    "KEllipse\0"
};

const QMetaObject KEllipse::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KEllipse,
      qt_meta_data_KEllipse, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KEllipse::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KEllipse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KEllipse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KEllipse))
        return static_cast<void*>(const_cast< KEllipse*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< KEllipse*>(this));
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(const_cast< KEllipse*>(this));
    if (!strcmp(_clname, "KRigidBody"))
        return static_cast< KRigidBody*>(const_cast< KEllipse*>(this));
    return QObject::qt_metacast(_clname);
}

int KEllipse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KTexture[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      59,   10,    9,    9, 0x0a,
     101,   10,    9,    9, 0x0a,
     146,   10,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KTexture[] = {
    "KTexture\0\0event\0"
    "mousePressEvent(QGraphicsSceneMouseEvent*)\0"
    "mouseMoveEvent(QGraphicsSceneMouseEvent*)\0"
    "mouseReleaseEvent(QGraphicsSceneMouseEvent*)\0"
    "dragEnterEvent(QGraphicsSceneDragDropEvent*)\0"
};

const QMetaObject KTexture::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KTexture,
      qt_meta_data_KTexture, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KTexture::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KTexture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KTexture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KTexture))
        return static_cast<void*>(const_cast< KTexture*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< KTexture*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< KTexture*>(this));
    if (!strcmp(_clname, "KRigidBody"))
        return static_cast< KRigidBody*>(const_cast< KTexture*>(this));
    return QObject::qt_metacast(_clname);
}

int KTexture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mousePressEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 1: mouseMoveEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 2: mouseReleaseEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 3: dragEnterEvent((*reinterpret_cast< QGraphicsSceneDragDropEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_KComplexItem[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KComplexItem[] = {
    "KComplexItem\0"
};

const QMetaObject KComplexItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KComplexItem,
      qt_meta_data_KComplexItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KComplexItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KComplexItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KComplexItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KComplexItem))
        return static_cast<void*>(const_cast< KComplexItem*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< KComplexItem*>(this));
    if (!strcmp(_clname, "QGraphicsItemGroup"))
        return static_cast< QGraphicsItemGroup*>(const_cast< KComplexItem*>(this));
    if (!strcmp(_clname, "KRigidBody"))
        return static_cast< KRigidBody*>(const_cast< KComplexItem*>(this));
    return QObject::qt_metacast(_clname);
}

int KComplexItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KLine[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KLine[] = {
    "KLine\0"
};

const QMetaObject KLine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KLine,
      qt_meta_data_KLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KLine))
        return static_cast<void*>(const_cast< KLine*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< KLine*>(this));
    if (!strcmp(_clname, "QGraphicsLineItem"))
        return static_cast< QGraphicsLineItem*>(const_cast< KLine*>(this));
    if (!strcmp(_clname, "KRigidBody"))
        return static_cast< KRigidBody*>(const_cast< KLine*>(this));
    return QObject::qt_metacast(_clname);
}

int KLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KText[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KText[] = {
    "KText\0"
};

const QMetaObject KText::staticMetaObject = {
    { &QGraphicsTextItem::staticMetaObject, qt_meta_stringdata_KText,
      qt_meta_data_KText, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KText::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KText::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KText))
        return static_cast<void*>(const_cast< KText*>(this));
    if (!strcmp(_clname, "GObject"))
        return static_cast< GObject*>(const_cast< KText*>(this));
    if (!strcmp(_clname, "KRigidBody"))
        return static_cast< KRigidBody*>(const_cast< KText*>(this));
    return QGraphicsTextItem::qt_metacast(_clname);
}

int KText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTextItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
