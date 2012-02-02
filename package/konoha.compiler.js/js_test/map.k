using konoha.compiler.*;
void main() {
    m = new Map();
    m["hello"] = 1;
    m["bye"] = 2;
    OUT.println(m["hello"]);
    OUT.println(m.keys());
    m.remove("hello");
    OUT.println(m.keys());
    OUT.println(m.getSize());
}
