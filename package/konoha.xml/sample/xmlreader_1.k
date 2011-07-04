#!/usr/local/bin/konoha
using libxml2.*;
// parse xml file and get title.

XmlReader reader = new XmlReader("rss.xhtml");
while(reader.read()){
    type = reader.nodeType();
    //OUT << type + " ";
    if(reader.hasAttributes() && reader.getAttributeCount() > 0){
        while(reader.moveToNextAttribute()){
            OUT << reader.constName() + "=" + reader.constValue() << EOL;
        }
    }
    if(type == XmlReader.TYPE_ELEMENT && reader.constName() == "title"){
        reader.read();
        if(reader.nodeType() == XmlReader.TYPE_TEXT){
            OUT  << reader.constValue() << EOL;
        }
    } else if(type == XmlReader.TYPE_ATTRIBUTE){
        OUT << "att:" + reader.getAttribute() << EOL;
    }
}

reader.close();

