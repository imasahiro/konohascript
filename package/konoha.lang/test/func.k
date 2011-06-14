using konoha.lang.*;

void f() {
	a = 1;
	b = 2;
	print a + b;
}

void main (String[] args)
{
	Func func = f;
	Array<Instruction> insts = func.getBytecode();
	for (int i = 0; i < insts.size; i++) {
		print insts[i];
	}

	print "while mode";
	op = insts[0];
	while (op != null) {
		print op;
		op = op.next;
	}

	print "a";
	op = insts[insts.size - 1];
	while (op != null) {
		print op;
		op = op.prev;
	}
}

