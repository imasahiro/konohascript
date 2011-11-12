using konoha.xml.*;
using konoha.posix.*;

GEN_CPP_SRC = true;
GEN_ENUM_BIND = true;
OUTPUT_ALL_METHODS = true;
OUTPUT_EVENT_BIND = true;
GEN_CONCATENATE_FILE = true;

include "gen/config.k";
include "gen/script/constStringList.k";
include "gen/script/EnumInterface.k";
include "gen/script/bind.k";
include "gen/script/QtXmlReader.k";
include "gen/script/QtInterface.k";
include "gen/script/FunctionElement.k";
include "gen/script/BindInfo.k";
include "gen/script/makeQtInterface.k";
include "gen/script/makeBindInfo.k";
include "gen/script/event.k";
include "gen/script/genHierarchy.k";
include "gen/script/genFlagObject.k";
include "gen/script/output.k";
//include "gen/script/genMake.k";
include "gen/script/genCMake.k";

void main() {
	QtHierarchy hierarchy = new QtHierarchy();
	QtInterface[] interfaces = makeQtInterface(QT_DOC_DIR, hierarchy);
	if (|interfaces| == 0) {
		OUT << "makeInterface error" << EOL;
		return;
	}
	BindInfo[] bia = makeBindInfo(interfaces, hierarchy);
	int event_mtd_num =	genEventSource(bia, interfaces);

	outputSrc(bia, hierarchy);
	genCMake(bia);

	outputCompletionRate(interfaces, bia, event_mtd_num);

	OUT << "exit nomally" << EOL;
}
