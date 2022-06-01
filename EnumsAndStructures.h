#pragma once
#include <vector>
#include <iostream>
enum class BehaviorOfSolver : unsigned int { NoneBehavior = 0, FinishAtTheLeftBorder, FinishAfterLeftBorder, FinishBeforeLeftBorder };
struct Points
{
	std::vector <double> X;
	std::vector <double> Y;
	friend std::ostream& operator << (std::ostream& S, Points& P)
	{
		for (unsigned int i = 0; i < P.X.size(); i++)
			std::cout << " t = " << P.X[i] << " y(t) = " << P.Y[i] << std::endl;
	}
};