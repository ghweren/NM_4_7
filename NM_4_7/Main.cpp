#include <iostream>
#include <vector>
#include "HermiteInterpolation.h"

using namespace std;

double function(double x);
double derivativeOfFunction(double x);
void print_table(vector<vector<double>> table);

int main()
{
	double start,step,value;
	size_t n;
	vector<vector<double>> table;
	cout << "Enter the number of points: ";
	cin >> n;
	cout << "\nEnter the start point: ";
	cin >> start;
	cout << "\nEnter the step: ";
	cin >> step;
	cout << "\Enter the value: ";
	cin >> value;
	for (int i = 0; i < n; i++)
	{
		vector<double> temp;
		temp.push_back(start);
		temp.push_back(function(start));
		temp.push_back(derivativeOfFunction(start));
		table.push_back(temp);
		start += step;
	}
	print_table(table);
	cout << "\nThe result of interpolation: "<<(new HermiteInterpolation)->Calculation(table,value);
	cin >> n;
}

double function(double x)
{
	return x*x*x;
}

double derivativeOfFunction(double x)
{
	return x*x * 3;
}

void print_table(vector<vector<double>> table)
{
	cout << endl;
	cout << 'x'<<' ';
	for (int i = 0; i < table.size(); i++)
		cout << table[i][0] << ' ';
	cout << endl;
	cout << 'y' << ' ';
	for (int i = 0; i < table.size(); i++)
		cout << table[i][1] << ' ';
	cout << endl;
	cout << "y\'" << ' ';
	for (int i = 0; i < table.size(); i++)
		cout << table[i][2] << ' ';
}