using libxml2.*;

doc = new Xml("1.0");
root = doc.createNode("EXAMPLE");

node = root.createNode("hoge","ssss");
root.addChild(node);

node = root.createNode("head","");
node.setAttr("type","aaa");

root.addChild(node);

OUT << doc.dump() << EOL;

XPath x = new XPath(doc);
XmlNode n = x.find("//hoge/text()");
OUT << n.getContent();

