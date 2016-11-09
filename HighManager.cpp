
#include "HighManager.h"

HighManager::HighManager(char* t_name, char* t_age,char* t_sex, char* t_worktime)
: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("高层管理人员");
	setJobMoney(400);
}

void HighManager::setMoney(int ym, int b){
	setYearMoney(ym*3);
	setBonus(b);
}