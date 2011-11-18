//QTextImageFormat QTextImageFormat.new();
KMETHOD QTextImageFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextImageFormat *ret_v = new KQTextImageFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QTextImageFormat.getHeight();
KMETHOD QTextImageFormat_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QTextImageFormat.getName();
KMETHOD QTextImageFormat_getName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextImageFormat *  qp = RawPtr_to(QTextImageFormat *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQTextImageFormat::DummyQTextImageFormat()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextImageFormat::~DummyQTextImageFormat()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
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
	if ((itr = DummyQTextImageFormat::slot_map->find(str)) == DummyQTextImageFormat::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextCharFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextImageFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextImageFormat::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQTextCharFormat::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTextImageFormat::connection(QObject *o)
{
	QTextImageFormat *p = dynamic_cast<QTextImageFormat*>(o);
	if (p != NULL) {
	}
	DummyQTextCharFormat::connection(o);
}

KQTextImageFormat::KQTextImageFormat() : QTextImageFormat()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextImageFormat();
}

KQTextImageFormat::~KQTextImageFormat()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextImageFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextImageFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextImageFormat *qp = (KQTextImageFormat *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextImageFormat*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextImageFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextImageFormat *qp = (KQTextImageFormat *)p->rawptr;
		KQTextImageFormat *qp = static_cast<KQTextImageFormat*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextImageFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextImageFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextImageFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextImageFormat";
	cdef->free = QTextImageFormat_free;
	cdef->reftrace = QTextImageFormat_reftrace;
	cdef->compareTo = QTextImageFormat_compareTo;
}


