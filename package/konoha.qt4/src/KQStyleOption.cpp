//QStyleOption QStyleOption.new(int version, int type);
KMETHOD QStyleOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int version = Int_to(int, sfp[1]);
	int type = Int_to(int, sfp[2]);
	KQStyleOption *ret_v = new KQStyleOption(version, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOption QStyleOption.new(QStyleOption other);
KMETHOD QStyleOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOption  other = *RawPtr_to(const QStyleOption *, sfp[1]);
	KQStyleOption *ret_v = new KQStyleOption(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QStyleOption.initFrom(QWidget widget);
KMETHOD QStyleOption_initFrom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOption *  qp = RawPtr_to(QStyleOption *, sfp[0]);
	if (qp != NULL) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		qp->initFrom(widget);
	}
	RETURNvoid_();
}


DummyQStyleOption::DummyQStyleOption()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOption::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOption::self = ptr;
}

bool DummyQStyleOption::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQStyleOption::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOption::event_map->bigin();
	if ((itr = DummyQStyleOption::event_map->find(str)) == DummyQStyleOption::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOption::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOption::slot_map->bigin();
	if ((itr = DummyQStyleOption::event_map->find(str)) == DummyQStyleOption::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOption::KQStyleOption(int version, int type) : QStyleOption(version, type)
{
	self = NULL;
}

KMETHOD QStyleOption_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOption *qp = RawPtr_to(KQStyleOption *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOption]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOption::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOption]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOption_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOption *qp = RawPtr_to(KQStyleOption *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOption]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOption::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOption]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOption_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOption *qp = (KQStyleOption *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOption_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOption *qp = (KQStyleOption *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOption_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOption(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOption";
	cdef->free = QStyleOption_free;
	cdef->reftrace = QStyleOption_reftrace;
	cdef->compareTo = QStyleOption_compareTo;
}

static knh_IntData_t QStyleOptionConstInt[] = {
	{"SO_Button", QStyleOption::SO_Button},
	{"SO_ComboBox", QStyleOption::SO_ComboBox},
	{"SO_Complex", QStyleOption::SO_Complex},
	{"SO_Default", QStyleOption::SO_Default},
	{"SO_DockWidget", QStyleOption::SO_DockWidget},
	{"SO_FocusRect", QStyleOption::SO_FocusRect},
	{"SO_Frame", QStyleOption::SO_Frame},
	{"SO_GraphicsItem", QStyleOption::SO_GraphicsItem},
	{"SO_GroupBox", QStyleOption::SO_GroupBox},
	{"SO_Header", QStyleOption::SO_Header},
	{"SO_MenuItem", QStyleOption::SO_MenuItem},
	{"SO_ProgressBar", QStyleOption::SO_ProgressBar},
	{"SO_RubberBand", QStyleOption::SO_RubberBand},
	{"SO_SizeGrip", QStyleOption::SO_SizeGrip},
	{"SO_Slider", QStyleOption::SO_Slider},
	{"SO_SpinBox", QStyleOption::SO_SpinBox},
	{"SO_Tab", QStyleOption::SO_Tab},
	{"SO_TabBarBase", QStyleOption::SO_TabBarBase},
	{"SO_TabWidgetFrame", QStyleOption::SO_TabWidgetFrame},
	{"SO_TitleBar", QStyleOption::SO_TitleBar},
	{"SO_ToolBar", QStyleOption::SO_ToolBar},
	{"SO_ToolBox", QStyleOption::SO_ToolBox},
	{"SO_ToolButton", QStyleOption::SO_ToolButton},
	{"SO_ViewItem", QStyleOption::SO_ViewItem},
	{"SO_CustomBase", QStyleOption::SO_CustomBase},
	{"SO_ComplexCustomBase", QStyleOption::SO_ComplexCustomBase},
	{"SO_Q3DockWindow", QStyleOption::SO_Q3DockWindow},
	{"SO_Q3ListView", QStyleOption::SO_Q3ListView},
	{"SO_Q3ListViewItem", QStyleOption::SO_Q3ListViewItem},
	{"Type", QStyleOption::Type},
	{"Version", QStyleOption::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOption(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionConstInt);
}

