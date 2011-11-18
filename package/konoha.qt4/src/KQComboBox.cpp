//@Virtual @Override boolean QComboBox.event(QEvent event);
KMETHOD QComboBox_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QComboBox.minimumSizeHint();
KMETHOD QComboBox_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QComboBox.sizeHint();
KMETHOD QComboBox_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QComboBox QComboBox.new(QWidget parent);
KMETHOD QComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQComboBox *ret_v = new KQComboBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QComboBox.addItem(String text, QVariant userData);
KMETHOD QComboBox_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		const QVariant  userData = *RawPtr_to(const QVariant *, sfp[2]);
		qp->addItem(text, userData);
	}
	RETURNvoid_();
}

/*
//void QComboBox.addItem(QIcon icon, String text, QVariant userData);
KMETHOD QComboBox_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		const QVariant  userData = *RawPtr_to(const QVariant *, sfp[3]);
		qp->addItem(icon, text, userData);
	}
	RETURNvoid_();
}
*/
//QCompleter QComboBox.getCompleter();
KMETHOD QComboBox_getCompleter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QCompleter* ret_v = qp->completer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QCompleter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QComboBox.count();
KMETHOD QComboBox_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QComboBox.getCurrentIndex();
KMETHOD QComboBox_getCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QComboBox.currentText();
KMETHOD QComboBox_currentText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->currentText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QComboBox.getDuplicatesEnabled();
KMETHOD QComboBox_getDuplicatesEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->duplicatesEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QComboBox.findData(QVariant data, int role, QtMatchFlags flags);
KMETHOD QComboBox_findData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QVariant  data = *RawPtr_to(const QVariant *, sfp[1]);
		int role = Int_to(int, sfp[2]);
		initFlag(flags, Qt::MatchFlags, sfp[3]);
		int ret_v = qp->findData(data, role, flags);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QComboBox.findText(String text, QtMatchFlags flags);
KMETHOD QComboBox_findText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		initFlag(flags, Qt::MatchFlags, sfp[2]);
		int ret_v = qp->findText(text, flags);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QComboBox.hasFrame();
KMETHOD QComboBox_hasFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasFrame();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QComboBox.hidePopup();
KMETHOD QComboBox_hidePopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		qp->hidePopup();
	}
	RETURNvoid_();
}

//QSize QComboBox.getIconSize();
KMETHOD QComboBox_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QComboBox.insertItem(int index, String text, QVariant userData);
KMETHOD QComboBox_insertItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		const QVariant  userData = *RawPtr_to(const QVariant *, sfp[3]);
		qp->insertItem(index, text, userData);
	}
	RETURNvoid_();
}

/*
//void QComboBox.insertItem(int index, QIcon icon, String text, QVariant userData);
KMETHOD QComboBox_insertItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		const QVariant  userData = *RawPtr_to(const QVariant *, sfp[4]);
		qp->insertItem(index, icon, text, userData);
	}
	RETURNvoid_();
}
*/
//int QComboBox.getInsertPolicy();
KMETHOD QComboBox_getInsertPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QComboBox::InsertPolicy ret_v = qp->insertPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QComboBox.insertSeparator(int index);
KMETHOD QComboBox_insertSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->insertSeparator(index);
	}
	RETURNvoid_();
}

//boolean QComboBox.isEditable();
KMETHOD QComboBox_isEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEditable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QVariant QComboBox.getItemData(int index, int role);
KMETHOD QComboBox_getItemData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int role = Int_to(int, sfp[2]);
		QVariant ret_v = qp->itemData(index, role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemDelegate QComboBox.getItemDelegate();
KMETHOD QComboBox_getItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QAbstractItemDelegate* ret_v = qp->itemDelegate();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemDelegate*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QComboBox.getItemIcon(int index);
KMETHOD QComboBox_getItemIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QIcon ret_v = qp->itemIcon(index);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QComboBox.getItemText(int index);
KMETHOD QComboBox_getItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->itemText(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLineEdit QComboBox.getLineEdit();
KMETHOD QComboBox_getLineEdit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QLineEdit* ret_v = qp->lineEdit();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLineEdit*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QComboBox.getMaxCount();
KMETHOD QComboBox_getMaxCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QComboBox.getMaxVisibleItems();
KMETHOD QComboBox_getMaxVisibleItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxVisibleItems();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QComboBox.getMinimumContentsLength();
KMETHOD QComboBox_getMinimumContentsLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->minimumContentsLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAbstractItemModel QComboBox.getModel();
KMETHOD QComboBox_getModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QComboBox.getModelColumn();
KMETHOD QComboBox_getModelColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->modelColumn();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QComboBox.removeItem(int index);
KMETHOD QComboBox_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->removeItem(index);
	}
	RETURNvoid_();
}

