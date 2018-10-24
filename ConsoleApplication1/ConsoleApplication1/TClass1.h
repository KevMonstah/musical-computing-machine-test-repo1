#pragma once

template<class T>
class TClass1
{
private:
	T value;
public:
	TClass1(void);
	virtual ~TClass1(void);
	T getValue(void);
	void setValue(T inVal);
};

#include "TClass1.h"

template<class T>
TClass1<T>::TClass1(void)
{
}


template<class T>
TClass1<T>::~TClass1(void)
{
}

	
template<class T>
void TClass1<T>::setValue(T inVal)
{
	value = inVal;
}

template<typename T>
T
TClass1<T>::getValue(void) //T& outVal)
{
	return value;
	//outVal = value;
}
