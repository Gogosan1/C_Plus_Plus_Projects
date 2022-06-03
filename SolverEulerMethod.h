#pragma once
#include "TaskKoshi.h"
#include "FarmSolvers.h"

class SolverEulerMethod : public FarmSolvers
{
public:
	Points SolverKoshiTask(const TaskKoshi&, BehaviorOfSolver&);
};
