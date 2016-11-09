#pragma once
#include "Staff.h"

class MiddleManager : public Staff{
public:
 MiddleManager(string, string,string, string);

 int getMoney();
 void setMoney(int, int);
};