using konoha.lang.*;

void f() {
	print "hi";
}

fc = f.kcode;
inst = fc[0];
fbb = fc.constructCfg();
inst.dump();
fbb.traverse();
print fbb.hasInst(inst);
