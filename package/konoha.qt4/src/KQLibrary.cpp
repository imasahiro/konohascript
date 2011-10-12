//QLibrary QLibrary.new(QObject parent);
KMETHOD QLibrary_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQLibrary *ret_v = new KQLibrary(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLibrary QLibrary.new(String fileName, QObject parent);
KMETHOD QLibrary_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQLibrary *ret_v = new KQLibrary(fileName, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLibrary QLibrary.new(String fileName, int verNum, QObject parent);
KMETHOD QLibrary_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	int verNum = Int_to(int, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQLibrary *ret_v = new KQLibrary(fileName, verNum, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLibrary QLibrary.new(String fileName, String version, QObject parent);
KMETHOD QLibrary_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const QString version = String_to(const QString, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQLibrary *ret_v = new KQLibrary(fileName, version, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QLibrary.errorString();
KMETHOD QLibrary_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLibrary.getFileName();
KMETHOD QLibrary_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLibrary.isLoaded();
KMETHOD QLibrary_isLoaded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isLoaded();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLibrary.load();
KMETHOD QLibrary_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->load();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLibrary.getLoadHints();
KMETHOD QLibrary_getLoadHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		QLibrary::LoadHints ret_v = qp->loadHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLibrary.resolve(String symbol);
KMETHOD QLibrary_resolve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const char*  symbol = RawPtr_to(const char*, sfp[1]);
		void* ret_v = qp->resolve(symbol);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLibrary.setFileName(String fileName);
KMETHOD QLibrary_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setFileName(fileName);
	}
	RETURNvoid_();
}

//void QLibrary.setFileNameAndVersion(String fileName, int versionNumber);
KMETHOD QLibrary_setFileNameAndVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		int versionNumber = Int_to(int, sfp[2]);
		qp->setFileNameAndVersion(fileName, versionNumber);
	}
	RETURNvoid_();
}

/*
//void QLibrary.setFileNameAndVersion(String fileName, String version);
KMETHOD QLibrary_setFileNameAndVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		const QString version = String_to(const QString, sfp[2]);
		qp->setFileNameAndVersion(fileName, version);
	}
	RETURNvoid_();
}
*/
//void QLibrary.setLoadHints(int hints);
KMETHOD QLibrary_setLoadHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		QLibrary::LoadHints hints = Int_to(QLibrary::LoadHints, sfp[1]);
		qp->setLoadHints(hints);
	}
	RETURNvoid_();
}

//boolean QLibrary.unload();
KMETHOD QLibrary_unload(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->unload();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLibrary.isLibrary(String fileName);
KMETHOD QLibrary_isLibrary(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		bool ret_v = qp->isLibrary(fileName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QLibrary.resolve(String fileName, String symbol);
KMETHOD QLibrary_resolve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		const char*  symbol = RawPtr_to(const char*, sfp[2]);
		void* ret_v = qp->resolve(fileName, symbol);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//void QLibrary.resolve(String fileName, int verNum, String symbol);
KMETHOD QLibrary_resolve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		int verNum = Int_to(int, sfp[2]);
		const char*  symbol = RawPtr_to(const char*, sfp[3]);
		void* ret_v = qp->resolve(fileName, verNum, symbol);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//void QLibrary.resolve(String fileName, String version, String symbol);
KMETHOD QLibrary_resolve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibrary *  qp = RawPtr_to(QLibrary *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		const QString version = String_to(const QString, sfp[2]);
		const char*  symbol = RawPtr_to(const char*, sfp[3]);
		void* ret_v = qp->resolve(fileName, version, symbol);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQLibrary::DummyQLibrary()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLibrary::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLibrary::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQLibrary::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLibrary::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLibrary::event_map->bigin();
	if ((itr = DummyQLibrary::event_map->find(str)) == DummyQLibrary::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLibrary::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLibrary::slot_map->bigin();
	if ((itr = DummyQLibrary::event_map->find(str)) == DummyQLibrary::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQLibrary::KQLibrary(QObject* parent) : QLibrary(parent)
{
	self = NULL;
}

KMETHOD QLibrary_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLibrary *qp = RawPtr_to(KQLibrary *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLibrary]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQLibrary::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLibrary]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QLibrary_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLibrary *qp = RawPtr_to(KQLibrary *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLibrary]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQLibrary::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLibrary]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLibrary_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLibrary *qp = (KQLibrary *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLibrary_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQLibrary *qp = (KQLibrary *)p->rawptr;
		(void)qp;
	}
}

static int QLibrary_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQLibrary::event(QEvent *event)
{
	if (!DummyQLibrary::eventDispatcher(event)) {
		QLibrary::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQLibrary(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLibrary";
	cdef->free = QLibrary_free;
	cdef->reftrace = QLibrary_reftrace;
	cdef->compareTo = QLibrary_compareTo;
}

static knh_IntData_t QLibraryConstInt[] = {
	{"ResolveAllSymbolsHint", QLibrary::ResolveAllSymbolsHint},
	{"ExportExternalSymbolsHint", QLibrary::ExportExternalSymbolsHint},
	{"LoadArchiveMemberHint", QLibrary::LoadArchiveMemberHint},
	{NULL, 0}
};

DEFAPI(void) constQLibrary(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLibraryConstInt);
}

