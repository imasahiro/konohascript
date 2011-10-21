/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
 *
 * All rights reserved.
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
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

using konoha.lang.*;
include "lib:gluelink";

//class Stmt {
//    int getSize();
//    Stmt  getS(int n);
//    Token getT(int n);
//    Class getC();
//    int getIndex();
//    int getESPIDX();
//}
//
//class Token {
//    Class getC();
//    int getIndex();
//    int type;
//}

class Compiler {
    Compiler() {}
    void asm(Stmt stmt) {
    }
    /* stmt = {...} */
    @Native void asmBLOCK(Stmt stmt) {}
    /* stmt = let stmt[1] = stmt[2] */
    void asmLET(Stmt stmt, Stmt lhs, Stmt rhs) {
    }
    /* stmt = if stmt[0] then stmt[1]:BLOCK else stmt[2] endif */
    void asmIF(Stmt stmt, Stmt stmtCond, Stmt stmtThen, Stmt stmtElse) {
        //int index = stmt.getIndex();
        //asm(stmtCond);
        //asmBlock(stmtThen);
        //asmBlock(stmtElse);
    }
    void asmSWITCH(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    }
    void asmWHILE(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    }
    void asmDO(Stmt stmt, Stmt stmtC, Stmt stmtBody) {
    }
    void asmFOR(Stmt stmt, Stmt stmt1, Stmt stmt2, Stmt stmt3, Stmt stmtBody) {
    }
    void asmFOREACH(Stmt stmt, Token tkVar, Stmt stmtItr, Stmt stmtBody, Stmt stmtVar) {
    }
    void asmBREAK(Stmt stmt, Stmt stmtLabel) {
    }
    void asmCONTINUE(Stmt stmt, Stmt stmtLabel) {
    }
    void asmTRY(Stmt stmt, Stmt stmtTry, Stmt stmtCATCH, Stmt stmtFINAL) {
    }
    void asmTHROW(Stmt stmt) {
        //int espidx = stmt.getESPIDX;
        //print espidx;
    }
    void asmRETURN(Stmt stmt, Stmt stmtRetExpr) {
        if (stmtRetExpr == null) {
        } else {
        }
    }
    void asmYIELD(Stmt stmt) {
        /* TODO */
    }
    void asmPRINT(Stmt stmt) {
        /* TODO */
    }
    void asmASSURE(Stmt stmt, Stmt stmtInit, Stmt stmtBody) {
    }
    void asmASSERT(Stmt stmt, Stmt cond) {
    }
    void asmERR(Stmt stmt, Token tkERR) {
    }

    void asmEXPR(Stmt stmt);
    void asmLETEXPR(Stmt stmt, int espidx, Token tkL, Stmt expr) {
    }
    void asmFUNCCALL(Stmt stmt, int espidx, Method mtd, Class c, Stmt stmt) {
    }
    void asmCALL(Stmt stmt, int espidx, Token tkMTD, Method mtd, Class c) {
    }
    void asmCALL1(Stmt stmt, int espidx, Stmt expr1, Stmt stmtPost) {
    }
    void asmBOX(Stmt stmt, int espidx, Class c, Stmt expr) {
    }
    void asmOPR(Stmt stmt, int espidx, Method mtd, Class c, Stmt lhs, Stmt rhs) {
    }
    void asmNEW(Stmt stmt, int espidx, Class thisCid, Method mtd) {
    }
    void asmTCAST(Stmt stmt, int espidx, TypeMap tmr, Stmt expr) {
    }
    void asmAND(Stmt stmt, int espidx) {
    }
    void asmOR(Stmt stmt, int espidx) {
    }
    void asmALT(Stmt stmt, int espidx) {
        /* TODO */
    }
    void asmTRI(Stmt stmt, int espidx, Stmt cond, Stmt lhs, Stmt rhs) {
        /* use CreateSelect */
    }
    void asmSEND(Stmt stmt, int espidx) {
    }
    void asmW1(Stmt stmt, int espidx, Method mtd, Token streamTk, Stmt expr) {
    }
    void asmFMTCALL(Stmt stmt, int espidx) {
        /* TODO */
    }
}

