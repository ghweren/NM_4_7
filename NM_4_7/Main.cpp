#include <iostream>
#include <vector>
#include <algorithm>
#include "HermiteInterpolation.h"

using namespace std;

double function(double x);
double derivativeOfFunction(double x);
void print_table(vector<vector<double>> table);
vector<vector<double>> newTable(vector<vector<double>> table,double value,int m);

int main()
{
	double start,step,value;
	size_t n,m;
	vector<vector<double>> table;
	cout << "Enter the number of points: ";
	cin >> n;
	cout << "\nEnter the start point: ";
	cin >> start;
	cout << "\nEnter the step: ";
	cin >> step;
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
	cout << "\nEnter the value: ";
	cin >> value;
	cout << "\nEnter the m: ";
	cin >> m;

	vector<vector<double>> mTable=newTable(table,value,m);
	print_table(mTable);
	cout << "\nThe result of interpolation: "<<(new HermiteInterpolation)->Calculation(mTable,value);
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

bool compare(const pair<int, double> &left, const pair<int, double> &right)
{
	return left.second < right.second;
}

vector<vector<double>> newTable(vector<vector<double>> table, double value,int m)
{
	vector<pair<int, double>> x_pair;
	for (int i = 0; i < table.size(); i++)
		x_pair.push_back(make_pair(i, abs(table[i][0] - value)));
	sort(begin(x_pair), end(x_pair), compare);

	vector<int> indices;
	for (int i = 0; i < table.size(); i++)
		indices.push_back(x_pair[i].first);
	
	vector<vector<double>> result;
	for (int i = 0; i < m; i++)
	{
		vector<double> temp;
		temp.push_back(table[indices[i]][0]);
		temp.push_back(table[indices[i]][1]);
		temp.push_back(table[indices[i]][2]);
		result.push_back(temp);
	}
	return result;
}