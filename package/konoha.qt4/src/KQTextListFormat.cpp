//QTextListFormat QTextListFormat.new();
KMETHOD QTextListFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextListFormat *ret_v = new KQTextListFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTextListFormat.getIndent();
KMETHOD QTextListFormat_getIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextListFormat *  qp = RawPtr_to(QTextListFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->indent();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextListFormat.setIndent(int indentation);
KMETHOD QTextListFormat_setIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextListFormat *  qp = RawPtr_to(QTextListFormat *, sfp[0]);
	if (qp) {
		int indentation = Int_to(int, sfp[1]);
		qp->setIndent(indentation);
	}
	RETURNvoid_();
}

//void QTextListFormat.setStyle(int style);
KMETHOD QTextListFormat_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextListFormat *  qp = RawPtr_to(QTextListFormat *, sfp[0]);
	if (qp) {
		QTextListFormat::Style style = Int_to(QTextListFormat::Style, sfp[1]);
		qp->setStyle(style);
	}
	RETURNvoid_();
}

//int QTextListFormat.getStyle();
KMETHOD QTextListFormat_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextListFormat *  qp = RawPtr_to(QTextListFormat *, sfp[0]);
	if (qp) {
		QTextListFormat::Style ret_v = qp->style();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTextListFormat::DummyQTextListFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextListFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextListFormat::self = ptr;
	DummyQTextFormat::setSelf(ptr);
}

bool DummyQTextListFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextListFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextListFormat::event_map->bigin();
	if ((itr = DummyQTextListFormat::event_map->find(str)) == DummyQTextListFormat::event_map->end()) {
		bool ret = false;
		ret = DummyQTextFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextListFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextListFormat::slot_map->bigin();
	if ((itr = DummyQTextListFormat::slot_map->find(str)) == DummyQTextListFormat::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextListFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQTextFormat::reftrace(ctx, p, tail_);
}

void DummyQTextListFormat::connection(QObject *o)
{
	QTextListFormat *p = dynamic_cast<QTextListFormat*>(o);
	if (p != NULL) {
	}
	DummyQTextFormat::connection(o);
}

KQTextListFormat::KQTextListFormat() : QTextListFormat()
{
	self = NULL;
	dummy = new DummyQTextListFormat();
}

KMETHOD QTextListFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextListFormat *qp = RawPtr_to(KQTextListFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextListFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextListFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextListFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextListFormat *qp = RawPtr_to(KQTextListFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextListFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextListFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextListFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextListFormat *qp = (KQTextListFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextListFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextListFormat *qp = (KQTextListFormat *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextListFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextListFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextListFormatConstInt[] = {
	{"ListDisc", QTextListFormat::ListDisc},
	{"ListCircle", QTextListFormat::ListCircle},
	{"ListSquare", QTextListFormat::ListSquare},
	{"ListDecimal", QTextListFormat::ListDecimal},
//	{"ListLowerAlpha", QTextListFormat::ListLowerAlpha},
//	{"ListUpperAlpha", QTextListFormat::ListUpperAlpha},
	{"ListLowerRoman", QTextListFormat::ListLowerRoman},
	{"ListUpperRoman", QTextListFormat::ListUpperRoman},
	{NULL, 0}
};

DEFAPI(void) constQTextListFormat(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextListFormatConstInt);
}


DEFAPI(void) defQTextListFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextListFormat";
	cdef->free = QTextListFormat_free;
	cdef->reftrace = QTextListFormat_reftrace;
	cdef->compareTo = QTextListFormat_compareTo;
}


