
void main() {
	String s = "abcdec aa";
	OUT.println(s.split("c"));
	OUT.println(s.startsWith("abc"));
	OUT.println(s.endsWith("abc"));
	OUT.println(s.indexOf("cd"));
	OUT.println(s.size);
	OUT.println(s.substring(1, 2));
	if(s.split("c")[0] == "ab") {
		OUT.println("OK");
	}

	OUT.println(s.get(4));
	OUT.println(s.replace("a", "-"));
	OUT.println(s - "a");

	s = "123";
	OUT.println((to Int)s);
}

