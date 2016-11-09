#pragma once
#include "Staff.h"

class Finance : public Staff{
public:
	Finance(string, string,string, string);

	int getMoney();
	void setMoney(int, int);
};
