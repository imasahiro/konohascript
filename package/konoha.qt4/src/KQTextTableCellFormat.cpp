//QTextTableCellFormat QTextTableCellFormat.new();
KMETHOD QTextTableCellFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCellFormat *ret_v = new KQTextTableCellFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QTextTableCellFormat.getBottomPadding();
KMETHOD QTextTableCellFormat_getBottomPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->bottomPadding();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextTableCellFormat.getLeftPadding();
KMETHOD QTextTableCellFormat_getLeftPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->leftPadding();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextTableCellFormat.getRightPadding();
KMETHOD QTextTableCellFormat_getRightPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->rightPadding();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTextTableCellFormat.setBottomPadding(float padding);
KMETHOD QTextTableCellFormat_setBottomPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal padding = Float_to(qreal, sfp[1]);
		qp->setBottomPadding(padding);
	}
	RETURNvoid_();
}

//void QTextTableCellFormat.setLeftPadding(float padding);
KMETHOD QTextTableCellFormat_setLeftPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal padding = Float_to(qreal, sfp[1]);
		qp->setLeftPadding(padding);
	}
	RETURNvoid_();
}

//void QTextTableCellFormat.setPadding(float padding);
KMETHOD QTextTableCellFormat_setPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal padding = Float_to(qreal, sfp[1]);
		qp->setPadding(padding);
	}
	RETURNvoid_();
}

//void QTextTableCellFormat.setRightPadding(float padding);
KMETHOD QTextTableCellFormat_setRightPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal padding = Float_to(qreal, sfp[1]);
		qp->setRightPadding(padding);
	}
	RETURNvoid_();
}

//void QTextTableCellFormat.setTopPadding(float padding);
KMETHOD QTextTableCellFormat_setTopPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal padding = Float_to(qreal, sfp[1]);
		qp->setTopPadding(padding);
	}
	RETURNvoid_();
}

//float QTextTableCellFormat.getTopPadding();
KMETHOD QTextTableCellFormat_getTopPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCellFormat *  qp = RawPtr_to(QTextTableCellFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->topPadding();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQTextTableCellFormat::DummyQTextTableCellFormat()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextTableCellFormat::~DummyQTextTableCellFormat()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextTableCellFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextTableCellFormat::self = ptr;
	DummyQTextCharFormat::setSelf(ptr);
}

bool DummyQTextTableCellFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextCharFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextTableCellFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableCellFormat::event_map->bigin();
	if ((itr = DummyQTextTableCellFormat::event_map->find(str)) == DummyQTextTableCellFormat::event_map->end()) {
		bool ret = false;
		ret = DummyQTextCharFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextTableCellFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableCellFormat::slot_map->bigin();
	if ((itr = DummyQTextTableCellFormat::slot_map->find(str)) == DummyQTextTableCellFormat::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextCharFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextTableCellFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextTableCellFormat::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQTextCharFormat::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTextTableCellFormat::connection(QObject *o)
{
	QTextTableCellFormat *p = dynamic_cast<QTextTableCellFormat*>(o);
	if (p != NULL) {
	}
	DummyQTextCharFormat::connection(o);
}

KQTextTableCellFormat::KQTextTableCellFormat() : QTextTableCellFormat()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextTableCellFormat();
}

KQTextTableCellFormat::~KQTextTableCellFormat()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextTableCellFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCellFormat *qp = RawPtr_to(KQTextTableCellFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTableCellFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableCellFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextTableCellFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCellFormat *qp = RawPtr_to(KQTextTableCellFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTableCellFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableCellFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextTableCellFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextTableCellFormat *qp = (KQTextTableCellFormat *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextTableCellFormat*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextTableCellFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextTableCellFormat *qp = (KQTextTableCellFormat *)p->rawptr;
		KQTextTableCellFormat *qp = static_cast<KQTextTableCellFormat*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextTableCellFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextTableCellFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextTableCellFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextTableCellFormat";
	cdef->free = QTextTableCellFormat_free;
	cdef->reftrace = QTextTableCellFormat_reftrace;
	cdef->compareTo = QTextTableCellFormat_compareTo;
}


