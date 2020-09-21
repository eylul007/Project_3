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

bool test_triangle(point one, point two, point three) {
	if ((one.get_x_coor() == two.get_x_coor() == three.get_x_coor()) || (one.get_y_coor() == two.get_y_coor() == three.get_y_coor()))
	{
		return false;
	}

	else {
		double len_a, len_b, len_c;

		line* a = new line(one, two);
		line* b = new line(one, three);
		line* c = new line(two, three);

		len_a = a->get_length();
		len_b = b->get_length();
		len_c = c->get_length();

		if ((len_a < (len_b + len_c) && len_a > abs((len_b - len_c))) && (len_b < (len_a + len_c) && len_b > abs((len_a - len_c))) && (len_c < (len_a + len_b) && len_c > abs((len_a - len_b))))
		{
			return true;
		}
		else
			return false;
	}
}

int combination(triangle** tr_array, point** point_arr, int no_points)
{
	point temp_arr[3];
	int count = 0;

	string id_string;
	int id;

	for (int i = 0; i <= no_points - 3; i++) {
		temp_arr[0] = *point_arr[i];

		for (int j = i + 1; j <= no_points - 2; j++) {
			temp_arr[1] = *point_arr[j];

			for (int k = j + 1; k <= no_points - 1; k++) {
				temp_arr[2] = *point_arr[k];

				if (test_triangle(temp_arr[0], temp_arr[1], temp_arr[2])) {

					line a(temp_arr[0], temp_arr[1]);
					line b(temp_arr[1], temp_arr[2]);
					line c(temp_arr[0], temp_arr[2]);

					id = count + 1;
					id_string = to_string(id);
					tr_array[count] = new triangle(a, b, c,id_string);
					cout<<endl<<tr_array[count]->get_perimeter(); //trying
					count++;
				}
			}
		}
	}

	return count;
}
int main() {

	string line;
	point** point_arr;
	triangle** triangle_array;

	string x_string, y_string;
	double x, y;
	string l; //string that will be used while loading points
	int i;

	int no_of_combinations;

	cout << "Creating input filestream" << endl;
	/* Creating input filestream */
	ifstream input_file("input.txt");
	if (!input_file.is_open()) {
		cout << "File error.";
		return 0;
	}

	cout << "calculating the size of array of points" << endl;
	int counter = 0;
	while (getline(input_file, line)) counter++;  //calculating the size of array of points
	point_arr = new point * [counter];
	cout << "counter:" << counter << endl;

	i = 0;

	input_file.clear();
	input_file.seekg(0);


	cout << "reading points" << endl;
	while (getline(input_file, l)) {
		stringstream ss(l);
		getline(ss, x_string, ',');
		x = stod(x_string);
		getline(ss, y_string, ',');
		y = stod(y_string);

		point_arr[i] = new point(x, y);
		i++;
	}

	//coalculating the number of combinations
	no_of_combinations = fact(counter) / (fact(3) * fact(counter - 3));
	cout << "number combin:" << no_of_combinations << endl;

	triangle_array = new triangle * [no_of_combinations];

	int no_triangles = combination(triangle_array, point_arr, counter);


	ofstream outfile("output.txt");
	if (outfile.is_open())
	{

		for (int a = 0; a < no_triangles; a++) {
			outfile << triangle_array[a]->get_id() << "," << triangle_array[a]->get_perimeter() << endl;
			if (a != no_of_combinations - 1) outfile << "\n";
		}

		outfile.close();
	}
	else cout << "File error.";

	return 0;
}