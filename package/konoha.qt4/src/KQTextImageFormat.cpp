//QTextImageFormat QTextImageFormat.new();
KMETHOD QTextImageFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextImageFormat *ret_v = new KQTextImageFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QTextImageFormat.getHeight();
KMETHOD QTextImageFormat_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

////boolean QTextImageFormat.isValid();
KMETHOD QTextImageFormat_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QTextImageFormat.getName();
KMETHOD QTextImageFormat_getName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextImageFormat.setHeight(float height);
KMETHOD QTextImageFormat_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}

//void QTextImageFormat.setName(String name);
KMETHOD QTextImageFormat_setName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setName(name);
	}
	RETURNvoid_();
}

//void QTextImageFormat.setWidth(float width);
KMETHOD QTextImageFormat_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//float QTextImageFormat.getWidth();
KMETHOD QTextImageFormat_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQTextImageFormat::DummyQTextImageFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextImageFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextImageFormat::self = ptr;
	DummyQTextCharFormat::setSelf(ptr);
}

bool DummyQTextImageFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextCharFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextImageFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextImageFormat::event_map->bigin();
	if ((itr = DummyQTextImageFormat::event_map->find(str)) == DummyQTextImageFormat::event_map->end()) {
		bool ret;
		ret = DummyQTextCharFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextImageFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextImageFormat::slot_map->bigin();
	if ((itr = DummyQTextImageFormat::event_map->find(str)) == DummyQTextImageFormat::slot_map->end()) {
		bool ret;
		ret = DummyQTextCharFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextImageFormat::KQTextImageFormat() : QTextImageFormat()
{
	self = NULL;
}

KMETHOD QTextImageFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextImageFormat *qp = RawPtr_to(KQTextImageFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextImageFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextImageFormat::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextImageFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextImageFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextImageFormat *qp = RawPtr_to(KQTextImageFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextImageFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextImageFormat::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextImageFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextImageFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextImageFormat *qp = (KQTextImageFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextImageFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextImageFormat *qp = (KQTextImageFormat *)p->rawptr;
		(void)qp;
	}
}

static int QTextImageFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextImageFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextImageFormat";
	cdef->free = QTextImageFormat_free;
	cdef->reftrace = QTextImageFormat_reftrace;
	cdef->compareTo = QTextImageFormat_compareTo;
}


