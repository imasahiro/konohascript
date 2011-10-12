#ifndef QCDESTYLE
#define QCDESTYLE
class DummyQCDEStyle : public DummyQMotifStyle {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCDEStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCDEStyle : public QCDEStyle, public DummyQCDEStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCDEStyle(bool useHighlightCols);
	bool event(QEvent *event);
};

#endif //QCDESTYLE


