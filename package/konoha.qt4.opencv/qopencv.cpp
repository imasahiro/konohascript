#include <qopencv.hpp>

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
			/*
			qImageBuffer = (uchar *)malloc(width * height * sizeof(uchar));
			uchar *QImagePtr = qImageBuffer;
			const float *iplImagePtr = (const float *)iplImage->imageData;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					uchar p;
					float pf = 255 * ((*iplImagePtr++) - mini) / (maxi - mini);
					if (pf < 0) p = 0;
					else if (pf > 255) p = 255;
					else p = (uchar) pf;
					*QImagePtr++ = p;
				}
				iplImagePtr += widthStep/sizeof(float)-width;
			}
			*/
		} else {
			qDebug("IplImageToQImage: image format is not supported:\
						depth=32F and %d channels\n", iplImage->nChannels);
		}
		break;
	case IPL_DEPTH_64F:
		if (iplImage->nChannels == 1) {
			/*
			qImageBuffer = (uchar *)malloc(width * height * sizeof(uchar));
			uchar *QImagePtr = qImageBuffer;
			const double *iplImagePtr = (const double *)iplImage->imageData;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					uchar p;
					double pf = 255 * ((*iplImagePtr++) - mini) / (maxi - mini);
					if (pf < 0) p = 0;
					else if (pf > 255) p = 255;
					else p = (uchar) pf;
					*QImagePtr++ = p;
				}
				iplImagePtr += widthStep/sizeof(double)-width;
			}
			*/
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

KMETHOD QWebCamera_new(CTX ctx, ksfp_t *sfp _RIX)
{
	int n = Int_to(int, sfp[1]);
	CvCapture *capture = cvCaptureFromCAM(n);
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, capture, NULL);
	RETURN_(rptr);
}

KMETHOD QWebCamera_queryFrame(CTX ctx, ksfp_t *sfp _RIX)
{
	CvCapture *capture = RawPtr_to(CvCapture *, sfp[0]);
	IplImage *frame = cvQueryFrame(capture);//not allocated
	QImage *image = convertFromIplImageToQImage(frame);
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, image, NULL);
	RETURN_(rptr);
}

KMETHOD QVideo_new(CTX ctx, ksfp_t *sfp _RIX)
{
	const char *filename = String_to(const char *, sfp[1]);
	CvCapture *capture = cvCaptureFromAVI(filename);
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, capture, NULL);
	RETURN_(rptr);
}

KMETHOD QVideo_queryFrame(CTX ctx, ksfp_t *sfp _RIX)
{
	CvCapture *capture = RawPtr_to(CvCapture *, sfp[0]);
	IplImage *frame = cvQueryFrame(capture);//not allocated
	QImage *image = convertFromIplImageToQImage(frame);
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, image, NULL);
	RETURN_(rptr);
}

