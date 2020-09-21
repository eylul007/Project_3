#include"shape.h"
#include"triangle.h"
#include<iostream>
using namespace std;

triangle::triangle(line one, line two, line three,string ID):shape(ID) {
	a = one;
	b = two;
	c = three;
	perimeter = set_perimeter();
}


double triangle::get_perimeter() {
	return perimeter;
}

/*triangle::triangle(const triangle& t){
	a = t.a;
	b = t.b;
	c = t.c;
	perimeter = t.perimeter;
}*/

double triangle::set_perimeter() {
	double lenght_a, lenght_b, lenght_c;
	lenght_a = this->a.get_length();
	lenght_b = this->b.get_length();
	lenght_c = this->c.get_length();
	this->perimeter = lenght_a + lenght_b + lenght_c;
	return this->perimeter;
}

