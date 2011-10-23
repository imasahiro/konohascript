using konoha.gsl.*;

assure "GslMulti.new" {
	GslMulti m = new GslMulti(4, 2); 
	assert m != null;
} 

assure "GslMulti.InitFirst" {
	GslMulti m = new GslMulti(4, 4);
	m.initFirst();
	assert m.getData() == [0, 0, 0, 0];
}

assure "GslMulti.InitLast" {
	GslMulti m = new GslMulti(4, 4);
	m.initLast();
	assert m.getData() == [3, 3, 3, 3];
}

assure "GslMulti.Copy" {
	GslMulti m1 = new GslMulti(4, 4);
	m1.initFirst();
	assert m1.getData() == [0, 0, 0, 0];
	GslMulti m2 = m1.copy();
	assert m2.getData() == [0, 0, 0, 0];
}

assure "GslMulti.get" {
	GslMulti m = new GslMulti(4, 4); 
	m.initFirst();
	m = m.next();
	assert m.get(0) == 0;
	assert m.get(1) == 0;
	assert m.get(2) == 0;
	assert m.get(3) == 1;
}

assure "GslMulti.Next" {
	GslMulti m = new GslMulti(4, 4); 
	m.initFirst();
	assert m.getData() == [0, 0, 0, 0];
	m = m.next();
	assert m.getData() == [0, 0, 0, 1];

	m.initLast();
	assert m.next() == null;
}

assure "GslMulti.Prev" {
	GslMulti m = new GslMulti(4, 4);
	m.initLast();
	assert m.getData() == [3, 3, 3, 3];
	m = m.prev();
	assert m.getData() == [2, 3, 3, 3];

	m.initFirst();
	assert m.prev() == null;
} 

assure "GslMulti.Range" {
	GslMulti m = new GslMulti(4, 2); 
	assert m.range() == 4;
} 

assure "GslMulti.Size" {
	GslMulti m = new GslMulti(4, 2);
	assert m.size() == 2;
} 

assure "GslMulti.GetData" {
	GslMulti m = new GslMulti(4, 2);
	m.initFirst();
	assert typeof(m.getData()) == Array<Int>;
	assert |m.getData()| == m.size();
	assert m.getData() == [0, 0];
} 

assure "GslMulti.Valid" {
	GslMulti m = new GslMulti(4, 2);
	m.initFirst();
	assert m.valid() == true;
}
