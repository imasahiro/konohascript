//@Virtual @Override QRectF QPlainTextDocumentLayout.blockBoundingRect(QTextBlock block);
KMETHOD QPlainTextDocumentLayout_blockBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
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

//@Virtual @Override QSizeF QPlainTextDocumentLayout.documentSize();
KMETHOD QPlainTextDocumentLayout_documentSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QSizeF ret_v = qp->documentSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QPlainTextDocumentLayout.draw(QPainter arg0, int arg1);
KMETHOD QPlainTextDocumentLayout_draw(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QPainter*  arg0 = RawPtr_to(QPainter*, sfp[1]);
		const QPlainTextDocumentLayout::PaintContext  arg1 = *RawPtr_to(const QPlainTextDocumentLayout::PaintContext *, sfp[2]);
		qp->draw(arg0, arg1);
	}
	RETURNvoid_();
}

//@Virtual @Override QRectF QPlainTextDocumentLayout.frameBoundingRect(QTextFrame arg0);
KMETHOD QPlainTextDocumentLayout_frameBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		QTextFrame*  arg0 = RawPtr_to(QTextFrame*, sfp[1]);
		QRectF ret_v = qp->frameBoundingRect(arg0);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QPlainTextDocumentLayout.hitTest(QPointF arg0, int arg1);
KMETHOD QPlainTextDocumentLayout_hitTest(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		const QPointF  arg0 = *RawPtr_to(const QPointF *, sfp[1]);
		Qt::HitTestAccuracy arg1 = Int_to(Qt::HitTestAccuracy, sfp[2]);
		int ret_v = qp->hitTest(arg0, arg1);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override int QPlainTextDocumentLayout.pageCount();
KMETHOD QPlainTextDocumentLayout_pageCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pageCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPlainTextDocumentLayout QPlainTextDocumentLayout.new(QTextDocument document);
KMETHOD QPlainTextDocumentLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument*  document = RawPtr_to(QTextDocument*, sfp[1]);
	KQPlainTextDocumentLayout *ret_v = new KQPlainTextDocumentLayout(document);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QPlainTextDocumentLayout.getCursorWidth();
KMETHOD QPlainTextDocumentLayout_getCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->cursorWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPlainTextDocumentLayout.ensureBlockLayout(QTextBlock block);
KMETHOD QPlainTextDocumentLayout_ensureBlockLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
		qp->ensureBlockLayout(block);
	}
	RETURNvoid_();
}

//void QPlainTextDocumentLayout.requestUpdate();
KMETHOD QPlainTextDocumentLayout_requestUpdate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		qp->requestUpdate();
	}
	RETURNvoid_();
}

//void QPlainTextDocumentLayout.setCursorWidth(int width);
KMETHOD QPlainTextDocumentLayout_setCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextDocumentLayout *  qp = RawPtr_to(QPlainTextDocumentLayout *, sfp[0]);
	if (qp != NULL) {
		int width = Int_to(int, sfp[1]);
		qp->setCursorWidth(width);
	}
	RETURNvoid_();
}


DummyQPlainTextDocumentLayout::DummyQPlainTextDocumentLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPlainTextDocumentLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPlainTextDocumentLayout::self = ptr;
	DummyQAbstractTextDocumentLayout::setSelf(ptr);
}

bool DummyQPlainTextDocumentLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractTextDocumentLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPlainTextDocumentLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPlainTextDocumentLayout::event_map->bigin();
	if ((itr = DummyQPlainTextDocumentLayout::event_map->find(str)) == DummyQPlainTextDocumentLayout::event_map->end()) {
		bool ret;
		ret = DummyQAbstractTextDocumentLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPlainTextDocumentLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPlainTextDocumentLayout::slot_map->bigin();
	if ((itr = DummyQPlainTextDocumentLayout::event_map->find(str)) == DummyQPlainTextDocumentLayout::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractTextDocumentLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPlainTextDocumentLayout::KQPlainTextDocumentLayout(QTextDocument* document) : QPlainTextDocumentLayout(document)
{
	self = NULL;
}

KMETHOD QPlainTextDocumentLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPlainTextDocumentLayout *qp = RawPtr_to(KQPlainTextDocumentLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPlainTextDocumentLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPlainTextDocumentLayout::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPlainTextDocumentLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPlainTextDocumentLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPlainTextDocumentLayout *qp = RawPtr_to(KQPlainTextDocumentLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPlainTextDocumentLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPlainTextDocumentLayout::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPlainTextDocumentLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPlainTextDocumentLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPlainTextDocumentLayout *qp = (KQPlainTextDocumentLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPlainTextDocumentLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPlainTextDocumentLayout *qp = (KQPlainTextDocumentLayout *)p->rawptr;
		(void)qp;
	}
}

static int QPlainTextDocumentLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQPlainTextDocumentLayout::event(QEvent *event)
{
	if (!DummyQPlainTextDocumentLayout::eventDispatcher(event)) {
		QPlainTextDocumentLayout::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQPlainTextDocumentLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPlainTextDocumentLayout";
	cdef->free = QPlainTextDocumentLayout_free;
	cdef->reftrace = QPlainTextDocumentLayout_reftrace;
	cdef->compareTo = QPlainTextDocumentLayout_compareTo;
}


