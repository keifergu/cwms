#include "stdafx.h"
#include "HighManager.h"

HighManager::HighManager(string t_name, string t_age,string t_sex, string t_worktime)
: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("高层管理人员");
	setJobMoney(400);
}

int HighManager::getMoney()
{
	return 0;
}

void HighManager::setMoney(int ym, int b){
	setYearMoney(ym*3);
	setBonus(b);
}