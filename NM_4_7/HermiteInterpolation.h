#include <vector>
#include "GaussMethod.h"
class HermiteInterpolation
{
public:
	double Calculation(std::vector<std::vector<double>> table,double value);
private:
	double generateX(double x,int degree);
	double generateDerivativeOfX(double x,int degree);
	double resultGeneration(std::vector<double> a, double value);
};