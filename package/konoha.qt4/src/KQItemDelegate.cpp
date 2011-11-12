//@Virtual @Override QWidget QItemDelegate.createEditor(QWidget parent, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QItemDelegate_createEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		QWidget* ret_v = qp->createEditor(parent, option, index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QItemDelegate.paint(QPainter painter, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QItemDelegate_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->paint(painter, option, index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QItemDelegate.setEditorData(QWidget editor, QModelIndex index);
KMETHOD QItemDelegate_setEditorData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[2]);
		qp->setEditorData(editor, index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QItemDelegate.setModelData(QWidget editor, QAbstractItemModel model, QModelIndex index);
KMETHOD QItemDelegate_setModelData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->setModelData(editor, model, index);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QItemDelegate.sizeHint(QStyleOptionViewItem option, QModelIndex index);
KMETHOD QItemDelegate_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[1]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[2]);
		QSize ret_v = qp->sizeHint(option, index);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QItemDelegate.updateEditorGeometry(QWidget editor, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QItemDelegate_updateEditorGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->updateEditorGeometry(editor, option, index);
	}
	RETURNvoid_();
}

//QItemDelegate QItemDelegate.new(QObject parent);
KMETHOD QItemDelegate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQItemDelegate *ret_v = new KQItemDelegate(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QItemDelegate.hasClipping();
KMETHOD QItemDelegate_hasClipping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasClipping();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QItemEditorFactory QItemDelegate.getItemEditorFactory();
KMETHOD QItemDelegate_getItemEditorFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QItemEditorFactory* ret_v = qp->itemEditorFactory();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QItemEditorFactory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QItemDelegate.setClipping(boolean clip);
KMETHOD QItemDelegate_setClipping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		bool clip = Boolean_to(bool, sfp[1]);
		qp->setClipping(clip);
	}
	RETURNvoid_();
}

//void QItemDelegate.setItemEditorFactory(QItemEditorFactory factory);
KMETHOD QItemDelegate_setItemEditorFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemDelegate *  qp = RawPtr_to(QItemDelegate *, sfp[0]);
	if (qp) {
		QItemEditorFactory*  factory = RawPtr_to(QItemEditorFactory*, sfp[1]);
		qp->setItemEditorFactory(factory);
	}
	RETURNvoid_();
}


DummyQItemDelegate::DummyQItemDelegate()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQItemDelegate::setSelf(knh_RawPtr_t *ptr)
{
	DummyQItemDelegate::self = ptr;
	DummyQAbstractItemDelegate::setSelf(ptr);
}

bool DummyQItemDelegate::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemDelegate::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQItemDelegate::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQItemDelegate::event_map->bigin();
	if ((itr = DummyQItemDelegate::event_map->find(str)) == DummyQItemDelegate::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemDelegate::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQItemDelegate::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQItemDelegate::slot_map->bigin();
	if ((itr = DummyQItemDelegate::slot_map->find(str)) == DummyQItemDelegate::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemDelegate::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQItemDelegate::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQItemDelegate::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractItemDelegate::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQItemDelegate::connection(QObject *o)
{
	QItemDelegate *p = dynamic_cast<QItemDelegate*>(o);
	if (p != NULL) {
	}
	DummyQAbstractItemDelegate::connection(o);
}

KQItemDelegate::KQItemDelegate(QObject* parent) : QItemDelegate(parent)
{
	self = NULL;
	dummy = new DummyQItemDelegate();
	dummy->connection((QObject*)this);
}

KMETHOD QItemDelegate_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemDelegate *qp = RawPtr_to(KQItemDelegate *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QItemDelegate]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QItemDelegate]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QItemDelegate_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemDelegate *qp = RawPtr_to(KQItemDelegate *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QItemDelegate]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QItemDelegate]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QItemDelegate_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQItemDelegate *qp = (KQItemDelegate *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QItemDelegate_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQItemDelegate *qp = (KQItemDelegate *)p->rawptr;
//		KQItemDelegate *qp = static_cast<KQItemDelegate*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QItemDelegate_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQItemDelegate::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQItemDelegate::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QItemDelegate::event(event);
		return false;
	}
//	QItemDelegate::event(event);
	return true;
}



DEFAPI(void) defQItemDelegate(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QItemDelegate";
	cdef->free = QItemDelegate_free;
	cdef->reftrace = QItemDelegate_reftrace;
	cdef->compareTo = QItemDelegate_compareTo;
}


