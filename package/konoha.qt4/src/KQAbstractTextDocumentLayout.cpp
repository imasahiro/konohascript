//
//String QAbstractTextDocumentLayout.anchorAt(QPointF position);
KMETHOD QAbstractTextDocumentLayout_anchorAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QSizeF ret_v = qp->documentSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRectF QAbstractTextDocumentLayout.frameBoundingRect(QTextFrame frame);
KMETHOD QAbstractTextDocumentLayout_frameBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTextDocumentLayout *  qp = RawPtr_to(QAbstractTextDocumentLayout *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QPaintDevice*  device = RawPtr_to(QPaintDevice*, sfp[1]);
		qp->setPaintDevice(device);
	}
	RETURNvoid_();
}


DummyQAbstractTextDocumentLayout::DummyQAbstractTextDocumentLayout()
{
	self = NULL;
	document_size_changed_func = NULL;
	page_count_changed_func = NULL;
	update_func = NULL;
	update_block_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("document-size-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("page-count-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("update", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("update-block", NULL));
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

bool DummyQAbstractTextDocumentLayout::documentSizeChangedSlot(const QSizeF new_Size)
{
	if (document_size_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QSizeF, new_Size);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, document_size_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractTextDocumentLayout::pageCountChangedSlot(int new_Pages)
{
	if (page_count_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = new_Pages;
		knh_Func_invoke(lctx, page_count_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractTextDocumentLayout::updateSlot(const QRectF rect)
{
	if (update_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QRectF, rect);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, update_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractTextDocumentLayout::updateBlockSlot(const QTextBlock block)
{
	if (update_block_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QTextBlock, block);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, update_block_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractTextDocumentLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTextDocumentLayout::event_map->bigin();
	if ((itr = DummyQAbstractTextDocumentLayout::event_map->find(str)) == DummyQAbstractTextDocumentLayout::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQAbstractTextDocumentLayout::slot_map->find(str)) == DummyQAbstractTextDocumentLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		document_size_changed_func = (*slot_map)["document-size-changed"];
		page_count_changed_func = (*slot_map)["page-count-changed"];
		update_func = (*slot_map)["update"];
		update_block_func = (*slot_map)["update-block"];
		return true;
	}
}

knh_Object_t** DummyQAbstractTextDocumentLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractTextDocumentLayout::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, document_size_changed_func);
	KNH_ADDNNREF(ctx, page_count_changed_func);
	KNH_ADDNNREF(ctx, update_func);
	KNH_ADDNNREF(ctx, update_block_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractTextDocumentLayout::connection(QObject *o)
{
	QAbstractTextDocumentLayout *p = dynamic_cast<QAbstractTextDocumentLayout*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(documentSizeChanged(const QSizeF)), this, SLOT(documentSizeChangedSlot(const QSizeF)));
		connect(p, SIGNAL(pageCountChanged(int)), this, SLOT(pageCountChangedSlot(int)));
		connect(p, SIGNAL(update(const QRectF)), this, SLOT(updateSlot(const QRectF)));
		connect(p, SIGNAL(updateBlock(const QTextBlock)), this, SLOT(updateBlockSlot(const QTextBlock)));
	}
	DummyQObject::connection(o);
}

KQAbstractTextDocumentLayout::KQAbstractTextDocumentLayout(QTextDocument* document) : QAbstractTextDocumentLayout(document)
{
	self = NULL;
	dummy = new DummyQAbstractTextDocumentLayout();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQAbstractTextDocumentLayout *qp = (KQAbstractTextDocumentLayout *)p->rawptr;
//		KQAbstractTextDocumentLayout *qp = static_cast<KQAbstractTextDocumentLayout*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractTextDocumentLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractTextDocumentLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractTextDocumentLayout::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractTextDocumentLayout::event(event);
		return false;
	}
//	QAbstractTextDocumentLayout::event(event);
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


