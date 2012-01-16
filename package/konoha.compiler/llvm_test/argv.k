
class A {
    String n;
    A() {
        n = "a";
        String[] argv = $script.argv;
        OUT.println(argv);
        for (int i=0; i < argv.size; i++) {
            String s = argv[i];
            OUT.println(s);
        }
    }
}
new A();
void main (String[] args) {
    String[] argv = $script.argv;
    print args;
    print argv;
}
