#ifndef QMATRIX4X4
#define QMATRIX4X4
class DummyQMatrix4x4 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMatrix4x4();
	virtual ~DummyQMatrix4x4();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQMatrix4x4 : public QMatrix4x4 {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQMatrix4x4 *dummy;
	KQMatrix4x4();
	~KQMatrix4x4();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QMATRIX4X4


