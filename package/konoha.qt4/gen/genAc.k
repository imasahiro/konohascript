using konoha.lang.*;
using konoha.posix.*;
using konoha.xml.*;
using konoha.qt4.*;

GEN_CPP_SRC = true;
GEN_ENUM_BIND = true;
OUTPUT_ALL_METHODS = true;
OUTPUT_EVENT_BIND = true;
GEN_CONCATENATE_FILE = true;

include "gen/config.k";
include "gen/script/constStringList.k";
include "gen/script/EnumInterface.k";
include "gen/script/QtXmlReader.k";
include "gen/script/QtInterface.k";
include "gen/script/bind.k";
include "gen/script/FunctionElement.k";
include "gen/script/BindInfo.k";
include "gen/script/makeQtInterface.k";
include "gen/script/makeBindInfo.k";
include "gen/script/event.k";
include "gen/script/genHierarchy.k";

String initClass(String type, String name, int indent_num = 0) {
	String ret = "<T><TYPE> <NAME> = new <TYPE>(<ARGS>);";
	String a = "";
	String b = "";
	String args = "";

/*not have operator==
  QCursor, QGraphicsEffect, QLayout, QStyle, QIcon, QTreeWidgetItem, QSplashScreen
  QPixmap, 
*/
	switch (type) {
	case "QSize":
		b = "<T><NAME>.setHeight(8);\n<T><NAME>.setWidth(6);\n";
		break;
	case "QDate":
		b = "<T><NAME>.setDate(2011, 10, 31);\n";
		break;
	case "QDateTime":
		b = "<T>QDate d = new ();\n";
		b += "<T>d.setDate(2011, 11, 2);\n";
		b += "<T><NAME>.setDate(d);\n";
		break;
	case "QTime":
		b = "<T><NAME>.setHMS(20, 23, 27);\n";
		break;
	case "QPainterPath":
		b = "<T>QRectF r = new ();\n";
		b += "<T>r.setRect(20, 20, 60, 60);\n";
		b += "<T><NAME>.addRect(r);\n";
		break;
	case "QSplashScreen":
		a = "QPixmap p = new ();\n";
		args = "p";
		break;
	case "QMoveEvent":
		a = "QPoint pos = new ();\n";
		a += "QPoint old_pos = new ();\n";
		args = "pos, old_pos";
		break;
	case "QtWindowFlags":
		args = "3";
		break;
	case "QtAlignment":
		args = "1";
		break;
	default:
	}

	ret = a + ret + (b == "" ? b : "\n" + b);

	String indent = "";
	for (int i = 0; i < indent_num; i++) {
		indent += "\t";
	}
	ret = ret.replace("<A>", a);
	ret = ret.replace("<B>", b);
	ret = ret.replace("<NAME>", name);
	ret = ret.replace("<ARGS>", args);
	ret = ret.replace("<TYPE>", type);
	ret = ret.replace("<T>", indent);

	return ret;
}


String constArrayStr(String name = "a", String type)
{
	String ret = "\tArray<<TYPE>> <NAME> = ";
	switch (type) {
	case "int":
		ret += "[0, 1, 2, 3];\n";
		break;
	case "float":
		ret += "[0.0, 0.1, 0.2, 0.3]\n";
		break;
	case "boolean":
		ret += "[true, false, true, false]\n";
		break;
	case "String":
		ret += "[\"hogehoge\", \"fugafuga\"]\n";
		break;
	default:
		if (type.startsWith("Q")) {
			ret += "[elem1, elem2];\n";
			String tmp = """
	TYPE elem1 = new TYPE();
	TYPE elem2 = new TYPE();
""";
			ret  = tmp + ret;
		}
	}
	ret = ret.replace("<NAME>", name);
	ret = ret.replace("<TYPE>", type);
	return ret;
}

class Mtd {
	String field_name;
	FunctionElement fe_getter;
	FunctionElement fe_setter;
	String fe_getter_ac;
	String fe_setter_ac;
	String ac_body;

	Mtd() {
		field_name = "";
		fe_getter = null;
		fe_setter = null;
		fe_getter_ac = "";
		fe_setter_ac = "";
		ac_body = "";
	}

