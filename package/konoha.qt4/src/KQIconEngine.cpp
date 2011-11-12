//@Virtual QSize QIconEngine.actualSize(QSize size, int mode, int state);
KMETHOD QIconEngine_actualSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine *  qp = RawPtr_to(QIconEngine *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		QSize ret_v = qp->actualSize(size, mode, state);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QIconEngine.addFile(String fileName, QSize size, int mode, int state);
KMETHOD QIconEngine_addFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine *  qp = RawPtr_to(QIconEngine *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[3]);
		QIcon::State state = Int_to(QIcon::State, sfp[4]);
		qp->addFile(fileName, size, mode, state);
	}
	RETURNvoid_();
}

//@Virtual void QIconEngine.addPixmap(QPixmap pixmap, int mode, int state);
KMETHOD QIconEngine_addPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine *  qp = RawPtr_to(QIconEngine *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		qp->addPixmap(pixmap, mode, state);
	}
	RETURNvoid_();
}

//@Virtual void QIconEngine.paint(QPainter painter, QRect rect, int mode, int state);
KMETHOD QIconEngine_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine *  qp = RawPtr_to(QIconEngine *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRect  rect = *RawPtr_to(const QRect *, sfp[2]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[3]);
		QIcon::State state = Int_to(QIcon::State, sfp[4]);
		qp->paint(painter, rect, mode, state);
	}
	RETURNvoid_();
}

//@Virtual QPixmap QIconEngine.pixmap(QSize size, int mode, int state);
KMETHOD QIconEngine_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine *  qp = RawPtr_to(QIconEngine *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		QPixmap ret_v = qp->pixmap(size, mode, state);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QIconEngine.parents();
KMETHOD QIconEngine_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine *qp = RawPtr_to(QIconEngine*, sfp[0]);
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

DummyQIconEngine::DummyQIconEngine()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQIconEngine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQIconEngine::self = ptr;
}

bool DummyQIconEngine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQIconEngine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIconEngine::event_map->bigin();
	if ((itr = DummyQIconEngine::event_map->find(str)) == DummyQIconEngine::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQIconEngine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIconEngine::slot_map->bigin();
	if ((itr = DummyQIconEngine::slot_map->find(str)) == DummyQIconEngine::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQIconEngine::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQIconEngine::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQIconEngine::connection(QObject *o)
{
	QIconEngine *p = dynamic_cast<QIconEngine*>(o);
	if (p != NULL) {
	}
}

KMETHOD QIconEngine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconEngine *qp = RawPtr_to(KQIconEngine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QIconEngine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIconEngine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QIconEngine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconEngine *qp = RawPtr_to(KQIconEngine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QIconEngine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIconEngine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIconEngine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQIconEngine *qp = (KQIconEngine *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QIconEngine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQIconEngine *qp = (KQIconEngine *)p->rawptr;
//		KQIconEngine *qp = static_cast<KQIconEngine*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QIconEngine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQIconEngine::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQIconEngine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIconEngine";
	cdef->free = QIconEngine_free;
	cdef->reftrace = QIconEngine_reftrace;
	cdef->compareTo = QIconEngine_compareTo;
}


