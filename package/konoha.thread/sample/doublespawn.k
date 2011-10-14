using konoha.thread.*;

void spawn2() {
	print "hello";
}

void spawn1() {
	Thread.spawn(spawn2); // TODO
}

Thread.spawn(spawn1);

