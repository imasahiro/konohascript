//@Virtual @Override void QWizard.setVisible(boolean visible);
KMETHOD QWizard_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QWizard.sizeHint();
KMETHOD QWizard_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWizard QWizard.new(QWidget parent, QtWindowFlags flags);
KMETHOD QWizard_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(flags, Qt::WindowFlags, sfp[2]);
	KQWizard *ret_v = new KQWizard(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QWizard.addPage(QWizardPage page);
KMETHOD QWizard_addPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizardPage*  page = RawPtr_to(QWizardPage*, sfp[1]);
		int ret_v = qp->addPage(page);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAbstractButton QWizard.getButton(int which);
KMETHOD QWizard_getButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardButton which = Int_to(QWizard::WizardButton, sfp[1]);
		QAbstractButton* ret_v = qp->button(which);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWizard.getButtonText(int which);
KMETHOD QWizard_getButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardButton which = Int_to(QWizard::WizardButton, sfp[1]);
		QString ret_v = qp->buttonText(which);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWizard.currentId();
KMETHOD QWizard_currentId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWizardPage QWizard.currentPage();
KMETHOD QWizard_currentPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizardPage* ret_v = qp->currentPage();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWizardPage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QWizard.getField(String name);
KMETHOD QWizard_getField(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		QVariant ret_v = qp->field(name);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWizard.hasVisitedPage(int id);
KMETHOD QWizard_hasVisitedPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		bool ret_v = qp->hasVisitedPage(id);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QWizard.nextId();
KMETHOD QWizard_nextId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int ret_v = qp->nextId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWizardWizardOptions QWizard.getOptions();
KMETHOD QWizard_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardOptions ret_v = qp->options();
		QWizard::WizardOptions *ret_v_ = new QWizard::WizardOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWizardPage QWizard.getPage(int id);
KMETHOD QWizard_getPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		QWizardPage* ret_v = qp->page(id);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWizardPage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<int> QWizard.pageIds();
KMETHOD QWizard_pageIds(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QList<int> ret_v = qp->pageIds();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("int"));
		for (int n = 0; n < list_size; n++) {
			int *ret_v_ = new int(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QPixmap QWizard.getPixmap(int which);
KMETHOD QWizard_getPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardPixmap which = Int_to(QWizard::WizardPixmap, sfp[1]);
		QPixmap ret_v = qp->pixmap(which);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWizard.removePage(int id);
KMETHOD QWizard_removePage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		qp->removePage(id);
	}
	RETURNvoid_();
}

//void QWizard.setButton(int which, QAbstractButton button);
KMETHOD QWizard_setButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardButton which = Int_to(QWizard::WizardButton, sfp[1]);
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[2]);
		qp->setButton(which, button);
	}
	RETURNvoid_();
}

//void QWizard.setButtonLayout(Array<int> layout);
KMETHOD QWizard_setButtonLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QWizard::WizardButton> layout;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			layout.append(*(QWizard::WizardButton*)p->rawptr);
		}
		qp->setButtonLayout(layout);
	}
	RETURNvoid_();
}

//void QWizard.setButtonText(int which, String text);
KMETHOD QWizard_setButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardButton which = Int_to(QWizard::WizardButton, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setButtonText(which, text);
	}
	RETURNvoid_();
}

//void QWizard.setDefaultProperty(String className, String property, String changedSignal);
KMETHOD QWizard_setDefaultProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		const char*  className = RawPtr_to(const char*, sfp[1]);
		const char*  property = RawPtr_to(const char*, sfp[2]);
		const char*  changedSignal = RawPtr_to(const char*, sfp[3]);
		qp->setDefaultProperty(className, property, changedSignal);
	}
	RETURNvoid_();
}

//void QWizard.setField(String name, QVariant value);
KMETHOD QWizard_setField(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setField(name, value);
	}
	RETURNvoid_();
}

//void QWizard.setOption(int option, boolean on);
KMETHOD QWizard_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardOption option = Int_to(QWizard::WizardOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QWizard.setOptions(QWizardWizardOptions options);
KMETHOD QWizard_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		initFlag(options, QWizard::WizardOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//void QWizard.setPage(int id, QWizardPage page);
KMETHOD QWizard_setPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		QWizardPage*  page = RawPtr_to(QWizardPage*, sfp[2]);
		qp->setPage(id, page);
	}
	RETURNvoid_();
}

