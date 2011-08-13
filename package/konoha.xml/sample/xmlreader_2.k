#!/usr/local/bin/konoha

using konoha.xml.*;

class Parser{
    XmlReader reader;
    Map obj;
    Parser(String filename){
        this.reader = new XmlReader(filename);
        this.obj = {};
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

    Map getAttribute(){
        Map tmp = {};
        if(this.hasAttribute() == false) return tmp;
        tem = {};
        while(reader.moveToNextAttribute()){
            tmp[reader.constName()] = reader.constValue();
        }
        return tmp;
    }

    void parse(Map cur){
        while(reader.read()){
            type = reader.nodeType();
            if(type == XmlReader.TYPE_ELEMENT){
                name = reader.constName();
                cur[name] = {};
                if(this.hasAttribute() == true){
                    Map tmp = cur[name];
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