//typedef QList<QList<QPointF> *> QEdgePoints
static QList<QList<QPointF> *> *createEdgePoint(IplImage *src_img)
{
	CvMemStorage *storage = cvCreateMemStorage(0);
	CvSeq *contours = NULL;
	IplImage *src_img_gray = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	cvCvtColor(src_img, src_img_gray, CV_BGR2GRAY);
	IplImage *tmp_img = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	cvThreshold(src_img_gray, tmp_img, 120, 255, CV_THRESH_BINARY);
	cvFindContours(tmp_img, storage, &contours, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	QList<QList<QPointF> *> *list = new QList<QList<QPointF> *>();
	while (1) {
		if (contours == NULL) break;
		QList<QPointF> *pts = new QList<QPointF>();
		for (int i = 0; i < contours->total; i++) {
			CvPoint *point = CV_GET_SEQ_ELEM(CvPoint, contours, i);
			pts->append(QPointF(point->x, point->y));
		}
		list->append(pts);
		if (contours->h_next == NULL) break;
		contours = contours->h_next;
	}
	cvReleaseImage(&src_img_gray);
	cvReleaseImage(&tmp_img);
	cvReleaseMemStorage(&storage);
	return list;
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

//QImage QImage.binarization(QColor threshold_color);
KMETHOD QImage_binarization(CTX ctx, ksfp_t *sfp _RIX)
{
	QImage *image = RawPtr_to(QImage *, sfp[0]);
	if (image) {
		QColor *color = RawPtr_to(QColor *, sfp[1]);
		QImage *ret = new QImage(*image);
		QRgb rgb = color->rgb();
		int red = qRed(rgb);
		int green = qGreen(rgb);
		int blue = qBlue(rgb);
		int width = ret->width();
		int height = ret->height();
		for (int y = 0; y < height; y++) {
			QRgb *row = (QRgb*)ret->scanLine(y);
			for (int x = 0; x < width; x++) {
				unsigned char *r = (unsigned char*)&row[x];
				if (r[0] == red && r[1] == green && r[2] == blue) {
					r[0] = 0x00;
					r[1] = 0x00;
					r[2] = 0x00;
				} else {
					r[0] = 0xff;
					r[1] = 0xff;
					r[2] = 0xff;
				}
			}
		}
		//IplImage *iplimage = QImage_toIplImage(*image);
		//ret = convertFromIplImageToQImage(iplimage);
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, ret, NULL);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.permeabilization(QColor c);
KMETHOD QImage_permeabilization(CTX ctx, ksfp_t *sfp _RIX)
{
	QImage *image = RawPtr_to(QImage *, sfp[0]);
	if (image) {
		QImage alpha_image = image->convertToFormat(QImage::Format_ARGB32);
		QColor *color = RawPtr_to(QColor *, sfp[1]);
		QImage *ret = new QImage(alpha_image);
		QRgb rgb = color->rgb();
		int red = qRed(rgb);
		int green = qGreen(rgb);
		int blue = qBlue(rgb);
		int width = ret->width();
		int height = ret->height();
		for (int y = 0; y < height; y++) {
			QRgb *row = (QRgb*)ret->scanLine(y);
			for (int x = 0; x < width; x++) {
				unsigned char *r = (unsigned char*)&row[x];
				if (r[0] == red && r[1] == green && r[2] == blue) {
					r[3] = 0x00;
				}
			}
		}
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, ret, NULL);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF[][] QImage.getEdgePoints();
KMETHOD QImage_getEdgePoints(CTX ctx, ksfp_t *sfp _RIX)
{
	QImage *image = RawPtr_to(QImage *, sfp[0]);
	IplImage *iplimage = QImage_toIplImage(*image);
	QList<QList<QPointF> *> *list = createEdgePoint(iplimage);
	int size = list->size();
	kArray *a = new_Array0(ctx, size);
	kclass_t cid = knh_getcid(ctx, STEXT("QPointF"));
	for (int i = 0; i < size; i++) {
		QList<QPointF> *pts = list->at(i);
		int pts_size = pts->size();
		kArray *elem = new_Array0(ctx, pts_size);
		for (int j = 0; j < pts_size; j++) {
			QPointF pt = pts->at(j);
			kRawPtr *p = new_RawPtr(ctx, ClassTBL(cid), new QPointF(pt));
			knh_Array_add(ctx, elem, p);
		}
		knh_Array_add(ctx, a, elem);
	}
	RETURN_(a);
}

//QPointF[][] QImage.getEdgePointsUsingAlpha();
KMETHOD QImage_getEdgePointsUsingAlpha(CTX ctx, ksfp_t *sfp _RIX)
{
	QImage *image = RawPtr_to(QImage *, sfp[0]);
	QImage ret(*image);
	int width = ret.width();
	int height = ret.height();
	for (int y = 0; y < height; y++) {
		QRgb *row = (QRgb*)ret.scanLine(y);
		for (int x = 0; x < width; x++) {
			unsigned char *r = (unsigned char*)&row[x];
			if (r[3] == 0x00) {
				r[0] = 0x00;
				r[1] = 0x00;
				r[2] = 0x00;
			} else {
				r[0] = 0xff;
				r[1] = 0xff;
				r[2] = 0xff;
			}
		}
	}
	IplImage *iplimage = QImage_toIplImage(ret);
	QList<QList<QPointF> *> *list = createEdgePoint(iplimage);
	int size = list->size();
	kArray *a = new_Array0(ctx, size);
	kclass_t cid = knh_getcid(ctx, STEXT("QPointF"));
	for (int i = 0; i < size; i++) {
		QList<QPointF> *pts = list->at(i);
		int pts_size = pts->size();
		kArray *elem = new_Array0(ctx, pts_size);
		for (int j = 0; j < pts_size; j++) {
			QPointF pt = pts->at(j);
			kRawPtr *p = new_RawPtr(ctx, ClassTBL(cid), new QPointF(pt));
			knh_Array_add(ctx, elem, p);
		}
		knh_Array_add(ctx, a, elem);
	}
	RETURN_(a);
}

DEFAPI(const knh_PackageDef_t*) init(CTX, const knh_LoaderAPI_t *)
{
	RETURN_PKGINFO("qopencv");
}

#ifdef __cplusplus
}
#endif
