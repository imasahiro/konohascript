//boolean QAccessible.isActive();
KMETHOD QAccessible_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QAccessible::isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QAccessibleInterface QAccessible.queryAccessibleInterface(QObject object);
KMETHOD QAccessible_queryAccessibleInterface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		QAccessibleInterface* ret_v = QAccessible::queryAccessibleInterface(object);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAccessibleInterface*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAccessible.setRootObject(QObject object);
KMETHOD QAccessible_setRootObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		QAccessible::setRootObject(object);
	}
	RETURNvoid_();
}

//void QAccessible.updateAccessibility(QObject object, int child, int reason);
KMETHOD QAccessible_updateAccessibility(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		int child = Int_to(int, sfp[2]);
		QAccessible::Event reason = Int_to(QAccessible::Event, sfp[3]);
		QAccessible::updateAccessibility(object, child, reason);
	}
	RETURNvoid_();
}

//Array<String> QAccessible.parents();
KMETHOD QAccessible_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *qp = RawPtr_to(QAccessible*, sfp[0]);
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

DummyQAccessible::DummyQAccessible()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQAccessible::~DummyQAccessible()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAccessible::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAccessible::self = ptr;
}

bool DummyQAccessible::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQAccessible::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessible::event_map->bigin();
	if ((itr = DummyQAccessible::event_map->find(str)) == DummyQAccessible::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessible::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessible::slot_map->bigin();
	if ((itr = DummyQAccessible::slot_map->find(str)) == DummyQAccessible::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAccessible::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAccessible::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQAccessible::connection(QObject *o)
{
	QAccessible *p = dynamic_cast<QAccessible*>(o);
	if (p != NULL) {
	}
}

KQAccessible::~KQAccessible()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAccessible_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessible *qp = RawPtr_to(KQAccessible *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessible]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessible]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAccessible_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessible *qp = RawPtr_to(KQAccessible *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessible]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessible]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessible_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAccessible *qp = (KQAccessible *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAccessible*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAccessible_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAccessible *qp = (KQAccessible *)p->rawptr;
		KQAccessible *qp = static_cast<KQAccessible*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAccessible_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAccessible::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QAccessibleConstInt[] = {
	{"DefaultAction", QAccessible::DefaultAction},
	{"Press", QAccessible::Press},
	{"SetFocus", QAccessible::SetFocus},
	{"Increase", QAccessible::Increase},
	{"Decrease", QAccessible::Decrease},
	{"Accept", QAccessible::Accept},
	{"Cancel", QAccessible::Cancel},
	{"Select", QAccessible::Select},
	{"ClearSelection", QAccessible::ClearSelection},
	{"RemoveSelection", QAccessible::RemoveSelection},
	{"ExtendSelection", QAccessible::ExtendSelection},
	{"AddToSelection", QAccessible::AddToSelection},
	{"FirstStandardAction", QAccessible::FirstStandardAction},
	{"LastStandardAction", QAccessible::LastStandardAction},
	{"AcceleratorChanged", QAccessible::AcceleratorChanged},
	{"Alert", QAccessible::Alert},
	{"ContextHelpEnd", QAccessible::ContextHelpEnd},
	{"ContextHelpStart", QAccessible::ContextHelpStart},
	{"DefaultActionChanged", QAccessible::DefaultActionChanged},
	{"DescriptionChanged", QAccessible::DescriptionChanged},
	{"DialogEnd", QAccessible::DialogEnd},
	{"DialogStart", QAccessible::DialogStart},
	{"DragDropEnd", QAccessible::DragDropEnd},
	{"DragDropStart", QAccessible::DragDropStart},
	{"Focus", QAccessible::Focus},
	{"ForegroundChanged", QAccessible::ForegroundChanged},
	{"HelpChanged", QAccessible::HelpChanged},
	{"LocationChanged", QAccessible::LocationChanged},
	{"MenuCommand", QAccessible::MenuCommand},
	{"MenuEnd", QAccessible::MenuEnd},
	{"MenuStart", QAccessible::MenuStart},
	{"NameChanged", QAccessible::NameChanged},
	{"ObjectCreated", QAccessible::ObjectCreated},
	{"ObjectDestroyed", QAccessible::ObjectDestroyed},
	{"ObjectHide", QAccessible::ObjectHide},
	{"ObjectReorder", QAccessible::ObjectReorder},
	{"ObjectShow", QAccessible::ObjectShow},
	{"ParentChanged", QAccessible::ParentChanged},
	{"PopupMenuEnd", QAccessible::PopupMenuEnd},
	{"PopupMenuStart", QAccessible::PopupMenuStart},
	{"ScrollingEnd", QAccessible::ScrollingEnd},
	{"ScrollingStart", QAccessible::ScrollingStart},
	{"Selection", QAccessible::Selection},
	{"SelectionAdd", QAccessible::SelectionAdd},
	{"SelectionRemove", QAccessible::SelectionRemove},
	{"SelectionWithin", QAccessible::SelectionWithin},
	{"SoundPlayed", QAccessible::SoundPlayed},
	{"StateChanged", QAccessible::StateChanged},
	{"ValueChanged", QAccessible::ValueChanged},
	{"ListSupportedMethods", QAccessible::ListSupportedMethods},
	{"SetCursorPosition", QAccessible::SetCursorPosition},
	{"GetCursorPosition", QAccessible::GetCursorPosition},
	{"Unrelated", QAccessible::Unrelated},
	{"Self", QAccessible::Self},
	{"Ancestor", QAccessible::Ancestor},
	{"Child", QAccessible::Child},
	{"Descendent", QAccessible::Descendent},
	{"Sibling", QAccessible::Sibling},
	{"Up", QAccessible::Up},
	{"Down", QAccessible::Down},
	{"Left", QAccessible::Left},
	{"Right", QAccessible::Right},
	{"Covers", QAccessible::Covers},
	{"Covered", QAccessible::Covered},
	{"FocusChild", QAccessible::FocusChild},
	{"Label", QAccessible::Label},
	{"Labelled", QAccessible::Labelled},
	{"Controller", QAccessible::Controller},
	{"Controlled", QAccessible::Controlled},
	{"AlertMessage", QAccessible::AlertMessage},
	{"Animation", QAccessible::Animation},
	{"Application", QAccessible::Application},
	{"Assistant", QAccessible::Assistant},
	{"Border", QAccessible::Border},
	{"ButtonDropDown", QAccessible::ButtonDropDown},
	{"ButtonDropGrid", QAccessible::ButtonDropGrid},
	{"ButtonMenu", QAccessible::ButtonMenu},
	{"Canvas", QAccessible::Canvas},
	{"Caret", QAccessible::Caret},
	{"Cell", QAccessible::Cell},
	{"Chart", QAccessible::Chart},
	{"CheckBox", QAccessible::CheckBox},
	{"Client", QAccessible::Client},
	{"Clock", QAccessible::Clock},
	{"Column", QAccessible::Column},
	{"ColumnHeader", QAccessible::ColumnHeader},
	{"ComboBox", QAccessible::ComboBox},
	{"Cursor", QAccessible::Cursor},
	{"Dial", QAccessible::Dial},
	{"Dialog", QAccessible::Dialog},
	{"Document", QAccessible::Document},
	{"EditableText", QAccessible::EditableText},
	{"Equation", QAccessible::Equation},
	{"Graphic", QAccessible::Graphic},
	{"Grip", QAccessible::Grip},
	{"Grouping", QAccessible::Grouping},
	{"HelpBalloon", QAccessible::HelpBalloon},
	{"HotkeyField", QAccessible::HotkeyField},
	{"Indicator", QAccessible::Indicator},
	{"LayeredPane", QAccessible::LayeredPane},
	{"Link", QAccessible::Link},
	{"List", QAccessible::List},
	{"ListItem", QAccessible::ListItem},
	{"MenuBar", QAccessible::MenuBar},
	{"MenuItem", QAccessible::MenuItem},
	{"NoRole", QAccessible::NoRole},
	{"PageTab", QAccessible::PageTab},
	{"PageTabList", QAccessible::PageTabList},
	{"Pane", QAccessible::Pane},
	{"PopupMenu", QAccessible::PopupMenu},
	{"ProgressBar", QAccessible::ProgressBar},
	{"PropertyPage", QAccessible::PropertyPage},
	{"PushButton", QAccessible::PushButton},
	{"RadioButton", QAccessible::RadioButton},
	{"Row", QAccessible::Row},
	{"RowHeader", QAccessible::RowHeader},
	{"ScrollBar", QAccessible::ScrollBar},
	{"Separator", QAccessible::Separator},
	{"Slider", QAccessible::Slider},
	{"Sound", QAccessible::Sound},
	{"SpinBox", QAccessible::SpinBox},
	{"Splitter", QAccessible::Splitter},
	{"StaticText", QAccessible::StaticText},
	{"StatusBar", QAccessible::StatusBar},
	{"Table", QAccessible::Table},
	{"TitleBar", QAccessible::TitleBar},
	{"ToolBar", QAccessible::ToolBar},
	{"ToolTip", QAccessible::ToolTip},
	{"Tree", QAccessible::Tree},
	{"TreeItem", QAccessible::TreeItem},
	{"UserRole", QAccessible::UserRole},
	{"Whitespace", QAccessible::Whitespace},
	{"Window", QAccessible::Window},
	{"Animated", QAccessible::Animated},
	{"Busy", QAccessible::Busy},
	{"Checked", QAccessible::Checked},
	{"Collapsed", QAccessible::Collapsed},
	{"DefaultButton", QAccessible::DefaultButton},
	{"Expanded", QAccessible::Expanded},
	{"ExtSelectable", QAccessible::ExtSelectable},
	{"Focusable", QAccessible::Focusable},
	{"Focused", QAccessible::Focused},
	{"HasPopup", QAccessible::HasPopup},
	{"HotTracked", QAccessible::HotTracked},
	{"Invisible", QAccessible::Invisible},
	{"Linked", QAccessible::Linked},
	{"Marqueed", QAccessible::Marqueed},
	{"Mixed", QAccessible::Mixed},
	{"Modal", QAccessible::Modal},
	{"Movable", QAccessible::Movable},
	{"MultiSelectable", QAccessible::MultiSelectable},
	{"Normal", QAccessible::Normal},
	{"Offscreen", QAccessible::Offscreen},
	{"Pressed", QAccessible::Pressed},
	{"Protected", QAccessible::Protected},
	{"ReadOnly", QAccessible::ReadOnly},
	{"Selectable", QAccessible::Selectable},
	{"Selected", QAccessible::Selected},
	{"SelfVoicing", QAccessible::SelfVoicing},
	{"Sizeable", QAccessible::Sizeable},
	{"Traversed", QAccessible::Traversed},
	{"Unavailable", QAccessible::Unavailable},
	{"Name", QAccessible::Name},
	{"Description", QAccessible::Description},
	{"Value", QAccessible::Value},
	{"Help", QAccessible::Help},
	{"Accelerator", QAccessible::Accelerator},
	{"UserText", QAccessible::UserText},
	{NULL, 0}
};

DEFAPI(void) constQAccessible(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAccessibleConstInt);
}


