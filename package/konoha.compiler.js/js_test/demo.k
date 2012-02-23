using konoha.math.*;
using konoha.lang.*;
using js.dom.*;
using js.jquery.*;
void initCanvas();
class Mover {
    String color;
    float x;
    float y;
    float vX;
    float vY;
    int size = 1;
    Mover(int i, int canvasW, int canvasH) {
        this.color = "rgb(" + Int.random(256) + "," + Int.random(256) + "," + Int.random(256) + ")";
        this.x = canvasW * 0.5;
        this.y = canvasH * 0.5;
        this.vX = Math.cos(i) * Float.random() * 34;
        this.vY = Math.sin(i) * Float.random() * 34;
    }
}
class ParticleContext {
    int canvasW;
    int canvasH;
    int timerId;
    int numMovers;
    float friction;
    Mover[] movers;
    Canvas canvas;
    CanvasContext ctx;
    int mouseX;
    int mouseY;
    float mouseVX;
    float mouseVY;
    int prevMouseX;
    int prevMouseY;
    boolean mouseDown;
    ParticleContext() {
    }
    void init() {
        this.canvasW = 900;
        this.canvasH = 600;
        this.numMovers = 800;
        this.friction = 0.98;
        this.movers = [];
    }
}
ParticleContext pc = new ParticleContext();
pc.init();

void play() {
    initCanvas();
    new JQuery("#mainCanvas").css("display", "none").css("visibility", "visible");
    int w = new JQuery(new Window()).width();
    int h = new JQuery(new Window()).height();
    int imgW = new JQuery("#mainCanvas").width();
    int imgH = new JQuery("#mainCanvas").height();
    int imgLeft = (w-imgW-10*2)/2;
    int imgTop = (h-imgH-10*2-50)/2;
    new JQuery("#mainCanvas").css("left", imgLeft+"px").css("top", imgTop+"px");
    new JQuery("#close").css("left", imgLeft+"px").css("top", (imgTop+imgH+10*2)+"px");
    new JQuery("#close").width(imgW);
    new JQuery("#mainCanvas , #close").fadeIn(500);
}
@Public void Element.click1() {
    int h = new JQuery(new Window()).height();;
    new JQuery("#back").height(h);
    new JQuery("#back").css("opacity", "0.7").fadeIn(200);
    String fname = "b_" + new JQuery(this).getattr("src");
    new JQuery("body").append("<canvas class='big' id='mainCanvas'>");
    new JQuery("#mainCanvas").css("visibility", "hidden").css("display", "block");
    //new JQuery("#mainCanvas").load(method:Element.play);
    play();
}
@Public void Element.click2() {
    System.clearInterval(pc.timerId);
    new JQuery("body").unbind();
    new JQuery("#mainCanvas").unbind();
    new JQuery("#mainCanvas").remove();
    new JQuery("#back , #close").css("display", "none");
}


@Public void Element.onMouseMove(JEvent e) {
    Offset ca = new JQuery("#mainCanvas").offset();
    Offset cd = new JQuery("#canvasContainer").offset();
    pc.mouseX = e.pageX() - ca.getLeft() - 10; /* canvas.big: border */
    pc.mouseY = e.pageY() - ca.getTop() - 10; /* canvas.big: border */
}
@Public boolean Element.onMouseDown(JEvent e) {
    pc.mouseDown = true;
    return false;
}

@Public boolean Element.onMouseUp(JEvent e) {
    pc.mouseDown = false;
    return false;
}
void setup() {
    //canvasH = new JQuery("body").innerHeight();
    //canvasW = new JQuery("outer").innerWidth();

    new JQuery("#mainCanvas").attr("width", pc.canvasW+"");
    new JQuery("#mainCanvas").attr("height", pc.canvasH+"");
    pc.ctx = pc.canvas.getContext("2d");
    pc.movers.clear();
    for (int i = 0; i < pc.numMovers; i++) {
        pc.movers.add(new Mover(i, pc.canvasW, pc.canvasH));
    }
    pc.mouseX = pc.canvasW * 0.5;
    pc.prevMouseX = pc.mouseX;
    pc.mouseY = pc.canvasH * 0.5;
    pc.prevMouseY = pc.mouseY;
    new JQuery("canvas").mousemove(method:Element.onMouseMove);
    new JQuery("#mainCanvas").mousedown(method:Element.onMouseDown);
    new JQuery("#mainCanvas").mouseup(method:Element.onMouseUp);
}