	void makeAcBody(String getter_return_type) {
		if (field_name == "Mask" ||
			field_name == "Property") return;
		foreach (String key in UNUSED_CLASSES) {
			if (key in? getter_return_type) {
				return;
			}
		}

		switch (getter_return_type) {
		case "int":
			ac_body += "\tobj." + fe_setter.func_name + "(1);\n";
			ac_body += "\tassert obj." + fe_getter.func_name + "() == 1;\n";
			break;
		case "float":
		case "double":
			ac_body += "\tobj." + fe_setter.func_name + "(0.8);\n";
		ac_body += "\tassert obj." + fe_getter.func_name + "() == 0.8;\n";
		break;
		case "boolean":
			ac_body += "\tobj." + fe_setter.func_name + "(true);\n";
			ac_body += "\tassert obj." + fe_getter.func_name + "() == true;\n";
			ac_body += "\tobj." + fe_setter.func_name + "(false);\n";
			ac_body += "\tassert obj." + fe_getter.func_name + "() == false;\n";
			break;
		case "String":
			ac_body += "\tobj." + fe_setter.func_name + "(\"hogehoge\");\n";
			ac_body += "\tassert obj." + fe_getter.func_name + "() == \"hogehoge\";\n";
			break;
		default:
			if ("Array<" in? getter_return_type) {
			 	String type = getter_return_type - "Array<" - ">";
//				if (field_name == "TabPositions") print this;
				if ("::" in? fe_getter.return_value_type && !fe_getter.return_value_type_object_flag) {
//					print "int";
					ac_body += constArrayStr("int");
				} else {
//					print type;
					ac_body += constArrayStr(type);
				}
			 	ac_body += "\tobj." + fe_setter.func_name + "(a);\n";
			 	ac_body += "\tassert obj." + fe_getter.func_name + "() == a;\n";
			} else if (getter_return_type.startsWith("Q")) {
				if (getter_return_type == "QTextCodec" ||
					getter_return_type == "QFileSystemModel" ||
					getter_return_type == "QListView") {
					throw new UNUSED_METHOD!!();
				}
				ac_body += QClass(getter_return_type);
				// ac_body += "\t" + getter_return_type + " arg = new " + getter_return_type + "();\n";
				// ac_body += "\tobj." + fe_setter.func_name + "(arg);\n";
				// ac_body += "\tassert obj." + fe_getter.func_name + " == arg;\n";
			} else {
				print "error: no return type match to " + getter_return_type + " in " + field_name + " of " + fe_getter.class_name;
			}
		}
	}
	
