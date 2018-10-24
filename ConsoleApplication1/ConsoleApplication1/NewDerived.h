#pragma once
#include "newbase.h"
#include <iostream>
using namespace std;

class NewDerived :
	public NewBase
{
protected:
	int B;
public:
	NewDerived(void);
	virtual ~NewDerived(void);
	NewDerived(const NewDerived &inArg);
	NewDerived(const int &inVal);
	NewDerived & operator = (const NewDerived &nd);
	friend istream &operator >> (istream &stream, NewDerived &nd);
	friend ostream &operator << (ostream &stream, NewDerived &nd);
	inline int getB(void) { return B;};
	inline void setB(int inValue) { B = inValue; };
	int getA(void);
	void setA(int inValue); 

};

