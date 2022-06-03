#pragma once
#include <string>
#include <vector>
#include "EnumsAndStructures.h"
#include "TaskKoshi.h"

class FarmSolvers
{
public:	

	void SolveProblem(const TaskKoshi&);
	Points GetResults()const;
	std::string GetName()const;
	BehaviorOfSolver GetBehavior()const;
	
	FarmSolvers(std::string N, KindOfSolver K, BehaviorOfSolver B)
		:Name(N), Kind(K), Behavior(B) {}
	FarmSolvers(){}

protected:
	Points Point;
private:
	BehaviorOfSolver Behavior;
	KindOfSolver Kind;
	std::string Name;
};
