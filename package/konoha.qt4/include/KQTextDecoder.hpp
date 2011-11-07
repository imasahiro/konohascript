#ifndef QTEXTDECODER
#define QTEXTDECODER
class DummyQTextDecoder {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextDecoder();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQTextDecoder : public QTextDecoder {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTextDecoder *dummy;
	KQTextDecoder(const QTextCodec* codec);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QTEXTDECODER


