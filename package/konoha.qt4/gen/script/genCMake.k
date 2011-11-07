void genCMake(BindInfo[] binded_class)
{
	OUT << "genCMake" << EOL;
	String cppsrc = "";
	String hppsrc = "";

	if (GEN_CONCATENATE_FILE) {
		cppsrc += "\t" + CONCATENATE_CPP_FILE + "\n";
		hppsrc += "\t" + CONCATENATE_HPP_FILE + "\n";
	} else {
		for (int i = 0; i < |binded_class|; i++) {
			if (binded_class[i].checkUnusedClass()) continue;
			cppsrc += "\tsrc/K" + binded_class[i].class_name + ".cpp\n";
			if (binded_class[i].make_rapper_class_flag) hppsrc += "\tinclude/K" + binded_class[i].class_name + ".hpp\n";
		}
		cppsrc += "\n\tsrc/QtInitFunction.cpp";
	}

	String cmakelists = CMAKELISTS(cppsrc, hppsrc);

	ous = new OutputStream("CMakeLists.txt");
	ous.println(cmakelists);
	ous.flush();
	ous.close();
	return;
}
