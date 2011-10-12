class FunctionElement {
	String return_value_type;
	String func_name;
	String declation;
	String class_name;
	String default_getter_name;
	String[] argument_type;
	String[] argument_name;
	int argument_number;
	boolean virtualFlag;
	boolean constructorFlag;
	boolean destructorFlag;
	boolean notMakeFlag;
	boolean funcGetterFlag;
	boolean overloadFlag;
	boolean overrideFlag;
	boolean pureVirtualFlag;
	String[] knh_token;
	boolean return_value_type_enum_flag;
	boolean return_value_type_object_flag;
	boolean[] argument_type_enum_flag;
	boolean[] argument_type_object_flag;

	FunctionElement(String dec, String cn) {
		argument_type = [];
		argument_name = [];
		class_name = cn;
		declation = dec;
		knh_token = [];
		argument_number = 0;
		funcGetterFlag = false;
		virtualFlag = false;
		constructorFlag = false;
		destructorFlag = false;
		notMakeFlag = false;
		overloadFlag = false;
		overrideFlag = false;
		return_value_enum_flag = false;
		return_value_object_flag = false;
		pureVirtualFlag = false;
		argument_type_enum_flag = [];
		argument_type_object_flag = [];
		parse(declation);
		for (int i = 0; i < |argument_type|; i++) {argument_type_enum_flag <<< false;}
		for (int i = 0; i < |argument_type|; i++) {argument_type_object_flag <<< false;}
	}

	Array<String> tokenize(String declation) {
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
//					print token;
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
					argument_type <<< token[tc];
					an = "arg" + (String)ac;
					argument_name <<< an;
					tc++;
				}
				argument_number = ac;
			} else {
				int ac = 0;
				for (; token[tc] != ")"; ac++) {
					argument_type <<< token[tc];
					tc++;
					token[tc] -= ",";
					argument_name <<< token[tc];
					tc++;
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

	void renamePublicTypes(String[] public_enums, String[] typedefed_objects) {
		foreach (String public_enum in public_enums) {
			if (public_enum in? return_value_type &&
				!upperCheck(return_value_type[1])) {
				if (!("::" in? return_value_type)) {
						return_value_type = return_value_type.replace(public_enum, class_name + "::" + public_enum);
				}
				return_value_type_enum_flag = true;
				break;
			}
		}
		foreach (String typedefed_object in typedefed_objects) {
			if (typedefed_object in? return_value_type &&
				!upperCheck(return_value_type[1])) {
				if (!("::" in? return_value_type)) {
					return_value_type = return_value_type.replace(typedefed_object, class_name + "::" + typedefed_object);
				}
				return_value_type_enum_flag = false;
				return_value_type_object_flag = true;
				break;
			}
		}
		if (!return_value_type_enum_flag &&
			!return_value_type_object_flag &&
			!("Array" in? return_value_type)) {
			if (upperCheck(return_value_type[0]) &&
				!return_value_type.startsWith("Q")) {
				return_value_type = class_name + "::" + return_value_type;
			}
		}

		if ("iterator" in? return_value_type) return_value_type_object_flag = true;

		for (int i = 0; i < |argument_type|; i++) {
			if ("iterator" in? argument_type[i]) {
				return_value_type_object_flag = true;
				continue;
			}
			foreach (String public_enum in public_enums) {
				if (public_enum in? argument_type[i] &&
					!upperCheck(argument_type[i][1])) {
					if (!("::" in? argument_type[i])) {
						argument_type[i] = argument_type[i].replace(public_enum, class_name + "::" + public_enum);
					}
					argument_type_enum_flag[i] = true;
					break;
				}
			}
			foreach (String typedefed_object in typedefed_objects) {
				if (typedefed_object in? argument_type[i] &&
					!upperCheck(argument_type[i][1])) {
					if (!("::" in? argument_type[i])) {
						argument_type[i] = argument_type[i].replace(typedefed_object, class_name + "::" + typedefed_object);
					}
					argument_type_enum_flag[i] = false;
					argument_type_object_flag[i] = true;
					break;
				}
			}

			if (!argument_type_enum_flag[i] &&
				!argument_type_object_flag[i] &&
				!("Array" in? argument_type[i])) {
				if (upperCheck(argument_type[i][0]) &&
					!argument_type[i].startsWith("Q")) {
					argument_type[i] = class_name + "::" + argument_type[i];
				}
			}
		}
		return;
	}

	Array<String> parse(String declation) {
		String[] token = tokenize(declation);
		setElements(token);
		convertUnusedArgName(argument_name);
//		if (class_name == "QLineEdit") print this;
		return token;
	}

	String argumentFormat() {
		string str = "";
		if (argument_number == 0)
			return str;
		for (int i = 0; i < argument_number; i++) {
			type = argument_type[i];
			name = argument_name[i];
			int j = i + 1;
			if (constructorFlag == false) {
				str += "\t\t";
			} else {
				str += "\t";
			}
			String exclude_const_type = type - "const ";
			knh_token << exclude_const_type;
			knh_token << name;
			if ((exclude_const_type.startsWith("i") || exclude_const_type.startsWith("q"))
				&& "int" in? type) {
				str += Int_to(name, type, j);
			} else if ("float" in? type ||
					   "qreal" == type) {
				str += Float_to(name, type, j);
			} else if ("bool" in? type) {
				str += Boolean_to(name, type, j);
			} else if ("QString" in? type) {
				str += String_to(name, type, j);
			} else {
				if ("Array<" in? type) {
					str += Array_to(name, type, j);
				} else if ("::" in? type &&
						   !argument_type_object_flag[i]) {
					str += Int_to(name, type, j);
				} else {
					str += RawPtr_to(name, type, j);
				}
			}
		}
		return str;
	}

	String callFuncFormat(boolean make_rapper_class_flag = false) {
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
				str += (return_value_type.replace("Array<", "QList<") + "ret_v = ");
			} else if (return_value_type != "void") {
				str += (return_value_type + " ret_v = ");
			}
			if (funcGetterFlag == false) {
				str += ("qp->" + func_name + "(");
			} else {
				str += ("qp->" + default_getter_name + "(");
			}
		}
		for (int i = 0; i < (argument_number - 1); i++) {
			str += (argument_name[i] + ", ");
		}
		if (argument_number != 0)
			str += argument_name[argument_number - 1];
		str += ");\n";
		return str;
	}

	String returnFormat(boolean make_rapper_class_flag = false) {
		if (constructorFlag) {
			knh_token.insert(0, class_name);
			if (make_rapper_class_flag) {
				return RETURNrc_();
			} else {
				return RETURNc_();
			}
		}
		String exclude_const_type = return_value_type - "const ";
		knh_token.insert(0, exclude_const_type);
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

	String genBind(boolean make_rapper_class_flag) {
//		if (class_name == "QWidget") print make_rapper_class_flag;
		if (pureVirtualFlag) return "";
		String bind = "";
		bind += ("KMETHOD " + class_name + "_" + func_name + "(CTX ctx, knh_sfp_t *sfp _RIX)\n");
		bind += "{\n";
		bind += "\t(void)ctx;\n";
		if (constructorFlag == false) {
			knh_token << class_name;
			knh_token << func_name;
			bind += "\t" + RawPtr_to("qp", class_name + " *", 0);
			bind += "\tif (qp != NULL) {\n";
			bind += argumentFormat();
			bind += callFuncFormat();
			bind += returnFormat();
			bind += "\n";
		} else {
			knh_token << class_name;
			knh_token << "new";
			bind += argumentFormat();
			bind += callFuncFormat(make_rapper_class_flag);
			bind += returnFormat(make_rapper_class_flag);
			if (class_name == "QApplication") return QApplicationNew();
		}
		return bind;
	}

	void convertUnusedArgName(String[] ans) {
		for (int i = 0; i < |ans|; i++) {
			foreach (String[] unused_arg_name in UNUSED_ARG_NAMES) {
//				if ("new" == argument_name[i]) {
//					print class_name;
//					print argument_name[i];
//				}
				ans[i] = ans[i].replace(unused_arg_name[0], unused_arg_name[1]);
//				if ("new" in? argument_name[i]) print argument_name[i];
			}
		}
	}

	String genKonohaInterface()	{
		if (pureVirtualFlag) return "";
		for (int i = 0; i < |knh_token|; i++) {
			String token = knh_token[i];
//		knh_token[i] = knh_token[i].replace("const", "");
			knh_token[i] = knh_token[i].replace("*", "");
			knh_token[i] = knh_token[i].replace("bool", "boolean");
			knh_token[i] = knh_token[i].replace("qreal", "float");
			knh_token[i] = knh_token[i].replace("QString", "String");
			knh_token[i] = knh_token[i].replace("uchar", "String");
//		knh_token[i] = knh_token[i].replace("char", "String");
			knh_token[i] = knh_token[i].replace("unsigned", "");
			knh_token[i] = knh_token[i].replace("string", "str");
			knh_token[i] = knh_token[i].replace("Strings", "str");
			knh_token[i] = knh_token[i].replace("Stringacters", "str");
			knh_token[i] = knh_token[i].replace("include", "inc");
//			knh_token[i] = knh_token[i].replace("from", "from_");
//			knh_token[i] = knh_token[i].replace("to", "to_");
			knh_token[i] = knh_token[i].replace("Top", "top");
			if ((knh_token[i].startsWith("i") || knh_token[i].startsWith("q")) &&
				"int" in? knh_token[i]) {
				if (knh_token[0] != "//" &&
					i != 2 &&
					((i % 2) == 1 ||
					 i == 0)) {
					knh_token[i] = "int";
				}
				if (knh_token[0] == "//" &&
					i != 3 &&
					(i % 2) == 0) {
					knh_token[i] = "int";
				}
			}
			if (knh_token[i] == "from") knh_token[i] = "from_";
			if (knh_token[i] == "to") knh_token[i] = "to_";
			if (knh_token[i] == "char") knh_token[i] = "String";
			if (knh_token[i] == "uint") knh_token[i] = "int";
			if (knh_token[i] == "ushort") knh_token[i] = "int";
			if (knh_token[i] == "ulong") knh_token[i] = "int";
			if (knh_token[i] == "qlonglong") knh_token[i] = "int";
			if (knh_token[i] == "qulonglong") knh_token[i] = "int";
			if (knh_token[i] == "format") knh_token[i] = "fmt";
			if ("Array" in? token) {
				if ("::" in? token) knh_token[i] = "Array<int>";
			} else {
				if ("::" in? token) knh_token[i] = "int";
			}
		}
		if (knh_token == null) return;
		String knh_interface = "";
		if (knh_token[0] == "//") {
			knh_interface += "//";
			knh_token.remove(0);
		}
		if (virtualFlag) knh_interface += "@Virtual ";
		if (overrideFlag) knh_interface += "@Override ";
		if (|knh_token| < 3) {
			//print "Error!!";
			//print knh_token;
			return;
		}
		knh_interface += knh_token[0];
		knh_interface += " " + knh_token[1];//class name;
		knh_interface += "." + knh_token[2];//mtd name
		knh_interface += "(";
		for (i = 3; i < |knh_token|; i++) {
			knh_interface += knh_token[i];
			if (|knh_token| == i+1) break;
			if (i % 2 == 0) knh_interface += ", ";
			else knh_interface += " ";
		}
		knh_interface += ");\n";

		String[] unsupported_methods = [ //these methods are final
			"isNull", "isValid", "insertColumn", "insertRow",
			"addAction", /*"depth", "height", "width",*/ "accept",
			"ignore", "isAccepted", "setAccepted", "setWindowModality",
			"transformed", "from_Image"
			];
		foreach (um in unsupported_methods) {
			if (um in? knh_interface) knh_interface = "//" + knh_interface;
		}
		return knh_interface;
	}
}
