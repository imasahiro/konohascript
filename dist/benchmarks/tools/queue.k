using konoha.posix.*;
include "config.k";
String[] readDir(String dname) {
    Dir d = System.openDir(dname);
    String[] res = [];
    while (true) {
        name = d.readName();
        if (name == null) {
            break;
        }
        if (name.startsWith("_")) {
            continue;
        }
        if (!name.endsWith(".k")) {
            continue;
        }
        res.add(name);
    }
    res.sort();
    return res;
}

void run (String output, String bin) {
    String[] benchmarks = readDir(D);
    OutputStream ous = new OutputStream(output);
    if (CSV) {
        ous.println("Date,Benchmark,average,");
    } else {
        ous.print("{");
    }
    ous.flush();
    ous.close();
    foreach (String b in benchmarks) {
        ous = new OutputStream(output, "a");
        print b;
        if (CSV) {
        } else {
            ous.print("{\"" + b + "\":");
        }
        ous.flush();
        ous.close();
        int ret = System.system(bin + " " + D + b + " --Benchmark:OUTPUT=" + output + " --Benchmark:SIZE="+C);
        print ret;
        ous = new OutputStream(output, "a");
        if (ret != 0) {
            if (CSV) {
                ous.println(new Date() + "," + b + ", ERROR");
            } else {
            }
        }
        if (CSV) {
        } else {
            ous.println("}, ");
        }
        ous.flush();
        ous.close();
    }
    ous = new OutputStream(output, "a");
    if (CSV) {
    } else {
        ous.println("{\"\" : null}}");
    }
    ous.flush();
    ous.close();
}
String[] load(Path urn) {
    InputStream ins = new InputStream(urn, "r");
    String[] res = [];
    foreach (String l in ins) {
        res.add(l);
    }
    ins.close();
    return res;
}
void store(Path urn, String[] data) {
    OuputStream ous = new OutputStream(urn, "w");
    foreach (String l in data) {
        ous.println(l);
    }
    ous.flush();
    ous.close();
}

void main (String[] args) {
    while (true) {
        print "loop";
        String[] data = load("KONOHA_BENCH_QUEUE");
        if (data.size > 0) {
            String line = data[0];
            data.remove(0);
            store("KONOHA_BENCH_QUEUE", data);
            store("KONOHA_BENCH_CURRENT", [line]);
            a = line.split(",");
            print a;
            date = a[0];
            branch = a[2];
            System.system("cd konohascript;git checkout " + branch);
            System.system("mkdir -p konohascript/Release;");
            System.system("cd konohascript/Release && cmake ../ -DCMAKE_INSTALL_PREFIX=/tmp/");
            System.system("cd konohascript/Release && make && make install");
            String output = date + ".csv";
            run(output, "/tmp/bin/konoha");
            store("KONOHA_BENCH_CURRENT", []);
        }
        sleep(10);
    }
}

