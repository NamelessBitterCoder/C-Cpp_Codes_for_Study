#include "StudentInfo.h"

StudentInfo::StudentInfo(string name, string dept, int id, double hw, double exp, double exm):Score(hw, exp, exm)
{
	Name = name;
	Dept = dept;
	ID = id;
}

void StudentInfo::PrintInfo()
{
	cout << "Name:" << Name << "    "
	     << "Department:" << Dept << "    "
		 << "ID:" << ID << endl;
	Score.PrintScore(); 
}
