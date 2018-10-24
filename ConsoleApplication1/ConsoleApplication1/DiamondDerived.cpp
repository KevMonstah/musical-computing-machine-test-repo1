#include "DiamondDerived.h"
#include <iostream>
using namespace std;

int DiamondDerived::sDDerObjCount = 0;
int DiamondDerived2::sDDer2ObjCount = 0;
int DiamondDerived3::sDDer3ObjCount = 0;

DiamondDerived::DiamondDerived(void)
{
	cout << "DiamondDerived::DiamondDerived(void)" << endl;
	++sDDerObjCount;
	cout << "DiamondDerived::DiamondDerived(void), objCount is " << sDDerObjCount << endl;
}

DiamondDerived::~DiamondDerived(void)
{
	cout << "DiamondDerived::~DiamondDerived(void)" << endl;
	--sDDerObjCount;
	cout << "DiamondDerived::~DiamondDerived(void), objCount is " << sDDerObjCount << endl;
}

DiamondDerived::DiamondDerived(const DiamondDerived& dd)
{
	cout << "DiamondDerived::DiamondDerived(const DiamondDerived& dd)" << endl;
	++sDDerObjCount;
	cout << "DiamondDerived::DiamondDerived(const DiamondDerived& dd), objCount is " << sDDerObjCount << endl;
}

DiamondDerived & DiamondDerived::operator = (const DiamondDerived &nd)
{
	cout << "DiamondDerived::DiamondDerived & operator = (const DiamondDerived &nd)" << endl;
	return *this;
}

void
DiamondDerived::printMe(void)
{
	cout << "I'm in DiamondDerived::printMe" << endl;
}

DiamondDerived2::DiamondDerived2(void)
{
	cout << "DiamondDerived2::DiamondDerived2(void)" << endl;
	++sDDer2ObjCount;
	cout << "DiamondDerived2::DiamondDerived2(void), objCount is " << sDDer2ObjCount << endl;
}

DiamondDerived2::~DiamondDerived2(void)
{
	cout << "DiamondDerived2::~DiamondDerived2(void)" << endl;
	--sDDer2ObjCount;
	cout << "DiamondDerived2::~DiamondDerived2(void), objCount is " << sDDer2ObjCount << endl;
}

DiamondDerived2::DiamondDerived2(const DiamondDerived2& dd)
{
	cout << "DiamondDerived2::DiamondDerived2(const DiamondDerived2& dd)" << endl;
	++sDDer2ObjCount;
	cout << "DiamondDerived2::DiamondDerived2(const DiamondDerived2& dd), objCount is " << sDDer2ObjCount << endl;
}

DiamondDerived2 & DiamondDerived2::operator = (const DiamondDerived2 &nd)
{
	cout << "DiamondDerived2::DiamondDerived2 & operator = (const DiamondDerived2 &nd)" << endl;
	return *this;
}

void
DiamondDerived2::printMe(void)
{
	cout << "I'm in DiamondDerived2::printMe" << endl;
}

DiamondDerived3::DiamondDerived3(void)
{
	cout << "DiamondDerived3::DiamondDerived3(void)" << endl;
	++sDDer3ObjCount;
	cout << "DiamondDerived3::DiamondDerived3(void), objCount is " << sDDer3ObjCount << endl;
}

DiamondDerived3::~DiamondDerived3(void)
{
	cout << "DiamondDerived3::~DiamondDerived3(void)" << endl;
	--sDDer3ObjCount;
	cout << "DiamondDerived3::~DiamondDerived3(void), objCount is " << sDDer3ObjCount << endl;
}

DiamondDerived3::DiamondDerived3(const DiamondDerived3& dd)
{
	cout << "DiamondDerived3::DiamondDerived3(const DiamondDerived3& dd)" << endl;
	++sDDer3ObjCount;
	cout << "DiamondDerived3::DiamondDerived3(const DiamondDerived3& dd), objCount is " << sDDer3ObjCount << endl;
}

DiamondDerived3 & DiamondDerived3::operator = (const DiamondDerived3 &nd)
{
	cout << "DiamondDerived3::DiamondDerived3 & operator = (const DiamondDerived3 &nd)" << endl;
	return *this;
}

void
DiamondDerived3::printMe(void)
{
	cout << "I'm in DiamondDerived3::printMe" << endl;
}





// class template:
//template <class T>
//class mycontainer {
//    T element;
//  public:
//    mycontainer (T arg) {element=arg;}
//    T increase () {return ++element;}
//};

/*
// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};
*/
//int main () {
//  mycontainer<int> myint (7);
//  mycontainer<char> mychar ('j');
//  cout << myint.increase() << endl;
//  cout << mychar.uppercase() << endl;
//  return 0;
//}

template <typename T>
//template <>
//class myTemplate <char> {
myTemplate<T>::myTemplate(T inp)// Test<T>&
{
	a = inp;
	cout << "myTemplate cons" << endl;
}

/*
template <typename T>
myTemplate<T>::myTemplate(const T& inp)
{
	a = inp;
	cout << "myTemplate constructor" << endl;
}

template<typename T>
myTemplate<T>::~myTemplate()
{
	cout << "myTemplate destructor" << endl;
}
*/
template<typename T>
void myTemplate<T>::print(void)
{
	cout << "print:: a = " << a << endl;
}
