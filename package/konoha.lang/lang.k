include nativelink;

@Native class Symbol;
@Native class Instruction;
@Native class Basicblock;
@Native class Controlflow;
@Native class ByteCode;

include func:InstructionCONST;

@Native Symbol Symbol.new(String name);
@Native String Symbol.getOrigName();

@Native Instruction Instruction.new(Int opcode, dynamic d1, dynamic d2, dynamic d3, dynamic d4, Instruction _);
@Native Symbol Instruction.getDefineSymbol();

@Native String Instruction.getOpname();
@Native Int Instruction.getOpcode();
@Native Array<Symbol> Instruction.getUseSymbolList();
@Native Boolean Instruction.isMerging();
@Native Boolean Instruction.approve(Int opcode);
@Native Instruction Instruction.getNext();
@Native Instruction Instruction.getPrev();

@Native Basicblock Basicblock.new();
@Native Instruction Basicblock.getInst(int i);
@Native Instruction Basicblock.getDefineInst(Symbol sym);
@Native Boolean Basicblock.removeInst(Instruction inst);
@Native Boolean Basicblock.insertBefore(Instruction inst1, Instruction inst2);
@Native Boolean Basicblock.insertAfter(Instruction inst1, Instruction inst2);
@Native Array<Basicblock> Basicblock.getSuccessors();
@Native Array<Basicblock> Basicblock.getPredecessors();

//@Native Controlflow Controlflow.new(Method mtd);
@Native Controlflow Method.getControlflow();
@Native Array<Symbol> Controlflow.getAllSymbolList();
@Native Array<Instruction> Controlflow.getUseInstList(Symbol sym);
@Native Array<Basicblock> Controlflow.getBasicblockList(Symbol sym);
@Native Basicblock Controlflow.getDefineBB(Symbol sym);

@Native Array<Instruction> Func.getInstList(Instruction _, Basicblock _);
@Native ByteCode Func.getBytecodes(Instruction _, Basicblock _, ByteCode _);
@Native Basicblock[] ByteCode.searchBBContains(Int opcode);
@Native Instruction Basicblock.getFirstInstruction();
@Native Basicblock Bytecode.getEntryBlock();
@Native Method ByteCode.save();

