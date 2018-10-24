#pragma once

#include <iostream>

using namespace std;

class Fraction
{

private:

	long mNumerator;
	long mDenominator;

	void Reduce(void);
	long FindGCD(long n, long d);

public:
	//void Reduce(void);

	Fraction(void);
	Fraction(const long inNum, const long inDenom);
	Fraction(const Fraction& inFrac);  //copy
	~Fraction(void);  // not needed to be virtual, because no intent to derive from at present, and no 
	                  // memory manipulation either

	// simple member access functions, inline here rather than in implementation file
	inline long GetNumerator(void) { return mNumerator; };
	inline long GetDenominator(void) { return mDenominator; };
	void SetNumerator(long inNum);  // this too
	void SetDenominator(long inDenom);  // this one a little more complicated, can't inline

	friend istream &operator >> (istream &stream, Fraction &nb);
	friend ostream &operator << (ostream &stream, Fraction &nb);

	Fraction &operator = (const Fraction &inFrac);  // assignment
	Fraction operator *(const Fraction& rightOp) const;
	Fraction operator *=(const Fraction& rightOp);
	Fraction operator *(long inInt) const;
	Fraction operator *=(long inInt);
	friend Fraction operator *(long inVal, const Fraction& rightOp);

};

