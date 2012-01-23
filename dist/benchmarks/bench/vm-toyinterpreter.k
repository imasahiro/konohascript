/*
 * toy interpreter
 * see http://lua-users.org/lists/lua-l/2010-02/msg00323.html
 */

include "_bench.k";
N=10000000;

// these are the opcodes for the interpreted language
JUMP_IF_A  = 1;
MOV_A_R    = 2;
MOV_R_A    = 3;
ADD_R_TO_A = 4;
DECR_A     = 5;
RETURN_A   = 6;

// the main interpreter loop
int interpret(Int[] bytecode, int a) {
    int pc = 0;
    Int[] regs = new Int[256];
    while (true) {
        int opcode = bytecode[pc];
        pc += 1;
        if (opcode == JUMP_IF_A) {
            int target = bytecode[pc];
            pc += 1;
            if (a > 0) {
                pc = target;
            }
        }
        else if (opcode == MOV_A_R) {
            int n = bytecode[pc];
            pc += 1;
            regs[n] = a;

        }
        else if (opcode == MOV_R_A) {
            int n = bytecode[pc];
            pc += 1;
            a = regs[n];

        }
        else if (opcode == ADD_R_TO_A) {
            int n = bytecode[pc];
            pc += 1;
            a += regs[n];
        }
        else if (opcode == DECR_A) {
            a -= 1;
        }
        else if (opcode == RETURN_A) {
            return a;
        }
    }
    return 0;
}

class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "toy interpreter N="+N;
    }
    @Override void run() {
        // the program we want to interpret
        // it computes the square of its argument
        Int[] bytecode = [
            MOV_A_R,    0, // i = a
            MOV_A_R,    1, // copy of 'a'
            // 4:
            MOV_R_A,    0, // i--
            DECR_A,
            MOV_A_R,    0,
            MOV_R_A,    2, // res += a
            ADD_R_TO_A, 1,
            MOV_A_R,    2,
            MOV_R_A,    0, // if i!=0: goto 4
            JUMP_IF_A,  4,
            MOV_R_A,    2,
            RETURN_A
                ];
        int n = N;
        OUT.println(interpret(bytecode, n));
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Bench1());
    bm.run();
}
