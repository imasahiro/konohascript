abstract_classes = ["Abstract", "QGraphicsLayout", "QGraphicsEffect", "QAccessibleObject",
					"QGraphicsItem", "QIODevice", "QValidator", "QRunnable", "QGraphicsObject",
					"QGraphicsItem", "QLayout"];
class QtInterface {
	XmlReader reader;
	String input_urn, output_urn;
	boolean error_flag;
	String class_name;
	String[] inherits;
	String[] public_types;
	String[] properties;
	String[] public_functions;
	String[] public_slots;
	String[] signals;
	String[] static_public_members;
	String[] protected_functions;
	String[] reimplemented_public_functions;
	String[] reimplemented_protected_functions;
	String[] protected_slots;
	String[] related_non_members;
	boolean templateClass;
	boolean abstractClass;
	boolean enbeddedClass;
	String[] typedefed_objects; //typedefed object the class defined
	String[] parent_typedefed_objects; //typedefed object parent class defined
	EnumInterface[] enums; //enum the class defined
	EnumInterface[] parent_enums; //enum parent class defined
	int[] parent_index;
	String[] parent_name;

	QtInterface(String iu) {
		initMember();
		input_urn = iu;
		if (input_urn == "") {
//			print "input_urn not found";
			return;
		}
		reader = new XmlReader(input_urn);
		parse();
	}

	void initMember() {
		input_urn = "";
		output_urn = "";
		error_flag = false;
		class_name = "";
		inherits = [];
		public_types = [];
		parent_public_types = [];
		properties = [];
		public_functions = [];
		public_slots = [];
		signals = [];
		static_public_members = [];
		protected_functions = [];
		reimplemented_public_functions = [];
		reimplemented_protected_functions = [];
		protected_slots = [];
		related_non_members = [];
		templateClass = false;
		abstractClass = false;
		embeddedClass = false;
		typedefed_objects = [];
		parent_typedefed_objects = [];
		enums = [];
		parent_enums = [];
		parent_index = [];
		parent_name = [];
	}

	boolean isAbstractClass() {
		return abstractClass;
	}

	boolean isTemplateClass() {
		return templateClass;
	}
	
	void collectTypedefedObject() {
//		print public_types;
		if (|public_types| == 0) return;
		foreach (String public_type in public_types) {
//			print public_type;
			String name = (public_type.split(" "))[2];
			if (!("enum" in? public_type)) {
				typedefed_objects <<< name;
			}
		}
		return;
	}

	EnumInterface[] extractedEnumInterface() {
		QtXmlReader q_reader = new QtXmlReader(input_urn);
		while (q_reader.read()) {
			if (q_reader.nodeType() == XmlReader.TYPE_TEXT) {
				if (q_reader.constValue() == "Member Type Documentation") break;
			}
		}
		String[] token = [];
		EnumInterface[] interfaces = [];
		int type = -1;
		String name = "";
		boolean break_flag = false;
		while (q_reader.read()) {
			name = q_reader.constName();
			type = q_reader.nodeType();
			switch (type) {
			case XmlReader.TYPE_END_ELEMENT:
				if (name == "div") {
					break_flag = true;
					EnumInterface interface = new EnumInterface(token, class_name);
					interface.checkAccessModifier(public_types);
					if (interface.name != "") interfaces <<< interface;
					token = [];
				}
				break;
			case XmlReader.TYPE_ELEMENT:
				if (name == "h3" && |token| != 0) {
					EnumInterface interface = new EnumInterface(token, class_name);
					interface.checkAccessModifier(public_types);
					if (interface.name != "") interfaces <<< interface;
					token = [];
				}
				if (name == "h3" || name == "tt") {
					while (q_reader.read()) {
						name = q_reader.constName();
						type = q_reader.nodeType();
						if (type == XmlReader.TYPE_TEXT) {
							token <<< q_reader.constValue();
							break;
						}
						if (type == XmlReader.TYPE_END_ELEMENT &&
							(name == "h3" || name == "tt")) {
							break;
						}
					}
				}
				break;
			}
			if (break_flag) break;
		}
		return interfaces;
	}

	String[] extractedValue() {
		String[] ret = [];
		String value = "";
		while (reader.read()) {
			String name = reader.constName();
			int type = reader.nodeType();
			switch (type) {
			case XmlReader.TYPE_TEXT:
				value += reader.constValue();
				break;
			case XmlReader.TYPE_END_ELEMENT:
				if (reader.constName() == "tr" ||
					reader.constName() == "li") {
					ret << value;
					value = "";
				}
				break;
			}
			if (type == XmlReader.TYPE_END_ELEMENT &&
				(name == "table" || name == "ul")) {
				break;
			}
		}
		return ret;
	}

	String inheritanceStructure() {
		String data;
		boolean break_flag = false;

		while (reader.read()) {
			switch (reader.nodeType()) {
			case XmlReader.TYPE_END_ELEMENT:
				if (reader.constName() == "ul") return;
			case XmlReader.TYPE_TEXT:
				if (reader.constValue() == "Inherits ") {
					data += "Inherits\n";
					break_flag = true;
					break;
				} else if ("template" in? reader.constValue()) {
					data += "templete class\n";
					templateClass = true;
				} else if ("abstract" in? reader.constValue()) {
					data += "abstract class\n";
					abstractClass = true;
				} else if ("Embedded" in? reader.constValue()) {
					enbeddedClass = true;
				}
			}
			if (break_flag == true) break;
		}

		while (reader.read()) {
			switch (reader.nodeType()) {
			case XmlReader.TYPE_TEXT:
				if (reader.constValue() != " and " &&
					reader.constValue() != ".") {
					data += reader.constValue();
					data += "\n";
				}
				break;
			case XmlReader.TYPE_END_ELEMENT:
				if (reader.constName() == "p") {
					data += "\n";
					return data;
				}
			}
		}
//		return data;
	}

	void parse() {
		while (reader.read()) {
			if (reader.nodeType() != XmlReader.TYPE_ELEMENT)
				continue;
			tag_name = reader.constName();
			reader.read();
			if (reader.nodeType() != XmlReader.TYPE_TEXT)
				continue;

			switch (tag_name) {
			case "h1":
				output_urn = reader.constValue();
				if (output_urn.indexOf("Class Reference") == -1) {
					//OUT << "error output_urn=" << output_urn << EOL;
					error_flag = true;
					return;
				}
				output_urn -= " Class Reference";
				inheritanceStructure();
				class_name = output_urn;
				foreach (abst_class in abstract_classes) {
					if (abst_class in? class_name) {
						abstractClass = true;
						break;
					}
				}
				break;
			case "h2":
				switch (reader.constValue()) {
				case "Public Types":
					public_types = extractedValue();
					collectTypedefedObject();
					break;
				case "Properties":
					properties = extractedValue();
					break;
				case "Public Functions":
					public_functions = extractedValue();
					break;
				case "Public Slots":
					public_slots = extractedValue();
				case "Signals":
					signals = extractedValue();
					break;
				case "Static Public Members":
					static_public_members = extractedValue();
					break;
				case "Protected Functions":
					protected_functions = extractedValue();
					break;
				case "Reimplemented Public Functions":
					reimplemented_public_functions = extractedValue();
					break;
				case "Reimplemented Protected Functions":
					reimplemented_protected_functions = extractedValue();
					break;
				case "Protected Slots":
					protected_slots = extractedValue();
					break;
				case "Related Non-Members":
					related_non_members = extractedValue();
					break;
				case "Detailed Description":
					reader.close();
					enums = extractedEnumInterface();
					return;
				}
				break;
			}
		}
	}
}
