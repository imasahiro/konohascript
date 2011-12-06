#include <kinect.hpp>

static bool match(const char *a, const char *b)
{
	bool ret = false;
	if (!strncmp(a, b, strlen(a)) && strlen(a) == strlen(b)) {
		ret = true;
	}
	return ret;
}

#ifdef __cplusplus
extern "C" {
#endif

QImage *convertFromIplImageToQImage(const IplImage * iplImage)
{
	int width = iplImage->width;
	int widthStep = iplImage->widthStep;
	int height = iplImage->height;
	uchar *qImageBuffer = NULL;
	switch (iplImage->depth) {
	case IPL_DEPTH_8U:
		if (iplImage->nChannels == 1) {
			qImageBuffer = (uchar *)malloc(width * height * sizeof(uchar));
			uchar *QImagePtr = qImageBuffer;
			const uchar *iplImagePtr = (const uchar *)iplImage->imageData;
			for (int y = 0; y < height; y++) {
				memcpy(QImagePtr, iplImagePtr, width);
				QImagePtr += width;
				iplImagePtr += widthStep;
			}
		} else if (iplImage->nChannels == 3) {
			qImageBuffer = (uchar *)malloc(width * height * 4 * sizeof(uchar));
			uchar *QImagePtr = qImageBuffer;
			const uchar *iplImagePtr = (const uchar *)iplImage->imageData;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					QImagePtr[0] = iplImagePtr[0];
					QImagePtr[1] = iplImagePtr[1];
					QImagePtr[2] = iplImagePtr[2];
					QImagePtr[3] = 0;
					QImagePtr += 4;
					iplImagePtr += 3;
				}
				iplImagePtr += widthStep-3*width;
			}
		} else {
			qDebug("IplImageToQImage: image format is not supported:\
						depth=8U and %d channels\n", iplImage->nChannels);
		}
		break;
	case IPL_DEPTH_16U:
		if (iplImage->nChannels == 1) {
			qImageBuffer = (uchar *)malloc(width * height * sizeof(uchar));
			uchar *QImagePtr = qImageBuffer;
			const uint16_t *iplImagePtr = (const uint16_t *)iplImage->imageData;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					*QImagePtr++ = ((*iplImagePtr++) >> 8);
				}
				iplImagePtr += widthStep/sizeof(uint16_t)-width;
			}
		} else {
			qDebug("IplImageToQImage: image format is not supported:\
						depth=16U and %d channels\n", iplImage->nChannels);
		}
		break;
	case IPL_DEPTH_32F:
		if (iplImage->nChannels == 1) {
		} else {
			qDebug("IplImageToQImage: image format is not supported:\
						depth=32F and %d channels\n", iplImage->nChannels);
		}
		break;
	case IPL_DEPTH_64F:
		if (iplImage->nChannels == 1) {
		} else {
			qDebug("IplImageToQImage: image format is not supported:\
						depth=64F and %d channels\n", iplImage->nChannels);
		}
		break;
	default:
		qDebug("IplImageToQImage: image format is not supported: depth=%d\
					and %d channels\n", iplImage->depth, iplImage->nChannels);
		break;
	}
	QImage *qImage;
	if (iplImage->nChannels == 1) {
		QVector<QRgb> colorTable;
		for (int i = 0; i < 256; i++) {
			colorTable.push_back(qRgb(i, i, i));
		}
		qImage = new QImage(qImageBuffer, width, height, QImage::Format_Indexed8);
		qImage->setColorTable(colorTable);
	} else {
		qImage = new QImage(qImageBuffer, width, height, QImage::Format_RGB32);
	}
	free(qImageBuffer);
	return qImage;
}

using namespace xn;

QPerson::QPerson(unsigned int label_, QList<QPointF> *pts)
{
	label = label_;
	this->pts = pts;
}

QList<QPointF> *QPerson::getEdgePoints(void)
{
	return pts;
}

QPerson::~QPerson(void)
{
	if (pts) {
		delete pts;
	}
}

QPeople::QPeople(void)
{
	num = 0;
	persons = new QList<QPerson *>();
}

void QPeople::addPerson(QPerson *person)
{
	num++;
	persons->append(person);
}

unsigned int QPeople::length(void)
{
	return num;
}

QPerson *QPeople::getPerson(int n)
{
	return persons->at(n);
}

