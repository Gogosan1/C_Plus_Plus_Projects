#pragma once

class TaskKoshi
{
private:
	double y0, t0, T, h;

public:
	
	TaskKoshi(double y, double t, double T, double h)
		: y0(y), t0(t), T(T), h(h)
	{}

	double Gety0() const;
	double Gett0() const;
	double GetT() const;
	double Geth() const;
	double CountFunctionValue(const double, const double)const; 
	
};