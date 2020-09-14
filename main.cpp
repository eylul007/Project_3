#include"point.h"
#include"line.h"
#include"shape.h"
#include"triangle.h"
#include<iostream>
using namespace std;
#include<string>
using std::string;
#include<cmath>
#include<fstream>
#include<sstream>

int fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return n * fact(n - 1);
}

int main() {
	int counter = 0;
	string line;

	point** point_arr;
	string x_string, y_string;
	double x, y;
	string l; //string that will be used while loading points
	int i;

	triangle* triangle_array;

	/* Creating input filestream */
	ifstream input_file("input.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
		return 0;
	}

	while (getline(input_file, line)) counter++;  //calculating the size of array of points

	cout << counter;

	point_arr = new point * [counter];

	i = 0;
	while (getline(input_file, l)) {
		stringstream ss(l);
		getline(ss, x_string, ',');
		x = stoi(x_string);
		getline(ss, y_string, ',');
		y = stoi(y_string);

		point_arr[i] = new point(x, y);
	}



	return 0;
}