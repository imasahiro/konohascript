//@Virtual @Override void QMessageBox.setVisible(boolean visible);
KMETHOD QMessageBox_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QMessageBox QMessageBox.new(QWidget parent);
KMETHOD QMessageBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQMessageBox *ret_v = new KQMessageBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMessageBox QMessageBox.new(int icon, String title, String text, QMessageBoxStandardButtons buttons, QWidget parent, QtWindowFlags f);
KMETHOD QMessageBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox::Icon icon = Int_to(QMessageBox::Icon, sfp[1]);
	const QString title = String_to(const QString, sfp[2]);
	const QString text = String_to(const QString, sfp[3]);
	initFlag(buttons, QMessageBox::StandardButtons, sfp[4]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[5]);
	initFlag(f, Qt::WindowFlags, sfp[6]);
	KQMessageBox *ret_v = new KQMessageBox(icon, title, text, buttons, parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QMessageBox.addButton(QAbstractButton button, int role);
KMETHOD QMessageBox_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		QMessageBox::ButtonRole role = Int_to(QMessageBox::ButtonRole, sfp[2]);
		qp->addButton(button, role);
	}
	RETURNvoid_();
}

/*
//QPushButton QMessageBox.addButton(String text, int role);
KMETHOD QMessageBox_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		QMessageBox::ButtonRole role = Int_to(QMessageBox::ButtonRole, sfp[2]);
		QPushButton* ret_v = qp->addButton(text, role);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPushButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPushButton QMessageBox.addButton(int button);
KMETHOD QMessageBox_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::StandardButton button = Int_to(QMessageBox::StandardButton, sfp[1]);
		QPushButton* ret_v = qp->addButton(button);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPushButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QAbstractButton QMessageBox.button(int which);
KMETHOD QMessageBox_button(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::StandardButton which = Int_to(QMessageBox::StandardButton, sfp[1]);
		QAbstractButton* ret_v = qp->button(which);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMessageBox.buttonRole(QAbstractButton button);
KMETHOD QMessageBox_buttonRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		QMessageBox::ButtonRole ret_v = qp->buttonRole(button);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QAbstractButton> QMessageBox.buttons();
KMETHOD QMessageBox_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QList<QAbstractButton*> ret_v = qp->buttons();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAbstractButton"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QAbstractButton QMessageBox.clickedButton();
KMETHOD QMessageBox_clickedButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton* ret_v = qp->clickedButton();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPushButton QMessageBox.getDefaultButton();
KMETHOD QMessageBox_getDefaultButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QPushButton* ret_v = qp->defaultButton();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPushButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QMessageBox.getDetailedText();
KMETHOD QMessageBox_getDetailedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->detailedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractButton QMessageBox.getEscapeButton();
KMETHOD QMessageBox_getEscapeButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton* ret_v = qp->escapeButton();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMessageBox.getIcon();
KMETHOD QMessageBox_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::Icon ret_v = qp->icon();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPixmap QMessageBox.getIconPixmap();
KMETHOD QMessageBox_getIconPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QPixmap ret_v = qp->iconPixmap();
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QMessageBox.getInformativeText();
KMETHOD QMessageBox_getInformativeText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->informativeText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMessageBox.open(QObject receiver, String member);
KMETHOD QMessageBox_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//void QMessageBox.removeButton(QAbstractButton button);
KMETHOD QMessageBox_removeButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		qp->removeButton(button);
	}
	RETURNvoid_();
}

//void QMessageBox.setDefaultButton(QPushButton button);
KMETHOD QMessageBox_setDefaultButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QPushButton*  button = RawPtr_to(QPushButton*, sfp[1]);
		qp->setDefaultButton(button);
	}
	RETURNvoid_();
}

/*
//void QMessageBox.setDefaultButton(int button);
KMETHOD QMessageBox_setDefaultButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::StandardButton button = Int_to(QMessageBox::StandardButton, sfp[1]);
		qp->setDefaultButton(button);
	}
	RETURNvoid_();
}
*/
//void QMessageBox.setDetailedText(String text);
KMETHOD QMessageBox_setDetailedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setDetailedText(text);
	}
	RETURNvoid_();
}

//void QMessageBox.setEscapeButton(QAbstractButton button);
KMETHOD QMessageBox_setEscapeButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		qp->setEscapeButton(button);
	}
	RETURNvoid_();
}

