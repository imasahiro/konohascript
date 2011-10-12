#ifndef QDIRMODEL
#define QDIRMODEL
class DummyQDirModel : public DummyQAbstractItemModel {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDirModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDirModel : public QDirModel, public DummyQDirModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDirModel(QObject* parent);
	bool event(QEvent *event);
};

#endif //QDIRMODEL


