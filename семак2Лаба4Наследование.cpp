#include <iostream>
#include <vector>
#include "SolverEulerMethod.h"
#include "SolverMethodHoina.h"
#include "TaskKoshi.h"
#include "FarmSolvers.h"
#include "EnumsAndStructures.h"

double GetCorrectEnteredNumber();
std::string GetCorrectStringInput();
BehaviorOfSolver DefineBehavior(const double, const double, const double, std::string&);
//enum class SelectedSolver
//{
//	 SolverEulerMethod = 1,
//	 SolverMethodHoina
//
//};

int main() 
{
	
	setlocale(LC_ALL, "");
	
	double  y, t0, T, h;
	// Задание входных данных для задачи Коши.
	//std::cout << "Обратите внимание, если вы хотите ввести нецелое число, вводите его через запятую!\n";

	std::cout << "Задайте входные данные для задачи Коши. Правую часть:\n";
	y = GetCorrectEnteredNumber();

	std::cout << "Левую границу интервала: ";
	t0 = GetCorrectEnteredNumber();
	
	while (true)
	{
		std::cout << "Правую границу интервала:\n";
		T = GetCorrectEnteredNumber();
		
		if (t0 > T)
			std::cout << "Значение левой границы больше правой! Повторите ввод.\n";
		else
			break;
	}

	while (true)
	{
		std::cout << "Величину шага интегрирования: \n";
		h = GetCorrectEnteredNumber();
		if (h <= 0)
			std::cout << "Ошибка, шаг не может быть отрицателен или равен нулю! Попробуйте еще!\n";
		else
			break;
	}
	
	TaskKoshi Task(y, t0, T, h);
	

	// добавление решателей
	FarmSolvers Solver;
	std::string Name, YesOrNoInput;
	BehaviorOfSolver Behavior = static_cast<BehaviorOfSolver>(0);
	Points Point;
	//unsigned int CounterEulerMethod = 0, CounterMethodHoina = 0;
	// создание решателя
	while (true)
	{
		unsigned int SelectedSolver = 0;

		// выбор метода
		while (true)
		{
			std::cout << "Хотите добавить решатель? yes/no \n";
			YesOrNoInput = GetCorrectStringInput();

			// не хотим больше добавлять решатели
			if (YesOrNoInput == "no") 
				break;

			std::cout << " Выберите вид решателя 1 - Explicit Euler Method, 2 - Method Hoina\n";
			SelectedSolver = GetCorrectEnteredNumber();
			break;
		}

		// не хотим больше добавлять решатели
		if (YesOrNoInput == "no") 
			break;

		// добавление решателя по имени
		while (true)
		{
			std::cout << "Введите имя вашего решателя: ";
			std::cin >> Name;

			// проверяем на наличие таких имён
			try 
			{
				Solver.CheckNameRepeat(Name); // здесь идёт сама проверка

				// Определение поведения в зависимости от входных параметров
				Behavior = DefineBehavior(t0, T, h, Name);

				//выбор решателя в зависимости от выбора пользователя
				if (SelectedSolver == 1)
					Solver.AddSolverEulerMethod(Name, Behavior);
				else
					Solver.AddSolverMethodHoina(Name, Behavior);
				
				break;
			}
			catch (const FarmSolvers::Errors)
			{
				std::cout << "Ошибка! Вы ввели 2 одинаковых имени! Попробуйте еще!\n";
			}
		}
	}

	//решение задач всеми решателями
	Solver.SolveProblem(Task);


	// Просмотр результатов и удаление решателей
	while (true) 
	{
		std::cout << "Посмотреть результаты? yes/no \n";
		YesOrNoInput = GetCorrectStringInput();
		
		// не хотим больше смотреть результаты
		if (YesOrNoInput == "no") 
			break;

		// цикл для просмотра результатов
		while (true) 
		{
			std::cout << "Введите имя решателя, для просмотра результатов:";	
			std::cin >> Name;

			//проверка на корректное имя
			try
			{
				Point = Solver.GetResults(Name);
				std::cout << Point;
				break;
			}
			catch (const FarmSolvers::Errors)
			{
				std::cout << "Ошибка! Такого решателя не существует! Повторите ввод!\n";
			}
			
		}
		//// цикл на удаление решателей
		//while (true) 
		//{
		//	// если решателей не осталось
		//	if (NumberOfExistingSolvers == 0) 
		//	{
		//		std::cout << "Отсутствуют решатели!\n";
		//		break;
		//	}
		//	std::cout << "Хотите удалить решатель? yes/no \n";
		//	YesOrNoInput = GetCorrectStringInput();
		//	// не хотим больше удалять
		//	if (YesOrNoInput == "no") 
		//		break;
		//	// проверка на корректное имя
		//	while (true)
		//	{
		//		std::cout << "Введите имя решателя, для его удаления: ";	
		//		std::cin >> Name;
		//		//непосредственно удаление
		//		try
		//		{
		//			Solver.DeleteMethod(Name);
		//			NumberOfExistingSolvers--;
		//			break;
		//		}
		//		catch (const FarmSolvers::Errors)
		//		{
		//			std::cout << "Ошибка! Такого решателя не существует! Повторите ввод!\n";
		//		}
		//	}
		//}
		//// если решателей не осталось
		//if (NumberOfExistingSolvers == 0)
		//{
		//	std::cout << "Отсутствуют решатели!\n";
		//	break;
		//}
	}
}

double GetCorrectEnteredNumber()
{
	double i;
	std::string parametr;

	while (true)
	{
		std::cin >> parametr;
		try
		{
			i = std::stod(parametr);
			break;
		}
		catch (const std::logic_error)
		{
			std::cout << "Ошибка, Вы ввели не число! Попробуйте еще!\n";
		}
	}
	return i;
}

std::string GetCorrectStringInput()
{
	std::string Input;
	while (true)
	{
		std::cin >> Input;

		if (Input == "yes" || Input == "no")
			break;
		else std::cout << "Ввод некоректен. Введите еще раз.\n";
	}
	return Input;
}

BehaviorOfSolver DefineBehavior(const double t0, const double T, const double h, std::string& Name)
{
	BehaviorOfSolver Behavior;
	int Costil;
	for (double i = t0; i <= T; i += h)
		if (((i + h) > T) && (i != T))
			while (true)
			{
				std::cout << "Интервал [t0; T] не удалось разбить на целое число шагов интегрирования. Придётся задать поведение.\n";
				std::cout << "Выберите алгоритм поведения для решателя по имени: " << Name << "\n";
				std::cout << "1 - уменьшить величину последнего шага интегрирования до такой, чтобы расчёт завершился ровно в точке T\n";
				std::cout << "2 - не изменять величину последнего шага, закончить расчёт в точке q > T\n";
				std::cout << "3 -  не изменять величину последнего шага, закончить расчёт в точке q < T.\n";
				Costil = GetCorrectEnteredNumber();
				
				if (Costil == 1 || Costil == 2 || Costil == 3)
					break;
				else
					std::cout << "Ошибка! Вы ввели неверное число\n";
			}

	return Behavior = static_cast<BehaviorOfSolver>(Costil);
	
}

