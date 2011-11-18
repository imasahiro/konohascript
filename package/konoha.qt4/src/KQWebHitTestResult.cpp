//QWebHitTestResult QWebHitTestResult.new();
KMETHOD QWebHitTestResult_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHitTestResult *ret_v = new KQWebHitTestResult();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QWebHitTestResult QWebHitTestResult.new(QWebHitTestResult other);
KMETHOD QWebHitTestResult_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebHitTestResult  other = *RawPtr_to(const QWebHitTestResult *, sfp[1]);
	KQWebHitTestResult *ret_v = new KQWebHitTestResult(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QWebHitTestResult.alternateText();
KMETHOD QWebHitTestResult_alternateText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QString ret_v = qp->alternateText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWebHitTestResult.boundingRect();
KMETHOD QWebHitTestResult_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->boundingRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebHitTestResult.element();
KMETHOD QWebHitTestResult_element(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->element();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebHitTestResult.enclosingBlockElement();
KMETHOD QWebHitTestResult_enclosingBlockElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->enclosingBlockElement();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebFrame QWebHitTestResult.frame();
KMETHOD QWebHitTestResult_frame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QWebFrame* ret_v = qp->frame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebHitTestResult.imageUrl();
KMETHOD QWebHitTestResult_imageUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->imageUrl();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebHitTestResult.isContentEditable();
KMETHOD QWebHitTestResult_isContentEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isContentEditable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebHitTestResult.isContentSelected();
KMETHOD QWebHitTestResult_isContentSelected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isContentSelected();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebElement QWebHitTestResult.linkElement();
KMETHOD QWebHitTestResult_linkElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->linkElement();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebFrame QWebHitTestResult.linkTargetFrame();
KMETHOD QWebHitTestResult_linkTargetFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QWebFrame* ret_v = qp->linkTargetFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebHitTestResult.linkText();
KMETHOD QWebHitTestResult_linkText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QString ret_v = qp->linkText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebHitTestResult.linkTitle();
KMETHOD QWebHitTestResult_linkTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->linkTitle();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebHitTestResult.linkUrl();
KMETHOD QWebHitTestResult_linkUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->linkUrl();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QWebHitTestResult.pixmap();
KMETHOD QWebHitTestResult_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QPixmap ret_v = qp->pixmap();
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWebHitTestResult.pos();
KMETHOD QWebHitTestResult_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebHitTestResult.title();
KMETHOD QWebHitTestResult_title(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *  qp = RawPtr_to(QWebHitTestResult *, sfp[0]);
	if (qp) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QWebHitTestResult.parents();
KMETHOD QWebHitTestResult_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHitTestResult *qp = RawPtr_to(QWebHitTestResult*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQWebHitTestResult::DummyQWebHitTestResult()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQWebHitTestResult::~DummyQWebHitTestResult()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQWebHitTestResult::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebHitTestResult::self = ptr;
}

bool DummyQWebHitTestResult::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebHitTestResult::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHitTestResult::event_map->bigin();
	if ((itr = DummyQWebHitTestResult::event_map->find(str)) == DummyQWebHitTestResult::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebHitTestResult::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHitTestResult::slot_map->bigin();
	if ((itr = DummyQWebHitTestResult::slot_map->find(str)) == DummyQWebHitTestResult::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebHitTestResult::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebHitTestResult::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebHitTestResult::connection(QObject *o)
{
	QWebHitTestResult *p = dynamic_cast<QWebHitTestResult*>(o);
	if (p != NULL) {
	}
}

KQWebHitTestResult::KQWebHitTestResult() : QWebHitTestResult()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQWebHitTestResult();
}

KQWebHitTestResult::~KQWebHitTestResult()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QWebHitTestResult_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHitTestResult *qp = RawPtr_to(KQWebHitTestResult *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHitTestResult]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHitTestResult]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebHitTestResult_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHitTestResult *qp = RawPtr_to(KQWebHitTestResult *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHitTestResult]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHitTestResult]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebHitTestResult_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQWebHitTestResult *qp = (KQWebHitTestResult *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QWebHitTestResult*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QWebHitTestResult_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQWebHitTestResult *qp = (KQWebHitTestResult *)p->rawptr;
		KQWebHitTestResult *qp = static_cast<KQWebHitTestResult*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebHitTestResult_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebHitTestResult::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWebHitTestResult(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebHitTestResult";
	cdef->free = QWebHitTestResult_free;
	cdef->reftrace = QWebHitTestResult_reftrace;
	cdef->compareTo = QWebHitTestResult_compareTo;
}


