using konoha.math.*; using konoha.lang.*;
using js.dom.*;
using js.jquery.*;
void initCanvas();
@Public void Element.draw();
@Public boolean Element.onMouseDown(JEvent e);
@Public void Element.onMouseMove(JEvent e);
@Public boolean Element.onMouseUp(JEvent e);
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
class SimpleParticleContext {
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
    SimpleParticleContext() {
    }
    @Virtual void init() {
        this.canvasW = 900;
        this.canvasH = 600;
        this.numMovers = 800;
        this.friction = 0.98;
        this.movers = [];
    }
    @Virtual void setup() {
        new JQuery("#mainCanvas").attr("width", canvasW+"");
        new JQuery("#mainCanvas").attr("height", canvasH+"");
        ctx = canvas.getContext("2d");
        movers.clear();
        for (int i = 0; i < numMovers; i++) {
            movers.add(new Mover(i, canvasW, canvasH));
        }
        mouseX = canvasW * 0.5;
        prevMouseX = mouseX;
        mouseY = canvasH * 0.5;
        prevMouseY = mouseY;
        new JQuery("canvas").mousemove(method:Element.onMouseMove);
        new JQuery("#mainCanvas").mousedown(method:Element.onMouseDown);
        new JQuery("#mainCanvas").mouseup(method:Element.onMouseUp);
    }
    void initCanvas() {
        canvas = (Canvas)(new Document().getElementById("mainCanvas"));
        setup();
    }

    @Virtual void play() {
        new JQuery("body").append("<canvas class='big' id='mainCanvas'>");
        new JQuery("#mainCanvas").css("visibility", "hidden").css("display", "block");
        initCanvas();
        new JQuery("#mainCanvas").css("display", "none").css("visibility", "visible");
        int w = new JQuery(new Window()).width();
        int h = new JQuery(new Window()).height();
        int imgW = new JQuery("#mainCanvas").width();
        int imgH = new JQuery("#mainCanvas").height();
        int imgLeft = (w-imgW-10*2)/2;
        int imgTop = (h-imgH-10*2-50)/2;
        new JQuery("#mainCanvas").css("left", imgLeft+"px").css("top", imgTop+"px");
        int left = imgLeft + canvasW / 10 * 9;
        new JQuery("#close").css("left", left+"px").css("top", (imgTop+imgH+10*2)+"px");
        left = imgLeft;
        new JQuery("#demo1").css("left", left+"px").css("top", (imgTop+imgH+10*2)+"px");
        left = imgLeft + canvasW / 10;
        new JQuery("#demo2").css("left", left+"px").css("top", (imgTop+imgH+10*2)+"px");
        left = imgLeft + canvasW / 10 * 2;
        new JQuery("#demo3").css("left", left+"px").css("top", (imgTop+imgH+10*2)+"px");
        int width = canvasW / 10;
        new JQuery("#close").width(width + 20);
        new JQuery("#demo1").width(width);
        new JQuery("#demo2").width(width);
        new JQuery("#demo3").width(width);
        new JQuery("#mainCanvas , #close").fadeIn(500);
        new JQuery("#demo1").fadeIn(500);
        new JQuery("#demo2").fadeIn(500);
        new JQuery("#demo3").fadeIn(500);
        ctx.setGlobalCompositeOperation("source-over");
        ctx.setFillStyle("rgba(8,8,12,.65)");
        ctx.fillRect(0, 0, canvasW, canvasH);
        ctx.setFillStyle("#ffffff");
        ctx.setFont("20pt Arial");
        ctx.fillText("JavaScript Demo Page", 300, canvasH/2);
        ctx.setGlobalCompositeOperation("lighter");
    }
}
SimpleParticleContext pc_global;

SimpleParticleContext spc = new SimpleParticleContext();
spc.init();

class ParticleContextNoMouseEvent extends SimpleParticleContext{
    ParticleContextNoMouseEvent() {
    }
    @Override void init() {
        this.canvasW = 900;
        this.canvasH = 600;
        this.numMovers = 800;
        this.friction = 1.00;
        this.movers = [];
    }
    void play() {
        new JQuery("body").append("<canvas class='big' id='mainCanvas'>");
        new JQuery("#mainCanvas").css("visibility", "hidden").css("display", "block");
        initCanvas();
        new JQuery("#mainCanvas").css("display", "none").css("visibility", "visible");
        int w = new JQuery(new Window()).width();
        int h = new JQuery(new Window()).height();
        int imgW = new JQuery("#mainCanvas").width();
        int imgH = new JQuery("#mainCanvas").height();
        int imgLeft = (w-imgW-10*2)/2;
        int imgTop = (h-imgH-10*2-50)/2;
        new JQuery("#mainCanvas").css("left", imgLeft+"px").css("top", imgTop+"px");
        new JQuery("#mainCanvas").fadeIn(500);
        timerId = System.setInterval(method:Element.draw, 33);
    }
}
ParticleContextNoMouseEvent pcnme = new ParticleContextNoMouseEvent();
pcnme.init();


