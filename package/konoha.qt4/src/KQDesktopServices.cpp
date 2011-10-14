//String QDesktopServices.displayName(int type);
KMETHOD QDesktopServices_displayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopServices *  qp = RawPtr_to(QDesktopServices *, sfp[0]);
	if (qp != NULL) {
		QDesktopServices::StandardLocation type = Int_to(QDesktopServices::StandardLocation, sfp[1]);
		QString ret_v = qp->displayName(type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDesktopServices.openUrl(QUrl url);
KMETHOD QDesktopServices_openUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopServices *  qp = RawPtr_to(QDesktopServices *, sfp[0]);
	if (qp != NULL) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		bool ret_v = qp->openUrl(url);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDesktopServices.setUrlHandler(String scheme, QObject receiver, String method);
KMETHOD QDesktopServices_setUrlHandler(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopServices *  qp = RawPtr_to(QDesktopServices *, sfp[0]);
	if (qp != NULL) {
		const QString scheme = String_to(const QString, sfp[1]);
		QObject*  receiver = RawPtr_to(QObject*, sfp[2]);
		const char*  method = RawPtr_to(const char*, sfp[3]);
		qp->setUrlHandler(scheme, receiver, method);
	}
	RETURNvoid_();
}

//String QDesktopServices.storageLocation(int type);
KMETHOD QDesktopServices_storageLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopServices *  qp = RawPtr_to(QDesktopServices *, sfp[0]);
	if (qp != NULL) {
		QDesktopServices::StandardLocation type = Int_to(QDesktopServices::StandardLocation, sfp[1]);
		QString ret_v = qp->storageLocation(type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDesktopServices.unsetUrlHandler(String scheme);
KMETHOD QDesktopServices_unsetUrlHandler(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDesktopServices *  qp = RawPtr_to(QDesktopServices *, sfp[0]);
	if (qp != NULL) {
		const QString scheme = String_to(const QString, sfp[1]);
		qp->unsetUrlHandler(scheme);
	}
	RETURNvoid_();
}


DummyQDesktopServices::DummyQDesktopServices()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDesktopServices::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDesktopServices::self = ptr;
}

bool DummyQDesktopServices::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQDesktopServices::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDesktopServices::event_map->bigin();
	if ((itr = DummyQDesktopServices::event_map->find(str)) == DummyQDesktopServices::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDesktopServices::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDesktopServices::slot_map->bigin();
	if ((itr = DummyQDesktopServices::slot_map->find(str)) == DummyQDesktopServices::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQDesktopServices::connection(QObject *o)
{
	return;
}

KQDesktopServices::KQDesktopServices() : QDesktopServices()
{
	self = NULL;
	dummy = new DummyQDesktopServices();
	dummy->connection((QObject*)this);
}

KMETHOD QDesktopServices_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDesktopServices *qp = RawPtr_to(KQDesktopServices *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDesktopServices]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDesktopServices]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDesktopServices_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDesktopServices *qp = RawPtr_to(KQDesktopServices *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDesktopServices]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDesktopServices]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDesktopServices_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDesktopServices *qp = (KQDesktopServices *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDesktopServices_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQDesktopServices *qp = (KQDesktopServices *)p->rawptr;
		(void)qp;
	}
}

static int QDesktopServices_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDesktopServices::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQDesktopServices(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDesktopServices";
	cdef->free = QDesktopServices_free;
	cdef->reftrace = QDesktopServices_reftrace;
	cdef->compareTo = QDesktopServices_compareTo;
}

static knh_IntData_t QDesktopServicesConstInt[] = {
	{"DesktopLocation", QDesktopServices::DesktopLocation},
	{"DocumentsLocation", QDesktopServices::DocumentsLocation},
	{"FontsLocation", QDesktopServices::FontsLocation},
	{"ApplicationsLocation", QDesktopServices::ApplicationsLocation},
	{"MusicLocation", QDesktopServices::MusicLocation},
	{"MoviesLocation", QDesktopServices::MoviesLocation},
	{"PicturesLocation", QDesktopServices::PicturesLocation},
	{"TempLocation", QDesktopServices::TempLocation},
	{"HomeLocation", QDesktopServices::HomeLocation},
	{"DataLocation", QDesktopServices::DataLocation},
	{"CacheLocation", QDesktopServices::CacheLocation},
	{NULL, 0}
};

DEFAPI(void) constQDesktopServices(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDesktopServicesConstInt);
}

