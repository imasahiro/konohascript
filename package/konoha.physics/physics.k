include "lib:gluelink";

@Native class QWorld;
class QJoint extends QGraphicsItem;
class QDistanceJoint extends QGraphicsLineItem;
class QRevoluteJoint extends QGraphicsLineItem;
class QPrismaticJoint extends QGraphicsLineItem;
class QPulleyJoint extends QGraphicsPathItem;
class QGearJoint extends QGraphicsLineItem;
class QGraphicsComplexItem extends QGraphicsItemGroup;
class QMassData;

@Public @Native void QGraphicsItem.setDensity(float density);
@Public @Native float QGraphicsItem.getDensity(void);
@Public @Native void QGraphicsItem.setFriction(float friction);
@Public @Native float QGraphicsItem.getFriction(void);
@Public @Native void QGraphicsItem.setRestitution(float restitution);
@Public @Native float QGraphicsItem.getRestitution(void);
@Public @Native void QGraphicsItem.setBullet(boolean b);
@Public @Native boolean QGraphicsItem.isBullet(void);
@Public @Native boolean QGraphicsItem.isStatic(void);
@Public @Native void QGraphicsItem.setDraggable(boolean b);
@Public @Native boolean QGraphicsItem.isDraggable(void);
@Public @Native void QGraphicsItem.applyForce(QPointF force, QPointF pos);
@Public @Native void QGraphicsItem.applyTorque(float torque);
@Public @Native void QGraphicsItem.setXForm(QPointF pos, float angle);
@Public @Native void QGraphicsItem.setMassData(QMassData massdata);
@Public @Native QMassData QGraphicsItem.getMassData(void);
float QMassData.setMass(float mass);
float QMassData.getMass(void);
void QMassData.setCenterPos(QPointF pos);
QPointF QMassData.getCenterPos(void);

QGraphicsComplexItem QGraphicsComplexItem.new(Array<QPointF> pts);
void QGraphicsComplexItem.setBrush(QBrush b);

QWorld QWorld.new(QGraphicsScene scene);
void QWorld.setGravity(float x, float y);
void QWorld.add(QGraphicsItem item);
void QWorld.remove(QGraphicsItem item);
void QWorld.removeAll(void);
void QWorld.start();
void QWorld.showDebugDraw();
void QWorld.addEvent(String event_name, dynamic func);

QDistanceJoint QDistanceJoint.new(QGraphicsItem o1, QGraphicsItem o2);
void QDistanceJoint.setLocalAnchorA(QPointF p);
void QDistanceJoint.setLocalAnchorB(QPointF p);
void QDistanceJoint.setFrequencyHz(float frequency);
void QDistanceJoint.setDampingRatio(float ratio);
void QDistanceJoint.setLength(float length);
float QDistanceJoint.getFrequencyHz();
float QDistanceJoint.getDampingRatio();
float QDistanceJoint.getLength();

QRevoluteJoint QRevoluteJoint.new(QGraphicsItem o1, QGraphicsItem o2);
QPrismaticJoint QPrismaticJoint.new(QGraphicsItem o1, QGraphicsItem o2);
QPulleyJoint QPulleyJoint.new(QGraphicsItem o1, QPointF p1, QGraphicsItem o2, QPointF p2);
QGearJoint QGearJoint.new(QGraphicsItem o1, QJoint j1, QGraphicsItem o2, QJoint j2);
