#include "NewDerived.h"


NewDerived::NewDerived(void) : NewBase(10)
{
	cout << "inside NewDerived::NewDerived(void)" << endl;
	B = -1;
}

NewDerived::NewDerived(const int &inVal) : NewBase(inVal)
{
	cout << "inside NewDerived::NewDerived(const int &)" << endl;
	B = inVal;
}

NewDerived::NewDerived(const NewDerived &inArg)
{
	cout << "inside NewDerived::NewDerived(const NewDerived &)" << endl;
	A = inArg.A;
	B = inArg.B;
}

NewDerived::~NewDerived(void)
{
	cout << "inside NewDerived::~NewDerived" << endl;
}

istream &operator >> (istream &stream, NewDerived &nd)
{
	cout << "Enter value for A: ";
	stream >> nd.A;
	cout << "Enter value for B: ";
	stream >> nd.B;
	return stream;
}

ostream &operator << (ostream &stream, NewDerived &nd)
{
	stream << "Value A is: " << nd.A << endl;
	stream << "Value B is: " << nd.B << endl;
	return stream;
}

int NewDerived::getA(void) { return A; }

void NewDerived::setA(int inValue) { A = inValue; } 
 
NewDerived & NewDerived::operator = (const NewDerived &nd)
{
   // Check for self assignment
   if(this != &nd)
   {
     A = nd.A;
	 B = nd.B;
   }
 
   return *this;
}
