#pragma once
#include<string>
using std::string;

class shape {
private:
	string id;
public:
	shape(string);
	virtual double set_perimeter() = 0;
	string get_id();
};
