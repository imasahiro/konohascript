using konoha.sql.*;

/* edit your mysql username and password. */
urn = "sample.db";
c = new Connection(urn);
ResultSet r = c.query("select * from person");

while (r.next()) {
	OUT << "DATA: " << r.getString("NAME") << EOL;
}
r.close();
c.close();

