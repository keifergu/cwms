#include "stdafx.h"
#include "MiddleManager.h"

MiddleManager::MiddleManager(string t_name, string t_age,string t_sex, string t_worktime)
: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("中层管理人员");
	setJobMoney(200);
}

int MiddleManager::getMoney(){
	return 1;
}

void MiddleManager::setMoney(int ym, int b){
	setYearMoney(ym*2);
	setBonus(b);
}