include "lib:gluelink";

class QWorld;
@Public @Native void QGraphicsItem.setDensity(float density);
@Public @Native float QGraphicsItem.getDensity(void);
@Public @Native void QGraphicsItem.setFriction(float friction);
@Public @Native float QGraphicsItem.getFriction(void);
@Public @Native void QGraphicsItem.setRestitution(float restitution);
@Public @Native float QGraphicsItem.getRestitution(void);
@Public @Native void QGraphicsItem.setBullet(boolean b);
@Public @Native boolean QGraphicsItem.isBullet(void);
@Public @Native boolean QGraphicsItem.isStatic(void);
QWorld QWorld.new(QGraphicsScene scene);
void QWorld.add(QGraphicsItem item);
void QWorld.start();
