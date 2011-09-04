/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

@Expando class Person {

}

assure "ExpandoClass" {
	Person p = new Person();
	p.name = "naruto";
	p.age  = 17;
	assert p.name == "naruto";
	assert p.age == 17;
}

