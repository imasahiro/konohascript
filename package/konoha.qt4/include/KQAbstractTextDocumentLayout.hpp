#ifndef QABSTRACTTEXTDOCUMENTLAYOUT
#define QABSTRACTTEXTDOCUMENTLAYOUT
class DummyQAbstractTextDocumentLayout : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractTextDocumentLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractTextDocumentLayout : public QAbstractTextDocumentLayout, public DummyQAbstractTextDocumentLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractTextDocumentLayout(QTextDocument* document);
	bool event(QEvent *event);
};

#endif //QABSTRACTTEXTDOCUMENTLAYOUT


