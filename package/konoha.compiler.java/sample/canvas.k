using java.awt.*;
using java.awt.event.*;

Canvas cv;
int mouse_x=0, mouse_y=0;

class A extends MouseListener {
	@Override @Overload void mouseClicked(MouseEvent e) {
		mouse_x = e.x;
		mouse_y = e.y;
		cv.repaint();
	}
	@Override @Overload void mouseEntered(MouseEvent e) {}
	@Override @Overload void mouseExited(MouseEvent e) {}
	@Override @Overload void mousePressed(MouseEvent e) {}
	@Override @Overload void mouseReleased(MouseEvent e) {}
}

class B extends MouseMotionListener {
	@Override @Overload void mouseMoved(MouseEvent e) {
		mouse_x = e.x;
		mouse_y = e.y;
		cv.repaint();
	}
	@Override @Overload void mouseDragged(MouseEvent e) {}
}

class MyCanvas extends Canvas {
	MyCanvas() {
		setFont(new Font("", 1, 22));
	}
	@Override @Overload void paint(Graphics g) {
		g.setColor(new Color(0, 100, 0));
		g.fillRect(mouse_x-10, mouse_y-20, 100, 30);
		g.setColor(new Color(255, 200, 120));
		g.drawString("hello", mouse_x, mouse_y);
	}
}

void main() {
	Frame f = new Frame();
	f.setSize(600, 400);

	cv = new MyCanvas();
	cv.addMouseListener(new A());
	cv.addMouseMotionListener(new B());

	f.addMouseListener(new A());
	f.add(cv);
	f.setVisible(true);
	f.setTitle("jkonoha test window");
}