DEFAPI(void) defQAccessible(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessible";
	cdef->free = QAccessible_free;
	cdef->reftrace = QAccessible_reftrace;
	cdef->compareTo = QAccessible_compareTo;
}

//## QAccessibleRelation QAccessibleRelation.new(int value);
KMETHOD QAccessibleRelation_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::RelationFlag i = Int_to(QAccessible::RelationFlag, sfp[1]);
	QAccessible::Relation *ret_v = new QAccessible::Relation(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QAccessibleRelation QAccessibleRelation.and(int mask);
KMETHOD QAccessibleRelation_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QAccessible::Relation ret = ((*qp) & i);
		QAccessible::Relation *ret_ = new QAccessible::Relation(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleRelation QAccessibleRelation.iand(QAccessible::QAccessibleRelation other);
KMETHOD QAccessibleRelation_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation*, sfp[0]);
	if (qp != NULL) {
		QAccessible::Relation *other = RawPtr_to(QAccessible::Relation *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleRelation QAccessibleRelation.or(QAccessibleRelation f);
KMETHOD QAccessibleRelation_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation*, sfp[0]);
	if (qp != NULL) {
		QAccessible::Relation *f = RawPtr_to(QAccessible::Relation*, sfp[1]);
		QAccessible::Relation ret = ((*qp) | (*f));
		QAccessible::Relation *ret_ = new QAccessible::Relation(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleRelation QAccessibleRelation.ior(QAccessible::QAccessibleRelation other);
KMETHOD QAccessibleRelation_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation*, sfp[0]);
	if (qp != NULL) {
		QAccessible::Relation *other = RawPtr_to(QAccessible::Relation *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleRelation QAccessibleRelation.xor(QAccessibleRelation f);
KMETHOD QAccessibleRelation_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation*, sfp[0]);
	if (qp != NULL) {
		QAccessible::Relation *f = RawPtr_to(QAccessible::Relation*, sfp[1]);
		QAccessible::Relation ret = ((*qp) ^ (*f));
		QAccessible::Relation *ret_ = new QAccessible::Relation(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleRelation QAccessibleRelation.ixor(QAccessible::QAccessibleRelation other);
KMETHOD QAccessibleRelation_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation*, sfp[0]);
	if (qp != NULL) {
		QAccessible::Relation *other = RawPtr_to(QAccessible::Relation *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QAccessibleRelation.testFlag(int flag);
KMETHOD QAccessibleRelation_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation *, sfp[0]);
	if (qp != NULL) {
		QAccessible::RelationFlag flag = Int_to(QAccessible::RelationFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QAccessibleRelation.value();
KMETHOD QAccessibleRelation_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::Relation *qp = RawPtr_to(QAccessible::Relation *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QAccessibleRelation_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QAccessible::Relation *qp = (QAccessible::Relation *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QAccessibleRelation_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QAccessible::Relation *qp = (QAccessible::Relation *)p->rawptr;
		(void)qp;
	}
}

static int QAccessibleRelation_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QAccessible::Relation*)p1->rawptr);
//		int v2 = int(*(QAccessible::Relation*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QAccessible::Relation v1 = *(QAccessible::Relation*)p1->rawptr;
		QAccessible::Relation v2 = *(QAccessible::Relation*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQAccessibleRelation(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleRelation";
	cdef->free = QAccessibleRelation_free;
	cdef->reftrace = QAccessibleRelation_reftrace;
	cdef->compareTo = QAccessibleRelation_compareTo;
}
//## QAccessibleState QAccessibleState.new(int value);
KMETHOD QAccessibleState_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::StateFlag i = Int_to(QAccessible::StateFlag, sfp[1]);
	QAccessible::State *ret_v = new QAccessible::State(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QAccessibleState QAccessibleState.and(int mask);
KMETHOD QAccessibleState_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QAccessible::State ret = ((*qp) & i);
		QAccessible::State *ret_ = new QAccessible::State(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleState QAccessibleState.iand(QAccessible::QAccessibleState other);
KMETHOD QAccessibleState_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State*, sfp[0]);
	if (qp != NULL) {
		QAccessible::State *other = RawPtr_to(QAccessible::State *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleState QAccessibleState.or(QAccessibleState f);
KMETHOD QAccessibleState_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State*, sfp[0]);
	if (qp != NULL) {
		QAccessible::State *f = RawPtr_to(QAccessible::State*, sfp[1]);
		QAccessible::State ret = ((*qp) | (*f));
		QAccessible::State *ret_ = new QAccessible::State(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleState QAccessibleState.ior(QAccessible::QAccessibleState other);
KMETHOD QAccessibleState_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State*, sfp[0]);
	if (qp != NULL) {
		QAccessible::State *other = RawPtr_to(QAccessible::State *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleState QAccessibleState.xor(QAccessibleState f);
KMETHOD QAccessibleState_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State*, sfp[0]);
	if (qp != NULL) {
		QAccessible::State *f = RawPtr_to(QAccessible::State*, sfp[1]);
		QAccessible::State ret = ((*qp) ^ (*f));
		QAccessible::State *ret_ = new QAccessible::State(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAccessibleState QAccessibleState.ixor(QAccessible::QAccessibleState other);
KMETHOD QAccessibleState_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State*, sfp[0]);
	if (qp != NULL) {
		QAccessible::State *other = RawPtr_to(QAccessible::State *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QAccessibleState.testFlag(int flag);
KMETHOD QAccessibleState_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State *, sfp[0]);
	if (qp != NULL) {
		QAccessible::StateFlag flag = Int_to(QAccessible::StateFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QAccessibleState.value();
KMETHOD QAccessibleState_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAccessible::State *qp = RawPtr_to(QAccessible::State *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QAccessibleState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QAccessible::State *qp = (QAccessible::State *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QAccessibleState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QAccessible::State *qp = (QAccessible::State *)p->rawptr;
		(void)qp;
	}
}

static int QAccessibleState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QAccessible::State*)p1->rawptr);
//		int v2 = int(*(QAccessible::State*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QAccessible::State v1 = *(QAccessible::State*)p1->rawptr;
		QAccessible::State v2 = *(QAccessible::State*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQAccessibleState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleState";
	cdef->free = QAccessibleState_free;
	cdef->reftrace = QAccessibleState_reftrace;
	cdef->compareTo = QAccessibleState_compareTo;
}

