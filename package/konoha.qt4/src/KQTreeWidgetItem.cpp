//QTreeWidgetItem QTreeWidgetItem.new(int type);
KMETHOD QTreeWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int type = Int_to(int, sfp[1]);
	KQTreeWidgetItem *ret_v = new KQTreeWidgetItem(type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTreeWidgetItem QTreeWidgetItem.new(QTreeWidget parent, int type);
KMETHOD QTreeWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget*  parent = RawPtr_to(QTreeWidget*, sfp[1]);
	int type = Int_to(int, sfp[2]);
	KQTreeWidgetItem *ret_v = new KQTreeWidgetItem(parent, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTreeWidgetItem QTreeWidgetItem.new(QTreeWidget parent, QTreeWidgetItem preceding, int type);
KMETHOD QTreeWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget*  parent = RawPtr_to(QTreeWidget*, sfp[1]);
	QTreeWidgetItem*  preceding = RawPtr_to(QTreeWidgetItem*, sfp[2]);
	int type = Int_to(int, sfp[3]);
	KQTreeWidgetItem *ret_v = new KQTreeWidgetItem(parent, preceding, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTreeWidgetItem QTreeWidgetItem.new(QTreeWidgetItem parent, int type);
KMETHOD QTreeWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem*  parent = RawPtr_to(QTreeWidgetItem*, sfp[1]);
	int type = Int_to(int, sfp[2]);
	KQTreeWidgetItem *ret_v = new KQTreeWidgetItem(parent, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTreeWidgetItem QTreeWidgetItem.new(QTreeWidgetItem parent, QTreeWidgetItem preceding, int type);
KMETHOD QTreeWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem*  parent = RawPtr_to(QTreeWidgetItem*, sfp[1]);
	QTreeWidgetItem*  preceding = RawPtr_to(QTreeWidgetItem*, sfp[2]);
	int type = Int_to(int, sfp[3]);
	KQTreeWidgetItem *ret_v = new KQTreeWidgetItem(parent, preceding, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTreeWidgetItem QTreeWidgetItem.new(QTreeWidgetItem other);
KMETHOD QTreeWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTreeWidgetItem  other = *RawPtr_to(const QTreeWidgetItem *, sfp[1]);
	KQTreeWidgetItem *ret_v = new KQTreeWidgetItem(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QTreeWidgetItem.addChild(QTreeWidgetItem child);
KMETHOD QTreeWidgetItem_addChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem*  child = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		qp->addChild(child);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.addChildren(Array<QTreeWidgetItem> children);
KMETHOD QTreeWidgetItem_addChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QTreeWidgetItem*> children;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			children.append((QTreeWidgetItem*)p->rawptr);
		}
		qp->addChildren(children);
	}
	RETURNvoid_();
}

//QBrush QTreeWidgetItem.getBackground(int column);
KMETHOD QTreeWidgetItem_getBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QBrush ret_v = qp->background(column);
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidgetItem.getCheckState(int column);
KMETHOD QTreeWidgetItem_getCheckState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::CheckState ret_v = qp->checkState(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTreeWidgetItem QTreeWidgetItem.child(int index);
KMETHOD QTreeWidgetItem_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QTreeWidgetItem* ret_v = qp->child(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidgetItem.childCount();
KMETHOD QTreeWidgetItem_childCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->childCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTreeWidgetItem.getChildIndicatorPolicy();
KMETHOD QTreeWidgetItem_getChildIndicatorPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem::ChildIndicatorPolicy ret_v = qp->childIndicatorPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QTreeWidgetItem QTreeWidgetItem.clone();
KMETHOD QTreeWidgetItem_clone(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem* ret_v = qp->clone();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidgetItem.columnCount();
KMETHOD QTreeWidgetItem_columnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->columnCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QVariant QTreeWidgetItem.getData(int column, int role);
KMETHOD QTreeWidgetItem_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int role = Int_to(int, sfp[2]);
		QVariant ret_v = qp->data(column, role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtItemFlags QTreeWidgetItem.getFlags();
KMETHOD QTreeWidgetItem_getFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		Qt::ItemFlags ret_v = qp->flags();
		Qt::ItemFlags *ret_v_ = new Qt::ItemFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QTreeWidgetItem.getFont(int column);
KMETHOD QTreeWidgetItem_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QFont ret_v = qp->font(column);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QTreeWidgetItem.getForeground(int column);
KMETHOD QTreeWidgetItem_getForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QBrush ret_v = qp->foreground(column);
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QTreeWidgetItem.getIcon(int column);
KMETHOD QTreeWidgetItem_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QIcon ret_v = qp->icon(column);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidgetItem.indexOfChild(QTreeWidgetItem child);
KMETHOD QTreeWidgetItem_indexOfChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem*  child = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int ret_v = qp->indexOfChild(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTreeWidgetItem.insertChild(int index, QTreeWidgetItem child);
KMETHOD QTreeWidgetItem_insertChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QTreeWidgetItem*  child = RawPtr_to(QTreeWidgetItem*, sfp[2]);
		qp->insertChild(index, child);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.insertChildren(int index, Array<QTreeWidgetItem> children);
KMETHOD QTreeWidgetItem_insertChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		knh_Array_t *a = sfp[2].a;
		int asize = knh_Array_size(a);
		QList<QTreeWidgetItem*> children;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			children.append((QTreeWidgetItem*)p->rawptr);
		}
		qp->insertChildren(index, children);
	}
	RETURNvoid_();
}

//boolean QTreeWidgetItem.isDisabled();
KMETHOD QTreeWidgetItem_isDisabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDisabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeWidgetItem.isExpanded();
KMETHOD QTreeWidgetItem_isExpanded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isExpanded();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeWidgetItem.isFirstColumnSpanned();
KMETHOD QTreeWidgetItem_isFirstColumnSpanned(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFirstColumnSpanned();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeWidgetItem.isHidden();
KMETHOD QTreeWidgetItem_isHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isHidden();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeWidgetItem.isSelected();
KMETHOD QTreeWidgetItem_isSelected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSelected();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTreeWidgetItem QTreeWidgetItem.parent();
KMETHOD QTreeWidgetItem_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem* ret_v = qp->parent();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTreeWidgetItem.removeChild(QTreeWidgetItem child);
KMETHOD QTreeWidgetItem_removeChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem*  child = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		qp->removeChild(child);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setBackground(int column, QBrush brush);
KMETHOD QTreeWidgetItem_setBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[2]);
		qp->setBackground(column, brush);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setCheckState(int column, int state);
KMETHOD QTreeWidgetItem_setCheckState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::CheckState state = Int_to(Qt::CheckState, sfp[2]);
		qp->setCheckState(column, state);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setChildIndicatorPolicy(int policy);
KMETHOD QTreeWidgetItem_setChildIndicatorPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidgetItem::ChildIndicatorPolicy policy = Int_to(QTreeWidgetItem::ChildIndicatorPolicy, sfp[1]);
		qp->setChildIndicatorPolicy(policy);
	}
	RETURNvoid_();
}

//@Virtual void QTreeWidgetItem.setData(int column, int role, QVariant value);
KMETHOD QTreeWidgetItem_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int role = Int_to(int, sfp[2]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[3]);
		qp->setData(column, role, value);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setDisabled(boolean disabled);
KMETHOD QTreeWidgetItem_setDisabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool disabled = Boolean_to(bool, sfp[1]);
		qp->setDisabled(disabled);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setExpanded(boolean expand);
KMETHOD QTreeWidgetItem_setExpanded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool expand = Boolean_to(bool, sfp[1]);
		qp->setExpanded(expand);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setFirstColumnSpanned(boolean span);
KMETHOD QTreeWidgetItem_setFirstColumnSpanned(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool span = Boolean_to(bool, sfp[1]);
		qp->setFirstColumnSpanned(span);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setFlags(QtItemFlags flags);
KMETHOD QTreeWidgetItem_setFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		initFlag(flags, Qt::ItemFlags, sfp[1]);
		qp->setFlags(flags);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setFont(int column, QFont font);
KMETHOD QTreeWidgetItem_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[2]);
		qp->setFont(column, font);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setForeground(int column, QBrush brush);
KMETHOD QTreeWidgetItem_setForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[2]);
		qp->setForeground(column, brush);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setHidden(boolean hide);
KMETHOD QTreeWidgetItem_setHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool hide = Boolean_to(bool, sfp[1]);
		qp->setHidden(hide);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setIcon(int column, QIcon icon);
KMETHOD QTreeWidgetItem_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		qp->setIcon(column, icon);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setSelected(boolean select);
KMETHOD QTreeWidgetItem_setSelected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		bool select = Boolean_to(bool, sfp[1]);
		qp->setSelected(select);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setSizeHint(int column, QSize size);
KMETHOD QTreeWidgetItem_setSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
		qp->setSizeHint(column, size);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setStatusTip(int column, String statusTip);
KMETHOD QTreeWidgetItem_setStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QString statusTip = String_to(const QString, sfp[2]);
		qp->setStatusTip(column, statusTip);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setText(int column, String text);
KMETHOD QTreeWidgetItem_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setText(column, text);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setTextAlignment(int column, int alignment);
KMETHOD QTreeWidgetItem_setTextAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int alignment = Int_to(int, sfp[2]);
		qp->setTextAlignment(column, alignment);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setToolTip(int column, String toolTip);
KMETHOD QTreeWidgetItem_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QString toolTip = String_to(const QString, sfp[2]);
		qp->setToolTip(column, toolTip);
	}
	RETURNvoid_();
}

