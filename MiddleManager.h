#pragma once
#include "Staff.h"

class MiddleManager : public Staff{
public:
	MiddleManager(string, string, string, string);
	~MiddleManager();

	int getMoney();
	void setMoney(int basem, int jobm, int bonus);
};