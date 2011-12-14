using konoha.compiler.*;
void main() {
    String s = "hello";
    String t = "bye";
    Regex r = new Regex("hello", "g");
    OUT.println(s.equals("hello"));
    OUT.println(s.startsWith("h"));
    OUT.println(t.endsWith("e"));
    OUT.println(s.concat(t));
    OUT.println(s.replace(r, "bye"));
    OUT.println(s.split("e"));
    OUT.println(s.indexOf("e"));
    OUT.println(s.lastIndexof("l"));
    OUT.println(s.getSize());
}
