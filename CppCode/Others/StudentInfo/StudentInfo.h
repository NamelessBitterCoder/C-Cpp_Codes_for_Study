#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include<iostream>
#include<cstring>
#include"CPPScore.h"
using namespace std;

class StudentInfo
{
	public:
		StudentInfo(string, string, int, double, double, double);
		void PrintInfo();
	protected:
		string Name;
		string Dept;
		int ID;
		CPPScore Score;
};

#endif
