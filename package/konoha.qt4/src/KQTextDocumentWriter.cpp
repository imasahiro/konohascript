//QTextDocumentWriter QTextDocumentWriter.new();
KMETHOD QTextDocumentWriter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocumentWriter *ret_v = new KQTextDocumentWriter();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextDocumentWriter QTextDocumentWriter.new(QIODevice device, QByteArray fmt);
KMETHOD QTextDocumentWriter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	KQTextDocumentWriter *ret_v = new KQTextDocumentWriter(device, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextDocumentWriter QTextDocumentWriter.new(String fileName, QByteArray fmt);
KMETHOD QTextDocumentWriter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	KQTextDocumentWriter *ret_v = new KQTextDocumentWriter(fileName, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QTextCodec QTextDocumentWriter.getCodec();
KMETHOD QTextDocumentWriter_getCodec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		QTextCodec* ret_v = qp->codec();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIODevice QTextDocumentWriter.getDevice();
KMETHOD QTextDocumentWriter_getDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		QIODevice* ret_v = qp->device();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextDocumentWriter.getFileName();
KMETHOD QTextDocumentWriter_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QTextDocumentWriter.getFormat();
KMETHOD QTextDocumentWriter_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->format();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextDocumentWriter.setCodec(QTextCodec codec);
KMETHOD QTextDocumentWriter_setCodec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		QTextCodec*  codec = RawPtr_to(QTextCodec*, sfp[1]);
		qp->setCodec(codec);
	}
	RETURNvoid_();
}

//void QTextDocumentWriter.setDevice(QIODevice device);
KMETHOD QTextDocumentWriter_setDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		qp->setDevice(device);
	}
	RETURNvoid_();
}

//void QTextDocumentWriter.setFileName(String fileName);
KMETHOD QTextDocumentWriter_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setFileName(fileName);
	}
	RETURNvoid_();
}

//void QTextDocumentWriter.setFormat(QByteArray fmt);
KMETHOD QTextDocumentWriter_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//boolean QTextDocumentWriter.write(QTextDocument document);
KMETHOD QTextDocumentWriter_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		const QTextDocument*  document = RawPtr_to(const QTextDocument*, sfp[1]);
		bool ret_v = qp->write(document);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QTextDocumentWriter.write(QTextDocumentFragment fragment);
KMETHOD QTextDocumentWriter_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *  qp = RawPtr_to(QTextDocumentWriter *, sfp[0]);
	if (qp) {
		const QTextDocumentFragment  fragment = *RawPtr_to(const QTextDocumentFragment *, sfp[1]);
		bool ret_v = qp->write(fragment);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//Array<QByteArray> QTextDocumentWriter.supportedDocumentFormats();
KMETHOD QTextDocumentWriter_supportedDocumentFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QByteArray> ret_v = QTextDocumentWriter::supportedDocumentFormats();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<String> QTextDocumentWriter.parents();
KMETHOD QTextDocumentWriter_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocumentWriter *qp = RawPtr_to(QTextDocumentWriter*, sfp[0]);
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

DummyQTextDocumentWriter::DummyQTextDocumentWriter()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextDocumentWriter::~DummyQTextDocumentWriter()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextDocumentWriter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextDocumentWriter::self = ptr;
}

bool DummyQTextDocumentWriter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextDocumentWriter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocumentWriter::event_map->bigin();
	if ((itr = DummyQTextDocumentWriter::event_map->find(str)) == DummyQTextDocumentWriter::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextDocumentWriter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocumentWriter::slot_map->bigin();
	if ((itr = DummyQTextDocumentWriter::slot_map->find(str)) == DummyQTextDocumentWriter::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextDocumentWriter::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextDocumentWriter::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextDocumentWriter::connection(QObject *o)
{
	QTextDocumentWriter *p = dynamic_cast<QTextDocumentWriter*>(o);
	if (p != NULL) {
	}
}

KQTextDocumentWriter::KQTextDocumentWriter() : QTextDocumentWriter()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextDocumentWriter();
}

KQTextDocumentWriter::~KQTextDocumentWriter()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextDocumentWriter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocumentWriter *qp = RawPtr_to(KQTextDocumentWriter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDocumentWriter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocumentWriter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextDocumentWriter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocumentWriter *qp = RawPtr_to(KQTextDocumentWriter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDocumentWriter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocumentWriter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextDocumentWriter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextDocumentWriter *qp = (KQTextDocumentWriter *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextDocumentWriter*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextDocumentWriter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextDocumentWriter *qp = (KQTextDocumentWriter *)p->rawptr;
		KQTextDocumentWriter *qp = static_cast<KQTextDocumentWriter*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextDocumentWriter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextDocumentWriter::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextDocumentWriter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextDocumentWriter";
	cdef->free = QTextDocumentWriter_free;
	cdef->reftrace = QTextDocumentWriter_reftrace;
	cdef->compareTo = QTextDocumentWriter_compareTo;
}


