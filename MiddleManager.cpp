
#include "MiddleManager.h"

MiddleManager::MiddleManager(char* t_name, char* t_age,char* t_sex, char* t_worktime)
: Staff(t_name, t_age, t_sex, t_worktime)
{
	setJob("中层管理人员");
	setJobMoney(200);
}

int getMoney::MiddleManager(){
	
}
void setMoney::MiddleManager(int ym, int b){
	setYearMoney(ym*2);
	setBonus(b);
}
