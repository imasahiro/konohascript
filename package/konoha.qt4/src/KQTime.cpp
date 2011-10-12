//QTime QTime.new();
KMETHOD QTime_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTime *ret_v = new KQTime();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTime QTime.new(int h, int m, int s, int ms);
KMETHOD QTime_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int h = Int_to(int, sfp[1]);
	int m = Int_to(int, sfp[2]);
	int s = Int_to(int, sfp[3]);
	int ms = Int_to(int, sfp[4]);
	KQTime *ret_v = new KQTime(h, m, s, ms);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QTime QTime.addMSecs(int ms);
KMETHOD QTime_addMSecs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ms = Int_to(int, sfp[1]);
		QTime ret_v = qp->addMSecs(ms);
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTime QTime.addSecs(int s);
KMETHOD QTime_addSecs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int s = Int_to(int, sfp[1]);
		QTime ret_v = qp->addSecs(s);
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTime.elapsed();
KMETHOD QTime_elapsed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->elapsed();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTime.hour();
KMETHOD QTime_hour(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->hour();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QTime.isNull();
KMETHOD QTime_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QTime.isValid();
KMETHOD QTime_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTime.minute();
KMETHOD QTime_minute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minute();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTime.msec();
KMETHOD QTime_msec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->msec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTime.msecsTo(QTime t);
KMETHOD QTime_msecsTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		const QTime  t = *RawPtr_to(const QTime *, sfp[1]);
		int ret_v = qp->msecsTo(t);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTime.restart();
KMETHOD QTime_restart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->restart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTime.second();
KMETHOD QTime_second(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->second();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTime.secsTo(QTime t);
KMETHOD QTime_secsTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		const QTime  t = *RawPtr_to(const QTime *, sfp[1]);
		int ret_v = qp->secsTo(t);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTime.setHMS(int h, int m, int s, int ms);
KMETHOD QTime_setHMS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int h = Int_to(int, sfp[1]);
		int m = Int_to(int, sfp[2]);
		int s = Int_to(int, sfp[3]);
		int ms = Int_to(int, sfp[4]);
		bool ret_v = qp->setHMS(h, m, s, ms);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTime.start();
KMETHOD QTime_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		qp->start();
	}
	RETURNvoid_();
}

//String QTime.toString(String fmt);
KMETHOD QTime_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		const QString format = String_to(const QString, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QTime.toString(int fmt);
KMETHOD QTime_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		Qt::DateFormat format = Int_to(Qt::DateFormat, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTime QTime.currentTime();
KMETHOD QTime_currentTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		QTime ret_v = qp->currentTime();
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTime QTime.fromString(String str, int fmt);
KMETHOD QTime_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		Qt::DateFormat format = Int_to(Qt::DateFormat, sfp[2]);
		QTime ret_v = qp->fromString(string, format);
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTime QTime.fromString(String str, String fmt);
KMETHOD QTime_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QTime ret_v = qp->fromString(string, format);
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////boolean QTime.isValid(int h, int m, int s, int ms);
KMETHOD QTime_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTime *  qp = RawPtr_to(QTime *, sfp[0]);
	if (qp != NULL) {
		int h = Int_to(int, sfp[1]);
		int m = Int_to(int, sfp[2]);
		int s = Int_to(int, sfp[3]);
		int ms = Int_to(int, sfp[4]);
		bool ret_v = qp->isValid(h, m, s, ms);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/

DummyQTime::DummyQTime()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTime::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTime::self = ptr;
}

bool DummyQTime::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTime::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTime::event_map->bigin();
	if ((itr = DummyQTime::event_map->find(str)) == DummyQTime::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTime::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTime::slot_map->bigin();
	if ((itr = DummyQTime::event_map->find(str)) == DummyQTime::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTime::KQTime() : QTime()
{
	self = NULL;
}

KMETHOD QTime_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTime *qp = RawPtr_to(KQTime *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTime]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTime::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTime]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTime_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTime *qp = RawPtr_to(KQTime *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTime]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTime::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTime]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTime_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTime *qp = (KQTime *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTime_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTime *qp = (KQTime *)p->rawptr;
		(void)qp;
	}
}

static int QTime_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTime*>(p1->rawptr) == *static_cast<QTime*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQTime(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTime";
	cdef->free = QTime_free;
	cdef->reftrace = QTime_reftrace;
	cdef->compareTo = QTime_compareTo;
}