QList<QPerson *> *QPeople::getPersons(void)
{
	return persons;
}

QPeople::~QPeople(void)
{
	if (persons) {
		int size = persons->length();
		for (int i = 0; i < size; i++) {
			QPerson *p = persons->at(i);
			delete p;
		}
		delete persons;
	}
}

XnVPointDrawer::XnVPointDrawer(XnUInt32 nHistory, xn::DepthGenerator depthGenerator) :
	XnVPointControl("XnVPointDrawer"),
	m_nHistorySize(nHistory), m_DepthGenerator(depthGenerator), m_bDrawDM(false), m_bFrameID(false)
{
	m_pfPositionBuffer = new XnFloat[nHistory*3];
}

XnVPointDrawer::~XnVPointDrawer()
{
	std::map<XnUInt32, std::list<XnPoint3D> >::iterator iter;
	for (iter = m_History.begin(); iter != m_History.end(); ++iter)
	{
		iter->second.clear();
	}
	m_History.clear();
	delete []m_pfPositionBuffer;
}

void XnVPointDrawer::OnPointCreate(const XnVHandPointContext* cxt)
{
	fprintf(stderr, "** %d\n", cxt->nID);
	// Create entry for the hand
	m_History[cxt->nID].clear();
	OnPointUpdate(cxt);
}

void XnVPointDrawer::OnPointUpdate(const XnVHandPointContext* cxt)
{
	XnPoint3D ptProjective(cxt->ptPosition);
	fprintf(stderr, "Point (%f,%f,%f)", ptProjective.X, ptProjective.Y, ptProjective.Z);
	m_DepthGenerator.ConvertRealWorldToProjective(1, &ptProjective, &ptProjective);
	fprintf(stderr, " -> (%f,%f,%f)\n", ptProjective.X, ptProjective.Y, ptProjective.Z);
	QPointF p(ptProjective.X, ptProjective.Y);
	float z = ptProjective.Z;
	//emit updateHandPositionSignal(p, z);
	m_History[cxt->nID].push_front(ptProjective);
	if (m_History[cxt->nID].size() > m_nHistorySize)
		m_History[cxt->nID].pop_back();
}

void XnVPointDrawer::OnPointDestroy(XnUInt32 nID)
{
	m_History.erase(nID);
}

void XnVPointDrawer::Update(XnVMessage* pMessage)
{
	XnVPointControl::Update(pMessage);
	m_TouchingFOVEdge.clear();
}

void XnVPointDrawer::SetDepthMap(XnBool bDrawDM)
{
	m_bDrawDM = bDrawDM;
}

void XnVPointDrawer::SetFrameID(XnBool bFrameID)
{
	m_bFrameID = bFrameID;
}

void XnVPointDrawer::SetTouchingFOVEdge(XnUInt32 nID)
{
	m_TouchingFOVEdge.push_front(nID);
}

XnBool XnVPointDrawer::IsTouching(XnUInt32 id) const
{
	for (std::list<XnUInt32>::const_iterator iter = m_TouchingFOVEdge.begin(); iter != m_TouchingFOVEdge.end(); ++iter)
	{
		if (*iter == id)
			return TRUE;
	}
	return FALSE;
}

static void focusProgress(const XnChar* strFocus, const XnPoint3D &ptPosition, XnFloat fProgress, void* UserCxt)
{
	fprintf(stderr, "Focus progress: %s @(%f,%f,%f): %f\n", strFocus, ptPosition.X, ptPosition.Y, ptPosition.Z, fProgress);
}

static void startSession(const XnPoint3D &ptPosition, void *ctx)
{
	fprintf(stderr, "Session start: (%f,%f,%f)\n", ptPosition.X, ptPosition.Y, ptPosition.Z);
}

static void endSession(void *ctx)
{
	fprintf(stderr, "Session end\n");
}

static void noHands(void *ctx)
{
	//if (sessionState != NOT_IN_SESSION) {
	//fprintf(stderr, "Quick refocus\n");
	//sessionState = QUICK_REFOCUS;
	//}
}

static void push(XnFloat fVelocity, XnFloat fAngle, void *ctx)
{
}

static void swipe(XnFloat fVelocity, XnFloat fAngle, void *ctx)
{
}

