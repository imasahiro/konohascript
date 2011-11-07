//QPalette QPalette.new();
KMETHOD QPalette_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPalette *ret_v = new KQPalette();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPalette QPalette.new(QColor button);
KMETHOD QPalette_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QColor  button = *RawPtr_to(const QColor *, sfp[1]);
	KQPalette *ret_v = new KQPalette(button);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPalette QPalette.new(int button);
KMETHOD QPalette_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::GlobalColor button = Int_to(Qt::GlobalColor, sfp[1]);
	KQPalette *ret_v = new KQPalette(button);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPalette QPalette.new(QColor button, QColor window);
KMETHOD QPalette_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QColor  button = *RawPtr_to(const QColor *, sfp[1]);
	const QColor  window = *RawPtr_to(const QColor *, sfp[2]);
	KQPalette *ret_v = new KQPalette(button, window);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPalette QPalette.new(QBrush windowText, QBrush button, QBrush light, QBrush dark, QBrush mid, QBrush text, QBrush bright_text, QBrush base, QBrush window);
KMETHOD QPalette_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QBrush  windowText = *RawPtr_to(const QBrush *, sfp[1]);
	const QBrush  button = *RawPtr_to(const QBrush *, sfp[2]);
	const QBrush  light = *RawPtr_to(const QBrush *, sfp[3]);
	const QBrush  dark = *RawPtr_to(const QBrush *, sfp[4]);
	const QBrush  mid = *RawPtr_to(const QBrush *, sfp[5]);
	const QBrush  text = *RawPtr_to(const QBrush *, sfp[6]);
	const QBrush  bright_text = *RawPtr_to(const QBrush *, sfp[7]);
	const QBrush  base = *RawPtr_to(const QBrush *, sfp[8]);
	const QBrush  window = *RawPtr_to(const QBrush *, sfp[9]);
	KQPalette *ret_v = new KQPalette(windowText, button, light, dark, mid, text, bright_text, base, window);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPalette QPalette.new(QPalette p);
KMETHOD QPalette_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPalette  p = *RawPtr_to(const QPalette *, sfp[1]);
	KQPalette *ret_v = new KQPalette(p);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QBrush QPalette.alternateBase();
KMETHOD QPalette_alternateBase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->alternateBase();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.base();
KMETHOD QPalette_base(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->base();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.brightText();
KMETHOD QPalette_brightText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->brightText();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.getBrush(int group, int role);
KMETHOD QPalette_getBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup group = Int_to(QPalette::ColorGroup, sfp[1]);
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[2]);
		const QBrush ret_v = qp->brush(group, role);
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QBrush QPalette.getBrush(int role);
KMETHOD QPalette_getBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[1]);
		const QBrush ret_v = qp->brush(role);
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QBrush QPalette.button();
KMETHOD QPalette_button(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->button();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.buttonText();
KMETHOD QPalette_buttonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->buttonText();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPalette.cacheKey();
KMETHOD QPalette_cacheKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->cacheKey();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QPalette.getColor(int group, int role);
KMETHOD QPalette_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup group = Int_to(QPalette::ColorGroup, sfp[1]);
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[2]);
		const QColor ret_v = qp->color(group, role);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QColor QPalette.getColor(int role);
KMETHOD QPalette_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[1]);
		const QColor ret_v = qp->color(role);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QPalette.getCurrentColorGroup();
KMETHOD QPalette_getCurrentColorGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup ret_v = qp->currentColorGroup();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QBrush QPalette.dark();
KMETHOD QPalette_dark(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->dark();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.highlight();
KMETHOD QPalette_highlight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->highlight();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.highlightedText();
KMETHOD QPalette_highlightedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->highlightedText();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPalette.isBrushSet(int cg, int cr);
KMETHOD QPalette_isBrushSet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup cg = Int_to(QPalette::ColorGroup, sfp[1]);
		QPalette::ColorRole cr = Int_to(QPalette::ColorRole, sfp[2]);
		bool ret_v = qp->isBrushSet(cg, cr);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPalette.isCopyOf(QPalette p);
KMETHOD QPalette_isCopyOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QPalette  p = *RawPtr_to(const QPalette *, sfp[1]);
		bool ret_v = qp->isCopyOf(p);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPalette.isEqual(int cg1, int cg2);
KMETHOD QPalette_isEqual(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup cg1 = Int_to(QPalette::ColorGroup, sfp[1]);
		QPalette::ColorGroup cg2 = Int_to(QPalette::ColorGroup, sfp[2]);
		bool ret_v = qp->isEqual(cg1, cg2);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QBrush QPalette.light();
KMETHOD QPalette_light(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->light();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.link();
KMETHOD QPalette_link(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->link();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.linkVisited();
KMETHOD QPalette_linkVisited(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->linkVisited();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.mid();
KMETHOD QPalette_mid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->mid();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.midlight();
KMETHOD QPalette_midlight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->midlight();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPalette QPalette.resolve(QPalette other);
KMETHOD QPalette_resolve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QPalette  other = *RawPtr_to(const QPalette *, sfp[1]);
		QPalette ret_v = qp->resolve(other);
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPalette.setBrush(int role, QBrush brush);
KMETHOD QPalette_setBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[1]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[2]);
		qp->setBrush(role, brush);
	}
	RETURNvoid_();
}

/*
//void QPalette.setBrush(int group, int role, QBrush brush);
KMETHOD QPalette_setBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup group = Int_to(QPalette::ColorGroup, sfp[1]);
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[2]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[3]);
		qp->setBrush(group, role, brush);
	}
	RETURNvoid_();
}
*/
//void QPalette.setColor(int group, int role, QColor color);
KMETHOD QPalette_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup group = Int_to(QPalette::ColorGroup, sfp[1]);
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[2]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[3]);
		qp->setColor(group, role, color);
	}
	RETURNvoid_();
}

