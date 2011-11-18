//QCoreApplication QCoreApplication.new(int argc, String argv);
KMETHOD QCoreApplication_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int argc = Int_to(int, sfp[1]);
	char**  argv = RawPtr_to(char**, sfp[2]);
	KQCoreApplication *ret_v = new KQCoreApplication(argc, argv);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QCoreApplication.filterEvent(void message, long result);
KMETHOD QCoreApplication_filterEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCoreApplication *  qp = RawPtr_to(QCoreApplication *, sfp[0]);
	if (qp) {
		void*  message = RawPtr_to(void*, sfp[1]);
		long*  result = RawPtr_to(long*, sfp[2]);
		bool ret_v = qp->filterEvent(message, result);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QCoreApplication.notify(QObject receiver, QEvent event);
KMETHOD QCoreApplication_notify(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCoreApplication *  qp = RawPtr_to(QCoreApplication *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		QEvent*  event = RawPtr_to(QEvent*, sfp[2]);
		bool ret_v = qp->notify(receiver, event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QCoreApplication.addLibraryPath(String path);
KMETHOD QCoreApplication_addLibraryPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QCoreApplication::addLibraryPath(path);
	}
	RETURNvoid_();
}

//String QCoreApplication.applicationDirPath();
KMETHOD QCoreApplication_applicationDirPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QCoreApplication::applicationDirPath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QCoreApplication.applicationFilePath();
KMETHOD QCoreApplication_applicationFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QCoreApplication::applicationFilePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QCoreApplication.getApplicationName();
KMETHOD QCoreApplication_getApplicationName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QCoreApplication::applicationName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCoreApplication.applicationPid();
KMETHOD QCoreApplication_applicationPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qint64 ret_v = QCoreApplication::applicationPid();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QCoreApplication.getApplicationVersion();
KMETHOD QCoreApplication_getApplicationVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QCoreApplication::applicationVersion();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QCoreApplication.closingDown();
KMETHOD QCoreApplication_closingDown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QCoreApplication::closingDown();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QCoreApplication.exec();
KMETHOD QCoreApplication_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QCoreApplication::exec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QCoreApplication.exit(int returnCode);
KMETHOD QCoreApplication_exit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int returnCode = Int_to(int, sfp[1]);
		QCoreApplication::exit(returnCode);
	}
	RETURNvoid_();
}

//void QCoreApplication.flush();
KMETHOD QCoreApplication_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QCoreApplication::flush();
	}
	RETURNvoid_();
}

//boolean QCoreApplication.hasPendingEvents();
KMETHOD QCoreApplication_hasPendingEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QCoreApplication::hasPendingEvents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QCoreApplication.installTranslator(QTranslator translationFile);
KMETHOD QCoreApplication_installTranslator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTranslator*  translationFile = RawPtr_to(QTranslator*, sfp[1]);
		QCoreApplication::installTranslator(translationFile);
	}
	RETURNvoid_();
}

//QCoreApplication QCoreApplication.instance();
KMETHOD QCoreApplication_instance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QCoreApplication* ret_v = QCoreApplication::instance();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QCoreApplication*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QCoreApplication.getOrganizationDomain();
KMETHOD QCoreApplication_getOrganizationDomain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QCoreApplication::organizationDomain();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QCoreApplication.getOrganizationName();
KMETHOD QCoreApplication_getOrganizationName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QCoreApplication::organizationName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QCoreApplication.postEvent(QObject receiver, QEvent event);
KMETHOD QCoreApplication_postEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		QEvent*  event = RawPtr_to(QEvent*, sfp[2]);
		QCoreApplication::postEvent(receiver, event);
	}
	RETURNvoid_();
}

/*
//void QCoreApplication.postEvent(QObject receiver, QEvent event, int priority);
KMETHOD QCoreApplication_postEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		QEvent*  event = RawPtr_to(QEvent*, sfp[2]);
		int priority = Int_to(int, sfp[3]);
		QCoreApplication::postEvent(receiver, event, priority);
	}
	RETURNvoid_();
}
*/
//void QCoreApplication.processEvents(int flags);
KMETHOD QCoreApplication_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QEventLoop::ProcessEventsFlags flags = Int_to(QEventLoop::ProcessEventsFlags, sfp[1]);
		QCoreApplication::processEvents(flags);
	}
	RETURNvoid_();
}

