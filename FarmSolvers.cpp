#include "FarmSolvers.h"
#include <iostream>

void FarmSolvers::CheckNameRepeat(const std::string& Name) const // подумать как можно лучше реализовать без повтора циклов 
{
	for (int i = 0; i < ArraySolversEulerMethod.size(); i++) // Проверка на наличие таких имён уже
		if (ArraySolversEulerMethod[i].GetName() == Name)
			throw Errors();// переделать

	for ( int i = 0; i < ArraySolversMethodHoina.size(); i++)
		if (ArraySolversMethodHoina[i].GetName() == Name)
			throw Errors(); // переделать
}

void FarmSolvers::AddSolverEulerMethod(const std::string& Name, const BehaviorOfSolver& Behavior)
{
	// создать объект этого класса и присвоить ему имя
	SolverEulerMethod Solver(Name, Behavior);
	ArraySolversEulerMethod.push_back(Solver); //срабатывает оператор копирования
}

void FarmSolvers::AddSolverMethodHoina(const std::string& Name, const BehaviorOfSolver& Behavior)
{
	// создать объект этого класса и присвоить ему имя
	SolverMethodHoina Solver(Name, Behavior);
	ArraySolversMethodHoina.push_back(Solver);
}

void FarmSolvers::SolveProblem(const TaskKoshi& Task)
{
	unsigned int i = 0;

	for (i = 0; i < ArraySolversEulerMethod.size(); i++) // цикл на решение задачи Коши, для каждого из решателей методом Эйлера
		ArraySolversEulerMethod[i].SolverKoshiTask(Task);

	for (i = 0; i < ArraySolversMethodHoina.size(); i++) // цикл на решение задачи Коши, для каждого из решателей методом Хойна		
		ArraySolversMethodHoina[i].SolverKoshiTask(Task);

}

Points FarmSolvers::GetResults(const std::string&) const
{
	for (int i = 0; i < ArraySolversEulerMethod.size(); i++)
		if (ArraySolversEulerMethod[i].GetName() == Name)
			return ArraySolversEulerMethod[i].GetPoints();

	for (int i = 0; i < ArraySolversMethodHoina.size(); i++)
		if (ArraySolversMethodHoina[i].GetName() == Name)
			return ArraySolversMethodHoina[i].GetPoints();
}

BehaviorOfSolver FarmSolvers::GetBehavior() const
{
	return Behavior;
}

std::string FarmSolvers::GetName() const
{
	return std::string(Name);
}

Points FarmSolvers::GetPoints() const
{
	return Point;
}