using konoha.lang.*;

int f(int a) {
	int x = 0;
	if (a < 10) {
		x += 10;
	}
	else {
		x += 20;
	}
	/* print x; */
	return x;
}

b = f.getBytecodes();
BasicBlock[] bbList = b.searchBBContains(Instruction.NMOV);
for (int i=0; i < |bbList|; i++) {
	bb = bbList[i];
	inst = bb.getFirstInstruction();
	while (inst != null) {
		if (inst.opcode == Instruction.NMOV) {
			bb.insertAfter(inst, new Inst(Instruction.P, "%d", "x"));
		}
		inst = inst.next;
	}
}
b.save();
print f(10);

