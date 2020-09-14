#pragma once
#include"shape.h"
#include"line.h"
class triangle: public shape {
private:
	line a;
	line b;
	line c;
	double perimeter;
public:
	double get_perimeter();
	triangle(line,line,line);
	double set_perimeter(); //overrides superclass
};