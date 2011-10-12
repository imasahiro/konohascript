#ifndef QSPLITTERHANDLE
#define QSPLITTERHANDLE
class DummyQSplitterHandle : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSplitterHandle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSplitterHandle : public QSplitterHandle, public DummyQSplitterHandle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSplitterHandle(Qt::Orientation orientation, QSplitter* parent);
	bool event(QEvent *event);
};

#endif //QSPLITTERHANDLE


