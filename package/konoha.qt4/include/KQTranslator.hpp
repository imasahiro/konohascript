#ifndef QTRANSLATOR
#define QTRANSLATOR
class DummyQTranslator : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTranslator();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTranslator : public QTranslator, public DummyQTranslator {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTranslator(QObject* parent);
	bool event(QEvent *event);
};

#endif //QTRANSLATOR