//void QWizard.setPixmap(int which, QPixmap pixmap);
KMETHOD QWizard_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardPixmap which = Int_to(QWizard::WizardPixmap, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		qp->setPixmap(which, pixmap);
	}
	RETURNvoid_();
}

//void QWizard.setSideWidget(QWidget widget);
KMETHOD QWizard_setSideWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setSideWidget(widget);
	}
	RETURNvoid_();
}

//void QWizard.setStartId(int id);
KMETHOD QWizard_setStartId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		qp->setStartId(id);
	}
	RETURNvoid_();
}

//void QWizard.setSubTitleFormat(int fmt);
KMETHOD QWizard_setSubTitleFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		Qt::TextFormat format = Int_to(Qt::TextFormat, sfp[1]);
		qp->setSubTitleFormat(format);
	}
	RETURNvoid_();
}

//void QWizard.setTitleFormat(int fmt);
KMETHOD QWizard_setTitleFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		Qt::TextFormat format = Int_to(Qt::TextFormat, sfp[1]);
		qp->setTitleFormat(format);
	}
	RETURNvoid_();
}

//void QWizard.setWizardStyle(int style);
KMETHOD QWizard_setWizardStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardStyle style = Int_to(QWizard::WizardStyle, sfp[1]);
		qp->setWizardStyle(style);
	}
	RETURNvoid_();
}

//QWidget QWizard.getSideWidget();
KMETHOD QWizard_getSideWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->sideWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWizard.getStartId();
KMETHOD QWizard_getStartId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		int ret_v = qp->startId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWizard.getSubTitleFormat();
KMETHOD QWizard_getSubTitleFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		Qt::TextFormat ret_v = qp->subTitleFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QWizard.testOption(int option);
KMETHOD QWizard_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardOption option = Int_to(QWizard::WizardOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QWizard.getTitleFormat();
KMETHOD QWizard_getTitleFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		Qt::TextFormat ret_v = qp->titleFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual boolean QWizard.validateCurrentPage();
KMETHOD QWizard_validateCurrentPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		bool ret_v = qp->validateCurrentPage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<int> QWizard.visitedPages();
KMETHOD QWizard_visitedPages(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QList<int> ret_v = qp->visitedPages();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("int"));
		for (int n = 0; n < list_size; n++) {
			int *ret_v_ = new int(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QWizard.getWizardStyle();
KMETHOD QWizard_getWizardStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		QWizard::WizardStyle ret_v = qp->wizardStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QWizard.back();
KMETHOD QWizard_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		qp->back();
	}
	RETURNvoid_();
}

//void QWizard.next();
KMETHOD QWizard_next(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		qp->next();
	}
	RETURNvoid_();
}

//void QWizard.restart();
KMETHOD QWizard_restart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard *  qp = RawPtr_to(QWizard *, sfp[0]);
	if (qp) {
		qp->restart();
	}
	RETURNvoid_();
}


