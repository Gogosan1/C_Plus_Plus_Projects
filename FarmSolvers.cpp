#include "FarmSolvers.h"
#include "SolverEulerMethod.h"
#include "SolverMethodHoina.h"
#include <iostream>

//void FarmSolvers::AddSolverEulerMethod(const std::string& Name, const BehaviorOfSolver& Behavior)
//{
//	// создать объект этого класса и присвоить ему имя
//	ArraySolvers Solver(Name, Behavior);
//	ArraySolvers.push_back(Solver);
//}
//
//void FarmSolvers::AddSolverMethodHoina(const std::string& Name, const BehaviorOfSolver& Behavior)
//{
//	// создать объект этого класса и присвоить ему имя
//	ArraySolvers Solver(Name, Behavior);
//	ArraySolvers.push_back(Solver);
//}

void FarmSolvers::SolveProblem(const TaskKoshi& Task)
{
	SolverEulerMethod FirstSolver;
	SolverMethodHoina SecondSolver;

	switch (Kind)
	{
	case KindOfSolver::EulerMethod:
		Point = FirstSolver.SolverKoshiTask(Task, Behavior);
		break;

	case KindOfSolver::MethodHoina:
		Point = SecondSolver.SolverKoshiTask(Task, Behavior);  // перегрузить оператор на перемещение
		break;
	}
}

Points FarmSolvers::GetResults() const
{
	return Point;
}

std::string FarmSolvers::GetName() const
{
	return std::string(Name);
}

BehaviorOfSolver FarmSolvers::GetBehavior() const
{
	return Behavior;
}
