/*
 * Richards Benchmark
 */
include "_bench.k";
// based on a Java version:
//  Based on original version written in BCPL by Dr Martin Richards
//  in 1981 at Cambridge University Computer Laboratory, England
//  and a C++ version derived from a Smalltalk version written by
//  L Peter Deutsch.
//  Java version:  Copyright (C) 1995 Sun Microsystems, Inc.
//  Translation from C++, Mario Wolczko
//  Outer loop added by Alex Jacoby

// Task IDs
I_IDLE = 1;
I_WORK = 2;
I_HANDLERA = 3;
I_HANDLERB = 4;
I_DEVA = 5;
I_DEVB = 6;

// Packet types
K_DEV  = 1000;
K_WORK = 1001;

// Packet

BUFSIZE = 4;

class Packet {
    Packet link;
    int ident;
    int kind;
    int datum;
    int[] data;

    Packet(Packet l,int i,int k) {
        this.link = l;
        this.ident = i;
        this.kind = k;
        this.datum = 0;
        this.data = new int[BUFSIZE];
    }

    Packet append_to(Packet list) {
        this.link = null;
        if (list == null) {
            return this;
        }
        else {
            Packet p = list;
            Packet next = p.link;
            while (next != null) {
                p = next;
                next = p.link;
            }
            p.link = this;
            return list;
        }
    }
}
// Task Records

class TaskRec {}

class DeviceTaskRec extends TaskRec {
    Packet pending;
    DeviceTaskRec() {
        this.pending = null;
    }
}
class IdleTaskRec extends TaskRec {
    int control;
    int count;
    IdleTaskRec() {
        this.control = 1;
        this.count = 10000;
    }
}
class HandlerTaskRec extends TaskRec {
    Packet work_in;
    Packet device_in;
    HandlerTaskRec() {
        this.work_in   = null;
        this.device_in = null;
    }

    Packet workInAdd(Packet p) {
        this.work_in = p.append_to(this.work_in);
        return this.work_in;
    }

    Packet deviceInAdd(Packet p) {
        this.device_in = p.append_to(this.device_in);
        return this.device_in;
    }
}
class WorkerTaskRec extends TaskRec {
    int destination;
    int count;
    WorkerTaskRec() {
        this.destination = I_HANDLERA
        this.count = 0
    }
}
// Task

class TaskState {
    Boolean packet_pending;
    Boolean task_waiting;
    Boolean task_holding;
    TaskState() {
        this.packet_pending = true;
        this.task_waiting   = false;
        this.task_holding   = false;
    }

    TaskState packetPending() {
        this.packet_pending = true;
        this.task_waiting   = false;
        this.task_holding   = false;
        return this;
    }

    TaskState waiting() {
        this.packet_pending = false;
        this.task_waiting   = true;
        this.task_holding   = false;
        return this;
    }

    TaskState running() {
        this.packet_pending = false;
        this.task_waiting   = false;
        this.task_holding   = false;
        return this;
    }

    TaskState waitingWithPacket() {
        this.packet_pending = true;
        this.task_waiting   = true;
        this.task_holding   = false;
        return this;
    }

    Boolean isTaskHoldingOrWaiting() {
        return task_holding or (not packet_pending and task_waiting);
    }

    Boolean isWaitingWithPacket() {
        return packet_pending and task_waiting and not task_holding;
    }
}
TRACING = false;
int layout = 0;
TASKTABSIZE = 10

class Task extends TaskState {
    Task link;
    int ident;
    int priority;
    Packet input;
    TaskRec handle;

    void init(int i, int p, Packet w, TaskState initialState, TaskRec r);
    Task(int i, int p, Packet w, TaskState initialState, TaskRec r) {
        init(i, p, w, initialState, r);
    }
    @Virtual Task fn(Packet pkt, TaskRec r) {
        ERR.println("error");
        return null;
    }
    Task Task.findtcb(int id);
}

class TaskWorkArea{
    Task[] taskTab;
    Task   taskList;
    int holdCount;
    int qpktCount;
    TaskWorkArea() {
        this.taskTab   = new Task[TASKTABSIZE];
        this.taskList  = null;
        this.holdCount = 0;
        this.qpktCount = 0;
    }
}

