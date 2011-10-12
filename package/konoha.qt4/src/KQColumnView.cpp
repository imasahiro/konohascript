//@Virtual @Override QModelIndex QColumnView.indexAt(QPoint point);
KMETHOD QColumnView_indexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QModelIndex ret_v = qp->indexAt(point);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QColumnView.scrollTo(QModelIndex index, int hint);
KMETHOD QColumnView_scrollTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QColumnView::ScrollHint hint = Int_to(QColumnView::ScrollHint, sfp[2]);
		qp->scrollTo(index, hint);
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.selectAll();
KMETHOD QColumnView_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.setModel(QAbstractItemModel model);
KMETHOD QColumnView_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.setRootIndex(QModelIndex index);
KMETHOD QColumnView_setRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootIndex(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QColumnView.setSelectionModel(QItemSelectionModel new_SelectionModel);
KMETHOD QColumnView_setSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		QItemSelectionModel*  new_SelectionModel = RawPtr_to(QItemSelectionModel*, sfp[1]);
		qp->setSelectionModel(new_SelectionModel);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QColumnView.sizeHint();
KMETHOD QColumnView_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QColumnView.visualRect(QModelIndex index);
KMETHOD QColumnView_visualRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QRect ret_v = qp->visualRect(index);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColumnView QColumnView.new(QWidget parent);
KMETHOD QColumnView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQColumnView *ret_v = new KQColumnView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<int> QColumnView.getColumnWidths();
KMETHOD QColumnView_getColumnWidths(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		QList<int>ret_v = qp->columnWidths();
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
	

//QWidget QColumnView.getPreviewWidget();
KMETHOD QColumnView_getPreviewWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->previewWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QColumnView.getResizeGripsVisible();
KMETHOD QColumnView_getResizeGripsVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->resizeGripsVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QColumnView.setColumnWidths(Array<int> list);
KMETHOD QColumnView_setColumnWidths(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<int> list;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			list.append(*(int*)p->rawptr);
		}
		qp->setColumnWidths(list);
	}
	RETURNvoid_();
}

//void QColumnView.setPreviewWidget(QWidget widget);
KMETHOD QColumnView_setPreviewWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setPreviewWidget(widget);
	}
	RETURNvoid_();
}

//void QColumnView.setResizeGripsVisible(boolean visible);
KMETHOD QColumnView_setResizeGripsVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColumnView *  qp = RawPtr_to(QColumnView *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setResizeGripsVisible(visible);
	}
	RETURNvoid_();
}


DummyQColumnView::DummyQColumnView()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQColumnView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQColumnView::self = ptr;
	DummyQAbstractItemView::setSelf(ptr);
}

bool DummyQColumnView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemView::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQColumnView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColumnView::event_map->bigin();
	if ((itr = DummyQColumnView::event_map->find(str)) == DummyQColumnView::event_map->end()) {
		bool ret;
		ret = DummyQAbstractItemView::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQColumnView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColumnView::slot_map->bigin();
	if ((itr = DummyQColumnView::event_map->find(str)) == DummyQColumnView::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractItemView::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQColumnView::KQColumnView(QWidget* parent) : QColumnView(parent)
{
	self = NULL;
}

KMETHOD QColumnView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColumnView *qp = RawPtr_to(KQColumnView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QColumnView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQColumnView::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColumnView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QColumnView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColumnView *qp = RawPtr_to(KQColumnView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QColumnView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQColumnView::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColumnView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QColumnView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQColumnView *qp = (KQColumnView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QColumnView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQColumnView *qp = (KQColumnView *)p->rawptr;
		(void)qp;
	}
}

static int QColumnView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQColumnView::event(QEvent *event)
{
	if (!DummyQColumnView::eventDispatcher(event)) {
		QColumnView::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQColumnView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColumnView";
	cdef->free = QColumnView_free;
	cdef->reftrace = QColumnView_reftrace;
	cdef->compareTo = QColumnView_compareTo;
}


