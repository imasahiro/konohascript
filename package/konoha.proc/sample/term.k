using konoha.proc.*;
using konoha.posix.*;

p = new Proc(["/usr/bin/python"]);
p.terminate();
print "hi";
print "sleep(10)";
sleep(10);
