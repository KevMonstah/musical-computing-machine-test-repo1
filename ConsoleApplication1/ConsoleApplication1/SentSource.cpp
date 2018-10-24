
#include "Fraction.h"

#include<iostream>
#include <stdexcept>

using namespace std;

int main( int argc, char *argv[])
{

    Fraction a;
	cout << "Fraction a [noargs]: " << a << endl;

	Fraction b(4, 7);
	cout << "Fraction b [4,7]: " << b << endl;

	Fraction c;
	cout << "Fraction c [noargs]: " << c << endl;

	c = b;
	cout << "Fraction c [c=b]:" << c << endl;

	c = c;
	cout << "Fraction c [c=c]: " << c << endl;

	Fraction d(b);
	cout << "Fraction d [b]: " << d << endl;

	Fraction e;
	cin >> e;
	cout << "Fraction e: " << e << endl;

	Fraction f;
	cout << "Fraction f [noargs]: " << f << endl;
	f = b * e;
	cout << "Fraction f [b*e]: " << f << endl;

	Fraction* pf = new Fraction(11,13);
	cout << "Fraction pf [11,13]: " << *pf << endl;
	if (pf) delete pf;

	Fraction g(7,8);
	cout << "Fraction g [7,8]: " << g << endl;
	g = g * 4;
	cout << "Fraction g [g*4]: " << g << endl;

	Fraction h(10,12);
	cout << "Fraction h [10,12]: " << g << endl;
	h = 3 * h;
	cout << "Fraction h [3*h]: " << h << endl;
	
	Fraction m(2,3);
	cout << "Fraction m [2,3]: " << m << endl;
	Fraction n;
	cout << "Fraction n [noargs]: " << n << endl;
	m *= n;
	cout << "Fraction m [m*=n]: " << m << endl;

	Fraction r(-7,-10);
	cout << "Fraction r [7,10]: " << r << endl;
	Fraction s(2,-3);
	cout << "Fraction s [2,3]: " << s << endl;
	r *= s;
	cout << "Fraction r [r*=s]: " << r << endl;

	Fraction w;
	cout << "Fraction w [noargs]: " << w << endl;
	w.SetNumerator(8);
	w.SetDenominator(9);
	cout << "Fraction w [num=8,denom=9]: " << w << endl;
	Fraction x(1,2);
	cout << "Fraction x [1,2]: " << x << endl;
	try {
		cout << "try setting x denominator to zero." << endl;
		x.SetDenominator(0);
	}
	catch (invalid_argument &ex) {
		cout << ex.what() << endl;
	}

	Fraction z1(-1,2);
	cout << "Fraction z1 [-1,2]: " << z1 << endl;
	z1.SetDenominator(-2);
	cout << "Fraction z1 [set denom=-2]: " << z1 << endl;
	Fraction z2(-1, -2);
	cout << "Fraction z2 [-1,-2]: " << z2 << endl;
	Fraction z3(1,-2);
	cout << "Fraction z3 [1,-2]: " << z3 << endl;
	z3.SetNumerator(-2);
	cout << "Fraction z3 [set num=-2]: " << z3 << endl;
	Fraction z4(0,4);
	cout << "Fraction z4 [0,4]: " << z4 << endl;
	Fraction z5(-4,-8);
	cout << "Fraction z5 [-4,-8]: " << z5 << endl;
	try {
		cout << "Try to create Fraction z6 [-4,0], expect error " << endl;
		Fraction z6(-4,0);
		cout << "Fraction z6 [-4,0]: " << z6 << endl;
	}
	catch (invalid_argument &ex) {
		cout << ex.what() << endl;
	}

	return 0;
}