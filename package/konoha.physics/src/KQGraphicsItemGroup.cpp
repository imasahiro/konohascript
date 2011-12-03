#include <physics.hpp>
#include <qt4_common.hpp>

using namespace std;

void KQGraphicsItemGroup::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
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
		QGraphicsItemGroup::paint(painter, option, widget);
	}
}

DummyQGraphicsItemGroup::DummyQGraphicsItemGroup()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	paint_func = NULL;
	event_map = new map<string, kFunc *>();
	slot_map = new map<string, kFunc *>();
	event_map->insert(map<string, kFunc *>::value_type("paint", NULL));
}

DummyQGraphicsItemGroup::~DummyQGraphicsItemGroup()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsItemGroup::setSelf(kRawPtr *ptr)
{
	DummyQGraphicsItemGroup::self = ptr;
	DummyQGraphicsItem::setSelf(ptr);
}

bool DummyQGraphicsItemGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsItemGroup::addEvent(kFunc *callback_func, string str)
{
	std::map<string, kFunc*>::iterator itr;// = DummyQGraphicsItemGroup::event_map->bigin();
	if ((itr = DummyQGraphicsItemGroup::event_map->find(str)) == DummyQGraphicsItemGroup::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		paint_func = (*event_map)["paint"];
		return true;
	}
}

bool DummyQGraphicsItemGroup::signalConnect(kFunc *callback_func, string str)
{
	std::map<string, kFunc*>::iterator itr;// = DummyQGraphicsItemGroup::slot_map->bigin();
	if ((itr = DummyQGraphicsItemGroup::slot_map->find(str)) == DummyQGraphicsItemGroup::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

kObject** DummyQGraphicsItemGroup::reftrace(CTX ctx, kRawPtr *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsItemGroup::reftrace p->rawptr=[%p]\n", p->rawptr);
	int length = added_list->length();
	KNH_ENSUREREF(ctx, length);

	for (int i = 0; i < length; i++) {
		kRawPtr *item = added_list->at(i);
		KNH_ADDNNREF(ctx, item);
	}

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsItemGroup::connection(QObject *o)
{
	QGraphicsItemGroup *p = dynamic_cast<QGraphicsItemGroup*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsItem::connection(o);
}

KQGraphicsItemGroup::KQGraphicsItemGroup(QGraphicsItem* parent) : QGraphicsItemGroup(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsItemGroup();
	dummy->added_list = new QList<kRawPtr *>();
}

KQGraphicsItemGroup::~KQGraphicsItemGroup()
{
	delete dummy;
	dummy = NULL;
}

void KQGraphicsItemGroup::setSelf(kRawPtr *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsItemGroup::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsItemGroup::sceneEvent(event);
		return false;
	}
//	QGraphicsItemGroup::sceneEvent(event);
	return true;
}
