//QIcon QIcon.new();
KMETHOD QIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIcon *ret_v = new KQIcon();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QIcon QIcon.new(QPixmap pixmap);
KMETHOD QIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	KQIcon *ret_v = new KQIcon(pixmap);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QIcon QIcon.new(QIcon other);
KMETHOD QIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QIcon  other = *RawPtr_to(const QIcon *, sfp[1]);
	KQIcon *ret_v = new KQIcon(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QIcon QIcon.new(String fileName);
KMETHOD QIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	KQIcon *ret_v = new KQIcon(fileName);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QIcon QIcon.new(QIconEngine engine);
KMETHOD QIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngine*  engine = RawPtr_to(QIconEngine*, sfp[1]);
	KQIcon *ret_v = new KQIcon(engine);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QIcon QIcon.new(QIconEngineV2 engine);
KMETHOD QIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngineV2*  engine = RawPtr_to(QIconEngineV2*, sfp[1]);
	KQIcon *ret_v = new KQIcon(engine);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QSize QIcon.actualSize(QSize size, int mode, int state);
KMETHOD QIcon_actualSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		QSize ret_v = qp->actualSize(size, mode, state);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QIcon.addFile(String fileName, QSize size, int mode, int state);
KMETHOD QIcon_addFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[3]);
		QIcon::State state = Int_to(QIcon::State, sfp[4]);
		qp->addFile(fileName, size, mode, state);
	}
	RETURNvoid_();
}

//void QIcon.addPixmap(QPixmap pixmap, int mode, int state);
KMETHOD QIcon_addPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		qp->addPixmap(pixmap, mode, state);
	}
	RETURNvoid_();
}

//Array<QSize> QIcon.availableSizes(int mode, int state);
KMETHOD QIcon_availableSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[1]);
		QIcon::State state = Int_to(QIcon::State, sfp[2]);
		QList<QSize> ret_v = qp->availableSizes(mode, state);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSize"));
		for (int n = 0; n < list_size; n++) {
			QSize *ret_v_ = new QSize(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QIcon.cacheKey();
KMETHOD QIcon_cacheKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->cacheKey();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QIcon.name();
KMETHOD QIcon_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QIcon.paint(QPainter painter, QRect rect, QtAlignment alignment, int mode, int state);
KMETHOD QIcon_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRect  rect = *RawPtr_to(const QRect *, sfp[2]);
		initFlag(alignment, Qt::Alignment, sfp[3]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[4]);
		QIcon::State state = Int_to(QIcon::State, sfp[5]);
		qp->paint(painter, rect, alignment, mode, state);
	}
	RETURNvoid_();
}

/*
//void QIcon.paint(QPainter painter, int x, int y, int w, int h, QtAlignment alignment, int mode, int state);
KMETHOD QIcon_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		int x = Int_to(int, sfp[2]);
		int y = Int_to(int, sfp[3]);
		int w = Int_to(int, sfp[4]);
		int h = Int_to(int, sfp[5]);
		initFlag(alignment, Qt::Alignment, sfp[6]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[7]);
		QIcon::State state = Int_to(QIcon::State, sfp[8]);
		qp->paint(painter, x, y, w, h, alignment, mode, state);
	}
	RETURNvoid_();
}
*/
//QPixmap QIcon.pixmap(QSize size, int mode, int state);
KMETHOD QIcon_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		QPixmap ret_v = qp->pixmap(size, mode, state);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPixmap QIcon.pixmap(int w, int h, int mode, int state);
KMETHOD QIcon_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[3]);
		QIcon::State state = Int_to(QIcon::State, sfp[4]);
		QPixmap ret_v = qp->pixmap(w, h, mode, state);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPixmap QIcon.pixmap(int extent, int mode, int state);
KMETHOD QIcon_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *  qp = RawPtr_to(QIcon *, sfp[0]);
	if (qp) {
		int extent = Int_to(int, sfp[1]);
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[2]);
		QIcon::State state = Int_to(QIcon::State, sfp[3]);
		QPixmap ret_v = qp->pixmap(extent, mode, state);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QIcon QIcon.fromTheme(String name, QIcon fallback);
KMETHOD QIcon_fromTheme(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		const QIcon  fallback = *RawPtr_to(const QIcon *, sfp[2]);
		QIcon ret_v = QIcon::fromTheme(name, fallback);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QIcon.hasThemeIcon(String name);
KMETHOD QIcon_hasThemeIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = QIcon::hasThemeIcon(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QIcon.setThemeName(String name);
KMETHOD QIcon_setThemeName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		QIcon::setThemeName(name);
	}
	RETURNvoid_();
}

//String QIcon.getThemeName();
KMETHOD QIcon_getThemeName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QIcon::themeName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QIcon.parents();
KMETHOD QIcon_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIcon *qp = RawPtr_to(QIcon*, sfp[0]);
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

DummyQIcon::DummyQIcon()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQIcon::setSelf(knh_RawPtr_t *ptr)
{
	DummyQIcon::self = ptr;
}

bool DummyQIcon::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQIcon::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIcon::event_map->bigin();
	if ((itr = DummyQIcon::event_map->find(str)) == DummyQIcon::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQIcon::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIcon::slot_map->bigin();
	if ((itr = DummyQIcon::slot_map->find(str)) == DummyQIcon::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQIcon::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQIcon::connection(QObject *o)
{
	QIcon *p = dynamic_cast<QIcon*>(o);
	if (p != NULL) {
	}
}

KQIcon::KQIcon() : QIcon()
{
	self = NULL;
	dummy = new DummyQIcon();
}

KMETHOD QIcon_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIcon *qp = RawPtr_to(KQIcon *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QIcon]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIcon]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QIcon_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIcon *qp = RawPtr_to(KQIcon *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QIcon]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIcon]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIcon_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQIcon *qp = (KQIcon *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QIcon_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQIcon *qp = (KQIcon *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QIcon_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQIcon::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QIconConstInt[] = {
	{"Normal", QIcon::Normal},
	{"Disabled", QIcon::Disabled},
	{"Active", QIcon::Active},
	{"Selected", QIcon::Selected},
	{"Off", QIcon::Off},
	{"On", QIcon::On},
	{NULL, 0}
};

DEFAPI(void) constQIcon(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QIconConstInt);
}


DEFAPI(void) defQIcon(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIcon";
	cdef->free = QIcon_free;
	cdef->reftrace = QIcon_reftrace;
	cdef->compareTo = QIcon_compareTo;
}


