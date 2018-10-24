#include "Fraction.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// constructors
Fraction::Fraction(void) : 
	mNumerator(0), 
	mDenominator(0)
{
}


Fraction::Fraction(const long inNum, const long inDenom) : 
	mNumerator(inNum), 
	mDenominator(inDenom)
{
	// might reconsider not using member init list as i'm checking values, tbd
	if (mDenominator == 0) 
		throw invalid_argument("Denominator set to zero, invalid fraction.");

	if ((mNumerator < 0) & (mDenominator < 0))
	{
		mNumerator = -mNumerator;
		mDenominator = -mDenominator;
	}
	Reduce();
}


// copy cons
Fraction::Fraction(const Fraction& inFrac) 
{
	mNumerator = inFrac.mNumerator;
	mDenominator = inFrac.mDenominator;
}


// destructor
// not needed to be virtual, because no intent to derive from at present, and no
// memory manipulation either
Fraction::~Fraction(void)
{
}


// member function settors
void 
Fraction::SetNumerator(long inNum)
{
	if ((inNum < 0) && (mDenominator < 0))
	{
		mNumerator = -(inNum);
		mDenominator = -(mDenominator);
	}
	else
		mNumerator = inNum;
	Reduce();
}


void 
Fraction::SetDenominator(long inDenom)
{
	if (inDenom == 0)
		throw invalid_argument("Denominator set to zero, invalid fraction.");
	if ((inDenom < 0) && (mNumerator < 0))
	{
		mNumerator = -(mNumerator);
		mDenominator = -(inDenom);
	}
	else
		mDenominator = inDenom;
	Reduce();
}


// I/O operators
// force entry of a valid fraction here, could exception, or fail input instead
istream &operator >> (istream &stream, Fraction &inFrac)
{
	cout << "Enter a fraction using two longs, first a Numerator, then a Denominator." << endl;
	cout << "Enter the Numerator: ";
	stream >> inFrac.mNumerator;
	cout << "Enter the Denominator: ";
	stream >> inFrac.mDenominator;
	while (inFrac.mDenominator == 0)
	{
		cout << "Invalid fraction, zero not allowed as Denominator.  Re-enter Denominator:";
		stream >> inFrac.mDenominator;
	}
	cout << endl;
	inFrac.Reduce();
	return stream;
}


ostream &operator << (ostream &stream, Fraction &inFrac)
{
	stream << inFrac.mNumerator << "/" << inFrac.mDenominator << endl;
	return stream;
}


// assignment operator
Fraction& 
Fraction::operator = (const Fraction &inFrac)
{
	if (this != &inFrac)
	{
		mNumerator = inFrac.mNumerator;
		mDenominator = inFrac.mDenominator;
	}
	return *this;
}


// Fraction multiplier, frac * frac
Fraction
Fraction::operator * (const Fraction& right) const
{
	return Fraction((mNumerator * right.mNumerator), (mDenominator * right.mDenominator));
	Fraction rV((mNumerator * right.mNumerator), (mDenominator * right.mDenominator));
	rV.Reduce();
	return rV;
}


// Fraction multiplier, frac *= frac
Fraction
Fraction::operator *= (const Fraction& right)
{
	mNumerator *= right.mNumerator;
	mDenominator *= right.mDenominator;
	Reduce();
	return *this;
}


// Fraction multiplier, frac * int
Fraction
Fraction::operator * (long inVal) const
{
	Fraction rV((mNumerator * inVal), mDenominator);
	rV.Reduce();
	return rV;
	//return Fraction((mNumerator * inVal), mDenominator);
}


// Fraction multiplier, frac *= int
Fraction
Fraction::operator *= (long inVal) 
{
	mNumerator *= inVal;
	Reduce();
	return *this;
}


// Fraction multiplier, int * frac
Fraction operator * (long inVal, const Fraction& rightOp)
{
	Fraction rV((inVal * rightOp.mNumerator), rightOp.mDenominator);
	rV.Reduce();
	return rV;
	//return Fraction((inVal * rightOp.mNumerator), rightOp.mDenominator);
}


long
Fraction::FindGCD(long n, long d) 
{
	long retVal = 0;

	if (d == 0) retVal = n;
	else retVal = FindGCD(d, n % d);

	return retVal;
}

void
Fraction::Reduce(void)
{
	if (mNumerator) {
		
		long gcd = FindGCD(mNumerator, mDenominator);
		cout << "GCD is " << gcd << endl;
		mNumerator /= gcd;
		mDenominator /= gcd;
	}
}


// still got some troubling spots for finding gcd.
// how to return Fraction(...).Reduce()  ???

