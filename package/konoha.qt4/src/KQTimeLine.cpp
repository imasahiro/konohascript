//QTimeLine QTimeLine.new(int duration, QObject parent);
KMETHOD QTimeLine_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int duration = Int_to(int, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQTimeLine *ret_v = new KQTimeLine(duration, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTimeLine.currentFrame();
KMETHOD QTimeLine_currentFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentFrame();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.getCurrentTime();
KMETHOD QTimeLine_getCurrentTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentTime();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTimeLine.currentValue();
KMETHOD QTimeLine_currentValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->currentValue();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTimeLine.getCurveShape();
KMETHOD QTimeLine_getCurveShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		QTimeLine::CurveShape ret_v = qp->curveShape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.getDirection();
KMETHOD QTimeLine_getDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		QTimeLine::Direction ret_v = qp->direction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.getDuration();
KMETHOD QTimeLine_getDuration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->duration();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QEasingCurve QTimeLine.getEasingCurve();
KMETHOD QTimeLine_getEasingCurve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		QEasingCurve ret_v = qp->easingCurve();
		QEasingCurve *ret_v_ = new QEasingCurve(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTimeLine.getEndFrame();
KMETHOD QTimeLine_getEndFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->endFrame();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.frameForTime(int msec);
KMETHOD QTimeLine_frameForTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		int ret_v = qp->frameForTime(msec);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.getLoopCount();
KMETHOD QTimeLine_getLoopCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->loopCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTimeLine.setCurveShape(int shape);
KMETHOD QTimeLine_setCurveShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		QTimeLine::CurveShape shape = Int_to(QTimeLine::CurveShape, sfp[1]);
		qp->setCurveShape(shape);
	}
	RETURNvoid_();
}

//void QTimeLine.setDirection(int direction);
KMETHOD QTimeLine_setDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		QTimeLine::Direction direction = Int_to(QTimeLine::Direction, sfp[1]);
		qp->setDirection(direction);
	}
	RETURNvoid_();
}

//void QTimeLine.setDuration(int duration);
KMETHOD QTimeLine_setDuration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int duration = Int_to(int, sfp[1]);
		qp->setDuration(duration);
	}
	RETURNvoid_();
}

//void QTimeLine.setEasingCurve(QEasingCurve curve);
KMETHOD QTimeLine_setEasingCurve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		const QEasingCurve  curve = *RawPtr_to(const QEasingCurve *, sfp[1]);
		qp->setEasingCurve(curve);
	}
	RETURNvoid_();
}

//void QTimeLine.setEndFrame(int frame);
KMETHOD QTimeLine_setEndFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int frame = Int_to(int, sfp[1]);
		qp->setEndFrame(frame);
	}
	RETURNvoid_();
}

//void QTimeLine.setFrameRange(int startFrame, int endFrame);
KMETHOD QTimeLine_setFrameRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int startFrame = Int_to(int, sfp[1]);
		int endFrame = Int_to(int, sfp[2]);
		qp->setFrameRange(startFrame, endFrame);
	}
	RETURNvoid_();
}

//void QTimeLine.setLoopCount(int count);
KMETHOD QTimeLine_setLoopCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int count = Int_to(int, sfp[1]);
		qp->setLoopCount(count);
	}
	RETURNvoid_();
}

//void QTimeLine.setStartFrame(int frame);
KMETHOD QTimeLine_setStartFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int frame = Int_to(int, sfp[1]);
		qp->setStartFrame(frame);
	}
	RETURNvoid_();
}

//void QTimeLine.setUpdateInterval(int interval);
KMETHOD QTimeLine_setUpdateInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int interval = Int_to(int, sfp[1]);
		qp->setUpdateInterval(interval);
	}
	RETURNvoid_();
}

//int QTimeLine.getStartFrame();
KMETHOD QTimeLine_getStartFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->startFrame();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.state();
KMETHOD QTimeLine_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		QTimeLine::State ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTimeLine.getUpdateInterval();
KMETHOD QTimeLine_getUpdateInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->updateInterval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual float QTimeLine.valueForTime(int msec);
KMETHOD QTimeLine_valueForTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		qreal ret_v = qp->valueForTime(msec);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTimeLine.resume();
KMETHOD QTimeLine_resume(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		qp->resume();
	}
	RETURNvoid_();
}

//void QTimeLine.setCurrentTime(int msec);
KMETHOD QTimeLine_setCurrentTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		qp->setCurrentTime(msec);
	}
	RETURNvoid_();
}

//void QTimeLine.setPaused(boolean paused);
KMETHOD QTimeLine_setPaused(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		bool paused = Boolean_to(bool, sfp[1]);
		qp->setPaused(paused);
	}
	RETURNvoid_();
}

//void QTimeLine.start();
KMETHOD QTimeLine_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		qp->start();
	}
	RETURNvoid_();
}

//void QTimeLine.stop();
KMETHOD QTimeLine_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		qp->stop();
	}
	RETURNvoid_();
}

//void QTimeLine.toggleDirection();
KMETHOD QTimeLine_toggleDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimeLine *  qp = RawPtr_to(QTimeLine *, sfp[0]);
	if (qp != NULL) {
		qp->toggleDirection();
	}
	RETURNvoid_();
}


DummyQTimeLine::DummyQTimeLine()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTimeLine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTimeLine::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQTimeLine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTimeLine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimeLine::event_map->bigin();
	if ((itr = DummyQTimeLine::event_map->find(str)) == DummyQTimeLine::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTimeLine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimeLine::slot_map->bigin();
	if ((itr = DummyQTimeLine::event_map->find(str)) == DummyQTimeLine::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTimeLine::KQTimeLine(int duration, QObject* parent) : QTimeLine(duration, parent)
{
	self = NULL;
}

KMETHOD QTimeLine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimeLine *qp = RawPtr_to(KQTimeLine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTimeLine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTimeLine::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimeLine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTimeLine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimeLine *qp = RawPtr_to(KQTimeLine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTimeLine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTimeLine::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimeLine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTimeLine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTimeLine *qp = (KQTimeLine *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTimeLine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTimeLine *qp = (KQTimeLine *)p->rawptr;
		(void)qp;
	}
}

static int QTimeLine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTimeLine::event(QEvent *event)
{
	if (!DummyQTimeLine::eventDispatcher(event)) {
		QTimeLine::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTimeLine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTimeLine";
	cdef->free = QTimeLine_free;
	cdef->reftrace = QTimeLine_reftrace;
	cdef->compareTo = QTimeLine_compareTo;
}

static knh_IntData_t QTimeLineConstInt[] = {
	{"EaseInCurve", QTimeLine::EaseInCurve},
	{"EaseOutCurve", QTimeLine::EaseOutCurve},
	{"EaseInOutCurve", QTimeLine::EaseInOutCurve},
	{"LinearCurve", QTimeLine::LinearCurve},
	{"SineCurve", QTimeLine::SineCurve},
	{"CosineCurve", QTimeLine::CosineCurve},
	{"Forward", QTimeLine::Forward},
	{"Backward", QTimeLine::Backward},
	{"NotRunning", QTimeLine::NotRunning},
	{"Paused", QTimeLine::Paused},
	{"Running", QTimeLine::Running},
	{NULL, 0}
};

DEFAPI(void) constQTimeLine(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTimeLineConstInt);
}

