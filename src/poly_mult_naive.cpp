#include"polynomial.h"

int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

polynomial multiply(polynomial a,polynomial b)
{
	int n1=a.get_degree();
	int n2=b.get_degree();
	int n=max(n1,n2)*2;
	polynomial p(n);    // the new polynomial that we want to make
	int i,j,k;
	for( i=0; i<n; i++)   // the degree term loop
	{
		for( j=0; j<=i ; j++ )    // for each of the term in a
		{
			if( j>=a.get_degree() || (i-j)>=b.get_degree() )   // if corresponding degree does not exist
				continue;
			p.set_coeff( i , p.get_coeff(i) + a.get_coeff(j)*b.get_coeff(i-j) );
		}
	}
	return p;
}
