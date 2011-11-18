#ifndef QMOVIE
#define QMOVIE
class DummyQMovie : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *error_func;
	knh_Func_t *finished_func;
	knh_Func_t *frame_changed_func;
	knh_Func_t *resized_func;
	knh_Func_t *started_func;
	knh_Func_t *state_changed_func;
	knh_Func_t *updated_func;
	DummyQMovie();
	virtual ~DummyQMovie();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool errorSlot(QImageReader::ImageReaderError error);
	bool finishedSlot();
	bool frameChangedSlot(int frameNumber);
	bool resizedSlot(const QSize size);
	bool startedSlot();
	bool stateChangedSlot(QMovie::MovieState state);
	bool updatedSlot(const QRect rect);
};

class KQMovie : public QMovie {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQMovie *dummy;
	KQMovie(QObject* parent);
	~KQMovie();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMOVIE


