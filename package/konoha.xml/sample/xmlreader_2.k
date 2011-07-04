#!/usr/local/bin/konoha
using libxml2.*;
// parse xml file and get title.

class Parser{
    XmlReader reader;
    DictMap obj;
    Parser(String filename){
        this.reader = new XmlReader(filename);
        this.obj = new DictMap();
    }

    void parseXml(){
        parse(this.obj);
    }

    boolean hasAttribute(){
        if(reader.hasAttributes() and reader.getAttributeCount() > 0){
            return true;
        }
        return false;
    }

    DictMap getAttribute(){
        DictMap tmp = new DictMap();
        if(this.hasAttribute() == false) return tmp;
        tem = new DictMap();
        while(reader.moveToNextAttribute()){
            tmp[reader.constName()] = reader.constValue();
        }
        return tmp;
    }

    void parse(DictMap cur){
        while(reader.read()){
            type = reader.nodeType();
            if(type == XmlReader.TYPE_ELEMENT){
                name = reader.constName();
                cur[name] = new DictMap();
                if(this.hasAttribute() == true){
                    DictMap tmp = cur[name];
                    tmp["#attr"] = this.getAttribute();
                }
                if(reader.isEmptyElement() == 0){
                    this.parse(cur[name]);
                }
            }
            else if(reader.nodeType() == XmlReader.TYPE_TEXT){
                cur["#text"] = reader.constValue();
                break;
            }
        }
    }
}

Parser p = new Parser("./rss.xhtml");
p.parseXml();
print p.obj;

