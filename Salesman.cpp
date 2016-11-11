#include "stdafx.h"
#include "Salesman.h"

Salesman::Salesman(string t_name, string t_age, string t_sex, string t_worktime)
	: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("销售人员");
}

Salesman::~Salesman()
{
}

void Salesman::setVolume(int v)
{
	volume = v;
}

void Salesman::setPercent(float p)
{
	percent = p;
}

void Salesman::setMoney(int v, float p)
{
	volume = v;
	percent = p;
}

int Salesman::getMoney()
{
	float m = volume * percent;
	return (int)m;
}
