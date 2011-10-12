//=========== qt install directory setting ====================//
QT_HOME_DIR = "/usr/local/Trolltech/Qt-4.7.3/";
//=============================================================//

QT_DOC_DIR = QT_HOME_DIR + "doc/html/";
QT_INCLUDE_DIR = QT_HOME_DIR + "include/";

CONCATENATE_CPP_FILE = "qt4.cpp";
CONCATENATE_HPP_FILE = "qt4.hpp";

GEN_INTERFACE_FILE = false;
/*
To speed up generating, at fist, set true. In each run after the first, set false.
(If interface file(gen/interface/ *) do not exist, load qt document(QT_DOC_DIR/ *) to generate. If interface file exist, load them to generate.)
 */
