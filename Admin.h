#pragma once
#include "stdafx.h"
#include <vector>
#include <map>

using namespace std;

class Admin
{
public:
	Admin();
	~Admin();
	
	void init();				// 运行函数

	void showMenu(); 			// 显示主菜单
	void showWageAdmin();		// 显示工资管理界面
	void showStaffAdmin();		// 显示员工管理界面
	
	void showWageCount();		// 显示工资统计结果界面
	void showAllWageInfo();		// 显示所有员工工资

	void showAddStaff();        // 显示添加员工界面
	void showAllStaffInfo();	// 显示所有员工信息

	void setStaffInfo(int i);	// 设置某一个员工的信息
	void addStaff(int type, vector<string> staff, vector<int> wage);	// 添加一个员工


	void exportAllWage();	// 导出文件
	void exportAllStaff(); 
	void importAllStaff();	// 引入文件

	vector< vector<string>> getStaffInfo();  	// 获得员工的所有基本信息
	vector< vector<string>> getAllWagesInfo();  // 获得所有的工资信息

	vector<int> getWageCount();		// 获得工资的统计信息
private:
	vector<Salesman* > saleStaff;
	vector<HighManager* > highStaff;
	vector<MiddleManager* > middleStaff;

	vector<Staff*> allStaff;
};