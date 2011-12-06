QGraphicsRectItem new_StaticRect(int x, int y, int width, int height)
{
	QGraphicsRectItem rect = new ();
	QRectF r = new QRectF();
	r.setRect(x, y, width, height);
	rect.setRect(r);
	QBrush brush = new QBrush();
	brush.setStyle(1);
	QColor syan = new QColor();
	syan.setNamedColor("#00ffff");
	brush.setColor(syan);
	rect.setBrush(brush);
	return rect;
}

QRectF new_QRectF(int x, int y, int width, int height)
{
	QRectF r = new QRectF();
	r.setRect(x, y, width, height);
	return r;
}

QGraphicsRectItem new_DynamicRect(int x, int y, int width, int height)
{
	QGraphicsRectItem rect = new ();
	QRectF r = new QRectF();
	r.setRect(x, y, width, height);
	rect.setRect(r);
	QBrush brush = new QBrush();
	brush.setStyle(1);
	QColor syan = new QColor();
	syan.setNamedColor("#00ffff");
	brush.setColor(syan);
	rect.setBrush(brush);

	rect.setDensity(1);
	rect.setRestitution(0);
	return rect;
}

QFont new_QFont(String font_name, int style, int font_size)
{
	QFont font = new QFont();
	font.setFamily(font_name);
	font.setPixelSize(font_size);
	//font.setPointSize(font_size);
	font.setStyle(style);
	font.setFixedPitch(true);
	return font;
}

QColor new_QColor(String name)
{
	QColor c = new QColor();
	c.setNamedColor(name);
	return c;
}

QBrush new_QBrush(QColor c)
{
	QBrush brush = new QBrush();
	brush.setColor(c);
	brush.setStyle(1);
	return brush;
}

QPen new_QPen(String name, int width)
{
	QPen pen = new QPen();
	QBrush brush = new_QBrush(new_QColor(name));
	pen.setBrush(brush);
	pen.setWidth(width);
	return pen;
}

QPointF new_QPointF(int x, int y)
{
	QPointF p = new QPointF();
	p.setX(x);
	p.setY(y);
	return p;
}

QGraphicsPixmapItem new_QGraphicsPixmapItem(dynamic d, int w, int h)
{
	QGraphicsPixmapItem ret = new QGraphicsPixmapItem();
	QPixmap pixmap;
	if (d.class == String) {
		pixmap = new QPixmap();
		pixmap.load((String)d);
		ret.setPixmap(pixmap);
		if (w != 0 && h != 0) {
			QSize size = new QSize();
			size.setWidth(w);
			size.setHeight(h);
			pixmap = pixmap.scaled(size);
			ret.setPixmap(pixmap);
		}
	} else if (d.class == QPixmap) {
		pixmap = (QPixmap)d;
		ret.setPixmap(pixmap);
		if (w != 0 && h != 0) {
			QSize size = new QSize();
			size.setWidth(w);
			size.setHeight(h);
			pixmap = pixmap.scaled(size);
			ret.setPixmap(pixmap);
		}
	} else {
		print "ERROR";
	}
	return ret;
}