DummyQWizard::DummyQWizard()
{
	self = NULL;
	current_id_changed_func = NULL;
	custom_button_clicked_func = NULL;
	help_requested_func = NULL;
	page_added_func = NULL;
	page_removed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-id-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("custom-button-clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("help-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("page-added", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("page-removed", NULL));
}

void DummyQWizard::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWizard::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQWizard::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWizard::currentIdChangedSlot(int id)
{
	if (current_id_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		knh_Func_invoke(lctx, current_id_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWizard::customButtonClickedSlot(int which)
{
	if (custom_button_clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = which;
		knh_Func_invoke(lctx, custom_button_clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWizard::helpRequestedSlot()
{
	if (help_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, help_requested_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWizard::pageAddedSlot(int id)
{
	if (page_added_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		knh_Func_invoke(lctx, page_added_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWizard::pageRemovedSlot(int id)
{
	if (page_removed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		knh_Func_invoke(lctx, page_removed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWizard::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWizard::event_map->bigin();
	if ((itr = DummyQWizard::event_map->find(str)) == DummyQWizard::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWizard::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWizard::slot_map->bigin();
	if ((itr = DummyQWizard::slot_map->find(str)) == DummyQWizard::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_id_changed_func = (*slot_map)["current-id-changed"];
		custom_button_clicked_func = (*slot_map)["custom-button-clicked"];
		help_requested_func = (*slot_map)["help-requested"];
		page_added_func = (*slot_map)["page-added"];
		page_removed_func = (*slot_map)["page-removed"];
		return true;
	}
}

knh_Object_t** DummyQWizard::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWizard::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, current_id_changed_func);
	KNH_ADDNNREF(ctx, custom_button_clicked_func);
	KNH_ADDNNREF(ctx, help_requested_func);
	KNH_ADDNNREF(ctx, page_added_func);
	KNH_ADDNNREF(ctx, page_removed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWizard::connection(QObject *o)
{
	QWizard *p = dynamic_cast<QWizard*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(currentIdChanged(int)), this, SLOT(currentIdChangedSlot(int)));
		connect(p, SIGNAL(customButtonClicked(int)), this, SLOT(customButtonClickedSlot(int)));
		connect(p, SIGNAL(helpRequested()), this, SLOT(helpRequestedSlot()));
		connect(p, SIGNAL(pageAdded(int)), this, SLOT(pageAddedSlot(int)));
		connect(p, SIGNAL(pageRemoved(int)), this, SLOT(pageRemovedSlot(int)));
	}
	DummyQDialog::connection(o);
}

KQWizard::KQWizard(QWidget* parent, Qt::WindowFlags flags) : QWizard(parent, flags)
{
	self = NULL;
	dummy = new DummyQWizard();
	dummy->connection((QObject*)this);
}

KMETHOD QWizard_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWizard *qp = RawPtr_to(KQWizard *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWizard]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWizard]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWizard_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWizard *qp = RawPtr_to(KQWizard *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWizard]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWizard]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWizard_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWizard *qp = (KQWizard *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWizard_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWizard *qp = (KQWizard *)p->rawptr;
//		KQWizard *qp = static_cast<KQWizard*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWizard_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWizard::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWizard::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWizard::event(event);
		return false;
	}
//	QWizard::event(event);
	return true;
}

static knh_IntData_t QWizardConstInt[] = {
	{"BackButton", QWizard::BackButton},
	{"NextButton", QWizard::NextButton},
	{"CommitButton", QWizard::CommitButton},
	{"FinishButton", QWizard::FinishButton},
	{"CancelButton", QWizard::CancelButton},
	{"HelpButton", QWizard::HelpButton},
	{"CustomButton1", QWizard::CustomButton1},
	{"CustomButton2", QWizard::CustomButton2},
	{"CustomButton3", QWizard::CustomButton3},
	{"Stretch", QWizard::Stretch},
	{"IndependentPages", QWizard::IndependentPages},
	{"IgnoreSubTitles", QWizard::IgnoreSubTitles},
	{"ExtendedWatermarkPixmap", QWizard::ExtendedWatermarkPixmap},
	{"NoDefaultButton", QWizard::NoDefaultButton},
	{"NoBackButtonOnStartPage", QWizard::NoBackButtonOnStartPage},
	{"NoBackButtonOnLastPage", QWizard::NoBackButtonOnLastPage},
	{"DisabledBackButtonOnLastPage", QWizard::DisabledBackButtonOnLastPage},
	{"HaveNextButtonOnLastPage", QWizard::HaveNextButtonOnLastPage},
	{"HaveFinishButtonOnEarlyPages", QWizard::HaveFinishButtonOnEarlyPages},
	{"NoCancelButton", QWizard::NoCancelButton},
	{"CancelButtonOnLeft", QWizard::CancelButtonOnLeft},
	{"HaveHelpButton", QWizard::HaveHelpButton},
	{"HelpButtonOnRight", QWizard::HelpButtonOnRight},
	{"HaveCustomButton1", QWizard::HaveCustomButton1},
	{"HaveCustomButton2", QWizard::HaveCustomButton2},
	{"HaveCustomButton3", QWizard::HaveCustomButton3},
	{"WatermarkPixmap", QWizard::WatermarkPixmap},
	{"LogoPixmap", QWizard::LogoPixmap},
	{"BannerPixmap", QWizard::BannerPixmap},
	{"BackgroundPixmap", QWizard::BackgroundPixmap},
	{"ClassicStyle", QWizard::ClassicStyle},
	{"ModernStyle", QWizard::ModernStyle},
	{"MacStyle", QWizard::MacStyle},
	{"AeroStyle", QWizard::AeroStyle},
	{NULL, 0}
};

DEFAPI(void) constQWizard(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWizardConstInt);
}


DEFAPI(void) defQWizard(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWizard";
	cdef->free = QWizard_free;
	cdef->reftrace = QWizard_reftrace;
	cdef->compareTo = QWizard_compareTo;
}

//## QWizardWizardOptions QWizardWizardOptions.new(int value);
KMETHOD QWizardWizardOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOption i = Int_to(QWizard::WizardOption, sfp[1]);
	QWizard::WizardOptions *ret_v = new QWizard::WizardOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QWizardWizardOptions QWizardWizardOptions.and(int mask);
KMETHOD QWizardWizardOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QWizard::WizardOptions ret = ((*qp) & i);
		QWizard::WizardOptions *ret_ = new QWizard::WizardOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWizardWizardOptions QWizardWizardOptions.iand(QWizard::QWizardWizardOptions other);
KMETHOD QWizardWizardOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions*, sfp[0]);
	if (qp != NULL) {
		QWizard::WizardOptions *other = RawPtr_to(QWizard::WizardOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWizardWizardOptions QWizardWizardOptions.or(QWizardWizardOptions f);
KMETHOD QWizardWizardOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions*, sfp[0]);
	if (qp != NULL) {
		QWizard::WizardOptions *f = RawPtr_to(QWizard::WizardOptions*, sfp[1]);
		QWizard::WizardOptions ret = ((*qp) | (*f));
		QWizard::WizardOptions *ret_ = new QWizard::WizardOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWizardWizardOptions QWizardWizardOptions.ior(QWizard::QWizardWizardOptions other);
KMETHOD QWizardWizardOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions*, sfp[0]);
	if (qp != NULL) {
		QWizard::WizardOptions *other = RawPtr_to(QWizard::WizardOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWizardWizardOptions QWizardWizardOptions.xor(QWizardWizardOptions f);
KMETHOD QWizardWizardOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions*, sfp[0]);
	if (qp != NULL) {
		QWizard::WizardOptions *f = RawPtr_to(QWizard::WizardOptions*, sfp[1]);
		QWizard::WizardOptions ret = ((*qp) ^ (*f));
		QWizard::WizardOptions *ret_ = new QWizard::WizardOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWizardWizardOptions QWizardWizardOptions.ixor(QWizard::QWizardWizardOptions other);
KMETHOD QWizardWizardOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions*, sfp[0]);
	if (qp != NULL) {
		QWizard::WizardOptions *other = RawPtr_to(QWizard::WizardOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QWizardWizardOptions.testFlag(int flag);
KMETHOD QWizardWizardOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions *, sfp[0]);
	if (qp != NULL) {
		QWizard::WizardOption flag = Int_to(QWizard::WizardOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QWizardWizardOptions.value();
KMETHOD QWizardWizardOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWizard::WizardOptions *qp = RawPtr_to(QWizard::WizardOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QWizardWizardOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QWizard::WizardOptions *qp = (QWizard::WizardOptions *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QWizardWizardOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QWizard::WizardOptions *qp = (QWizard::WizardOptions *)p->rawptr;
		(void)qp;
	}
}

static int QWizardWizardOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QWizard::WizardOptions*)p1->rawptr);
//		int v2 = int(*(QWizard::WizardOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QWizard::WizardOptions v1 = *(QWizard::WizardOptions*)p1->rawptr;
		QWizard::WizardOptions v2 = *(QWizard::WizardOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQWizardWizardOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWizardWizardOptions";
	cdef->free = QWizardWizardOptions_free;
	cdef->reftrace = QWizardWizardOptions_reftrace;
	cdef->compareTo = QWizardWizardOptions_compareTo;
}

