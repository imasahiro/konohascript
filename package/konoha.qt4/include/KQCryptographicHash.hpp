#ifndef QCRYPTOGRAPHICHASH
#define QCRYPTOGRAPHICHASH
class DummyQCryptographicHash {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCryptographicHash();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCryptographicHash : public QCryptographicHash, public DummyQCryptographicHash {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCryptographicHash(QCryptographicHash::Algorithm method);
};

#endif //QCRYPTOGRAPHICHASH