/*
//void QMessageBox.setEscapeButton(int button);
KMETHOD QMessageBox_setEscapeButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::StandardButton button = Int_to(QMessageBox::StandardButton, sfp[1]);
		qp->setEscapeButton(button);
	}
	RETURNvoid_();
}
*/
//void QMessageBox.setIcon(int arg0);
KMETHOD QMessageBox_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::Icon arg0 = Int_to(QMessageBox::Icon, sfp[1]);
		qp->setIcon(arg0);
	}
	RETURNvoid_();
}

//void QMessageBox.setIconPixmap(QPixmap pixmap);
KMETHOD QMessageBox_setIconPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		qp->setIconPixmap(pixmap);
	}
	RETURNvoid_();
}

//void QMessageBox.setInformativeText(String text);
KMETHOD QMessageBox_setInformativeText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setInformativeText(text);
	}
	RETURNvoid_();
}

//void QMessageBox.setStandardButtons(QMessageBoxStandardButtons buttons);
KMETHOD QMessageBox_setStandardButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		initFlag(buttons, QMessageBox::StandardButtons, sfp[1]);
		qp->setStandardButtons(buttons);
	}
	RETURNvoid_();
}

//void QMessageBox.setText(String text);
KMETHOD QMessageBox_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//void QMessageBox.setTextFormat(int fmt);
KMETHOD QMessageBox_setTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		Qt::TextFormat format = Int_to(Qt::TextFormat, sfp[1]);
		qp->setTextFormat(format);
	}
	RETURNvoid_();
}

//void QMessageBox.setWindowModality(int windowModality);
KMETHOD QMessageBox_setWindowModality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		Qt::WindowModality windowModality = Int_to(Qt::WindowModality, sfp[1]);
		qp->setWindowModality(windowModality);
	}
	RETURNvoid_();
}

//void QMessageBox.setWindowTitle(String title);
KMETHOD QMessageBox_setWindowTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setWindowTitle(title);
	}
	RETURNvoid_();
}

//int QMessageBox.standardButton(QAbstractButton button);
KMETHOD QMessageBox_standardButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		QMessageBox::StandardButton ret_v = qp->standardButton(button);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMessageBoxStandardButtons QMessageBox.getStandardButtons();
KMETHOD QMessageBox_getStandardButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QMessageBox::StandardButtons ret_v = qp->standardButtons();
		QMessageBox::StandardButtons *ret_v_ = new QMessageBox::StandardButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QMessageBox.getText();
KMETHOD QMessageBox_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMessageBox.getTextFormat();
KMETHOD QMessageBox_getTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		Qt::TextFormat ret_v = qp->textFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QMessageBox.about(QWidget parent, String title, String text);
KMETHOD QMessageBox_about(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		QMessageBox::about(parent, title, text);
	}
	RETURNvoid_();
}

//void QMessageBox.aboutQt(QWidget parent, String title);
KMETHOD QMessageBox_aboutQt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		QMessageBox::aboutQt(parent, title);
	}
	RETURNvoid_();
}

