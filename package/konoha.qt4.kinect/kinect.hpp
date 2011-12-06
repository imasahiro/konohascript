#define K_INTERNAL
#include <cv.h>
#include <highgui.h>
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <QtGui>

#define warning(msg) //for escape OpenNI's warning
#include <XnOpenNI.h>
#include <XnVPointControl.h>
#include <XnVSessionManager.h>
#include <XnVPushDetector.h>
#include <XnVSwipeDetector.h>

#define getClassTBL(ctx, CLASS) ctx->share->ClassTBL[knh_getcid(ctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(ctx, CLASS, o) new_RawPtr(ctx, getClassTBL(ctx, CLASS), o)


class QPerson {
private:
	unsigned int label;
	QList<QPointF> *pts;
public:

	QPerson(unsigned int label_, QList<QPointF> *pts);
	QList<QPointF> *getEdgePoints(void);
	~QPerson(void);
};

class QPeople {
private:
	unsigned int capacity;
	unsigned int num;
	QList<QPerson *> *persons;
public:
	QPeople(void);
	void addPerson(QPerson *p);
	unsigned int length(void);
	QPerson *getPerson(int n);
	QList<QPerson *> *getPersons(void);
	~QPeople(void);
};

class XnVPointDrawer : public QObject, public XnVPointControl {
	Q_OBJECT;
public:
	XnVPointDrawer(XnUInt32 nHistorySize, xn::DepthGenerator depthGenerator);
	virtual ~XnVPointDrawer();
	void Update(XnVMessage* pMessage);
	void OnPointCreate(const XnVHandPointContext* cxt);
	void OnPointUpdate(const XnVHandPointContext* cxt);
	void OnPointDestroy(XnUInt32 nID);
	void SetDepthMap(XnBool bDrawDM);
	void SetFrameID(XnBool bFrameID);
	void SetTouchingFOVEdge(XnUInt32 nID);
protected:
	XnBool IsTouching(XnUInt32 nID) const;
	XnUInt32 m_nHistorySize;
	std::map<XnUInt32, std::list<XnPoint3D> > m_History;
	std::list<XnUInt32> m_TouchingFOVEdge;
	xn::DepthGenerator m_DepthGenerator;
	XnFloat* m_pfPositionBuffer;
	XnBool m_bDrawDM;
	XnBool m_bFrameID;
//signals:
	//void updateHandPositionSignal(GamPoint p, float z);
};

class QKinect : public QObject {
	Q_OBJECT;
private:
	XnVSessionManager *sessionManager;
	XnVPushDetector *pushDetector;
	XnVSwipeDetector *swipeDetector;
	xn::Context *context;
	xn::UserGenerator *userGenerator;
	xn::ImageGenerator *imageGenerator;
	xn::DepthGenerator *depthGenerator;
	xn::HandsGenerator *handsGenerator;
	xn::GestureGenerator *gestureGenerator;
	xn::ImageMetaData *imageMD;
	IplImage *iplImage;
	XnVPointDrawer *drawer;
	QPeople *people;
	IplImage *background_texture;
	IplImage *blend_texture;

public:
	QKinect(const char *xmlpath);
	QImage *queryFrame(void);
	QImage *queryBlendFrame(void);
	void setEdgePointToPeople(IplImage *image);
	//void startSessionHandler(const XnPoint3D &pFocus, void *ctx);
	//void endSessionHandler(void *ctx);
	//void pushHandler(XnFloat fVelocity, XnFloat fAngle, void *ctx);
	//void swipeHandler(XnFloat fVelocity, XnFloat fAngle, void *ctx);
	void update(void);
	void setBackgroundImage(const char *texture);
	QPeople *getPeople(void);
	~QKinect(void);
//signals:
	//void startSessionSignal(const XnPoint3D pFocus, void *ctx);
	//void endSessionSignal(void *ctx);
	//void pushSignal(XnFloat fVelocity, XnFloat fAngle, void *ctx);
	//void swipeSignal(XnFloat fVelocity, XnFloat fAngle, void *ctx);
	//void updateHandPositionSignal(QPointF *p, float z);
	//void foundPeopleSignal(QPeople *people);
//public slots:
	//void updateHandPositionHandler(QPointF *p, float z);
};

#define GET_CID(CLASS) knh_getcid(ctx, STEXT(#CLASS))
