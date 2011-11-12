//String QWebSettings.getDefaultTextEncoding();
KMETHOD QWebSettings_getDefaultTextEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QString ret_v = qp->defaultTextEncoding();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebSettings.getFontFamily(int which);
KMETHOD QWebSettings_getFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::FontFamily which = Int_to(QWebSettings::FontFamily, sfp[1]);
		QString ret_v = qp->fontFamily(which);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebSettings.getFontSize(int type);
KMETHOD QWebSettings_getFontSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::FontSize type = Int_to(QWebSettings::FontSize, sfp[1]);
		int ret_v = qp->fontSize(type);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QWebSettings.getLocalStoragePath();
KMETHOD QWebSettings_getLocalStoragePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QString ret_v = qp->localStoragePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebSettings.resetAttribute(int attribute);
KMETHOD QWebSettings_resetAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::WebAttribute attribute = Int_to(QWebSettings::WebAttribute, sfp[1]);
		qp->resetAttribute(attribute);
	}
	RETURNvoid_();
}

//void QWebSettings.resetFontFamily(int which);
KMETHOD QWebSettings_resetFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::FontFamily which = Int_to(QWebSettings::FontFamily, sfp[1]);
		qp->resetFontFamily(which);
	}
	RETURNvoid_();
}

//void QWebSettings.resetFontSize(int type);
KMETHOD QWebSettings_resetFontSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::FontSize type = Int_to(QWebSettings::FontSize, sfp[1]);
		qp->resetFontSize(type);
	}
	RETURNvoid_();
}

//void QWebSettings.setAttribute(int attribute, boolean on);
KMETHOD QWebSettings_setAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::WebAttribute attribute = Int_to(QWebSettings::WebAttribute, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setAttribute(attribute, on);
	}
	RETURNvoid_();
}

//void QWebSettings.setDefaultTextEncoding(String encoding);
KMETHOD QWebSettings_setDefaultTextEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		const QString encoding = String_to(const QString, sfp[1]);
		qp->setDefaultTextEncoding(encoding);
	}
	RETURNvoid_();
}

//void QWebSettings.setFontFamily(int which, String family);
KMETHOD QWebSettings_setFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::FontFamily which = Int_to(QWebSettings::FontFamily, sfp[1]);
		const QString family = String_to(const QString, sfp[2]);
		qp->setFontFamily(which, family);
	}
	RETURNvoid_();
}

//void QWebSettings.setFontSize(int type, int size);
KMETHOD QWebSettings_setFontSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::FontSize type = Int_to(QWebSettings::FontSize, sfp[1]);
		int size = Int_to(int, sfp[2]);
		qp->setFontSize(type, size);
	}
	RETURNvoid_();
}

//void QWebSettings.setLocalStoragePath(String path);
KMETHOD QWebSettings_setLocalStoragePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		qp->setLocalStoragePath(path);
	}
	RETURNvoid_();
}

//void QWebSettings.setUserStyleSheetUrl(QUrl location);
KMETHOD QWebSettings_setUserStyleSheetUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		const QUrl  location = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setUserStyleSheetUrl(location);
	}
	RETURNvoid_();
}

//boolean QWebSettings.testAttribute(int attribute);
KMETHOD QWebSettings_testAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QWebSettings::WebAttribute attribute = Int_to(QWebSettings::WebAttribute, sfp[1]);
		bool ret_v = qp->testAttribute(attribute);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QUrl QWebSettings.getUserStyleSheetUrl();
KMETHOD QWebSettings_getUserStyleSheetUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *  qp = RawPtr_to(QWebSettings *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->userStyleSheetUrl();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebSettings.clearIconDatabase();
KMETHOD QWebSettings_clearIconDatabase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebSettings::clearIconDatabase();
	}
	RETURNvoid_();
}

//void QWebSettings.clearMemoryCaches();
KMETHOD QWebSettings_clearMemoryCaches(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebSettings::clearMemoryCaches();
	}
	RETURNvoid_();
}

//void QWebSettings.enablePersistentStorage(String path);
KMETHOD QWebSettings_enablePersistentStorage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QWebSettings::enablePersistentStorage(path);
	}
	RETURNvoid_();
}

