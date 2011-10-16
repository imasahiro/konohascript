using konoha.sql.*;

c = new Connection("mysql://root:konoha@localhost:3306/test");
r = c.query("SELECT * FROM hoge");

while (r.next()) {
	OUT.println(r.getString("NAME"));
}
r.close();
c.close();

