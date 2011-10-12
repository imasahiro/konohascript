//void QTextList.add(QTextBlock block);
KMETHOD QTextList_add(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
		qp->add(block);
	}
	RETURNvoid_();
}

//int QTextList.count();
KMETHOD QTextList_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextListFormat QTextList.getFormat();
KMETHOD QTextList_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		QTextListFormat ret_v = qp->format();
		QTextListFormat *ret_v_ = new QTextListFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlock QTextList.item(int i);
KMETHOD QTextList_item(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextBlock ret_v = qp->item(i);
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextList.itemNumber(QTextBlock block);
KMETHOD QTextList_itemNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
		int ret_v = qp->itemNumber(block);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextList.itemText(QTextBlock block);
KMETHOD QTextList_itemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
		QString ret_v = qp->itemText(block);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextList.remove(QTextBlock block);
KMETHOD QTextList_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
		qp->remove(block);
	}
	RETURNvoid_();
}

//void QTextList.removeItem(int i);
KMETHOD QTextList_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		qp->removeItem(i);
	}
	RETURNvoid_();
}

//void QTextList.setFormat(QTextListFormat fmt);
KMETHOD QTextList_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextList *  qp = RawPtr_to(QTextList *, sfp[0]);
	if (qp != NULL) {
		const QTextListFormat  format = *RawPtr_to(const QTextListFormat *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}


DummyQTextList::DummyQTextList()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextList::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextList::self = ptr;
	DummyQTextBlockGroup::setSelf(ptr);
}

bool DummyQTextList::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextBlockGroup::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextList::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextList::event_map->bigin();
	if ((itr = DummyQTextList::event_map->find(str)) == DummyQTextList::event_map->end()) {
		bool ret;
		ret = DummyQTextBlockGroup::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextList::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextList::slot_map->bigin();
	if ((itr = DummyQTextList::event_map->find(str)) == DummyQTextList::slot_map->end()) {
		bool ret;
		ret = DummyQTextBlockGroup::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KMETHOD QTextList_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextList *qp = RawPtr_to(KQTextList *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextList]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextList::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextList]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextList_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextList *qp = RawPtr_to(KQTextList *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextList]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextList::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextList]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextList_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextList *qp = (KQTextList *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextList_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextList *qp = (KQTextList *)p->rawptr;
		(void)qp;
	}
}

static int QTextList_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTextList::event(QEvent *event)
{
	if (!DummyQTextList::eventDispatcher(event)) {
		QTextList::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTextList(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextList";
	cdef->free = QTextList_free;
	cdef->reftrace = QTextList_reftrace;
	cdef->compareTo = QTextList_compareTo;
}