@Public void Element.draw() {
    int canvasW = pc.canvasW;
    int canvasH = pc.canvasH;
    CanvasContext ctx = pc.ctx;
    ctx.setGlobalCompositeOperation("source-over");
    ctx.setFillStyle("rgba(8,8,12,.65)");
    ctx.fillRect(0, 0, canvasW, canvasH);
    ctx.setGlobalCompositeOperation("lighter");
    pc.mouseVX = pc.mouseX - pc.prevMouseX;
    pc.mouseVY = pc.mouseY - pc.prevMouseY;
    pc.prevMouseX = pc.mouseX;
    pc.prevMouseY = pc.mouseY;

    float toDist = canvasW * 0.86;
    float stirDist = canvasW * 0.125;
    float blowDist = canvasW * 0.5;
    for (int i = 0; i < pc.numMovers; i++) {
        Mover m = pc.movers[i];
        float x = m.x;
        float y = m.y;
        float vX = m.vX;
        float vY = m.vY;
        float dX = x - pc.mouseX;
        float dY = y - pc.mouseY;
        float d = Math.sqrt(dX * dX + dY * dY);
        if (d == 0) {
            d = 0.001;
        }
        dX = dX / d;
        dY = dY / d;
        if (pc.mouseDown && d < blowDist) {
            float blowAcc = (1 - (d / blowDist)) * 14;
            vX = vX + (dX * blowAcc + 0.5 - Float.random());
            vY = vY + (dY * blowAcc + 0.5 - Float.random());
        }

        if (d < toDist) {
            float toAcc = (1 - (d / toDist)) * canvasW * 0.0014;
            vX = vX - dX * toAcc;
            vY = vY - dY * toAcc;
        }

        if (d < stirDist) {
            float mAcc = (1 - (d / stirDist)) * canvasW * 0.00026;
            vX = vX + pc.mouseVX * mAcc;
            vY = vY + pc.mouseVY * mAcc;
        }

        vX = vX * pc.friction;
        vY = vY * pc.friction;

        float avgVX = Math.fabs(vX);
        float avgVY = Math.fabs(vY);
        float avgV = (avgVX + avgVY) * 0.5;

        if (avgVX < 0.1) {
            vX = vX * Float.random() * 3;
        }
        if (avgVY < 0.1) {
            vY = vY * Float.random() * 3;
        }

        float sc = avgV * 0.45;
        if (sc > 3.5) {
            sc = 3.5;
        }
        if (sc < 0.4) {
            sc = 0.4;
        }

        float nextX = x + vX;
        float nextY = y + vY;

        if (nextX > canvasW) {
            nextX = canvasW;
            vX = vX * -1;
        }
        if (nextX < 0) {
            nextX = 0;
            vX = vX * -1;
        }
        m.vX = vX;
        m.x = nextX;

        if (nextY > canvasH) {
            nextY = canvasH;
            vY = vY * -1;
        } 
        if (nextY < 0) {
            nextY = 0;
            vY = vY * -1;
        }

        m.vY = vY;
        m.y = nextY;
        ctx.setFillStyle(m.color);
        ctx.beginPath();
        ctx.arc(nextX, nextY, sc, 0, (Math.PI * 2), true);
        ctx.closePath();
        ctx.fill();
    }
}
void initCanvas() {
    pc.canvas = (Canvas)(new Document().getElementById("mainCanvas"));
    setup();
    pc.timerId = System.setInterval(method:Element.draw, 33);
}
void main() {
    int y = 0;
    new JQuery("#back").css("top", y+"px");
    new JQuery(".mini").click(method:Element.click1);
    new JQuery("#close").click(method:Element.click2);
}