TaskWorkArea taskWorkArea = new TaskWorkArea();

void trace(int a) {
    layout -= 1;
    if (layout <= 0) {
        OUT.println();
        layout = 50
    }
    OUT.print(a);
}

void Task.init(int i, int p, Packet w, TaskState initialState, TaskRec r) {
    this.link = taskWorkArea.taskList;
    this.ident = i;
    this.priority = p;
    this.input = w;

    this.packet_pending = initialState.isPacketPending();
    this.task_waiting   = initialState.isTaskWaiting();
    this.task_holding   = initialState.isTaskHolding();

    this.handle = r;

    taskWorkArea.taskList = this;
    taskWorkArea.taskTab[i] = this;
}

Task Task.addPacket(Packet p, Task old) {
    if (this.input == null) {
        this.input = p;
        this.packet_pending = true;
        if (this.priority > old.priority) {
            return this;
        }
    }
    else {
        p.append_to(this.input);
    }
    return old;
}


Task Task.runTask() {
    Packet msg;
    if (this.isWaitingWithPacket()) {
        msg = this.input;
        this.input = msg.link;
        if (this.input == null) {
            this.running();
        }
        else {
            this.packetPending();
        }
    }
    else {
        msg = null;
    }

    return this.fn(msg,this.handle);
}


Task Task.waitTask() {
    this.task_waiting = true;
    return this;
}

Task Task.hold() {
    taskWorkArea.holdCount += 1;
    this.task_holding = true;
    return this.link;
}

Task Task.release(int i) {
    Task t = this.findtcb(i);
    t.task_holding = false;
    if (t.priority > this.priority) {
        return t;
    }
    else {
        return this;
    }
}

Task Task.qpkt(Packet pkt) {
    Task t = this.findtcb(pkt.ident);
    taskWorkArea.qpktCount += 1;
    pkt.link = null;
    pkt.ident = this.ident;
    return t.addPacket(pkt, this);
}

Task Task.findtcb(int id) {
    Task t = taskWorkArea.taskTab[id];
    if (t == null) {
        OUT.println("\tBad task id " + id);
    }
    return t;
}

// DeviceTask

class DeviceTask extends Task {
    DeviceTask(int i, int p, Packet w, TaskState s, TaskRec r) {
        this.init(i, p, w, s, r);
    }

    @Override Task fn(Packet pkt, TaskRec r) {
        DeviceTaskRec d = (DeviceTaskRec)r;
        Task ret;
        if (pkt == null) {
            pkt = d.pending;
            if (pkt == null) {
                ret = this.waitTask();
            }
            else {
                d.pending = null;
                ret = this.qpkt(pkt);
            }
        }
        else {
            d.pending = pkt;
            if (TRACING) trace(pkt.datum);
            ret = this.hold();
        }
        return ret;
    }
}

class HandlerTask extends Task {
    HandlerTask(int i, int p, Packet w, TaskState s, TaskRec r) {
        this.init(i, p, w, s, r);
    }

    @Override Task fn(Packet pkt, TaskRec r) {
        HandlerTaskRec h = (HandlerTaskRec) r;
        if (pkt != null) {
            if (pkt.kind == K_WORK) {
                h.workInAdd(pkt);
            } else {
                h.deviceInAdd(pkt);
            }
        }
        Packet work = h.work_in;
        if (work == null) {
            return this.waitTask();
        }
        int count = work.datum;
        if (count >= BUFSIZE) {
            h.work_in = work.link;
            return this.qpkt(work);
        }

        Packet dev = h.device_in;
        if (dev == null) {
            return this.waitTask();
        }

        h.device_in = dev.link;
        dev.datum = work.data[count];
        work.datum = count + 1;
        return this.qpkt(dev);
    }
}

// IdleTask


class IdleTask extends Task {
    IdleTask(int i, int p, int a2, TaskState s, TaskRec r) {
        this.init(i, 0, null, s, r);
    }

