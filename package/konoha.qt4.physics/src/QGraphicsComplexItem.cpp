#include <physics.hpp>
#include <del_interface.hpp>

typedef struct {
	QPointF a;
	QPointF b;
	QPointF c;
} Triangle;

#define fMIN(x, y) (((x) < (y)) ? x : y)
#define fMAX(x, y) (((x) < (y)) ? y : x)

std::vector<Triangle> triangulate(const QList<QPointF> &points, float resolution = 50.0f)
{
	std::vector<Triangle> mTriangles;
	float mSize = points.size();
	float mCount = fMIN(resolution, mSize);
	tpp::Delaunay::Point mPoint;
	std::vector<tpp::Delaunay::Point> mVertices;
	for (int32_t i = 0; i < mCount; i++) {
		int32_t mId = (int32_t)((float)i / mCount * mSize);
		mPoint[0] = points.at(mId).x();
		mPoint[1] = points.at(mId).y();
		mVertices.push_back(mPoint);
	}
	tpp::Delaunay mDelaunay(mVertices);
	mDelaunay.Triangulate();
	for (tpp::Delaunay::fIterator mTriIt = mDelaunay.fbegin(); mTriIt != mDelaunay.fend(); ++mTriIt) {
		int32_t mA = mDelaunay.Org(mTriIt);
		int32_t mB = mDelaunay.Dest(mTriIt);
		int32_t mC = mDelaunay.Apex(mTriIt);
		int32_t mAId = (int32_t)(((float)mA / resolution) * mSize);
		int32_t mBId = (int32_t)(((float)mB / resolution) * mSize);
		int32_t mCId = (int32_t)(((float)mC / resolution) * mSize);
		QPointF mTriangle[3];
		mTriangle[0] = points.at(mAId);
		mTriangle[1] = points.at(mBId);
		mTriangle[2] = points.at(mCId);
		QPointF mCentroid = QPointF(
			(mTriangle[0].x() + mTriangle[1].x() + mTriangle[2].x()) / 3.0f,
			(mTriangle[0].y() + mTriangle[1].y() + mTriangle[2].y()) / 3.0f
			);
		int32_t mCounter = 0;
		QPointF mPointA = points.at(0);
		QPointF mPointB;
		for (int32_t i = 1; i < (int32_t)mSize; i++) {
			mPointB = points.at(i);
			if (mCentroid.y() > fMIN(mPointA.y(), mPointB.y()) &&
				mCentroid.y() <= fMAX(mPointA.y(), mPointB.y()) &&
				mCentroid.x() <= fMAX(mPointA.x(), mPointB.x()) &&
				mPointA.y() != mPointB.y() &&
				(mPointA.x() == mPointB.x() || mCentroid.x() <= (mCentroid.y() - mPointA.y()) * (mPointB.x() - mPointA.x()) / (mPointB.y() - mPointA.y()) + mPointA.x()))
				mCounter++;
			mPointA = mPointB;
		}
		if (mCounter % 2 != 0) {
			Triangle mTriData;
			float x0 = mTriangle[0].x();
			float y0 = mTriangle[0].y();
			float x1 = mTriangle[1].x();
			float y1 = mTriangle[1].y();
			float x2 = mTriangle[2].x();
			float y2 = mTriangle[2].y();
			if (((x1 - x0) * (y2 - y0) - (x2 -x0) * (y1 - y0)) > 0) {
				mTriData.a = QPointF(x0, y0);
				mTriData.b = QPointF(x1, y1);
				mTriData.c = QPointF(x2, y2);
			} else {
				mTriData.a = QPointF(x0, y0);
				mTriData.b = QPointF(x2, y2);
				mTriData.c = QPointF(x1, y1);
			}
			mTriangles.push_back(mTriData);
		}
	}
	return mTriangles;
}

QGraphicsComplexItem::QGraphicsComplexItem(const QList<QPointF> &pts) : KQGraphicsItemGroup(0)
{
	int size = pts.size();
	std::vector<Triangle> tris = triangulate(pts, (float)size);
	polygons = new QList<QGraphicsPolygonItem *>();
	for (std::vector<Triangle>::iterator triIt = tris.begin(); triIt != tris.end(); ++triIt) {
		QPolygonF p;
		p << QPoint(triIt->a.x(), triIt->a.y());
		p << QPoint(triIt->b.x(), triIt->b.y());
		p << QPoint(triIt->c.x(), triIt->c.y());
		QGraphicsPolygonItem *gp = new QGraphicsPolygonItem();
		gp->setPolygon(p);
		gp->setPen(Qt::NoPen);
		polygons->append(gp);
		addToGroup(gp);
		//fprintf(stderr, "(%f, %f), (%f, %f), (%f, %f)\n", triIt->a.x, triIt->a.y, triIt->b.x, triIt->b.y, triIt->c.x, triIt->c.y);
	}
	/*
	QPainterPath path;
	path.moveTo(pts[0]);
	for (int i = 1; i < size; i++) {
		path.lineTo(pts[i]);
	}
	QGraphicsPathItem *edge = new QGraphicsPathItem();
	edge->setPath(path);
	addToGroup(edge);
	*/
}

QGraphicsComplexItem::~QGraphicsComplexItem(void) {}

void QGraphicsComplexItem::addToWorld(QWorld *w)
{
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!dummy->isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	//bodyDef.position.Set(0/PTM_RATIO, 0/PTM_RATIO);
	b2Body *body = world->CreateBody(&bodyDef);
	dummy->body = body;
	w->bodys->append(body);

	int length = polygons->size();
	b2FixtureDef shapeDef;
	shapeDef.density = dummy->density;
	shapeDef.friction = dummy->friction;
	shapeDef.restitution = dummy->restitution;
	for (int i = 0; i < length; i++) {
		QPolygonF poly = polygons->at(i)->polygon();
		b2Vec2 vers[3];
		const QPointF p0 = poly.at(0);
		const QPointF p1 = poly.at(1);
		const QPointF p2 = poly.at(2);
		vers[0].Set(p0.x()/PTM_RATIO, p0.y()/PTM_RATIO);
		vers[1].Set(p1.x()/PTM_RATIO, p1.y()/PTM_RATIO);
		vers[2].Set(p2.x()/PTM_RATIO, p2.y()/PTM_RATIO);
		b2PolygonShape shape;
		shape.Set(vers, 3);
		shapeDef.shape = &shape;
		body->CreateFixture(&shapeDef);
	}
	body->SetBullet(dummy->bullet);
	KQData *data = new KQData();
	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(this);
	data->i = i;
	data->cid = CLASS_QGraphicsComplexItem;
	body->SetUserData(data);
}

void QGraphicsComplexItem::setBrush(const QBrush &b)
{
	int length = polygons->size();
	for (int i = 0; i < length; i++) {
		polygons->at(i)->setBrush(b);
	}
}
