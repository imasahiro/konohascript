//QMatrix4x4 QMatrix4x4.new();
KMETHOD QMatrix4x4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMatrix4x4 *ret_v = new KQMatrix4x4();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMatrix4x4 QMatrix4x4.new(float values);
KMETHOD QMatrix4x4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const qreal*  values = RawPtr_to(const qreal*, sfp[1]);
	KQMatrix4x4 *ret_v = new KQMatrix4x4(values);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QMatrix4x4 QMatrix4x4.new(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
KMETHOD QMatrix4x4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal m11 = Float_to(qreal, sfp[1]);
	qreal m12 = Float_to(qreal, sfp[2]);
	qreal m13 = Float_to(qreal, sfp[3]);
	qreal m14 = Float_to(qreal, sfp[4]);
	qreal m21 = Float_to(qreal, sfp[5]);
	qreal m22 = Float_to(qreal, sfp[6]);
	qreal m23 = Float_to(qreal, sfp[7]);
	qreal m24 = Float_to(qreal, sfp[8]);
	qreal m31 = Float_to(qreal, sfp[9]);
	qreal m32 = Float_to(qreal, sfp[10]);
	qreal m33 = Float_to(qreal, sfp[11]);
	qreal m34 = Float_to(qreal, sfp[12]);
	qreal m41 = Float_to(qreal, sfp[13]);
	qreal m42 = Float_to(qreal, sfp[14]);
	qreal m43 = Float_to(qreal, sfp[15]);
	qreal m44 = Float_to(qreal, sfp[16]);
	KQMatrix4x4 *ret_v = new KQMatrix4x4(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QMatrix4x4 QMatrix4x4.new(QTransform transform);
KMETHOD QMatrix4x4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTransform  transform = *RawPtr_to(const QTransform *, sfp[1]);
	KQMatrix4x4 *ret_v = new KQMatrix4x4(transform);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QMatrix4x4 QMatrix4x4.new(QMatrix matrix);
KMETHOD QMatrix4x4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
	KQMatrix4x4 *ret_v = new KQMatrix4x4(matrix);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QMatrix4x4.constData();
KMETHOD QMatrix4x4_constData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const qreal* ret_v = qp->constData();
		RETURNf_(*ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QMatrix4x4.copyDataTo(float values);
KMETHOD QMatrix4x4_copyDataTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal*  values = RawPtr_to(qreal*, sfp[1]);
		qp->copyDataTo(values);
	}
	RETURNvoid_();
}

//float QMatrix4x4.data();
KMETHOD QMatrix4x4_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal* ret_v = qp->data();
		RETURNf_(*ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

/*
//float QMatrix4x4.data();
KMETHOD QMatrix4x4_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const qreal* ret_v = qp->data();
		RETURNf_(*ret_v);
	} else {
		RETURNf_(0.0f);
	}
}
*/
//float QMatrix4x4.determinant();
KMETHOD QMatrix4x4_determinant(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->determinant();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QMatrix4x4.fill(float value);
KMETHOD QMatrix4x4_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->fill(value);
	}
	RETURNvoid_();
}

//void QMatrix4x4.flipCoordinates();
KMETHOD QMatrix4x4_flipCoordinates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qp->flipCoordinates();
	}
	RETURNvoid_();
}

//void QMatrix4x4.frustum(float left, float right, float bottom, float top, float nearPlane, float farPlane);
KMETHOD QMatrix4x4_frustum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal left = Float_to(qreal, sfp[1]);
		qreal right = Float_to(qreal, sfp[2]);
		qreal bottom = Float_to(qreal, sfp[3]);
		qreal top = Float_to(qreal, sfp[4]);
		qreal nearPlane = Float_to(qreal, sfp[5]);
		qreal farPlane = Float_to(qreal, sfp[6]);
		qp->frustum(left, right, bottom, top, nearPlane, farPlane);
	}
	RETURNvoid_();
}

//QMatrix4x4 QMatrix4x4.inverted(boolean invertible);
KMETHOD QMatrix4x4_inverted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		bool* invertible = Boolean_to(bool*, sfp[1]);
		QMatrix4x4 ret_v = qp->inverted(invertible);
		QMatrix4x4 *ret_v_ = new QMatrix4x4(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMatrix4x4.isIdentity();
KMETHOD QMatrix4x4_isIdentity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isIdentity();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPoint QMatrix4x4.map(QPoint point);
KMETHOD QMatrix4x4_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QPoint ret_v = qp->map(point);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPointF QMatrix4x4.map(QPointF point);
KMETHOD QMatrix4x4_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->map(point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRect QMatrix4x4.mapRect(QRect rect);
KMETHOD QMatrix4x4_mapRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		QRect ret_v = qp->mapRect(rect);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QMatrix4x4.mapRect(QRectF rect);
KMETHOD QMatrix4x4_mapRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->mapRect(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QMatrix3x3 QMatrix4x4.normalMatrix();
KMETHOD QMatrix4x4_normalMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		QMatrix3x3 ret_v = qp->normalMatrix();
		QMatrix3x3 *ret_v_ = new QMatrix3x3(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMatrix4x4.optimize();
KMETHOD QMatrix4x4_optimize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qp->optimize();
	}
	RETURNvoid_();
}

//void QMatrix4x4.ortho(float left, float right, float bottom, float top, float nearPlane, float farPlane);
KMETHOD QMatrix4x4_ortho(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal left = Float_to(qreal, sfp[1]);
		qreal right = Float_to(qreal, sfp[2]);
		qreal bottom = Float_to(qreal, sfp[3]);
		qreal top = Float_to(qreal, sfp[4]);
		qreal nearPlane = Float_to(qreal, sfp[5]);
		qreal farPlane = Float_to(qreal, sfp[6]);
		qp->ortho(left, right, bottom, top, nearPlane, farPlane);
	}
	RETURNvoid_();
}

/*
//void QMatrix4x4.ortho(QRect rect);
KMETHOD QMatrix4x4_ortho(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->ortho(rect);
	}
	RETURNvoid_();
}
*/
/*
//void QMatrix4x4.ortho(QRectF rect);
KMETHOD QMatrix4x4_ortho(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->ortho(rect);
	}
	RETURNvoid_();
}
*/
//void QMatrix4x4.perspective(float angle, float aspect, float nearPlane, float farPlane);
KMETHOD QMatrix4x4_perspective(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal angle = Float_to(qreal, sfp[1]);
		qreal aspect = Float_to(qreal, sfp[2]);
		qreal nearPlane = Float_to(qreal, sfp[3]);
		qreal farPlane = Float_to(qreal, sfp[4]);
		qp->perspective(angle, aspect, nearPlane, farPlane);
	}
	RETURNvoid_();
}

