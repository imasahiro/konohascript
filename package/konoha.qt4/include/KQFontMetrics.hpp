#ifndef QFONTMETRICS
#define QFONTMETRICS
class DummyQFontMetrics {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFontMetrics();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFontMetrics : public QFontMetrics, public DummyQFontMetrics {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFontMetrics(const QFont font);
};

#endif //QFONTMETRICS


