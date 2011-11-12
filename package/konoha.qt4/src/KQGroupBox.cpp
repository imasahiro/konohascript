//@Virtual @Override QSize QGroupBox.minimumSizeHint();
KMETHOD QGroupBox_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGroupBox QGroupBox.new(QWidget parent);
KMETHOD QGroupBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQGroupBox *ret_v = new KQGroupBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGroupBox QGroupBox.new(String title, QWidget parent);
KMETHOD QGroupBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString title = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQGroupBox *ret_v = new KQGroupBox(title, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QtAlignment QGroupBox.getAlignment();
KMETHOD QGroupBox_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGroupBox.isCheckable();
KMETHOD QGroupBox_isCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCheckable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGroupBox.isChecked();
KMETHOD QGroupBox_isChecked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isChecked();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGroupBox.isFlat();
KMETHOD QGroupBox_isFlat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFlat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGroupBox.setAlignment(int alignment);
KMETHOD QGroupBox_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		int alignment = Int_to(int, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QGroupBox.setCheckable(boolean checkable);
KMETHOD QGroupBox_setCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		bool checkable = Boolean_to(bool, sfp[1]);
		qp->setCheckable(checkable);
	}
	RETURNvoid_();
}

//void QGroupBox.setFlat(boolean flat);
KMETHOD QGroupBox_setFlat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		bool flat = Boolean_to(bool, sfp[1]);
		qp->setFlat(flat);
	}
	RETURNvoid_();
}

//void QGroupBox.setTitle(String title);
KMETHOD QGroupBox_setTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setTitle(title);
	}
	RETURNvoid_();
}

//String QGroupBox.getTitle();
KMETHOD QGroupBox_getTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGroupBox.setChecked(boolean checked);
KMETHOD QGroupBox_setChecked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGroupBox *  qp = RawPtr_to(QGroupBox *, sfp[0]);
	if (qp) {
		bool checked = Boolean_to(bool, sfp[1]);
		qp->setChecked(checked);
	}
	RETURNvoid_();
}


DummyQGroupBox::DummyQGroupBox()
{
	self = NULL;
	clicked_func = NULL;
	toggled_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("toggled", NULL));
}

void DummyQGroupBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGroupBox::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQGroupBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGroupBox::clickedSlot(bool checked)
{
	if (clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = checked;
		knh_Func_invoke(lctx, clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGroupBox::toggledSlot(bool on)
{
	if (toggled_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = on;
		knh_Func_invoke(lctx, toggled_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGroupBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGroupBox::event_map->bigin();
	if ((itr = DummyQGroupBox::event_map->find(str)) == DummyQGroupBox::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGroupBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGroupBox::slot_map->bigin();
	if ((itr = DummyQGroupBox::slot_map->find(str)) == DummyQGroupBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		clicked_func = (*slot_map)["clicked"];
		toggled_func = (*slot_map)["toggled"];
		return true;
	}
}

knh_Object_t** DummyQGroupBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGroupBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, clicked_func);
	KNH_ADDNNREF(ctx, toggled_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGroupBox::connection(QObject *o)
{
	QGroupBox *p = dynamic_cast<QGroupBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(clicked(bool)), this, SLOT(clickedSlot(bool)));
		connect(p, SIGNAL(toggled(bool)), this, SLOT(toggledSlot(bool)));
	}
	DummyQWidget::connection(o);
}

KQGroupBox::KQGroupBox(QWidget* parent) : QGroupBox(parent)
{
	self = NULL;
	dummy = new DummyQGroupBox();
	dummy->connection((QObject*)this);
}

KMETHOD QGroupBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGroupBox *qp = RawPtr_to(KQGroupBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGroupBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGroupBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGroupBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGroupBox *qp = RawPtr_to(KQGroupBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGroupBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGroupBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGroupBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGroupBox *qp = (KQGroupBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGroupBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGroupBox *qp = (KQGroupBox *)p->rawptr;
//		KQGroupBox *qp = static_cast<KQGroupBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGroupBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGroupBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGroupBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGroupBox::event(event);
		return false;
	}
//	QGroupBox::event(event);
	return true;
}



DEFAPI(void) defQGroupBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGroupBox";
	cdef->free = QGroupBox_free;
	cdef->reftrace = QGroupBox_reftrace;
	cdef->compareTo = QGroupBox_compareTo;
}


