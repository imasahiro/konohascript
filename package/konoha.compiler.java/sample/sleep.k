using konoha.compiler.java.*;

Frame = Java_awt_Frame
Button = Java_awt_Button
Label = Java_awt_Label
FlowLayout = Java_awt_FlowLayout
ActionListener = Java_awt_event_ActionListener
ActionEvent = Java_awt_event_ActionEvent
Font = Java_awt_Font
Color = Java_awt_Color
Thread = Java_lang_Thread

void addHoge(Component com) {
	Label l = new Label("hoge");
	l.setFont(new Font("", 1, int.random(30) + 10));
	l.setForeground(new Color(int.random(256), int.random(256), int.random(256)));
	com.add(l);
	com.revalidate();
}

void main() {
	Frame f = new Frame();
	f.setLayout(new FlowLayout());
	f.setTitle("test frame");
	f.setSize(400, 300);
	f.setVisible(true);
	while(true) {
		addHoge(f);
		Thread.sleep(100);
	}
}

