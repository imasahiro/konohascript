class NodeList;
class NamedNodeMap;
class Document;
class Node {
    String getNodeName();
    String getNodeValue();
    void setNodeValue(String value);
    int getNodeType();
    Node getParentNode();
    void appendChild(Node newChild);
    Node insertBefore(Node newChild, Node refChild);
    Node replaceChild(Node newChild, Node oldChild);
    Node removeChild(Node oldChild);
    NodeList getChildNodes();
    NamedNodeMap getAttributes();
    Document getOwnerDocument();
    Node getFirstChild();
    Node getLastChild();
    Node getPreviousSibling();
    Node getNextSibling();
    String getPrefix();
    void setPrefix(String prefix);
    String getLocalName();
    boolean hasChildNodes();
    boolean hasAttributes();
}
class NodeList {
    Node item(int index);
}
class NamedNodeMap {
    Node getNamedItem(String name);
    Node setNamedItem(Node arg);
    Node removeNamedItem(String name);
    Node item(int index);
}
class CharacterData extends Node {
    String getData();
    String setData(String data);
    String substringData(int offset, int count);
    void appendData(String arg);
    void insertData(int offset, String arg);
    void deleteData(int offset, int count);
    void replaceData(int offset, int count, String arg);
}
class Text extends CharacterData {
    Text splitText(int offset);
}
class Attr extends Node {
    String getName();
    void setValue(String value);
}
class Element extends Node{
    String getTagName();
    NodeList getElementsByTagName(Sting name);
    Attr setAttributeNode(Attr newAttr);
    String getAttribute(String name);
    Attr getAttributeNode(String name);
    void setAttribute(String name, String value);
    void removeAttribute(String name);
    Attr removeAttributeNode(Attr oldAttr);
    boolean hasAttribute(String name);
};
class ImageData;
class Gradient;
class CanvasContext {
    // void addColorStop();
    void arc(float x, float y, float startAngle, float endAndle, float anticlockwise);
    void actTo(float x1, float y1, float x2, float y2, float radius);
    void beginPath();
    void bezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y);
    void clearRect(float x, float y, float w, float h);
    void clip();
    void closePath();
    ImageData createImageData(ImageData image);
    Gradient createLinearGradient(float x0, float y0, float x1, float y1);
    Gradient createRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1);
    void drawImage(ImageData image, float dx, float dy, float dw, float dh);
    void fill();
    void fillRect(float x, float y, float w, float h);
    void fillText(String text, float x, float y);
    ImageData getImageData(float sx, float sy, float sw, float sh);
    boolean isPointInPath(float x, float y);
    void lineTo(float x, float y);
    void moveTo(float x, float y);
    void putImageData(ImageData image, float dx, float dy);
    void quadraticCurveTo(float cpx, float cpy, float x, float y);
    void rect(float x, float y, float w, float h);
    void restore();
    void rotate(float angle);
    void save();
    void scale(float x, float y);
    void setTransform(float m11, float m12, float m21, float m22, float dx, float dy);
    void stroke();
    void strokeRect(float x, float y, float w, float h);
    void strokeText(String text, float x, float y);
    void translate(float x, float y);
    void transform(float m11, float m12, float m21, float m22, float dx, float dy);
    @Overload void setStrokeStyle(String cssColor);
    @Overload void setStrokeStyle(Gradient gradient);
    @Overload void setFillStyle(String cssColor);
    @Overload void setFillStyle(Gradient gradient);
}

class Canvas extends Element{
    CanvasContext getContext(String contextId);
}
class Event;
class Document{
    Attr creaetAttribute(String name);
    Element createElement(String tagName);
    Element getElementById(String elementId);
    NodeList getElementsByTagName(String tagName);
    Text createTextNode(String data);
    void cleaer();
    void close();
    void open();
    void write(String str);
    void writeln(String str);

    /* Interface */
    Event createEvent(String eventInterface);
}

