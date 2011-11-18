#ifndef QIODEVICE
#define QIODEVICE
class DummyQIODevice : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *about_to_close_func;
	knh_Func_t *bytes_written_func;
	knh_Func_t *read_channel_finished_func;
	knh_Func_t *ready_read_func;
	DummyQIODevice();
	virtual ~DummyQIODevice();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool aboutToCloseSlot();
	bool bytesWrittenSlot(qint64 bytes);
	bool readChannelFinishedSlot();
	bool readyReadSlot();
};

class KQIODevice : public QIODevice {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQIODevice *dummy;
	KQIODevice();
	~KQIODevice();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QIODEVICE


