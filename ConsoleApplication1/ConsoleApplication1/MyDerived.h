#pragma once
#include "mybase.h"
#include <iostream>

using namespace std;

class MyDerived :
	public MyBase
{
public:
	MyDerived(void);
	virtual ~MyDerived(void);
	void show(void);
};

