//QAction QWhatsThis.createAction(QObject parent);
KMETHOD QWhatsThis_createAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  parent = RawPtr_to(QObject*, sfp[1]);
		QAction* ret_v = QWhatsThis::createAction(parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWhatsThis.enterWhatsThisMode();
KMETHOD QWhatsThis_enterWhatsThisMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWhatsThis::enterWhatsThisMode();
	}
	RETURNvoid_();
}

//void QWhatsThis.hideText();
KMETHOD QWhatsThis_hideText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWhatsThis::hideText();
	}
	RETURNvoid_();
}

//boolean QWhatsThis.inWhatsThisMode();
KMETHOD QWhatsThis_inWhatsThisMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QWhatsThis::inWhatsThisMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWhatsThis.leaveWhatsThisMode();
KMETHOD QWhatsThis_leaveWhatsThisMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWhatsThis::leaveWhatsThisMode();
	}
	RETURNvoid_();
}

//void QWhatsThis.showText(QPoint pos, String text, QWidget w);
KMETHOD QWhatsThis_showText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		QWidget*  w = RawPtr_to(QWidget*, sfp[3]);
		QWhatsThis::showText(pos, text, w);
	}
	RETURNvoid_();
}

//Array<String> QWhatsThis.parents();
KMETHOD QWhatsThis_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWhatsThis *qp = RawPtr_to(QWhatsThis*, sfp[0]);
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

DummyQWhatsThis::DummyQWhatsThis()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWhatsThis::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWhatsThis::self = ptr;
}

bool DummyQWhatsThis::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWhatsThis::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWhatsThis::event_map->bigin();
	if ((itr = DummyQWhatsThis::event_map->find(str)) == DummyQWhatsThis::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWhatsThis::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWhatsThis::slot_map->bigin();
	if ((itr = DummyQWhatsThis::slot_map->find(str)) == DummyQWhatsThis::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQWhatsThis::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQWhatsThis::connection(QObject *o)
{
	QWhatsThis *p = dynamic_cast<QWhatsThis*>(o);
	if (p != NULL) {
	}
}

KMETHOD QWhatsThis_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWhatsThis *qp = RawPtr_to(KQWhatsThis *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWhatsThis]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWhatsThis]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWhatsThis_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWhatsThis *qp = RawPtr_to(KQWhatsThis *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWhatsThis]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWhatsThis]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWhatsThis_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWhatsThis *qp = (KQWhatsThis *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWhatsThis_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWhatsThis *qp = (KQWhatsThis *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWhatsThis_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWhatsThis::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWhatsThis(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWhatsThis";
	cdef->free = QWhatsThis_free;
	cdef->reftrace = QWhatsThis_reftrace;
	cdef->compareTo = QWhatsThis_compareTo;
}


