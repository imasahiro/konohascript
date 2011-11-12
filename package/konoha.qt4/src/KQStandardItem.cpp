//QStandardItem QStandardItem.new();
KMETHOD QStandardItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStandardItem *ret_v = new KQStandardItem();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStandardItem QStandardItem.new(String text);
KMETHOD QStandardItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	KQStandardItem *ret_v = new KQStandardItem(text);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStandardItem QStandardItem.new(QIcon icon, String text);
KMETHOD QStandardItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
	const QString text = String_to(const QString, sfp[2]);
	KQStandardItem *ret_v = new KQStandardItem(icon, text);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStandardItem QStandardItem.new(int rows, int columns);
KMETHOD QStandardItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int rows = Int_to(int, sfp[1]);
	int columns = Int_to(int, sfp[2]);
	KQStandardItem *ret_v = new KQStandardItem(rows, columns);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QStandardItem.getAccessibleDescription();
KMETHOD QStandardItem_getAccessibleDescription(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->accessibleDescription();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QStandardItem.getAccessibleText();
KMETHOD QStandardItem_getAccessibleText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->accessibleText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QStandardItem.appendColumn(Array<QStandardItem> items);
KMETHOD QStandardItem_appendColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QStandardItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QStandardItem*)p->rawptr);
		}
		qp->appendColumn(items);
	}
	RETURNvoid_();
}

//void QStandardItem.appendRow(Array<QStandardItem> items);
KMETHOD QStandardItem_appendRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QStandardItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QStandardItem*)p->rawptr);
		}
		qp->appendRow(items);
	}
	RETURNvoid_();
}

/*
//void QStandardItem.appendRow(QStandardItem item);
KMETHOD QStandardItem_appendRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QStandardItem*  item = RawPtr_to(QStandardItem*, sfp[1]);
		qp->appendRow(item);
	}
	RETURNvoid_();
}
*/
//void QStandardItem.appendRows(Array<QStandardItem> items);
KMETHOD QStandardItem_appendRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QStandardItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QStandardItem*)p->rawptr);
		}
		qp->appendRows(items);
	}
	RETURNvoid_();
}

//QBrush QStandardItem.getBackground();
KMETHOD QStandardItem_getBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->background();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QStandardItem.getCheckState();
KMETHOD QStandardItem_getCheckState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		Qt::CheckState ret_v = qp->checkState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QStandardItem QStandardItem.getChild(int row, int column);
KMETHOD QStandardItem_getChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QStandardItem* ret_v = qp->child(row, column);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStandardItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QStandardItem QStandardItem.clone();
KMETHOD QStandardItem_clone(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QStandardItem* ret_v = qp->clone();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStandardItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QStandardItem.column();
KMETHOD QStandardItem_column(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->column();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QStandardItem.getColumnCount();
KMETHOD QStandardItem_getColumnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->columnCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QVariant QStandardItem.getData(int role);
KMETHOD QStandardItem_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int role = Int_to(int, sfp[1]);
		QVariant ret_v = qp->data(role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtItemFlags QStandardItem.getFlags();
KMETHOD QStandardItem_getFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		Qt::ItemFlags ret_v = qp->flags();
		Qt::ItemFlags *ret_v_ = new Qt::ItemFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QStandardItem.getFont();
KMETHOD QStandardItem_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QStandardItem.getForeground();
KMETHOD QStandardItem_getForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->foreground();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QStandardItem.hasChildren();
KMETHOD QStandardItem_hasChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasChildren();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QIcon QStandardItem.getIcon();
KMETHOD QStandardItem_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QModelIndex QStandardItem.index();
KMETHOD QStandardItem_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QModelIndex ret_v = qp->index();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QStandardItem.insertColumns(int column, int count);
KMETHOD QStandardItem_insertColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		qp->insertColumns(column, count);
	}
	RETURNvoid_();
}

//void QStandardItem.insertRows(int row, Array<QStandardItem> items);
KMETHOD QStandardItem_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		knh_Array_t *a = sfp[2].a;
		int asize = knh_Array_size(a);
		QList<QStandardItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QStandardItem*)p->rawptr);
		}
		qp->insertRows(row, items);
	}
	RETURNvoid_();
}

/*
//void QStandardItem.insertRows(int row, int count);
KMETHOD QStandardItem_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		qp->insertRows(row, count);
	}
	RETURNvoid_();
}
*/
//boolean QStandardItem.isCheckable();
KMETHOD QStandardItem_isCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCheckable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QStandardItem.isDragEnabled();
KMETHOD QStandardItem_isDragEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDragEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QStandardItem.isDropEnabled();
KMETHOD QStandardItem_isDropEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDropEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QStandardItem.isEditable();
KMETHOD QStandardItem_isEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEditable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QStandardItem.isEnabled();
KMETHOD QStandardItem_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QStandardItem.isSelectable();
KMETHOD QStandardItem_isSelectable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSelectable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QStandardItem.isTristate();
KMETHOD QStandardItem_isTristate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTristate();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QStandardItemModel QStandardItem.model();
KMETHOD QStandardItem_model(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QStandardItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStandardItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QStandardItem QStandardItem.parent();
KMETHOD QStandardItem_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QStandardItem* ret_v = qp->parent();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStandardItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QStandardItem.removeColumn(int column);
KMETHOD QStandardItem_removeColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->removeColumn(column);
	}
	RETURNvoid_();
}

