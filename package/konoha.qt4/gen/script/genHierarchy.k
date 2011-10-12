class QtHierarchy {
	Path p;
	XmlReader reader;
	String[] parent_stack;
	String[] defined_classes;
	String tmp;
	String[] list;

	QtHierarchy() {
		p = QT_DOC_DIR + "hierarchy.html";
		reader = new XmlReader(p);
		parent_stack = [];
		tmp = "";
		list = [];
//		list <<< "QModelIndexList = Array<QModelIndex>;\n";
		defined_classes = [];
//		defined_classes <<< "";
		initReaderPosition();
		genHierarchy()
	}

	void initReaderPosition() {
		while (reader.read()) {
			if (reader.nodeType() == XmlReader.TYPE_END_ELEMENT &&
				reader.constName() == "h1")
				return;
		}
	}

	boolean checkDefinedClass(String class_name) {
		foreach (String defined_class in defined_classes) {
			if (class_name == defined_class) return true;
		}
		return false;
	}

	void genHierarchy() {
		String declaration = "";
		while (reader.read()) {
			switch (reader.nodeType()) {
			case XmlReader.TYPE_TEXT:
				String value = reader.constValue();
				declaration = "";
				if (checkDefinedClass(value) || "::" in? value) {
					declaration += "//";
				}
				int i;
				for (i = 0; i < |UNUSED_CLASSES|; i++) {
					if (UNUSED_CLASSES[i] in? value) {
						break;
					}
				}
				if (i == |UNUSED_CLASSES|) declaration += "@Native ";
				declaration += "class ";
				declaration += value;
				if (|parent_stack| != 0) {
					declaration += " extends ";
					declaration += parent_stack[|parent_stack| - 1];
				}
				declaration += ";";
				list <<< declaration + "\n";
				tmp = value;
				defined_classes <<< value;
				break;
			case XmlReader.TYPE_ELEMENT:
				if (reader.constName() == "ul") {
					if (tmp != "") {
						parent_stack <<< tmp;
					}
				}
				break;
			case XmlReader.TYPE_END_ELEMENT:
				if (reader.constName() == "ul") {
					if (|parent_stack| != 0) {
						parent_stack.pop();
					}
				}
				if (reader.constName() == "div") {
					return;
				}
				break;
			}
		}
		return;
	}
}

// int main() {
// 	QtHierarchy h = new QtHierarchy();
// 	OUT << h.list << EOL;
// }
