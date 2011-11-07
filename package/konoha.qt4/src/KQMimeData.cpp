//QMimeData QMimeData.new();
KMETHOD QMimeData_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMimeData *ret_v = new KQMimeData();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QMimeData.clear();
KMETHOD QMimeData_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//QVariant QMimeData.getColorData();
KMETHOD QMimeData_getColorData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		QVariant ret_v = qp->colorData();
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QMimeData.getData(String mimeType);
KMETHOD QMimeData_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QString mimeType = String_to(const QString, sfp[1]);
		QByteArray ret_v = qp->data(mimeType);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMimeData.hasColor();
KMETHOD QMimeData_hasColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasColor();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QMimeData.hasFormat(String mimeType);
KMETHOD QMimeData_hasFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QString mimeType = String_to(const QString, sfp[1]);
		bool ret_v = qp->hasFormat(mimeType);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMimeData.hasHtml();
KMETHOD QMimeData_hasHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHtml();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMimeData.hasImage();
KMETHOD QMimeData_hasImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasImage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMimeData.hasText();
KMETHOD QMimeData_hasText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasText();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMimeData.hasUrls();
KMETHOD QMimeData_hasUrls(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasUrls();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QMimeData.getHtml();
KMETHOD QMimeData_getHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		QString ret_v = qp->html();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QMimeData.getImageData();
KMETHOD QMimeData_getImageData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		QVariant ret_v = qp->imageData();
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMimeData.removeFormat(String mimeType);
KMETHOD QMimeData_removeFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QString mimeType = String_to(const QString, sfp[1]);
		qp->removeFormat(mimeType);
	}
	RETURNvoid_();
}

//void QMimeData.setColorData(QVariant color);
KMETHOD QMimeData_setColorData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QVariant  color = *RawPtr_to(const QVariant *, sfp[1]);
		qp->setColorData(color);
	}
	RETURNvoid_();
}

//void QMimeData.setData(String mimeType, QByteArray data);
KMETHOD QMimeData_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QString mimeType = String_to(const QString, sfp[1]);
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[2]);
		qp->setData(mimeType, data);
	}
	RETURNvoid_();
}

//void QMimeData.setHtml(String html);
KMETHOD QMimeData_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QString html = String_to(const QString, sfp[1]);
		qp->setHtml(html);
	}
	RETURNvoid_();
}

//void QMimeData.setImageData(QVariant image);
KMETHOD QMimeData_setImageData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QVariant  image = *RawPtr_to(const QVariant *, sfp[1]);
		qp->setImageData(image);
	}
	RETURNvoid_();
}

//void QMimeData.setText(String text);
KMETHOD QMimeData_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//void QMimeData.setUrls(Array<QUrl> urls);
KMETHOD QMimeData_setUrls(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QUrl> urls;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			urls.append(*(QUrl*)p->rawptr);
		}
		qp->setUrls(urls);
	}
	RETURNvoid_();
}

//String QMimeData.getText();
KMETHOD QMimeData_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QUrl> QMimeData.getUrls();
KMETHOD QMimeData_getUrls(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMimeData *  qp = RawPtr_to(QMimeData *, sfp[0]);
	if (qp) {
		QList<QUrl> ret_v = qp->urls();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QUrl"));
		for (int n = 0; n < list_size; n++) {
			QUrl *ret_v_ = new QUrl(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	


DummyQMimeData::DummyQMimeData()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMimeData::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMimeData::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQMimeData::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMimeData::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMimeData::event_map->bigin();
	if ((itr = DummyQMimeData::event_map->find(str)) == DummyQMimeData::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMimeData::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMimeData::slot_map->bigin();
	if ((itr = DummyQMimeData::slot_map->find(str)) == DummyQMimeData::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQMimeData::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQMimeData::connection(QObject *o)
{
	QMimeData *p = dynamic_cast<QMimeData*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQMimeData::KQMimeData() : QMimeData()
{
	self = NULL;
	dummy = new DummyQMimeData();
	dummy->connection((QObject*)this);
}

KMETHOD QMimeData_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMimeData *qp = RawPtr_to(KQMimeData *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMimeData]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMimeData]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMimeData_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMimeData *qp = RawPtr_to(KQMimeData *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMimeData]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMimeData]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMimeData_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMimeData *qp = (KQMimeData *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMimeData_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMimeData *qp = (KQMimeData *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMimeData_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMimeData::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMimeData::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMimeData::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQMimeData(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMimeData";
	cdef->free = QMimeData_free;
	cdef->reftrace = QMimeData_reftrace;
	cdef->compareTo = QMimeData_compareTo;
}


