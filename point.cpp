#include"point.h"
#include<iostream>
using namespace std;

point::point(double x, double y) {
	x_coor = x;
	y_coor = y;
}

point::point() {

}

double point::get_x_coor() {
	return x_coor;
}

double point::get_y_coor() {
	return y_coor;
}