#pragma once
#include "TaskKoshi.h"
#include <string>

class SolverEulerMethod
{
private:
	std::string Name;
	unsigned int Behavior, NumberOfTimeMoments;

	double* X;
	double* Y; 
	double* FunctionValue;

	unsigned int TimeMomentsNotOnInterval;

public:
	
	SolverEulerMethod();
	SolverEulerMethod(std::string, unsigned int, unsigned int);
	SolverEulerMethod(const SolverEulerMethod& Other);
	SolverEulerMethod(SolverEulerMethod&& Other);
	SolverEulerMethod& operator=(const SolverEulerMethod& Other);
	SolverEulerMethod& operator=(SolverEulerMethod&& Other);
	~SolverEulerMethod();

	std::string GetName()const;
	unsigned int GetBehavior()const;
	void SolverKoshiTask(const TaskKoshi &Second);
	void ShowResults()const;
	void Clean();
};

inline SolverEulerMethod::SolverEulerMethod(const SolverEulerMethod& Other)
	:Name(Other.Name), Behavior(Other.Behavior), NumberOfTimeMoments(Other.NumberOfTimeMoments), TimeMomentsNotOnInterval(Other.TimeMomentsNotOnInterval)
{
	X = new double[NumberOfTimeMoments];
	Y = new double[NumberOfTimeMoments];
	FunctionValue = new double[NumberOfTimeMoments];
}

inline SolverEulerMethod::~SolverEulerMethod()
{
	Name = "Default";
	Behavior = 0;
	TimeMomentsNotOnInterval = 0;
	NumberOfTimeMoments = 0;
	delete[]X;
	delete[]Y;
	delete[]FunctionValue;
}

inline SolverEulerMethod::SolverEulerMethod(SolverEulerMethod&& Other) 
	:Name(Other.Name), Behavior(Other.Behavior), NumberOfTimeMoments(Other.NumberOfTimeMoments), TimeMomentsNotOnInterval(Other.TimeMomentsNotOnInterval)
{
	X = Other.X; 
	Y = Other.Y;
	FunctionValue = Other.FunctionValue; 

	//чистка
	Other.Name = "Default";
	Behavior = 0;
	TimeMomentsNotOnInterval = 0;
	NumberOfTimeMoments = 0;
	Other.X = nullptr;
	Other.Y = nullptr;
	Other.FunctionValue = nullptr;
}

