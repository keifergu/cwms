
#include "Staff.h"

class Finance : public Staff{
public:
	Finance(char* t_name, char* t_age,char* t_sex, char* t_worktime);

	int getMoney();
	void setMoney(int ym, int b);
};