//int QMessageBox.critical(QWidget parent, String title, String text, QMessageBoxStandardButtons buttons, int defaultButton);
KMETHOD QMessageBox_critical(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		initFlag(buttons, QMessageBox::StandardButtons, sfp[4]);
		QMessageBox::StandardButton defaultButton = Int_to(QMessageBox::StandardButton, sfp[5]);
		QMessageBox::StandardButton ret_v = QMessageBox::critical(parent, title, text, buttons, defaultButton);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMessageBox.information(QWidget parent, String title, String text, QMessageBoxStandardButtons buttons, int defaultButton);
KMETHOD QMessageBox_information(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		initFlag(buttons, QMessageBox::StandardButtons, sfp[4]);
		QMessageBox::StandardButton defaultButton = Int_to(QMessageBox::StandardButton, sfp[5]);
		QMessageBox::StandardButton ret_v = QMessageBox::information(parent, title, text, buttons, defaultButton);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMessageBox.question(QWidget parent, String title, String text, QMessageBoxStandardButtons buttons, int defaultButton);
KMETHOD QMessageBox_question(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		initFlag(buttons, QMessageBox::StandardButtons, sfp[4]);
		QMessageBox::StandardButton defaultButton = Int_to(QMessageBox::StandardButton, sfp[5]);
		QMessageBox::StandardButton ret_v = QMessageBox::question(parent, title, text, buttons, defaultButton);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMessageBox.warning(QWidget parent, String title, String text, QMessageBoxStandardButtons buttons, int defaultButton);
KMETHOD QMessageBox_warning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		initFlag(buttons, QMessageBox::StandardButtons, sfp[4]);
		QMessageBox::StandardButton defaultButton = Int_to(QMessageBox::StandardButton, sfp[5]);
		QMessageBox::StandardButton ret_v = QMessageBox::warning(parent, title, text, buttons, defaultButton);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMessageBox.exec();
KMETHOD QMessageBox_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox *  qp = RawPtr_to(QMessageBox *, sfp[0]);
	if (qp) {
		int ret_v = qp->exec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQMessageBox::DummyQMessageBox()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	button_clicked_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("button-clicked", NULL));
}
DummyQMessageBox::~DummyQMessageBox()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQMessageBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMessageBox::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQMessageBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMessageBox::buttonClickedSlot(QAbstractButton* button)
{
	if (button_clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QAbstractButton, button);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, button_clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMessageBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMessageBox::event_map->bigin();
	if ((itr = DummyQMessageBox::event_map->find(str)) == DummyQMessageBox::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMessageBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMessageBox::slot_map->bigin();
	if ((itr = DummyQMessageBox::slot_map->find(str)) == DummyQMessageBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		button_clicked_func = (*slot_map)["button-clicked"];
		return true;
	}
}

knh_Object_t** DummyQMessageBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMessageBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, button_clicked_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQMessageBox::connection(QObject *o)
{
	QMessageBox *p = dynamic_cast<QMessageBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonClickedSlot(QAbstractButton*)));
	}
	DummyQDialog::connection(o);
}

KQMessageBox::KQMessageBox(QWidget* parent) : QMessageBox(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQMessageBox();
	dummy->connection((QObject*)this);
}

KQMessageBox::~KQMessageBox()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QMessageBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMessageBox *qp = RawPtr_to(KQMessageBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMessageBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMessageBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMessageBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMessageBox *qp = RawPtr_to(KQMessageBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMessageBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMessageBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMessageBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQMessageBox *qp = (KQMessageBox *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QMessageBox*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QMessageBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQMessageBox *qp = (KQMessageBox *)p->rawptr;
		KQMessageBox *qp = static_cast<KQMessageBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMessageBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMessageBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMessageBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMessageBox::event(event);
		return false;
	}
//	QMessageBox::event(event);
	return true;
}

static knh_IntData_t QMessageBoxConstInt[] = {
	{"InvalidRole", QMessageBox::InvalidRole},
	{"AcceptRole", QMessageBox::AcceptRole},
	{"RejectRole", QMessageBox::RejectRole},
	{"DestructiveRole", QMessageBox::DestructiveRole},
	{"ActionRole", QMessageBox::ActionRole},
	{"HelpRole", QMessageBox::HelpRole},
	{"YesRole", QMessageBox::YesRole},
	{"NoRole", QMessageBox::NoRole},
	{"ApplyRole", QMessageBox::ApplyRole},
	{"ResetRole", QMessageBox::ResetRole},
	{"NoIcon", QMessageBox::NoIcon},
	{"Question", QMessageBox::Question},
	{"Information", QMessageBox::Information},
	{"Warning", QMessageBox::Warning},
	{"Critical", QMessageBox::Critical},
	{"Ok", QMessageBox::Ok},
	{"Open", QMessageBox::Open},
	{"Save", QMessageBox::Save},
	{"Cancel", QMessageBox::Cancel},
	{"Close", QMessageBox::Close},
	{"Discard", QMessageBox::Discard},
	{"Apply", QMessageBox::Apply},
	{"Reset", QMessageBox::Reset},
	{"RestoreDefaults", QMessageBox::RestoreDefaults},
	{"Help", QMessageBox::Help},
	{"SaveAll", QMessageBox::SaveAll},
	{"Yes", QMessageBox::Yes},
	{"YesToAll", QMessageBox::YesToAll},
	{"No", QMessageBox::No},
	{"NoToAll", QMessageBox::NoToAll},
	{"Abort", QMessageBox::Abort},
	{"Retry", QMessageBox::Retry},
	{"Ignore", QMessageBox::Ignore},
	{"NoButton", QMessageBox::NoButton},
	{"YesAll", QMessageBox::YesAll},
	{"NoAll", QMessageBox::NoAll},
	{"Default", QMessageBox::Default},
	{"Escape", QMessageBox::Escape},
	{"FlagMask", QMessageBox::FlagMask},
	{"ButtonMask", QMessageBox::ButtonMask},
	{NULL, 0}
};

DEFAPI(void) constQMessageBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMessageBoxConstInt);
}


