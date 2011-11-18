//@Virtual @Override int QLabel.heightForWidth(int w);
KMETHOD QLabel_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QSize QLabel.minimumSizeHint();
KMETHOD QLabel_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QLabel.sizeHint();
KMETHOD QLabel_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLabel QLabel.new(QWidget parent, QtWindowFlags f);
KMETHOD QLabel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(f, Qt::WindowFlags, sfp[2]);
	KQLabel *ret_v = new KQLabel(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLabel QLabel.new(String text, QWidget parent, QtWindowFlags f);
KMETHOD QLabel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	initFlag(f, Qt::WindowFlags, sfp[3]);
	KQLabel *ret_v = new KQLabel(text, parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QtAlignment QLabel.getAlignment();
KMETHOD QLabel_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QLabel.getBuddy();
KMETHOD QLabel_getBuddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->buddy();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLabel.hasScaledContents();
KMETHOD QLabel_hasScaledContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasScaledContents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLabel.hasSelectedText();
KMETHOD QLabel_hasSelectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasSelectedText();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLabel.getIndent();
KMETHOD QLabel_getIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int ret_v = qp->indent();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLabel.getMargin();
KMETHOD QLabel_getMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int ret_v = qp->margin();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMovie QLabel.getMovie();
KMETHOD QLabel_getMovie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QMovie* ret_v = qp->movie();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMovie*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLabel.getOpenExternalLinks();
KMETHOD QLabel_getOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->openExternalLinks();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPicture QLabel.getPicture();
KMETHOD QLabel_getPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		const QPicture* ret_v = qp->picture();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPicture*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QLabel.getPixmap();
KMETHOD QLabel_getPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		const QPixmap* ret_v = qp->pixmap();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPixmap*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLabel.selectedText();
KMETHOD QLabel_selectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QString ret_v = qp->selectedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLabel.selectionStart();
KMETHOD QLabel_selectionStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int ret_v = qp->selectionStart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLabel.setAlignment(QtAlignment arg0);
KMETHOD QLabel_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		initFlag(arg0, Qt::Alignment, sfp[1]);
		qp->setAlignment(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setBuddy(QWidget buddy);
KMETHOD QLabel_setBuddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QWidget*  buddy = RawPtr_to(QWidget*, sfp[1]);
		qp->setBuddy(buddy);
	}
	RETURNvoid_();
}

//void QLabel.setIndent(int arg0);
KMETHOD QLabel_setIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setIndent(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setMargin(int arg0);
KMETHOD QLabel_setMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setMargin(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setOpenExternalLinks(boolean open);
KMETHOD QLabel_setOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool open = Boolean_to(bool, sfp[1]);
		qp->setOpenExternalLinks(open);
	}
	RETURNvoid_();
}

//void QLabel.setScaledContents(boolean arg0);
KMETHOD QLabel_setScaledContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setScaledContents(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setSelection(int start, int length);
KMETHOD QLabel_setSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int start = Int_to(int, sfp[1]);
		int length = Int_to(int, sfp[2]);
		qp->setSelection(start, length);
	}
	RETURNvoid_();
}

//void QLabel.setTextFormat(int arg0);
KMETHOD QLabel_setTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		Qt::TextFormat arg0 = Int_to(Qt::TextFormat, sfp[1]);
		qp->setTextFormat(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setTextInteractionFlags(QtTextInteractionFlags flags);
KMETHOD QLabel_setTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		initFlag(flags, Qt::TextInteractionFlags, sfp[1]);
		qp->setTextInteractionFlags(flags);
	}
	RETURNvoid_();
}

//void QLabel.setWordWrap(boolean on);
KMETHOD QLabel_setWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setWordWrap(on);
	}
	RETURNvoid_();
}

