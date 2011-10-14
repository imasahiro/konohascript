//QEvent QEvent.new(int type);
KMETHOD QEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent::Type type = Int_to(QEvent::Type, sfp[1]);
	KQEvent *ret_v = new KQEvent(type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

////void QEvent.accept();
KMETHOD QEvent_accept(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		qp->accept();
	}
	RETURNvoid_();
}

////void QEvent.ignore();
KMETHOD QEvent_ignore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		qp->ignore();
	}
	RETURNvoid_();
}

////boolean QEvent.isAccepted();
KMETHOD QEvent_isAccepted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isAccepted();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//////void QEvent.setAccepted(boolean accepted);
KMETHOD QEvent_setAccepted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		bool accepted = Boolean_to(bool, sfp[1]);
		qp->setAccepted(accepted);
	}
	RETURNvoid_();
}

//boolean QEvent.spontaneous();
KMETHOD QEvent_spontaneous(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->spontaneous();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QEvent.type();
KMETHOD QEvent_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		QEvent::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QEvent.registerEventType(int hint);
KMETHOD QEvent_registerEventType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent *  qp = RawPtr_to(QEvent *, sfp[0]);
	if (qp != NULL) {
		int hint = Int_to(int, sfp[1]);
		int ret_v = qp->registerEventType(hint);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQEvent::DummyQEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQEvent::self = ptr;
}

bool DummyQEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEvent::event_map->bigin();
	if ((itr = DummyQEvent::event_map->find(str)) == DummyQEvent::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEvent::slot_map->bigin();
	if ((itr = DummyQEvent::slot_map->find(str)) == DummyQEvent::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQEvent::connection(QObject *o)
{
	return;
}

KQEvent::KQEvent(QEvent::Type type) : QEvent(type)
{
	self = NULL;
	dummy = new DummyQEvent();
	dummy->connection((QObject*)this);
}

KMETHOD QEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEvent *qp = RawPtr_to(KQEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEvent *qp = RawPtr_to(KQEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQEvent *qp = (KQEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQEvent *qp = (KQEvent *)p->rawptr;
		(void)qp;
	}
}

static int QEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QEvent";
	cdef->free = QEvent_free;
	cdef->reftrace = QEvent_reftrace;
	cdef->compareTo = QEvent_compareTo;
}

static knh_IntData_t QEventConstInt[] = {
	{"None", QEvent::None},
	{"AccessibilityDescription", QEvent::AccessibilityDescription},
	{"AccessibilityHelp", QEvent::AccessibilityHelp},
	{"AccessibilityPrepare", QEvent::AccessibilityPrepare},
	{"ActionAdded", QEvent::ActionAdded},
	{"ActionChanged", QEvent::ActionChanged},
	{"ActionRemoved", QEvent::ActionRemoved},
	{"ActivationChange", QEvent::ActivationChange},
	{"ApplicationActivate", QEvent::ApplicationActivate},
	{"ApplicationActivated", QEvent::ApplicationActivated},
	{"ApplicationDeactivate", QEvent::ApplicationDeactivate},
	{"ApplicationFontChange", QEvent::ApplicationFontChange},
	{"ApplicationLayoutDirectionChange", QEvent::ApplicationLayoutDirectionChange},
	{"ApplicationPaletteChange", QEvent::ApplicationPaletteChange},
	{"ApplicationWindowIconChange", QEvent::ApplicationWindowIconChange},
	{"ChildAdded", QEvent::ChildAdded},
//	{"ChildInserted", QEvent::ChildInserted},
	{"ChildPolished", QEvent::ChildPolished},
	{"ChildRemoved", QEvent::ChildRemoved},
	{"Clipboard", QEvent::Clipboard},
	{"Close", QEvent::Close},
	{"CloseSoftwareInputPanel", QEvent::CloseSoftwareInputPanel},
	{"ContentsRectChange", QEvent::ContentsRectChange},
	{"ContextMenu", QEvent::ContextMenu},
	{"CursorChange", QEvent::CursorChange},
	{"DeferredDelete", QEvent::DeferredDelete},
	{"DragEnter", QEvent::DragEnter},
	{"DragLeave", QEvent::DragLeave},
	{"DragMove", QEvent::DragMove},
	{"Drop", QEvent::Drop},
	{"EnabledChange", QEvent::EnabledChange},
	{"Enter", QEvent::Enter},
//	{"EnterEditFocus", QEvent::EnterEditFocus},
	{"EnterWhatsThisMode", QEvent::EnterWhatsThisMode},
	{"FileOpen", QEvent::FileOpen},
	{"FocusIn", QEvent::FocusIn},
	{"FocusOut", QEvent::FocusOut},
	{"FontChange", QEvent::FontChange},
	{"GrabKeyboard", QEvent::GrabKeyboard},
	{"GrabMouse", QEvent::GrabMouse},
	{"GraphicsSceneContextMenu", QEvent::GraphicsSceneContextMenu},
	{"GraphicsSceneDragEnter", QEvent::GraphicsSceneDragEnter},
	{"GraphicsSceneDragLeave", QEvent::GraphicsSceneDragLeave},
	{"GraphicsSceneDragMove", QEvent::GraphicsSceneDragMove},
	{"GraphicsSceneDrop", QEvent::GraphicsSceneDrop},
	{"GraphicsSceneHelp", QEvent::GraphicsSceneHelp},
	{"GraphicsSceneHoverEnter", QEvent::GraphicsSceneHoverEnter},
	{"GraphicsSceneHoverLeave", QEvent::GraphicsSceneHoverLeave},
	{"GraphicsSceneHoverMove", QEvent::GraphicsSceneHoverMove},
	{"GraphicsSceneMouseDoubleClick", QEvent::GraphicsSceneMouseDoubleClick},
	{"GraphicsSceneMouseMove", QEvent::GraphicsSceneMouseMove},
	{"GraphicsSceneMousePress", QEvent::GraphicsSceneMousePress},
	{"GraphicsSceneMouseRelease", QEvent::GraphicsSceneMouseRelease},
	{"GraphicsSceneMove", QEvent::GraphicsSceneMove},
	{"GraphicsSceneResize", QEvent::GraphicsSceneResize},
	{"GraphicsSceneWheel", QEvent::GraphicsSceneWheel},
	{"Hide", QEvent::Hide},
	{"HideToParent", QEvent::HideToParent},
	{"HoverEnter", QEvent::HoverEnter},
	{"HoverLeave", QEvent::HoverLeave},
	{"HoverMove", QEvent::HoverMove},
	{"IconDrag", QEvent::IconDrag},
	{"IconTextChange", QEvent::IconTextChange},
	{"InputMethod", QEvent::InputMethod},
	{"KeyPress", QEvent::KeyPress},
	{"KeyRelease", QEvent::KeyRelease},
	{"LanguageChange", QEvent::LanguageChange},
	{"LayoutDirectionChange", QEvent::LayoutDirectionChange},
	{"LayoutRequest", QEvent::LayoutRequest},
	{"Leave", QEvent::Leave},
//	{"LeaveEditFocus", QEvent::LeaveEditFocus},
	{"LeaveWhatsThisMode", QEvent::LeaveWhatsThisMode},
	{"LocaleChange", QEvent::LocaleChange},
	{"NonClientAreaMouseButtonDblClick", QEvent::NonClientAreaMouseButtonDblClick},
	{"NonClientAreaMouseButtonPress", QEvent::NonClientAreaMouseButtonPress},
	{"NonClientAreaMouseButtonRelease", QEvent::NonClientAreaMouseButtonRelease},
	{"NonClientAreaMouseMove", QEvent::NonClientAreaMouseMove},
	{"MacSizeChange", QEvent::MacSizeChange},
	{"MenubarUpdated", QEvent::MenubarUpdated},
	{"MetaCall", QEvent::MetaCall},
	{"ModifiedChange", QEvent::ModifiedChange},
	{"MouseButtonDblClick", QEvent::MouseButtonDblClick},
	{"MouseButtonPress", QEvent::MouseButtonPress},
	{"MouseButtonRelease", QEvent::MouseButtonRelease},
	{"MouseMove", QEvent::MouseMove},
	{"MouseTrackingChange", QEvent::MouseTrackingChange},
	{"Move", QEvent::Move},
	{"Paint", QEvent::Paint},
	{"PaletteChange", QEvent::PaletteChange},
	{"ParentAboutToChange", QEvent::ParentAboutToChange},
	{"ParentChange", QEvent::ParentChange},
	{"Polish", QEvent::Polish},
	{"PolishRequest", QEvent::PolishRequest},
	{"QueryWhatsThis", QEvent::QueryWhatsThis},
	{"RequestSoftwareInputPanel", QEvent::RequestSoftwareInputPanel},
	{"Resize", QEvent::Resize},
	{"Shortcut", QEvent::Shortcut},
	{"ShortcutOverride", QEvent::ShortcutOverride},
	{"Show", QEvent::Show},
	{"ShowToParent", QEvent::ShowToParent},
	{"SockAct", QEvent::SockAct},
	{"StateMachineSignal", QEvent::StateMachineSignal},
	{"StateMachineWrapped", QEvent::StateMachineWrapped},
	{"StatusTip", QEvent::StatusTip},
	{"StyleChange", QEvent::StyleChange},
	{"TabletMove", QEvent::TabletMove},
	{"TabletPress", QEvent::TabletPress},
	{"TabletRelease", QEvent::TabletRelease},
	{"OkRequest", QEvent::OkRequest},
	{"TabletEnterProximity", QEvent::TabletEnterProximity},
	{"TabletLeaveProximity", QEvent::TabletLeaveProximity},
	{"Timer", QEvent::Timer},
	{"ToolBarChange", QEvent::ToolBarChange},
	{"ToolTip", QEvent::ToolTip},
	{"ToolTipChange", QEvent::ToolTipChange},
	{"UngrabKeyboard", QEvent::UngrabKeyboard},
	{"UngrabMouse", QEvent::UngrabMouse},
	{"UpdateLater", QEvent::UpdateLater},
	{"UpdateRequest", QEvent::UpdateRequest},
	{"WhatsThis", QEvent::WhatsThis},
	{"WhatsThisClicked", QEvent::WhatsThisClicked},
	{"Wheel", QEvent::Wheel},
	{"WinEventAct", QEvent::WinEventAct},
	{"WindowActivate", QEvent::WindowActivate},
	{"WindowBlocked", QEvent::WindowBlocked},
	{"WindowDeactivate", QEvent::WindowDeactivate},
	{"WindowIconChange", QEvent::WindowIconChange},
	{"WindowStateChange", QEvent::WindowStateChange},
	{"WindowTitleChange", QEvent::WindowTitleChange},
	{"WindowUnblocked", QEvent::WindowUnblocked},
	{"ZOrderChange", QEvent::ZOrderChange},
	{"KeyboardLayoutChange", QEvent::KeyboardLayoutChange},
	{"DynamicPropertyChange", QEvent::DynamicPropertyChange},
	{"TouchBegin", QEvent::TouchBegin},
	{"TouchUpdate", QEvent::TouchUpdate},
	{"TouchEnd", QEvent::TouchEnd},
	{"WinIdChange", QEvent::WinIdChange},
	{"Gesture", QEvent::Gesture},
	{"GestureOverride", QEvent::GestureOverride},
	{"User", QEvent::User},
	{"MaxUser", QEvent::MaxUser},
	{NULL, 0}
};

DEFAPI(void) constQEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QEventConstInt);
}

