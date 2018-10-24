#pragma once


class DiamondBase
{
public:
	static int sDBaseObjCount;
	DiamondBase(void);
	DiamondBase(const DiamondBase& db);
	DiamondBase & operator = (const DiamondBase &nb);
	virtual ~DiamondBase(void);
	virtual void printMe(void);

};

