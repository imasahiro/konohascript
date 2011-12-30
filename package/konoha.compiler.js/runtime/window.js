/* Document */

__Node__.prototype = new __Object__();
function __Node__(rawptr){
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Node";
    this.getNodeName = function() {
        return new __String__(this.rawptr.nodeName);
    }
    this.getNodeValue = function() {
        return new __String__(this.rawptr.nodeValue);
    }
    this.setNodeValue = function(value) {
        this.rawptr.nodeValue = value.rawptr;
    }
    this.getNodeType = function() {
        return this.rawptr.nodeType;
    }
    this.getParentNode = function() {
        return new __Node__(this.rawptr.parentNode);
    }
    this.appendChild = function(newChild) {
        return new __Node__(this.rawptr.appendChild(newChild.rawptr));
    }
    this.insertBefore = function(newChild, refChild) {
        return new __Node__(this.rawptr.insertBefore(newChild.rawptr, refChild.node));
    }
    this.replaceChild = function(newChild, oldChild) {
        return new __Node__(this.rawptr.replaceChild(newChild.rawptr, oldChild.rawptr));
    }
    this.removeChild = function(oldChild) {
        return new __Node__(this.rawptr.removeChild(oldChild));
    }
    this.getChildNodes = function() {
        return new __NodeList__(this.rawptr.childNodes);
    }
    this.getAttributes = function() {
        return new __NamedNodeMap__(this.rawptr.attributes);
    }
    this.getOwnerDocument = function() {
        return new __Document__(this.rawptr.ownerDocument);
    }
    this.getFirstChild = function() {
        return new __Node__(this.rawptr.firstChild);
    }
    this.getLastChild = function() {
        return new __Node__(this.rawptr.lastChild);
    }
    this.getPreviousSibling = function() {
        return new __Node__(this.rawptr.previousSibling);
    }
    this.getNextSibling = function() {
        return new __Node__(this.rawptr.nextSibling);
    }
    this.getPrefix = function() {
        return this.rawptr.prefix;
    }
    this.setPrefix = function(prefix) {
        this.rawptr.prefix = prefix;
    }
    this.getLocalName = function() {
        return this.rawptr.localName;
    }
    this.hasChildNodes = function() {
        return this.rawptr.hasChildNodes();
    }
    this.hasAttributes = function() {
        return this.rawptr.hasAttributes();
    }
}
__NodeList__.prototype = new __Object__();
function __NodeList__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.NodeList";
    this.item = function(index) {
        return new __Node__(this.rawptr.item(index));
    }
}
__NamedNodeMap__.prototype = new __Object__();
function __NamedNodeMap__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.NamedNodeMap";
    this.getNamedItem = function(name) {
        return new __Node__(this.rawptr.getNamedItem(name.rawptr));
    }
    this.setNamedItem = function(arg) {
        return new __Node__(this.rawptr.setNamedItem(arg));
    }
    this.removeNamedItem = function(name) {
        return new __Node__(this.rawptr.removeNamedItem(name.raw));
    }
    this.item = function(index) {
        return new __Node__(this.rawptr.item(index));
    }
}
__CharacterData__.prototype = new __Node__();
function __CharacterData__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.CharacterData";
    this.getData = function() {
        return new __String__(this.rawptr.data);
    }
    this.setData = function(data) {
        this.rawptr.data = data;
    }
    this.appendData = function(arg) {
        this.rawptr.appendData(arg.rawptr);
    }
    this.insertData = function(offset, arg) {
        this.rawptr.insertData(offset, arg.rawptr);
    }
    this.deleteData = function(offset, count) {
        this.rawptr.deleteData(offset, count);
    }
    this.replaceData = function(offset, count, arg) {
        this.rawptr.replaceData(offset, count, arg.rawptr);
    }
}
__Text__.prototype = new __CharacterData__();
function __Text__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Text";
    this.splitText = function(offset) {
        return new __Text__(this.rawptr.splitText(offset));
    }
}
__Attr__.prototype = new __Node__();
function __Attr__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Attr";
    this.getName = function() {
        return new __String__(this.rawptr.name);
    }
    this.setValue = function(value) {
        this.rawptr.value = value.rawptr;
    }
    this.getValue = function() {
        return new __String__(this.rawptr.value);
    }
}
__ImageData__.prototype = new __Object__();
function __ImageData__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.ImageData";
}
__Gradient__.prototype = new __Object__();
function __Gradient__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Gradient";
}
__Element__.prototype = new __Node__();
function __Element__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Element";
    this.getTagName = function() {
        return this.rawptr.tagName;
    }
    this.getAttribute = function(name) {
        return new __String__(this.rawptr.getAttribute(name.rawptr));
    }
    this.getAttributeNode = function(name) {
        return new __Attr__(this.rawptr.getAttributeNode(name.rawptr));
    }
    this.setAttribute = function(name, value) {
        this.rawptr.setAttribute(name.rawptr, value.rawptr);
    }
    this.removeAttribute = function(name) {
        this.rawptr.removeAttribute(name);
    }
    this.removeAttributeNode = function(oldAttr) {
        return new __Attr__(this.rawptr.removeAttributeNode(oldAttr));
    }
    this.getElementsByTagName = function(name) {
        var obj = this.rawptr.getElementsByTagName(name.rawptr);
        return new __NodeList__(obj);
    }
    this.setAttributeNode = function(newAttr) {
        return new __Attr__(this.rawptr.setAttributeNode(newAttr.attr));
    }
    this.hasAttribute = function(name) {
        return this.rawptr.hasAttribute(name);
    }
}
__Context__.prototype = new __Object__();
function __Context__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.CanvasContext";
    this.arc = function(x, y, startAngle, endAngle, anticlockwise) {
        this.rawptr.arc(x, y, startAngle, endAngle, anticlockwise);
    }
    this.actTo = function(x1, y1, x2, y2, radius) {
        this.rawptr.actTo(x1, y1, x2, y2, radius);
    }
    this.beginPath = function() {
        this.rawptr.beginPath();
    }
    this.bezierCurveTo = function(cp1x, cp1y, cp2x, cp2y, x, y) {
        this.rawptr.bezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y);
    }
    this.crearRect = function(x, y, w, h) {
        this.rawptr.crearRect(x, y, w, h);
    }
    this.clip = function() {
        this.rawptr.clip();
    }
    this.closePath = function() {
        this.rawptr.closePath();
    }
    this.createImageData = function(image) {
        return new __ImageData__(this.rawptr.createImageData(image.rawptr));
    }
    this.createLinearGradient = function(x0, y0, x1, y1) {
        return new __Gradient__(this.rawptr.createLinearGradient(x0, y0, x1, y1));
    }
    this.createRadialGradient = function(x0, y0, r0, x1, y1, r1) {
        return new __Gradient__(this.rawptr.createRadialGradient(x0, y0, r0, x1, y1, r1));
    }
    this.drawImage = function(image, dx, dy, dw, dh) {
        this.rawptr.drawImage(image.rawptr, dx, dy, dw, dh);
    }
    this.fill = function() {
        this.rawptr.fill();
    }
    this.fillRect = function(x, y, w, h) {
        this.rawptr.fillRect(x, y, w, h);
    }
    this.fillText = function(text, x, y) {
        this.rawptr.fillText(text.rawptr, x, y);
    }
    this.getImageData = function(sx, sy, sw, sh) {
        return new __ImageData__(this.rawptr.getImageData(sx, sy, sw, sh));
    }
    this.isPointInPath = function(x, y) {
        return this.rawptr.isPointInPath(x, y);
    }
    this.lineTo = function(x, y) {
        this.rawptr.lineTo(x, y);
    }
    this.moveTo = function(x, y) {
        this.rawptr.moveTo(x, y);
    }
    this.putImageData = function(image, dx, dy) {
        this.rawptr.putImageData(image.rawptr, dx, dy);
    }
    this.quadraticCurveTo = function(cpx, cpy, x, y) {
        this.rawptr.quadraticCurveTo(cpx, cpy, x, y);
    }
    this.rect = function(x, y, w, h) {
        this.rawptr.rect(x, y, w, h);
    }
    this.restore = function() {
        this.rawptr.restore();
    }
    this.rotate = function(angle) {
        this.rawptr.rotate(angle);
    }
    this.save = function() {
        this.rawptr.save();
    }
    this.scale = function(x, y) {
        this.rawptr.scale(x, y);
    }
    this.setTransform = function(m11, m12, m21, m22, dx, dy) {
        this.rawptr.setTransform(m11, m12, m21, m22, dx, dy);
    }
    this.stroke = function() {
        this.rawptr.stroke();
    }
    this.strokeRect = function(x, y, w, h) {
        this.rawptr.strokeRect(x, y, w, h);
    }
    this.stroketext = function(text, x, y) {
        this.rawptr.strokeText(text.rawptr, x, y);
    }
    this.translate = function(x, y) {
        this.rawptr.translate(x, y);
    }
    this.transform = function(m11, m12, m21, m22, dx, dy) {
        this.rawptr.transform(m11, m12, m21, m22, dx, dy);
    }
    this.setFillStyle = function(style) {
        this.rawptr.fillStyle = style.rawptr;
    }
}
__Canvas__.prototype = new __Element__();
function __Canvas__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Canvas";
    this.getContext = function(str) {
        return new __Context__(this.rawptr.getContext(str.rawptr));
    }
}

