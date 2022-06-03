#pragma once
#include <vector>
#include <iostream>
enum class BehaviorOfSolver { NoneBehavior = 0, FinishAtTheLeftBorder, FinishAfterLeftBorder, FinishBeforeLeftBorder };
enum class KindOfSolver { EulerMethod = 1, MethodHoina };
struct Points
{
	std::vector <double> X;
	std::vector <double> Y;
	friend std::ostream& operator << (std::ostream& S, Points& P)
	{
		for (unsigned int i = 0; i < P.X.size(); i++)
			S << " t = " << P.X[i] << " y(t) = " << P.Y[i] << std::endl;
		return S;
	}

};