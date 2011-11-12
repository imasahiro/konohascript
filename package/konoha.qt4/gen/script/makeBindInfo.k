void debugBindInfo(BindInfo[] bia, String class_name)
{
	foreach (bi in bia) {
		if (class_name == bi.class_name) {
			print bi;
			return;
		}
	}
}

int BIsearchClassIndex(BindInfo[] bia, String class_name)
{
	int i;
	for (i = 0; i < |bia|; i++) {
		if (bia[i].class_name == class_name) return i;
	}
	return -1;
}

void BIsetParentIndex(BindInfo[] bia, QtHierarchy hierarchy)
{
//	ins = new InputStream("gen/hierarchy.k");
	foreach (String line in hierarchy.list) {
		line = line - "class " - ";" - "/" - "@Native " - "\n";
		String[] token = line.split(" ");
//		print token;
		if (|token| != 3) continue;
//		print token[0];
//		print token[2];

		int cci = BIsearchClassIndex(bia, token[0]); //child class index
		int pci = BIsearchClassIndex(bia, token[2]); //parent class index
		if (cci == -1 || pci == -1) continue;

		if (bia[cci].parent_index.indexOf(pci) == -1) {
			bia[cci].parent_index <<< pci;
			bia[cci].parent_name <<< token[2];
			bia[pci].children_index <<< cci;
			bia[pci].children_name <<< token[0];
		}
	}
	return;
}

int BIsetHierarchyDepth(BindInfo[] bia, BindInfo bi)
{
	if (bi.hierarchy_depth == -1) {
		if (|bi.parent_index| == 0) {
			bi.hierarchy_depth = 1;
			return 1;
		}
		int[] candidate = [];
		foreach (int index in bi.parent_index) {
			candidate <<< (BIsetHierarchyDepth(bia, bia[index]) + 1);
		}
		int ret = -1;
		foreach (int max in candidate) {
			if (ret < max) ret = max;
		}
		bi.hierarchy_depth = ret;
		return ret;
	} else {
		return bi.hierarchy_depth;
	}
}

void setInheritsQObjectFlag(BindInfo[] bia, BindInfo bi)
{
	bi.inherits_qobject_flag = true;
	foreach (int index in bi.children_index) {
		setInheritsQObjectFlag(bia, bia[index]);
	}
}

void setInheritsQGraphicsItemFlag(BindInfo[] bia, BindInfo bi)
{
	bi.inherits_qgraphicsitem_flag = true;
	foreach (int index in bi.children_index) {
		setInheritsQGraphicsItemFlag(bia, bia[index]);
	}
}

BindInfo[] makeBindInfo(QtInterface[] interfaces, QtHierarchy hierarchy) {
	OUT << "make BindInfo" << EOL;

	String[] supported_domain = ["QtGui", "QtCore", "QtWebKit", "QtOpenGL", "QtNetwork"];
	String[] binding_class = [];
	foreach (domain in supported_domain) {
		Dir dir = System.openDir(QT_INCLUDE_DIR + domain);
		foreach (String filename in dir.readName() ..) {
			if (filename.startsWith("Q") &&	filename != domain) {
				binding_class <<< filename;
			}
		}
	}

	BindInfo[] bia = [];
	for (int i = 0; i < |interfaces|; i++) {
		if (interfaces[i].class_name in? binding_class) {
			if (GEN_CPP_SRC) {
				BindInfo bi = new BindInfo(interfaces[i]);
				bi.qtInterfaceIndex = i;
				bia << bi;
			}
		}
	}
	BIsetParentIndex(bia, hierarchy);
	int qobject_index = -1;
	int qgraphcisitem_index = -1;
	for (int i = 0; i < |bia|; i++) {
		BIsetHierarchyDepth(bia, bia[i]);
		if (bia[i].class_name == "QObject") qobject_index = i;
		if (bia[i].class_name == "QGraphicsItem") qgraphicsitem_index = i;
	}
	setInheritsQObjectFlag(bia, bia[qobject_index]);
	setInheritsQGraphicsItemFlag(bia, bia[qgraphicsitem_index]);
//	debugBindInfo(bia, "QWidget");
	// foreach (bi in bia) {
	// 	if (bi.class_name == "QStyle") {
	// 		print bi;
	// 	}
	// }
	return bia;
}