//QModelIndex QComboBox.getRootModelIndex();
KMETHOD QComboBox_getRootModelIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QModelIndex ret_v = qp->rootModelIndex();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QComboBox.setCompleter(QCompleter completer);
KMETHOD QComboBox_setCompleter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QCompleter*  completer = RawPtr_to(QCompleter*, sfp[1]);
		qp->setCompleter(completer);
	}
	RETURNvoid_();
}

//void QComboBox.setDuplicatesEnabled(boolean enable);
KMETHOD QComboBox_setDuplicatesEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDuplicatesEnabled(enable);
	}
	RETURNvoid_();
}

//void QComboBox.setEditable(boolean editable);
KMETHOD QComboBox_setEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		bool editable = Boolean_to(bool, sfp[1]);
		qp->setEditable(editable);
	}
	RETURNvoid_();
}

//void QComboBox.setFrame(boolean arg0);
KMETHOD QComboBox_setFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setFrame(arg0);
	}
	RETURNvoid_();
}

//void QComboBox.setIconSize(QSize size);
KMETHOD QComboBox_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(size);
	}
	RETURNvoid_();
}

//void QComboBox.setInsertPolicy(int policy);
KMETHOD QComboBox_setInsertPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QComboBox::InsertPolicy policy = Int_to(QComboBox::InsertPolicy, sfp[1]);
		qp->setInsertPolicy(policy);
	}
	RETURNvoid_();
}

//void QComboBox.setItemData(int index, QVariant value, int role);
KMETHOD QComboBox_setItemData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		int role = Int_to(int, sfp[3]);
		qp->setItemData(index, value, role);
	}
	RETURNvoid_();
}

//void QComboBox.setItemDelegate(QAbstractItemDelegate delegate);
KMETHOD QComboBox_setItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QAbstractItemDelegate*  delegate = RawPtr_to(QAbstractItemDelegate*, sfp[1]);
		qp->setItemDelegate(delegate);
	}
	RETURNvoid_();
}

//void QComboBox.setItemIcon(int index, QIcon icon);
KMETHOD QComboBox_setItemIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		qp->setItemIcon(index, icon);
	}
	RETURNvoid_();
}

//void QComboBox.setItemText(int index, String text);
KMETHOD QComboBox_setItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setItemText(index, text);
	}
	RETURNvoid_();
}

//void QComboBox.setLineEdit(QLineEdit edit);
KMETHOD QComboBox_setLineEdit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QLineEdit*  edit = RawPtr_to(QLineEdit*, sfp[1]);
		qp->setLineEdit(edit);
	}
	RETURNvoid_();
}

//void QComboBox.setMaxCount(int max);
KMETHOD QComboBox_setMaxCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int max = Int_to(int, sfp[1]);
		qp->setMaxCount(max);
	}
	RETURNvoid_();
}

//void QComboBox.setMaxVisibleItems(int maxItems);
KMETHOD QComboBox_setMaxVisibleItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int maxItems = Int_to(int, sfp[1]);
		qp->setMaxVisibleItems(maxItems);
	}
	RETURNvoid_();
}

//void QComboBox.setMinimumContentsLength(int characters);
KMETHOD QComboBox_setMinimumContentsLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int characters = Int_to(int, sfp[1]);
		qp->setMinimumContentsLength(characters);
	}
	RETURNvoid_();
}

//void QComboBox.setModel(QAbstractItemModel model);
KMETHOD QComboBox_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//void QComboBox.setModelColumn(int visibleColumn);
KMETHOD QComboBox_setModelColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int visibleColumn = Int_to(int, sfp[1]);
		qp->setModelColumn(visibleColumn);
	}
	RETURNvoid_();
}

//void QComboBox.setRootModelIndex(QModelIndex index);
KMETHOD QComboBox_setRootModelIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootModelIndex(index);
	}
	RETURNvoid_();
}

//void QComboBox.setSizeAdjustPolicy(int policy);
KMETHOD QComboBox_setSizeAdjustPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QComboBox::SizeAdjustPolicy policy = Int_to(QComboBox::SizeAdjustPolicy, sfp[1]);
		qp->setSizeAdjustPolicy(policy);
	}
	RETURNvoid_();
}

//void QComboBox.setValidator(QValidator validator);
KMETHOD QComboBox_setValidator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QValidator*  validator = RawPtr_to(const QValidator*, sfp[1]);
		qp->setValidator(validator);
	}
	RETURNvoid_();
}

