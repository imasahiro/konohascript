#include <physics.hpp>
#include <qt4_common.hpp>

PKGConnector::PKGConnector(){}
void PKGConnector::emitDragBeginSignal(QGraphicsSceneMouseEvent *event)
{
	emit dragBeginSignal(event);
}

void PKGConnector::emitDragMoveSignal(QGraphicsSceneMouseEvent *event)
{
	emit dragMoveSignal(event);
}

void PKGConnector::emitDragEndSignal(QGraphicsSceneMouseEvent *event)
{
	emit dragEndSignal(event);
}

using namespace std;

DummyQGraphicsItem::DummyQGraphicsItem()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	density = 0.0f;
	restitution = 0.0f;
	friction = 0.0f;
	isStatic = true;
	draggable = false;
	body = NULL;
	pkgconnector = new PKGConnector();

	contextMenuEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneContextMenuEvent);
	dragEnterEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneDragDropEvent);
	dragLeaveEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneDragDropEvent);
	dragMoveEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneDragDropEvent);
	dropEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneDragDropEvent);
	focusInEventPtr = new_empty_QRawPtr(lctx, QFocusEvent);
	focusOutEventPtr = new_empty_QRawPtr(lctx, QFocusEvent);
	hoverEnterEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneHoverEvent);
	hoverLeaveEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneHoverEvent);
	hoverMoveEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneHoverEvent);
	inputMethodEventPtr = new_empty_QRawPtr(lctx, QInputMethodEvent);
	keyPressEventPtr = new_empty_QRawPtr(lctx, QKeyEvent);
	keyReleaseEventPtr = new_empty_QRawPtr(lctx, QKeyEvent);
	mouseDoubleClickEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneMouseEvent);
	mouseMoveEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneMouseEvent);
	mousePressEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneMouseEvent);
	mouseReleaseEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneMouseEvent);
	sceneEventPtr = new_empty_QRawPtr(lctx, QEvent);
	wheelEventPtr = new_empty_QRawPtr(lctx, QGraphicsSceneWheelEvent);
	context_menu_event_func = NULL;
	drag_enter_event_func = NULL;
	drag_leave_event_func = NULL;
	drag_move_event_func = NULL;
	drop_event_func = NULL;
	focus_in_event_func = NULL;
	focus_out_event_func = NULL;
	hover_enter_event_func = NULL;
	hover_leave_event_func = NULL;
	hover_move_event_func = NULL;
	input_method_event_func = NULL;
	key_press_event_func = NULL;
	key_release_event_func = NULL;
	mouse_double_click_event_func = NULL;
	mouse_move_event_func = NULL;
	mouse_press_event_func = NULL;
	mouse_release_event_func = NULL;
	scene_event_func = NULL;
	wheel_event_func = NULL;
	paint_func = NULL;
	event_map = new map<string, kFunc *>();
	slot_map = new map<string, kFunc *>();
	event_map->insert(map<string, kFunc *>::value_type("context-menu-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("drag-enter-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("drag-leave-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("drag-move-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("drop-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("focus-in-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("focus-out-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("hover-enter-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("hover-leave-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("hover-move-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("input-method-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("key-press-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("key-release-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("mouse-double-click-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("mouse-move-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("mouse-press-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("mouse-release-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("scene-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("wheel-event", NULL));
	event_map->insert(map<string, kFunc *>::value_type("paint", NULL));
}
DummyQGraphicsItem::~DummyQGraphicsItem()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsItem::setSelf(kRawPtr *ptr)
{
	DummyQGraphicsItem::self = ptr;
}

bool DummyQGraphicsItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	case QEvent::GraphicsSceneContextMenu:
		ret = contextMenuEventDummy(dynamic_cast<QGraphicsSceneContextMenuEvent*>(event));
		break;
	case QEvent::GraphicsSceneDragEnter:
		ret = dragEnterEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::GraphicsSceneDragLeave:
		ret = dragLeaveEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::GraphicsSceneDragMove:
		ret = dragMoveEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::GraphicsSceneDrop:
		ret = dropEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::FocusIn:
		ret = focusInEventDummy(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::FocusOut:
		ret = focusOutEventDummy(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::GraphicsSceneHoverEnter:
		ret = hoverEnterEventDummy(dynamic_cast<QGraphicsSceneHoverEvent*>(event));
		break;
	case QEvent::GraphicsSceneHoverLeave:
		ret = hoverLeaveEventDummy(dynamic_cast<QGraphicsSceneHoverEvent*>(event));
		break;
	case QEvent::GraphicsSceneHoverMove:
		ret = hoverMoveEventDummy(dynamic_cast<QGraphicsSceneHoverEvent*>(event));
		break;
	case QEvent::InputMethod:
		ret = inputMethodEventDummy(dynamic_cast<QInputMethodEvent*>(event));
		break;
	case QEvent::KeyPress:
		ret = keyPressEventDummy(dynamic_cast<QKeyEvent*>(event));
		break;
	case QEvent::KeyRelease:
		ret = keyReleaseEventDummy(dynamic_cast<QKeyEvent*>(event));
		break;
	case QEvent::GraphicsSceneMouseDoubleClick:
		ret = mouseDoubleClickEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneMouseMove:
		ret = mouseMoveEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneMousePress:
		ret = mousePressEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneMouseRelease:
		ret = mouseReleaseEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
		ret = sceneEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::GraphicsSceneWheel:
		ret = wheelEventDummy(dynamic_cast<QGraphicsSceneWheelEvent*>(event));
		break;
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGraphicsItem::contextMenuEventDummy(QGraphicsSceneContextMenuEvent* event)
{
	if (context_menu_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		contextMenuEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(contextMenuEventPtr)));
		knh_Func_invoke(lctx, context_menu_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::dragEnterEventDummy(QGraphicsSceneDragDropEvent* event)
{
	if (drag_enter_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		dragEnterEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(dragEnterEventPtr)));
		knh_Func_invoke(lctx, drag_enter_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::dragLeaveEventDummy(QGraphicsSceneDragDropEvent* event)
{
	if (drag_leave_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		dragLeaveEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(dragLeaveEventPtr)));
		knh_Func_invoke(lctx, drag_leave_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::dragMoveEventDummy(QGraphicsSceneDragDropEvent* event)
{
	if (drag_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		dragMoveEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(dragMoveEventPtr)));
		knh_Func_invoke(lctx, drag_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::dropEventDummy(QGraphicsSceneDragDropEvent* event)
{
	if (drop_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		dropEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(dropEventPtr)));
		knh_Func_invoke(lctx, drop_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::focusInEventDummy(QFocusEvent* event)
{
	if (focus_in_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		focusInEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(focusInEventPtr)));
		knh_Func_invoke(lctx, focus_in_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::focusOutEventDummy(QFocusEvent* event)
{
	if (focus_out_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		focusOutEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(focusOutEventPtr)));
		knh_Func_invoke(lctx, focus_out_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::hoverEnterEventDummy(QGraphicsSceneHoverEvent* event)
{
	if (hover_enter_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		hoverEnterEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(hoverEnterEventPtr)));
		knh_Func_invoke(lctx, hover_enter_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::hoverLeaveEventDummy(QGraphicsSceneHoverEvent* event)
{
	if (hover_leave_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		hoverLeaveEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(hoverLeaveEventPtr)));
		knh_Func_invoke(lctx, hover_leave_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::hoverMoveEventDummy(QGraphicsSceneHoverEvent* event)
{
	if (hover_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		hoverMoveEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(hoverMoveEventPtr)));
		knh_Func_invoke(lctx, hover_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::inputMethodEventDummy(QInputMethodEvent* event)
{
	if (input_method_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		inputMethodEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(inputMethodEventPtr)));
		knh_Func_invoke(lctx, input_method_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::keyPressEventDummy(QKeyEvent* event)
{
	if (key_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		keyPressEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(keyPressEventPtr)));
		knh_Func_invoke(lctx, key_press_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::keyReleaseEventDummy(QKeyEvent* event)
{
	if (key_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		keyReleaseEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(keyReleaseEventPtr)));
		knh_Func_invoke(lctx, key_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mouseDoubleClickEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (mouse_double_click_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		mouseDoubleClickEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(mouseDoubleClickEventPtr)));
		knh_Func_invoke(lctx, mouse_double_click_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mouseMoveEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (draggable) pkgconnector->emitDragMoveSignal(event);
	if (mouse_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		mouseMoveEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(mouseMoveEventPtr)));
		knh_Func_invoke(lctx, mouse_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mousePressEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (draggable) pkgconnector->emitDragBeginSignal(event);
	if (mouse_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		mousePressEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(mousePressEventPtr)));
		knh_Func_invoke(lctx, mouse_press_event_func, lsfp, 2);
		return true;
	}
	return true;//false;
}

bool DummyQGraphicsItem::mouseReleaseEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (draggable) pkgconnector->emitDragEndSignal(event);
	if (mouse_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		mouseReleaseEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(mouseReleaseEventPtr)));
		knh_Func_invoke(lctx, mouse_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::sceneEventDummy(QEvent* event)
{
	if (scene_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		sceneEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(sceneEventPtr)));
		knh_Func_invoke(lctx, scene_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::wheelEventDummy(QGraphicsSceneWheelEvent* event)
{
	if (wheel_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		wheelEventPtr->rawptr = event;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, (UPCAST(wheelEventPtr)));
		knh_Func_invoke(lctx, wheel_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::addEvent(kFunc *callback_func, string str)
{
	std::map<string, kFunc*>::iterator itr;// = DummyQGraphicsItem::event_map->bigin();
	if ((itr = DummyQGraphicsItem::event_map->find(str)) == DummyQGraphicsItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		context_menu_event_func = (*event_map)["context-menu-event"];
		drag_enter_event_func = (*event_map)["drag-enter-event"];
		drag_leave_event_func = (*event_map)["drag-leave-event"];
		drag_move_event_func = (*event_map)["drag-move-event"];
		drop_event_func = (*event_map)["drop-event"];
		focus_in_event_func = (*event_map)["focus-in-event"];
		focus_out_event_func = (*event_map)["focus-out-event"];
		hover_enter_event_func = (*event_map)["hover-enter-event"];
		hover_leave_event_func = (*event_map)["hover-leave-event"];
		hover_move_event_func = (*event_map)["hover-move-event"];
		input_method_event_func = (*event_map)["input-method-event"];
		key_press_event_func = (*event_map)["key-press-event"];
		key_release_event_func = (*event_map)["key-release-event"];
		mouse_double_click_event_func = (*event_map)["mouse-double-click-event"];
		mouse_move_event_func = (*event_map)["mouse-move-event"];
		mouse_press_event_func = (*event_map)["mouse-press-event"];
		mouse_release_event_func = (*event_map)["mouse-release-event"];
		scene_event_func = (*event_map)["scene-event"];
		wheel_event_func = (*event_map)["wheel-event"];
		paint_func = (*event_map)["paint"];
		return true;
	}
}


bool DummyQGraphicsItem::signalConnect(kFunc *callback_func, string str)
{
	std::map<string, kFunc*>::iterator itr;// = DummyQGraphicsItem::slot_map->bigin();
	if ((itr = DummyQGraphicsItem::slot_map->find(str)) == DummyQGraphicsItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

kObject** DummyQGraphicsItem::reftrace(CTX ctx, kRawPtr *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsItem::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 39;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, context_menu_event_func);
	KNH_ADDNNREF(ctx, drag_enter_event_func);
	KNH_ADDNNREF(ctx, drag_leave_event_func);
	KNH_ADDNNREF(ctx, drag_move_event_func);
	KNH_ADDNNREF(ctx, drop_event_func);
	KNH_ADDNNREF(ctx, focus_in_event_func);
	KNH_ADDNNREF(ctx, focus_out_event_func);
	KNH_ADDNNREF(ctx, hover_enter_event_func);
	KNH_ADDNNREF(ctx, hover_leave_event_func);
	KNH_ADDNNREF(ctx, hover_move_event_func);
	KNH_ADDNNREF(ctx, input_method_event_func);
	KNH_ADDNNREF(ctx, key_press_event_func);
	KNH_ADDNNREF(ctx, key_release_event_func);
	KNH_ADDNNREF(ctx, mouse_double_click_event_func);
	KNH_ADDNNREF(ctx, mouse_move_event_func);
	KNH_ADDNNREF(ctx, mouse_press_event_func);
	KNH_ADDNNREF(ctx, mouse_release_event_func);
	KNH_ADDNNREF(ctx, scene_event_func);
	KNH_ADDNNREF(ctx, wheel_event_func);
	KNH_ADDNNREF(ctx, paint_func);
	KNH_ADDNNREF(ctx, contextMenuEventPtr);
	KNH_ADDNNREF(ctx, dragEnterEventPtr);
	KNH_ADDNNREF(ctx, dragLeaveEventPtr);
	KNH_ADDNNREF(ctx, dragMoveEventPtr);
	KNH_ADDNNREF(ctx, dropEventPtr);
	KNH_ADDNNREF(ctx, focusInEventPtr);
	KNH_ADDNNREF(ctx, focusOutEventPtr);
	KNH_ADDNNREF(ctx, hoverEnterEventPtr);
	KNH_ADDNNREF(ctx, hoverLeaveEventPtr);
	KNH_ADDNNREF(ctx, hoverMoveEventPtr);
	KNH_ADDNNREF(ctx, inputMethodEventPtr);
	KNH_ADDNNREF(ctx, keyPressEventPtr);
	KNH_ADDNNREF(ctx, keyReleaseEventPtr);
	KNH_ADDNNREF(ctx, mouseDoubleClickEventPtr);
	KNH_ADDNNREF(ctx, mouseMoveEventPtr);
	KNH_ADDNNREF(ctx, mousePressEventPtr);
	KNH_ADDNNREF(ctx, mouseReleaseEventPtr);
	KNH_ADDNNREF(ctx, sceneEventPtr);
	KNH_ADDNNREF(ctx, wheelEventPtr);

	KNH_SIZEREF(ctx);


	return tail_;
}

void DummyQGraphicsItem::connection(QObject *o)
{
	QGraphicsItem *p = dynamic_cast<QGraphicsItem*>(o);
	if (p != NULL) {
	}
}

KQGraphicsItem::KQGraphicsItem(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsItem();
}

KQGraphicsItem::~KQGraphicsItem()
{
	delete dummy;
	dummy = NULL;
}

void KQGraphicsItem::setSelf(kRawPtr *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsItem::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsItem::sceneEvent(event);
		return false;
	}
	//QGraphicsItem::sceneEvent(event);
	return true;
}

void KQGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (dummy->paint_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		kRawPtr *p1 = new_QRawPtr(lctx, QPainter, painter);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		kRawPtr *p2 = new_QRawPtr(lctx, QStyleOptionGraphicsItem, option);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		kRawPtr *p3 = new_QRawPtr(lctx, QWidget, widget);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, dummy->paint_func, lsfp, 4);
	} else {
//		QGraphicsItem::paint(painter, option, widget);
	}
}
