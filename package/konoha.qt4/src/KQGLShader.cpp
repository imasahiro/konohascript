//QGLShader QGLShader.new(QGLShaderShaderType type, QObject parent);
KMETHOD QGLShader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	initFlag(type, QGLShader::ShaderType, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQGLShader *ret_v = new KQGLShader(type, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLShader QGLShader.new(QGLShaderShaderType type, QGLContext context, QObject parent);
KMETHOD QGLShader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	initFlag(type, QGLShader::ShaderType, sfp[1]);
	const QGLContext*  context = RawPtr_to(const QGLContext*, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQGLShader *ret_v = new KQGLShader(type, context, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QGLShader.compileSourceCode(String source);
KMETHOD QGLShader_compileSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		const char*  source = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->compileSourceCode(source);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QGLShader.compileSourceCode(QByteArray source);
KMETHOD QGLShader_compileSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		const QByteArray  source = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->compileSourceCode(source);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QGLShader.compileSourceCode(String source);
KMETHOD QGLShader_compileSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		const QString source = String_to(const QString, sfp[1]);
		bool ret_v = qp->compileSourceCode(source);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QGLShader.compileSourceFile(String fileName);
KMETHOD QGLShader_compileSourceFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		bool ret_v = qp->compileSourceFile(fileName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLShader.isCompiled();
KMETHOD QGLShader_isCompiled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCompiled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QGLShader.log();
KMETHOD QGLShader_log(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		QString ret_v = qp->log();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//GLuint QGLShader.shaderId();
KMETHOD QGLShader_shaderId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		GLuint ret_v = qp->shaderId();
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGLShaderShaderType QGLShader.shaderType();
KMETHOD QGLShader_shaderType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		QGLShader::ShaderType ret_v = qp->shaderType();
		QGLShader::ShaderType *ret_v_ = new QGLShader::ShaderType(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QGLShader.sourceCode();
KMETHOD QGLShader_sourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader *  qp = RawPtr_to(QGLShader *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->sourceCode();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLShader.hasOpenGLShaders(QGLShaderShaderType type, QGLContext context);
KMETHOD QGLShader_hasOpenGLShaders(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		initFlag(type, QGLShader::ShaderType, sfp[1]);
		const QGLContext*  context = RawPtr_to(const QGLContext*, sfp[2]);
		bool ret_v = QGLShader::hasOpenGLShaders(type, context);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQGLShader::DummyQGLShader()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGLShader::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLShader::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQGLShader::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGLShader::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLShader::event_map->bigin();
	if ((itr = DummyQGLShader::event_map->find(str)) == DummyQGLShader::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLShader::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLShader::slot_map->bigin();
	if ((itr = DummyQGLShader::slot_map->find(str)) == DummyQGLShader::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLShader::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLShader::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGLShader::connection(QObject *o)
{
	QGLShader *p = dynamic_cast<QGLShader*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQGLShader::KQGLShader(QGLShader::ShaderType type, QObject* parent) : QGLShader(type, parent)
{
	self = NULL;
	dummy = new DummyQGLShader();
	dummy->connection((QObject*)this);
}

KMETHOD QGLShader_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLShader *qp = RawPtr_to(KQGLShader *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLShader]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLShader]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLShader_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLShader *qp = RawPtr_to(KQGLShader *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLShader]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLShader]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLShader_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGLShader *qp = (KQGLShader *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGLShader_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGLShader *qp = (KQGLShader *)p->rawptr;
//		KQGLShader *qp = static_cast<KQGLShader*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLShader_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLShader::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGLShader::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGLShader::event(event);
		return false;
	}
//	QGLShader::event(event);
	return true;
}

static knh_IntData_t QGLShaderConstInt[] = {
	{"Vertex", QGLShader::Vertex},
	{"Fragment", QGLShader::Fragment},
	{"Geometry", QGLShader::Geometry},
	{NULL, 0}
};

DEFAPI(void) constQGLShader(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGLShaderConstInt);
}


DEFAPI(void) defQGLShader(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLShader";
	cdef->free = QGLShader_free;
	cdef->reftrace = QGLShader_reftrace;
	cdef->compareTo = QGLShader_compareTo;
}

//## QGLShaderShaderType QGLShaderShaderType.new(int value);
KMETHOD QGLShaderShaderType_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderTypeBit i = Int_to(QGLShader::ShaderTypeBit, sfp[1]);
	QGLShader::ShaderType *ret_v = new QGLShader::ShaderType(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QGLShaderShaderType QGLShaderShaderType.and(int mask);
KMETHOD QGLShaderShaderType_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QGLShader::ShaderType ret = ((*qp) & i);
		QGLShader::ShaderType *ret_ = new QGLShader::ShaderType(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLShaderShaderType QGLShaderShaderType.iand(QGLShader::QGLShaderShaderType other);
KMETHOD QGLShaderShaderType_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType*, sfp[0]);
	if (qp != NULL) {
		QGLShader::ShaderType *other = RawPtr_to(QGLShader::ShaderType *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLShaderShaderType QGLShaderShaderType.or(QGLShaderShaderType f);
KMETHOD QGLShaderShaderType_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType*, sfp[0]);
	if (qp != NULL) {
		QGLShader::ShaderType *f = RawPtr_to(QGLShader::ShaderType*, sfp[1]);
		QGLShader::ShaderType ret = ((*qp) | (*f));
		QGLShader::ShaderType *ret_ = new QGLShader::ShaderType(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLShaderShaderType QGLShaderShaderType.ior(QGLShader::QGLShaderShaderType other);
KMETHOD QGLShaderShaderType_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType*, sfp[0]);
	if (qp != NULL) {
		QGLShader::ShaderType *other = RawPtr_to(QGLShader::ShaderType *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLShaderShaderType QGLShaderShaderType.xor(QGLShaderShaderType f);
KMETHOD QGLShaderShaderType_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType*, sfp[0]);
	if (qp != NULL) {
		QGLShader::ShaderType *f = RawPtr_to(QGLShader::ShaderType*, sfp[1]);
		QGLShader::ShaderType ret = ((*qp) ^ (*f));
		QGLShader::ShaderType *ret_ = new QGLShader::ShaderType(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLShaderShaderType QGLShaderShaderType.ixor(QGLShader::QGLShaderShaderType other);
KMETHOD QGLShaderShaderType_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType*, sfp[0]);
	if (qp != NULL) {
		QGLShader::ShaderType *other = RawPtr_to(QGLShader::ShaderType *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QGLShaderShaderType.testFlag(int flag);
KMETHOD QGLShaderShaderType_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType *, sfp[0]);
	if (qp != NULL) {
		QGLShader::ShaderTypeBit flag = Int_to(QGLShader::ShaderTypeBit, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QGLShaderShaderType.value();
KMETHOD QGLShaderShaderType_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLShader::ShaderType *qp = RawPtr_to(QGLShader::ShaderType *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QGLShaderShaderType_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QGLShader::ShaderType *qp = (QGLShader::ShaderType *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QGLShaderShaderType_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QGLShader::ShaderType *qp = (QGLShader::ShaderType *)p->rawptr;
		(void)qp;
	}
}

static int QGLShaderShaderType_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QGLShader::ShaderType*)p1->rawptr);
//		int v2 = int(*(QGLShader::ShaderType*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QGLShader::ShaderType v1 = *(QGLShader::ShaderType*)p1->rawptr;
		QGLShader::ShaderType v2 = *(QGLShader::ShaderType*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQGLShaderShaderType(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLShaderShaderType";
	cdef->free = QGLShaderShaderType_free;
	cdef->reftrace = QGLShaderShaderType_reftrace;
	cdef->compareTo = QGLShaderShaderType_compareTo;
}

