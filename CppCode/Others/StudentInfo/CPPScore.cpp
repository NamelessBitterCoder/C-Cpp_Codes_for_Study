#include "CPPScore.h"

CPPScore::CPPScore(double hw, double exp, double exam)
{
	Homework = hw;
	Experiment = exp;
	Exam = exam;
	Average = 0.2 * Homework + 0.1 * Experiment + 0.7 * Exam;
}

void CPPScore::PrintScore()
{
	cout << "CPP Score" << "    " 
		 << "Homework:" << Homework << "    "
		 << "Experiment:" << Experiment << "    "
		 << "Exam:" << Exam << "    "
		 << "Average:" << Average << endl;
}

