#include <iostream>
#include <vector>
#include "SolverEulerMethod.h"
#include "SolverMethodHoina.h"
#include "TaskKoshi.h"
#include "FarmSolvers.h"
#include "EnumsAndStructures.h"

double GetCorrectEnteredNumber();
std::string GetCorrectYesOrNoStringInput();
std::string GetCorrectKindOfSolverInput();
BehaviorOfSolver DefineBehavior(const double, const double, const double, std::string&);

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
	std::vector <FarmSolvers> ArraySolvers;

	std::string Name, YesOrNoInput;
	BehaviorOfSolver Behavior = static_cast<BehaviorOfSolver>(0);
	Points Point;
	KindOfSolver Kind;
	// создание решателя
	while (true)
	{
		// выбор метода
		while (true)
		{
			unsigned int Input;
			std::cout << "Хотите добавить решатель? yes/no \n";
			YesOrNoInput = GetCorrectYesOrNoStringInput();

			// не хотим больше добавлять решатели
			if (YesOrNoInput == "no") 
				break;

			while (true) 
			{
				std::cout << " Выберите вид решателя 1 - Explicit Euler Method, 2 - Method Hoina\n";
				Input = GetCorrectEnteredNumber();
				if (Input == 1 || Input == 2)
				{
					Kind = static_cast<KindOfSolver>(Input);
					break;
				}
				else
					std::cout << "Введено неверное значение. Повторите ввод\n";
			}
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
			int Costil = 0;
			// проверяем на наличие таких имён
			for (int i = 0; i < ArraySolvers.size(); i++)
			{
				if (ArraySolvers[i].GetName() == Name)
				{
					std::cout << "Ошибка Такое имя уже существует! Повторите ввод.\n";
					Costil++;
					break;
				}
			}
			if (Costil == 0)
			{
				Behavior = DefineBehavior(t0, T, h, Name);
				break;
			}
		}
		FarmSolvers Solver(Name, Kind, Behavior);// Работа конструктора
		ArraySolvers.push_back(Solver);
	}

	//решение задач всеми решателями
	for (int i = 0; i < ArraySolvers.size(); i++)
		ArraySolvers[i].SolveProblem(Task);


	// Просмотр результатов и удаление решателей
	while (true) 
	{
		if (ArraySolvers.empty())
		{
			std::cout << "Отсутсвуют решатели!\n";
			break;
		}
		std::cout << "Посмотреть результаты? yes/no \n";
		YesOrNoInput = GetCorrectYesOrNoStringInput();
		
		// не хотим больше смотреть результаты
		if (YesOrNoInput == "no") 
			break;

		// цикл для просмотра результатов
		while (true) 
		{
			std::cout << "Введите имя решателя, для просмотра результатов:";	
			std::cin >> Name;

			int counter = -1;

			for (int i = 0; i < ArraySolvers.size(); i++)
				if (ArraySolvers[i].GetName() == Name)
				{
					counter = i;
					break;
				}
			
			if (counter == -1)
				std::cout << "Ошибка! Решателя по такому имени не существует!\n";
			else
			{
				Point = ArraySolvers[counter].GetResults();
				std::cout << Point;
				break;
			}
			
		}
		// Цикл для удаления
		while (true)
		{
			std::cout << "Хотите удалить решатель? yes/no \n";
			YesOrNoInput = GetCorrectYesOrNoStringInput();

			if (YesOrNoInput == "no")
				break;

			std::cout << "Введите имя решателя, который хотите удалить:";
			std::cin >> Name;


			for (int i = 0; i < ArraySolvers.size(); i++)
				if (ArraySolvers[i].GetName() == Name)
					ArraySolvers.erase(ArraySolvers.cbegin() + i);

			if (ArraySolvers.empty())
			{
				std::cout << "Все решатели удалены!\n";
				break;
			}
		}
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

std::string GetCorrectYesOrNoStringInput()
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

std::string GetCorrectKindOfSolverInput()
{
	std::string Input;
	while (true)
	{
		std::cin >> Input;

		if (Input == "Euler" || Input == "Hoin")
			break;
		else std::cout << "Ввод некоректен. Введите еще раз.\n";
	}
	return Input;
}

BehaviorOfSolver DefineBehavior(const double t0, const double T, const double h, std::string& Name)
{
	BehaviorOfSolver Behavior;
	int Costil = 0;
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