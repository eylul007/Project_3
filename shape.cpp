#include"shape.h"
#include<iostream>
using namespace std;

shape::shape(string a) {
	id = a;
}

shape::shape() {

}

string shape::get_id() {
	return id;
}

string shape::to_string() {
	string temp;
	char ch = '+';
	temp = this->id;
	temp.insert(temp.length(), 0, ch);
	temp.push_back(ch);  //to make string +id+
	return temp; //??   returns "+id+" ??
}