static void touching(xn::HandTouchingFOVEdgeCapability &generator, XnUserID id,
					 const XnPoint3D* pPosition, XnFloat fTime, XnDirection eDir, void* pCookie)
{
	fprintf(stderr, "TouchingCallback\n");
}

static void gestureIntermediateStageCompleted(xn::GestureGenerator& generator, const XnChar* strGesture,
											  const XnPoint3D* pPosition, void* pCookie)
{
	fprintf(stderr, "Gesture %s: Intermediate stage complete (%f,%f,%f)\n", strGesture, pPosition->X, pPosition->Y, pPosition->Z);
}

static void gestureReadyForNextIntermediateStage(xn::GestureGenerator& generator, const XnChar* strGesture,
												 const XnPoint3D* pPosition, void* pCookie)
{
	fprintf(stderr, "Gesture %s: Ready for next intermediate stage (%f,%f,%f)\n", strGesture, pPosition->X, pPosition->Y, pPosition->Z);
}

static void gestureProgress(xn::GestureGenerator& generator, const XnChar* strGesture,
							const XnPoint3D* pPosition, XnFloat fProgress, void* pCookie)
{
	fprintf(stderr, "Gesture %s progress: %f (%f,%f,%f)\n", strGesture, fProgress, pPosition->X, pPosition->Y, pPosition->Z);
}

QKinect::QKinect(const char *xml)
{
	people = NULL;
	background_texture = NULL;
	context = new Context();
	XnStatus rc = context->InitFromXmlFile(xml);
	userGenerator = new UserGenerator();
	imageGenerator = new ImageGenerator();
	depthGenerator = new DepthGenerator();
	handsGenerator = new HandsGenerator();
	gestureGenerator = new GestureGenerator();
	XnStatus val = context->FindExistingNode(XN_NODE_TYPE_USER, *userGenerator);
	context->FindExistingNode(XN_NODE_TYPE_IMAGE, *imageGenerator);
	context->FindExistingNode (XN_NODE_TYPE_DEPTH, *depthGenerator);
	context->FindExistingNode (XN_NODE_TYPE_HANDS, *handsGenerator);
	context->FindExistingNode (XN_NODE_TYPE_GESTURE, *gestureGenerator);
	XnCallbackHandle h;
	if (handsGenerator->IsCapabilitySupported(XN_CAPABILITY_HAND_TOUCHING_FOV_EDGE)) {
		handsGenerator->GetHandTouchingFOVEdgeCap().RegisterToHandTouchingFOVEdge(&touching, NULL, h);
	}
	if (val != XN_STATUS_OK) {
		userGenerator->Create(*context);
	}
	XnCallbackHandle intermediateStageCompleted, progress, readyForNextIntermediateStage;
	gestureGenerator->RegisterToGestureIntermediateStageCompleted(gestureIntermediateStageCompleted,
															  NULL, intermediateStageCompleted);
	gestureGenerator->RegisterToGestureReadyForNextIntermediateStage(gestureReadyForNextIntermediateStage,
																 NULL, readyForNextIntermediateStage);
	gestureGenerator->RegisterGestureCallbacks(NULL, gestureProgress, NULL, progress);

	sessionManager = new XnVSessionManager();
	rc = sessionManager->Initialize(context, "Wave,Click", "RaiseHand");
	sessionManager->RegisterSession(NULL, startSession, endSession, focusProgress);

	pushDetector = new XnVPushDetector();
	pushDetector->RegisterPush(NULL, &push);
	sessionManager->AddListener(pushDetector);
	swipeDetector = new XnVSwipeDetector();
	swipeDetector->RegisterSwipeUp(NULL, &swipe);
	sessionManager->AddListener(swipeDetector);
	drawer = new XnVPointDrawer(20, *depthGenerator);
	sessionManager->AddListener(drawer);
	drawer->RegisterNoPoints(NULL, noHands);
	drawer->SetDepthMap(false);
//	connect(drawer, SIGNAL(updateHandPositionSignal(GamPoint, float)),
//			this, SLOT(updateHandPositionHandler(GamPoint, float)));
	depthGenerator->GetAlternativeViewPointCap().SetViewPoint(*imageGenerator);
	rc = context->StartGeneratingAll();
	imageMD = new ImageMetaData();
	iplImage = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
	blend_texture = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
	context->WaitAndUpdateAll();
}

