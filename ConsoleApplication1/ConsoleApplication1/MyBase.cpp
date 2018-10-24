#include "MyBase.h"
#include <iostream>

using namespace std;

MyBase::MyBase(void)
{
	cout<<"In MyBase::MyBase \n";
}


MyBase::~MyBase(void)
{
	cout<<"In MyBase::~MyBase \n";
}

void MyBase::show(void)
{
	cout<<"In MyBase::show \n";
}

ostream &operator << (ostream &stream, MyBase &mb)
{
	stream << "MyBase" << endl;
	return stream;
}

