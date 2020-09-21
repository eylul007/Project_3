#include"point.h"
#include<iostream>
using namespace std;

point::point(double x, double y) {
	x_coor = x;
	y_coor = y;
}

point::point() {
	x_coor = 0;
	y_coor = 0;
}

point::point(const point& a) {
	x_coor = a.x_coor;
	y_coor = a.y_coor;
}

double point::get_x_coor() {
	return x_coor;
}

double point::get_y_coor() {
	return y_coor;
}