include "lib:gluelink";

class QKinect;
class QPerson;
@Native class QPeople;

QKinect QKinect.new(String xmlpath);
void QKinect.setBackgroundImage(String imagepath);
void QKinect.addEvent(String event_name, dynamic func);
QPeople QKinect.getPeople();
void QKinect.update();
QImage QKinect.queryFrame();
QImage QKinect.queryBlendFrame();
QPerson[] QPeople.getPersons();
Array<QPointF> QPerson.getEdgePoints();
