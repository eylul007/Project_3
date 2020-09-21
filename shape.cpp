#include"shape.h"
#include<iostream>
using namespace std;

shape::shape(string a) {
	id = a;
}


string shape::get_id() {
	return id;
}

