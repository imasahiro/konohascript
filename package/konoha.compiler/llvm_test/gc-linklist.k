/*
 * create link list
 */
class A {
    A next;
}
COUNT = 10;
N = 1000;
LIST_SIZE = 100;

void main (String[] args) {
    A head = new A();
    for (int i=0; i < COUNT; i++) {
        for (int j=0; j < N; j++) {
            /* short live objects */
            for (int k=0; k < LIST_SIZE; k++) { new A(); }
            /* create link list */
            A a = new A();
            head.next = a;
            head = a;
        }
    }
}
