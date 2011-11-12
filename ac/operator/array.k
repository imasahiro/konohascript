/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 *  written by Masahiro Ide
 ***************************************************************************/

assure "ArrayOperation" {
	a = [];
	a.add(2);
	assert a[0] == 2;
	assert |a| == 1;
	a.insert(0, 0);
	a.insert(1, 1);
	assert a[0] == 0;
	assert a[1] == 1;
	assert |a| == 3;
	a.remove(1);
	assert a[1] == 2;
	assert |a| == 2;
	a.remove(1);  // tail remove
	a.pop();
	assert |a| == 0;
}

assure "ArrayOperation: int[]" {
	int[] a = [];
	a.add(2);
	assert a[0] == 2;
	assert |a| == 1;
	a.insert(0, 0);
	a.insert(1, 1);
	assert a[0] == 0;
	assert a[1] == 1;
	assert |a| == 3;
	a.remove(1);
	assert a[1] == 2;
	assert |a| == 2;
	a.remove(1);  // tail remove
	a.pop();
	assert |a| == 0;
}

assure "ArrayOperation: Array<T>.pop" {
	String[] a = ["hello"];
	String elem = a.pop();
	assert a.size == 0 && elem == "hello";

	String elem2 = a.pop();
	assert a.size == 0 && elem2 == null;
}

assure "ArrayOperation: Array<Int>.pop" {
	Int[] a = [3];
	Int elem = a.pop();
	assert a.size == 0 && elem == 3;

	Int elem2 = a.pop();
	assert a.size == 0 && elem2 == 0;
}