//void QMatrix4x4.rotate(QQuaternion quaternion);
KMETHOD QMatrix4x4_rotate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		const QQuaternion  quaternion = *RawPtr_to(const QQuaternion *, sfp[1]);
		qp->rotate(quaternion);
	}
	RETURNvoid_();
}

/*
//void QMatrix4x4.rotate(float angle, float x, float y, float z);
KMETHOD QMatrix4x4_rotate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal angle = Float_to(qreal, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal z = Float_to(qreal, sfp[4]);
		qp->rotate(angle, x, y, z);
	}
	RETURNvoid_();
}
*/
//void QMatrix4x4.scale(float x, float y);
KMETHOD QMatrix4x4_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->scale(x, y);
	}
	RETURNvoid_();
}

/*
//void QMatrix4x4.scale(float x, float y, float z);
KMETHOD QMatrix4x4_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal z = Float_to(qreal, sfp[3]);
		qp->scale(x, y, z);
	}
	RETURNvoid_();
}
*/
/*
//void QMatrix4x4.scale(float factor);
KMETHOD QMatrix4x4_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->scale(factor);
	}
	RETURNvoid_();
}
*/
//void QMatrix4x4.setToIdentity();
KMETHOD QMatrix4x4_setToIdentity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qp->setToIdentity();
	}
	RETURNvoid_();
}

//QMatrix QMatrix4x4.toAffine();
KMETHOD QMatrix4x4_toAffine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		QMatrix ret_v = qp->toAffine();
		QMatrix *ret_v_ = new QMatrix(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QMatrix4x4.toTransform();
KMETHOD QMatrix4x4_toTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		QTransform ret_v = qp->toTransform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTransform QMatrix4x4.toTransform(float distanceToPlane);
KMETHOD QMatrix4x4_toTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal distanceToPlane = Float_to(qreal, sfp[1]);
		QTransform ret_v = qp->toTransform(distanceToPlane);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QMatrix4x4.translate(float x, float y);
KMETHOD QMatrix4x4_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->translate(x, y);
	}
	RETURNvoid_();
}

/*
//void QMatrix4x4.translate(float x, float y, float z);
KMETHOD QMatrix4x4_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal z = Float_to(qreal, sfp[3]);
		qp->translate(x, y, z);
	}
	RETURNvoid_();
}
*/
//QMatrix4x4 QMatrix4x4.transposed();
KMETHOD QMatrix4x4_transposed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMatrix4x4 *  qp = RawPtr_to(QMatrix4x4 *, sfp[0]);
	if (qp != NULL) {
		QMatrix4x4 ret_v = qp->transposed();
		QMatrix4x4 *ret_v_ = new QMatrix4x4(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQMatrix4x4::DummyQMatrix4x4()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMatrix4x4::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMatrix4x4::self = ptr;
}

bool DummyQMatrix4x4::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMatrix4x4::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMatrix4x4::event_map->bigin();
	if ((itr = DummyQMatrix4x4::event_map->find(str)) == DummyQMatrix4x4::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMatrix4x4::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMatrix4x4::slot_map->bigin();
	if ((itr = DummyQMatrix4x4::slot_map->find(str)) == DummyQMatrix4x4::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQMatrix4x4::connection(QObject *o)
{
	return;
}

KQMatrix4x4::KQMatrix4x4() : QMatrix4x4()
{
	self = NULL;
	dummy = new DummyQMatrix4x4();
	dummy->connection((QObject*)this);
}

KMETHOD QMatrix4x4_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMatrix4x4 *qp = RawPtr_to(KQMatrix4x4 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMatrix4x4]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMatrix4x4]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMatrix4x4_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMatrix4x4 *qp = RawPtr_to(KQMatrix4x4 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMatrix4x4]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMatrix4x4]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMatrix4x4_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMatrix4x4 *qp = (KQMatrix4x4 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMatrix4x4_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQMatrix4x4 *qp = (KQMatrix4x4 *)p->rawptr;
		(void)qp;
	}
}

static int QMatrix4x4_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QMatrix4x4*>(p1->rawptr) == *static_cast<QMatrix4x4*>(p2->rawptr) ? 0 : 1);
}

void KQMatrix4x4::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQMatrix4x4(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMatrix4x4";
	cdef->free = QMatrix4x4_free;
	cdef->reftrace = QMatrix4x4_reftrace;
	cdef->compareTo = QMatrix4x4_compareTo;
}


