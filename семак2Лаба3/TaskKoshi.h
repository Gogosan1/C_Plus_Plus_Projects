#pragma once

class TaskKoshi
{
private:
	double y0, x0, t0, T, h;

public:
	
	TaskKoshi(double y, double x, double t, double T, double h)
		: y0(y), x0(x), t0(t), T(T), h(h)
	{}

	double Gety0() const;
	double Getx0() const;
	double Gett0() const;
	double GetT() const;
	double Geth() const;
	double CountFunctionValue(const double &, const double &)const; // не уверен
	
};