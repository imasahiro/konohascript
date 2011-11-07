//QTextFormat QTextFormat.new();
KMETHOD QTextFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFormat *ret_v = new KQTextFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextFormat QTextFormat.new(int type);
KMETHOD QTextFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int type = Int_to(int, sfp[1]);
	KQTextFormat *ret_v = new KQTextFormat(type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextFormat QTextFormat.new(QTextFormat other);
KMETHOD QTextFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextFormat  other = *RawPtr_to(const QTextFormat *, sfp[1]);
	KQTextFormat *ret_v = new KQTextFormat(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QBrush QTextFormat.getBackground();
KMETHOD QTextFormat_getBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->background();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextFormat.boolProperty(int propertyId);
KMETHOD QTextFormat_boolProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		bool ret_v = qp->boolProperty(propertyId);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QBrush QTextFormat.brushProperty(int propertyId);
KMETHOD QTextFormat_brushProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		QBrush ret_v = qp->brushProperty(propertyId);
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextFormat.clearBackground();
KMETHOD QTextFormat_clearBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		qp->clearBackground();
	}
	RETURNvoid_();
}

//void QTextFormat.clearForeground();
KMETHOD QTextFormat_clearForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		qp->clearForeground();
	}
	RETURNvoid_();
}

//void QTextFormat.clearProperty(int propertyId);
KMETHOD QTextFormat_clearProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		qp->clearProperty(propertyId);
	}
	RETURNvoid_();
}

//QColor QTextFormat.colorProperty(int propertyId);
KMETHOD QTextFormat_colorProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		QColor ret_v = qp->colorProperty(propertyId);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextFormat.doubleProperty(int propertyId);
KMETHOD QTextFormat_doubleProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		qreal ret_v = qp->doubleProperty(propertyId);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QBrush QTextFormat.getForeground();
KMETHOD QTextFormat_getForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->foreground();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextFormat.hasProperty(int propertyId);
KMETHOD QTextFormat_hasProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		bool ret_v = qp->hasProperty(propertyId);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextFormat.intProperty(int propertyId);
KMETHOD QTextFormat_intProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		int ret_v = qp->intProperty(propertyId);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextFormat.isBlockFormat();
KMETHOD QTextFormat_isBlockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isBlockFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextFormat.isCharFormat();
KMETHOD QTextFormat_isCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCharFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextFormat.isFrameFormat();
KMETHOD QTextFormat_isFrameFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFrameFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextFormat.isImageFormat();
KMETHOD QTextFormat_isImageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isImageFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextFormat.isListFormat();
KMETHOD QTextFormat_isListFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isListFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextFormat.isTableCellFormat();
KMETHOD QTextFormat_isTableCellFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTableCellFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextFormat.isTableFormat();
KMETHOD QTextFormat_isTableFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTableFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextFormat.getLayoutDirection();
KMETHOD QTextFormat_getLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		Qt::LayoutDirection ret_v = qp->layoutDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextLength QTextFormat.lengthProperty(int propertyId);
KMETHOD QTextFormat_lengthProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		QTextLength ret_v = qp->lengthProperty(propertyId);
		QTextLength *ret_v_ = new QTextLength(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextFormat.merge(QTextFormat other);
KMETHOD QTextFormat_merge(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		const QTextFormat  other = *RawPtr_to(const QTextFormat *, sfp[1]);
		qp->merge(other);
	}
	RETURNvoid_();
}

//int QTextFormat.getObjectIndex();
KMETHOD QTextFormat_getObjectIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->objectIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextFormat.getObjectType();
KMETHOD QTextFormat_getObjectType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->objectType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPen QTextFormat.penProperty(int propertyId);
KMETHOD QTextFormat_penProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		QPen ret_v = qp->penProperty(propertyId);
		QPen *ret_v_ = new QPen(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QTextFormat.getProperty(int propertyId);
KMETHOD QTextFormat_getProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		QVariant ret_v = qp->property(propertyId);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextFormat.propertyCount();
KMETHOD QTextFormat_propertyCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->propertyCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextFormat.setBackground(QBrush brush);
KMETHOD QTextFormat_setBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackground(brush);
	}
	RETURNvoid_();
}

//void QTextFormat.setForeground(QBrush brush);
KMETHOD QTextFormat_setForeground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setForeground(brush);
	}
	RETURNvoid_();
}

//void QTextFormat.setLayoutDirection(int direction);
KMETHOD QTextFormat_setLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		qp->setLayoutDirection(direction);
	}
	RETURNvoid_();
}

