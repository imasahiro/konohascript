class QtXmlReader {
	InputStream ins;
	String all;
	String node;
	int type;
	String name;
	String value;
	int index;
	String[] ignore_list;

	QtXmlReader (String input_urn) {
		all = "";
		type = -1;
		name = "";
		value = "";
		index = 0;
		initList();
		ins = new InputStream(input_urn);
		foreach (String line in ins) {
			all += line;
		}
	}

	void close() {
		ins.close();
	}

	int nodeType() {
		return type;
	}

	String constName() {
		return name;
	}

	String constValue() {
		return value;
	}

	void initList() {
		ignore_list = [
			"\n", "\t", " "
		];
	}

	void extractedNode() {
		boolean break_flag = false;
		while (true) {
			break_flag = true;
			foreach (il in ignore_list) {
				if (all[index] == il) {
					index++;
					break_flag = false;
				}
			}
			if (break_flag) break;
		}

		int node_start = index, node_end = index;

		if (all[index] == "<") {
			while (all[node_end] != ">") node_end++;
			node_end++;
		} else {
			while (all[node_end] != "<") node_end++;
		}
		if (node_end == |all|) {
			node_end = 0;
			node = all[node_start : node_end];
			index = |all|;
		} else {
			node = all[node_start : node_end];
			index = node_end;
		}
	}

	void parseNode() {
		if (node.startsWith("<")) {
			if (node[1] == "/") {
				type = XmlReader.TYPE_END_ELEMENT;
			} else {
				type = XmlReader.TYPE_ELEMENT;
			}
			tmp = node - "<" - "/";
			int name_end = 0;
			while (tmp[name_end] != ">" &&
				   tmp[name_end] != " ") {
				name_end++;
			}
			name = tmp[0 : name_end];
			value = "";
		} else {
			type = XmlReader.TYPE_TEXT;
			name = "text";
			value = node;
		}
		return;
	}

	boolean read() {
		if (|all| <= index)	return false;
		extractedNode();
		parseNode();
		return true;
	}

	int indexOf(String str) {
		return all.indexOf(str);
	}
}