	String QClass(String type) {
		String ret = "";
		switch (type) {
		case "QGraphicsLayout":
//			ret += QClassCase("QGraphicsAnchorLayout", type, 0);
			ret += QClassCase("QGraphicsGridLayout", type, 1);
			ret += QClassCase("QGraphicsLinearLayout", type, 2);
			break;
		case "QGraphicsLayoutItem":
//			ret += QClassCase("QGraphicsLayout", type, 0);
			ret += QClassCase("QGraphicsWidget", type, 1);
			break;
		case "QGraphicsEffect":
			ret += QClassCase("QGraphicsBlurEffect", type, 0);
			ret += QClassCase("QGraphicsColorizeEffect", type, 1);
			ret += QClassCase("QGraphicsDropShadowEffect", type, 2);
			ret += QClassCase("QGraphicsOpacityEffect", type, 3);
			break;
		case "QAccessibleObject":
			ret += QClassCase("QAccessibleWidget", type);
			break;
		case "QGraphicsItem":
//			ret += QClassCase("QAbstractGraphicsShapeItem", type, 0);
			ret += QClassCase("QGraphicsItemGroup", type, 1);
			ret += QClassCase("QGraphicsLineItem", type, 2);
//			ret += QClassCase("QGraphicsObject", type, 3);
			ret += QClassCase("QGraphicsPixmapItem", type, 4);
			break;
		case "QGraphicsObject":
			ret += QClassCase("QDeclarativeItem", type, 0);
			ret += QClassCase("QGraphicsSvgItem", type, 1);
			ret += QClassCase("QGraphicsTextItem", type, 2);
			ret += QClassCase("QGraphicsWidget", type, 3);
			break;
		case "QIODevice":
			ret += QClassCase("Q3Socket", type, 0);
			ret += QClassCase("Q3SocketDevice", type, 1);
			ret += QClassCase("QAbstractSocket", type, 2);
			ret += QClassCase("QBuffer", type, 3);
			ret += QClassCase("QFile", type, 4);
			ret += QClassCase("QLocalSocket", type, 5);
			ret += QClassCase("QNetworkReply", type, 6);
			ret += QClassCase("QProcess", type, 7);
			break;
		case "QAbstractTextDocumentLayout":
			ret += QClassCase("QPlainTextDocumentLayout", type, 0);
			break;
		case "QValidator":
			ret += QClassCase("QDoubleValidator", type, 0);
			ret += QClassCase("QIntValidator", type, 1);
			ret += QClassCase("QRegExpValidator", type, 2);
			break;
		case "QRunnable":
			break;
		case "QGraphcisObject":
			ret += QClassCase("QDeclarativeItem", type, 0);
			ret += QClassCase("QGraphicsSvgItem", type, 1);
			ret += QClassCase("QGraphicsTextItem", type, 2);
			ret += QClassCase("QGraphicsWidget", type, 3);
			break;
		case "QLayout":
			ret += QClassCase("QBoxLayout", type, 0);
			ret += QClassCase("QFormLayout", type, 1);
			ret += QClassCase("QGridLayout", type, 2);
//			ret += QClassCase("QStackedLayout", type, 3);
			break;
		case "QLayoutItem":
			ret += QClassCase("QLayout", type, 0);
			ret += QClassCase("QSpacerItem", type, 1);
			ret += QClassCase("QWidgetItem", type, 2);
			break;
		case "QStyle":
			ret += QClassCase("QCommonStyle", type, 0);
			break;
		case "QGraphicsTransform":
			ret += QClassCase("QGraphicsRotation", type, 0);
			ret += QClassCase("QGraphicsScale", type, 1);
			break;
		case "QInputContext":
			break;
		case "QPaintEngine":
			ret += QClassCase("QRasterPaintEngine", type, 0);
			break;
		case "QAbstractItemDelegate":
			ret += QClassCase("QItemDelegate", type, 0);
			ret += QClassCase("QStyledItemDelegate", type, 1);
			break;
		case "QAbstractItemModel":
			ret += QClassCase("QDirModel", type, 0);
//			ret += QClassCase("QFileSystemModel", type, 1);
			ret += QClassCase("QHelpContentModel", type, 2);
			ret += QClassCase("QProxyModel", type, 3);
			ret += QClassCase("QStandardItemModel", type, 4);
			ret += QClassCase("QStringListModel", type, 5);
			ret += QClassCase("QSortFilterProxyModel", type, 6);
			ret += QClassCase("QSqlQueryModel", type, 7);
			break;
		case "QAbstractItemView":
			ret += QClassCase("QColumnView", type, 0);
			ret += QClassCase("QHeaderView", type, 1);
//			ret += QClassCase("QListView", type, 2);
			ret += QClassCase("QTableView", type, 3);
			ret += QClassCase("QTreeView", type, 4);
			break;
		case "QAbstractButton":
			ret += QClassCase("QCheckBox", type, 0);
			ret += QClassCase("QPushButton", type, 1);
			ret += QClassCase("QRadioButton", type, 2);
			ret += QClassCase("QToolButton", type, 3);
			break;
		case "QAbstractState":
			ret += QClassCase("QFinalState", type, 0);
			ret += QClassCase("QHistoryState", type, 1);
			ret += QClassCase("QState", type, 2); //konoha panic
			break;
		case "QPaintDevice":
			ret += QClassCase("QCustomRasterPaintDevice", type, 0);
			ret += QClassCase("QGLFramebufferObject", type, 1);
			ret += QClassCase("QGLPixelBuffer", type, 2);
			ret += QClassCase("QImage", type, 3);
			ret += QClassCase("QPicture", type, 4);
			ret += QClassCase("QPixmap", type, 5);
			ret += QClassCase("QPrinter", type, 6);
			ret += QClassCase("QSvgGenerator", type, 7);
			ret += QClassCase("QWidget", type, 8);
			break;
		default:
			ret += QClassCase(type);
		}
		return ret;
	}


	String QClassCase(String type, String parent_type = "", int arg_num = 0) {
		String ret = """
<INIT>
	obj.<SETTER>((<PTYPE>)arg<NUM>);
	<PTYPE> ret = (<PTYPE>)arg<NUM>;
	assert ret == obj.<GETTER>();
""";
		ret = ret.replace("<INIT>", initClass(type, "arg<NUM>", 1));
//		ret = ret.replace("<TYPE>", type);
		ret = ret.replace("<NUM>", (String)arg_num);
		ret = ret.replace("<PTYPE>", (parent_type == "" ? type : parent_type));
		ret = ret.replace("<SETTER>", fe_setter.func_name);
		ret = ret.replace("<GETTER>", fe_getter.func_name);

		return ret;
	}
}



