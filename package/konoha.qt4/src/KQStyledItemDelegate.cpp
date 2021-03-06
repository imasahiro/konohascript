//@Virtual @Override QWidget QStyledItemDelegate.createEditor(QWidget parent, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QStyledItemDelegate_createEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
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

//@Virtual @Override void QStyledItemDelegate.paint(QPainter painter, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QStyledItemDelegate_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->paint(painter, option, index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QStyledItemDelegate.setEditorData(QWidget editor, QModelIndex index);
KMETHOD QStyledItemDelegate_setEditorData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[2]);
		qp->setEditorData(editor, index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QStyledItemDelegate.setModelData(QWidget editor, QAbstractItemModel model, QModelIndex index);
KMETHOD QStyledItemDelegate_setModelData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->setModelData(editor, model, index);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QStyledItemDelegate.sizeHint(QStyleOptionViewItem option, QModelIndex index);
KMETHOD QStyledItemDelegate_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
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

//@Virtual @Override void QStyledItemDelegate.updateEditorGeometry(QWidget editor, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QStyledItemDelegate_updateEditorGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->updateEditorGeometry(editor, option, index);
	}
	RETURNvoid_();
}

//QStyledItemDelegate QStyledItemDelegate.new(QObject parent);
KMETHOD QStyledItemDelegate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQStyledItemDelegate *ret_v = new KQStyledItemDelegate(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual String QStyledItemDelegate.displayText(QVariant value, QLocale locale);
KMETHOD QStyledItemDelegate_displayText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[1]);
		const QLocale  locale = *RawPtr_to(const QLocale *, sfp[2]);
		QString ret_v = qp->displayText(value, locale);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QItemEditorFactory QStyledItemDelegate.getItemEditorFactory();
KMETHOD QStyledItemDelegate_getItemEditorFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		QItemEditorFactory* ret_v = qp->itemEditorFactory();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QItemEditorFactory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QStyledItemDelegate.setItemEditorFactory(QItemEditorFactory factory);
KMETHOD QStyledItemDelegate_setItemEditorFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyledItemDelegate *  qp = RawPtr_to(QStyledItemDelegate *, sfp[0]);
	if (qp) {
		QItemEditorFactory*  factory = RawPtr_to(QItemEditorFactory*, sfp[1]);
		qp->setItemEditorFactory(factory);
	}
	RETURNvoid_();
}


DummyQStyledItemDelegate::DummyQStyledItemDelegate()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyledItemDelegate::~DummyQStyledItemDelegate()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyledItemDelegate::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyledItemDelegate::self = ptr;
	DummyQAbstractItemDelegate::setSelf(ptr);
}

bool DummyQStyledItemDelegate::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemDelegate::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyledItemDelegate::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyledItemDelegate::event_map->bigin();
	if ((itr = DummyQStyledItemDelegate::event_map->find(str)) == DummyQStyledItemDelegate::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemDelegate::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyledItemDelegate::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyledItemDelegate::slot_map->bigin();
	if ((itr = DummyQStyledItemDelegate::slot_map->find(str)) == DummyQStyledItemDelegate::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemDelegate::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyledItemDelegate::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyledItemDelegate::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractItemDelegate::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyledItemDelegate::connection(QObject *o)
{
	QStyledItemDelegate *p = dynamic_cast<QStyledItemDelegate*>(o);
	if (p != NULL) {
	}
	DummyQAbstractItemDelegate::connection(o);
}

KQStyledItemDelegate::KQStyledItemDelegate(QObject* parent) : QStyledItemDelegate(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyledItemDelegate();
	dummy->connection((QObject*)this);
}

KQStyledItemDelegate::~KQStyledItemDelegate()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyledItemDelegate_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyledItemDelegate *qp = RawPtr_to(KQStyledItemDelegate *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyledItemDelegate]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyledItemDelegate]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyledItemDelegate_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyledItemDelegate *qp = RawPtr_to(KQStyledItemDelegate *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyledItemDelegate]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyledItemDelegate]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyledItemDelegate_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyledItemDelegate *qp = (KQStyledItemDelegate *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyledItemDelegate*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyledItemDelegate_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyledItemDelegate *qp = (KQStyledItemDelegate *)p->rawptr;
		KQStyledItemDelegate *qp = static_cast<KQStyledItemDelegate*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyledItemDelegate_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyledItemDelegate::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQStyledItemDelegate::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QStyledItemDelegate::event(event);
		return false;
	}
//	QStyledItemDelegate::event(event);
	return true;
}



DEFAPI(void) defQStyledItemDelegate(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyledItemDelegate";
	cdef->free = QStyledItemDelegate_free;
	cdef->reftrace = QStyledItemDelegate_reftrace;
	cdef->compareTo = QStyledItemDelegate_compareTo;
}


