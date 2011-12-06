using konoha.qt4.*;
using konoha.qt4.physics.*;
include "sample/util.k";

class Vector {
	int x;
	int y;
	Vector(int x, int y) {
		_x = x;
		_y = y;
	}
}

class Tetris {
	QGraphicsScene scene;
	QWorld world;
	QGraphicsRectItem cur_block;
	QGraphicsRectItem[] wall_blocks;
	QGraphicsRectItem[] fell_blocks;
	boolean spawnFlag;
	float angle;
	//QGraphicsItemGroup cur_block;
	int offset_x;
	int offset_y;
	Vector[] type_a;

	Tetris(int x, int y) {
		offset_x = x;
		offset_y = y;
		angle = 0.0f;
		spawnFlag = true;
		type_a = [new Vector(4, 0), new Vector(5, 0), new Vector(4, 1), new Vector(5, 1)];
		scene = new QGraphicsScene();
		QRectF r = new QRectF();
		r.setRect(0, 0, 600, 600);
		scene.setSceneRect(r);
		scene.addEvent("key-press-event", delegate(this, keyPressEvent));
		world = new QWorld(scene);
		world.setGravity(0.0f, -5.0f);
		world.addEvent("begin-contact-event", delegate(this, contactEvent));
		scene.addEvent("timer-event", delegate(this, spawnBlock));
	}

	void setWall() {
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 10; x++) {
				if (x == 0 || x == 9 || y == 19) {
					QGraphicsRectItem rect = new_StaticRect(x * 20 + offset_x, y * 20 + offset_y, 20, 20);
					rect.setFriction(1);
					rect.setRestitution(0);
					scene.addItem(rect);
					world.add(rect);
					wall_blocks << rect;
				}
			}
		}
	}

	void spawnBlock(void) {
		if (spawnFlag) {
			angle = 0.0f;
			spawnFlag = false;
			/*
			switch (0) {//Int.random(0)) {
			case 0:
				group = new QGraphicsItemGroup();
				prev = new_DynamicRect(offset_x + type_a[0].x * 20, offset_y + 20 * type_a[0].y, 20, 20);
				prev.setBrush(new_QBrush(new_QColor("#00ff00")));
				prev.setFriction(1);
				prev.setRestitution(0);
				group.addToGroup(prev);
				world.add(prev);
				QGraphicsRectItem first = prev;
				for (int i = 1; i < type_a.size; i++) {
					next = new_DynamicRect(offset_x + type_a[i].x * 20, offset_y + 20 * type_a[i].y, 20, 20);
					next.setBrush(new_QBrush(new_QColor("#00ff00")));
					next.setFriction(1);
					next.setRestitution(0);
					group.addToGroup(next);
					world.add(next);
					QDistanceJoint j = new (prev, next);
					j.setLength(22);
					scene.addItem(j);
					world.add(j);
					prev = next;
				}
				QDistanceJoint j = new (prev, first);
				j.setLength(22);
				scene.addItem(j);
				world.add(j);
				cur_block = group;
				scene.addItem(group);
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
			*/
			cur_block = new_DynamicRect(offset_x + 4 * 20, 0, 20, 20);
			cur_block.setFriction(1);
			cur_block.setRestitution(0);
			scene.addItem(cur_block);
			world.add(cur_block);
		}
	}

	void contactEvent(QGraphicsItem a, QGraphicsItem b) {
		//cannot create physics object in this event
		if (spawnFlag == false) spawnFlag = true;
	}

	void keyPressEvent(QGraphicsScene scene, QKeyEvent event) {
		switch (event.key()) {
		case Qt.Key_Left:
			QPointF pos = cur_block.pos;
			pos.setX(pos.x - 20);
			cur_block.setXForm(pos, 0);
			break;
		case Qt.Key_Right:
			QPointF pos = cur_block.pos;
			pos.setX(pos.x + 20);
			cur_block.setXForm(pos, 0);
			break;
		case Qt.Key_Up:
			angle += 90;
			QPointF pos = cur_block.pos;
			cur_block.setXForm(pos, angle);
			break;
		case Qt.Key_Down:
			angle -= 90;
			QPointF pos = cur_block.pos;
			cur_block.setXForm(pos, angle);
			break;
		default:
			break;
		}
	}

	void start() {
		QGraphicsView view = new ();
		view.setScene(scene);
		view.show();
		world.start();
		scene.startTimer(2000);
	}
}

QApplication app = new QApplication();
Tetris tetris = new Tetris(100, 100);
tetris.setWall();
tetris.start();
app.exec();
