//QKeySequence QKeySequence.new();
KMETHOD QKeySequence_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeySequence *ret_v = new KQKeySequence();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QKeySequence QKeySequence.new(String key);
KMETHOD QKeySequence_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString key = String_to(const QString, sfp[1]);
	KQKeySequence *ret_v = new KQKeySequence(key);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QKeySequence QKeySequence.new(String key, int fmt);
KMETHOD QKeySequence_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString key = String_to(const QString, sfp[1]);
	QKeySequence::SequenceFormat format = Int_to(QKeySequence::SequenceFormat, sfp[2]);
	KQKeySequence *ret_v = new KQKeySequence(key, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QKeySequence QKeySequence.new(int k1, int k2, int k3, int k4);
KMETHOD QKeySequence_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int k1 = Int_to(int, sfp[1]);
	int k2 = Int_to(int, sfp[2]);
	int k3 = Int_to(int, sfp[3]);
	int k4 = Int_to(int, sfp[4]);
	KQKeySequence *ret_v = new KQKeySequence(k1, k2, k3, k4);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QKeySequence QKeySequence.new(QKeySequence keysequence);
KMETHOD QKeySequence_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QKeySequence  keysequence = *RawPtr_to(const QKeySequence *, sfp[1]);
	KQKeySequence *ret_v = new KQKeySequence(keysequence);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QKeySequence QKeySequence.new(int key);
KMETHOD QKeySequence_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeySequence::StandardKey key = Int_to(QKeySequence::StandardKey, sfp[1]);
	KQKeySequence *ret_v = new KQKeySequence(key);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QKeySequence.count();
KMETHOD QKeySequence_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeySequence *  qp = RawPtr_to(QKeySequence *, sfp[0]);
	if (qp) {
		uint ret_v = qp->count();
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QKeySequence.isEmpty();
KMETHOD QKeySequence_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeySequence *  qp = RawPtr_to(QKeySequence *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QKeySequence.matches(QKeySequence seq);
KMETHOD QKeySequence_matches(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeySequence *  qp = RawPtr_to(QKeySequence *, sfp[0]);
	if (qp) {
		const QKeySequence  seq = *RawPtr_to(const QKeySequence *, sfp[1]);
		QKeySequence::SequenceMatch ret_v = qp->matches(seq);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QKeySequence.toString(int fmt);
KMETHOD QKeySequence_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeySequence *  qp = RawPtr_to(QKeySequence *, sfp[0]);
	if (qp) {
		QKeySequence::SequenceFormat format = Int_to(QKeySequence::SequenceFormat, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QKeySequence QKeySequence.fromString(String str, int fmt);
KMETHOD QKeySequence_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString str = String_to(const QString, sfp[1]);
		QKeySequence::SequenceFormat format = Int_to(QKeySequence::SequenceFormat, sfp[2]);
		QKeySequence ret_v = QKeySequence::fromString(str, format);
		QKeySequence *ret_v_ = new QKeySequence(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QKeySequence> QKeySequence.keyBindings(int key);
KMETHOD QKeySequence_keyBindings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QKeySequence::StandardKey key = Int_to(QKeySequence::StandardKey, sfp[1]);
		QList<QKeySequence> ret_v = QKeySequence::keyBindings(key);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QKeySequence"));
		for (int n = 0; n < list_size; n++) {
			QKeySequence *ret_v_ = new QKeySequence(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QKeySequence QKeySequence.mnemonic(String text);
KMETHOD QKeySequence_mnemonic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString text = String_to(const QString, sfp[1]);
		QKeySequence ret_v = QKeySequence::mnemonic(text);
		QKeySequence *ret_v_ = new QKeySequence(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QKeySequence.parents();
KMETHOD QKeySequence_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeySequence *qp = RawPtr_to(QKeySequence*, sfp[0]);
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

DummyQKeySequence::DummyQKeySequence()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQKeySequence::~DummyQKeySequence()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQKeySequence::setSelf(knh_RawPtr_t *ptr)
{
	DummyQKeySequence::self = ptr;
}

bool DummyQKeySequence::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQKeySequence::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQKeySequence::event_map->bigin();
	if ((itr = DummyQKeySequence::event_map->find(str)) == DummyQKeySequence::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQKeySequence::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQKeySequence::slot_map->bigin();
	if ((itr = DummyQKeySequence::slot_map->find(str)) == DummyQKeySequence::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQKeySequence::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQKeySequence::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQKeySequence::connection(QObject *o)
{
	QKeySequence *p = dynamic_cast<QKeySequence*>(o);
	if (p != NULL) {
	}
}

KQKeySequence::KQKeySequence() : QKeySequence()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQKeySequence();
}

KQKeySequence::~KQKeySequence()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QKeySequence_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeySequence *qp = RawPtr_to(KQKeySequence *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QKeySequence]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QKeySequence]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QKeySequence_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeySequence *qp = RawPtr_to(KQKeySequence *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QKeySequence]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QKeySequence]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QKeySequence_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQKeySequence *qp = (KQKeySequence *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QKeySequence*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QKeySequence_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQKeySequence *qp = (KQKeySequence *)p->rawptr;
		KQKeySequence *qp = static_cast<KQKeySequence*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QKeySequence_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QKeySequence*>(p1->rawptr) == *static_cast<QKeySequence*>(p2->rawptr) ? 0 : 1);
}

void KQKeySequence::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QKeySequenceConstInt[] = {
	{"NativeText", QKeySequence::NativeText},
	{"PortableText", QKeySequence::PortableText},
	{"NoMatch", QKeySequence::NoMatch},
	{"PartialMatch", QKeySequence::PartialMatch},
	{"ExactMatch", QKeySequence::ExactMatch},
	{"AddTab", QKeySequence::AddTab},
	{"Back", QKeySequence::Back},
	{"Bold", QKeySequence::Bold},
	{"Close", QKeySequence::Close},
	{"Copy", QKeySequence::Copy},
	{"Cut", QKeySequence::Cut},
	{"Delete", QKeySequence::Delete},
	{"DeleteEndOfLine", QKeySequence::DeleteEndOfLine},
	{"DeleteEndOfWord", QKeySequence::DeleteEndOfWord},
	{"DeleteStartOfWord", QKeySequence::DeleteStartOfWord},
	{"Find", QKeySequence::Find},
	{"FindNext", QKeySequence::FindNext},
	{"FindPrevious", QKeySequence::FindPrevious},
	{"Forward", QKeySequence::Forward},
	{"HelpContents", QKeySequence::HelpContents},
	{"InsertLineSeparator", QKeySequence::InsertLineSeparator},
	{"InsertParagraphSeparator", QKeySequence::InsertParagraphSeparator},
	{"Italic", QKeySequence::Italic},
	{"MoveToEndOfBlock", QKeySequence::MoveToEndOfBlock},
	{"MoveToEndOfDocument", QKeySequence::MoveToEndOfDocument},
	{"MoveToEndOfLine", QKeySequence::MoveToEndOfLine},
	{"MoveToNextChar", QKeySequence::MoveToNextChar},
	{"MoveToNextLine", QKeySequence::MoveToNextLine},
	{"MoveToNextPage", QKeySequence::MoveToNextPage},
	{"MoveToNextWord", QKeySequence::MoveToNextWord},
	{"MoveToPreviousChar", QKeySequence::MoveToPreviousChar},
	{"MoveToPreviousLine", QKeySequence::MoveToPreviousLine},
	{"MoveToPreviousPage", QKeySequence::MoveToPreviousPage},
	{"MoveToPreviousWord", QKeySequence::MoveToPreviousWord},
	{"MoveToStartOfBlock", QKeySequence::MoveToStartOfBlock},
	{"MoveToStartOfDocument", QKeySequence::MoveToStartOfDocument},
	{"MoveToStartOfLine", QKeySequence::MoveToStartOfLine},
	{"New", QKeySequence::New},
	{"NextChild", QKeySequence::NextChild},
	{"Open", QKeySequence::Open},
	{"Paste", QKeySequence::Paste},
	{"Preferences", QKeySequence::Preferences},
	{"PreviousChild", QKeySequence::PreviousChild},
	{"Print", QKeySequence::Print},
	{"Quit", QKeySequence::Quit},
	{"Redo", QKeySequence::Redo},
	{"Refresh", QKeySequence::Refresh},
	{"Replace", QKeySequence::Replace},
	{"SaveAs", QKeySequence::SaveAs},
	{"Save", QKeySequence::Save},
	{"SelectAll", QKeySequence::SelectAll},
	{"SelectEndOfBlock", QKeySequence::SelectEndOfBlock},
	{"SelectEndOfDocument", QKeySequence::SelectEndOfDocument},
	{"SelectEndOfLine", QKeySequence::SelectEndOfLine},
	{"SelectNextChar", QKeySequence::SelectNextChar},
	{"SelectNextLine", QKeySequence::SelectNextLine},
	{"SelectNextPage", QKeySequence::SelectNextPage},
	{"SelectNextWord", QKeySequence::SelectNextWord},
	{"SelectPreviousChar", QKeySequence::SelectPreviousChar},
	{"SelectPreviousLine", QKeySequence::SelectPreviousLine},
	{"SelectPreviousPage", QKeySequence::SelectPreviousPage},
	{"SelectPreviousWord", QKeySequence::SelectPreviousWord},
	{"SelectStartOfBlock", QKeySequence::SelectStartOfBlock},
	{"SelectStartOfDocument", QKeySequence::SelectStartOfDocument},
	{"SelectStartOfLine", QKeySequence::SelectStartOfLine},
	{"Underline", QKeySequence::Underline},
	{"Undo", QKeySequence::Undo},
	{"UnknownKey", QKeySequence::UnknownKey},
	{"WhatsThis", QKeySequence::WhatsThis},
	{"ZoomIn", QKeySequence::ZoomIn},
	{"ZoomOut", QKeySequence::ZoomOut},
	{NULL, 0}
};

DEFAPI(void) constQKeySequence(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QKeySequenceConstInt);
}


DEFAPI(void) defQKeySequence(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QKeySequence";
	cdef->free = QKeySequence_free;
	cdef->reftrace = QKeySequence_reftrace;
	cdef->compareTo = QKeySequence_compareTo;
}


