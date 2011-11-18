//@Virtual @Override QSize QFontComboBox.sizeHint();
KMETHOD QFontComboBox_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontComboBox QFontComboBox.new(QWidget parent);
KMETHOD QFontComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQFontComboBox *ret_v = new KQFontComboBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QFont QFontComboBox.getCurrentFont();
KMETHOD QFontComboBox_getCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->currentFont();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontComboBoxFontFilters QFontComboBox.getFontFilters();
KMETHOD QFontComboBox_getFontFilters(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		QFontComboBox::FontFilters ret_v = qp->fontFilters();
		QFontComboBox::FontFilters *ret_v_ = new QFontComboBox::FontFilters(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QFontComboBox.setFontFilters(QFontComboBoxFontFilters filters);
KMETHOD QFontComboBox_setFontFilters(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		initFlag(filters, QFontComboBox::FontFilters, sfp[1]);
		qp->setFontFilters(filters);
	}
	RETURNvoid_();
}

//void QFontComboBox.setWritingSystem(int script);
KMETHOD QFontComboBox_setWritingSystem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		QFontDatabase::WritingSystem script = Int_to(QFontDatabase::WritingSystem, sfp[1]);
		qp->setWritingSystem(script);
	}
	RETURNvoid_();
}

//int QFontComboBox.getWritingSystem();
KMETHOD QFontComboBox_getWritingSystem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		QFontDatabase::WritingSystem ret_v = qp->writingSystem();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFontComboBox.setCurrentFont(QFont font);
KMETHOD QFontComboBox_setCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setCurrentFont(font);
	}
	RETURNvoid_();
}


DummyQFontComboBox::DummyQFontComboBox()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	current_font_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-font-changed", NULL));
}
DummyQFontComboBox::~DummyQFontComboBox()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQFontComboBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontComboBox::self = ptr;
	DummyQComboBox::setSelf(ptr);
}

bool DummyQFontComboBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQComboBox::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFontComboBox::currentFontChangedSlot(const QFont font)
{
	if (current_font_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFont, font);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, current_font_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFontComboBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontComboBox::event_map->bigin();
	if ((itr = DummyQFontComboBox::event_map->find(str)) == DummyQFontComboBox::event_map->end()) {
		bool ret = false;
		ret = DummyQComboBox::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontComboBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontComboBox::slot_map->bigin();
	if ((itr = DummyQFontComboBox::slot_map->find(str)) == DummyQFontComboBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQComboBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_font_changed_func = (*slot_map)["current-font-changed"];
		return true;
	}
}

knh_Object_t** DummyQFontComboBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQFontComboBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, current_font_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQComboBox::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQFontComboBox::connection(QObject *o)
{
	QFontComboBox *p = dynamic_cast<QFontComboBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(currentFontChanged(const QFont)), this, SLOT(currentFontChangedSlot(const QFont)));
	}
	DummyQComboBox::connection(o);
}

KQFontComboBox::KQFontComboBox(QWidget* parent) : QFontComboBox(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQFontComboBox();
	dummy->connection((QObject*)this);
}

KQFontComboBox::~KQFontComboBox()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QFontComboBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontComboBox *qp = RawPtr_to(KQFontComboBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontComboBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontComboBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFontComboBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontComboBox *qp = RawPtr_to(KQFontComboBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontComboBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontComboBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontComboBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQFontComboBox *qp = (KQFontComboBox *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QFontComboBox*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QFontComboBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQFontComboBox *qp = (KQFontComboBox *)p->rawptr;
		KQFontComboBox *qp = static_cast<KQFontComboBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFontComboBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFontComboBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFontComboBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFontComboBox::event(event);
		return false;
	}
//	QFontComboBox::event(event);
	return true;
}

static knh_IntData_t QFontComboBoxConstInt[] = {
	{"AllFonts", QFontComboBox::AllFonts},
	{"ScalableFonts", QFontComboBox::ScalableFonts},
	{"NonScalableFonts", QFontComboBox::NonScalableFonts},
	{"MonospacedFonts", QFontComboBox::MonospacedFonts},
	{"ProportionalFonts", QFontComboBox::ProportionalFonts},
	{NULL, 0}
};

DEFAPI(void) constQFontComboBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFontComboBoxConstInt);
}


DEFAPI(void) defQFontComboBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontComboBox";
	cdef->free = QFontComboBox_free;
	cdef->reftrace = QFontComboBox_reftrace;
	cdef->compareTo = QFontComboBox_compareTo;
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.new(int value);
KMETHOD QFontComboBoxFontFilters_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilter i = Int_to(QFontComboBox::FontFilter, sfp[1]);
	QFontComboBox::FontFilters *ret_v = new QFontComboBox::FontFilters(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.and(int mask);
KMETHOD QFontComboBoxFontFilters_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QFontComboBox::FontFilters ret = ((*qp) & i);
		QFontComboBox::FontFilters *ret_ = new QFontComboBox::FontFilters(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.iand(QFontComboBox::QFontComboBoxFontFilters other);
KMETHOD QFontComboBoxFontFilters_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters*, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters *other = RawPtr_to(QFontComboBox::FontFilters *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.or(QFontComboBoxFontFilters f);
KMETHOD QFontComboBoxFontFilters_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters*, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters *f = RawPtr_to(QFontComboBox::FontFilters*, sfp[1]);
		QFontComboBox::FontFilters ret = ((*qp) | (*f));
		QFontComboBox::FontFilters *ret_ = new QFontComboBox::FontFilters(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.ior(QFontComboBox::QFontComboBoxFontFilters other);
KMETHOD QFontComboBoxFontFilters_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters*, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters *other = RawPtr_to(QFontComboBox::FontFilters *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.xor(QFontComboBoxFontFilters f);
KMETHOD QFontComboBoxFontFilters_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters*, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters *f = RawPtr_to(QFontComboBox::FontFilters*, sfp[1]);
		QFontComboBox::FontFilters ret = ((*qp) ^ (*f));
		QFontComboBox::FontFilters *ret_ = new QFontComboBox::FontFilters(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontComboBoxFontFilters QFontComboBoxFontFilters.ixor(QFontComboBox::QFontComboBoxFontFilters other);
KMETHOD QFontComboBoxFontFilters_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters*, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters *other = RawPtr_to(QFontComboBox::FontFilters *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QFontComboBoxFontFilters.testFlag(int flag);
KMETHOD QFontComboBoxFontFilters_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters *, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilter flag = Int_to(QFontComboBox::FontFilter, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QFontComboBoxFontFilters.value();
KMETHOD QFontComboBoxFontFilters_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontComboBox::FontFilters *qp = RawPtr_to(QFontComboBox::FontFilters *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QFontComboBoxFontFilters_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QFontComboBox::FontFilters *qp = (QFontComboBox::FontFilters *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QFontComboBoxFontFilters_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QFontComboBox::FontFilters *qp = (QFontComboBox::FontFilters *)p->rawptr;
		(void)qp;
	}
}

static int QFontComboBoxFontFilters_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QFontComboBox::FontFilters*)p1->rawptr);
//		int v2 = int(*(QFontComboBox::FontFilters*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QFontComboBox::FontFilters v1 = *(QFontComboBox::FontFilters*)p1->rawptr;
		QFontComboBox::FontFilters v2 = *(QFontComboBox::FontFilters*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQFontComboBoxFontFilters(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontComboBoxFontFilters";
	cdef->free = QFontComboBoxFontFilters_free;
	cdef->reftrace = QFontComboBoxFontFilters_reftrace;
	cdef->compareTo = QFontComboBoxFontFilters_compareTo;
}

