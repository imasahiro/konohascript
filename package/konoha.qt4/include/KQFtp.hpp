#ifndef QFTP
#define QFTP
class DummyQFtp : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *command_finished_func;
	knh_Func_t *command_started_func;
	knh_Func_t *data_transfer_progress_func;
	knh_Func_t *done_func;
	knh_Func_t *list_info_func;
	knh_Func_t *raw_command_reply_func;
	knh_Func_t *ready_read_func;
	knh_Func_t *state_changed_func;
	DummyQFtp();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool commandFinishedSlot(int id, bool error);
	bool commandStartedSlot(int id);
	bool dataTransferProgressSlot(qint64 done, qint64 total);
	bool doneSlot(bool error);
	bool listInfoSlot(const QUrlInfo i);
	bool rawCommandReplySlot(int replyCode, const QString detail);
	bool readyReadSlot();
	bool stateChangedSlot(int state);
};

class KQFtp : public QFtp {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQFtp *dummy;
	KQFtp(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QFTP


