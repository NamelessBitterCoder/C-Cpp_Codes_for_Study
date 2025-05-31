#include "Cat.h"
#include<iostream>
using namespace std;

int Cat::GetAge()
{
	return itsAge;
}

void Cat::SetAge(int age)
{
	itsAge = age;
}

void Cat::Meow()
{
	cout << "Meow.\n";
}