Mtd[] GetterAndSetter(FunctionElement[] fea)
{
	if (|fea| == 0) {
//		print "empty";
		return [];
	}

	Mtd[] field_access_mtds = [];

	foreach (FunctionElement fe in fea) {
		if (fe.overloadFlag) continue;
		if ("get" in? fe.func_name) {
//			print "getter";
			String field_name = fe.func_name - "get";
			int index = 0;
			for (index = 0; index < |field_access_mtds|; index++) {
				if (field_access_mtds[index].field_name == field_name) break;
			}
			if (index != |field_access_mtds|) {
				field_access_mtds[index].fe_getter = fe;
			} else {
				Mtd m = new Mtd();
				m.field_name = field_name;
				m.fe_getter = fe;
				field_access_mtds <<< m;
			}
		} else if ("set" in? fe.func_name) {
//			print "setter";
			String field_name = fe.func_name - "set";
			int index = 0;
			for (index = 0; index < |field_access_mtds|; index++) {
				if (field_access_mtds[index].field_name == field_name) break;
			}
			if (index != |field_access_mtds|) {
				field_access_mtds[index].fe_setter = fe;
			} else {
				Mtd m = new Mtd();
				m.field_name = field_name;
				m.fe_setter = fe;
				field_access_mtds <<< m;
			}
		}
	}

	for (int i = 0; i < |field_access_mtds|; i++) {
		if (field_access_mtds[i].fe_getter == null ||
			field_access_mtds[i].fe_setter == null) {
			field_access_mtds.remove(i);
			i--;
		}
	}

	return field_access_mtds;
}

boolean checkHaveAbstractParent(BindInfo bi, BindInfo[] bia)
{
	foreach (int index in bi.parent_index) {
		if (bia[index].abstract_class_flag) return true;
	}
	return false;
}

String genMtdAssure(String class_name, Mtd m)
{
	if (m.ac_body == "") return "";
	String ret = """

assure \"<M>\" {
<B>}
""";

	ret = ret.replace("<M>", m.field_name);
	ret = ret.replace("<C>", class_name);
	ret = ret.replace("<B>", m.ac_body);

	return ret;
}

String knhReturnType(FunctionElement fe)
{
	fe.genBind();
	String kinterface = fe.genKonohaInterface();
	String[] token = kinterface.split(" ");
	int i = 0;
	for (i = 0; i < |token|; i++) {
		if (!("@" in? token[i])) break;
	}
	return token[i];
}

String genAssure(String class_name, Mtd[] ms)
{
	Dir src_dir = System.openDir("ac/");
	if (src_dir == null) System.exec("mkdir ac");

	String ac = "";
	foreach (m in ms) {
		try {
//		String knh_return_type = convertKonohaType(m.fe_getter.return_value_type);
			String knh_return_type = knhReturnType(m.fe_getter);
			m.makeAcBody(knh_return_type);
			ac += genMtdAssure(class_name, m);
		}
		catch (UNUSED_METHOD!! um) {
		}
	}

	return ac;
}

String genConstructor(BindInfo bi)
{
	String ret = "";
	ret += initClass(bi.class_name, "obj", 0);
	return ret;
}

void main()
{
	QtHierarchy hierarchy = new QtHierarchy();
	QtInterface[] interfaces = makeQtInterface(QT_DOC_DIR, hierarchy);
	if (|interfaces| == 0) {
		print "makeInterface error";
		return;
	}
	BindInfo[] bia = makeBindInfo(interfaces, hierarchy);
	genEventSource(bia, interfaces);

	foreach (BindInfo bi in bia) {
		try {
			if (bi.checkUnusedClass() ||
				bi.abstract_class_flag ||
				!bi.checkHaveConstructor()) continue;
			Mtd[] mtds = GetterAndSetter(bi.fea);
			String ac = "";
			ac += """
using konoha.qt4.*;

QApplication app = new QApplication();
<CONSTRUCTOR>
""";
			ac = ac.replace("<CONSTRUCTOR>", genConstructor(bi));
			ac += genAssure(bi.class_name, mtds);

//			String[] parents = getClassParents(bi.class_name);
			// if (|parents| != 0) {
			// 	foreach (String parent in parents) {
			// 		int index = BIsearchClassIndex(bia, parent - "konoha.qt4.");
			// 		Mtd[] mtds = GetterAndSetter(bia[index].fea);
			// 		ac += "\n//method of " + bia[index].class_name;
			// 		ac += genAssure(bi.class_name, mtds);
			// 	}
			// }

			ous = new OutputStream("ac/" + bi.class_name + ".k");
			ous.println(ac);
			ous.flush();
			ous.close();
		}
		catch (UNUSED_CLASS!! uc) {
//			print "not make ac of " + ;
		}
	}
	print "exit nomally";
}