DEFAPI(void) defQMessageBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMessageBox";
	cdef->free = QMessageBox_free;
	cdef->reftrace = QMessageBox_reftrace;
	cdef->compareTo = QMessageBox_compareTo;
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.new(int value);
KMETHOD QMessageBoxStandardButtons_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButton i = Int_to(QMessageBox::StandardButton, sfp[1]);
	QMessageBox::StandardButtons *ret_v = new QMessageBox::StandardButtons(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.and(int mask);
KMETHOD QMessageBoxStandardButtons_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QMessageBox::StandardButtons ret = ((*qp) & i);
		QMessageBox::StandardButtons *ret_ = new QMessageBox::StandardButtons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.iand(QMessageBox::QMessageBoxStandardButtons other);
KMETHOD QMessageBoxStandardButtons_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons*, sfp[0]);
	if (qp != NULL) {
		QMessageBox::StandardButtons *other = RawPtr_to(QMessageBox::StandardButtons *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.or(QMessageBoxStandardButtons f);
KMETHOD QMessageBoxStandardButtons_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons*, sfp[0]);
	if (qp != NULL) {
		QMessageBox::StandardButtons *f = RawPtr_to(QMessageBox::StandardButtons*, sfp[1]);
		QMessageBox::StandardButtons ret = ((*qp) | (*f));
		QMessageBox::StandardButtons *ret_ = new QMessageBox::StandardButtons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.ior(QMessageBox::QMessageBoxStandardButtons other);
KMETHOD QMessageBoxStandardButtons_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons*, sfp[0]);
	if (qp != NULL) {
		QMessageBox::StandardButtons *other = RawPtr_to(QMessageBox::StandardButtons *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.xor(QMessageBoxStandardButtons f);
KMETHOD QMessageBoxStandardButtons_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons*, sfp[0]);
	if (qp != NULL) {
		QMessageBox::StandardButtons *f = RawPtr_to(QMessageBox::StandardButtons*, sfp[1]);
		QMessageBox::StandardButtons ret = ((*qp) ^ (*f));
		QMessageBox::StandardButtons *ret_ = new QMessageBox::StandardButtons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMessageBoxStandardButtons QMessageBoxStandardButtons.ixor(QMessageBox::QMessageBoxStandardButtons other);
KMETHOD QMessageBoxStandardButtons_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons*, sfp[0]);
	if (qp != NULL) {
		QMessageBox::StandardButtons *other = RawPtr_to(QMessageBox::StandardButtons *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QMessageBoxStandardButtons.testFlag(int flag);
KMETHOD QMessageBoxStandardButtons_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons *, sfp[0]);
	if (qp != NULL) {
		QMessageBox::StandardButton flag = Int_to(QMessageBox::StandardButton, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QMessageBoxStandardButtons.value();
KMETHOD QMessageBoxStandardButtons_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMessageBox::StandardButtons *qp = RawPtr_to(QMessageBox::StandardButtons *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QMessageBoxStandardButtons_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QMessageBox::StandardButtons *qp = (QMessageBox::StandardButtons *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QMessageBoxStandardButtons_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QMessageBox::StandardButtons *qp = (QMessageBox::StandardButtons *)p->rawptr;
		(void)qp;
	}
}

static int QMessageBoxStandardButtons_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QMessageBox::StandardButtons*)p1->rawptr);
//		int v2 = int(*(QMessageBox::StandardButtons*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QMessageBox::StandardButtons v1 = *(QMessageBox::StandardButtons*)p1->rawptr;
		QMessageBox::StandardButtons v2 = *(QMessageBox::StandardButtons*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQMessageBoxStandardButtons(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMessageBoxStandardButtons";
	cdef->free = QMessageBoxStandardButtons_free;
	cdef->reftrace = QMessageBoxStandardButtons_reftrace;
	cdef->compareTo = QMessageBoxStandardButtons_compareTo;
}