//void QComboBox.setView(QAbstractItemView itemView);
KMETHOD QComboBox_setView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QAbstractItemView*  itemView = RawPtr_to(QAbstractItemView*, sfp[1]);
		qp->setView(itemView);
	}
	RETURNvoid_();
}

//@Virtual void QComboBox.showPopup();
KMETHOD QComboBox_showPopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		qp->showPopup();
	}
	RETURNvoid_();
}

//int QComboBox.getSizeAdjustPolicy();
KMETHOD QComboBox_getSizeAdjustPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QComboBox::SizeAdjustPolicy ret_v = qp->sizeAdjustPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QValidator QComboBox.getValidator();
KMETHOD QComboBox_getValidator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QValidator* ret_v = qp->validator();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QValidator*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemView QComboBox.getView();
KMETHOD QComboBox_getView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		QAbstractItemView* ret_v = qp->view();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemView*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QComboBox.clear();
KMETHOD QComboBox_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QComboBox.clearEditText();
KMETHOD QComboBox_clearEditText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		qp->clearEditText();
	}
	RETURNvoid_();
}

//void QComboBox.setCurrentIndex(int index);
KMETHOD QComboBox_setCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->setCurrentIndex(index);
	}
	RETURNvoid_();
}

//void QComboBox.setEditText(String text);
KMETHOD QComboBox_setEditText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QComboBox *  qp = RawPtr_to(QComboBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setEditText(text);
	}
	RETURNvoid_();
}


DummyQComboBox::DummyQComboBox()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	edit_text_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("edit-text-changed", NULL));
}
DummyQComboBox::~DummyQComboBox()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQComboBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQComboBox::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQComboBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQComboBox::editTextChangedSlot(const QString text)
{
	if (edit_text_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, text);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, edit_text_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQComboBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQComboBox::event_map->bigin();
	if ((itr = DummyQComboBox::event_map->find(str)) == DummyQComboBox::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQComboBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQComboBox::slot_map->bigin();
	if ((itr = DummyQComboBox::slot_map->find(str)) == DummyQComboBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		edit_text_changed_func = (*slot_map)["edit-text-changed"];
		return true;
	}
}

knh_Object_t** DummyQComboBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQComboBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, edit_text_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQComboBox::connection(QObject *o)
{
	QComboBox *p = dynamic_cast<QComboBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(editTextChanged(const QString)), this, SLOT(editTextChangedSlot(const QString)));
	}
	DummyQWidget::connection(o);
}

KQComboBox::KQComboBox(QWidget* parent) : QComboBox(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQComboBox();
	dummy->connection((QObject*)this);
}

KQComboBox::~KQComboBox()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QComboBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQComboBox *qp = RawPtr_to(KQComboBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QComboBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QComboBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QComboBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQComboBox *qp = RawPtr_to(KQComboBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QComboBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QComboBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QComboBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQComboBox *qp = (KQComboBox *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QComboBox*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QComboBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQComboBox *qp = (KQComboBox *)p->rawptr;
		KQComboBox *qp = static_cast<KQComboBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QComboBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQComboBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQComboBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QComboBox::event(event);
		return false;
	}
//	QComboBox::event(event);
	return true;
}

static knh_IntData_t QComboBoxConstInt[] = {
	{"NoInsert", QComboBox::NoInsert},
	{"InsertAtTop", QComboBox::InsertAtTop},
	{"InsertAtCurrent", QComboBox::InsertAtCurrent},
	{"InsertAtBottom", QComboBox::InsertAtBottom},
	{"InsertAfterCurrent", QComboBox::InsertAfterCurrent},
	{"InsertBeforeCurrent", QComboBox::InsertBeforeCurrent},
//	{"InsertAlphabetically", QComboBox::InsertAlphabetically},
	{"AdjustToContents", QComboBox::AdjustToContents},
	{"AdjustToContentsOnFirstShow", QComboBox::AdjustToContentsOnFirstShow},
	{"AdjustToMinimumContentsLength", QComboBox::AdjustToMinimumContentsLength},
	{"AdjustToMinimumContentsLengthWithIcon", QComboBox::AdjustToMinimumContentsLengthWithIcon},
	{NULL, 0}
};

DEFAPI(void) constQComboBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QComboBoxConstInt);
}


DEFAPI(void) defQComboBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QComboBox";
	cdef->free = QComboBox_free;
	cdef->reftrace = QComboBox_reftrace;
	cdef->compareTo = QComboBox_compareTo;
}


