#include"polynomial.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;


polynomial::polynomial(int n=1)
{
	degree=n;
	coeff = new double[n+1];
}

float polynomial::get_coeff(int n)
{
	if( n>= degree )
		return 0;
	else 
		return coeff[n];
}

void polynomial::set_coeff(int n,float v)
{
	if( n >= degree )
		return;
	else
	{
		coeff[n]=v;
		return;
	}
}


int polynomial::get_degree()
{
	return degree;
}

void polynomial::print()
{
	cout<<"The coefficients are: ";
	int i;
	for(i=0;i<degree;i++)
	{
		cout<<coeff[i]<<" , ";
	}
	cout<<endl;
}
