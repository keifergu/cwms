#pragma once
#include <string>
using namespace std;

class Staff {

public:
	Staff(string t_name, string t_age,string t_sex, string t_worktime);
	~Staff();

	// 获取相应的员工信息
	string getSex();
	string getJob();
	string getAge();
	string getName();
	string getWorkTime();

	// 设置相应的工资项
	void setBonus(int);       // 奖金
	void setJobMoney(int);    // 职位工资
	void setBaseMoney(int);   // 基本工资
	void setYearMoney(int);   // 年终奖

    // 获取相应的工资项
	int getBonus();
	int getJobMoney();
	int getBaseMoney();
	int getYearMoney();

	void setJob(string);			// 设置岗位

	virtual int getMoney();			// 获得员工工资
	virtual void setMoney();		// 设置相应的工资项目

private:

	// 员工基本信息
	string name,sex,age,job,workTime;
	
	// 员工工资信息
	int baseMoney,jobMoney,yearMoney,bonus;
};