//QWebSettings QWebSettings.globalSettings();
KMETHOD QWebSettings_globalSettings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebSettings* ret_v = QWebSettings::globalSettings();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebSettings*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebSettings.getIconDatabasePath();
KMETHOD QWebSettings_getIconDatabasePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QWebSettings::iconDatabasePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QWebSettings.iconForUrl(QUrl url);
KMETHOD QWebSettings_iconForUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		QIcon ret_v = QWebSettings::iconForUrl(url);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebSettings.getMaximumPagesInCache();
KMETHOD QWebSettings_getMaximumPagesInCache(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QWebSettings::maximumPagesInCache();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWebSettings.getOfflineStorageDefaultQuota();
KMETHOD QWebSettings_getOfflineStorageDefaultQuota(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 ret_v = QWebSettings::offlineStorageDefaultQuota();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebSettings.getOfflineStoragePath();
KMETHOD QWebSettings_getOfflineStoragePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QWebSettings::offlineStoragePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebSettings.getOfflineWebApplicationCachePath();
KMETHOD QWebSettings_getOfflineWebApplicationCachePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QWebSettings::offlineWebApplicationCachePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebSettings.getOfflineWebApplicationCacheQuota();
KMETHOD QWebSettings_getOfflineWebApplicationCacheQuota(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 ret_v = QWebSettings::offlineWebApplicationCacheQuota();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebSettings.setIconDatabasePath(String path);
KMETHOD QWebSettings_setIconDatabasePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QWebSettings::setIconDatabasePath(path);
	}
	RETURNvoid_();
}

//void QWebSettings.setMaximumPagesInCache(int pages);
KMETHOD QWebSettings_setMaximumPagesInCache(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int pages = Int_to(int, sfp[1]);
		QWebSettings::setMaximumPagesInCache(pages);
	}
	RETURNvoid_();
}

//void QWebSettings.setObjectCacheCapacities(int cacheMinDeadCapacity, int cacheMaxDead, int totalCapacity);
KMETHOD QWebSettings_setObjectCacheCapacities(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int cacheMinDeadCapacity = Int_to(int, sfp[1]);
		int cacheMaxDead = Int_to(int, sfp[2]);
		int totalCapacity = Int_to(int, sfp[3]);
		QWebSettings::setObjectCacheCapacities(cacheMinDeadCapacity, cacheMaxDead, totalCapacity);
	}
	RETURNvoid_();
}

//void QWebSettings.setOfflineStorageDefaultQuota(int maximumSize);
KMETHOD QWebSettings_setOfflineStorageDefaultQuota(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 maximumSize = Int_to(qint64, sfp[1]);
		QWebSettings::setOfflineStorageDefaultQuota(maximumSize);
	}
	RETURNvoid_();
}

//void QWebSettings.setOfflineStoragePath(String path);
KMETHOD QWebSettings_setOfflineStoragePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QWebSettings::setOfflineStoragePath(path);
	}
	RETURNvoid_();
}

//void QWebSettings.setOfflineWebApplicationCachePath(String path);
KMETHOD QWebSettings_setOfflineWebApplicationCachePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QWebSettings::setOfflineWebApplicationCachePath(path);
	}
	RETURNvoid_();
}

//void QWebSettings.setOfflineWebApplicationCacheQuota(int maximumSize);
KMETHOD QWebSettings_setOfflineWebApplicationCacheQuota(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 maximumSize = Int_to(qint64, sfp[1]);
		QWebSettings::setOfflineWebApplicationCacheQuota(maximumSize);
	}
	RETURNvoid_();
}

//void QWebSettings.setWebGraphic(int type, QPixmap graphic);
KMETHOD QWebSettings_setWebGraphic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebSettings::WebGraphic type = Int_to(QWebSettings::WebGraphic, sfp[1]);
		const QPixmap  graphic = *RawPtr_to(const QPixmap *, sfp[2]);
		QWebSettings::setWebGraphic(type, graphic);
	}
	RETURNvoid_();
}

//QPixmap QWebSettings.getWebGraphic(int type);
KMETHOD QWebSettings_getWebGraphic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebSettings::WebGraphic type = Int_to(QWebSettings::WebGraphic, sfp[1]);
		QPixmap ret_v = QWebSettings::webGraphic(type);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QWebSettings.parents();
KMETHOD QWebSettings_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSettings *qp = RawPtr_to(QWebSettings*, sfp[0]);
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

DummyQWebSettings::DummyQWebSettings()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWebSettings::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebSettings::self = ptr;
}

