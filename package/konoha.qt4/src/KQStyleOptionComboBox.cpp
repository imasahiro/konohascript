//QStyleOptionComboBox QStyleOptionComboBox.new();
KMETHOD QStyleOptionComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComboBox *ret_v = new KQStyleOptionComboBox();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionComboBox QStyleOptionComboBox.new(QStyleOptionComboBox other);
KMETHOD QStyleOptionComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionComboBox  other = *RawPtr_to(const QStyleOptionComboBox *, sfp[1]);
	KQStyleOptionComboBox *ret_v = new KQStyleOptionComboBox(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionComboBox::DummyQStyleOptionComboBox()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionComboBox::~DummyQStyleOptionComboBox()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionComboBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionComboBox::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionComboBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionComboBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionComboBox::event_map->bigin();
	if ((itr = DummyQStyleOptionComboBox::event_map->find(str)) == DummyQStyleOptionComboBox::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionComboBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionComboBox::slot_map->bigin();
	if ((itr = DummyQStyleOptionComboBox::slot_map->find(str)) == DummyQStyleOptionComboBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionComboBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionComboBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionComplex::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionComboBox::connection(QObject *o)
{
	QStyleOptionComboBox *p = dynamic_cast<QStyleOptionComboBox*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionComplex::connection(o);
}

KQStyleOptionComboBox::KQStyleOptionComboBox() : QStyleOptionComboBox()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionComboBox();
}

KQStyleOptionComboBox::~KQStyleOptionComboBox()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionComboBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComboBox *qp = RawPtr_to(KQStyleOptionComboBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionComboBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComboBox *qp = RawPtr_to(KQStyleOptionComboBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionComboBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionComboBox *qp = (KQStyleOptionComboBox *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionComboBox*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionComboBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionComboBox *qp = (KQStyleOptionComboBox *)p->rawptr;
		KQStyleOptionComboBox *qp = static_cast<KQStyleOptionComboBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionComboBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionComboBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionComboBoxConstInt[] = {
	{"Type", QStyleOptionComboBox::Type},
	{"Version", QStyleOptionComboBox::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionComboBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionComboBoxConstInt);
}


DEFAPI(void) defQStyleOptionComboBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionComboBox";
	cdef->free = QStyleOptionComboBox_free;
	cdef->reftrace = QStyleOptionComboBox_reftrace;
	cdef->compareTo = QStyleOptionComboBox_compareTo;
}