//void QTreeWidgetItem.setWhatsThis(int column, String whatsThis);
KMETHOD QTreeWidgetItem_setWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QString whatsThis = String_to(const QString, sfp[2]);
		qp->setWhatsThis(column, whatsThis);
	}
	RETURNvoid_();
}

//QSize QTreeWidgetItem.getSizeHint(int column);
KMETHOD QTreeWidgetItem_getSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QSize ret_v = qp->sizeHint(column);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTreeWidgetItem.sortChildren(int column, int order);
KMETHOD QTreeWidgetItem_sortChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sortChildren(column, order);
	}
	RETURNvoid_();
}

//String QTreeWidgetItem.getStatusTip(int column);
KMETHOD QTreeWidgetItem_getStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QString ret_v = qp->statusTip(column);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTreeWidgetItem QTreeWidgetItem.takeChild(int index);
KMETHOD QTreeWidgetItem_takeChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QTreeWidgetItem* ret_v = qp->takeChild(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QTreeWidgetItem> QTreeWidgetItem.takeChildren();
KMETHOD QTreeWidgetItem_takeChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QList<QTreeWidgetItem*> ret_v = qp->takeChildren();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTreeWidgetItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QTreeWidgetItem.getText(int column);
KMETHOD QTreeWidgetItem_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QString ret_v = qp->text(column);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidgetItem.getTextAlignment(int column);
KMETHOD QTreeWidgetItem_getTextAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->textAlignment(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTreeWidgetItem.getToolTip(int column);
KMETHOD QTreeWidgetItem_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QString ret_v = qp->toolTip(column);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTreeWidget QTreeWidgetItem.treeWidget();
KMETHOD QTreeWidgetItem_treeWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		QTreeWidget* ret_v = qp->treeWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidgetItem.type();
KMETHOD QTreeWidgetItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTreeWidgetItem.getWhatsThis(int column);
KMETHOD QTreeWidgetItem_getWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *  qp = RawPtr_to(QTreeWidgetItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QString ret_v = qp->whatsThis(column);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QTreeWidgetItem.parents();
KMETHOD QTreeWidgetItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidgetItem *qp = RawPtr_to(QTreeWidgetItem*, sfp[0]);
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

DummyQTreeWidgetItem::DummyQTreeWidgetItem()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTreeWidgetItem::~DummyQTreeWidgetItem()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTreeWidgetItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTreeWidgetItem::self = ptr;
}

bool DummyQTreeWidgetItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTreeWidgetItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTreeWidgetItem::event_map->bigin();
	if ((itr = DummyQTreeWidgetItem::event_map->find(str)) == DummyQTreeWidgetItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTreeWidgetItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTreeWidgetItem::slot_map->bigin();
	if ((itr = DummyQTreeWidgetItem::slot_map->find(str)) == DummyQTreeWidgetItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTreeWidgetItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTreeWidgetItem::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTreeWidgetItem::connection(QObject *o)
{
	QTreeWidgetItem *p = dynamic_cast<QTreeWidgetItem*>(o);
	if (p != NULL) {
	}
}

KQTreeWidgetItem::KQTreeWidgetItem(int type) : QTreeWidgetItem(type)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTreeWidgetItem();
}

KQTreeWidgetItem::~KQTreeWidgetItem()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTreeWidgetItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTreeWidgetItem *qp = RawPtr_to(KQTreeWidgetItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTreeWidgetItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTreeWidgetItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTreeWidgetItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTreeWidgetItem *qp = RawPtr_to(KQTreeWidgetItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTreeWidgetItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTreeWidgetItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTreeWidgetItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTreeWidgetItem *qp = (KQTreeWidgetItem *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTreeWidgetItem*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTreeWidgetItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTreeWidgetItem *qp = (KQTreeWidgetItem *)p->rawptr;
		KQTreeWidgetItem *qp = static_cast<KQTreeWidgetItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTreeWidgetItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTreeWidgetItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTreeWidgetItemConstInt[] = {
	{"ShowIndicator", QTreeWidgetItem::ShowIndicator},
	{"DontShowIndicator", QTreeWidgetItem::DontShowIndicator},
	{"DontShowIndicatorWhenChildless", QTreeWidgetItem::DontShowIndicatorWhenChildless},
	{"Type", QTreeWidgetItem::Type},
	{"UserType", QTreeWidgetItem::UserType},
	{NULL, 0}
};

DEFAPI(void) constQTreeWidgetItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTreeWidgetItemConstInt);
}


DEFAPI(void) defQTreeWidgetItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTreeWidgetItem";
	cdef->free = QTreeWidgetItem_free;
	cdef->reftrace = QTreeWidgetItem_reftrace;
	cdef->compareTo = QTreeWidgetItem_compareTo;
}