/*
//void QCoreApplication.processEvents(int flags, int maxtime);
KMETHOD QCoreApplication_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QEventLoop::ProcessEventsFlags flags = Int_to(QEventLoop::ProcessEventsFlags, sfp[1]);
		int maxtime = Int_to(int, sfp[2]);
		QCoreApplication::processEvents(flags, maxtime);
	}
	RETURNvoid_();
}
*/
//void QCoreApplication.removeLibraryPath(String path);
KMETHOD QCoreApplication_removeLibraryPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QCoreApplication::removeLibraryPath(path);
	}
	RETURNvoid_();
}

//void QCoreApplication.removePostedEvents(QObject receiver);
KMETHOD QCoreApplication_removePostedEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		QCoreApplication::removePostedEvents(receiver);
	}
	RETURNvoid_();
}

/*
//void QCoreApplication.removePostedEvents(QObject receiver, int eventType);
KMETHOD QCoreApplication_removePostedEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		int eventType = Int_to(int, sfp[2]);
		QCoreApplication::removePostedEvents(receiver, eventType);
	}
	RETURNvoid_();
}
*/
//void QCoreApplication.removeTranslator(QTranslator translationFile);
KMETHOD QCoreApplication_removeTranslator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTranslator*  translationFile = RawPtr_to(QTranslator*, sfp[1]);
		QCoreApplication::removeTranslator(translationFile);
	}
	RETURNvoid_();
}

//boolean QCoreApplication.sendEvent(QObject receiver, QEvent event);
KMETHOD QCoreApplication_sendEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		QEvent*  event = RawPtr_to(QEvent*, sfp[2]);
		bool ret_v = QCoreApplication::sendEvent(receiver, event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QCoreApplication.sendPostedEvents(QObject receiver, int event_type);
KMETHOD QCoreApplication_sendPostedEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		int event_type = Int_to(int, sfp[2]);
		QCoreApplication::sendPostedEvents(receiver, event_type);
	}
	RETURNvoid_();
}

/*
//void QCoreApplication.sendPostedEvents();
KMETHOD QCoreApplication_sendPostedEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QCoreApplication::sendPostedEvents();
	}
	RETURNvoid_();
}
*/
//void QCoreApplication.setApplicationName(String application);
KMETHOD QCoreApplication_setApplicationName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString application = String_to(const QString, sfp[1]);
		QCoreApplication::setApplicationName(application);
	}
	RETURNvoid_();
}

//void QCoreApplication.setApplicationVersion(String version);
KMETHOD QCoreApplication_setApplicationVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString version = String_to(const QString, sfp[1]);
		QCoreApplication::setApplicationVersion(version);
	}
	RETURNvoid_();
}

//void QCoreApplication.setAttribute(int attribute, boolean on);
KMETHOD QCoreApplication_setAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::ApplicationAttribute attribute = Int_to(Qt::ApplicationAttribute, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		QCoreApplication::setAttribute(attribute, on);
	}
	RETURNvoid_();
}

//void QCoreApplication.setOrganizationDomain(String orgDomain);
KMETHOD QCoreApplication_setOrganizationDomain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString orgDomain = String_to(const QString, sfp[1]);
		QCoreApplication::setOrganizationDomain(orgDomain);
	}
	RETURNvoid_();
}

//void QCoreApplication.setOrganizationName(String orgName);
KMETHOD QCoreApplication_setOrganizationName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString orgName = String_to(const QString, sfp[1]);
		QCoreApplication::setOrganizationName(orgName);
	}
	RETURNvoid_();
}

//boolean QCoreApplication.startingUp();
KMETHOD QCoreApplication_startingUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QCoreApplication::startingUp();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QCoreApplication.testAttribute(int attribute);
KMETHOD QCoreApplication_testAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::ApplicationAttribute attribute = Int_to(Qt::ApplicationAttribute, sfp[1]);
		bool ret_v = QCoreApplication::testAttribute(attribute);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QCoreApplication.translate(String context, String sourceText, String disambiguation, int encoding, int n);
