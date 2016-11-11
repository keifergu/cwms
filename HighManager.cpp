#include "stdafx.h"
#include "HighManager.h"

HighManager::HighManager(string t_name, string t_age,string t_sex, string t_worktime)
: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("高层管理人员");
	setJobMoney(400);
}

HighManager::~HighManager()
{
}

int HighManager::getMoney()
{
	return getBaseMoney() + getJobMoney() + getBonus() + getDividend();
}

void HighManager::setMoney(int bm, int jm, int b, int d){
	setBaseMoney(bm);
	setJobMoney(jm);
	setBonus(b);
	setDividend(d);
}

void HighManager::setDividend(int m)
{
	dividend = m;
}

int HighManager::getDividend()
{
	return dividend;
}
