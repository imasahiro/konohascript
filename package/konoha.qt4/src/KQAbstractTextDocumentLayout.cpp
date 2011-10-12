//
//String QAbstractTextDocumentLayout.anchorAt(QPointF position);
KMETHOD QAbstractTextDocumentLayout_anchorAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		QString ret_v = qp->anchorAt(position);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRectF QAbstractTextDocumentLayout.blockBoundingRect(QTextBlock block);
KMETHOD QAbstractTextDocumentLayout_blockBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
		QRectF ret_v = qp->blockBoundingRect(block);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextDocument QAbstractTextDocumentLayout.document();
KMETHOD QAbstractTextDocumentLayout_document(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QSizeF QAbstractTextDocumentLayout.documentSize();
KMETHOD QAbstractTextDocumentLayout_documentSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QSizeF ret_v = qp->documentSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractTextDocumentLayout.draw(QPainter painter, int context);
KMETHOD QAbstractTextDocumentLayout_draw(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QAbstractTextDocumentLayout::PaintContext  context = *RawPtr_to(const QAbstractTextDocumentLayout::PaintContext *, sfp[2]);
		qp->draw(painter, context);
	}
	RETURNvoid_();
}

//@Virtual QRectF QAbstractTextDocumentLayout.frameBoundingRect(QTextFrame frame);
KMETHOD QAbstractTextDocumentLayout_frameBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QTextFrame*  frame = RawPtr_to(QTextFrame*, sfp[1]);
		QRectF ret_v = qp->frameBoundingRect(frame);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextObjectInterface QAbstractTextDocumentLayout.handlerForObject(int objectType);
KMETHOD QAbstractTextDocumentLayout_handlerForObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		int objectType = Int_to(int, sfp[1]);
		QTextObjectInterface* ret_v = qp->handlerForObject(objectType);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextObjectInterface*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAbstractTextDocumentLayout.hitTest(QPointF point, int accuracy);
KMETHOD QAbstractTextDocumentLayout_hitTest(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		Qt::HitTestAccuracy accuracy = Int_to(Qt::HitTestAccuracy, sfp[2]);
		int ret_v = qp->hitTest(point, accuracy);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QAbstractTextDocumentLayout.pageCount();
KMETHOD QAbstractTextDocumentLayout_pageCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pageCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPaintDevice QAbstractTextDocumentLayout.getPaintDevice();
KMETHOD QAbstractTextDocumentLayout_getPaintDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QPaintDevice* ret_v = qp->paintDevice();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintDevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractTextDocumentLayout.registerHandler(int objectType, QObject component);
KMETHOD QAbstractTextDocumentLayout_registerHandler(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		int objectType = Int_to(int, sfp[1]);
		QObject*  component = RawPtr_to(QObject*, sfp[2]);
		qp->registerHandler(objectType, component);
	}
	RETURNvoid_();
}

//void QAbstractTextDocumentLayout.setPaintDevice(QPaintDevice device);
KMETHOD QAbstractTextDocumentLayout_setPaintDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QPaintDevice*  device = RawPtr_to(QPaintDevice*, sfp[1]);
		qp->setPaintDevice(device);
	}
	RETURNvoid_();
}


DummyQAbstractTextDocumentLayout::DummyQAbstractTextDocumentLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractTextDocumentLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractTextDocumentLayout::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractTextDocumentLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractTextDocumentLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTextDocumentLayout::event_map->bigin();
	if ((itr = DummyQAbstractTextDocumentLayout::event_map->find(str)) == DummyQAbstractTextDocumentLayout::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractTextDocumentLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTextDocumentLayout::slot_map->bigin();
	if ((itr = DummyQAbstractTextDocumentLayout::event_map->find(str)) == DummyQAbstractTextDocumentLayout::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractTextDocumentLayout::KQAbstractTextDocumentLayout(QTextDocument* document) : QAbstractTextDocumentLayout(document)
{
	self = NULL;
}

KMETHOD QAbstractTextDocumentLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractTextDocumentLayout *qp = RawPtr_to(KQAbstractTextDocumentLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractTextDocumentLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQAbstractTextDocumentLayout::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractTextDocumentLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QAbstractTextDocumentLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractTextDocumentLayout *qp = RawPtr_to(KQAbstractTextDocumentLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractTextDocumentLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQAbstractTextDocumentLayout::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractTextDocumentLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractTextDocumentLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractTextDocumentLayout *qp = (KQAbstractTextDocumentLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractTextDocumentLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractTextDocumentLayout *qp = (KQAbstractTextDocumentLayout *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractTextDocumentLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQAbstractTextDocumentLayout::event(QEvent *event)
{
	if (!DummyQAbstractTextDocumentLayout::eventDispatcher(event)) {
		QAbstractTextDocumentLayout::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQAbstractTextDocumentLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractTextDocumentLayout";
	cdef->free = QAbstractTextDocumentLayout_free;
	cdef->reftrace = QAbstractTextDocumentLayout_reftrace;
	cdef->compareTo = QAbstractTextDocumentLayout_compareTo;
}


