//QTranslator QTranslator.new(QObject parent);
KMETHOD QTranslator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQTranslator *ret_v = new KQTranslator(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual boolean QTranslator.isEmpty();
KMETHOD QTranslator_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTranslator *  qp = RawPtr_to(QTranslator *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTranslator.load(String filename, String directory, String search_delimiters, String suffix);
KMETHOD QTranslator_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTranslator *  qp = RawPtr_to(QTranslator *, sfp[0]);
	if (qp != NULL) {
		const QString filename = String_to(const QString, sfp[1]);
		const QString directory = String_to(const QString, sfp[2]);
		const QString search_delimiters = String_to(const QString, sfp[3]);
		const QString suffix = String_to(const QString, sfp[4]);
		bool ret_v = qp->load(filename, directory, search_delimiters, suffix);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QTranslator.load(String data, int len);
KMETHOD QTranslator_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTranslator *  qp = RawPtr_to(QTranslator *, sfp[0]);
	if (qp != NULL) {
		const uchar*  data = RawPtr_to(const uchar*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		bool ret_v = qp->load(data, len);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//@Virtual String QTranslator.translate(String context, String sourceText, String disambiguation);
KMETHOD QTranslator_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTranslator *  qp = RawPtr_to(QTranslator *, sfp[0]);
	if (qp != NULL) {
		const char*  context = RawPtr_to(const char*, sfp[1]);
		const char*  sourceText = RawPtr_to(const char*, sfp[2]);
		const char*  disambiguation = RawPtr_to(const char*, sfp[3]);
		QString ret_v = qp->translate(context, sourceText, disambiguation);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QTranslator.translate(String context, String sourceText, String disambiguation, int n);
KMETHOD QTranslator_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTranslator *  qp = RawPtr_to(QTranslator *, sfp[0]);
	if (qp != NULL) {
		const char*  context = RawPtr_to(const char*, sfp[1]);
		const char*  sourceText = RawPtr_to(const char*, sfp[2]);
		const char*  disambiguation = RawPtr_to(const char*, sfp[3]);
		int n = Int_to(int, sfp[4]);
		QString ret_v = qp->translate(context, sourceText, disambiguation, n);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQTranslator::DummyQTranslator()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTranslator::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTranslator::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQTranslator::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTranslator::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTranslator::event_map->bigin();
	if ((itr = DummyQTranslator::event_map->find(str)) == DummyQTranslator::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTranslator::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTranslator::slot_map->bigin();
	if ((itr = DummyQTranslator::slot_map->find(str)) == DummyQTranslator::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQTranslator::connection(QObject *o)
{
	DummyQObject::connection(o);
}

KQTranslator::KQTranslator(QObject* parent) : QTranslator(parent)
{
	self = NULL;
	dummy = new DummyQTranslator();
	dummy->connection((QObject*)this);
}

KMETHOD QTranslator_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTranslator *qp = RawPtr_to(KQTranslator *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTranslator]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTranslator]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTranslator_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTranslator *qp = RawPtr_to(KQTranslator *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTranslator]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTranslator]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTranslator_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTranslator *qp = (KQTranslator *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTranslator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTranslator *qp = (KQTranslator *)p->rawptr;
		(void)qp;
	}
}

static int QTranslator_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTranslator::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTranslator::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTranslator::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTranslator(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTranslator";
	cdef->free = QTranslator_free;
	cdef->reftrace = QTranslator_reftrace;
	cdef->compareTo = QTranslator_compareTo;
}


