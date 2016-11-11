#include "stdafx.h"
#include "Staff.h"

Staff::Staff(string t_name, string t_age,string t_sex, string t_worktime)
: name(t_name),age(t_age),sex(t_sex),workTime(t_worktime)
{
  baseMoney = 0;
  jobMoney = yearMoney = bonus = 0;
}

Staff::~Staff(){

}

string Staff::getName(){
  return name;
}

string Staff::getSex(){
  return sex;
}

string Staff::getJob(){
  return job;
}

string Staff::getAge(){
  return age;
}

string Staff::getWorkTime(){
  return workTime;
}


void Staff::setJobMoney(int m){
  jobMoney = m;
}

void Staff::setBaseMoney(int m){
	baseMoney = m;
}

void Staff::setYearMoney(int m){
  yearMoney = m;
}

int Staff::getBonus()
{
	return bonus;
}

int Staff::getJobMoney()
{
	return jobMoney;
}

int Staff::getBaseMoney()
{
	return baseMoney;
}

int Staff::getYearMoney()
{
	return yearMoney;
}

void Staff::setBonus(int m){
  bonus = m;
}

void Staff::setJob(string t_job){
  job = t_job;
}

int Staff::getMoney()
{
	return 0;
}

void Staff::setMoney()
{
}

