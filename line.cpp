#include"point.h"
#include"line.h"
#include<iostream>
#include<cmath>
using namespace std;

line::line(point one,point two){
	p_one = one;
	p_two = two;
	set_length();
}

double line::get_length() {
	return length;
}

void line::set_length() {
	double x1, x2, y1, y2,sq_of_distance;
	x1 = this->p_one.get_x_coor();
	x2 = this->p_two.get_x_coor();
	y1 = this->p_one.get_y_coor();
	y2 = this->p_two.get_y_coor();

	sq_of_distance = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));

	this->length = sqrt(sq_of_distance);
}