class EventTarget;
class Event {
    String getType();
    EventTarget getTarget();
    EventTarget getCurrentTarget();
    int getEventPhase();
    boolean getBubbles();
    boolean getCancelable();
    int getTimeStamp();
    void stopPropagation();
    void preventDefault();
    void initEment(String eventTypeArg, boolean canBubbleArg, boolean cancelableArg);
    void stopImmediatePropagation();
    boolean getDefaultPrevented();
    boolean getIsTrusted();
}
class CustomEvent extends Event {
    /* dynamic getDetail(); */
    void initCustomEvent(String typeArg, boolean canBubbleArg, boolean cancelableArg, dynamic detailArg);
}
class EventListener {
    void handleEvent(Event evt);
}
class EventTarget {
    void addEventListener(String type, EventListener listener, boolean useCapture);
    void removeEventListener(String type, EventListener listener, boolean useCapture);
    boolean dispatchEvent(Event evt);
}
class EventException {

}
class AbstractView;
class UIEvent extends Event {
    AbstractView getView();
    int getDetail();
    void initUIEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            int detailArg);
}
class FocusEvent extends UIEvent {
    EventTarget getRelatedTarget();
    void initFocusEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            int detailArg,
            EventTarget relatedTargetArg);
}
class MouseEvent extends UIEvent {
    int getScreenX();
    int getScreenY();
    int getClientX();
    int getClientY();
    boolean getCtrlKey();
    boolean getShiftKey();
    boolean getAltKey();
    boolean getMetaKey();
    int getButton();
    int getButtons();
    EventTarget getRelatedTarget();
    void initMouseEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            int detailArg,
            int screenXArg,
            int screenYArg,
            int clientXArg,
            int clientYArg,
            boolean ctrlKeyArg,
            boolean altKeyArg,
            bookean shiftKeyArg,
            boolean metaKeyArg,
            int buttonArg,
            EventTarget relatedTargetArg);
    boolean getModifierState(String keyArg);
}
class WheelEvent extends MouseEvent {
    float getDeltaX();
    float getDeltaY();
    float getDeltaZ();
    int getDeltaMode();
    void initWheelEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            int detailArg,
            int screenXArg,
            int screenYArg,
            int clientXArg,
            int clientYArg,
            int buttonArg,
            EventTarget relatedTargetArg,
            String modifiersListArg,
            float deltaXArg,
            float deltaYArg,
            float deltaZArg,
            int deltaMode);
}
class TextEvent extends UIEvent {
    String getData();
    int getInputMethod();
    String getLocale();
    void initTextEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            String dataArg,
            int inputMethod,
            String localeArg);
}
class KeyboardEvent extends UIEvent {
    String getChar();
    String getKey();
    int getLocation();
    boolean getCtrlKey();
    boolean getShiftKey();
    boolean getAltKey();
    boolean getMetaKey();
    boolean getRepeat();
    String getLocale();
    boolean getModifierState(String keyArg);
    void initKeyboardEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            String charArg,
            String keyArg,
            int locationArg,
            String modifiersListArg,
            boolean repeat,
            String localeArg);
}
class CompositionEvent extends UIEvent {
    String getData();
    String getLocale();
    void initCompositionEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            AbstractView viewArg,
            String dataArg,
            String localeArg);
}
class MutationEvent extends Event {
    Node getRelatedNode();
    String getPrevValue();
    String getNewValue();
    String getAttrName();
    int getAttrChange();
    void initMutationEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            Node relatedNodeArg,
            String prevValueArg,
            String newValueArg,
            String attrNameArg,
            int attrChangeArg);
}
class MutationNameEvnet extends MutationEvent {
    String getPrevNamespaceURI();
    String getPrevNodeName();
    void initMutationNameEvent(
            String typeArg,
            boolean canBubbleArg,
            boolean cancelableArg,
            Node relatedNodeArg,
            String prevNamespaceURIArg,
            String prevNodeNameArg);
}
