#include<iostream>
#include"Cat.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Cat frisky;
	frisky.SetAge(5);
	frisky.Meow();
	cout << "frisky is a cat who is "
	     << frisky.GetAge()
	     << " years old.\n";
	frisky.Meow();
	return 0;
}
