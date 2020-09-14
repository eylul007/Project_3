#pragma once
class point {
private:
	double x_coor;
	double y_coor;
public:
	point(double, double);
	point();
	double get_x_coor();
	double get_y_coor();
};