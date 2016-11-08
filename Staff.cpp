#include "Staff.h"

Staff::Staff(char* t_name, char* t_age,char* t_sex, char* t_worktime)
: name(t_name),age(t_age),sex(t_sex),workTime(t_worktime)
{
  baseMoney = 100;
  jobMoney = yearMoney = bonus = 0;
}

char* getName::Staff(){
  return name;
}

char* getSex::Staff(){
  return sex;
}

char* getJob::Staff(){
  return job;
}

char* getAge::Staff(){
  return age;
}

char* getWorkTime::Staff(){
  return workTime;
}

void setName::Staff(char* t_name){
  name = t_name;
}

void setJobMoney::Staff(int m){
  jobMoney = m;
}

void setYearMoney::Staff(int m){
  yearMoney = m;
}

void setBonus::Staff(int m){
  bonus = m;
}

void setJob::Staff(char* t_job){
  job = t_job;
}

int getWages::Staff(){
  return baseMoney + jobMoney + yearMoney + bonus;
}