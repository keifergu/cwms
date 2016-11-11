#include "stdafx.h"
#include "Admin.h"

Admin::Admin() {
	init();
}

Admin::~Admin() {

}

void Admin::init() {
	// 初始化数据
	/*string staff_a[4] = {"Job","35","男","5年"};
	string st2[4] = {"Mike","40","男","4年"};
	MiddleManager* mm1 = new MiddleManager(st1[0],st1[1],st1[2],st1[3]);
	mm1->setMoney(100,300);
	MiddleManager* mm2 = new MiddleManager(st2[0],st2[1],st2[2],st2[3]);
	mm2->setMoney(200,400);
	middleStaff.push_back(mm1);
	middleStaff.push_back(mm2);
	*/
	// 显示主菜单
	showMenu();
}

void Admin::showMenu() {
	// 主菜单
	int f = 1;
	while (f != 0) {
		cout << "----XX公司财务及员工信息管理系统----" << endl;
		cout << "1. 员工信息管理系统" << endl;
		cout << "2. 财务管理系统" << endl;
		cout << "请输入选项前的编号以进入系统（输入0退出系统）:";
		cin >> f;

		// 员工管理系统
		if (f == 1) showStaffAdmin();

		// 工资管理系统
		if (f == 2) showWageAdmin();

		if (f == 0) exit(0);
	}
}

void Admin::showWageAdmin() {
	cout << "\n姓名\t年龄\t性别\t工作时间\t职位\t" << endl;
	vector< vector<string>> staffInfo = getStaffInfo();
	for (int i = 0; i < staffInfo.size(); i++)
	{
		for (int j = 0; j < staffInfo[i].size(); j++)
		{
			cout << staffInfo[i][j];
		}
		cout << endl;
	}
	cout << "\n\n";
}

void Admin::showAddStaff() {

}

void Admin::showStaffAdmin() {
	cout << "\n姓名\t年龄\t性别\t工作时间\t职位\t" << endl;
	vector< vector<string>> staffInfo = getStaffInfo();
	for (int i = 0; i < staffInfo.size(); i++)
	{
		for (int j = 0; j < staffInfo[i].size(); j++)
		{
			cout << staffInfo[i][j];
		}
		cout << endl;
	}
	cout << "\n\n";
}

vector< vector<string>> Admin::getStaffInfo() {
	vector< vector<string>> staffInfo;
	vector<string> stringTmp;

	int mlength = middleStaff.size();
	int hlength = highStaff.size();
	int slength = saleStaff.size();

	for (int i = 0; i < mlength; i++)
	{
		stringTmp.push_back(middleStaff[i]->getName());
		stringTmp.push_back(middleStaff[i]->getSex());
		stringTmp.push_back(middleStaff[i]->getAge());
		stringTmp.push_back(middleStaff[i]->getJob());
		stringTmp.push_back(middleStaff[i]->getWorkTime());
	}
	staffInfo.push_back(stringTmp);
	stringTmp.clear();

	for (int i = 0; i < hlength; i++)
	{
		stringTmp.push_back(highStaff[i]->getName());
		stringTmp.push_back(highStaff[i]->getSex());
		stringTmp.push_back(highStaff[i]->getAge());
		stringTmp.push_back(highStaff[i]->getJob());
		stringTmp.push_back(highStaff[i]->getWorkTime());
	}
	staffInfo.push_back(stringTmp);
	stringTmp.clear();

	for (int i = 0; i < slength; i++)
	{
		stringTmp.push_back(saleStaff[i]->getName());
		stringTmp.push_back(saleStaff[i]->getSex());
		stringTmp.push_back(saleStaff[i]->getAge());
		stringTmp.push_back(saleStaff[i]->getJob());
		stringTmp.push_back(saleStaff[i]->getWorkTime());
	}
	staffInfo.push_back(stringTmp);
	stringTmp.clear();

	staffInfo.push_back(stringTmp);
	return staffInfo;
}

vector< vector<string>> Admin::getAllWagesInfo() {
	vector< vector<string>> wageInfo;
	vector<string> stringTmp;

	int mlength = middleStaff.size();
	int hlength = highStaff.size();
	int slength = saleStaff.size();

	int min = 999999, max = 0, total = 0;

	for (int i = 0; i < mlength; i++) {

		stringTmp.push_back(middleStaff[i]->getName());
		int m = middleStaff[i]->getMoney();
		// int 类型转换为 string 再放入 vector
		stringstream tmpa;
		string tmpb;
		tmpa << m;
		tmpa >> tmpb;
		stringTmp.push_back(tmpb);
	}
	wageInfo.push_back(stringTmp);
	stringTmp.clear();

	for (int i = 0; i < hlength; i++) {
		stringTmp.push_back(highStaff[i]->getName());
		int m = highStaff[i]->getMoney();
		// int 类型转换为 string 再放入 vector
		stringstream tmpa;
		string tmpb;
		tmpa << m;
		tmpa >> tmpb;
		stringTmp.push_back(tmpb);
	}
	wageInfo.push_back(stringTmp);
	stringTmp.clear();

	for (int i = 0; i < slength; i++) {
		stringTmp.push_back(highStaff[i]->getName());
		int m = highStaff[i]->getMoney();
		// int 类型转换为 string 再放入 vector
		stringstream tmpa;
		string tmpb;
		tmpa << m;
		tmpa >> tmpb;
		stringTmp.push_back(tmpb);
	}
	wageInfo.push_back(stringTmp);
	stringTmp.clear();

	return wageInfo;
	/*
	if (item == 1) {
		ofstream file;
		file.open("staff.txt", ios::out | ios::app);
		file << "最低工资为:" << min << "\t最高工资为:" << max << "\t总支出工资为:" << total << endl;
		file.close();
		cout << "导出成功\n\n\n";
	}
	return (string)"allWages";
	*/
}


void Admin::addStaff() {
	char name[20], age[20], sex[4], time[20];
	int yearMoney, bonus, type;
	type = 1;
	cout << "pleas" << endl;
	cout << "name:";
	cin >> name;
	cout << "age:";
	cin >> age;
	cout << "sex:";
	cin >> sex;
	cout << "work time:";
	cin >> time;
	cout << "wage/year";
	cin >> yearMoney;
	cout << "bonus:";
	cin >> bonus;
	cout << "请选择员工类别:\n1.中层管理人员\n2.高层管理人员\n3.财务人员\n";
	cin >> type;
	switch (type) {
	case(1) : {
		MiddleManager* m = new MiddleManager((char*)name, (char*)age, (char*)sex, (char*)time);
		//m->setMoney((int)yearMoney, (int)bonus);
		middleStaff.push_back(m);
		break;
	}
	case(2) : {
		HighManager* h = new HighManager((char*)name, (char*)age, (char*)sex, (char*)time);
		//h->setMoney(yearMoney, bonus);
		highStaff.push_back(h);
		break;
	}
	case(3) : {
		Salesman* f = new Salesman((char*)name, (char*)age, (char*)sex, (char*)time);
//		f->setMoney(1, 1.2);
		saleStaff.push_back(f);
		break;
	}
	default:
		cout << "error" << endl;
	};
}

void Admin::setStaffInfo(int i) {

}


void Admin::exportFile(char* type, char* path) {

}

void Admin::importFile(char* type, char* path) {

}