using konoha.thread.*;

void catchTest() {
	try{
		print "catch test";
		throw new Exception();
	}catch(Exception!! e){
		print e;
	}
}

void notCatchTest() {
	print "not catch test";
	throw new Exception(); // TODO
}

t1 = Thread.spawn(catchTest);
t2 = Thread.spawn(notCatchTest);

t1.join();
t2.join();

print "finish";

