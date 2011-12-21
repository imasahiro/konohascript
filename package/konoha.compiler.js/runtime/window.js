/* Document */
function __Node__(node){
    this.node = node;
    this.getNodeName = function() {
        return new __String__(this.node.nodeName);
    }
    this.getNodeValue = function() {
        return new __String__(this.node.nodeValue);
    }
    this.setNodeValue = function(value) {
        this.node.nodeValue = value.obj;
    }
    this.getNodeType = function() {
        return this.node.nodeType;
    }
    this.getParentNode = function() {
        return new __Node__(this.node.parentNode);
    }
    this.appendChild = function(newChild) {
        return new __Node__(this.node.appendChild(newChild));
    }
    this.insertBefore = function(newChild, refChild) {
        return new __Node__(this.node.insertBefore(newChild.node, refChild.node));
    }
    this.replaceChild = function(newChild, oldChild) {
        return new __Node__(this.node.replaceChild(newChild.node, oldChild.node));
    }
    this.removeChild = function(oldChild) {
        return new __Node__(this.node.removeChild(oldChild));
    }
    this.getChildNodes = function() {
        return new __NodeList__(this.node.childNodes);
    }
    this.getAttributes = function() {
        return new __NamedNodeMap__(this.node.attributes);
    }
    this.getOwnerDocument = function() {
        return new __Document__(this.node.ownerDocument);
    }
    this.getFirstChild = function() {
        return new __Node__(this.node.firstChild);
    }
    this.getLastChild = function() {
        return new __Node__(this.node.lastChild);
    }
    this.getPreviousSibling = function() {
        return new __Node__(this.node.previousSibling);
    }
    this.getNextSibling = function() {
        return new __Node__(this.node.nextSibling);
    }
    this.getPrefix = function() {
        return this.node.prefix;
    }
    this.setPrefix = function(prefix) {
        this.node.prefix = prefix;
    }
    this.getLocalName = function() {
        return this.node.localName;
    }
    this.hasChildNodes = function() {
        return this.node.hasChildNodes();
    }
    this.hasAttributes = function() {
        return this.node.hasAttributes();
    }
}
function __NodeList__(node) {
    this.node = node;
    this.item = function(index) {
        return new __Node__(this.node.item(index));
    }
}
function __NamedNodeMap__(node) {
    this.node = node;
    this.getNamedItem = function(name) {
        return new __Node__(this.node.getNamedItem(name.obj));
    }
    this.setNamedItem = function(arg) {
        return new __Node__(this.node.setNamedItem(arg));
    }
    this.removeNamedItem = function(name) {
        return new __Node__(this.node.removeNamedItem(name.obj));
    }
    this.item = function(index) {
        return new __Node__(this.node.item(index));
    }
}
__CharacterData__.prototype = new __Node__();
function __CharacterData__(node) {
    this.node = node;
    this.getData = function() {
        return new __String__(this.node.data);
    }
    this.setData = function(data) {
        this.node.data = data;
    }
    this.appendData = function(arg) {
        this.node.appendData(arg.obj);
    }
    this.insertData = function(offset, arg) {
        this.node.insertData(offset, arg.obj);
    }
    this.deleteData = function(offset, count) {
        this.node.deleteData(offset, count);
    }
    this.replaceData = function(offset, count, arg) {
        this.node.replaceData(offset, count, arg.obj);
    }
}
__Text__.prototype = new __CharacterData__();
function __Text__(node) {
    this.node = node;
    this.splitText = function(offset) {
        return new __Text__(this.node.splitText(offset));
    }
}
__Attr__.prototype = new __Node__();
function __Attr__(node) {
    this.node = node;
    this.getName = function() {
        return new __String__(this.node.name);
    }
    this.setValue = function(value) {
        this.node.value = value.obj;
    }
    this.getValue = function() {
        return new __String__(this.node.value);
    }
}
__Element__.prototype = new __Node__();
function __Element__(node) {
    this.node = node;
    this.getTagName = function() {
        return this.node.tagName;
    }
    this.getAttribute = function(name) {
        return new __String__(this.node.getAttribute(name.obj));
    }
    this.getAttributeNode = function(name) {
        return new __Attr__(this.node.getAttributeNode(name.obj));
    }
    this.setAttribute = function(name, value) {
        this.node.setAttribute(name.obj, value);
    }
    this.removeAttribute = function(name) {
        this.node.removeAttribute(name);
    }
    this.removeAttributeNode = function(oldAttr) {
        return new __Attr__(this.node.removeAttributeNode(oldAttr));
    }
    this.getElementsByTagName = function(name) {
        var obj = this.node.getElementsByTagName(name.obj);
        return new __Array__(obj);
    }
    this.setAttributeNode = function(newAttr) {
        return new __Attr__(this.node.setAttributeNode(newAttr.attr));
    }
    this.hasAttribute = function(name) {
        return this.node.hasAttribute(name);
    }
}
function __Context__(ctx) {
    this.ctx = ctx;
    this.setFillStyle = function(style) {
        this.ctx.fillStyle = style.obj;
    }
    this.fillRect = function(x, y, w, h) {
        this.ctx.fillRect(x, y, w, h);
    }
}
__Canvas__.prototype = new __Element__();
function __Canvas__(node) {
    this.node = node;
    this.getContext = function(str) {
        return new __Context__(this.node.getContext(str.obj));
    }
}

__Img__.prototype = new __Element__();
function __Img__(img) {
    this.node = node;
}
__Document__.prototype = new __Node__();
function __Document__(node) {
    if (node != null) {
        this.node = node;
    } else {
        this.node = document;
    }
    //this.createEvent = function(eventInterface) {
    //    return new __Event__(this.node.createEvent(eventInterface));
    //}
    this.createAttribute = function(name) {
        var attr = this.node.createAttribute(name.obj);
        return new __Attr__(attr);
    }
    this.getElementsByTagName = function(name) {
        var obj = this.element.getElementsByTagName(name.obj);
        return new __Array__(obj);
    }
    this.getElementById = function(elementId) {
        var obj = this.node.getElementById(elementId.obj);
        switch (obj.nodeName) {
            case 'CANVAS':
                return new __Canvas__(obj);
            case 'IMG':
                return new __Img__(obj);
            default:
                return new __Element__(obj);
                break;
        }
    }
    this.createElement = function(tagName) {
        var obj = this.node.createElement(tagName.obj);
        switch(obj.nodeName) {
            case 'CANVAS':
                return new __Canvas__(obj);
            case 'IMG':
                return new __Img__(obj);
            default:
                return new __Element__(obj);
        }
    }
    this.createTextNode = function(data) {
        return new __Text__(this.node.createTextNode(data.obj));
    }

    this.write = function(str) {
        this.node.write(str);
    }
    this.writeln = function(str) {
        this.node.writeln(str);
    }
    this.clear = function() {
        this.node.clear();
    }
    this.close = function() {
        this.node.close();
    }
    this.open = function() {
        this.node.open();
    }
}
