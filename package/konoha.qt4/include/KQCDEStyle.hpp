#ifndef QCDESTYLE
#define QCDESTYLE
class DummyQCDEStyle : public DummyQMotifStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCDEStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQCDEStyle : public QCDEStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQCDEStyle *dummy;
	KQCDEStyle(bool useHighlightCols);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCDESTYLE


