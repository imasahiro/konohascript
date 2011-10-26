using konoha.thread.*;
using konoha.posix.*;

Mutex m = new Mutex();

void func(int i)
{
	m.lock();
	sleep(Int.random(2));
	print i;
	m.unlock();
}

void main()
{
	for(i=0; i<10; i++) {
		Thread.spawn(func, [i]);
	}
}
