using konoha.sql.*;

c = new Connection("sqlite3:sample.db");
c.exec ## create table data(str, i, f)
c.exec ## insert into data
       ## values ('foo', 1, 1.0)
c.exec ## insert into data
       ## values ('bar', -1, 2.23)

ResultSet r = c.query ## select * from data
while(r.next()) {
	OUT << "-------" << EOL;
	for (int i = 0; i < r.size; i++) {
		OUT << r.getName(i)+ ": " << r[i] << EOL;
	}
}
