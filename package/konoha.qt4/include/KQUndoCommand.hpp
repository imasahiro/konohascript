#ifndef QUNDOCOMMAND
#define QUNDOCOMMAND
class DummyQUndoCommand {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQUndoCommand();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQUndoCommand : public QUndoCommand {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQUndoCommand *dummy;
	KQUndoCommand(QUndoCommand* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QUNDOCOMMAND