QImage *QKinect::queryFrame(void)
{
	imageGenerator->GetMetaData(*imageMD);
	iplImage->imageData = (char *)imageMD->WritableData();
	cvCvtColor(iplImage, iplImage, CV_RGB2BGR);
	QImage *image = convertFromIplImageToQImage(iplImage);
	return image;
}

QImage *QKinect::queryBlendFrame(void)
{
	cvCvtColor(blend_texture, blend_texture, CV_RGB2BGR);
	QImage *image = convertFromIplImageToQImage(blend_texture);
	return image;
}

void QKinect::update(void)
{
	sessionManager->Update(context);
	context->WaitAndUpdateAll();
	xn::DepthMetaData dmd;
	depthGenerator->GetMetaData(dmd);
	context->WaitOneUpdateAll(*depthGenerator);
	imageGenerator->GetMetaData(*imageMD);
	xn::SceneMetaData smd;
	userGenerator->GetUserPixels(0, smd);
	const XnLabel* pLabels = smd.Data();//user labels' pointer
	XnUInt16 width = dmd.XRes();
	XnUInt16 height = dmd.YRes();
	bool user_found_flag = false;
	char *imagePtr = (char *)imageMD->WritableData();
	char *headPtr = imagePtr;
	char *background = NULL;
	if (background_texture) {
		background = background_texture->imageData;
	}
	char *blend = blend_texture->imageData;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < height; x++) {
			if (*pLabels != 0) {
				user_found_flag = true;
				blend[0] = imagePtr[0];
				blend[1] = imagePtr[1];
				blend[2] = imagePtr[2];
				imagePtr[0] = 255;
				imagePtr[1] = 255;
				imagePtr[2] = 255;
			} else {
				imagePtr[0] = 0;
				imagePtr[1] = 0;
				imagePtr[2] = 0;
				if (background) {
					blend[0] = background[0];
					blend[1] = background[1];
					blend[2] = background[2];
				}
			}
			pLabels++;
			imagePtr+=3;
			blend+=3;
			if (background) {
				background+=3;
			}
		}
	}
	//delete people; ==> please delete application side
	people = NULL;
	if (user_found_flag) {
		iplImage->imageData = headPtr;//(char *)imageMD->WritableData();
		cvCvtColor(iplImage, iplImage, CV_RGB2BGR);
		setEdgePointToPeople(iplImage);
		//emit foundPeopleSignal(people);
	}
}

QPeople *QKinect::getPeople(void)
{
	return people;
}

IplImage *QImage_toIplImage(const QImage &image)
{
    int width = image.width();
    int height = image.height();
    CvSize size;
    size.height = height;
    size.width = width;
    IplImage *ret = cvCreateImage(size, IPL_DEPTH_8U, 3);
    char *data = (char *)ret->imageData;
    for (int y = 0; y < height; y++) {
		QRgb *row = (QRgb*)image.scanLine(y);
        for (int x = 0; x < width; x++) {
			unsigned char *r = (unsigned char*)&row[x];
            data[0] = r[0];
			data[1] = r[1];
			data[2] = r[2];
			data += 3;
        }
    }
    return ret;
}

void QKinect::setBackgroundImage(const char *imagepath)
{
	QImage image(imagepath);
	image = image.scaled(640, 480);
	background_texture = QImage_toIplImage(image);
	cvCvtColor(background_texture, background_texture, CV_RGB2BGR);
}

void QKinect::setEdgePointToPeople(IplImage *src_img)
{
	people = new QPeople();
	CvMemStorage *storage = cvCreateMemStorage(0);
	CvSeq *contours = NULL;
	IplImage *src_img_gray = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	cvCvtColor(src_img, src_img_gray, CV_BGR2GRAY);
	IplImage *tmp_img = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	cvThreshold(src_img_gray, tmp_img, 120, 255, CV_THRESH_BINARY);
	cvFindContours(tmp_img, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	int label = 0;
	//people->clear();
	while (1) {
		if (contours == NULL) break;
		QList<QPointF> *pts = new QList<QPointF>();
		for (int i = 0; i < contours->total; i++) {
			CvPoint *point = CV_GET_SEQ_ELEM(CvPoint, contours, i);
			pts->append(QPointF(point->x, point->y));
		}
		QPerson *person = new QPerson(label, pts);
		people->addPerson(person);
		if (contours->h_next == NULL) break;
		contours = contours->h_next;
		label++;
	}
	cvReleaseImage(&src_img_gray);
	cvReleaseImage(&tmp_img);
	cvReleaseMemStorage(&storage);
}

QKinect::~QKinect(void)
{
	context->Shutdown();
}

KMETHOD QKinect_new(CTX ctx, ksfp_t *sfp _RIX)
{
	const char *xmlpath = String_to(const char *, sfp[1]);
	QKinect *kinect = new QKinect(xmlpath);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, kinect, NULL);
	RETURN_(p);
}

KMETHOD QKinect_setBackgroundImage(CTX ctx, ksfp_t *sfp _RIX)
{
	QKinect *kinect = RawPtr_to(QKinect *, sfp[0]);
	const char *imagepath = String_to(const char *, sfp[1]);
	if (kinect) kinect->setBackgroundImage(imagepath);
	RETURNvoid_();
}

KMETHOD QKinect_addEvent(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNvoid_();
}

KMETHOD QKinect_queryFrame(CTX ctx, ksfp_t *sfp _RIX)
{
	QKinect *kinect = RawPtr_to(QKinect *, sfp[0]);
	if (kinect) {
		QImage *image = kinect->queryFrame();
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, image, NULL);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}

KMETHOD QKinect_queryBlendFrame(CTX ctx, ksfp_t *sfp _RIX)
{
	QKinect *kinect = RawPtr_to(QKinect *, sfp[0]);
	if (kinect) {
		QImage *image = kinect->queryBlendFrame();
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, image, NULL);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}

KMETHOD QKinect_getPeople(CTX ctx, ksfp_t *sfp _RIX)
{
	QKinect *kinect = RawPtr_to(QKinect *, sfp[0]);
	QPeople *ret = NULL;
	if (kinect) {
		ret = kinect->getPeople();
	}
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, ret, NULL);
	RETURN_(p);
}

KMETHOD QKinect_update(CTX ctx, ksfp_t *sfp _RIX)
{
	QKinect *kinect = RawPtr_to(QKinect *, sfp[0]);
	if (kinect) kinect->update();
	RETURNvoid_();
}

KMETHOD QPeople_getPersons(CTX ctx, ksfp_t *sfp _RIX)
{
	QPeople *people = RawPtr_to(QPeople *, sfp[0]);
	kArray *a;
	if (people) {
		QList<QPerson *> *persons = people->getPersons();
		int size = persons->size();
		a = new_Array0(ctx, size);
		kclass_t cid = knh_getcid(ctx, STEXT("QPerson"));
		for (int n = 0; n < size; n++) {
			kRawPtr *p = new_RawPtr(ctx, ClassTBL(cid), persons->at(n));
			knh_Array_add(ctx, a, UPCAST(p));
		}
	} else {
		a = new_Array0(ctx, 0);
	}
	RETURN_(a);
}

KMETHOD QPerson_getEdgePoints(CTX ctx, ksfp_t *sfp _RIX)
{
	QPerson *person = RawPtr_to(QPerson *, sfp[0]);
	kArray *a;
	if (person) {
		QList<QPointF> *pts = person->getEdgePoints();
		int size = pts->size();
		a = new_Array0(ctx, size);
		kclass_t cid = knh_getcid(ctx, STEXT("QPointF"));
		for (int n = 0; n < size; n++) {
			kRawPtr *p = new_RawPtr(ctx, ClassTBL(cid), new QPointF(pts->at(n)));
			knh_Array_add(ctx, a, UPCAST(p));
		}
	} else {
		a = new_Array0(ctx, 0);
	}
	RETURN_(a);
}

static void QPeople_free(CTX ctx, kRawPtr *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QPeople *people = static_cast<QPeople *>(p->rawptr);
		delete people;
		p->rawptr = NULL;
	}
}

//static void QPeople_reftrace(CTX ctx, kRawPtr *p FTRARG)
//{
//	if (p->rawptr != NULL) {
//	}
//}

DEFAPI(void) defQPeople(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPeople";
	cdef->free = QPeople_free;
	//cdef->reftrace = QPeople_reftrace;
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *)
{
	RETURN_PKGINFO("kinect");
}

#ifdef __cplusplus
}
#endif
