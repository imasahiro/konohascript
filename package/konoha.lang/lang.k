/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//
// **************************************************************************

include "lib:gluelink";

/** 
class Charset extends String;

@Native Charset Charset.opLINK(String path, NameSpace _);

@Native @Const @Semantic StringEncoder : (Charset c) {
  return new StringEncoder(c);
}

@Native @Const @Semantic StringDecoder : (Charset c) {
  return new StringDecoder(c);
}
**/

@Public @Native boolean Object.hasMethod(String name);
@Public @Native dynamic Object.invokeMethod(String name, dynamic a, ...);

@Public @Native boolean System.addClassField(Class c, Class type, String name);

@Public @Native Class Class.opLINK(String path, NameSpace _);
@Public @Native @Static Class[] Class.query(String path);
@Public @Native int Class.getClassTablePtr();
@Public @Native Object Class.getNullValue();
@Public @Native Class Class.getP1();

@Public @Native Method Method.opLINK(String path, NameSpace _);
@Public @Native Method[] Class.getMethods(NameSpace _);
@Public @Native Method[] Object.getMethods(NameSpace _);
@Public @Native @Const Class Method.getReturnType();
@Public @Native @Const Class[]  Method.getParamTypes();
@Public @Native @Const String[] Method.getParamNames();
@Public @Native @Const String Method.getSourceCode();
@Public @Native String Method.toString();
@Public @Native String Method.getName();
@Public @Native boolean Method.isStatic();

@Public @Native Class TypeMap.getSource();
@Public @Native Class TypeMap.getTarget();
@Public @Native int Stmt.getStmtSize();
@Public @Native int Stmt.getESPIDX();
@Public @Native Stmt Stmt.next();
@Public @Native Token Stmt.getT(int n);
@Public @Native Stmt Stmt.getS(int n);
@Public @Native int Stmt.getStmtType();
@Public @Native Object Token.getD();
@Public @Native Token Stmt.toToken();
@Public @Native Stmt Stmt.getStmtPost();
@Public @Native int Token.getTT();
@Public @Native int Token.getT();
@Public @Native int Token.getTokenIndex();
@Public @Native Class Token.getTokenClass();
@Public @Native int Object.getPtr();
@Public @Native Class Method.getMethodClass();

/* *****************
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

***/
