//QButtonGroup QButtonGroup.new(QObject parent);
KMETHOD QButtonGroup_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQButtonGroup *ret_v = new KQButtonGroup(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QButtonGroup.addButton(QAbstractButton button);
KMETHOD QButtonGroup_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		qp->addButton(button);
	}
	RETURNvoid_();
}

/*
//void QButtonGroup.addButton(QAbstractButton button, int id);
KMETHOD QButtonGroup_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		int id = Int_to(int, sfp[2]);
		qp->addButton(button, id);
	}
	RETURNvoid_();
}
*/
//QAbstractButton QButtonGroup.button(int id);
KMETHOD QButtonGroup_button(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		QAbstractButton* ret_v = qp->button(id);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QAbstractButton> QButtonGroup.buttons();
KMETHOD QButtonGroup_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QList<QAbstractButton*>ret_v = qp->buttons();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAbstractButton"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QAbstractButton QButtonGroup.checkedButton();
KMETHOD QButtonGroup_checkedButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton* ret_v = qp->checkedButton();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QButtonGroup.checkedId();
KMETHOD QButtonGroup_checkedId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->checkedId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QButtonGroup.getExclusive();
KMETHOD QButtonGroup_getExclusive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->exclusive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QButtonGroup.getId(QAbstractButton button);
KMETHOD QButtonGroup_getId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		int ret_v = qp->id(button);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QButtonGroup.removeButton(QAbstractButton button);
KMETHOD QButtonGroup_removeButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		qp->removeButton(button);
	}
	RETURNvoid_();
}

//void QButtonGroup.setExclusive(boolean arg0);
KMETHOD QButtonGroup_setExclusive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setExclusive(arg0);
	}
	RETURNvoid_();
}

//void QButtonGroup.setId(QAbstractButton button, int id);
KMETHOD QButtonGroup_setId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QButtonGroup *  qp = RawPtr_to(QButtonGroup *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		int id = Int_to(int, sfp[2]);
		qp->setId(button, id);
	}
	RETURNvoid_();
}


DummyQButtonGroup::DummyQButtonGroup()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQButtonGroup::setSelf(knh_RawPtr_t *ptr)
{
	DummyQButtonGroup::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQButtonGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQButtonGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQButtonGroup::event_map->bigin();
	if ((itr = DummyQButtonGroup::event_map->find(str)) == DummyQButtonGroup::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQButtonGroup::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQButtonGroup::slot_map->bigin();
	if ((itr = DummyQButtonGroup::event_map->find(str)) == DummyQButtonGroup::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQButtonGroup::KQButtonGroup(QObject* parent) : QButtonGroup(parent)
{
	self = NULL;
}

KMETHOD QButtonGroup_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQButtonGroup *qp = RawPtr_to(KQButtonGroup *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QButtonGroup]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQButtonGroup::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QButtonGroup]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QButtonGroup_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQButtonGroup *qp = RawPtr_to(KQButtonGroup *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QButtonGroup]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQButtonGroup::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QButtonGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QButtonGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQButtonGroup *qp = (KQButtonGroup *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QButtonGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQButtonGroup *qp = (KQButtonGroup *)p->rawptr;
		(void)qp;
	}
}

static int QButtonGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQButtonGroup::event(QEvent *event)
{
	if (!DummyQButtonGroup::eventDispatcher(event)) {
		QButtonGroup::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQButtonGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QButtonGroup";
	cdef->free = QButtonGroup_free;
	cdef->reftrace = QButtonGroup_reftrace;
	cdef->compareTo = QButtonGroup_compareTo;
}


