//void QWebHistory.back();
KMETHOD QWebHistory_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		qp->back();
	}
	RETURNvoid_();
}

//QWebHistoryItem QWebHistory.backItem();
KMETHOD QWebHistory_backItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		QWebHistoryItem ret_v = qp->backItem();
		QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QWebHistoryItem> QWebHistory.backItems(int maxItems);
KMETHOD QWebHistory_backItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int maxItems = Int_to(int, sfp[1]);
		QList<QWebHistoryItem> ret_v = qp->backItems(maxItems);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebHistoryItem"));
		for (int n = 0; n < list_size; n++) {
			QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QWebHistory.canGoBack();
KMETHOD QWebHistory_canGoBack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canGoBack();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebHistory.canGoForward();
KMETHOD QWebHistory_canGoForward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canGoForward();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWebHistory.clear();
KMETHOD QWebHistory_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//int QWebHistory.count();
KMETHOD QWebHistory_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWebHistoryItem QWebHistory.currentItem();
KMETHOD QWebHistory_currentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		QWebHistoryItem ret_v = qp->currentItem();
		QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebHistory.currentItemIndex();
KMETHOD QWebHistory_currentItemIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentItemIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QWebHistory.forward();
KMETHOD QWebHistory_forward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		qp->forward();
	}
	RETURNvoid_();
}

//QWebHistoryItem QWebHistory.forwardItem();
KMETHOD QWebHistory_forwardItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		QWebHistoryItem ret_v = qp->forwardItem();
		QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QWebHistoryItem> QWebHistory.forwardItems(int maxItems);
KMETHOD QWebHistory_forwardItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int maxItems = Int_to(int, sfp[1]);
		QList<QWebHistoryItem> ret_v = qp->forwardItems(maxItems);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebHistoryItem"));
		for (int n = 0; n < list_size; n++) {
			QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QWebHistory.goToItem(QWebHistoryItem item);
KMETHOD QWebHistory_goToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		const QWebHistoryItem  item = *RawPtr_to(const QWebHistoryItem *, sfp[1]);
		qp->goToItem(item);
	}
	RETURNvoid_();
}

//QWebHistoryItem QWebHistory.itemAt(int i);
KMETHOD QWebHistory_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		QWebHistoryItem ret_v = qp->itemAt(i);
		QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QWebHistoryItem> QWebHistory.items();
KMETHOD QWebHistory_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		QList<QWebHistoryItem> ret_v = qp->items();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebHistoryItem"));
		for (int n = 0; n < list_size; n++) {
			QWebHistoryItem *ret_v_ = new QWebHistoryItem(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QWebHistory.getMaximumItemCount();
KMETHOD QWebHistory_getMaximumItemCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int ret_v = qp->maximumItemCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QWebHistory.setMaximumItemCount(int count);
KMETHOD QWebHistory_setMaximumItemCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *  qp = RawPtr_to(QWebHistory *, sfp[0]);
	if (qp) {
		int count = Int_to(int, sfp[1]);
		qp->setMaximumItemCount(count);
	}
	RETURNvoid_();
}

//Array<String> QWebHistory.parents();
KMETHOD QWebHistory_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistory *qp = RawPtr_to(QWebHistory*, sfp[0]);
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

DummyQWebHistory::DummyQWebHistory()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWebHistory::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebHistory::self = ptr;
}

bool DummyQWebHistory::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebHistory::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHistory::event_map->bigin();
	if ((itr = DummyQWebHistory::event_map->find(str)) == DummyQWebHistory::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebHistory::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHistory::slot_map->bigin();
	if ((itr = DummyQWebHistory::slot_map->find(str)) == DummyQWebHistory::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebHistory::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebHistory::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebHistory::connection(QObject *o)
{
	QWebHistory *p = dynamic_cast<QWebHistory*>(o);
	if (p != NULL) {
	}
}

KMETHOD QWebHistory_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHistory *qp = RawPtr_to(KQWebHistory *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHistory]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHistory]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebHistory_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHistory *qp = RawPtr_to(KQWebHistory *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHistory]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHistory]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebHistory_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebHistory *qp = (KQWebHistory *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebHistory_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebHistory *qp = (KQWebHistory *)p->rawptr;
//		KQWebHistory *qp = static_cast<KQWebHistory*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebHistory_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebHistory::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWebHistory(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebHistory";
	cdef->free = QWebHistory_free;
	cdef->reftrace = QWebHistory_reftrace;
	cdef->compareTo = QWebHistory_compareTo;
}


