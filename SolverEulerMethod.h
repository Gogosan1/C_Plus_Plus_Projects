#pragma once
#include "TaskKoshi.h"
#include "Solver.h"
#include <vector>

class SolverEulerMethod : public Solver
{
public:
	Points SolverKoshiTask(const TaskKoshi&) override;
	SolverEulerMethod(BehaviorOfSolver B)
		:Solver(B) {}
};
