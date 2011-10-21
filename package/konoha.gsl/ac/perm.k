using konoha.gsl.*;

int p_size = 10;
int gsl_success = 0;
GslPerm p = new GslPerm(p_size);
GslPerm q = new GslPerm(p_size);

assure "GslPerm.get"{
	for (int i = 0; i < p_size; i++){
		assert p.get(i) == i;
	}
}

assure "GslPerm.swap"{
	int i = 3, j = 5;
	p.swap(i, j);
	assert p.get(j) == i;
	assert p.get(i) == j;
	p.swap(i, j);
}


assure "GslPerm.size"{
	assert p.size() == p_size;
}

assure "GslPerm.data"{
	int i,k;
	k = p.size();
	Array<int> a;
	a = p.data();
	for (i = 0; i < k; i++){
	assert a[i] == p[i];
	}
}

assure "GslPerm.valid"{
	assert p.valid() == 0;
}

assure "GslPerm.reverse"{
	int i = 0,j = p_size;
	q.reverse();
	for(i = 0; i < 10; i++){
	j--;
	assert q.get(i) == p.get(j);
	}
	q = q.reverse();
}

assure "GslPerm.inverse"{
	GslPerm a = new GslPerm(4);
	a.swap(0,1);//a = {1023}
	a.swap(0,2);//a = {2013}
	a.swap(2,3);//a = {2031}
	a = a.inverse();//if a = {2031}, inversed a = {1302}
	assert a[0] == 1;
	assert a[1] == 3;
	assert a[2] == 0;
	assert a[3] == 2;
}

assure "GslPerm.next"{
	assert p.next() == gsl_success;
}

assure "GslPerm.prev"{
	assert p.prev() == gsl_success;
}

assure "GslPerm.mul"{
	GslPerm pa = new GslPerm(5);
	GslPerm pb = new GslPerm(5);
	pa.swap(1,4);
	pb.swap(2,3);
	pa = pa.mul(pb);
	assert pa[0] == 0;
	assert pa[1] == 4;
	assert pa[2] == 3;
	assert pa[3] == 2;
	assert pa[4] == 1;
}

assure "GslPerm.linear_to_canonical"{
	GslPerm a = new GslPerm(5);//a = {01234}
	a = a.linear_to_canonical();//if linear form of a = {01234}, cannonical form of a = {43210}
	assert a[0] == 4;
	assert a[1] == 3;
	assert a[2] == 2;
	assert a[3] == 1;
	assert a[4] == 0;
}

assure "GslPerm.canonical_to_linear"{
	GslPerm a = new GslPerm(5);//a = {01234}
	a = a.canonical_to_linear();//if canonical form of a = {01234}, linear form of a = {43210}
	assert a[0] == 1;
	assert a[1] == 2;
	assert a[2] == 3;
	assert a[3] == 4;
	assert a[4] == 0;
}

assure "GslPerm.inversions"{
	GslPerm a = new GslPerm(4);
	a.swap(0,1);//a = {1023}
	a.swap(0,2);//a = {2013}
	a.swap(2,3);//a = {2031}
	assert a.inversions() == 3;//if a = {2031} ,a.inversions = 3
}

assure "GslPerm.linear_cycles"{
	GslPerm a = new GslPerm(5);//a = {01234}
	assert a.linear_cycles() == 5;//if linear form of a = {01234}, the number of cycles of permutation a = 5
}

assure "GslPerm.canonical_cycles"{
	GslPerm a = new GslPerm(5);//a = {01234}
	assert a.canonical_cycles() == 1;//if canonical form of a = {01234}, the number of cycles of permutation a = 1
}
