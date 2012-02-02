using js.dom.*;
using js.jquery.*;
using konoha.lang.*;
void buildHTML() {
    Document d = new Document();
    body = d.getElementsByTagName("body").item(0);
    div = d.createElement("div");
    div.appendChild(d.createTextNode("hello"));
    body.appendChild(div);
}
@Public void Element.f0() {
    new JQuery(this).css("border", "3px solid blue");
    new JQuery(this).css("color", "blue")
}
@Public void Element.f1() {
    new JQuery(this).css("border", "3px solid red");
    new JQuery(this).css("color", "red");
}
void main() {
    buildHTML();
    new JQuery("div").css("border", "3px solid black");
    new JQuery("div").css("color", "black");
    new JQuery("div").toggleEvent([method:Element.f0, method:Element.f1]);
}
