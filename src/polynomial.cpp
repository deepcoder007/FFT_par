#include"polynomial.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int min(int a,int b)
{
	if( a<b ) return a;
	else return b;
}

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

void polynomial::set_coeff(int n,double v)
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

void polynomial::set_degree(int n)
{
	double* c2=new double[n+1];
	for(int i=0;i<=n; i++)
	{
		if( i>=degree )
			c2[i]=0.0;
		else
			c2[i]=coeff[i];
	}
	delete[] coeff;
	coeff = c2;
	degree = n;
}




