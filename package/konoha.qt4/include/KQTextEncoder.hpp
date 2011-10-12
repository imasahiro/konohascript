#ifndef QTEXTENCODER
#define QTEXTENCODER
class DummyQTextEncoder {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextEncoder();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextEncoder : public QTextEncoder, public DummyQTextEncoder {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextEncoder(const QTextCodec* codec);
};

#endif //QTEXTENCODER