//void QTextFormat.setObjectIndex(int index);
KMETHOD QTextFormat_setObjectIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->setObjectIndex(index);
	}
	RETURNvoid_();
}

//void QTextFormat.setObjectType(int type);
KMETHOD QTextFormat_setObjectType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int type = Int_to(int, sfp[1]);
		qp->setObjectType(type);
	}
	RETURNvoid_();
}

//void QTextFormat.setProperty(int propertyId, QVariant value);
KMETHOD QTextFormat_setProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setProperty(propertyId, value);
	}
	RETURNvoid_();
}

//String QTextFormat.stringProperty(int propertyId);
KMETHOD QTextFormat_stringProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int propertyId = Int_to(int, sfp[1]);
		QString ret_v = qp->stringProperty(propertyId);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlockFormat QTextFormat.toBlockFormat();
KMETHOD QTextFormat_toBlockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextBlockFormat ret_v = qp->toBlockFormat();
		QTextBlockFormat *ret_v_ = new QTextBlockFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCharFormat QTextFormat.toCharFormat();
KMETHOD QTextFormat_toCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextCharFormat ret_v = qp->toCharFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextFrameFormat QTextFormat.toFrameFormat();
KMETHOD QTextFormat_toFrameFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextFrameFormat ret_v = qp->toFrameFormat();
		QTextFrameFormat *ret_v_ = new QTextFrameFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextImageFormat QTextFormat.toImageFormat();
KMETHOD QTextFormat_toImageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextImageFormat ret_v = qp->toImageFormat();
		QTextImageFormat *ret_v_ = new QTextImageFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextListFormat QTextFormat.toListFormat();
KMETHOD QTextFormat_toListFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextListFormat ret_v = qp->toListFormat();
		QTextListFormat *ret_v_ = new QTextListFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextTableCellFormat QTextFormat.toTableCellFormat();
KMETHOD QTextFormat_toTableCellFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextTableCellFormat ret_v = qp->toTableCellFormat();
		QTextTableCellFormat *ret_v_ = new QTextTableCellFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextTableFormat QTextFormat.toTableFormat();
KMETHOD QTextFormat_toTableFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		QTextTableFormat ret_v = qp->toTableFormat();
		QTextTableFormat *ret_v_ = new QTextTableFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextFormat.type();
KMETHOD QTextFormat_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *  qp = RawPtr_to(QTextFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QTextFormat.parents();
KMETHOD QTextFormat_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat *qp = RawPtr_to(QTextFormat*, sfp[0]);
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

DummyQTextFormat::DummyQTextFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextFormat::self = ptr;
}

