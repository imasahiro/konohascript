//QTextTableFormat QTextTableFormat.new();
KMETHOD QTextTableFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableFormat *ret_v = new KQTextTableFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QtAlignment QTextTableFormat.getAlignment();
KMETHOD QTextTableFormat_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextTableFormat.getCellPadding();
KMETHOD QTextTableFormat_getCellPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->cellPadding();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextTableFormat.getCellSpacing();
KMETHOD QTextTableFormat_getCellSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->cellSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTextTableFormat.clearColumnWidthConstraints();
KMETHOD QTextTableFormat_clearColumnWidthConstraints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		qp->clearColumnWidthConstraints();
	}
	RETURNvoid_();
}

//int QTextTableFormat.columns();
KMETHOD QTextTableFormat_columns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->columns();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextTableFormat.getHeaderRowCount();
KMETHOD QTextTableFormat_getHeaderRowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->headerRowCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextTableFormat.setAlignment(QtAlignment alignment);
KMETHOD QTextTableFormat_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QTextTableFormat.setCellPadding(float padding);
KMETHOD QTextTableFormat_setCellPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		qreal padding = Float_to(qreal, sfp[1]);
		qp->setCellPadding(padding);
	}
	RETURNvoid_();
}

//void QTextTableFormat.setCellSpacing(float spacing);
KMETHOD QTextTableFormat_setCellSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setCellSpacing(spacing);
	}
	RETURNvoid_();
}

//void QTextTableFormat.setHeaderRowCount(int count);
KMETHOD QTextTableFormat_setHeaderRowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp) {
		int count = Int_to(int, sfp[1]);
		qp->setHeaderRowCount(count);
	}
	RETURNvoid_();
}


DummyQTextTableFormat::DummyQTextTableFormat()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextTableFormat::~DummyQTextTableFormat()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextTableFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextTableFormat::self = ptr;
	DummyQTextFrameFormat::setSelf(ptr);
}

bool DummyQTextTableFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextFrameFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextTableFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableFormat::event_map->bigin();
	if ((itr = DummyQTextTableFormat::event_map->find(str)) == DummyQTextTableFormat::event_map->end()) {
		bool ret = false;
		ret = DummyQTextFrameFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextTableFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableFormat::slot_map->bigin();
	if ((itr = DummyQTextTableFormat::slot_map->find(str)) == DummyQTextTableFormat::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextFrameFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextTableFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextTableFormat::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQTextFrameFormat::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTextTableFormat::connection(QObject *o)
{
	QTextTableFormat *p = dynamic_cast<QTextTableFormat*>(o);
	if (p != NULL) {
	}
	DummyQTextFrameFormat::connection(o);
}

KQTextTableFormat::KQTextTableFormat() : QTextTableFormat()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextTableFormat();
}

KQTextTableFormat::~KQTextTableFormat()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextTableFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableFormat *qp = RawPtr_to(KQTextTableFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTableFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextTableFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableFormat *qp = RawPtr_to(KQTextTableFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTableFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextTableFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextTableFormat *qp = (KQTextTableFormat *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextTableFormat*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextTableFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextTableFormat *qp = (KQTextTableFormat *)p->rawptr;
		KQTextTableFormat *qp = static_cast<KQTextTableFormat*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextTableFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextTableFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextTableFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextTableFormat";
	cdef->free = QTextTableFormat_free;
	cdef->reftrace = QTextTableFormat_reftrace;
	cdef->compareTo = QTextTableFormat_compareTo;
}


