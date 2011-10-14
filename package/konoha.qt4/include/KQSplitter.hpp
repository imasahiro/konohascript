#ifndef QSPLITTER
#define QSPLITTER
class DummyQSplitter : public DummyQFrame {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *splitter_moved_func;
	DummyQSplitter();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool splitterMovedSlot(int pos, int index);
};

class KQSplitter : public QSplitter {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQSplitter *dummy;
	KQSplitter(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSPLITTER


