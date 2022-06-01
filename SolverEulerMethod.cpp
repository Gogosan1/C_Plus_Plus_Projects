#include "SolverEulerMethod.h"
#include <cmath>
#include <iostream>

void SolverEulerMethod::SolverKoshiTask(const TaskKoshi &Task)
{
	double FunctionValue;
	double StepSize = Task.Geth();
	unsigned int i = 1;

	Point.X[0] = Task.Gett0();
	Point.Y[0] = Task.Gety0();
	FunctionValue = Task.CountFunctionValue(Point.X[0],Point.Y[0]);

	while (Point.X[i] <= Task.GetT())
	{
		Point.X[i] = Point.X[i - 1] + StepSize;
		Point.Y[i] = Point.Y[i - 1] + StepSize * FunctionValue;
		FunctionValue = Task.CountFunctionValue(Point.X[i], Point.Y[i]);
		
		// случаи непопадания на границу отрезка
		if ((Point.X[i] + StepSize) > Task.GetT())
		{
			switch (Behavior) 
			{
			case BehaviorOfSolver::NoneBehavior:
				break;

			case BehaviorOfSolver::FinishAtTheLeftBorder: 

				StepSize = Task.GetT() - (StepSize * i + Point.X[0]);

				Point.X[i + 1] = Point.X[i] + StepSize;
				Point.Y[i + 1] = Point.Y[i] + StepSize * FunctionValue;
				break;
			
			case BehaviorOfSolver::FinishAfterLeftBorder: 

				Point.X[i + 1] = Point.X[i] + StepSize;
				Point.Y[i + 1] = Point.Y[i] + StepSize * FunctionValue;
				break;

			case BehaviorOfSolver::FinishBeforeLeftBorder:
				break;
			}
			break;
		}
		i++;
	}
}