class ParticleContext extends SimpleParticleContext{
    ParticleContext() {
    }
    @Override void init() {
        this.canvasW = 900;
        this.canvasH = 600;
        this.numMovers = 800;
        this.friction = 0.98;
        this.movers = [];
    }
    void play() {
        new JQuery("body").append("<canvas class='big' id='mainCanvas'>");
        new JQuery("#mainCanvas").css("visibility", "hidden").css("display", "block");
        initCanvas();
        new JQuery("#mainCanvas").css("display", "none").css("visibility", "visible");
        int w = new JQuery(new Window()).width();
        int h = new JQuery(new Window()).height();
        int imgW = new JQuery("#mainCanvas").width();
        int imgH = new JQuery("#mainCanvas").height();
        int imgLeft = (w-imgW-10*2)/2;
        int imgTop = (h-imgH-10*2-50)/2;
        new JQuery("#mainCanvas").css("left", imgLeft+"px").css("top", imgTop+"px");
        new JQuery("#mainCanvas").fadeIn(500);
        timerId = System.setInterval(method:Element.draw, 33);
    }
}
ParticleContext pc = new ParticleContext();
pc.init();

void clearIntervalAll() {
    System.clearInterval(pc.timerId);
    System.clearInterval(spc.timerId);
    System.clearInterval(pcnme.timerId);
}
void clearDemo() {
    new JQuery("#mainCanvas").remove();
}

@Public void Element.click1() {
    int h = new JQuery(new Window()).height();;
    new JQuery("#back").height(h);
    new JQuery("#back").css("opacity", "0.7").fadeIn(200);
    pc_global = spc;
    spc.play();
}
@Public void Element.click2() {
    clearIntervalAll();
    clearDemo();
    new JQuery("body").unbind();
    new JQuery("#mainCanvas").unbind();
    new JQuery("#back , #close").css("display", "none");
    new JQuery("#demo1").css("display", "none");
    new JQuery("#demo2").css("display", "none");
    new JQuery("#demo3").css("display", "none");
}
@Public void Element.click3() {
    clearIntervalAll();
    clearDemo();
    pc_global = pc;
    pc.play();
}
@Public void Element.click4() {
    clearIntervalAll();
    clearDemo();
    pc_global = spc;
    spc.play();
}
@Public void Element.click5() {
    clearIntervalAll();
    clearDemo();
    pc_global = pcnme;
    pcnme.play();
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


@Public void Element.draw() {
    int canvasW = pc_global.canvasW;
    int canvasH = pc_global.canvasH;
    CanvasContext ctx = pc_global.ctx;
    ctx.setGlobalCompositeOperation("source-over");
    ctx.setFillStyle("rgba(8,8,12,.65)");
    ctx.fillRect(0, 0, canvasW, canvasH);
    ctx.setGlobalCompositeOperation("lighter");
    pc_global.mouseVX = pc_global.mouseX - pc_global.prevMouseX;
    pc_global.mouseVY = pc_global.mouseY - pc_global.prevMouseY;
    pc_global.prevMouseX = pc_global.mouseX;
    pc_global.prevMouseY = pc_global.mouseY;

    float toDist = canvasW * 0.86;
    float stirDist = canvasW * 0.125;
    float blowDist = canvasW * 0.5;
    for (int i = 0; i < pc_global.numMovers; i++) {
        Mover m = pc_global.movers[i];
        float x = m.x;
        float y = m.y;
        float vX = m.vX;
        float vY = m.vY;
        float dX = x - pc_global.mouseX;
        float dY = y - pc_global.mouseY;
        float d = Math.sqrt(dX * dX + dY * dY);
        if (d == 0) {
            d = 0.001;
        }
        dX = dX / d;
        dY = dY / d;
        if (pc_global.mouseDown && d < blowDist) {
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
            vX = vX + pc_global.mouseVX * mAcc;
            vY = vY + pc_global.mouseVY * mAcc;
        }

        vX = vX * pc_global.friction;
        vY = vY * pc_global.friction;

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
void main() {
    int y = 0;
    new JQuery("#back").css("top", y+"px");
    new JQuery(".mini").click(method:Element.click1);
    new JQuery("#close").click(method:Element.click2);
    new JQuery("#demo1").click(method:Element.click4);
    new JQuery("#demo2").click(method:Element.click5);
    new JQuery("#demo3").click(method:Element.click3);
}
