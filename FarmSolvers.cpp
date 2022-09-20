#include "FarmSolvers.h"

void FarmSolvers::CheckNameRepeat(const std::string& Name) const
{
	unsigned int Counter = -1;
	if (ArraySolvers.empty())
		Counter = -1;

	for (int i = 0; i < ArraySolvers.size(); i++)
		if (ArraySolvers[i].GetName() == Name)
			Counter = 0;

	if (Counter == 0)
		throw std::invalid_argument("Ошибка Такое имя уже существует! Повторите ввод.\n");
}

void FarmSolvers::DetermeningTheExistenceSolvers(const std::string& Name) const
{
	unsigned int Counter = 0;

	for (int i = 0; i < ArraySolvers.size(); i++)
		if (ArraySolvers[i].GetName() == Name)
			Counter++;

	if (Counter == 0)
		throw std::invalid_argument("Решателя по такому имени не существует!\n");
}
void FarmSolvers::IsArraySolversEmpty()const
{
	if (ArraySolvers.empty())
		throw std::out_of_range("Отсутсвуют решатели!\n");
}

void FarmSolvers::AddSolver(FarmSolvers Solvers)
{
	ArraySolvers.push_back(Solvers);
}

void FarmSolvers::SolveProblem(Solver* Solv, TaskKoshi &Task)
{
	Point = Solv->SolverKoshiTask(Task);
}

void FarmSolvers::DeleteSolver(std::string& Name)
{
	for (int i = 0; i < ArraySolvers.size(); i++)
		if (ArraySolvers[i].GetName() == Name)
			ArraySolvers.erase(ArraySolvers.begin() + i);
}

Points FarmSolvers::GetResults(const std::string& Name) const
{
	for (int i = 0; i < ArraySolvers.size(); i++)
		if (ArraySolvers[i].GetName() == Name)
			return ArraySolvers[i].GetPoints();
}
Points FarmSolvers::GetPoints()const
{
	return Point;
}

std::string FarmSolvers::GetName() const
{
	return Name;
}
