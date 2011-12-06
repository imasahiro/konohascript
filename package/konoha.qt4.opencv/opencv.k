include "lib:gluelink";

class QWebCamera;
class QVideo;

QWebCamera QWebCamera.new(int n);
QImage QWebCamera.queryFrame();

QVideo QVideo.new(String filename);
QImage QVideo.queryFrame();

@Public @Native QImage QImage.binarization(QColor c);
@Public @Native QImage QImage.permeabilization(QColor c);
@Public @Native QPointF[][] QImage.getEdgePoints();
@Public @Native QPointF[][] QImage.getEdgePointsUsingAlpha();
