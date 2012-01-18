void main(String[] args) {

	a = new int[0];
	a.add(5, 9, 2, 4, 1, 2, 5, 4, 3);
	OUT.println(a);

	a.reverse();
	OUT.println(a);

	a.shuffle();
	OUT.println(a);

	//a.insert(1, 0);
	//OUT.println(a);

	a.remove(5);
	OUT.println(a);

	//a.indexOf(1);
	//OUT.println(a);

	a.clear();
	OUT.println(a);
}

