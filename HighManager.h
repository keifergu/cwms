#pragma once
#include "Staff.h"

class HighManager : public Staff{
public:
	HighManager(string, string,string, string);

	int getMoney();
	void setMoney(int, int);
};