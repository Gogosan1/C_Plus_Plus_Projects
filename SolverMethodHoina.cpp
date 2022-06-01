#include "SolverMethodHoina.h"
#include <iostream>

void SolverMethodHoina::SolverKoshiTask(const TaskKoshi& Task)
{
	double StepSize = Task.Geth();
	double YIntermedied, FunctionIntermediedValue, FunctionValue;
	unsigned int i = 1; 

	Point.X[0] = Task.Gett0(); // Задание первоначальных значений
	Point.Y[0] = Task.Gety0();
	FunctionValue = Task.CountFunctionValue(Point.X[0], Point.Y[0]);


	while (Point.X[i] <= Task.GetT())
	{
		Point.X[i] = Point.X[i - 1] + StepSize;
		YIntermedied = Point.Y[i - 1] + StepSize * FunctionValue;
		FunctionIntermediedValue = Task.CountFunctionValue(Point.X[i], YIntermedied);
		Point.Y[i] = Point.Y[i - 1] + StepSize / 2 * (FunctionValue + FunctionIntermediedValue);
		FunctionValue = Task.CountFunctionValue(Point.X[i], Point.Y[i]);


		// Особый случай не поподания на конец интервала
		if ((Point.X[i] + StepSize) > Task.GetT())
		{
			switch (Behavior)//// // случаи непопадания на границу отрезка
			{
			case BehaviorOfSolver::NoneBehavior:
				break;

			case BehaviorOfSolver::FinishAtTheLeftBorder: 

				StepSize = Task.GetT() - (StepSize * i + Point.X[0]);
				
				Point.X[i + 1] = Point.X[i] + StepSize;
				YIntermedied = Point.Y[i] + StepSize * FunctionValue;
				FunctionIntermediedValue = Task.CountFunctionValue(Point.X[i + 1], YIntermedied);
				Point.Y[i + 1] = Point.Y[i] + StepSize / 2 * (FunctionValue + FunctionIntermediedValue);
				
				break;
			case BehaviorOfSolver::FinishAfterLeftBorder: 

		
				Point.X[i + 1] = Point.X[i] + StepSize;
				YIntermedied = Point.Y[i] + StepSize * FunctionValue;
				FunctionIntermediedValue = Task.CountFunctionValue(Point.X[i + 1], YIntermedied);
				Point.Y[i + 1] = Point.Y[i] + StepSize / 2 * (FunctionValue + FunctionIntermediedValue);
	
				break;
			case BehaviorOfSolver::FinishBeforeLeftBorder: 
				break;
			}
			break; 
		}
		i++;
	}
}
