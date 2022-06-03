#pragma once
#include "TaskKoshi.h"
#include "Solver.h"


class SolverMethodHoina : public Solver
{
public:
	Points SolverKoshiTask(const TaskKoshi&) override;
	SolverMethodHoina(BehaviorOfSolver B)
		:Solver(B) {}
};