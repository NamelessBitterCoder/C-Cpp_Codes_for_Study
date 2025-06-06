#include"CPPScore.h"
#include"StudentInfo.h"

int main(int argc, char** argv) {
	StudentInfo s1("Denny", "SDSE", 101, 90, 90, 85);
	s1.PrintInfo();
	StudentInfo s2("Nancy", "Fashion Design", 102, 100, 94.5, 80);
	s2.PrintInfo();
	return 0;
}
