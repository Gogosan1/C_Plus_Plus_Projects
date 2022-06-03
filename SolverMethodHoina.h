#pragma once
#include "TaskKoshi.h"
#include "FarmSolvers.h"


class SolverMethodHoina : public FarmSolvers
{
public:
	Points SolverKoshiTask(const TaskKoshi&, BehaviorOfSolver&);
};