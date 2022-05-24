#include "FarmSolvers.h"
#include <iostream>

void FarmSolvers::CheckNameRepeat(const std::string Name) const
{
	for (int i = 0; i < 3; i++) // Проверка на наличие таких имён уже
	{
		if (ArraySolversEulerMethod[i].GetName() == Name)
			throw Errors();
		if (ArraySolversMethodHoina[i].GetName() == Name)
			throw Errors();
	}
}

void FarmSolvers::AddSolverEulerMethod(const std::string Name, const unsigned int Behavior,const unsigned int NumberOfTimeMoments)
{ 
	// создать объект этого класса и присвоить ему имя
	SolverEulerMethod Solver(Name, Behavior, NumberOfTimeMoments);
	ArraySolversEulerMethod[CounterOfSolversEulerMethod] = Solver; //срабатывает оператор копирования

	CounterOfSolversEulerMethod++;
}

void FarmSolvers::AddSolverMethodHoina(const std::string Name,const unsigned int Behavior, const unsigned int NumberOfTimeMoments)
{
	// создать объект этого класса и присвоить ему имя
	SolverMethodHoina Solver(Name, Behavior, NumberOfTimeMoments);
	ArraySolversMethodHoina[CounterOfSolversMethodHoina] = Solver; 

	CounterOfSolversMethodHoina++;

}

void FarmSolvers::DeleteMethod(std::string& Name) // на самом деле не совсем удаление, скорее просто обнуление
{
	bool CheckNameExist = false;
	for (int i = 0; i < 3; i++)
	{
		if (ArraySolversEulerMethod[i].GetName() == Name) // обнуление результатов для решателя методом Эйлера
		{
			CheckNameExist = true;
			ArraySolversEulerMethod[i].Clean();
		}

		if (ArraySolversMethodHoina[i].GetName() == Name) // обнуление результатов для решателя методом Хойна
		{
			CheckNameExist = true;
			ArraySolversMethodHoina[i].Clean();
		}
	}
		if (CheckNameExist == false)
			throw Errors();
		//throw кидать исключение если имя не найдено
}

void FarmSolvers::SolveProblem(const TaskKoshi& Task)const
{
	unsigned int i = 0;

	for (i = 0; i < CounterOfSolversEulerMethod; i++) // цикл на решение задачи Коши, для каждого из решателей методом Эйлера
		ArraySolversEulerMethod[i].SolverKoshiTask(Task);

	for (i = 0; i < CounterOfSolversMethodHoina; i++) // цикл на решение задачи Коши, для каждого из решателей методом Хойна		
		ArraySolversMethodHoina[i].SolverKoshiTask(Task);

}

void FarmSolvers::ShowResults(const std::string Name) const
{
	bool CheckNameExist = false;
	for (int i = 0; i < 3; i++)
	{
		if (ArraySolversEulerMethod[i].GetName() == Name) // вывод результатов для решателя методом Эйлера
		{
			CheckNameExist = true;
			ArraySolversEulerMethod[i].ShowResults();
			//break;
		}

		if (ArraySolversMethodHoina[i].GetName() == Name) // вывод результатов для решателя методом Хойна
		{
			CheckNameExist = true;
			ArraySolversMethodHoina[i].ShowResults();
			//break;
		}
	}

		if (CheckNameExist == false)
			throw Errors();
		// кидать исключение если имя не найдено
	
}

unsigned int FarmSolvers::GetSumOfCountersMethods()
{
	return CounterOfSolversEulerMethod + CounterOfSolversMethodHoina;
}