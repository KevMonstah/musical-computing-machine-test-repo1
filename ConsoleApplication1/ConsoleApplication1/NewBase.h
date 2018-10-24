#pragma once

#include <iostream>
using namespace std;

class NewBase
{
protected:
	int A;
public:
	NewBase(void);
	virtual ~NewBase(void);
	NewBase(const NewBase &inArg);
	NewBase(const int &inVal);
	NewBase & operator = (const NewBase &nb);
	friend istream &operator >> (istream &stream, NewBase &nb);
	friend ostream &operator << (ostream &stream, NewBase &nb);
//	inline int getA(void) { return A;};
//	inline void setA(int inValue) { A = inValue; };
	virtual int getA(void) = 0;
	virtual void setA(int inValue) = 0; 
	void printMe(void);


};
