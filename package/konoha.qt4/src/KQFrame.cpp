//@Virtual @Override QSize QFrame.sizeHint();
KMETHOD QFrame_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFrame QFrame.new(QWidget parent, QtWindowFlags f);
KMETHOD QFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(f, Qt::WindowFlags, sfp[2]);
	KQFrame *ret_v = new KQFrame(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QRect QFrame.getFrameRect();
KMETHOD QFrame_getFrameRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->frameRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFrame.getFrameShadow();
KMETHOD QFrame_getFrameShadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		QFrame::Shadow ret_v = qp->frameShadow();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFrame.getFrameShape();
KMETHOD QFrame_getFrameShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		QFrame::Shape ret_v = qp->frameShape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFrame.getFrameStyle();
KMETHOD QFrame_getFrameStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int ret_v = qp->frameStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFrame.frameWidth();
KMETHOD QFrame_frameWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int ret_v = qp->frameWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFrame.getLineWidth();
KMETHOD QFrame_getLineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int ret_v = qp->lineWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFrame.getMidLineWidth();
KMETHOD QFrame_getMidLineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int ret_v = qp->midLineWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFrame.setFrameRect(QRect arg0);
KMETHOD QFrame_setFrameRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		const QRect  arg0 = *RawPtr_to(const QRect *, sfp[1]);
		qp->setFrameRect(arg0);
	}
	RETURNvoid_();
}

//void QFrame.setFrameShadow(int arg0);
KMETHOD QFrame_setFrameShadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		QFrame::Shadow arg0 = Int_to(QFrame::Shadow, sfp[1]);
		qp->setFrameShadow(arg0);
	}
	RETURNvoid_();
}

//void QFrame.setFrameShape(int arg0);
KMETHOD QFrame_setFrameShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		QFrame::Shape arg0 = Int_to(QFrame::Shape, sfp[1]);
		qp->setFrameShape(arg0);
	}
	RETURNvoid_();
}

//void QFrame.setFrameStyle(int style);
KMETHOD QFrame_setFrameStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int style = Int_to(int, sfp[1]);
		qp->setFrameStyle(style);
	}
	RETURNvoid_();
}

//void QFrame.setLineWidth(int arg0);
KMETHOD QFrame_setLineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setLineWidth(arg0);
	}
	RETURNvoid_();
}

//void QFrame.setMidLineWidth(int arg0);
KMETHOD QFrame_setMidLineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFrame *  qp = RawPtr_to(QFrame *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setMidLineWidth(arg0);
	}
	RETURNvoid_();
}


DummyQFrame::DummyQFrame()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFrame::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFrame::event_map->bigin();
	if ((itr = DummyQFrame::event_map->find(str)) == DummyQFrame::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFrame::slot_map->bigin();
	if ((itr = DummyQFrame::slot_map->find(str)) == DummyQFrame::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQFrame::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQFrame::connection(QObject *o)
{
	QFrame *p = dynamic_cast<QFrame*>(o);
	if (p != NULL) {
	}
	DummyQWidget::connection(o);
}

KQFrame::KQFrame(QWidget* parent, Qt::WindowFlags f) : QFrame(parent, f)
{
	self = NULL;
	dummy = new DummyQFrame();
	dummy->connection((QObject*)this);
}

KMETHOD QFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFrame *qp = RawPtr_to(KQFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFrame *qp = RawPtr_to(KQFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFrame *qp = (KQFrame *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQFrame *qp = (KQFrame *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFrame::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFrame::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFrame::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QFrameConstInt[] = {
	{"Plain", QFrame::Plain},
	{"Raised", QFrame::Raised},
	{"Sunken", QFrame::Sunken},
	{"NoFrame", QFrame::NoFrame},
	{"Box", QFrame::Box},
	{"Panel", QFrame::Panel},
	{"StyledPanel", QFrame::StyledPanel},
	{"HLine", QFrame::HLine},
	{"VLine", QFrame::VLine},
	{"WinPanel", QFrame::WinPanel},
	{"Shadow_Mask", QFrame::Shadow_Mask},
	{"Shape_Mask", QFrame::Shape_Mask},
	{NULL, 0}
};

DEFAPI(void) constQFrame(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFrameConstInt);
}


DEFAPI(void) defQFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFrame";
	cdef->free = QFrame_free;
	cdef->reftrace = QFrame_reftrace;
	cdef->compareTo = QFrame_compareTo;
}


