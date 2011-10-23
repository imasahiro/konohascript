using konoha.gsl.*;

int n = 4;
int k = 3;

assure "GslComb.new" {
	GslComb c1 = new GslComb(n, k);
	assert c1 != NULL;
	GslComb c2 = new GslComb(-1, -1);
	assert c2 == NULL;
	GslComb c3 = new GslComb(4, 5);
	assert c2 == NULL;
}

assure "GslComb.getN" {
	GslComb c = new GslComb(n, k);
	assert c.n == n;
}

assure "GslComb.getK" {
	GslComb c = new GslComb(n, k);
	assert c.k == k;
}

assure "GslComb.getData" {
	GslComb c = new GslComb(n, k);
	assert c.data == [0, 1, 2];
}

assure "GslComb.next" {
	GslComb c = new GslComb(n, k);
	c.initFirst();
	assert c.data == [0, 1, 2];
	c = c.next();
	assert c.data == [0, 1, 3];
	c = c.next();
	assert c.data == [0, 2, 3];
	c = c.next();
	assert c.data == [1, 2, 3];
	c = c.next();
	assert c == NULL;
}

assure "GslComb.prev" {
	GslComb c = new GslComb(n, k);
	c.initLast();
	assert c.data == [1, 2, 3];
	c = c.prev();
	assert c.data == [0, 2, 3];
	c = c.prev();
	assert c.data == [0, 1, 3];
	c = c.prev();
	assert c.data == [0, 1, 2];
	c = c.prev();
	assert c == NULL;
}

assure "GslComb.init" {
	GslComb c = new GslComb(n, k);
	c = c.next();
	c = c.next();
	c.initFirst();
	assert c.data == [0, 1, 2];
	c.initLast();
	c = c.prev();
	c = c.prev();
	c.initLast();
	assert c.data == [1, 2, 3];
}

assure "GslComb.memcpy" {
	GslComb c = new GslComb(n, k);
	GslComb c2 = c.memcpy();
	c2.initFirst();
	assert c2.data == [0, 1, 2];
	c2 = c2.next();
	assert c2.data == [0, 1, 3];
	c2 = c2.next();
	assert c2.data == [0, 2, 3];
	c2 = c2.next();
	assert c2.data == [1, 2, 3];
}

assure "GslComb.get" {
	GslComb c = new GslComb(n, k);
	assert c.get(0) == 0;
	assert c.get(1) == 1;
	assert c.get(2) == 2;
}

assure "GslComb.valid" {
	GslComb c = new GslComb(-1, -1);
	c.valid();
}
