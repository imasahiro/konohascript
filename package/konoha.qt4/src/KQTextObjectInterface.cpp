//@Virtual void QTextObjectInterface.drawObject(QPainter painter, QRectF rect, QTextDocument doc, int posInDocument, QTextFormat fmt);
KMETHOD QTextObjectInterface_drawObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextObjectInterface *  qp = RawPtr_to(QTextObjectInterface *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[2]);
		QTextDocument*  doc = RawPtr_to(QTextDocument*, sfp[3]);
		int posInDocument = Int_to(int, sfp[4]);
		const QTextFormat  format = *RawPtr_to(const QTextFormat *, sfp[5]);
		qp->drawObject(painter, rect, doc, posInDocument, format);
	}
	RETURNvoid_();
}

//@Virtual QSizeF QTextObjectInterface.intrinsicSize(QTextDocument doc, int posInDocument, QTextFormat fmt);
KMETHOD QTextObjectInterface_intrinsicSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextObjectInterface *  qp = RawPtr_to(QTextObjectInterface *, sfp[0]);
	if (qp != NULL) {
		QTextDocument*  doc = RawPtr_to(QTextDocument*, sfp[1]);
		int posInDocument = Int_to(int, sfp[2]);
		const QTextFormat  format = *RawPtr_to(const QTextFormat *, sfp[3]);
		QSizeF ret_v = qp->intrinsicSize(doc, posInDocument, format);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQTextObjectInterface::DummyQTextObjectInterface()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextObjectInterface::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextObjectInterface::self = ptr;
}

bool DummyQTextObjectInterface::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextObjectInterface::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextObjectInterface::event_map->bigin();
	if ((itr = DummyQTextObjectInterface::event_map->find(str)) == DummyQTextObjectInterface::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextObjectInterface::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextObjectInterface::slot_map->bigin();
	if ((itr = DummyQTextObjectInterface::event_map->find(str)) == DummyQTextObjectInterface::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextObjectInterface::KQTextObjectInterface() : QTextObjectInterface()
{
	self = NULL;
}

KMETHOD QTextObjectInterface_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextObjectInterface *qp = RawPtr_to(KQTextObjectInterface *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextObjectInterface]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextObjectInterface::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextObjectInterface]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextObjectInterface_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextObjectInterface *qp = RawPtr_to(KQTextObjectInterface *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextObjectInterface]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextObjectInterface::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextObjectInterface]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextObjectInterface_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextObjectInterface *qp = (KQTextObjectInterface *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextObjectInterface_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextObjectInterface *qp = (KQTextObjectInterface *)p->rawptr;
		(void)qp;
	}
}

static int QTextObjectInterface_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextObjectInterface(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextObjectInterface";
	cdef->free = QTextObjectInterface_free;
	cdef->reftrace = QTextObjectInterface_reftrace;
	cdef->compareTo = QTextObjectInterface_compareTo;
}


