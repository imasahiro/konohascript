#ifndef QPROCESS
#define QPROCESS
class DummyQProcess : public DummyQIODevice {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *error_func;
	knh_Func_t *finished_func;
	knh_Func_t *ready_read_standard_error_func;
	knh_Func_t *ready_read_standard_output_func;
	knh_Func_t *started_func;
	knh_Func_t *state_changed_func;
	DummyQProcess();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool errorSlot(QProcess::ProcessError error);
	bool finishedSlot(int exitCode, QProcess::ExitStatus exitStatus);
	bool readyReadStandardErrorSlot();
	bool readyReadStandardOutputSlot();
	bool startedSlot();
	bool stateChangedSlot(QProcess::ProcessState new_State);
};

class KQProcess : public QProcess {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQProcess *dummy;
	KQProcess(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPROCESS


