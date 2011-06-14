using konoha.lang.*;

void f(int n) {
	if (n < 3) print "n < 3";
	else if (n > 3) print "n > 3";
	else print "3";
	print "end";
}

void main (String[] args)
{
	Func func = f;
	BasicBlock bb = func.getEntryBasicBlock();
	for (int i = 0; i < insts.size; i++) {
		print insts[i];
	}
}

