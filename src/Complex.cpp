#include<cmath>
#include"Complex.h"
#include<iostream>
using namespace std;


Complex::Complex(double a=0,double b=0)
{
	real = a;
	img = b;
}

/*
Complex::Complex(Complex& a)
{
	this->real = a.re();
	this->img = a.im();
}
*/

double Complex::re()
{
	return real;
}

double Complex::im()
{
	return img;
}

void Complex::set_re(double a)
{
	real=a;
}

void Complex::set_im(double a)
{
	img = a;
}

Complex Complex::operator + (Complex a)
{
	return Complex(real+a.re(),img+a.im());
}

Complex Complex::operator - (Complex a)
{
	return Complex(real-a.re(),img-a.im());
}

Complex Complex::operator - ()
{
	return Complex(-real,-img);
}

Complex Complex::operator * (Complex a)
{
	return Complex( real*a.re() - img*a.im(), real*a.im() + img*a.re() );
}

Complex Complex::operator / (Complex a)
{
	return Complex( (real*a.re() + img*a.im())/( a.re()*a.re() + a.im()*a.im()) , ( img*a.re() - real*a.im() )/ ( a.re()*a.re() + a.im()*a.im() ) );
}

Complex Complex::pow(int n)
{
	double r = sqrt( real*real + img*img );
	double cd = acos(real/r) ;
	double sd = asin(img/r);
	double ans=1;
	int i;
	for(i=0;i<n;i++) ans*=r;
	return Complex( ans*cos(n*cd) , ans*sin(n*sd) );
}


void Complex::print()
{
	cout<<" "<<real<<"+j"<<img;
}
