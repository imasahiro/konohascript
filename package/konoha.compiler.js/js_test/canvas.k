using konoha.compiler.*;
using js.dom.*;
void main() {
    d = new Document();
    Node body = d.getElementsByTagName("body").item(0);
    Canvas canvas = (Canvas)d.createElement("Canvas");
    canvas.setAttribute("width", "256");
    canvas.setAttribute("height", "256");
    body.appendChild(canvas);
    ctx = canvas.getContext("2d");
    ctx.setFillStyle("#ff0000");
    ctx.fillRect(100, 100, 100, 100);
    ctx.setFillStyle("#00ff00")
    ctx.fillRect(200, 200, 50, 50);
    ctx.setFillStyle("#00ff00");
    ctx.fillText("hi", 20, 20);
}
