//QFont QToolTip.getFont();
KMETHOD QToolTip_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QFont ret_v = QToolTip::font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QToolTip.hideText();
KMETHOD QToolTip_hideText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QToolTip::hideText();
	}
	RETURNvoid_();
}

//boolean QToolTip.isVisible();
KMETHOD QToolTip_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QToolTip::isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPalette QToolTip.getPalette();
KMETHOD QToolTip_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QPalette ret_v = QToolTip::palette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QToolTip.setFont(QFont font);
KMETHOD QToolTip_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		QToolTip::setFont(font);
	}
	RETURNvoid_();
}

//void QToolTip.setPalette(QPalette palette);
KMETHOD QToolTip_setPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPalette  palette = *RawPtr_to(const QPalette *, sfp[1]);
		QToolTip::setPalette(palette);
	}
	RETURNvoid_();
}

//void QToolTip.showText(QPoint pos, String text, QWidget w, QRect rect);
KMETHOD QToolTip_showText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		QWidget*  w = RawPtr_to(QWidget*, sfp[3]);
		const QRect  rect = *RawPtr_to(const QRect *, sfp[4]);
		QToolTip::showText(pos, text, w, rect);
	}
	RETURNvoid_();
}

/*
//void QToolTip.showText(QPoint pos, String text, QWidget w);
KMETHOD QToolTip_showText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		QWidget*  w = RawPtr_to(QWidget*, sfp[3]);
		QToolTip::showText(pos, text, w);
	}
	RETURNvoid_();
}
*/
//String QToolTip.text();
KMETHOD QToolTip_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QToolTip::text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QToolTip.parents();
KMETHOD QToolTip_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolTip *qp = RawPtr_to(QToolTip*, sfp[0]);
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

DummyQToolTip::DummyQToolTip()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQToolTip::setSelf(knh_RawPtr_t *ptr)
{
	DummyQToolTip::self = ptr;
}

bool DummyQToolTip::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQToolTip::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolTip::event_map->bigin();
	if ((itr = DummyQToolTip::event_map->find(str)) == DummyQToolTip::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQToolTip::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolTip::slot_map->bigin();
	if ((itr = DummyQToolTip::slot_map->find(str)) == DummyQToolTip::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQToolTip::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQToolTip::connection(QObject *o)
{
	QToolTip *p = dynamic_cast<QToolTip*>(o);
	if (p != NULL) {
	}
}

KMETHOD QToolTip_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolTip *qp = RawPtr_to(KQToolTip *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QToolTip]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolTip]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QToolTip_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolTip *qp = RawPtr_to(KQToolTip *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QToolTip]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolTip]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QToolTip_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQToolTip *qp = (KQToolTip *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QToolTip_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQToolTip *qp = (KQToolTip *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QToolTip_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQToolTip::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQToolTip(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QToolTip";
	cdef->free = QToolTip_free;
	cdef->reftrace = QToolTip_reftrace;
	cdef->compareTo = QToolTip_compareTo;
}


