#include "SolverEulerMethod.h"
#include <cmath>
#include <iostream>

SolverEulerMethod::SolverEulerMethod()
	:Name("None"), Behavior(0), NumberOfTimeMoments(0), TimeMomentsNotOnInterval(0)
{
	X = new double[0];
	Y = new double[0];
	FunctionValue = new double[0];
}

SolverEulerMethod::SolverEulerMethod(std::string N, unsigned int B, unsigned int TM)
	: Name(N), Behavior(B), NumberOfTimeMoments(TM + 1), TimeMomentsNotOnInterval(0)
{
	X = new double[NumberOfTimeMoments];
	Y = new double[NumberOfTimeMoments];
	FunctionValue = new double[NumberOfTimeMoments];
}

SolverEulerMethod& SolverEulerMethod::operator=(const SolverEulerMethod& Other)
{
	// Учёт самоприсваивания a = a;
	if (this == &Other)
		return *this;

	// Убираемся в левом операнде
	delete[] X;
	delete[] Y;
	delete[] FunctionValue;

	// Осуществляем глубокое копирование
	Name = Other.Name;
	Behavior = Other.Behavior;
	NumberOfTimeMoments = Other.NumberOfTimeMoments;
	X = new double[NumberOfTimeMoments];
	Y = new double[NumberOfTimeMoments];
	FunctionValue = new double[NumberOfTimeMoments];

	// Возвращаем ссылку на левый операнд
	return *this;
}

SolverEulerMethod& SolverEulerMethod::operator=(SolverEulerMethod&& Other)
{
	// Учёт самоприсваивания a = a;
	if (this == &Other)
		return *this;

	// Убираемся в левом операнде
	delete[] X;
	delete[] Y;
	delete[] FunctionValue;

	// Осуществляем поверхностное копирование
	Name = Other.Name;
	Behavior = Other.Behavior;
	NumberOfTimeMoments = Other.NumberOfTimeMoments;
	X = Other.X;
	Y = Other.Y;
	FunctionValue = Other.FunctionValue;

	// Переводим правый объект в опустошённое состояние
	Other.Name = "Default";
	Behavior = 0;
	TimeMomentsNotOnInterval = 0;
	NumberOfTimeMoments = 0;
	Other.X = nullptr;
	Other.Y = nullptr;
	Other.FunctionValue = nullptr;
	
	return *this;
}

std::string SolverEulerMethod::GetName() const
{
	return std::string(Name);
}

unsigned int SolverEulerMethod::GetBehavior()const
{
	return Behavior;
}

void SolverEulerMethod::SolverKoshiTask(const TaskKoshi &Task)
{
	
	double StepSize = Task.Geth();
	unsigned int i = 1;

	X[0] = Task.Getx0(); // Задание первоначальных значений
	Y[0] = Task.Gety0();
	FunctionValue[0] = Task.CountFunctionValue(X[0],Y[0]);
	
	if (X[0] < Task.Gett0())
		TimeMomentsNotOnInterval = 1;

	while (X[i] <= Task.GetT())
	{
		X[i] = X[i - 1] + StepSize;
		Y[i] = Y[i - 1] + StepSize * FunctionValue[i - 1];
		FunctionValue[i] = Task.CountFunctionValue(X[i], Y[i]);
		
		//Подсчёт переменной, которая помогает выводить только те значения, которые входят в интервал
		if (X[i] < Task.Gett0())
			TimeMomentsNotOnInterval++;

		// Особый случай не поподания на конец интервала
		if ((X[i] + StepSize) > Task.GetT())
		{
			switch (Behavior)//// // случаи непопадания на границу отрезка
			{
			// случай заканчивания в точке T
			case 1: 

				if (i == 1) i = 0; 
				// Используется для тривиального случая, когда единственное значение на интервале является его концом

				StepSize = Task.GetT() - (StepSize * i + X[0]);//изменение величины шага для поподания на конец отрезка

				X[i + 1] = X[i] + StepSize;
				Y[i + 1] = Y[i] + StepSize * FunctionValue[i];
				FunctionValue[i + 1] = Task.CountFunctionValue(X[i + 1], Y[i + 1]);
				break;
			
			// случай не изменения величины шага q > T
			case 2: 

				X[i + 1] = X[i] + StepSize;
				Y[i + 1] = Y[i] + StepSize * FunctionValue[i];
				FunctionValue[i + 1] = Task.CountFunctionValue(X[i + 1], Y[i + 1]);
				break;

			// случай заканчивания в ближайшей к концу интервала точке q < T
			case 3: 
				NumberOfTimeMoments--;
				break;
			default: 
				NumberOfTimeMoments--;
				break;
			}
			break; // выход из цикла нужен для 3 случая
		}
		i++;
	}
}

void SolverEulerMethod::ShowResults()const // обычный вывод
{
	unsigned int i = TimeMomentsNotOnInterval;

	for (i; i < NumberOfTimeMoments; i++)
	{
		std::cout << "Временные моменты: x(t) = " << X[i] << " y(t) = " << Y[i];
		std::cout << " f[x(t), y(t)] = " << FunctionValue[i] << "\n";
	}
}

void SolverEulerMethod::Clean() // Согласен с тем, что не совсем похоже на удаление
{
	// по идее надо как-то по другому делать через вызов деструктора
	Name = "Default";
	Behavior = 0;
	TimeMomentsNotOnInterval = 0;
	NumberOfTimeMoments = 0;
}
