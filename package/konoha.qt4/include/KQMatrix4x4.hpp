#ifndef QMATRIX4X4
#define QMATRIX4X4
class DummyQMatrix4x4 {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMatrix4x4();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMatrix4x4 : public QMatrix4x4, public DummyQMatrix4x4 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMatrix4x4();
};

#endif //QMATRIX4X4