KMETHOD QCoreApplication_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  context = RawPtr_to(const char*, sfp[1]);
		const char*  sourceText = RawPtr_to(const char*, sfp[2]);
		const char*  disambiguation = RawPtr_to(const char*, sfp[3]);
		QCoreApplication::Encoding encoding = Int_to(QCoreApplication::Encoding, sfp[4]);
		int n = Int_to(int, sfp[5]);
		QString ret_v = QCoreApplication::translate(context, sourceText, disambiguation, encoding, n);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QCoreApplication.translate(String context, String sourceText, String disambiguation, int encoding);
KMETHOD QCoreApplication_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  context = RawPtr_to(const char*, sfp[1]);
		const char*  sourceText = RawPtr_to(const char*, sfp[2]);
		const char*  disambiguation = RawPtr_to(const char*, sfp[3]);
		QCoreApplication::Encoding encoding = Int_to(QCoreApplication::Encoding, sfp[4]);
		QString ret_v = QCoreApplication::translate(context, sourceText, disambiguation, encoding);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QCoreApplication.quit();
KMETHOD QCoreApplication_quit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCoreApplication *  qp = RawPtr_to(QCoreApplication *, sfp[0]);
	if (qp) {
		qp->quit();
	}
	RETURNvoid_();
}


DummyQCoreApplication::DummyQCoreApplication()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	about_to_quit_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("about-to-quit", NULL));
}
DummyQCoreApplication::~DummyQCoreApplication()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQCoreApplication::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCoreApplication::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQCoreApplication::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCoreApplication::aboutToQuitSlot()
{
	if (about_to_quit_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, about_to_quit_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQCoreApplication::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCoreApplication::event_map->bigin();
	if ((itr = DummyQCoreApplication::event_map->find(str)) == DummyQCoreApplication::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCoreApplication::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCoreApplication::slot_map->bigin();
	if ((itr = DummyQCoreApplication::slot_map->find(str)) == DummyQCoreApplication::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		about_to_quit_func = (*slot_map)["about-to-quit"];
		return true;
	}
}

knh_Object_t** DummyQCoreApplication::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQCoreApplication::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, about_to_quit_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQCoreApplication::connection(QObject *o)
{
	QCoreApplication *p = dynamic_cast<QCoreApplication*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(aboutToQuit()), this, SLOT(aboutToQuitSlot()));
	}
	DummyQObject::connection(o);
}

KQCoreApplication::KQCoreApplication(int argc, char** argv) : QCoreApplication(argc, argv)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQCoreApplication();
	dummy->connection((QObject*)this);
}

KQCoreApplication::~KQCoreApplication()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QCoreApplication_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCoreApplication *qp = RawPtr_to(KQCoreApplication *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCoreApplication]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCoreApplication]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCoreApplication_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCoreApplication *qp = RawPtr_to(KQCoreApplication *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCoreApplication]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCoreApplication]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCoreApplication_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQCoreApplication *qp = (KQCoreApplication *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QCoreApplication*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QCoreApplication_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQCoreApplication *qp = (KQCoreApplication *)p->rawptr;
		KQCoreApplication *qp = static_cast<KQCoreApplication*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QCoreApplication_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCoreApplication::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQCoreApplication::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QCoreApplication::event(event);
		return false;
	}
//	QCoreApplication::event(event);
	return true;
}

static knh_IntData_t QCoreApplicationConstInt[] = {
	{"CodecForTr", QCoreApplication::CodecForTr},
	{"UnicodeUTF8", QCoreApplication::UnicodeUTF8},
	{"DefaultCodec", QCoreApplication::DefaultCodec},
	{NULL, 0}
};

DEFAPI(void) constQCoreApplication(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QCoreApplicationConstInt);
}


DEFAPI(void) defQCoreApplication(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCoreApplication";
	cdef->free = QCoreApplication_free;
	cdef->reftrace = QCoreApplication_reftrace;
	cdef->compareTo = QCoreApplication_compareTo;
}


