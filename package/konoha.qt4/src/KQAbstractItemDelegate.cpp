//
//@Virtual QWidget QAbstractItemDelegate.createEditor(QWidget parent, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QAbstractItemDelegate_createEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
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

//@Virtual boolean QAbstractItemDelegate.editorEvent(QEvent event, QAbstractItemModel model, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QAbstractItemDelegate_editorEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
	if (qp) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[2]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[3]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[4]);
		bool ret_v = qp->editorEvent(event, model, option, index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractItemDelegate.paint(QPainter painter, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QAbstractItemDelegate_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->paint(painter, option, index);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemDelegate.setEditorData(QWidget editor, QModelIndex index);
KMETHOD QAbstractItemDelegate_setEditorData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[2]);
		qp->setEditorData(editor, index);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemDelegate.setModelData(QWidget editor, QAbstractItemModel model, QModelIndex index);
KMETHOD QAbstractItemDelegate_setModelData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->setModelData(editor, model, index);
	}
	RETURNvoid_();
}

//@Virtual QSize QAbstractItemDelegate.sizeHint(QStyleOptionViewItem option, QModelIndex index);
KMETHOD QAbstractItemDelegate_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
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

//@Virtual void QAbstractItemDelegate.updateEditorGeometry(QWidget editor, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QAbstractItemDelegate_updateEditorGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
	if (qp) {
		QWidget*  editor = RawPtr_to(QWidget*, sfp[1]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		qp->updateEditorGeometry(editor, option, index);
	}
	RETURNvoid_();
}

//boolean QAbstractItemDelegate.helpEvent(QHelpEvent event, QAbstractItemView view, QStyleOptionViewItem option, QModelIndex index);
KMETHOD QAbstractItemDelegate_helpEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemDelegate *  qp = RawPtr_to(QAbstractItemDelegate *, sfp[0]);
	if (qp) {
		QHelpEvent*  event = RawPtr_to(QHelpEvent*, sfp[1]);
		QAbstractItemView*  view = RawPtr_to(QAbstractItemView*, sfp[2]);
		const QStyleOptionViewItem  option = *RawPtr_to(const QStyleOptionViewItem *, sfp[3]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[4]);
		bool ret_v = qp->helpEvent(event, view, option, index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQAbstractItemDelegate::DummyQAbstractItemDelegate()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	close_editor_func = NULL;
	commit_data_func = NULL;
	size_hint_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("close-editor", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("commit-data", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("size-hint-changed", NULL));
}
DummyQAbstractItemDelegate::~DummyQAbstractItemDelegate()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAbstractItemDelegate::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractItemDelegate::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractItemDelegate::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractItemDelegate::closeEditorSlot(QWidget* editor, QAbstractItemDelegate::EndEditHint hint)
{
	if (close_editor_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWidget, editor);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = hint;
		knh_Func_invoke(lctx, close_editor_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQAbstractItemDelegate::commitDataSlot(QWidget* editor)
{
	if (commit_data_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWidget, editor);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, commit_data_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractItemDelegate::sizeHintChangedSlot(const QModelIndex index)
{
	if (size_hint_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, index);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, size_hint_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractItemDelegate::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemDelegate::event_map->bigin();
	if ((itr = DummyQAbstractItemDelegate::event_map->find(str)) == DummyQAbstractItemDelegate::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractItemDelegate::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemDelegate::slot_map->bigin();
	if ((itr = DummyQAbstractItemDelegate::slot_map->find(str)) == DummyQAbstractItemDelegate::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		close_editor_func = (*slot_map)["close-editor"];
		commit_data_func = (*slot_map)["commit-data"];
		size_hint_changed_func = (*slot_map)["size-hint-changed"];
		return true;
	}
}

knh_Object_t** DummyQAbstractItemDelegate::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractItemDelegate::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, close_editor_func);
	KNH_ADDNNREF(ctx, commit_data_func);
	KNH_ADDNNREF(ctx, size_hint_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractItemDelegate::connection(QObject *o)
{
	QAbstractItemDelegate *p = dynamic_cast<QAbstractItemDelegate*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(closeEditor(QWidget*, QAbstractItemDelegate::EndEditHint)), this, SLOT(closeEditorSlot(QWidget*, QAbstractItemDelegate::EndEditHint)));
		connect(p, SIGNAL(commitData(QWidget*)), this, SLOT(commitDataSlot(QWidget*)));
		connect(p, SIGNAL(sizeHintChanged(const QModelIndex)), this, SLOT(sizeHintChangedSlot(const QModelIndex)));
	}
	DummyQObject::connection(o);
}

KQAbstractItemDelegate::KQAbstractItemDelegate(QObject* parent) : QAbstractItemDelegate(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQAbstractItemDelegate();
	dummy->connection((QObject*)this);
}

KQAbstractItemDelegate::~KQAbstractItemDelegate()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAbstractItemDelegate_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractItemDelegate *qp = RawPtr_to(KQAbstractItemDelegate *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractItemDelegate]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemDelegate]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractItemDelegate_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractItemDelegate *qp = RawPtr_to(KQAbstractItemDelegate *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractItemDelegate]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemDelegate]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractItemDelegate_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAbstractItemDelegate *qp = (KQAbstractItemDelegate *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAbstractItemDelegate*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAbstractItemDelegate_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAbstractItemDelegate *qp = (KQAbstractItemDelegate *)p->rawptr;
		KQAbstractItemDelegate *qp = static_cast<KQAbstractItemDelegate*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractItemDelegate_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractItemDelegate::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractItemDelegate::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractItemDelegate::event(event);
		return false;
	}
//	QAbstractItemDelegate::event(event);
	return true;
}

static knh_IntData_t QAbstractItemDelegateConstInt[] = {
	{"NoHint", QAbstractItemDelegate::NoHint},
	{"EditNextItem", QAbstractItemDelegate::EditNextItem},
	{"EditPreviousItem", QAbstractItemDelegate::EditPreviousItem},
	{"SubmitModelCache", QAbstractItemDelegate::SubmitModelCache},
	{"RevertModelCache", QAbstractItemDelegate::RevertModelCache},
	{NULL, 0}
};

DEFAPI(void) constQAbstractItemDelegate(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractItemDelegateConstInt);
}


DEFAPI(void) defQAbstractItemDelegate(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractItemDelegate";
	cdef->free = QAbstractItemDelegate_free;
	cdef->reftrace = QAbstractItemDelegate_reftrace;
	cdef->compareTo = QAbstractItemDelegate_compareTo;
}


