//QQuaternion QQuaternion.new();
KMETHOD QQuaternion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQQuaternion *ret_v = new KQQuaternion();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QQuaternion QQuaternion.new(float scalar, float xpos, float ypos, float zpos);
KMETHOD QQuaternion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal scalar = Float_to(qreal, sfp[1]);
	qreal xpos = Float_to(qreal, sfp[2]);
	qreal ypos = Float_to(qreal, sfp[3]);
	qreal zpos = Float_to(qreal, sfp[4]);
	KQQuaternion *ret_v = new KQQuaternion(scalar, xpos, ypos, zpos);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QQuaternion QQuaternion.conjugate();
KMETHOD QQuaternion_conjugate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		QQuaternion ret_v = qp->conjugate();
		QQuaternion *ret_v_ = new QQuaternion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QQuaternion.isIdentity();
KMETHOD QQuaternion_isIdentity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isIdentity();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QQuaternion.length();
KMETHOD QQuaternion_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->length();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QQuaternion.lengthSquared();
KMETHOD QQuaternion_lengthSquared(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->lengthSquared();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QQuaternion.normalize();
KMETHOD QQuaternion_normalize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qp->normalize();
	}
	RETURNvoid_();
}

//QQuaternion QQuaternion.normalized();
KMETHOD QQuaternion_normalized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		QQuaternion ret_v = qp->normalized();
		QQuaternion *ret_v_ = new QQuaternion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QQuaternion.getScalar();
KMETHOD QQuaternion_getScalar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->scalar();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QQuaternion.setScalar(float scalar);
KMETHOD QQuaternion_setScalar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal scalar = Float_to(qreal, sfp[1]);
		qp->setScalar(scalar);
	}
	RETURNvoid_();
}

//void QQuaternion.setVector(float x, float y, float z);
KMETHOD QQuaternion_setVector(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal z = Float_to(qreal, sfp[3]);
		qp->setVector(x, y, z);
	}
	RETURNvoid_();
}

//void QQuaternion.setX(float x);
KMETHOD QQuaternion_setX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->setX(x);
	}
	RETURNvoid_();
}

//void QQuaternion.setY(float y);
KMETHOD QQuaternion_setY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->setY(y);
	}
	RETURNvoid_();
}

//void QQuaternion.setZ(float z);
KMETHOD QQuaternion_setZ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal z = Float_to(qreal, sfp[1]);
		qp->setZ(z);
	}
	RETURNvoid_();
}

//float QQuaternion.getX();
KMETHOD QQuaternion_getX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->x();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QQuaternion.getY();
KMETHOD QQuaternion_getY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->y();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QQuaternion.getZ();
KMETHOD QQuaternion_getZ(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *  qp = RawPtr_to(QQuaternion *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->z();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QQuaternion QQuaternion.fromAxisAndAngle(float x, float y, float z, float angle);
KMETHOD QQuaternion_fromAxisAndAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal z = Float_to(qreal, sfp[3]);
		qreal angle = Float_to(qreal, sfp[4]);
		QQuaternion ret_v = QQuaternion::fromAxisAndAngle(x, y, z, angle);
		QQuaternion *ret_v_ = new QQuaternion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QQuaternion QQuaternion.nlerp(QQuaternion q1, QQuaternion q2, float t);
KMETHOD QQuaternion_nlerp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QQuaternion  q1 = *RawPtr_to(const QQuaternion *, sfp[1]);
		const QQuaternion  q2 = *RawPtr_to(const QQuaternion *, sfp[2]);
		qreal t = Float_to(qreal, sfp[3]);
		QQuaternion ret_v = QQuaternion::nlerp(q1, q2, t);
		QQuaternion *ret_v_ = new QQuaternion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QQuaternion QQuaternion.slerp(QQuaternion q1, QQuaternion q2, float t);
KMETHOD QQuaternion_slerp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QQuaternion  q1 = *RawPtr_to(const QQuaternion *, sfp[1]);
		const QQuaternion  q2 = *RawPtr_to(const QQuaternion *, sfp[2]);
		qreal t = Float_to(qreal, sfp[3]);
		QQuaternion ret_v = QQuaternion::slerp(q1, q2, t);
		QQuaternion *ret_v_ = new QQuaternion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QQuaternion.parents();
KMETHOD QQuaternion_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QQuaternion *qp = RawPtr_to(QQuaternion*, sfp[0]);
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

DummyQQuaternion::DummyQQuaternion()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQQuaternion::~DummyQQuaternion()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQQuaternion::setSelf(knh_RawPtr_t *ptr)
{
	DummyQQuaternion::self = ptr;
}

bool DummyQQuaternion::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQQuaternion::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQQuaternion::event_map->bigin();
	if ((itr = DummyQQuaternion::event_map->find(str)) == DummyQQuaternion::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQQuaternion::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQQuaternion::slot_map->bigin();
	if ((itr = DummyQQuaternion::slot_map->find(str)) == DummyQQuaternion::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQQuaternion::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQQuaternion::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQQuaternion::connection(QObject *o)
{
	QQuaternion *p = dynamic_cast<QQuaternion*>(o);
	if (p != NULL) {
	}
}

KQQuaternion::KQQuaternion() : QQuaternion()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQQuaternion();
}

KQQuaternion::~KQQuaternion()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QQuaternion_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQQuaternion *qp = RawPtr_to(KQQuaternion *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QQuaternion]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QQuaternion]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QQuaternion_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQQuaternion *qp = RawPtr_to(KQQuaternion *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QQuaternion]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QQuaternion]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QQuaternion_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQQuaternion *qp = (KQQuaternion *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QQuaternion*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QQuaternion_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQQuaternion *qp = (KQQuaternion *)p->rawptr;
		KQQuaternion *qp = static_cast<KQQuaternion*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QQuaternion_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QQuaternion*>(p1->rawptr) == *static_cast<QQuaternion*>(p2->rawptr) ? 0 : 1);
}

void KQQuaternion::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQQuaternion(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QQuaternion";
	cdef->free = QQuaternion_free;
	cdef->reftrace = QQuaternion_reftrace;
	cdef->compareTo = QQuaternion_compareTo;
}


