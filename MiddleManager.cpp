#include "stdafx.h"
#include "MiddleManager.h"

MiddleManager::MiddleManager(string t_name, string t_age,string t_sex, string t_worktime)
: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("中层管理人员");
	setJobMoney(200);
}

MiddleManager::~MiddleManager()
{
}

inline int MiddleManager::getMoney()
{
	return getBaseMoney() + getJobMoney() + getBonus();
}

void MiddleManager::setMoney(int bm, int jm, int b) {
	setBaseMoney(bm);
	setJobMoney(jm);
	setBonus(b);
}