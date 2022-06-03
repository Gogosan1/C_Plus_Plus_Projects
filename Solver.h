#pragma once
#include <string>
#include <vector>
#include "EnumsAndStructures.h"
#include "TaskKoshi.h"

class Solver
{
public:
	 virtual Points SolverKoshiTask(const TaskKoshi&) = 0;

	Solver( BehaviorOfSolver B)
		:Behavior(B) {}

protected:
	Points Point;
	BehaviorOfSolver Behavior;
};

