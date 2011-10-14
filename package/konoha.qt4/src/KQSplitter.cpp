//@Virtual @Override QSize QSplitter.minimumSizeHint();
KMETHOD QSplitter_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QSplitter.sizeHint();
KMETHOD QSplitter_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSplitter QSplitter.new(QWidget parent);
KMETHOD QSplitter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQSplitter *ret_v = new KQSplitter(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSplitter QSplitter.new(int orientation, QWidget parent);
KMETHOD QSplitter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQSplitter *ret_v = new KQSplitter(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QSplitter.addWidget(QWidget widget);
KMETHOD QSplitter_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->addWidget(widget);
	}
	RETURNvoid_();
}

//boolean QSplitter.getChildrenCollapsible();
KMETHOD QSplitter_getChildrenCollapsible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->childrenCollapsible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSplitter.count();
KMETHOD QSplitter_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSplitter.getRange(int index, int min, int max);
KMETHOD QSplitter_getRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		int* min = Int_to(int*, sfp[2]);
		int* max = Int_to(int*, sfp[3]);
		qp->getRange(index, min, max);
	}
	RETURNvoid_();
}

//QSplitterHandle QSplitter.handle(int index);
KMETHOD QSplitter_handle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QSplitterHandle* ret_v = qp->handle(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QSplitterHandle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSplitter.getHandleWidth();
KMETHOD QSplitter_getHandleWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->handleWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSplitter.indexOf(QWidget widget);
KMETHOD QSplitter_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int ret_v = qp->indexOf(widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSplitter.insertWidget(int index, QWidget widget);
KMETHOD QSplitter_insertWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		qp->insertWidget(index, widget);
	}
	RETURNvoid_();
}

//boolean QSplitter.isCollapsible(int index);
KMETHOD QSplitter_isCollapsible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		bool ret_v = qp->isCollapsible(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QSplitter.getOpaqueResize();
KMETHOD QSplitter_getOpaqueResize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->opaqueResize();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSplitter.getOrientation();
KMETHOD QSplitter_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSplitter.refresh();
KMETHOD QSplitter_refresh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		qp->refresh();
	}
	RETURNvoid_();
}

//boolean QSplitter.restoreState(QByteArray state);
KMETHOD QSplitter_restoreState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  state = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->restoreState(state);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QByteArray QSplitter.saveState();
KMETHOD QSplitter_saveState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->saveState();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSplitter.setChildrenCollapsible(boolean arg0);
KMETHOD QSplitter_setChildrenCollapsible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setChildrenCollapsible(arg0);
	}
	RETURNvoid_();
}

//void QSplitter.setCollapsible(int index, boolean collapse);
KMETHOD QSplitter_setCollapsible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		bool collapse = Boolean_to(bool, sfp[2]);
		qp->setCollapsible(index, collapse);
	}
	RETURNvoid_();
}

//void QSplitter.setHandleWidth(int arg0);
KMETHOD QSplitter_setHandleWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setHandleWidth(arg0);
	}
	RETURNvoid_();
}

//void QSplitter.setOpaqueResize(boolean opaque);
KMETHOD QSplitter_setOpaqueResize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		bool opaque = Boolean_to(bool, sfp[1]);
		qp->setOpaqueResize(opaque);
	}
	RETURNvoid_();
}

//void QSplitter.setOrientation(int arg0);
KMETHOD QSplitter_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation arg0 = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(arg0);
	}
	RETURNvoid_();
}

//void QSplitter.setSizes(Array<int> list);
KMETHOD QSplitter_setSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<int> list;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			list.append(*(int*)p->rawptr);
		}
		qp->setSizes(list);
	}
	RETURNvoid_();
}

//void QSplitter.setStretchFactor(int index, int stretch);
KMETHOD QSplitter_setStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setStretchFactor(index, stretch);
	}
	RETURNvoid_();
}

//Array<int> QSplitter.getSizes();
KMETHOD QSplitter_getSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		QList<int>ret_v = qp->sizes();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("int"));
		for (int n = 0; n < list_size; n++) {
			int *ret_v_ = new int(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QWidget QSplitter.widget(int index);
KMETHOD QSplitter_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplitter *  qp = RawPtr_to(QSplitter *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget* ret_v = qp->widget(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQSplitter::DummyQSplitter()
{
	self = NULL;
	splitter_moved_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("splitter-moved", NULL));
}

void DummyQSplitter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSplitter::self = ptr;
	DummyQFrame::setSelf(ptr);
}

bool DummyQSplitter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSplitter::splitterMovedSlot(int pos, int index)
{
	if (splitter_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = pos;
		lsfp[K_CALLDELTA+3].ivalue = index;
		knh_Func_invoke(lctx, splitter_moved_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQSplitter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplitter::event_map->bigin();
	if ((itr = DummyQSplitter::event_map->find(str)) == DummyQSplitter::event_map->end()) {
		bool ret = false;
		ret = DummyQFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSplitter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplitter::slot_map->bigin();
	if ((itr = DummyQSplitter::slot_map->find(str)) == DummyQSplitter::slot_map->end()) {
		bool ret = false;
		ret = DummyQFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		splitter_moved_func = (*slot_map)["splitter-moved"];
		return true;
	}
}


void DummyQSplitter::connection(QObject *o)
{
	connect(o, SIGNAL(splitterMoved(int, int)), this, SLOT(splitterMovedSlot(int, int)));
	DummyQFrame::connection(o);
}

KQSplitter::KQSplitter(QWidget* parent) : QSplitter(parent)
{
	self = NULL;
	dummy = new DummyQSplitter();
	dummy->connection((QObject*)this);
}

KMETHOD QSplitter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSplitter *qp = RawPtr_to(KQSplitter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSplitter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplitter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSplitter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSplitter *qp = RawPtr_to(KQSplitter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSplitter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplitter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSplitter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSplitter *qp = (KQSplitter *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSplitter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQSplitter *qp = (KQSplitter *)p->rawptr;
//		(void)qp;
		if (qp->dummy->splitter_moved_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->splitter_moved_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QSplitter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSplitter::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSplitter::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSplitter::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQSplitter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSplitter";
	cdef->free = QSplitter_free;
	cdef->reftrace = QSplitter_reftrace;
	cdef->compareTo = QSplitter_compareTo;
}


