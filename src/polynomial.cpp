#include"polynomial.h"


polynomial::polynomial(int n=1)
{
	degree=n;
	coeff = new int[n+1];
}

float polynomial::get_coeff(int n)
{
	if( n> degree )
		return 0;
	else 
		return coeff[n];
}

void polynomial::set_coeff(int n,float v)
{
	if( n > degree )
		return;
	else
		return coeff[n]=v;
}


