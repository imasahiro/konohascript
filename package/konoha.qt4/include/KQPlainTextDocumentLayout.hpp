#ifndef QPLAINTEXTDOCUMENTLAYOUT
#define QPLAINTEXTDOCUMENTLAYOUT
class DummyQPlainTextDocumentLayout : public DummyQAbstractTextDocumentLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPlainTextDocumentLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQPlainTextDocumentLayout : public QPlainTextDocumentLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPlainTextDocumentLayout *dummy;
	KQPlainTextDocumentLayout(QTextDocument* document);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPLAINTEXTDOCUMENTLAYOUT

