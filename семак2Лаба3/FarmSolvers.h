#pragma once
#include "SolverEulerMethod.h"
#include "SolverMethodHoina.h"
#include <string>

class FarmSolvers
{
private:
	unsigned int CounterOfSolversEulerMethod, CounterOfSolversMethodHoina;

	//не совсем понятно где брать количество элеменов для массива
	SolverEulerMethod* ArraySolversEulerMethod = new SolverEulerMethod[3];// нехорошо с точки зрения занятой памяти
	SolverMethodHoina *ArraySolversMethodHoina = new SolverMethodHoina[3];// создать свой динамический вектор 
	
public:
	FarmSolvers()
		:CounterOfSolversEulerMethod(0), CounterOfSolversMethodHoina(0)
	{}
	
	class Errors{};

	void CheckNameRepeat(const std::string Name)const;
	void AddSolverEulerMethod(const std::string, const unsigned int, const unsigned int);
	void AddSolverMethodHoina(const std::string Name, const unsigned int, const unsigned int);
	void DeleteMethod(std::string &Name);
	void SolveProblem(const TaskKoshi& Task)const;
	void ShowResults(const std::string Name)const;
	unsigned int GetSumOfCountersMethods(); //?

	~FarmSolvers() 
	{
		delete[]ArraySolversEulerMethod;
		delete[]ArraySolversMethodHoina;
	}
};
