//QDate QLibraryInfo.buildDate();
KMETHOD QLibraryInfo_buildDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QDate ret_v = QLibraryInfo::buildDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLibraryInfo.buildKey();
KMETHOD QLibraryInfo_buildKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QLibraryInfo::buildKey();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLibraryInfo.licensedProducts();
KMETHOD QLibraryInfo_licensedProducts(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QLibraryInfo::licensedProducts();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLibraryInfo.licensee();
KMETHOD QLibraryInfo_licensee(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QLibraryInfo::licensee();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLibraryInfo.location(int loc);
KMETHOD QLibraryInfo_location(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QLibraryInfo::LibraryLocation loc = Int_to(QLibraryInfo::LibraryLocation, sfp[1]);
		QString ret_v = QLibraryInfo::location(loc);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QLibraryInfo.parents();
KMETHOD QLibraryInfo_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLibraryInfo *qp = RawPtr_to(QLibraryInfo*, sfp[0]);
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

DummyQLibraryInfo::DummyQLibraryInfo()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQLibraryInfo::~DummyQLibraryInfo()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQLibraryInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLibraryInfo::self = ptr;
}

bool DummyQLibraryInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLibraryInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLibraryInfo::event_map->bigin();
	if ((itr = DummyQLibraryInfo::event_map->find(str)) == DummyQLibraryInfo::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLibraryInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLibraryInfo::slot_map->bigin();
	if ((itr = DummyQLibraryInfo::slot_map->find(str)) == DummyQLibraryInfo::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQLibraryInfo::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQLibraryInfo::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQLibraryInfo::connection(QObject *o)
{
	QLibraryInfo *p = dynamic_cast<QLibraryInfo*>(o);
	if (p != NULL) {
	}
}

KQLibraryInfo::~KQLibraryInfo()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QLibraryInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLibraryInfo *qp = RawPtr_to(KQLibraryInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLibraryInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLibraryInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLibraryInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLibraryInfo *qp = RawPtr_to(KQLibraryInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLibraryInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLibraryInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLibraryInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQLibraryInfo *qp = (KQLibraryInfo *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QLibraryInfo*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QLibraryInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQLibraryInfo *qp = (KQLibraryInfo *)p->rawptr;
		KQLibraryInfo *qp = static_cast<KQLibraryInfo*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLibraryInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLibraryInfo::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QLibraryInfoConstInt[] = {
	{"PrefixPath", QLibraryInfo::PrefixPath},
	{"DocumentationPath", QLibraryInfo::DocumentationPath},
	{"HeadersPath", QLibraryInfo::HeadersPath},
	{"LibrariesPath", QLibraryInfo::LibrariesPath},
	{"BinariesPath", QLibraryInfo::BinariesPath},
	{"PluginsPath", QLibraryInfo::PluginsPath},
	{"ImportsPath", QLibraryInfo::ImportsPath},
	{"DataPath", QLibraryInfo::DataPath},
	{"TranslationsPath", QLibraryInfo::TranslationsPath},
	{"SettingsPath", QLibraryInfo::SettingsPath},
	{"ExamplesPath", QLibraryInfo::ExamplesPath},
	{"DemosPath", QLibraryInfo::DemosPath},
	{NULL, 0}
};

DEFAPI(void) constQLibraryInfo(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLibraryInfoConstInt);
}


DEFAPI(void) defQLibraryInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLibraryInfo";
	cdef->free = QLibraryInfo_free;
	cdef->reftrace = QLibraryInfo_reftrace;
	cdef->compareTo = QLibraryInfo_compareTo;
}


