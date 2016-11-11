#pragma once
#include "Staff.h"

class HighManager : public Staff{
public:
	HighManager(string, string,string, string);
	~HighManager();

	int getMoney();
	void setMoney(int basem, int jobm, int bonus, int divident);

	void setDividend(int); // 设置分红
	int getDividend();	   // 获得分红

private:
	int dividend;		   // 高层管理人员的分红
};