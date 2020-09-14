#pragma once
#include"point.h"
class line {
private:
	point p_one;
	point p_two;
	double length;
public:
	line(point, point);
	double get_length();
	void set_length();
};
