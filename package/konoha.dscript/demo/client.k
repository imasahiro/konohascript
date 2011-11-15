using konoha.actor.*;

Actor a = actor:localhost:8080;
t = new DTask("HitNKT", """
using konoha.posix.*;
System.sleep(3);
print 'hi';""");
print t.bind(a, "Role1");
trace = t.go("TestTrans");
print trace.checkTaskLog();
//dc = new DControl("hoge");
//dc.add(t);
//dc.add(t2);
//dc.go("id");
//