__Img__.prototype = new __Element__();
function __Img__(rawptr) {
    this.rawptr = rawptr;
    this.konohaclass = "js.dom.Img";
}
__Document__.prototype = new __Node__();
function __Document__(rawptr) {
    if (rawptr != null) {
        this.rawptr = rawptr;
    } else {
        this.rawptr = document;
    }
    this.konohaclass = "js.dom.Document";
    //this.createEvent = function(eventInterface) {
    //    return new __Event__(this.rawptr.createEvent(eventInterface));
    //}
    this.createAttribute = function(name) {
        var attr = this.rawptr.createAttribute(name.rawptr);
        return new __Attr__(attr);
    }
    this.getElementsByTagName = function(name) {
        var obj = this.rawptr.getElementsByTagName(name.rawptr);
        return new __NodeList__(obj);
    }
    this.getElementById = function(elementId) {
        var obj = this.rawptr.getElementById(elementId.rawptr);
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
        var obj = this.rawptr.createElement(tagName.rawptr);
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
        return new __Text__(this.rawptr.createTextNode(data.rawptr));
    }

    this.write = function(str) {
        this.rawptr.write(str);
    }
    this.writeln = function(str) {
        this.rawptr.writeln(str);
    }
    this.clear = function() {
        this.rawptr.clear();
    }
    this.close = function() {
        this.rawptr.close();
    }
    this.open = function() {
        this.rawptr.open();
    }
}
