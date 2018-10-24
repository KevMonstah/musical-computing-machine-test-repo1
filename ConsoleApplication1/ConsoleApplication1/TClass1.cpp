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

//template<typename T>
//T
//TClass1<T>::getValue(void) //T& outVal)
//{
//	return value;
////	outVal = value;
//}
