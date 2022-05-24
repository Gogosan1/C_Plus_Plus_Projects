#pragma once
#include "TaskKoshi.h"
#include <string>

class SolverMethodHoina
{
private:
	std::string Name;
	unsigned int Behavior, NumberOfTimeMoments, TimeMomentsNotOnInterval;

	double* X; 
	double* Y; 
	double* FunctionValue;

public:

	SolverMethodHoina();
	SolverMethodHoina(std::string, unsigned int, unsigned int);
	SolverMethodHoina(const SolverMethodHoina& Other);
	SolverMethodHoina(SolverMethodHoina&& Other);
	SolverMethodHoina& operator=(const SolverMethodHoina& Other);
	SolverMethodHoina& operator=(SolverMethodHoina&& Other);
	~SolverMethodHoina();

	std::string GetName()const;
	unsigned int GetBehavior()const;
	void SolverKoshiTask(const TaskKoshi& Second);
	void ShowResults()const;
	void Clean();
};


inline SolverMethodHoina::SolverMethodHoina(const SolverMethodHoina& Other)
	:Name(Other.Name), Behavior(Other.Behavior), NumberOfTimeMoments(Other.NumberOfTimeMoments), TimeMomentsNotOnInterval(Other.TimeMomentsNotOnInterval)
{
	X = new double[NumberOfTimeMoments];
	Y = new double[NumberOfTimeMoments];
	FunctionValue = new double[NumberOfTimeMoments];
}

inline SolverMethodHoina::~SolverMethodHoina()
{
	Name = "Default";
	Behavior = 0;
	TimeMomentsNotOnInterval = 0;
	NumberOfTimeMoments = 0;
	delete[]X;
	delete[]Y;
	delete[]FunctionValue;
}

inline SolverMethodHoina::SolverMethodHoina(SolverMethodHoina&& Other)
	:Name(Other.Name), Behavior(Other.Behavior), NumberOfTimeMoments(Other.NumberOfTimeMoments), TimeMomentsNotOnInterval(Other.TimeMomentsNotOnInterval)
{
	X = new double[NumberOfTimeMoments];
	Y = new double[NumberOfTimeMoments];
	FunctionValue = new double[NumberOfTimeMoments];

	//чистка
	Other.Name = "Default";
	Behavior = 0;
	TimeMomentsNotOnInterval = 0;
	NumberOfTimeMoments = 0;
	Other.X = nullptr;
	Other.Y = nullptr;
	Other.FunctionValue = nullptr;
}

