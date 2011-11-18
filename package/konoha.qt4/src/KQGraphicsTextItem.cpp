//@Virtual @Override QRectF QGraphicsTextItem.boundingRect();
KMETHOD QGraphicsTextItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsTextItem.contains(QPointF point);
KMETHOD QGraphicsTextItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QGraphicsTextItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsTextItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsTextItem.opaqueArea();
KMETHOD QGraphicsTextItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPainterPath QGraphicsTextItem.shape();
KMETHOD QGraphicsTextItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsTextItem.type();
KMETHOD QGraphicsTextItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsTextItem QGraphicsTextItem.new(QGraphicsItem parent);
KMETHOD QGraphicsTextItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsTextItem *ret_v = new KQGraphicsTextItem(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsTextItem QGraphicsTextItem.new(String text, QGraphicsItem parent);
KMETHOD QGraphicsTextItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[2]);
	KQGraphicsTextItem *ret_v = new KQGraphicsTextItem(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QGraphicsTextItem.adjustSize();
KMETHOD QGraphicsTextItem_adjustSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		qp->adjustSize();
	}
	RETURNvoid_();
}

//QColor QGraphicsTextItem.getDefaultTextColor();
KMETHOD QGraphicsTextItem_getDefaultTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->defaultTextColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextDocument QGraphicsTextItem.getDocument();
KMETHOD QGraphicsTextItem_getDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QGraphicsTextItem.getFont();
KMETHOD QGraphicsTextItem_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsTextItem.getOpenExternalLinks();
KMETHOD QGraphicsTextItem_getOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->openExternalLinks();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsTextItem.setDefaultTextColor(QColor col);
KMETHOD QGraphicsTextItem_setDefaultTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QColor  col = *RawPtr_to(const QColor *, sfp[1]);
		qp->setDefaultTextColor(col);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setDocument(QTextDocument document);
KMETHOD QGraphicsTextItem_setDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QTextDocument*  document = RawPtr_to(QTextDocument*, sfp[1]);
		qp->setDocument(document);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setFont(QFont font);
KMETHOD QGraphicsTextItem_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setHtml(String text);
KMETHOD QGraphicsTextItem_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setHtml(text);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setOpenExternalLinks(boolean open);
KMETHOD QGraphicsTextItem_setOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		bool open = Boolean_to(bool, sfp[1]);
		qp->setOpenExternalLinks(open);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setPlainText(String text);
KMETHOD QGraphicsTextItem_setPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setPlainText(text);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setTabChangesFocus(boolean b);
KMETHOD QGraphicsTextItem_setTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setTabChangesFocus(b);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setTextCursor(QTextCursor cursor);
KMETHOD QGraphicsTextItem_setTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		qp->setTextCursor(cursor);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setTextInteractionFlags(QtTextInteractionFlags flags);
KMETHOD QGraphicsTextItem_setTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		initFlag(flags, Qt::TextInteractionFlags, sfp[1]);
		qp->setTextInteractionFlags(flags);
	}
	RETURNvoid_();
}

//void QGraphicsTextItem.setTextWidth(float width);
KMETHOD QGraphicsTextItem_setTextWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setTextWidth(width);
	}
	RETURNvoid_();
}

//boolean QGraphicsTextItem.getTabChangesFocus();
KMETHOD QGraphicsTextItem_getTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->tabChangesFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTextCursor QGraphicsTextItem.getTextCursor();
KMETHOD QGraphicsTextItem_getTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QTextCursor ret_v = qp->textCursor();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtTextInteractionFlags QGraphicsTextItem.getTextInteractionFlags();
KMETHOD QGraphicsTextItem_getTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		Qt::TextInteractionFlags ret_v = qp->textInteractionFlags();
		Qt::TextInteractionFlags *ret_v_ = new Qt::TextInteractionFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsTextItem.getTextWidth();
KMETHOD QGraphicsTextItem_getTextWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->textWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QGraphicsTextItem.toHtml();
KMETHOD QGraphicsTextItem_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toHtml();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QGraphicsTextItem.toPlainText();
KMETHOD QGraphicsTextItem_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsTextItem *  qp = RawPtr_to(QGraphicsTextItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

// //@Virtual void QGraphicsTextItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QGraphicsTextItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQGraphicsTextItem *  qp = RawPtr_to(KQGraphicsTextItem *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QGraphicsTextItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsTextItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsTextItem *  qp = RawPtr_to(KQGraphicsTextItem *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQGraphicsTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (dummy->paint_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPainter, painter);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QStyleOptionGraphicsItem, option);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QWidget, widget);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, dummy->paint_func, lsfp, 4);
	} else {
		QGraphicsTextItem::paint(painter, option, widget);
	}
}

DummyQGraphicsTextItem::DummyQGraphicsTextItem()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	link_activated_func = NULL;
	link_hovered_func = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-activated", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-hovered", NULL));
}
DummyQGraphicsTextItem::~DummyQGraphicsTextItem()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsTextItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsTextItem::self = ptr;
	DummyQGraphicsObject::setSelf(ptr);
}

bool DummyQGraphicsTextItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsTextItem::linkActivatedSlot(const QString link)
{
	if (link_activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, link);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, link_activated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsTextItem::linkHoveredSlot(const QString link)
{
	if (link_hovered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, link);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, link_hovered_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsTextItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsTextItem::event_map->bigin();
	if ((itr = DummyQGraphicsTextItem::event_map->find(str)) == DummyQGraphicsTextItem::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		paint_func = (*event_map)["paint"];
		return true;
	}
}

bool DummyQGraphicsTextItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsTextItem::slot_map->bigin();
	if ((itr = DummyQGraphicsTextItem::slot_map->find(str)) == DummyQGraphicsTextItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		link_activated_func = (*slot_map)["link-activated"];
		link_hovered_func = (*slot_map)["link-hovered"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsTextItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsTextItem::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, link_activated_func);
	KNH_ADDNNREF(ctx, link_hovered_func);
	KNH_ADDNNREF(ctx, paint_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsTextItem::connection(QObject *o)
{
	QGraphicsTextItem *p = dynamic_cast<QGraphicsTextItem*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(linkActivated(const QString)), this, SLOT(linkActivatedSlot(const QString)));
		connect(p, SIGNAL(linkHovered(const QString)), this, SLOT(linkHoveredSlot(const QString)));
	}
	DummyQGraphicsObject::connection(o);
}

KQGraphicsTextItem::KQGraphicsTextItem(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsTextItem();
	dummy->connection((QObject*)this);
}

KQGraphicsTextItem::~KQGraphicsTextItem()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsTextItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsTextItem *qp = RawPtr_to(KQGraphicsTextItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsTextItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsTextItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsTextItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsTextItem *qp = RawPtr_to(KQGraphicsTextItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsTextItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsTextItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsTextItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsTextItem *qp = (KQGraphicsTextItem *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsTextItem*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsTextItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsTextItem *qp = (KQGraphicsTextItem *)p->rawptr;
		KQGraphicsTextItem *qp = static_cast<KQGraphicsTextItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsTextItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsTextItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsTextItem::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsTextItem::sceneEvent(event);
		return false;
	}
//	QGraphicsTextItem::sceneEvent(event);
	return true;
}



DEFAPI(void) defQGraphicsTextItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsTextItem";
	cdef->free = QGraphicsTextItem_free;
	cdef->reftrace = QGraphicsTextItem_reftrace;
	cdef->compareTo = QGraphicsTextItem_compareTo;
}