//void QStandardItem.removeColumns(int column, int count);
KMETHOD QStandardItem_removeColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		qp->removeColumns(column, count);
	}
	RETURNvoid_();
}

//void QStandardItem.removeRow(int row);
KMETHOD QStandardItem_removeRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qp->removeRow(row);
	}
	RETURNvoid_();
}

//void QStandardItem.removeRows(int row, int count);
KMETHOD QStandardItem_removeRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		qp->removeRows(row, count);
	}
	RETURNvoid_();
}

//int QStandardItem.row();
KMETHOD QStandardItem_row(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->row();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QStandardItem.getRowCount();
KMETHOD QStandardItem_getRowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->rowCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QStandardItem.setAccessibleDescription(String accessibleDescription);
KMETHOD QStandardItem_setAccessibleDescription(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QString accessibleDescription = String_to(const QString, sfp[1]);
		qp->setAccessibleDescription(accessibleDescription);
	}
	RETURNvoid_();
}

//void QStandardItem.setAccessibleText(String accessibleText);
KMETHOD QStandardItem_setAccessibleText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QString accessibleText = String_to(const QString, sfp[1]);
		qp->setAccessibleText(accessibleText);
	}
	RETURNvoid_();
}

//void QStandardItem.setBackground(QBrush brush);
KMETHOD QStandardItem_setBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackground(brush);
	}
	RETURNvoid_();
}

//void QStandardItem.setCheckState(int state);
KMETHOD QStandardItem_setCheckState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		Qt::CheckState state = Int_to(Qt::CheckState, sfp[1]);
		qp->setCheckState(state);
	}
	RETURNvoid_();
}

//void QStandardItem.setCheckable(boolean checkable);
KMETHOD QStandardItem_setCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool checkable = Boolean_to(bool, sfp[1]);
		qp->setCheckable(checkable);
	}
	RETURNvoid_();
}

//void QStandardItem.setChild(int row, int column, QStandardItem item);
KMETHOD QStandardItem_setChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QStandardItem*  item = RawPtr_to(QStandardItem*, sfp[3]);
		qp->setChild(row, column, item);
	}
	RETURNvoid_();
}

/*
//void QStandardItem.setChild(int row, QStandardItem item);
KMETHOD QStandardItem_setChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		QStandardItem*  item = RawPtr_to(QStandardItem*, sfp[2]);
		qp->setChild(row, item);
	}
	RETURNvoid_();
}
*/
//void QStandardItem.setColumnCount(int columns);
KMETHOD QStandardItem_setColumnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int columns = Int_to(int, sfp[1]);
		qp->setColumnCount(columns);
	}
	RETURNvoid_();
}

//@Virtual void QStandardItem.setData(QVariant value, int role);
KMETHOD QStandardItem_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[1]);
		int role = Int_to(int, sfp[2]);
		qp->setData(value, role);
	}
	RETURNvoid_();
}

//void QStandardItem.setDragEnabled(boolean dragEnabled);
KMETHOD QStandardItem_setDragEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool dragEnabled = Boolean_to(bool, sfp[1]);
		qp->setDragEnabled(dragEnabled);
	}
	RETURNvoid_();
}

//void QStandardItem.setDropEnabled(boolean dropEnabled);
KMETHOD QStandardItem_setDropEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool dropEnabled = Boolean_to(bool, sfp[1]);
		qp->setDropEnabled(dropEnabled);
	}
	RETURNvoid_();
}

//void QStandardItem.setEditable(boolean editable);
KMETHOD QStandardItem_setEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool editable = Boolean_to(bool, sfp[1]);
		qp->setEditable(editable);
	}
	RETURNvoid_();
}

//void QStandardItem.setEnabled(boolean enabled);
KMETHOD QStandardItem_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setEnabled(enabled);
	}
	RETURNvoid_();
}

//void QStandardItem.setFlags(QtItemFlags flags);
KMETHOD QStandardItem_setFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		initFlag(flags, Qt::ItemFlags, sfp[1]);
		qp->setFlags(flags);
	}
	RETURNvoid_();
}

//void QStandardItem.setFont(QFont font);
KMETHOD QStandardItem_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QStandardItem.setForeground(QBrush brush);
KMETHOD QStandardItem_setForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setForeground(brush);
	}
	RETURNvoid_();
}

//void QStandardItem.setIcon(QIcon icon);
KMETHOD QStandardItem_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		qp->setIcon(icon);
	}
	RETURNvoid_();
}

