
#include "Admin.h"

Admin::Admin(){
	init();
}

Admin::~Admin(){

}

void Admin::init(){
	// 初始化数据
	string st1[4] = {"Job","35","男","5年"};
	string st2[4] = {"Mike","40","男","4年"};
	MiddleManager* mm1 = new MiddleManager(st1[0],st1[1],st1[2],st1[3]);
	mm1->setMoney(100,300);
	MiddleManager* mm2 = new MiddleManager(st2[0],st2[1],st2[2],st2[3]);
	mm2->setMoney(200,400);
	middleStaff.push_back(mm1);
	middleStaff.push_back(mm2);

	// 显示主菜单
	showMenu();
}

void Admin::showMenu(){
	// 主菜单
	int f = 1;
	while(f != 0) {
	 cout<<"------xx公司人员工资管理系统------"<<endl;
	 cout<<"1.员工管理界面"<<endl;
	 cout<<"2.工资管理界面"<<endl;
	 cout<<"请输入编号选择功能,输入q退出: ";
	 cin>>f;

	 // 员工管理系统
	 if(f==1) showStaffAdmin();

	 // 工资管理系统
	 if(f==2) showWageAdmin();

	}
}

void Admin::showWageAdmin(){

}

void Admin::showAddStaff(){

}

void Admin::showStaffAdmin(){
	int t = 1;
	cout<<"name\tage\tsex\twork time\tjob\t"<<endl;
	cout<<middleStaff[t]->getName();
	cout<<middleStaff[t]->getAge();
	cout<<middleStaff[t]->getSex();
	cout<<middleStaff[t]->getWorkTime();
	cout<<middleStaff[t]->getMoney();
	cout<<middleStaff[t]->getJob()<<endl;

	int i = middleStaff.size();
	int m = highStaff.size();
	int n = financeStaff.size();
	cout<<"\n\n";
}


string Admin::getStaffInfo(){

}

string Admin::getAllWagesInfo(){
	int i = middleStaff.size();
	int m = highStaff.size();
	int n = financeStaff.size();
	int min = 999999,max = 0, total = 0;
	int t;
	cout<<"\n\n正在计算工资情况\n";
	for(t = 0; t<i; t++){
		int m = middleStaff[t]->getMoney();
		min = min > m ? m : min;
		max = max < m ? m : max;
		total += m;
	}
	for(t = 0; t<m; t++){
		int m = highStaff[t]->getMoney();
		min = min > m ? m : min;
		max = max < m ? m : max;
		total += m;
	}
	for(t = 0; t<n; t++){
		int m = financeStaff[t]->getMoney();
		min = min > m ? m : min;
		max = max < m ? m : max;
		total += m;
	}
	int item;
	cout<<"最低工资为:"<<min<<endl;
	cout<<"最高工资为:"<<max<<endl;
	cout<<"总支出工资为:"<<total<<endl;
	cout<<"导出工资单请输入1:";
	cin>>item;
	if(item == 1){
		ofstream file;
		file.open("staff.txt",ios::out|ios::app);
		file<<"最低工资为:"<<min<<"\t最高工资为:"<<max<<"\t总支出工资为:"<<total<<endl;
		file.close();
		cout<<"导出成功\n\n\n";
	}
}


void Admin::addStaff(){
	char name[20], age[20], sex[4], time[20];
	int yearMoney,bonus,type;
	type = 1;
	cout<<"请输入员工信息"<<endl;
	cout<<"姓名：";
	cin>>name;
	cout<<"年龄：";
	cin>>age;
	cout<<"性别：";
	cin>>sex;
	cout<<"工作年限：";
	cin>>time;
	cout<<"年限工资:";
	cin>>yearMoney;
	cout<<"绩效奖励:";
	cin>>bonus;
	cout<<"请选择员工类别:\n1.中层管理人员\n2.高层管理人员\n3.财务人员\n";
	cin>>type;
	switch(type) {
	case(1):{
		MiddleManager* m = new MiddleManager((char*)name,(char*)age,(char*)sex,(char*)time);
		m->setMoney((int)yearMoney, (int)bonus);
		middleStaff.push_back(m);
		break;
	}
	case(2):{
		HighManager* h = new HighManager((char*)name,(char*)age,(char*)sex,(char*)time);
		h->setMoney(yearMoney,bonus);
		highStaff.push_back(h);
		break;
	}
	case(3):{
		Finance* f = new Finance((char*)name,(char*)age,(char*)sex,(char*)time);
		f->setMoney(yearMoney,bonus);
		financeStaff.push_back(f);
		break;
	}
	default:
	 cout<<"error"<<endl;
	};
}

void Admin::setStaffInfo(int i){

}


void Admin::exportFile(char* type, char* path){

}

void Admin::importFile(char* type, char* path){

}
