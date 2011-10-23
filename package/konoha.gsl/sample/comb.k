using konoha.gsl.*;

int i;
     
print "All subsets of {0,1,2,3} by size:";
for (i = 0; i <= 4; i++)
{
	GslComb c = new GslComb(4, i);
	print "combination(4, " + (String)i + ")";
	do {
		print c.data;
	} while ((c = c.next()) != NULL);
}
