//QGLFramebufferObjectFormat QGLFramebufferObjectFormat.new();
KMETHOD QGLFramebufferObjectFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFramebufferObjectFormat *ret_v = new KQGLFramebufferObjectFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLFramebufferObjectFormat QGLFramebufferObjectFormat.new(QGLFramebufferObjectFormat other);
KMETHOD QGLFramebufferObjectFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLFramebufferObjectFormat  other = *RawPtr_to(const QGLFramebufferObjectFormat *, sfp[1]);
	KQGLFramebufferObjectFormat *ret_v = new KQGLFramebufferObjectFormat(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QGLFramebufferObjectFormat.getAttachment();
KMETHOD QGLFramebufferObjectFormat_getAttachment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		QGLFramebufferObject::Attachment ret_v = qp->attachment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//GLenum QGLFramebufferObjectFormat.getInternalTextureFormat();
KMETHOD QGLFramebufferObjectFormat_getInternalTextureFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		GLenum ret_v = qp->internalTextureFormat();
		GLenum *ret_v_ = new GLenum(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGLFramebufferObjectFormat.getSamples();
KMETHOD QGLFramebufferObjectFormat_getSamples(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->samples();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGLFramebufferObjectFormat.setAttachment(int attachment);
KMETHOD QGLFramebufferObjectFormat_setAttachment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		QGLFramebufferObject::Attachment attachment = Int_to(QGLFramebufferObject::Attachment, sfp[1]);
		qp->setAttachment(attachment);
	}
	RETURNvoid_();
}

//void QGLFramebufferObjectFormat.setInternalTextureFormat(GLenum internalTextureFormat);
KMETHOD QGLFramebufferObjectFormat_setInternalTextureFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		GLenum  internalTextureFormat = *RawPtr_to(GLenum *, sfp[1]);
		qp->setInternalTextureFormat(internalTextureFormat);
	}
	RETURNvoid_();
}

//void QGLFramebufferObjectFormat.setSamples(int samples);
KMETHOD QGLFramebufferObjectFormat_setSamples(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		int samples = Int_to(int, sfp[1]);
		qp->setSamples(samples);
	}
	RETURNvoid_();
}

//void QGLFramebufferObjectFormat.setTextureTarget(GLenum target);
KMETHOD QGLFramebufferObjectFormat_setTextureTarget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		GLenum  target = *RawPtr_to(GLenum *, sfp[1]);
		qp->setTextureTarget(target);
	}
	RETURNvoid_();
}

//GLenum QGLFramebufferObjectFormat.getTextureTarget();
KMETHOD QGLFramebufferObjectFormat_getTextureTarget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *  qp = RawPtr_to(QGLFramebufferObjectFormat *, sfp[0]);
	if (qp) {
		GLenum ret_v = qp->textureTarget();
		GLenum *ret_v_ = new GLenum(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QGLFramebufferObjectFormat.parents();
KMETHOD QGLFramebufferObjectFormat_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObjectFormat *qp = RawPtr_to(QGLFramebufferObjectFormat*, sfp[0]);
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

DummyQGLFramebufferObjectFormat::DummyQGLFramebufferObjectFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGLFramebufferObjectFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLFramebufferObjectFormat::self = ptr;
}

bool DummyQGLFramebufferObjectFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGLFramebufferObjectFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLFramebufferObjectFormat::event_map->bigin();
	if ((itr = DummyQGLFramebufferObjectFormat::event_map->find(str)) == DummyQGLFramebufferObjectFormat::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLFramebufferObjectFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLFramebufferObjectFormat::slot_map->bigin();
	if ((itr = DummyQGLFramebufferObjectFormat::slot_map->find(str)) == DummyQGLFramebufferObjectFormat::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLFramebufferObjectFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLFramebufferObjectFormat::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQGLFramebufferObjectFormat::connection(QObject *o)
{
	QGLFramebufferObjectFormat *p = dynamic_cast<QGLFramebufferObjectFormat*>(o);
	if (p != NULL) {
	}
}

KQGLFramebufferObjectFormat::KQGLFramebufferObjectFormat() : QGLFramebufferObjectFormat()
{
	self = NULL;
	dummy = new DummyQGLFramebufferObjectFormat();
}

KMETHOD QGLFramebufferObjectFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFramebufferObjectFormat *qp = RawPtr_to(KQGLFramebufferObjectFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLFramebufferObjectFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLFramebufferObjectFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLFramebufferObjectFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFramebufferObjectFormat *qp = RawPtr_to(KQGLFramebufferObjectFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLFramebufferObjectFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLFramebufferObjectFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLFramebufferObjectFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGLFramebufferObjectFormat *qp = (KQGLFramebufferObjectFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGLFramebufferObjectFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGLFramebufferObjectFormat *qp = (KQGLFramebufferObjectFormat *)p->rawptr;
//		KQGLFramebufferObjectFormat *qp = static_cast<KQGLFramebufferObjectFormat*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLFramebufferObjectFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QGLFramebufferObjectFormat*>(p1->rawptr) == *static_cast<QGLFramebufferObjectFormat*>(p2->rawptr) ? 0 : 1);
}

void KQGLFramebufferObjectFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGLFramebufferObjectFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLFramebufferObjectFormat";
	cdef->free = QGLFramebufferObjectFormat_free;
	cdef->reftrace = QGLFramebufferObjectFormat_reftrace;
	cdef->compareTo = QGLFramebufferObjectFormat_compareTo;
}


