using konoha.actor.*;

Actor a = actor:localhost:8080;
t = new DTask("HitNKT", "print 'hi';");
t.bind(a, "Role1");
t.go("TestTransaction");
//dc = new DControl("hoge");
//dc.add(t);
//dc.add(t2);
//dc.go("id");
//