bool DummyQTextFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFormat::event_map->bigin();
	if ((itr = DummyQTextFormat::event_map->find(str)) == DummyQTextFormat::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFormat::slot_map->bigin();
	if ((itr = DummyQTextFormat::slot_map->find(str)) == DummyQTextFormat::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQTextFormat::connection(QObject *o)
{
	QTextFormat *p = dynamic_cast<QTextFormat*>(o);
	if (p != NULL) {
	}
}

KQTextFormat::KQTextFormat() : QTextFormat()
{
	self = NULL;
	dummy = new DummyQTextFormat();
}

KMETHOD QTextFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFormat *qp = RawPtr_to(KQTextFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFormat *qp = RawPtr_to(KQTextFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextFormat *qp = (KQTextFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextFormat *qp = (KQTextFormat *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextFormat*>(p1->rawptr) == *static_cast<QTextFormat*>(p2->rawptr) ? 0 : 1);
}

void KQTextFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextFormatConstInt[] = {
	{"InvalidFormat", QTextFormat::InvalidFormat},
	{"BlockFormat", QTextFormat::BlockFormat},
	{"CharFormat", QTextFormat::CharFormat},
	{"ListFormat", QTextFormat::ListFormat},
	{"TableFormat", QTextFormat::TableFormat},
	{"FrameFormat", QTextFormat::FrameFormat},
	{"UserFormat", QTextFormat::UserFormat},
	{"NoObject", QTextFormat::NoObject},
	{"ImageObject", QTextFormat::ImageObject},
	{"TableObject", QTextFormat::TableObject},
	{"TableCellObject", QTextFormat::TableCellObject},
	{"UserObject", QTextFormat::UserObject},
	{"PageBreak_Auto", QTextFormat::PageBreak_Auto},
	{"PageBreak_AlwaysBefore", QTextFormat::PageBreak_AlwaysBefore},
	{"PageBreak_AlwaysAfter", QTextFormat::PageBreak_AlwaysAfter},
	{"ObjectIndex", QTextFormat::ObjectIndex},
	{"CssFloat", QTextFormat::CssFloat},
	{"LayoutDirection", QTextFormat::LayoutDirection},
	{"OutlinePen", QTextFormat::OutlinePen},
	{"ForegroundBrush", QTextFormat::ForegroundBrush},
	{"BackgroundBrush", QTextFormat::BackgroundBrush},
	{"BackgroundImageUrl", QTextFormat::BackgroundImageUrl},
	{"BlockAlignment", QTextFormat::BlockAlignment},
	{"BlockTopMargin", QTextFormat::BlockTopMargin},
	{"BlockBottomMargin", QTextFormat::BlockBottomMargin},
	{"BlockLeftMargin", QTextFormat::BlockLeftMargin},
	{"BlockRightMargin", QTextFormat::BlockRightMargin},
	{"TextIndent", QTextFormat::TextIndent},
	{"TabPositions", QTextFormat::TabPositions},
	{"BlockIndent", QTextFormat::BlockIndent},
	{"BlockNonBreakableLines", QTextFormat::BlockNonBreakableLines},
	{"BlockTrailingHorizontalRulerWidth", QTextFormat::BlockTrailingHorizontalRulerWidth},
	{"FontFamily", QTextFormat::FontFamily},
	{"FontPointSize", QTextFormat::FontPointSize},
	{"FontPixelSize", QTextFormat::FontPixelSize},
	{"FontSizeAdjustment", QTextFormat::FontSizeAdjustment},
	{"FontFixedPitch", QTextFormat::FontFixedPitch},
	{"FontWeight", QTextFormat::FontWeight},
	{"FontItalic", QTextFormat::FontItalic},
	{"FontUnderline", QTextFormat::FontUnderline},
	{"FontOverline", QTextFormat::FontOverline},
	{"FontStrikeOut", QTextFormat::FontStrikeOut},
	{"FontCapitalization", QTextFormat::FontCapitalization},
	{"FontLetterSpacing", QTextFormat::FontLetterSpacing},
	{"FontWordSpacing", QTextFormat::FontWordSpacing},
	{"FontStyleHint", QTextFormat::FontStyleHint},
	{"FontStyleStrategy", QTextFormat::FontStyleStrategy},
	{"FontKerning", QTextFormat::FontKerning},
	{"TextUnderlineColor", QTextFormat::TextUnderlineColor},
	{"TextVerticalAlignment", QTextFormat::TextVerticalAlignment},
	{"TextOutline", QTextFormat::TextOutline},
	{"TextUnderlineStyle", QTextFormat::TextUnderlineStyle},
	{"TextToolTip", QTextFormat::TextToolTip},
	{"IsAnchor", QTextFormat::IsAnchor},
	{"AnchorHref", QTextFormat::AnchorHref},
	{"AnchorName", QTextFormat::AnchorName},
	{"ObjectType", QTextFormat::ObjectType},
	{"ListStyle", QTextFormat::ListStyle},
	{"ListIndent", QTextFormat::ListIndent},
	{"FrameBorder", QTextFormat::FrameBorder},
	{"FrameBorderBrush", QTextFormat::FrameBorderBrush},
	{"FrameBorderStyle", QTextFormat::FrameBorderStyle},
	{"FrameBottomMargin", QTextFormat::FrameBottomMargin},
	{"FrameHeight", QTextFormat::FrameHeight},
	{"FrameLeftMargin", QTextFormat::FrameLeftMargin},
	{"FrameMargin", QTextFormat::FrameMargin},
	{"FramePadding", QTextFormat::FramePadding},
	{"FrameRightMargin", QTextFormat::FrameRightMargin},
	{"FrameTopMargin", QTextFormat::FrameTopMargin},
	{"FrameWidth", QTextFormat::FrameWidth},
	{"TableCellSpacing", QTextFormat::TableCellSpacing},
	{"TableCellPadding", QTextFormat::TableCellPadding},
	{"TableColumns", QTextFormat::TableColumns},
	{"TableColumnWidthConstraints", QTextFormat::TableColumnWidthConstraints},
	{"TableHeaderRowCount", QTextFormat::TableHeaderRowCount},
	{"TableCellRowSpan", QTextFormat::TableCellRowSpan},
	{"TableCellColumnSpan", QTextFormat::TableCellColumnSpan},
	{"TableCellLeftPadding", QTextFormat::TableCellLeftPadding},
	{"TableCellRightPadding", QTextFormat::TableCellRightPadding},
	{"TableCellTopPadding", QTextFormat::TableCellTopPadding},
	{"TableCellBottomPadding", QTextFormat::TableCellBottomPadding},
	{"ImageName", QTextFormat::ImageName},
	{"ImageWidth", QTextFormat::ImageWidth},
	{"ImageHeight", QTextFormat::ImageHeight},
	{"FullWidthSelection", QTextFormat::FullWidthSelection},
	{"PageBreakPolicy", QTextFormat::PageBreakPolicy},
	{"UserProperty", QTextFormat::UserProperty},
	{NULL, 0}
};

DEFAPI(void) constQTextFormat(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextFormatConstInt);
}


DEFAPI(void) defQTextFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextFormat";
	cdef->free = QTextFormat_free;
	cdef->reftrace = QTextFormat_reftrace;
	cdef->compareTo = QTextFormat_compareTo;
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.new(int value);
KMETHOD QTextFormatPageBreakFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlag i = Int_to(QTextFormat::PageBreakFlag, sfp[1]);
	QTextFormat::PageBreakFlags *ret_v = new QTextFormat::PageBreakFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.and(int mask);
KMETHOD QTextFormatPageBreakFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextFormat::PageBreakFlags ret = ((*qp) & i);
		QTextFormat::PageBreakFlags *ret_ = new QTextFormat::PageBreakFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.iand(QTextFormat::QTextFormatPageBreakFlags other);
KMETHOD QTextFormatPageBreakFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[0]);
	if (qp != NULL) {
		QTextFormat::PageBreakFlags *other = RawPtr_to(QTextFormat::PageBreakFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.or(QTextFormatPageBreakFlags f);
KMETHOD QTextFormatPageBreakFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[0]);
	if (qp != NULL) {
		QTextFormat::PageBreakFlags *f = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[1]);
		QTextFormat::PageBreakFlags ret = ((*qp) | (*f));
		QTextFormat::PageBreakFlags *ret_ = new QTextFormat::PageBreakFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.ior(QTextFormat::QTextFormatPageBreakFlags other);
KMETHOD QTextFormatPageBreakFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[0]);
	if (qp != NULL) {
		QTextFormat::PageBreakFlags *other = RawPtr_to(QTextFormat::PageBreakFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.xor(QTextFormatPageBreakFlags f);
KMETHOD QTextFormatPageBreakFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[0]);
	if (qp != NULL) {
		QTextFormat::PageBreakFlags *f = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[1]);
		QTextFormat::PageBreakFlags ret = ((*qp) ^ (*f));
		QTextFormat::PageBreakFlags *ret_ = new QTextFormat::PageBreakFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextFormatPageBreakFlags QTextFormatPageBreakFlags.ixor(QTextFormat::QTextFormatPageBreakFlags other);
KMETHOD QTextFormatPageBreakFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags*, sfp[0]);
	if (qp != NULL) {
		QTextFormat::PageBreakFlags *other = RawPtr_to(QTextFormat::PageBreakFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextFormatPageBreakFlags.testFlag(int flag);
KMETHOD QTextFormatPageBreakFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags *, sfp[0]);
	if (qp != NULL) {
		QTextFormat::PageBreakFlag flag = Int_to(QTextFormat::PageBreakFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextFormatPageBreakFlags.value();
KMETHOD QTextFormatPageBreakFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextFormat::PageBreakFlags *qp = RawPtr_to(QTextFormat::PageBreakFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextFormatPageBreakFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextFormat::PageBreakFlags *qp = (QTextFormat::PageBreakFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QTextFormatPageBreakFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextFormat::PageBreakFlags *qp = (QTextFormat::PageBreakFlags *)p->rawptr;
		(void)qp;
	}
}

static int QTextFormatPageBreakFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextFormat::PageBreakFlags*)p1->rawptr);
//		int v2 = int(*(QTextFormat::PageBreakFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextFormat::PageBreakFlags v1 = *(QTextFormat::PageBreakFlags*)p1->rawptr;
		QTextFormat::PageBreakFlags v2 = *(QTextFormat::PageBreakFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextFormatPageBreakFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextFormatPageBreakFlags";
	cdef->free = QTextFormatPageBreakFlags_free;
	cdef->reftrace = QTextFormatPageBreakFlags_reftrace;
	cdef->compareTo = QTextFormatPageBreakFlags_compareTo;
}

