#ifndef QTEXTDOCUMENTFRAGMENT
#define QTEXTDOCUMENTFRAGMENT
class DummyQTextDocumentFragment {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextDocumentFragment();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQTextDocumentFragment : public QTextDocumentFragment {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTextDocumentFragment *dummy;
	KQTextDocumentFragment();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QTEXTDOCUMENTFRAGMENT


