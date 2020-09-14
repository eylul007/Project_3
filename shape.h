#pragma once
#include<string>
using std::string;

class shape {
private:
	string id;
public:
	shape(string);
	shape();
	virtual double set_perimeter() = 0;
	string get_id();
	string to_string();
};
