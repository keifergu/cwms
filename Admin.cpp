#include "stdafx.h"
#include "Admin.h"

Admin::Admin() {
	init();
}

Admin::~Admin() {
	delete &saleStaff;
	delete &middleStaff;
	delete &highStaff;
}

void Admin::init() {
	// 初始化数据
	string st1[4] = {"Job","35","男","5年"};
	string st2[4] = {"Mike","40","男","4年"};
	string st3[4] = { "Janie","24","女","1年" };

	MiddleManager* mm1 = new MiddleManager(st1[0],st1[1],st1[2],st1[3]);
	mm1->setMoney(1000, 1000, 500);
	HighManager* mm2 = new HighManager(st2[0],st2[1],st2[2],st2[3]);
	mm2->setMoney(100, 1500, 700, 800);
	Salesman* mm3 = new Salesman(st3[0], st3[1], st3[2], st3[3]);
	mm3->setMoney(15000, (float)0.15);
	middleStaff.push_back(mm1);
	highStaff.push_back(mm2);
	saleStaff.push_back(mm3);

	allStaff.push_back(mm1);
	allStaff.push_back(mm2);
	allStaff.push_back(mm3);

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

void Admin::showStaffAdmin()
{
	int f = 0;
	cout << "\n\n1. 显示所有员工信息\n";
	cout << "2. 添加一个员工\n";
	cout << "请输入序号：";
	cin >> f;
	if (f == 1) showAllStaffInfo();
	else if (f == 2) showAddStaff();
	else showMenu();
}

void Admin::showWageAdmin() {
	int f = 0;
	cout << "\n\n1. 显示所有员工工资信息\n";
	cout << "2. 显示当月工资统计情况\n";
	cout << "请输入序号：";
	cin >> f;
	if (f == 1) showAllWageInfo();
	else if (f == 2) showWageCount();
	else showMenu();
}

void Admin::showAddStaff() {
	vector<string> staff;
	vector<int> wage;
	char name[20], age[20], sex[4], time[20];
	int basem, jobm, bonus, divm, volume, percent;
	basem = jobm = bonus = divm = volume = percent = 0;
	int type = 1;
	cout << "请选择添加的员工类别:\n1.中层管理人员\t2.高层管理人员\t3.销售人员\n";
	cin >> type;

	cout << "请输入员工信息:" << endl;
	cout << "姓名：";
	cin >> name;
	cout << "年龄：";
	cin >> age;
	cout << "性别：";
	cin >> sex;
	cout << "工作经验：";
	cin >> time;
	switch (type)
	{
	case 1:
		cout << "基础工资：";
		cin >> basem;
		cout << "职位工资：";
		cin >> jobm;
		cout << "月度奖金：";
		cin >> bonus;
		break;
	case 2:
		cout << "基础工资：";
		cin >> basem;
		cout << "职位工资：";
		cin >> jobm;
		cout << "月度奖金：";
		cin >> bonus;
		cout << "月度分红：";
		cin >> divm;
		break;
	case 3:
		cout << "销售额：";
		cin >> volume;
		cout << "提成：";
		cin >> percent;
		break;
	default:
		break;
	}
	staff.push_back(name);
	staff.push_back(age);
	staff.push_back(sex);
	staff.push_back(time);
	
	wage.push_back(basem);
	wage.push_back(jobm);
	wage.push_back(bonus);
	wage.push_back(divm);
	wage.push_back(volume);
	wage.push_back(percent);

	// 调用添加员工的函数
	addStaff(type, staff, wage);

	cout << "添加员工成功!\n\n";
}

void Admin::showAllStaffInfo()
{
	cout << "\n姓名\t年龄\t性别\t职位\t\t工作经验\t" << endl;
	vector< vector<string>> staffInfo = getStaffInfo();
	for (int i = 0; i < (int)staffInfo.size(); i++)
	{
		for (int j = 0; j < (int)staffInfo[i].size(); j++)
		{
			cout << staffInfo[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n";
}



void Admin::showWageCount()
{
	cout << "本月工资统计情况为：" << endl;

	vector<int> countInfo = getWageCount();
	cout << "工资总数\t平均工资\t最高工资\t最低工资" << endl;
	for (int i = 0; i < (int)countInfo.size(); i++)
	{
		cout << countInfo[i] << "\t";
	}
	cout << "\n\n";
}

void Admin::showAllWageInfo()
{
	cout << "\n姓名\t职位\t\t工资\t" << endl;
	vector< vector<string>> staffInfo = getAllWagesInfo();
	for (int i = 0; i < (int)staffInfo.size(); i++)
	{
		for (int j = 0; j < (int)staffInfo[i].size(); j++)
		{
			cout << staffInfo[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";
	cout << "导出所有员工工资信息请输入1:";
	int t;
	cin >> t;
	if (t == 1) {
		exportAllWage();
		cout << "\n导出成功！\n\n";
	}
}

vector< vector<string>> Admin::getStaffInfo() {
	vector< vector<string>> staffInfo;
	vector<string> stringTmp;
	
	int length = allStaff.size();

	for (int i = 0; i < length; i++)
	{
		stringTmp.push_back(allStaff[i]->getName());
		stringTmp.push_back(allStaff[i]->getSex());
		stringTmp.push_back(allStaff[i]->getAge());
		stringTmp.push_back(allStaff[i]->getJob());
		stringTmp.push_back(allStaff[i]->getWorkTime());
		staffInfo.push_back(stringTmp);
		stringTmp.clear();
	}
	return staffInfo;
}

vector< vector<string>> Admin::getAllWagesInfo() {
	vector< vector<string>> wageInfo;
	vector<string> stringTmp;

	int mlength = allStaff.size();

	int min = 999999, max = 0, total = 0;

	for (int i = 0; i < mlength; i++) {

		stringTmp.push_back(allStaff[i]->getName());
		stringTmp.push_back(allStaff[i]->getJob());
		int m = allStaff[i]->getMoney();
		// int 类型转换为 string 再放入 vector
		stringstream tmpa;
		string tmpb;
		tmpa << m;
		tmpa >> tmpb;
		stringTmp.push_back(tmpb);

		wageInfo.push_back(stringTmp);
		stringTmp.clear();
	}

	return wageInfo;
}

vector<int> Admin::getWageCount()
{
	vector<int> countInfo;
	vector< vector<string>> allWageInfo = getAllWagesInfo();
	int wlength = allWageInfo.size();

	int total = 0, min = 99999, max = 0;

	for (int i = 0; i < wlength; i++)
	{
		int wage = atoi(allWageInfo[i][2].c_str());
		total += wage;
		min = min < wage ? min : wage;
		max = max > wage ? max : wage;
	}
	int avrage = total / wlength;
	countInfo.push_back(total);
	countInfo.push_back(avrage);
	countInfo.push_back(max);
	countInfo.push_back(min);
	return countInfo;
}


void Admin::addStaff(int type, vector<string> staff, vector<int> wage) {
	string name = staff[0],
		age = staff[1],
		sex = staff[2],
		time = staff[3];
	int basem = wage[0],
		jobm = wage[1],
		bonus = wage[2],
		divm = wage[3],
		volum = wage[4],
		percent = wage[5];
	switch (type) {
	case(1) : {
		MiddleManager* m = new MiddleManager(name, age, sex, time);
		m->setMoney(basem, jobm, bonus);
		middleStaff.push_back(m);
		break;
	}
	case(2) : {
		HighManager* h = new HighManager(name, age, sex, time);
		h->setMoney(basem, jobm, bonus, divm);
		highStaff.push_back(h);
		break;
	}
	case(3) : {
		Salesman* f = new Salesman(name, age, sex, time);
		f->setMoney(volum, (float)0.2);
		saleStaff.push_back(f);
		break;
	}
	default: {
		break;
	}
		
	}
}

void Admin::setStaffInfo(int i) {

}

void Admin::exportAllWage()
{
	vector< vector<string>> staffInfo = getAllWagesInfo();
	ofstream file;
	file.open("staffWages.txt", ios::out | ios::app);
	for (int i = 0; i < (int)staffInfo.size(); i++)
	{
		for (int j = 0; j < (int)staffInfo[i].size(); j++)
		{
			file << staffInfo[i][j] << " ";
		}
		file << "\n";
	}
	file.close();
}

void Admin::exportAllStaff()
{
	vector< vector<string>> staffInfo = getStaffInfo();
	ofstream file;
	file.open("staffInfo.txt", ios::out | ios::app);
	for (int i = 0; i < (int)staffInfo.size(); i++)
	{
		for (int j = 0; j < (int)staffInfo[i].size(); j++)
		{
			file << staffInfo[i][j] << " ";
		}
		file << "\n";
	}
	file.close();
}

void Admin::importAllStaff()
{
	vector< vector<string>> staffInfo;
	ifstream file;
	char buffer[512];
	string tmp;
	file.open("staffInfo.txt");
	while (!file.eof())
	{
		file.getline(buffer, 512, ' ');
		cout << buffer << " ";
	}
	file.close();
}