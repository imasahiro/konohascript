//QTextTableFormat QTextTableFormat.new();
KMETHOD QTextTableFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableFormat *ret_v = new KQTextTableFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTextTableFormat.getAlignment();
KMETHOD QTextTableFormat_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextTableFormat.getCellPadding();
KMETHOD QTextTableFormat_getCellPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->clearColumnWidthConstraints();
	}
	RETURNvoid_();
}

//int QTextTableFormat.columns();
KMETHOD QTextTableFormat_columns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		int ret_v = qp->headerRowCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QTextTableFormat.isValid();
KMETHOD QTextTableFormat_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextTableFormat.setAlignment(int alignment);
KMETHOD QTextTableFormat_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QTextTableFormat.setCellPadding(float padding);
KMETHOD QTextTableFormat_setCellPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableFormat *  qp = RawPtr_to(QTextTableFormat *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		int count = Int_to(int, sfp[1]);
		qp->setHeaderRowCount(count);
	}
	RETURNvoid_();
}


DummyQTextTableFormat::DummyQTextTableFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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
		bool ret;
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
	if ((itr = DummyQTextTableFormat::event_map->find(str)) == DummyQTextTableFormat::slot_map->end()) {
		bool ret;
		ret = DummyQTextFrameFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextTableFormat::KQTextTableFormat() : QTextTableFormat()
{
	self = NULL;
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
		if (!qp->DummyQTextTableFormat::addEvent(callback_func, str)) {
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
		if (!qp->DummyQTextTableFormat::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextTableFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextTableFormat *qp = (KQTextTableFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextTableFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextTableFormat *qp = (KQTextTableFormat *)p->rawptr;
		(void)qp;
	}
}

static int QTextTableFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextTableFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextTableFormat";
	cdef->free = QTextTableFormat_free;
	cdef->reftrace = QTextTableFormat_reftrace;
	cdef->compareTo = QTextTableFormat_compareTo;
}


