using konoha.json.*;
Set=Map<String, Float>;

class BenchMarkTask {
    String name;
    @virtual void run() {}
}

//@Public void OutputStream.writeCSV(Map m) {
//    String[] keys = m.keys();
//    dynamic a = m["average"]; /*Array<Map> */
//    dynamic akeys = a.keys();
//    int task_size = akeys.size;
//    for (int j=0; j < task_size; j++) {
//        this.print(m["platform"]["data"]+",");
//        this.print($script.name);
//        this.print(",");
//        dynamic key = akeys[j];
//        this.print(key);
//        this.print(",");
//        this.print(a.get(key));
//        this.print(",");
//        dynamic o = m["rawdata"]; /*Array<Map> */
//        int size = o.size;
//        for (int i=0; i < size; i++) {
//            dynamic v = o.get(i);
//            this.print(v.get(key));
//            this.print(",");
//        }
//        this.println();
//    }
//}

class Benchmark extends BenchMarkTask {
    BenchMarkTask[] tasks;
    int cycle;
    Outputstream ous;
    Benchmark(int cycle) {
        this.name  = "Benchmark";
        this.cycle = cycle;
        this.tasks = [];
        this.ous   = OUT;
        String[] argv = $script.argv;
        for (int i=0; i < argv.size; i++) {
            String s = argv[i];
            if (s.startsWith("--Benchmark:OUTPUT=")) {
                String file = s.replace("--Benchmark:OUTPUT=", "");
                this.ous = new OutputStream(file, "a");
            }
            if (s.startsWith("--Benchmark:SIZE=")) {
                int n = (to Int) s.replace("--Benchmark:SIZE=", "");
                this.cycle = n;
            }
        }
    }
    Map<String, String> platform() {
        Map<String, String> m = new();
        m["data"] = (to String) new Date();
        m["konoha.version"] = $konoha.version;
        //m["konoha.options"] = System.KONOHA_OPTIONS;
        //m["system.cc"]      = System.KONOHA_HOSTCC;
        //m["system.os"]      = System.SYSTEM_OSTYPE;
        //m["system.arch"]    = System.SYSTEM_OSARCH;
        //m["system.cpu"]     = System.SYSTEM_CPU;
        //m["system.bits"]    = (to String) System.SYSTEM_BITS;
        return m;
    }
    void addTask(BenchMarkTask t) {
        this.tasks.add(t);
    }
    @Override void run() {
        Map m = {};
        m["platform"] = platform();
        Set[] data = [];
        for (int i=0; i < cycle; i++) {
            Set d = new();
            for (int j=0; j < tasks.size; j++) {
                BenchMarkTask t = tasks[j];
                int s = System.getTime();
                t.run();
                int e = System.getTime();
                d[t.name] = e - s;
                ous.println(t.name+","+(e-s));
            }
            data.add(d);
        }
        m["rawdata"] = data;
        ///* print average */
        //Set average = new();
        //foreach (BenchMarkTask t in tasks) {
        //    String name = t.name;
        //    Float v = 0;
        //    foreach (Set s in data) {
        //        v += s[name];
        //    }
        //    average[name] = v / cycle;
        //}
        //m["average"] = average;
        //ous.writeJson(m);
        //ous.writeCSV(m);
        ous.flush();
        ous.close();
    }
}

