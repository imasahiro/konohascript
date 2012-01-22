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

void run (String output) {
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
        int ret = System.system(f + " " + D + b + " --Benchmark:OUTPUT=" + output + " --Benchmark:SIZE="+C);
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

void main (String[] args) {
    Date date = new Date();
    String output = (to String) date + ".csv";
    run(output);
}

