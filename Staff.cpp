#include "Staff.h"

Staff::Staff(char* t_name, char* t_age,char* t_sex, char* t_worktime)
: name(t_name),age(t_age),sex(t_sex),workTime(t_worktime)
{
  baseMoney = 100;
  jobMoney = yearMoney = bonus = 0;
}

char* Staff::getName(){
  return name;
}

char* Staff::getSex(){
  return sex;
}

char* Staff::getJob(){
  return job;
}

char* Staff::getAge(){
  return age;
}

char* Staff::getWorkTime(){
  return workTime;
}

void Staff::setName(char* t_name){
  name = t_name;
}

void Staff::setJobMoney(int m){
  jobMoney = m;
}

void Staff::setYearMoney(int m){
  yearMoney = m;
}

void Staff::setBonus(int m){
  bonus = m;
}

void Staff::setJob(char* t_job){
  job = t_job;
}

int Staff::getWages(){
  return baseMoney + jobMoney + yearMoney + bonus;
}