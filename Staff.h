class Staff {

public:
	Staff(string t_name, string t_age,string t_sex, string t_worktime);

	string getSex();								// 获得员工性别
	string getJob();								// 获得员工的工作岗位
	string getAge();								// 获得员工年龄
	string getName();							// 获得员工姓名
	string getWorkTime();					// 获得员工工作年限

	void setBonus(int m);					// 设置奖金
	void setJobMoney(int m);			// 设置岗位工资
	void setBaseMoney(int m);			// 设置基本工资
	void setYearMoney(int m);			// 设置工作年限工资

	void setJob(string t_job);			// 设置岗位

	virtual int getMoney();			// 获得员工工资
	virtual void setMoney();		// 设置相应的工资项目

private:

	// 员工基本信息
	string name;
	string sex;
	string age;
	string job;
	string workTime;
	
	// 员工工资信息
	int baseMoney,jobMoney,yearMoney,bonus;
};