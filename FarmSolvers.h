#pragma once
#include "SolverEulerMethod.h"
#include "SolverMethodHoina.h"
#include <string>
#include <vector>
#include "EnumsAndStructures.h"

class FarmSolvers
{
public:
	FarmSolvers()
	{}
	
	class Errors{};

	void CheckNameRepeat(const std::string&)const;
	void AddSolverEulerMethod(const std::string&, const BehaviorOfSolver&);
	void AddSolverMethodHoina(const std::string&, const BehaviorOfSolver&);
	void DeleteMethod(std::string&);
	void SolveProblem(const TaskKoshi&);
	Points GetResults(const std::string&)const;


	std::string GetName()const;
	BehaviorOfSolver GetBehavior()const;
	Points GetPoints()const;

protected:
	std::string Name;
	BehaviorOfSolver Behavior;
	Points Point;


private:
	std::vector <SolverEulerMethod> ArraySolversEulerMethod;
	std::vector <SolverMethodHoina> ArraySolversMethodHoina;

};
