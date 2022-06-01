#pragma once
#include "TaskKoshi.h"
#include "FarmSolvers.h"

class SolverEulerMethod : public FarmSolvers
{
public:
	//SolverEulerMethod::SolverEulerMethod(FarmSolvers(f)){}
	void SolverKoshiTask(const TaskKoshi&);
};
