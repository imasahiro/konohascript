using konoha.sql.*;

/* edit your mysql username and password. */
uname = "root";
pass = "";
urn = "mysql://" + uname + ":" + pass + "@localhost:3306/information_schema";
if (pass == "") {
	OUT << "EDIT YOUR MYSQL ROOT PASS." << EOL;
	exit(0);
}
c = new Connection(urn);
ResultSet r = c.query("SELECT * FROM INFORMATION_SCHEMA.SCHEMATA");

while (r.next()) {
	OUT << "SCHEMATA: " << r.getString("SCHEMA_NAME") << EOL;
}
r.close();
c.close();

