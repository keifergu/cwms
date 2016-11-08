
#include "Staff.h"

class HighManager : public Staff{
public:
	HighManager(char* t_name, char* t_age,char* t_sex, char* t_worktime);

	void setMoney(int ym, int b);
};