/*
//void QPalette.setColor(int role, QColor color);
KMETHOD QPalette_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->setColor(role, color);
	}
	RETURNvoid_();
}
*/
//void QPalette.setColorGroup(int cg, QBrush windowText, QBrush button, QBrush light, QBrush dark, QBrush mid, QBrush text, QBrush bright_text, QBrush base, QBrush window);
KMETHOD QPalette_setColorGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup cg = Int_to(QPalette::ColorGroup, sfp[1]);
		const QBrush  windowText = *RawPtr_to(const QBrush *, sfp[2]);
		const QBrush  button = *RawPtr_to(const QBrush *, sfp[3]);
		const QBrush  light = *RawPtr_to(const QBrush *, sfp[4]);
		const QBrush  dark = *RawPtr_to(const QBrush *, sfp[5]);
		const QBrush  mid = *RawPtr_to(const QBrush *, sfp[6]);
		const QBrush  text = *RawPtr_to(const QBrush *, sfp[7]);
		const QBrush  bright_text = *RawPtr_to(const QBrush *, sfp[8]);
		const QBrush  base = *RawPtr_to(const QBrush *, sfp[9]);
		const QBrush  window = *RawPtr_to(const QBrush *, sfp[10]);
		qp->setColorGroup(cg, windowText, button, light, dark, mid, text, bright_text, base, window);
	}
	RETURNvoid_();
}

//void QPalette.setCurrentColorGroup(int cg);
KMETHOD QPalette_setCurrentColorGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		QPalette::ColorGroup cg = Int_to(QPalette::ColorGroup, sfp[1]);
		qp->setCurrentColorGroup(cg);
	}
	RETURNvoid_();
}

//QBrush QPalette.shadow();
KMETHOD QPalette_shadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->shadow();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.text();
KMETHOD QPalette_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->text();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.toolTipBase();
KMETHOD QPalette_toolTipBase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->toolTipBase();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.toolTipText();
KMETHOD QPalette_toolTipText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->toolTipText();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.window();
KMETHOD QPalette_window(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->window();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QPalette.windowText();
KMETHOD QPalette_windowText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *  qp = RawPtr_to(QPalette *, sfp[0]);
	if (qp) {
		const QBrush ret_v = qp->windowText();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QPalette.parents();
KMETHOD QPalette_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPalette *qp = RawPtr_to(QPalette*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQPalette::DummyQPalette()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPalette::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPalette::self = ptr;
}

bool DummyQPalette::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPalette::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPalette::event_map->bigin();
	if ((itr = DummyQPalette::event_map->find(str)) == DummyQPalette::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPalette::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPalette::slot_map->bigin();
	if ((itr = DummyQPalette::slot_map->find(str)) == DummyQPalette::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQPalette::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQPalette::connection(QObject *o)
{
	QPalette *p = dynamic_cast<QPalette*>(o);
	if (p != NULL) {
	}
}

KQPalette::KQPalette() : QPalette()
{
	self = NULL;
	dummy = new DummyQPalette();
}

KMETHOD QPalette_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPalette *qp = RawPtr_to(KQPalette *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPalette]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPalette]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPalette_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPalette *qp = RawPtr_to(KQPalette *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPalette]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPalette]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPalette_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPalette *qp = (KQPalette *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPalette_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPalette *qp = (KQPalette *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPalette_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QPalette*>(p1->rawptr) == *static_cast<QPalette*>(p2->rawptr) ? 0 : 1);
}

void KQPalette::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QPaletteConstInt[] = {
	{"Disabled", QPalette::Disabled},
	{"Active", QPalette::Active},
	{"Inactive", QPalette::Inactive},
	{"Normal", QPalette::Normal},
	{"Window", QPalette::Window},
	{"Background", QPalette::Background},
	{"WindowText", QPalette::WindowText},
	{"Foreground", QPalette::Foreground},
	{"Base", QPalette::Base},
	{"AlternateBase", QPalette::AlternateBase},
	{"ToolTipBase", QPalette::ToolTipBase},
	{"ToolTipText", QPalette::ToolTipText},
	{"Text", QPalette::Text},
	{"Button", QPalette::Button},
	{"ButtonText", QPalette::ButtonText},
	{"BrightText", QPalette::BrightText},
	{"Light", QPalette::Light},
	{"Midlight", QPalette::Midlight},
	{"Dark", QPalette::Dark},
	{"Mid", QPalette::Mid},
	{"Shadow", QPalette::Shadow},
	{"Highlight", QPalette::Highlight},
	{"HighlightedText", QPalette::HighlightedText},
	{"Link", QPalette::Link},
	{"LinkVisited", QPalette::LinkVisited},
	{"NoRole", QPalette::NoRole},
	{NULL, 0}
};

DEFAPI(void) constQPalette(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPaletteConstInt);
}


DEFAPI(void) defQPalette(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPalette";
	cdef->free = QPalette_free;
	cdef->reftrace = QPalette_reftrace;
	cdef->compareTo = QPalette_compareTo;
}


