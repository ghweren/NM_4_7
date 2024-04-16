#include "HermiteInterpolation.h"

double HermiteInterpolation::Calculation(std::vector<std::vector<double>> table, double value)
{
	std::vector<std::vector<double>> SLAE_left;
	std::vector<double> SLAE_right;
	for (int i = 0; i < table.size(); i++)
	{
		SLAE_right.push_back(table[i][1]);
		vector<double> row;
		for (int j = 0; j < table.size() * 2; j++)
			row.push_back(generateX(table[i][0],j));
		SLAE_left.push_back(row);
	}
	for (int i = 0; i < table.size(); i++)
	{
		SLAE_right.push_back(table[i][2]);
		vector<double> row;
		for (int j = 0; j < table.size()*2; j++)
			row.push_back(generateDerivativeOfX(table[i][0], j));
		SLAE_left.push_back(row);
	}

	std::vector<double> a = (new GaussMethod)->Calculation(SLAE_left, SLAE_right);

	return resultGeneration(a, value);
}

double HermiteInterpolation::generateX(double x, int degree)
{
	double result = 1;
	for (int i = 0; i < degree; i++)
		result *= x;
	return result;
}

double HermiteInterpolation::generateDerivativeOfX(double x, int degree)
{
	double result = 1;
	for (int i = 1; i < degree; i++)
		result *= x;
	return result*degree;
}

double HermiteInterpolation::resultGeneration(std::vector<double> a, double value)
{
	double result = 0;
	for (int i = 0; i < a.size(); i++)
		result += (a[i] * generateX(value, i));
	return result;
}