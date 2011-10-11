using konoha.actor.*;

void process_done() {
	print "done";
}

int main (String[] args) {
	a = actor:localhost:2000;
	print a;
	a.eval("""
void f() {
	OUT << "hello world" << EOL;
}""");
	a.eval("f()");
	return 0;
}
