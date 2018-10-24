#pragma once
#include "diamondbase.h"
class DiamondDerived :
	virtual public DiamondBase
{
public:
	static int sDDerObjCount;
	DiamondDerived(void);
	DiamondDerived(const DiamondDerived& dd);
	DiamondDerived & operator = (const DiamondDerived &nd);
	virtual ~DiamondDerived(void);
	virtual void printMe(void);
};

class DiamondDerived2 :
	virtual public DiamondBase
{
public:
	static int sDDer2ObjCount;
	DiamondDerived2(void);
	DiamondDerived2(const DiamondDerived2& dd);
	DiamondDerived2 & operator = (const DiamondDerived2 &nd);
	virtual ~DiamondDerived2(void);
	virtual void printMe(void);
};

class DiamondDerived3 :
	public DiamondDerived, public DiamondDerived2
{
public:
	static int sDDer3ObjCount;
	DiamondDerived3(void);
	DiamondDerived3(const DiamondDerived3& dd);
	DiamondDerived3 & operator = (const DiamondDerived3 &nd);
	virtual ~DiamondDerived3(void);
	virtual void printMe(void);
};

//template <class T>
//class mypair {
//    T a, b;
//  public:
//    mypair (T first, T second)
//      {a=first; b=second;}
//    T getmax ();
//d};

template <typename T>
class myTemplate
{
private:
	T a;
public:
	//myTemplate(const T& inp);
	myTemplate(T inp);
	//~myTemplate();
	void print(void);

	//myTemplate(const myTemplate& myTemp);
	//myTemplate & operator = (const myTemplate& myTemp);
};
