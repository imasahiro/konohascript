/*
 * access global variable
 */
N=1_000_00;
Int     a = 10;
Float   b = 10.0;
boolean c = true;
String  d = "10";
Object  e = new OutputStream();;

void test1() {
    for (int i=0; i < N; i++) {
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
        a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
    }
}
void test2() {
    for (int i=0; i < N; i++) {
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
        b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1; b=1;
    }
}
void test3() {
    for (int i=0; i < N; i++) {
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
        c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false; c=true; c=false;
    }
}
void test4() {
    for (int i=0; i < N; i++) {
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
        d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a"; d="a";
    }
}
void test5() {
    for (int i=0; i < N; i++) {
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
        e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e; e=e;
    }
}
void main (String[] args) {
    test1();
    test2();
    test3();
    test4();
    test5();
}

