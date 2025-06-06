#ifndef CPPSCORE_H
#define CPPSCORE_H

#include<iostream>
using namespace std;

class CPPScore
{
	public:
		CPPScore(double, double, double);
		void PrintScore();
	protected:
		double Homework;
		double Experiment;
		double Exam;
		double Average;
};

#endif
