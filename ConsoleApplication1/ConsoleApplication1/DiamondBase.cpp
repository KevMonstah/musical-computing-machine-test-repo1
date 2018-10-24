#include "DiamondBase.h"
#include <iostream>
using namespace std;

int DiamondBase::sDBaseObjCount = 0;

DiamondBase::DiamondBase(void)
{
	cout << "DiamondBase::DiamondBase(void)" << endl;
	++sDBaseObjCount;
	cout << "DiamondBase::DiamondBase(void), objCount is " << sDBaseObjCount << endl;
}

DiamondBase::DiamondBase(const DiamondBase& db)
{
	cout << "DiamondBase::DiamondBase(const DiamondBase& db)" << endl;
	++sDBaseObjCount;
	cout << "DiamondBase::DiamondBase(void), objCount is " << sDBaseObjCount << endl;
}

DiamondBase & DiamondBase::operator = (const DiamondBase &nb)
{
	cout << "DiamondBase::DiamondBase & operator = (const DiamondBase &nb)" << endl;
	return *this;
}

DiamondBase::~DiamondBase(void)
{
	cout << "DiamondBase::~DiamondBase(void)" << endl;
	--sDBaseObjCount;
	cout << "DiamondBase::DiamondBase(void), objCount is " << sDBaseObjCount << endl;
}

void
DiamondBase::printMe(void)
{
	cout << "I'm in DiamondBase::printMe" << endl;
}
