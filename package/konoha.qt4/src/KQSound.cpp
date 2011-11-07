//QSound QSound.new(String filename, QObject parent);
KMETHOD QSound_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString filename = String_to(const QString, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQSound *ret_v = new KQSound(filename, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QSound.fileName();
KMETHOD QSound_fileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSound.isFinished();
KMETHOD QSound_isFinished(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFinished();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSound.getLoops();
KMETHOD QSound_getLoops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		int ret_v = qp->loops();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSound.loopsRemaining();
KMETHOD QSound_loopsRemaining(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		int ret_v = qp->loopsRemaining();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSound.setLoops(int number);
KMETHOD QSound_setLoops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		int number = Int_to(int, sfp[1]);
		qp->setLoops(number);
	}
	RETURNvoid_();
}

//boolean QSound.isAvailable();
KMETHOD QSound_isAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QSound::isAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSound.play(String filename);
KMETHOD QSound_play(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString filename = String_to(const QString, sfp[1]);
		QSound::play(filename);
	}
	RETURNvoid_();
}

/*
//void QSound.play();
KMETHOD QSound_play(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		qp->play();
	}
	RETURNvoid_();
}
*/
//void QSound.stop();
KMETHOD QSound_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSound *  qp = RawPtr_to(QSound *, sfp[0]);
	if (qp) {
		qp->stop();
	}
	RETURNvoid_();
}


DummyQSound::DummyQSound()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSound::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSound::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQSound::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSound::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSound::event_map->bigin();
	if ((itr = DummyQSound::event_map->find(str)) == DummyQSound::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSound::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSound::slot_map->bigin();
	if ((itr = DummyQSound::slot_map->find(str)) == DummyQSound::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSound::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQSound::connection(QObject *o)
{
	QSound *p = dynamic_cast<QSound*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQSound::KQSound(const QString filename, QObject* parent) : QSound(filename, parent)
{
	self = NULL;
	dummy = new DummyQSound();
	dummy->connection((QObject*)this);
}

KMETHOD QSound_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSound *qp = RawPtr_to(KQSound *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSound]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSound]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSound_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSound *qp = RawPtr_to(KQSound *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSound]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSound]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSound_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSound *qp = (KQSound *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSound_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSound *qp = (KQSound *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSound_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSound::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSound::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSound::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQSound(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSound";
	cdef->free = QSound_free;
	cdef->reftrace = QSound_reftrace;
	cdef->compareTo = QSound_compareTo;
}


