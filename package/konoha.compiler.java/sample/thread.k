using konoha.compiler.java.*;

Runnable = Java_lang_Runnable
Thread = Java_lang_Thread

class A extends Runnable {
	int id;

	A(int id) {
		_id = id;
	}

	@Override void run() {
		for(int i=0; i<5; i++) {
			Thread.sleep(int.random(1000));
			OUT << "id= " + id + " count = " + i << EOL;
		}
	}
}

void main() {
	for(int i=1; i<=5; i++) {
		A a = new A(i);
		Thread t = new Thread(a);
		t.start();
	}
}

