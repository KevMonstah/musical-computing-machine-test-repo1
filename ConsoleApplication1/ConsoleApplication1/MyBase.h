#pragma once

#include <iostream>

using namespace std;

class MyBase
{
public:
	MyBase(void);
	virtual ~MyBase(void);
	virtual void show();
	friend ostream &operator << (ostream &stream, MyBase &mb);
};

