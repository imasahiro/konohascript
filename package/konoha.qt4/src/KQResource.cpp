//QResource QResource.new(String file, QLocale locale);
KMETHOD QResource_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString file = String_to(const QString, sfp[1]);
	const QLocale  locale = *RawPtr_to(const QLocale *, sfp[2]);
	KQResource *ret_v = new KQResource(file, locale);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QResource.absoluteFilePath();
KMETHOD QResource_absoluteFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->absoluteFilePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QResource.data();
KMETHOD QResource_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const uchar* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QResource.getFileName();
KMETHOD QResource_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QResource.isCompressed();
KMETHOD QResource_isCompressed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isCompressed();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QResource.isValid();
KMETHOD QResource_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QLocale QResource.getLocale();
KMETHOD QResource_getLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		QLocale ret_v = qp->locale();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QResource.setFileName(String file);
KMETHOD QResource_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const QString file = String_to(const QString, sfp[1]);
		qp->setFileName(file);
	}
	RETURNvoid_();
}

//void QResource.setLocale(QLocale locale);
KMETHOD QResource_setLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const QLocale  locale = *RawPtr_to(const QLocale *, sfp[1]);
		qp->setLocale(locale);
	}
	RETURNvoid_();
}

//int QResource.size();
KMETHOD QResource_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->size();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QResource.registerResource(String rccFileName, String mapRoot);
KMETHOD QResource_registerResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const QString rccFileName = String_to(const QString, sfp[1]);
		const QString mapRoot = String_to(const QString, sfp[2]);
		bool ret_v = qp->registerResource(rccFileName, mapRoot);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QResource.registerResource(String rccData, String mapRoot);
KMETHOD QResource_registerResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const uchar*  rccData = RawPtr_to(const uchar*, sfp[1]);
		const QString mapRoot = String_to(const QString, sfp[2]);
		bool ret_v = qp->registerResource(rccData, mapRoot);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QResource.unregisterResource(String rccFileName, String mapRoot);
KMETHOD QResource_unregisterResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const QString rccFileName = String_to(const QString, sfp[1]);
		const QString mapRoot = String_to(const QString, sfp[2]);
		bool ret_v = qp->unregisterResource(rccFileName, mapRoot);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QResource.unregisterResource(String rccData, String mapRoot);
KMETHOD QResource_unregisterResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResource *  qp = RawPtr_to(QResource *, sfp[0]);
	if (qp != NULL) {
		const uchar*  rccData = RawPtr_to(const uchar*, sfp[1]);
		const QString mapRoot = String_to(const QString, sfp[2]);
		bool ret_v = qp->unregisterResource(rccData, mapRoot);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/

DummyQResource::DummyQResource()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQResource::setSelf(knh_RawPtr_t *ptr)
{
	DummyQResource::self = ptr;
}

bool DummyQResource::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQResource::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQResource::event_map->bigin();
	if ((itr = DummyQResource::event_map->find(str)) == DummyQResource::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQResource::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQResource::slot_map->bigin();
	if ((itr = DummyQResource::event_map->find(str)) == DummyQResource::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQResource::KQResource(const QString file, const QLocale locale) : QResource(file, locale)
{
	self = NULL;
}

KMETHOD QResource_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQResource *qp = RawPtr_to(KQResource *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QResource]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQResource::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QResource]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QResource_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQResource *qp = RawPtr_to(KQResource *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QResource]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQResource::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QResource]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QResource_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQResource *qp = (KQResource *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QResource_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQResource *qp = (KQResource *)p->rawptr;
		(void)qp;
	}
}

static int QResource_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQResource(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QResource";
	cdef->free = QResource_free;
	cdef->reftrace = QResource_reftrace;
	cdef->compareTo = QResource_compareTo;
}


