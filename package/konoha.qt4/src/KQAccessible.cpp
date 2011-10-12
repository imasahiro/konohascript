//void QAccessible.installFactory(int factory);
KMETHOD QAccessible_installFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *  qp = RawPtr_to(QAccessible *, sfp[0]);
	if (qp != NULL) {
		QAccessible::InterfaceFactory  factory = *RawPtr_to(QAccessible::InterfaceFactory *, sfp[1]);
		qp->installFactory(factory);
	}
	RETURNvoid_();
}

//boolean QAccessible.isActive();
KMETHOD QAccessible_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *  qp = RawPtr_to(QAccessible *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QAccessibleInterface QAccessible.queryAccessibleInterface(QObject object);
KMETHOD QAccessible_queryAccessibleInterface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *  qp = RawPtr_to(QAccessible *, sfp[0]);
	if (qp != NULL) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		QAccessibleInterface* ret_v = qp->queryAccessibleInterface(object);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAccessibleInterface*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAccessible.removeFactory(int factory);
KMETHOD QAccessible_removeFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *  qp = RawPtr_to(QAccessible *, sfp[0]);
	if (qp != NULL) {
		QAccessible::InterfaceFactory  factory = *RawPtr_to(QAccessible::InterfaceFactory *, sfp[1]);
		qp->removeFactory(factory);
	}
	RETURNvoid_();
}

//void QAccessible.setRootObject(QObject object);
KMETHOD QAccessible_setRootObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *  qp = RawPtr_to(QAccessible *, sfp[0]);
	if (qp != NULL) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		qp->setRootObject(object);
	}
	RETURNvoid_();
}

//void QAccessible.updateAccessibility(QObject object, int child, int reason);
KMETHOD QAccessible_updateAccessibility(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessible *  qp = RawPtr_to(QAccessible *, sfp[0]);
	if (qp != NULL) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		int child = Int_to(int, sfp[2]);
		QAccessible::Event reason = Int_to(QAccessible::Event, sfp[3]);
		qp->updateAccessibility(object, child, reason);
	}
	RETURNvoid_();
}


DummyQAccessible::DummyQAccessible()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessible::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessible::slot_map->bigin();
	if ((itr = DummyQAccessible::event_map->find(str)) == DummyQAccessible::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAccessible::KQAccessible() : QAccessible()
{
	self = NULL;
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
		if (!qp->DummyQAccessible::addEvent(callback_func, str)) {
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
		if (!qp->DummyQAccessible::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessible]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessible_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAccessible *qp = (KQAccessible *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAccessible_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAccessible *qp = (KQAccessible *)p->rawptr;
		(void)qp;
	}
}

static int QAccessible_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQAccessible(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessible";
	cdef->free = QAccessible_free;
	cdef->reftrace = QAccessible_reftrace;
	cdef->compareTo = QAccessible_compareTo;
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

