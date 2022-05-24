#include "TaskKoshi.h"
#include <cmath>

double TaskKoshi::Gety0() const
{
	return y0;
}

double TaskKoshi::Getx0() const
{
	return x0;
}

double TaskKoshi::Gett0() const
{
	return t0;
}

double TaskKoshi::GetT() const
{
	return T;
}

double TaskKoshi::Geth() const
{
	return h;
}

double TaskKoshi::CountFunctionValue(const double& Xi, const double& Yi)const
{
	const double Pi = 3.14;
	double parametr = Xi + Yi;
	return sin(parametr * Pi / 180);
}
