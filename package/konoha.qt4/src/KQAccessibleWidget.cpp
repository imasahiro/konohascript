//@Virtual @Override String QAccessibleWidget.actionText(int action, int t, int child);
KMETHOD QAccessibleWidget_actionText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int action = Int_to(int, sfp[1]);
		QAccessibleWidget::Text t = Int_to(QAccessibleWidget::Text, sfp[2]);
		int child = Int_to(int, sfp[3]);
		QString ret_v = qp->actionText(action, t, child);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QAccessibleWidget.childAt(int x, int y);
KMETHOD QAccessibleWidget_childAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int ret_v = qp->childAt(x, y);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override int QAccessibleWidget.childCount();
KMETHOD QAccessibleWidget_childCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->childCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QAccessibleWidget.doAction(int action, int child, QVariantList params);
KMETHOD QAccessibleWidget_doAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int action = Int_to(int, sfp[1]);
		int child = Int_to(int, sfp[2]);
		const QVariantList  params = *RawPtr_to(const QVariantList *, sfp[3]);
		bool ret_v = qp->doAction(action, child, params);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QAccessibleWidget.indexOfChild(QAccessibleInterface child);
KMETHOD QAccessibleWidget_indexOfChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		const QAccessibleInterface*  child = RawPtr_to(const QAccessibleInterface*, sfp[1]);
		int ret_v = qp->indexOfChild(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override int QAccessibleWidget.navigate(int relation, int entry, QAccessibleInterface target);
KMETHOD QAccessibleWidget_navigate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		QAccessibleWidget::RelationFlag relation = Int_to(QAccessibleWidget::RelationFlag, sfp[1]);
		int entry = Int_to(int, sfp[2]);
		QAccessibleInterface**  target = RawPtr_to(QAccessibleInterface**, sfp[3]);
		int ret_v = qp->navigate(relation, entry, target);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QAccessibleWidget.rect(int child);
KMETHOD QAccessibleWidget_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		QRect ret_v = qp->rect(child);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QAccessibleWidget.relationTo(int child, QAccessibleInterface other, int otherChild);
KMETHOD QAccessibleWidget_relationTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		const QAccessibleInterface*  other = RawPtr_to(const QAccessibleInterface*, sfp[2]);
		int otherChild = Int_to(int, sfp[3]);
		QAccessibleWidget::Relation ret_v = qp->relationTo(child, other, otherChild);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override int QAccessibleWidget.role(int child);
KMETHOD QAccessibleWidget_role(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		QAccessibleWidget::Role ret_v = qp->role(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override int QAccessibleWidget.state(int child);
KMETHOD QAccessibleWidget_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		QAccessibleWidget::State ret_v = qp->state(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override String QAccessibleWidget.text(int t, int child);
KMETHOD QAccessibleWidget_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		QAccessibleWidget::Text t = Int_to(QAccessibleWidget::Text, sfp[1]);
		int child = Int_to(int, sfp[2]);
		QString ret_v = qp->text(t, child);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QAccessibleWidget.userActionCount(int child);
KMETHOD QAccessibleWidget_userActionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleWidget *  qp = RawPtr_to(QAccessibleWidget *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		int ret_v = qp->userActionCount(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAccessibleWidget QAccessibleWidget.new(QWidget w, int role, String name);
KMETHOD QAccessibleWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
	QAccessibleWidget::Role role = Int_to(QAccessibleWidget::Role, sfp[2]);
	const QString name = String_to(const QString, sfp[3]);
	KQAccessibleWidget *ret_v = new KQAccessibleWidget(w, role, name);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQAccessibleWidget::DummyQAccessibleWidget()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAccessibleWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAccessibleWidget::self = ptr;
	DummyQAccessibleObject::setSelf(ptr);
}

bool DummyQAccessibleWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAccessibleObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAccessibleWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleWidget::event_map->bigin();
	if ((itr = DummyQAccessibleWidget::event_map->find(str)) == DummyQAccessibleWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQAccessibleObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessibleWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleWidget::slot_map->bigin();
	if ((itr = DummyQAccessibleWidget::slot_map->find(str)) == DummyQAccessibleWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQAccessibleObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQAccessibleWidget::connection(QObject *o)
{
	DummyQAccessibleObject::connection(o);
}

KQAccessibleWidget::KQAccessibleWidget(QWidget* w, QAccessibleWidget::Role role, const QString name) : QAccessibleWidget(w, role, name)
{
	self = NULL;
	dummy = new DummyQAccessibleWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QAccessibleWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleWidget *qp = RawPtr_to(KQAccessibleWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAccessibleWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleWidget *qp = RawPtr_to(KQAccessibleWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessibleWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAccessibleWidget *qp = (KQAccessibleWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAccessibleWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQAccessibleWidget *qp = (KQAccessibleWidget *)p->rawptr;
		(void)qp;
	}
}

static int QAccessibleWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAccessibleWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQAccessibleWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleWidget";
	cdef->free = QAccessibleWidget_free;
	cdef->reftrace = QAccessibleWidget_reftrace;
	cdef->compareTo = QAccessibleWidget_compareTo;
}