//String QLabel.getText();
KMETHOD QLabel_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLabel.getTextFormat();
KMETHOD QLabel_getTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		Qt::TextFormat ret_v = qp->textFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtTextInteractionFlags QLabel.getTextInteractionFlags();
KMETHOD QLabel_getTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		Qt::TextInteractionFlags ret_v = qp->textInteractionFlags();
		Qt::TextInteractionFlags *ret_v_ = new Qt::TextInteractionFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLabel.getWordWrap();
KMETHOD QLabel_getWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wordWrap();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QLabel.clear();
KMETHOD QLabel_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QLabel.setMovie(QMovie movie);
KMETHOD QLabel_setMovie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		QMovie*  movie = RawPtr_to(QMovie*, sfp[1]);
		qp->setMovie(movie);
	}
	RETURNvoid_();
}

//void QLabel.setNum(int num);
KMETHOD QLabel_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		int num = Int_to(int, sfp[1]);
		qp->setNum(num);
	}
	RETURNvoid_();
}

/*
//void QLabel.setNum(double num);
KMETHOD QLabel_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		double  num = *RawPtr_to(double *, sfp[1]);
		qp->setNum(num);
	}
	RETURNvoid_();
}
*/
//void QLabel.setPicture(QPicture picture);
KMETHOD QLabel_setPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		const QPicture  picture = *RawPtr_to(const QPicture *, sfp[1]);
		qp->setPicture(picture);
	}
	RETURNvoid_();
}

//void QLabel.setPixmap(QPixmap arg0);
KMETHOD QLabel_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		const QPixmap  arg0 = *RawPtr_to(const QPixmap *, sfp[1]);
		qp->setPixmap(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setText(String arg0);
KMETHOD QLabel_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setText(arg0);
	}
	RETURNvoid_();
}


DummyQLabel::DummyQLabel()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	link_activated_func = NULL;
	link_hovered_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-activated", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-hovered", NULL));
}
DummyQLabel::~DummyQLabel()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQLabel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLabel::self = ptr;
	DummyQFrame::setSelf(ptr);
}

bool DummyQLabel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLabel::linkActivatedSlot(const QString link)
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

bool DummyQLabel::linkHoveredSlot(const QString link)
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

bool DummyQLabel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLabel::event_map->bigin();
	if ((itr = DummyQLabel::event_map->find(str)) == DummyQLabel::event_map->end()) {
		bool ret = false;
		ret = DummyQFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLabel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLabel::slot_map->bigin();
	if ((itr = DummyQLabel::slot_map->find(str)) == DummyQLabel::slot_map->end()) {
		bool ret = false;
		ret = DummyQFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		link_activated_func = (*slot_map)["link-activated"];
		link_hovered_func = (*slot_map)["link-hovered"];
		return true;
	}
}

knh_Object_t** DummyQLabel::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQLabel::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, link_activated_func);
	KNH_ADDNNREF(ctx, link_hovered_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQFrame::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQLabel::connection(QObject *o)
{
	QLabel *p = dynamic_cast<QLabel*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(linkActivated(const QString)), this, SLOT(linkActivatedSlot(const QString)));
		connect(p, SIGNAL(linkHovered(const QString)), this, SLOT(linkHoveredSlot(const QString)));
	}
	DummyQFrame::connection(o);
}

KQLabel::KQLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQLabel();
	dummy->connection((QObject*)this);
}

KQLabel::~KQLabel()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QLabel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLabel *qp = RawPtr_to(KQLabel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLabel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLabel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLabel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLabel *qp = RawPtr_to(KQLabel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLabel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLabel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLabel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQLabel *qp = (KQLabel *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QLabel*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QLabel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQLabel *qp = (KQLabel *)p->rawptr;
		KQLabel *qp = static_cast<KQLabel*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLabel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLabel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQLabel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QLabel::event(event);
		return false;
	}
//	QLabel::event(event);
	return true;
}



DEFAPI(void) defQLabel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLabel";
	cdef->free = QLabel_free;
	cdef->reftrace = QLabel_reftrace;
	cdef->compareTo = QLabel_compareTo;
}


