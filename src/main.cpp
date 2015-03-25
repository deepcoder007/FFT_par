#include"polynomial.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

extern polynomial multiply(polynomial a,polynomial b);

int main()
{
	cout<<"Program started : "<<endl;
	int n=1000;
	polynomial a(n);
	polynomial b(n);
	a.set_coeff(0,10);
	a.set_coeff(1,10);
	a.set_coeff(2,10);
	a.set_coeff(3,10);
	b.set_coeff(0,10);
	b.set_coeff(1,10);
	b.set_coeff(2,10);
	b.set_coeff(3,10);
	multiply(a,b);
}


