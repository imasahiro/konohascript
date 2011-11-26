class FunctionElement {
	String return_value_type;
	String knh_return_value_type;
	String func_name;
	String declation;
	String class_name;
	String default_getter_name;
	String[] argument_types;
	String[] argument_names;
//	String[] default_arguments;
	String[] knh_argument_types;
	int argument_number;
	boolean staticFlag;
	boolean virtualFlag;
	boolean constructorFlag;
	boolean destructorFlag;
	boolean notMakeFlag;
	boolean funcGetterFlag;
	boolean overloadFlag;
	boolean overrideFlag;
	boolean pureVirtualFlag;
	boolean return_value_type_enum_flag;
	boolean return_value_type_object_flag;
	boolean[] argument_type_object_flags;

	FunctionElement(String dec, String cn) {
		argument_types = [];
		argument_names = [];
		knh_argument_types = [];
		knh_return_value_type = "";
		class_name = cn;
		declation = dec;
		argument_number = 0;
		funcGetterFlag = false;
		virtualFlag = false;
		constructorFlag = false;
		destructorFlag = false;
		notMakeFlag = false;
		overloadFlag = false;
		overrideFlag = false;
		pureVirtualFlag = false;
		staticFlag = false;
		default_arguments = [];

		parse();

		return_value_type_object_flag = false;
		argument_type_object_flags = [];
		for (int i = 0; i < |argument_types|; i++) {argument_type_object_flags <<< false;}
//		if (class_name == "QWidget" && func_name == "render") print this;
//		print declation;
//		print default_arguments;
	}

	Array<String> tokenize() {
		declation = declation.replace("QList<", "Array<");
		String[] token = declation.split(" ");
		if (token[|token| - 1] == "const") token.pop();
		for (int i = 0; i < |token|; i++) {
//			print token;
//			print i;
			switch (token[i]) {
			case "":
			case "&":
			case "Signals":
				token.remove(i);
				i--;
				break;
			case "const":
				token[i] += " " + token[i + 1];
				if (token[i + 1] == "unsigned") {
					token.remove(i + 1);
				} else {
					token.remove(i + 1);
					break;
				}
			case "unsigned":
				token[i] += " " + token[i + 1];
				token.remove(i + 1);
				break;
			case "=":
				boolean objFlag = false;
				while (true) {
					token.remove(i);
					if (|token| <= i) {
						break;
					} else if ("," in? token[i]) {
						if (!objFlag) {
							token.remove(i);
							i--;
							break;
						}
					} else if (token[i] == ")") {
						if (!objFlag) {
							i--;
						}
						break;
					} else if ("(" in? token[i]) {
						objFlag = true;
					}
//					print i;
				}
				break;
			case "virtual":
				virtualFlag = true;
				token.remove(i);
				i--;
				break;
			case ")":
			case "()":
				while (i + 1 < |token|) {
					token.remove(i + 1);
				}
				break;
			default:
				if ((token[i].indexOf(">") == -1) &&
					("<" in? token[i])) {
					int count = 0;
					for (int j = 0; j < |token[i]|; j++) {
						if (token[i][j] == "<")
							count++;
					}
					while (count != 0) {
						if (">" in? token[i + 1])
							count--;
						token[i] += token[i + 1];
						token.remove(i + 1);
					}
				} else if ("*" in? token[i]) {
					token[i - 1] += token[i];
					token.remove(i);
					i--;
				} else if ("&" in? token[i]) {
					token[i] -= "&";
					token[i - 1] += token[i];
					token.remove(i);
					i--;
				}
			}
		}
		return token;
	}



	void setElements(String[] token) {
//		print "setElements";
//		print token;
		int tc = 0;
		if (token[0].startsWith("~")) {
			destructorFlag = true;
			return;
		} else if (token[0] == class_name &&
				   (token[1] == "(" ||
					token[1] == "()")) {
			constructorFlag = true;
			return_value_type = class_name;
			func_name = "new";
			tc = 1;
		} else if (|token| < 3) {
			print "error";
			print token;
			notMakeFlag = true;
			return;
		} else {
			return_value_type = token[0];
			func_name = token[1];
			tc = 2;
		}
		if (token[|token| - 1] != "()" &&
			token[|token| - 1] != ")") {
			print "error: not method";
			print token;
			notMakeFlag = true;
			return;
		}
		if (token[tc] == "()") {
			argument_number = 0;
			return;
		} else {
			tc++;
			if (token[tc].endsWith(",") ||
				token[tc + 1] == ")") {
				int ac = 0;
				for (; token[tc] != ")"; ac++) {
					token[tc] -= ",";
					argument_types <<< token[tc];
					an = "arg" + (String)ac;
					argument_names <<< an;
					tc++;
				}
				argument_number = ac;
			} else {
//				print token[tc];
				int ac = 0;
				for (; token[tc] != ")"; ac++) {
//					print token[tc];
					argument_types <<< token[tc];
					tc++;
					token[tc] -= ",";
					argument_names <<< token[tc];
					tc++;
// 					if (token[tc] == "=") {
// 						String tmp = "";
// 						boolean objFlag = false;
// 						while (true) {
// 							tc++;
// 							tmp += token[tc];
// 							if ("," in? token[tc]) {
// 								if (!objFlag) {
// //									tmp += token[tc];
// 									tc++;
// 									break;
// 								}
// 							} else if (token[tc] == ")") {
// 								if (objFlag) {
// 									tmp += token[tc];
// 								}
// 								break;
// 							} else if (token[tc] == "(") {
// 								objFlag = true;
// 							}
// //							tmp += token[tc];
// 						}
// 						default_arguments.add(tmp);
// 					} else {
// 						default_arguments.add("");
// 					}
				}
				argument_number = ac;
			}
			return;
		}
		print "argument size error";
		print token;
		return;
	}

	boolean upperCheck(String s) {
		String upper_s = s.convert(to:upper);
		if (upper_s == s) {
			return true;
		}
		return false;
	}

	void renamePublicTypes(String[] public_enums, String[] typedefed_objects, Tuple<String, String>[] flag_objects, String[] class_objects) {

		// if (class_name == "QWidget" && func_name == "new") {
		// 	print flag_objects;
		// }

		String comp_return_type = return_value_type - "Array<" - ">" - "*" - "const" - " ";
		String[] comp_arg_types = [];
		foreach (String type in argument_types) {
			comp_arg_types <<< (type - "Array<" - ">" - "*" - "const" - " ");
		}

		foreach (String typedefed_object in typedefed_objects) {
			if (comp_return_type == typedefed_object) {
				notMakeFlag = true;
				return;
			}
			foreach (String type in comp_arg_types) {
				if (type == typedefed_object) {
					notMakeFlag = true;
					return;
				}
			}
		}

		foreach (String class_object in class_objects) {
			if (comp_return_type == class_object) {
				notMakeFlag = true;
				return;
			}
			foreach (String type in comp_arg_types) {
				if (type == class_object) {
					notMakeFlag = true;
					return;
				}
			}
		}

		foreach (String public_enum in public_enums) {
			if (comp_return_type == public_enum) {
				if (!("::" in? comp_return_type)) {
						return_value_type = return_value_type.replace(public_enum, class_name + "::" + public_enum);
				}
			}
			for (int i = 0; i < |argument_types|; i++) {
				if (comp_arg_types[i] == public_enum) {
					if (!("::" in? argument_types[i])) {
						argument_types[i] = argument_types[i].replace(public_enum, class_name + "::" + public_enum);
					}
				}
			}
		}

		// if (class_name == "QWidget" && func_name == "new") {
		// 	print flag_objects;
		// 	print comp_return_type;
		// 	print comp_arg_types;
		// }
		foreach (Tuple<String, String> flag_object in flag_objects) {
			if (comp_return_type == flag_object[1] ||
				comp_return_type == (flag_object[0] + "::" + flag_object[1])) {
				if (!("::" in? comp_return_type)) {
						return_value_type = return_value_type.replace(flag_object[1], flag_object[0] + "::" + flag_object[1]);
				}
				return_value_type_object_flag = true;
			}
			for (int i = 0; i < |argument_types|; i++) {
				if (comp_arg_types[i] == flag_object[1] ||
					comp_arg_types[i] == (flag_object[0] + "::" + flag_object[1])) {
					if (!("::" in? argument_types[i])) {
						argument_types[i] = argument_types[i].replace(flag_object[1], flag_object[0] + "::" + flag_object[1]);
					}
					argument_type_object_flags[i] = true;
				}
			}
		}

		return;
	}

	Array<String> parse() {
		String[] token = tokenize();
		setElements(token);
		convertUnusedArgName(argument_names);
//		if (class_name == "QLineEdit") print this;
		return token;
	}

	String argumentFormat() {
		string str = "";
		if (argument_number == 0)
			return str;
		for (int i = 0; i < argument_number; i++) {
			type = argument_types[i];
			name = argument_names[i];
			int j = i + 1;
			if (constructorFlag == false) {
				str += "\t\t";
			} else {
				str += "\t";
			}
			String exclude_const_type = type - "const ";
//			knh_token << exclude_const_type;
//			knh_token << name;
			if ((exclude_const_type.startsWith("i") || exclude_const_type.startsWith("q"))
				&& "int" in? type) {
				str += Int_to(name, type, j);
			} else if (exclude_const_type == "float" ||
					   exclude_const_type == "qreal") {
				str += Float_to(name, type, j);
			} else if ("bool" in? type) {
				str += Boolean_to(name, type, j);
			} else if ("QString" in? type) {
				str += String_to(name, type, j);
			} else {
				if ("Array<" in? type) {
					str += Array_to(name, type, j);
				} else if ("::" in? type &&
						   !argument_type_object_flags[i]) {
					str += Int_to(name, type, j);
				} else {
					str += RawPtr_to(name, type, j, argument_type_object_flags[i]);
				}
			}
		}
		return str;
	}

	String callFuncFormat(boolean make_rapper_class_flag = false, boolean have_private_destructor_flag = false) {
//		if (class_name == "QWidget") print make_rapper_class_flag;
		string str;
		int array_flag = -1, string_flag = 0, bool_flag = 0;
		if (constructorFlag) {
			if (make_rapper_class_flag) {
				str += ("\tK" + class_name + " *ret_v = new K" + class_name + "(");
			} else {
				str += ("\t" + class_name + " *ret_v = new " + class_name + "(");
			}
		} else {
			str += "\t\t";
			switch (return_value_type) {
			case "QString":
				string_flag = 1;
				break;
			case "bool":
				bool_flag = 1;
				break;
			default:
				array_flag = return_value_type.indexOf("Array<");
				break;
			}
			if (array_flag != -1) {
				str += (return_value_type.replace("Array<", "QList<") + " ret_v = ");
			} else if (return_value_type != "void") {
				str += (return_value_type + " ret_v = ");
			}
			if (staticFlag) {
				str += class_name + "::";
			} else if (have_private_destructor_flag) {
				str += "qp->q_self->";
			} else {
				str += "qp->";
			}
			if (funcGetterFlag == false) {
				str += func_name + "(";
			} else {
				str += default_getter_name + "(";
			}
		}
		for (int i = 0; i < (argument_number - 1); i++) {
			str += (argument_names[i] + ", ");
		}
		if (argument_number != 0)
			str += argument_names[argument_number - 1];
		str += ");\n";
		return str;
	}

	String returnFormat(boolean make_rapper_class_flag = false) {
		if (constructorFlag) {
//			knh_token.insert(0, class_name);
			if (make_rapper_class_flag) {
				return RETURNrc_();
			} else {
				return RETURNc_();
			}
		}
		String exclude_const_type = return_value_type - "const ";
//		knh_token.insert(0, exclude_const_type);
		if ("Array<" in? return_value_type) {
			return RETURNa_(return_value_type)
		} else if ("void" == return_value_type) {
			return RETURNvoid_();
		} else if ("*" in? return_value_type) {
			if (exclude_const_type.startsWith("i") &&
				"int" in? return_value_type) {
				return RETURNip_();
			} else if ("float" in? return_value_type ||
					   "qreal" in? return_value_type) {
				return RETURNfp_();
			} else if ("void" in? return_value_type) {
				return RETURNr_(return_value_type);
			} else {
				return RETURNr_(return_value_type);
			}
		} else if (exclude_const_type.startsWith("i") &&
				   "int" in? return_value_type) {
			return RETURNi_();
		} else if ("float" in? return_value_type ||
				   "qreal" in? return_value_type) {
			return RETURNf_();
		} else if ("bool" in? return_value_type) {
			return RETURNb_();
		} else if ("QString" in? return_value_type) {
			return RETURNs_();
		} else if ("::" in? return_value_type && !return_value_type_object_flag) {
			return RETURNi_();
		} else {
			return RETURNr_(return_value_type);
		}
	}

	String genBind(boolean make_rapper_class_flag, boolean have_private_destructor_flag) {
//		if (class_name == "QWidget") print make_rapper_class_flag;
		if (pureVirtualFlag) return "";

		String bind = "";

		switch (class_name) {
		case "QApplication":
			switch (func_name) {
			case "new":
				bind += QApplicationNew();
				break;
			case "exec":
				bind += QApplicationExec();
				break;
			}
			break;
		default:
			bind += ("KMETHOD " + class_name + "_" + func_name + "(CTX ctx, ksfp_t *sfp _RIX)\n");
			bind += "{\n";
			bind += "\t(void)ctx;\n";
			if (staticFlag) {
				bind += "\tif (true) {\n";
				bind += argumentFormat();
				bind += callFuncFormat();
				bind += returnFormat();
				bind += "\n";
			} else if (!constructorFlag) {
				bind += "\t" + RawPtr_to("qp", (have_private_destructor_flag ? "K" : "") + class_name + " *", 0);
				bind += "\tif (qp) {\n";
				bind += argumentFormat();
				bind += callFuncFormat(false, have_private_destructor_flag);
				bind += returnFormat();
				bind += "\n";
			} else {
				bind += argumentFormat();
				bind += callFuncFormat(make_rapper_class_flag);
				bind += returnFormat(make_rapper_class_flag);
//				if (class_name == "QApplication") return QApplicationNew();
			}
		}
		return bind;
	}

	void convertUnusedArgName(String[] ans) {
		for (int i = 0; i < |ans|; i++) {
			foreach (String[] unused_arg_name in UNUSED_ARG_NAMES) {
				ans[i] = ans[i].replace(unused_arg_name[0], unused_arg_name[1]);
			}
		}
	}

	String genKonohaInterface() {
		String konoha_interface = "";

		if (pureVirtualFlag) return "";
		if (virtualFlag) konoha_interface += "@Virtual ";
		if (overrideFlag) konoha_interface += "@Override ";

		konoha_interface += toKonohaType(return_value_type, return_value_type_object_flag) + " ";
		konoha_interface += class_name + ".";
		konoha_interface += func_name + "(";
		for (int i = 0; i < |argument_types|; i++) {
			konoha_interface += toKonohaType(argument_types[i], argument_type_object_flags[i]) + " ";
			konoha_interface += toKonohaArgName(argument_names[i]);
			if (i < |argument_types| - 1) {
				konoha_interface += ", ";
			}
		}
		konoha_interface += ");\n";

		return konoha_interface;
	}

	String toKonohaArgName(String arg_name) {
		String konoha_arg_name = arg_name;

		konoha_arg_name = konoha_arg_name.replace("Top", "top");
		konoha_arg_name = konoha_arg_name.replace("include", "inc");
		konoha_arg_name = konoha_arg_name.replace("string", "str");
		konoha_arg_name = konoha_arg_name.replace("Strings", "str");
		konoha_arg_name = konoha_arg_name.replace("Stringacters", "str");
		if (konoha_arg_name == "from") konoha_arg_name = "from_";
		if (konoha_arg_name == "to") konoha_arg_name = "to_";
		if (konoha_arg_name == "format") konoha_arg_name = "fmt";

		return konoha_arg_name;
	}

	void setKonohaTypes() {
		knh_return_value_type = toKonohaType(return_value_type, return_value_type_object_flag);
		for (int i = 0; i < |argument_types|; i++) {
			knh_argument_types <<< toKonohaType(argument_types[i], argument_type_object_flags[i]);
		}
	}

	String toKonohaType(String cpp_type, boolean object_flag = false) {
		String konoha_type = cpp_type;

		konoha_type = konoha_type.replace(" ", "");
		konoha_type = konoha_type.replace("const", "");
		konoha_type = konoha_type.replace("*", "");
		konoha_type = konoha_type.replace("bool", "boolean");
		konoha_type = konoha_type.replace("qreal", "float");
		konoha_type = konoha_type.replace("QString", "String");
		konoha_type = konoha_type.replace("uchar", "String");
		konoha_type = konoha_type.replace("unsigned", "");
		if (konoha_type == "char") konoha_type = "String";
		if (konoha_type == "uint") konoha_type = "int";
		if (konoha_type == "ushort") konoha_type = "int";
		if (konoha_type == "ulong") konoha_type = "int";
		if (konoha_type == "qlonglong") konoha_type = "int";
		if (konoha_type == "qulonglong") konoha_type = "int";
		if ("qint" in? konoha_type) konoha_type = "int";
		if ("quint" in? konoha_type) konoha_type = "int";

		if ("::" in? konoha_type) {
			String elem = konoha_type - "Array<" - ">";
			if (object_flag) {
				konoha_type = konoha_type.replace(elem, elem - "::");
			} else {
				konoha_type = konoha_type.replace(elem, "int");
			}
		}

		return konoha_type;
	}
}
