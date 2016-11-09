#pragma once

#include "Finance.h"
#include "HighManager.h"
#include "MiddleManager.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Admin
{
public:
	Admin();
	~Admin();
	
	void init();							// 运行函数

	void showMenu();  				// 显示主菜单
	void showAddStaff();      // 显示添加员工界面
	void showWageAdmin();			// 显示工资管理界面
	void showStaffAdmin();		// 显示员工管理界面

	string getStaffInfo();  	// 获得员工的所有基本信息
	string getAllWagesInfo(); // 获得所有的工资信息

	void addStaff();					// 添加一个员工
	void setStaffInfo(int i); // 设置某一个员工的信息

	void exportFile(char* type, char* path);				// 导出文件
	void importFile(char* type, char* path);				// 导入员工信息文件

private:
	vector<Finance*> financeStaff;
	vector<HighManager*> highStaff;
	vector<MiddleManager*> middleStaff;
};