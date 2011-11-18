//QToolBox QToolBox.new(QWidget parent, QtWindowFlags f);
KMETHOD QToolBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(f, Qt::WindowFlags, sfp[2]);
	KQToolBox *ret_v = new KQToolBox(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QToolBox.addItem(QWidget widget, QIcon iconSet, String text);
KMETHOD QToolBox_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		const QIcon  iconSet = *RawPtr_to(const QIcon *, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		int ret_v = qp->addItem(widget, iconSet, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QToolBox.addItem(QWidget w, String text);
KMETHOD QToolBox_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		int ret_v = qp->addItem(w, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QToolBox.count();
KMETHOD QToolBox_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QToolBox.getCurrentIndex();
KMETHOD QToolBox_getCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QToolBox.getCurrentWidget();
KMETHOD QToolBox_getCurrentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->currentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QToolBox.indexOf(QWidget widget);
KMETHOD QToolBox_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int ret_v = qp->indexOf(widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QToolBox.insertItem(int index, QWidget widget, QIcon icon, String text);
KMETHOD QToolBox_insertItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[3]);
		const QString text = String_to(const QString, sfp[4]);
		int ret_v = qp->insertItem(index, widget, icon, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QToolBox.insertItem(int index, QWidget widget, String text);
KMETHOD QToolBox_insertItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		int ret_v = qp->insertItem(index, widget, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//boolean QToolBox.isItemEnabled(int index);
KMETHOD QToolBox_isItemEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		bool ret_v = qp->isItemEnabled(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QIcon QToolBox.getItemIcon(int index);
KMETHOD QToolBox_getItemIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QIcon ret_v = qp->itemIcon(index);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QToolBox.getItemText(int index);
KMETHOD QToolBox_getItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->itemText(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QToolBox.getItemToolTip(int index);
KMETHOD QToolBox_getItemToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->itemToolTip(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QToolBox.removeItem(int index);
KMETHOD QToolBox_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->removeItem(index);
	}
	RETURNvoid_();
}

//void QToolBox.setItemEnabled(int index, boolean enabled);
KMETHOD QToolBox_setItemEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setItemEnabled(index, enabled);
	}
	RETURNvoid_();
}

//void QToolBox.setItemIcon(int index, QIcon icon);
KMETHOD QToolBox_setItemIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		qp->setItemIcon(index, icon);
	}
	RETURNvoid_();
}

//void QToolBox.setItemText(int index, String text);
KMETHOD QToolBox_setItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setItemText(index, text);
	}
	RETURNvoid_();
}

//void QToolBox.setItemToolTip(int index, String toolTip);
KMETHOD QToolBox_setItemToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QString toolTip = String_to(const QString, sfp[2]);
		qp->setItemToolTip(index, toolTip);
	}
	RETURNvoid_();
}

//QWidget QToolBox.widget(int index);
KMETHOD QToolBox_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QWidget* ret_v = qp->widget(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QToolBox.setCurrentIndex(int index);
KMETHOD QToolBox_setCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->setCurrentIndex(index);
	}
	RETURNvoid_();
}

//void QToolBox.setCurrentWidget(QWidget widget);
KMETHOD QToolBox_setCurrentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBox *  qp = RawPtr_to(QToolBox *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setCurrentWidget(widget);
	}
	RETURNvoid_();
}


DummyQToolBox::DummyQToolBox()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	current_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-changed", NULL));
}
DummyQToolBox::~DummyQToolBox()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQToolBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQToolBox::self = ptr;
	DummyQFrame::setSelf(ptr);
}

bool DummyQToolBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQToolBox::currentChangedSlot(int index)
{
	if (current_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = index;
		knh_Func_invoke(lctx, current_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQToolBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolBox::event_map->bigin();
	if ((itr = DummyQToolBox::event_map->find(str)) == DummyQToolBox::event_map->end()) {
		bool ret = false;
		ret = DummyQFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQToolBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolBox::slot_map->bigin();
	if ((itr = DummyQToolBox::slot_map->find(str)) == DummyQToolBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_changed_func = (*slot_map)["current-changed"];
		return true;
	}
}

knh_Object_t** DummyQToolBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQToolBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, current_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQFrame::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQToolBox::connection(QObject *o)
{
	QToolBox *p = dynamic_cast<QToolBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(currentChanged(int)), this, SLOT(currentChangedSlot(int)));
	}
	DummyQFrame::connection(o);
}

KQToolBox::KQToolBox(QWidget* parent, Qt::WindowFlags f) : QToolBox(parent, f)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQToolBox();
	dummy->connection((QObject*)this);
}

KQToolBox::~KQToolBox()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QToolBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolBox *qp = RawPtr_to(KQToolBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QToolBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QToolBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolBox *qp = RawPtr_to(KQToolBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QToolBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QToolBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQToolBox *qp = (KQToolBox *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QToolBox*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QToolBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQToolBox *qp = (KQToolBox *)p->rawptr;
		KQToolBox *qp = static_cast<KQToolBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QToolBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQToolBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQToolBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QToolBox::event(event);
		return false;
	}
//	QToolBox::event(event);
	return true;
}



DEFAPI(void) defQToolBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QToolBox";
	cdef->free = QToolBox_free;
	cdef->reftrace = QToolBox_reftrace;
	cdef->compareTo = QToolBox_compareTo;
}


