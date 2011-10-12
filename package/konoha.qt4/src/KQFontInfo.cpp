//QFontInfo QFontInfo.new(QFont font);
KMETHOD QFontInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	KQFontInfo *ret_v = new KQFontInfo(font);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QFontInfo QFontInfo.new(QFontInfo fi);
KMETHOD QFontInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFontInfo  fi = *RawPtr_to(const QFontInfo *, sfp[1]);
	KQFontInfo *ret_v = new KQFontInfo(fi);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QFontInfo.bold();
KMETHOD QFontInfo_bold(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->bold();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontInfo.exactMatch();
KMETHOD QFontInfo_exactMatch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->exactMatch();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QFontInfo.family();
KMETHOD QFontInfo_family(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->family();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QFontInfo.fixedPitch();
KMETHOD QFontInfo_fixedPitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fixedPitch();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontInfo.italic();
KMETHOD QFontInfo_italic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->italic();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFontInfo.pixelSize();
KMETHOD QFontInfo_pixelSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pixelSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontInfo.pointSize();
KMETHOD QFontInfo_pointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pointSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QFontInfo.pointSizeF();
KMETHOD QFontInfo_pointSizeF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->pointSizeF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QFontInfo.rawMode();
KMETHOD QFontInfo_rawMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->rawMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFontInfo.style();
KMETHOD QFontInfo_style(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		QFont::Style ret_v = qp->style();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontInfo.styleHint();
KMETHOD QFontInfo_styleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleHint ret_v = qp->styleHint();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontInfo.weight();
KMETHOD QFontInfo_weight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontInfo *  qp = RawPtr_to(QFontInfo *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->weight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQFontInfo::DummyQFontInfo()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFontInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontInfo::self = ptr;
}

bool DummyQFontInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQFontInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontInfo::event_map->bigin();
	if ((itr = DummyQFontInfo::event_map->find(str)) == DummyQFontInfo::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontInfo::slot_map->bigin();
	if ((itr = DummyQFontInfo::event_map->find(str)) == DummyQFontInfo::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQFontInfo::KQFontInfo(const QFont font) : QFontInfo(font)
{
	self = NULL;
}

KMETHOD QFontInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontInfo *qp = RawPtr_to(KQFontInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQFontInfo::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QFontInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontInfo *qp = RawPtr_to(KQFontInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQFontInfo::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFontInfo *qp = (KQFontInfo *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFontInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQFontInfo *qp = (KQFontInfo *)p->rawptr;
		(void)qp;
	}
}

static int QFontInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQFontInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontInfo";
	cdef->free = QFontInfo_free;
	cdef->reftrace = QFontInfo_reftrace;
	cdef->compareTo = QFontInfo_compareTo;
}


