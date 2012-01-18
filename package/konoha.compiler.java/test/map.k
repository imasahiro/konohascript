void main(String[] args) {
	Map<String, String> m = new();
	m["aa"] = "hello";
	m["bb"] = "world";
	m["cc"] = "hoge";

	OUT.println(m.size);
	m.remove("bb");

	if(args.size >= 1) {
		OUT.println(m[args[0]]);
	}
	OUT.println(m.keys());
}