    @Override Task fn(Packet pkt, TaskRec r) {
        IdleTaskRec i = (IdleTaskRec) r;
        i.count -= 1;
        Task ret;
        if (i.count == 0) {
            ret = this.hold();
        }
        else if ((i.control & 1) == 0) {
            i.control = i.control / 2;
            ret = this.release(I_DEVA);
        }
        else {
            i.control = (i.control/2) ^ 0xd008;
            ret = this.release(I_DEVB);
        }
        return ret;
    }
}

// WorkTask


class WorkTask extends Task {
    WorkTask(int i, int p, Packet w, TaskState s, TaskRec r) {
        this.init(i, p, w, s, r);
    }

    @Override Task fn(Packet pkt, TaskRec r) {
        WorkerTaskRec w = (WorkerTaskRec) r;
        if (pkt == null) {
            return this.waitTask();
        }

        int dest;
        if (w.destination == I_HANDLERA) {
            dest = I_HANDLERB;
        }
        else {
            dest = I_HANDLERA;
        }

        w.destination = dest;
        pkt.ident = dest;
        pkt.datum = 0;

        for (int i = 0; i < BUFSIZE; i++) {
            w.count += 1;
            if (w.count > 26) {
                w.count = 1;
            }
            pkt.data[i] = 'A' + w.count - 1;
        }

        return this.qpkt(pkt);
    }
}

void schedule() {
    Task t = taskWorkArea.taskList;
    while (t != null) {
        Packet pkt = null;

        if (TRACING) {
            OUT.print("tcb = "+t.ident);
        }

        if (t.isTaskHoldingOrWaiting()) {
            t = t.link
        }
        else {
            if (TRACING)
                trace('0'+t.ident);
            t = t.runTask();
        }
    }
}

N=1000;
class Richards extends BenchMarkTask  {
    Richards() {
        this.name = "RichardsBenchmark";
    }
    @Override void run() {
        int iterations = N;
        long total_ms;
        OUT.println("Richards benchmark (konoha) starting...");
        long startTime = System.getTime();
        if (!exec())
            return;
        long endTime = System.getTime();
        OUT.println("finished.");
        total_ms= endTime - startTime;
        OUT.println("Total time for " + iterations + " iterations: " + (total_ms/1000.0) + " secs");
        OUT.println("Average time per iteration: " + (total_ms / iterations) + " ms");
    }

    boolean exec() {
        int iterations = N;
        for (int i= 0; i < iterations; i++){
            taskWorkArea.holdCount = 0;
            taskWorkArea.qpktCount = 0;

            new IdleTask(I_IDLE, 1, 10000, (new TaskState()).running(), new IdleTaskRec());

            Packet wkq = new Packet(null, 0, K_WORK);
            wkq = new Packet(wkq, 0, K_WORK);
            new WorkTask(I_WORK, 1000, wkq,
                    (new TaskState()).waitingWithPacket(),
                    new WorkerTaskRec());

            wkq = new Packet(null, I_DEVA, K_DEV);
            wkq = new Packet(wkq , I_DEVA, K_DEV);
            wkq = new Packet(wkq , I_DEVA, K_DEV);
            new HandlerTask(I_HANDLERA, 2000, wkq,
                    (new TaskState()).waitingWithPacket(),
                    new HandlerTaskRec());

            wkq = new Packet(null, I_DEVB, K_DEV);
            wkq = new Packet(wkq, I_DEVB, K_DEV);
            wkq = new Packet(wkq, I_DEVB, K_DEV);
            new HandlerTask(I_HANDLERB, 3000, wkq,
                    (new TaskState()).waitingWithPacket(),
                    new HandlerTaskRec());

            wkq = null;
            new DeviceTask(I_DEVA, 4000, wkq, (new TaskState()).waiting(),
                    new DeviceTaskRec());
            new DeviceTask(I_DEVB, 5000, wkq, (new TaskState()).waiting(),
                    new DeviceTaskRec());

            schedule();

            if (taskWorkArea.holdCount == 9297 &&
                    taskWorkArea.qpktCount == 23246) {
                // correct
            } else {
                OUT.println("Incorrect results!");
                return false;
            }
        }
        return true;
    }

}
void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Richards();
    bm.run();
}