//void QStandardItem.setRowCount(int rows);
KMETHOD QStandardItem_setRowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int rows = Int_to(int, sfp[1]);
		qp->setRowCount(rows);
	}
	RETURNvoid_();
}

//void QStandardItem.setSelectable(boolean selectable);
KMETHOD QStandardItem_setSelectable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool selectable = Boolean_to(bool, sfp[1]);
		qp->setSelectable(selectable);
	}
	RETURNvoid_();
}

//void QStandardItem.setSizeHint(QSize size);
KMETHOD QStandardItem_setSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setSizeHint(size);
	}
	RETURNvoid_();
}

//void QStandardItem.setStatusTip(String statusTip);
KMETHOD QStandardItem_setStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QString statusTip = String_to(const QString, sfp[1]);
		qp->setStatusTip(statusTip);
	}
	RETURNvoid_();
}

//void QStandardItem.setText(String text);
KMETHOD QStandardItem_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//void QStandardItem.setTextAlignment(QtAlignment alignment);
KMETHOD QStandardItem_setTextAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setTextAlignment(alignment);
	}
	RETURNvoid_();
}

//void QStandardItem.setToolTip(String toolTip);
KMETHOD QStandardItem_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QString toolTip = String_to(const QString, sfp[1]);
		qp->setToolTip(toolTip);
	}
	RETURNvoid_();
}

//void QStandardItem.setTristate(boolean tristate);
KMETHOD QStandardItem_setTristate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		bool tristate = Boolean_to(bool, sfp[1]);
		qp->setTristate(tristate);
	}
	RETURNvoid_();
}

//void QStandardItem.setWhatsThis(String whatsThis);
KMETHOD QStandardItem_setWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		const QString whatsThis = String_to(const QString, sfp[1]);
		qp->setWhatsThis(whatsThis);
	}
	RETURNvoid_();
}

//QSize QStandardItem.getSizeHint();
KMETHOD QStandardItem_getSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QStandardItem.sortChildren(int column, int order);
KMETHOD QStandardItem_sortChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sortChildren(column, order);
	}
	RETURNvoid_();
}

//String QStandardItem.getStatusTip();
KMETHOD QStandardItem_getStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->statusTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QStandardItem QStandardItem.takeChild(int row, int column);
KMETHOD QStandardItem_takeChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QStandardItem* ret_v = qp->takeChild(row, column);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStandardItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QStandardItem> QStandardItem.takeColumn(int column);
KMETHOD QStandardItem_takeColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		QList<QStandardItem*> ret_v = qp->takeColumn(column);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QStandardItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QStandardItem> QStandardItem.takeRow(int row);
KMETHOD QStandardItem_takeRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		QList<QStandardItem*> ret_v = qp->takeRow(row);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QStandardItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QStandardItem.getText();
KMETHOD QStandardItem_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtAlignment QStandardItem.getTextAlignment();
KMETHOD QStandardItem_getTextAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->textAlignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QStandardItem.getToolTip();
KMETHOD QStandardItem_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toolTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QStandardItem.type();
KMETHOD QStandardItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QStandardItem.getWhatsThis();
KMETHOD QStandardItem_getWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *  qp = RawPtr_to(QStandardItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->whatsThis();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QStandardItem.parents();
KMETHOD QStandardItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStandardItem *qp = RawPtr_to(QStandardItem*, sfp[0]);
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

DummyQStandardItem::DummyQStandardItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStandardItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStandardItem::self = ptr;
}

bool DummyQStandardItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQStandardItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStandardItem::event_map->bigin();
	if ((itr = DummyQStandardItem::event_map->find(str)) == DummyQStandardItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStandardItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStandardItem::slot_map->bigin();
	if ((itr = DummyQStandardItem::slot_map->find(str)) == DummyQStandardItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStandardItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStandardItem::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQStandardItem::connection(QObject *o)
{
	QStandardItem *p = dynamic_cast<QStandardItem*>(o);
	if (p != NULL) {
	}
}

KQStandardItem::KQStandardItem() : QStandardItem()
{
	self = NULL;
	dummy = new DummyQStandardItem();
}

KMETHOD QStandardItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStandardItem *qp = RawPtr_to(KQStandardItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStandardItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStandardItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStandardItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStandardItem *qp = RawPtr_to(KQStandardItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStandardItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStandardItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStandardItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStandardItem *qp = (KQStandardItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStandardItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStandardItem *qp = (KQStandardItem *)p->rawptr;
//		KQStandardItem *qp = static_cast<KQStandardItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStandardItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStandardItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStandardItemConstInt[] = {
	{"Type", QStandardItem::Type},
	{"UserType", QStandardItem::UserType},
	{NULL, 0}
};

DEFAPI(void) constQStandardItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStandardItemConstInt);
}


DEFAPI(void) defQStandardItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStandardItem";
	cdef->free = QStandardItem_free;
	cdef->reftrace = QStandardItem_reftrace;
	cdef->compareTo = QStandardItem_compareTo;
}


