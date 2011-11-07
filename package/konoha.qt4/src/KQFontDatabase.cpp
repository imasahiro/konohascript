//QFontDatabase QFontDatabase.new();
KMETHOD QFontDatabase_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontDatabase *ret_v = new KQFontDatabase();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QFontDatabase.bold(String family, String style);
KMETHOD QFontDatabase_bold(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		bool ret_v = qp->bold(family, style);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QFont QFontDatabase.font(String family, String style, int pointSize);
KMETHOD QFontDatabase_font(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		int pointSize = Int_to(int, sfp[3]);
		QFont ret_v = qp->font(family, style, pointSize);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QFontDatabase.isBitmapScalable(String family, String style);
KMETHOD QFontDatabase_isBitmapScalable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		bool ret_v = qp->isBitmapScalable(family, style);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontDatabase.isFixedPitch(String family, String style);
KMETHOD QFontDatabase_isFixedPitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		bool ret_v = qp->isFixedPitch(family, style);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontDatabase.isScalable(String family, String style);
KMETHOD QFontDatabase_isScalable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		bool ret_v = qp->isScalable(family, style);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontDatabase.isSmoothlyScalable(String family, String style);
KMETHOD QFontDatabase_isSmoothlyScalable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		bool ret_v = qp->isSmoothlyScalable(family, style);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontDatabase.italic(String family, String style);
KMETHOD QFontDatabase_italic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		bool ret_v = qp->italic(family, style);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<int> QFontDatabase.pointSizes(String family, String style);
KMETHOD QFontDatabase_pointSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		QList<int> ret_v = qp->pointSizes(family, style);
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
	

//Array<int> QFontDatabase.smoothSizes(String family, String style);
KMETHOD QFontDatabase_smoothSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		QList<int> ret_v = qp->smoothSizes(family, style);
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
	

//String QFontDatabase.styleString(QFont font);
KMETHOD QFontDatabase_styleString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		QString ret_v = qp->styleString(font);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QFontDatabase.styleString(QFontInfo fontInfo);
KMETHOD QFontDatabase_styleString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QFontInfo  fontInfo = *RawPtr_to(const QFontInfo *, sfp[1]);
		QString ret_v = qp->styleString(fontInfo);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QFontDatabase.weight(String family, String style);
KMETHOD QFontDatabase_weight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		const QString style = String_to(const QString, sfp[2]);
		int ret_v = qp->weight(family, style);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<int> QFontDatabase.writingSystems();
KMETHOD QFontDatabase_writingSystems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		QList<QFontDatabase::WritingSystem> ret_v = qp->writingSystems();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QFontDatabase::WritingSystem"));
		for (int n = 0; n < list_size; n++) {
			QFontDatabase::WritingSystem *ret_v_ = new QFontDatabase::WritingSystem(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

/*
//Array<int> QFontDatabase.writingSystems(String family);
KMETHOD QFontDatabase_writingSystems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *  qp = RawPtr_to(QFontDatabase *, sfp[0]);
	if (qp) {
		const QString family = String_to(const QString, sfp[1]);
		QList<QFontDatabase::WritingSystem> ret_v = qp->writingSystems(family);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QFontDatabase::WritingSystem"));
		for (int n = 0; n < list_size; n++) {
			QFontDatabase::WritingSystem *ret_v_ = new QFontDatabase::WritingSystem(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
//int QFontDatabase.addApplicationFont(String fileName);
KMETHOD QFontDatabase_addApplicationFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString fileName = String_to(const QString, sfp[1]);
		int ret_v = QFontDatabase::addApplicationFont(fileName);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontDatabase.addApplicationFontFromData(QByteArray fontData);
KMETHOD QFontDatabase_addApplicationFontFromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  fontData = *RawPtr_to(const QByteArray *, sfp[1]);
		int ret_v = QFontDatabase::addApplicationFontFromData(fontData);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QFontDatabase.removeAllApplicationFonts();
KMETHOD QFontDatabase_removeAllApplicationFonts(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QFontDatabase::removeAllApplicationFonts();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFontDatabase.removeApplicationFont(int id);
KMETHOD QFontDatabase_removeApplicationFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int id = Int_to(int, sfp[1]);
		bool ret_v = QFontDatabase::removeApplicationFont(id);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<int> QFontDatabase.standardSizes();
KMETHOD QFontDatabase_standardSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<int> ret_v = QFontDatabase::standardSizes();
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
	

//boolean QFontDatabase.supportsThreadedFontRendering();
KMETHOD QFontDatabase_supportsThreadedFontRendering(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QFontDatabase::supportsThreadedFontRendering();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QFontDatabase.writingSystemName(int writingSystem);
KMETHOD QFontDatabase_writingSystemName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QFontDatabase::WritingSystem writingSystem = Int_to(QFontDatabase::WritingSystem, sfp[1]);
		QString ret_v = QFontDatabase::writingSystemName(writingSystem);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QFontDatabase.writingSystemSample(int writingSystem);
KMETHOD QFontDatabase_writingSystemSample(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QFontDatabase::WritingSystem writingSystem = Int_to(QFontDatabase::WritingSystem, sfp[1]);
		QString ret_v = QFontDatabase::writingSystemSample(writingSystem);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QFontDatabase.parents();
KMETHOD QFontDatabase_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDatabase *qp = RawPtr_to(QFontDatabase*, sfp[0]);
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

DummyQFontDatabase::DummyQFontDatabase()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFontDatabase::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontDatabase::self = ptr;
}

bool DummyQFontDatabase::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQFontDatabase::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontDatabase::event_map->bigin();
	if ((itr = DummyQFontDatabase::event_map->find(str)) == DummyQFontDatabase::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontDatabase::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontDatabase::slot_map->bigin();
	if ((itr = DummyQFontDatabase::slot_map->find(str)) == DummyQFontDatabase::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQFontDatabase::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQFontDatabase::connection(QObject *o)
{
	QFontDatabase *p = dynamic_cast<QFontDatabase*>(o);
	if (p != NULL) {
	}
}

KQFontDatabase::KQFontDatabase() : QFontDatabase()
{
	self = NULL;
	dummy = new DummyQFontDatabase();
}

KMETHOD QFontDatabase_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontDatabase *qp = RawPtr_to(KQFontDatabase *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontDatabase]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontDatabase]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFontDatabase_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontDatabase *qp = RawPtr_to(KQFontDatabase *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontDatabase]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontDatabase]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontDatabase_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFontDatabase *qp = (KQFontDatabase *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFontDatabase_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQFontDatabase *qp = (KQFontDatabase *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFontDatabase_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFontDatabase::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QFontDatabaseConstInt[] = {
	{"Any", QFontDatabase::Any},
	{"Latin", QFontDatabase::Latin},
	{"Greek", QFontDatabase::Greek},
	{"Cyrillic", QFontDatabase::Cyrillic},
	{"Armenian", QFontDatabase::Armenian},
	{"Hebrew", QFontDatabase::Hebrew},
	{"Arabic", QFontDatabase::Arabic},
	{"Syriac", QFontDatabase::Syriac},
	{"Thaana", QFontDatabase::Thaana},
	{"Devanagari", QFontDatabase::Devanagari},
	{"Bengali", QFontDatabase::Bengali},
	{"Gurmukhi", QFontDatabase::Gurmukhi},
	{"Gujarati", QFontDatabase::Gujarati},
	{"Oriya", QFontDatabase::Oriya},
	{"Tamil", QFontDatabase::Tamil},
	{"Telugu", QFontDatabase::Telugu},
	{"Kannada", QFontDatabase::Kannada},
	{"Malayalam", QFontDatabase::Malayalam},
	{"Sinhala", QFontDatabase::Sinhala},
	{"Thai", QFontDatabase::Thai},
	{"Lao", QFontDatabase::Lao},
	{"Tibetan", QFontDatabase::Tibetan},
	{"Myanmar", QFontDatabase::Myanmar},
	{"Georgian", QFontDatabase::Georgian},
	{"Khmer", QFontDatabase::Khmer},
	{"SimplifiedChinese", QFontDatabase::SimplifiedChinese},
	{"TraditionalChinese", QFontDatabase::TraditionalChinese},
	{"Japanese", QFontDatabase::Japanese},
	{"Korean", QFontDatabase::Korean},
	{"Vietnamese", QFontDatabase::Vietnamese},
	{"Symbol", QFontDatabase::Symbol},
	{"Other", QFontDatabase::Other},
	{"Ogham", QFontDatabase::Ogham},
	{"Runic", QFontDatabase::Runic},
	{"Nko", QFontDatabase::Nko},
	{NULL, 0}
};

DEFAPI(void) constQFontDatabase(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFontDatabaseConstInt);
}


DEFAPI(void) defQFontDatabase(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontDatabase";
	cdef->free = QFontDatabase_free;
	cdef->reftrace = QFontDatabase_reftrace;
	cdef->compareTo = QFontDatabase_compareTo;
}


