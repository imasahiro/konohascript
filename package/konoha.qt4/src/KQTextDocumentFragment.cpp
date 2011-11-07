//QTextDocumentFragment QTextDocumentFragment.new();
KMETHOD QTextDocumentFragment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocumentFragment *ret_v = new KQTextDocumentFragment();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextDocumentFragment QTextDocumentFragment.new(QTextDocument document);
KMETHOD QTextDocumentFragment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextDocument*  document = RawPtr_to(const QTextDocument*, sfp[1]);
	KQTextDocumentFragment *ret_v = new KQTextDocumentFragment(document);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextDocumentFragment QTextDocumentFragment.new(QTextCursor cursor);
KMETHOD QTextDocumentFragment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
	KQTextDocumentFragment *ret_v = new KQTextDocumentFragment(cursor);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextDocumentFragment QTextDocumentFragment.new(QTextDocumentFragment other);
KMETHOD QTextDocumentFragment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextDocumentFragment  other = *RawPtr_to(const QTextDocumentFragment *, sfp[1]);
	KQTextDocumentFragment *ret_v = new KQTextDocumentFragment(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QTextDocumentFragment.isEmpty();
KMETHOD QTextDocumentFragment_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentFragment *  qp = RawPtr_to(QTextDocumentFragment *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QTextDocumentFragment.toHtml(QByteArray encoding);
KMETHOD QTextDocumentFragment_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentFragment *  qp = RawPtr_to(QTextDocumentFragment *, sfp[0]);
	if (qp) {
		const QByteArray  encoding = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = qp->toHtml(encoding);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QTextDocumentFragment.toHtml();
KMETHOD QTextDocumentFragment_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentFragment *  qp = RawPtr_to(QTextDocumentFragment *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toHtml();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//String QTextDocumentFragment.toPlainText();
KMETHOD QTextDocumentFragment_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentFragment *  qp = RawPtr_to(QTextDocumentFragment *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextDocumentFragment QTextDocumentFragment.fromHtml(String text);
KMETHOD QTextDocumentFragment_fromHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString text = String_to(const QString, sfp[1]);
		QTextDocumentFragment ret_v = QTextDocumentFragment::fromHtml(text);
		QTextDocumentFragment *ret_v_ = new QTextDocumentFragment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextDocumentFragment QTextDocumentFragment.fromHtml(String text, QTextDocument resourceProvider);
KMETHOD QTextDocumentFragment_fromHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString text = String_to(const QString, sfp[1]);
		const QTextDocument*  resourceProvider = RawPtr_to(const QTextDocument*, sfp[2]);
		QTextDocumentFragment ret_v = QTextDocumentFragment::fromHtml(text, resourceProvider);
		QTextDocumentFragment *ret_v_ = new QTextDocumentFragment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextDocumentFragment QTextDocumentFragment.fromPlainText(String plainText);
KMETHOD QTextDocumentFragment_fromPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString plainText = String_to(const QString, sfp[1]);
		QTextDocumentFragment ret_v = QTextDocumentFragment::fromPlainText(plainText);
		QTextDocumentFragment *ret_v_ = new QTextDocumentFragment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QTextDocumentFragment.parents();
KMETHOD QTextDocumentFragment_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentFragment *qp = RawPtr_to(QTextDocumentFragment*, sfp[0]);
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

DummyQTextDocumentFragment::DummyQTextDocumentFragment()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextDocumentFragment::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextDocumentFragment::self = ptr;
}

bool DummyQTextDocumentFragment::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextDocumentFragment::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocumentFragment::event_map->bigin();
	if ((itr = DummyQTextDocumentFragment::event_map->find(str)) == DummyQTextDocumentFragment::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextDocumentFragment::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocumentFragment::slot_map->bigin();
	if ((itr = DummyQTextDocumentFragment::slot_map->find(str)) == DummyQTextDocumentFragment::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextDocumentFragment::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQTextDocumentFragment::connection(QObject *o)
{
	QTextDocumentFragment *p = dynamic_cast<QTextDocumentFragment*>(o);
	if (p != NULL) {
	}
}

KQTextDocumentFragment::KQTextDocumentFragment() : QTextDocumentFragment()
{
	self = NULL;
	dummy = new DummyQTextDocumentFragment();
}

KMETHOD QTextDocumentFragment_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocumentFragment *qp = RawPtr_to(KQTextDocumentFragment *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDocumentFragment]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocumentFragment]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextDocumentFragment_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocumentFragment *qp = RawPtr_to(KQTextDocumentFragment *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDocumentFragment]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocumentFragment]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextDocumentFragment_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextDocumentFragment *qp = (KQTextDocumentFragment *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextDocumentFragment_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextDocumentFragment *qp = (KQTextDocumentFragment *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextDocumentFragment_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextDocumentFragment::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextDocumentFragment(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextDocumentFragment";
	cdef->free = QTextDocumentFragment_free;
	cdef->reftrace = QTextDocumentFragment_reftrace;
	cdef->compareTo = QTextDocumentFragment_compareTo;
}


