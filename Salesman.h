#pragma once
#include "Staff.h"
class Salesman :
	public Staff
{
public:
	Salesman(string, string, string, string);
	~Salesman();
private:
	int volume;		// 销售额
	float percent;	// 提成额度
public:
	void setVolume(int v); // 设置单价
	void setPercent(float p);// 设置提成额度
	
	void setMoney(int volume, float percent);  // 设置销售额和提成
	int getMoney();		 // 获得工资
};

