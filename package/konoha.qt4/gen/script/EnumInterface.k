class EnumInterface {
	String class_name;
	String name;
	String[] key;
	boolean public_flag;

	EnumInterface(String[] token = [], String cn = "") {
		class_name = "";
		name = "";
		key = [];
		public_flag = false;
		if (|token| == 0 || cn == "") return;
		class_name = cn;
		frontEnd(token);
		parse(token);
	}

	boolean isPublic() {
		return public_flag;
	}

	void frontEnd(String[] token) {
		for (int i = 0; i < |token|; i++) {
			if ((class_name + "::") in? token[i]) {
				token[i] = (token[i].split("::")).pop();
			} else {
				token.remove(i);
				i--;
			}
		}
		return;
	}

	void parse(String[] token) {
		if (|token| < 2) return;
		name = token[0];
		for (int i = 1; i < |token|; i++) {
			key <<< token[i];
		}
	}

	void checkAccessModifier(String[] public_types) { //detect public
		foreach (String public_type in public_types) {
			if ("enum" in? public_type &&
				name in? public_type) {
				public_flag = true;
				break;
			}
		}
	}
}
