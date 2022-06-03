#include "SolverEulerMethod.h"
#include <cmath>
#include <iostream>

Points SolverEulerMethod::SolverKoshiTask(const TaskKoshi& Task)
{
	double FunctionValue;
	double StepSize = Task.Geth();
	unsigned int i = 1;

	Point.X.push_back( Task.Gett0() );
	Point.Y.push_back( Task.Gety0() );
	FunctionValue = Task.CountFunctionValue(Point.X[0],Point.Y[0]);

	while (Point.X[i - 1] <= Task.GetT())
	{
		Point.X.push_back( Point.X[i - 1] + StepSize );
		Point.Y.push_back( Point.Y[i - 1] + StepSize * FunctionValue );
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

				Point.X.push_back( Point.X[i] + StepSize );
				Point.Y.push_back( Point.Y[i] + StepSize * FunctionValue );
				break;
			
			case BehaviorOfSolver::FinishAfterLeftBorder: 

				Point.X.push_back( Point.X[i] + StepSize );
				Point.Y.push_back( Point.Y[i] + StepSize * FunctionValue );
				break;

			case BehaviorOfSolver::FinishBeforeLeftBorder:
				break;
			}
			break;
		}
		i++;
	}
	return Point;
}
