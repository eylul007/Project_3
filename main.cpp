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

void combination(triangle** tr_array,point** arr, point** data, int start, int end, int index)
{
	double len_a, len_b, len_c;
	int count = 0;

	if (index == 3)
	{

		if ((data[0]->get_x_coor() == data[1]->get_x_coor() == data[2]->get_x_coor()) && (data[0]->get_y_coor() == data[1]->get_y_coor() == data[2]->get_y_coor())) 
		{
			cout << "?";
			line *a = new line(*data[0], *data[1]);
			line *b = new line(*data[1], *data[2]);
			line *c = new line(*data[0], *data[2]);

			len_a = a->get_length();
			len_b = b->get_length();
			len_c = c->get_length();

			if ((len_a < (len_b + len_c) && len_a > abs((len_b - len_c))) && (len_b < (len_a + len_c) && len_b > abs((len_a - len_c))) && (len_c < (len_a + len_b) && len_c > abs((len_a - len_b)))) 
			{
				tr_array[count] = new triangle(*a, *b, *c);
				count++;
			}
		}
	}

	for (int i = start; i <= end && end - i + 1 >= 3 - index; i++)
	{
		data[index] = arr[i];
		combination(tr_array,arr, data, i + 1, end, index + 1);
	}


}

int main() {
	int counter = 0;
	string line;

	point** point_arr;
	string x_string, y_string;
	double x, y;
	string l; //string that will be used while loading points
	int i;

	triangle** triangle_array;

	int no_of_combinations;

	/* Creating input filestream */
	ifstream input_file("input.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
		return 0;
	}

	while (getline(input_file, line)) counter++;  //calculating the size of array of points

	//cout << counter;

	point_arr = new point * [counter];

	i = 0;

	input_file.clear();
	input_file.seekg(0);
	
	while (getline(input_file, l)) {
		stringstream ss(l);
		getline(ss, x_string, ',');
		x = stod(x_string);
		getline(ss, y_string, ',');
		y = stod(y_string);

		point_arr[i] = new point(x, y);
		i++;
	}

	no_of_combinations = fact(counter) / (fact(3) * fact(counter - 3));

	triangle_array = new triangle*[no_of_combinations];

	point** temp_data = new point * [3];

	combination(triangle_array, point_arr, temp_data, 0, counter - 1, 0);

	//cout << endl << triangle_array[i]->get_perimeter();

	int a, n;
	n = sizeof(triangle_array);

	ofstream outfile("user.txt");

	if (outfile.is_open())
	{
		for (a = 0; a < n; a++) {
			outfile << a+1<<"," <<triangle_array[a]->get_perimeter();
			if (a != n - 1) outfile << "\n";

		}

		outfile.close();
	}
	else cout << "File error.";
	
	return 0;
}