bool DummyQWebSettings::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebSettings::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebSettings::event_map->bigin();
	if ((itr = DummyQWebSettings::event_map->find(str)) == DummyQWebSettings::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebSettings::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebSettings::slot_map->bigin();
	if ((itr = DummyQWebSettings::slot_map->find(str)) == DummyQWebSettings::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebSettings::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebSettings::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebSettings::connection(QObject *o)
{
	QWebSettings *p = dynamic_cast<QWebSettings*>(o);
	if (p != NULL) {
	}
}

KMETHOD QWebSettings_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebSettings *qp = RawPtr_to(KQWebSettings *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebSettings]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebSettings]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebSettings_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebSettings *qp = RawPtr_to(KQWebSettings *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebSettings]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebSettings]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebSettings_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebSettings *qp = (KQWebSettings *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebSettings_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebSettings *qp = (KQWebSettings *)p->rawptr;
//		KQWebSettings *qp = static_cast<KQWebSettings*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebSettings_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebSettings::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QWebSettingsConstInt[] = {
	{"StandardFont", QWebSettings::StandardFont},
	{"FixedFont", QWebSettings::FixedFont},
	{"SerifFont", QWebSettings::SerifFont},
	{"SansSerifFont", QWebSettings::SansSerifFont},
	{"CursiveFont", QWebSettings::CursiveFont},
	{"FantasyFont", QWebSettings::FantasyFont},
	{"MinimumFontSize", QWebSettings::MinimumFontSize},
	{"MinimumLogicalFontSize", QWebSettings::MinimumLogicalFontSize},
	{"DefaultFontSize", QWebSettings::DefaultFontSize},
	{"DefaultFixedFontSize", QWebSettings::DefaultFixedFontSize},
	{"AutoLoadImages", QWebSettings::AutoLoadImages},
	{"DnsPrefetchEnabled", QWebSettings::DnsPrefetchEnabled},
	{"JavascriptEnabled", QWebSettings::JavascriptEnabled},
	{"JavaEnabled", QWebSettings::JavaEnabled},
	{"PluginsEnabled", QWebSettings::PluginsEnabled},
	{"PrivateBrowsingEnabled", QWebSettings::PrivateBrowsingEnabled},
	{"JavascriptCanOpenWindows", QWebSettings::JavascriptCanOpenWindows},
	{"JavascriptCanAccessClipboard", QWebSettings::JavascriptCanAccessClipboard},
	{"DeveloperExtrasEnabled", QWebSettings::DeveloperExtrasEnabled},
	{"SpatialNavigationEnabled", QWebSettings::SpatialNavigationEnabled},
	{"LinksIncludedInFocusChain", QWebSettings::LinksIncludedInFocusChain},
	{"ZoomTextOnly", QWebSettings::ZoomTextOnly},
	{"PrintElementBackgrounds", QWebSettings::PrintElementBackgrounds},
	{"OfflineStorageDatabaseEnabled", QWebSettings::OfflineStorageDatabaseEnabled},
	{"OfflineWebApplicationCacheEnabled", QWebSettings::OfflineWebApplicationCacheEnabled},
	{"LocalStorageEnabled", QWebSettings::LocalStorageEnabled},
	{"LocalStorageDatabaseEnabled", QWebSettings::LocalStorageDatabaseEnabled},
	{"LocalContentCanAccessRemoteUrls", QWebSettings::LocalContentCanAccessRemoteUrls},
	{"LocalContentCanAccessFileUrls", QWebSettings::LocalContentCanAccessFileUrls},
	{"XSSAuditingEnabled", QWebSettings::XSSAuditingEnabled},
	{"AcceleratedCompositingEnabled", QWebSettings::AcceleratedCompositingEnabled},
	{"TiledBackingStoreEnabled", QWebSettings::TiledBackingStoreEnabled},
	{"FrameFlatteningEnabled", QWebSettings::FrameFlatteningEnabled},
	{"SiteSpecificQuirksEnabled", QWebSettings::SiteSpecificQuirksEnabled},
	{"MissingImageGraphic", QWebSettings::MissingImageGraphic},
	{"MissingPluginGraphic", QWebSettings::MissingPluginGraphic},
	{"DefaultFrameIconGraphic", QWebSettings::DefaultFrameIconGraphic},
	{"TextAreaSizeGripCornerGraphic", QWebSettings::TextAreaSizeGripCornerGraphic},
	{NULL, 0}
};

DEFAPI(void) constQWebSettings(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWebSettingsConstInt);
}


DEFAPI(void) defQWebSettings(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebSettings";
	cdef->free = QWebSettings_free;
	cdef->reftrace = QWebSettings_reftrace;
	cdef->compareTo = QWebSettings_compareTo;
}


