#ifndef QPLAINTEXTDOCUMENTLAYOUT
#define QPLAINTEXTDOCUMENTLAYOUT
class DummyQPlainTextDocumentLayout : public DummyQAbstractTextDocumentLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPlainTextDocumentLayout();
	virtual ~DummyQPlainTextDocumentLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQPlainTextDocumentLayout : public QPlainTextDocumentLayout {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQPlainTextDocumentLayout *dummy;
	KQPlainTextDocumentLayout(QTextDocument* document);
	~KQPlainTextDocumentLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPLAINTEXTDOCUMENTLAYOUT


