//QRegExp QRegExp.new();
KMETHOD QRegExp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegExp *ret_v = new KQRegExp();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRegExp QRegExp.new(String pattern, int cs, int syntax);
KMETHOD QRegExp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString pattern = String_to(const QString, sfp[1]);
	Qt::CaseSensitivity cs = Int_to(Qt::CaseSensitivity, sfp[2]);
	QRegExp::PatternSyntax syntax = Int_to(QRegExp::PatternSyntax, sfp[3]);
	KQRegExp *ret_v = new KQRegExp(pattern, cs, syntax);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRegExp QRegExp.new(QRegExp rx);
KMETHOD QRegExp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRegExp  rx = *RawPtr_to(const QRegExp *, sfp[1]);
	KQRegExp *ret_v = new KQRegExp(rx);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QRegExp.cap(int nth);
KMETHOD QRegExp_cap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		int nth = Int_to(int, sfp[1]);
		QString ret_v = qp->cap(nth);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QRegExp.captureCount();
KMETHOD QRegExp_captureCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->captureCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QRegExp.getCaseSensitivity();
KMETHOD QRegExp_getCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		Qt::CaseSensitivity ret_v = qp->caseSensitivity();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QRegExp.errorString();
KMETHOD QRegExp_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QRegExp.exactMatch(String str);
KMETHOD QRegExp_exactMatch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		const QString str = String_to(const QString, sfp[1]);
		bool ret_v = qp->exactMatch(str);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QRegExp.indexIn(String str, int offset, int caretMode);
KMETHOD QRegExp_indexIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		const QString str = String_to(const QString, sfp[1]);
		int offset = Int_to(int, sfp[2]);
		QRegExp::CaretMode caretMode = Int_to(QRegExp::CaretMode, sfp[3]);
		int ret_v = qp->indexIn(str, offset, caretMode);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QRegExp.isEmpty();
KMETHOD QRegExp_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QRegExp.isMinimal();
KMETHOD QRegExp_isMinimal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMinimal();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QRegExp.isValid();
KMETHOD QRegExp_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QRegExp.lastIndexIn(String str, int offset, int caretMode);
KMETHOD QRegExp_lastIndexIn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		const QString str = String_to(const QString, sfp[1]);
		int offset = Int_to(int, sfp[2]);
		QRegExp::CaretMode caretMode = Int_to(QRegExp::CaretMode, sfp[3]);
		int ret_v = qp->lastIndexIn(str, offset, caretMode);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QRegExp.matchedLength();
KMETHOD QRegExp_matchedLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->matchedLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QRegExp.getPattern();
KMETHOD QRegExp_getPattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->pattern();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QRegExp.getPatternSyntax();
KMETHOD QRegExp_getPatternSyntax(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		QRegExp::PatternSyntax ret_v = qp->patternSyntax();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QRegExp.pos(int nth);
KMETHOD QRegExp_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		int nth = Int_to(int, sfp[1]);
		int ret_v = qp->pos(nth);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QRegExp.setCaseSensitivity(int cs);
KMETHOD QRegExp_setCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		Qt::CaseSensitivity cs = Int_to(Qt::CaseSensitivity, sfp[1]);
		qp->setCaseSensitivity(cs);
	}
	RETURNvoid_();
}

//void QRegExp.setMinimal(boolean minimal);
KMETHOD QRegExp_setMinimal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		bool minimal = Boolean_to(bool, sfp[1]);
		qp->setMinimal(minimal);
	}
	RETURNvoid_();
}

//void QRegExp.setPattern(String pattern);
KMETHOD QRegExp_setPattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		const QString pattern = String_to(const QString, sfp[1]);
		qp->setPattern(pattern);
	}
	RETURNvoid_();
}

//void QRegExp.setPatternSyntax(int syntax);
KMETHOD QRegExp_setPatternSyntax(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		QRegExp::PatternSyntax syntax = Int_to(QRegExp::PatternSyntax, sfp[1]);
		qp->setPatternSyntax(syntax);
	}
	RETURNvoid_();
}

//String QRegExp.escape(String str);
KMETHOD QRegExp_escape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExp *  qp = RawPtr_to(QRegExp *, sfp[0]);
	if (qp != NULL) {
		const QString str = String_to(const QString, sfp[1]);
		QString ret_v = qp->escape(str);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQRegExp::DummyQRegExp()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRegExp::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRegExp::self = ptr;
}

bool DummyQRegExp::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQRegExp::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRegExp::event_map->bigin();
	if ((itr = DummyQRegExp::event_map->find(str)) == DummyQRegExp::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRegExp::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRegExp::slot_map->bigin();
	if ((itr = DummyQRegExp::slot_map->find(str)) == DummyQRegExp::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQRegExp::connection(QObject *o)
{
	return;
}

KQRegExp::KQRegExp() : QRegExp()
{
	self = NULL;
	dummy = new DummyQRegExp();
	dummy->connection((QObject*)this);
}

KMETHOD QRegExp_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegExp *qp = RawPtr_to(KQRegExp *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRegExp]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRegExp]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRegExp_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegExp *qp = RawPtr_to(KQRegExp *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRegExp]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRegExp]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRegExp_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRegExp *qp = (KQRegExp *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRegExp_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQRegExp *qp = (KQRegExp *)p->rawptr;
		(void)qp;
	}
}

static int QRegExp_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QRegExp*>(p1->rawptr) == *static_cast<QRegExp*>(p2->rawptr) ? 0 : 1);
}

void KQRegExp::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQRegExp(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRegExp";
	cdef->free = QRegExp_free;
	cdef->reftrace = QRegExp_reftrace;
	cdef->compareTo = QRegExp_compareTo;
}

static knh_IntData_t QRegExpConstInt[] = {
	{"CaretAtZero", QRegExp::CaretAtZero},
	{"CaretAtOffset", QRegExp::CaretAtOffset},
	{"CaretWontMatch", QRegExp::CaretWontMatch},
	{"RegExp", QRegExp::RegExp},
	{"RegExp2", QRegExp::RegExp2},
	{"Wildcard", QRegExp::Wildcard},
	{"WildcardUnix", QRegExp::WildcardUnix},
	{"FixedString", QRegExp::FixedString},
	{"W3CXmlSchema11", QRegExp::W3CXmlSchema11},
	{NULL, 0}
};

DEFAPI(void) constQRegExp(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QRegExpConstInt);
}
