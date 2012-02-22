using js.dom.*;
using js.jquery.*;
using konoha.lang.*;

void buildHTML();
int closed = 0;
int numClicked = -1;
JQuery divClicked1;
JQuery divClicked2;
String[] colors;
@Public void Element.change() {
    divClicked1.css("background-color", "white");
    divClicked2.css("background-color", "white");
}
@Public void Element.onclick(JEvent e) {
    print e.pageX();
    print e.pageY();
    JQuery j = new JQuery(this);
    print j;
    int i = (to Int)j.getAttr("val");
    if (i == numClicked) {
        return;
    }
    if (numClicked == -1) {
        j.css("background-color", colors[i]);
        numClicked = i;
        divClicked1 = j;
        divClicked1.unbind();
    } else {
        if (colors[i].equals(colors[numClicked])) {
            j.css("background-color", colors[i]);
            j.hide(100);
            divClicked1.hide(100);
            closed += 1;
        } else {
            divClicked1.click(method:Element.onclick);
            divClicked2 = j;
            divClicked2.css("background-color", colors[i]);
            divClicked1.fadeOut(200);
            divClicked2.fadeOut(200);
            divClicked1.fadeIn(200);
            divClicked2.fadeIn(200, method:Element.change);
        }
        numClicked = -1;
    }
    if (closed == |colors|) {
        new JQuery("div").remove();
        buildHTML();
    }
}
void buildHTML() {
    colors = [];
    colors.add("Teal");
    colors.add("LawnGreen");
    colors.add("HotPink");
    colors.add("Aqua");
    colors.add("red");
    colors.add("green");
    colors.add("yellow");
    colors.add("Brown");
    int[] flags = new Int[|colors|];
    for (int i = 0; i < |colors| * 2; i++) {
        JQuery j = new JQuery("<div></div>");
        while(true) {
            int index = Int.random(|colors|);
            if (flags[index] < 2) {
                j.attr("val", index + "");
                flags[index] = flags[index] + 1;
                break;
            }
        }
        j.css("position", "absolute");
        j.css("width", "80px");
        j.css("height", "80px");
        j.css("border", "1px solid black");
        j.css("background-color", "white");
        j.css("top", 100 * (int)(i/4) + 10 + "");
        j.css("left", 100 * (i%4)+ 10 + "");
        j.click(method:Element.onclick);
        new JQuery("body").append(j)
    }
}

void main() {
    buildHTML();
}
