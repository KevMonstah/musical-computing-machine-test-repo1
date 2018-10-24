#include "NewBase.h"
#include <iostream>
using namespace std;


NewBase::NewBase(void)
{
	cout << "inside NewBase::NewBase(void)" << endl;
	A = -1;
}

NewBase::NewBase(const int &inVal)
{
	cout << "inside NewBase::NewBase(const int &)" << endl;
	A = inVal;
}

NewBase::NewBase(const NewBase &inArg)
{
	cout << "inside NewBase::NewBase(const NewBase &)" << endl;
	A = inArg.A;
}

NewBase::~NewBase(void)
{
	cout << "inside NewBase::~NewBase" << endl;
}

NewBase & NewBase::operator = (const NewBase &nb)
{
   // Check for self assignment
   if(this != &nb)
     A = nb.A;
 
   return *this;
}

istream &operator >> (istream &stream, NewBase &nb)
{
	cout << "Enter value: ";
	stream >> nb.A;
	return stream;
}

ostream &operator << (ostream &stream, NewBase &nb)
{
	stream << "Value is: " << nb.A << endl;
	return stream;
}

int NewBase::getA(void) { return A; }

void NewBase::setA(int inValue) { A = inValue; } 

void
NewBase::printMe(void)
{
	cout << "I'm in NewBase::printMe" << endl;
}
