#include"polynomial.h"
#include"Complex.h"
#include<vector>
#include<set>
#include<cmath>
#include<iostream>
using namespace std;

extern int max(int a,int b);
extern void prn(vector<Complex> v);

vector<Complex> get_coeff(polynomial p)
{
	vector<Complex> out;
	int n=p.get_degree();
	for(int i=0;i<n ; i++)
	{
		out.push_back( Complex(p.get_coeff(i),0) );
	}
	return out;
}

static int level=0;

vector<Complex> recur_FFT(vector<Complex> a)
{
	level++;
	vector<Complex> out;
	out.resize(a.size(),Complex(0.0,0.0));
	int i;
	if( a.size() == 1 )   // if only the constatn element
	{
		out.clear();
		out.push_back(a[0]);
		level--;
		return out;
	}
	Complex omega_n( cos( 2*M_PI/a.size() ),sin( 2*M_PI/a.size() ) );
	Complex omega( 1,0 );
	vector<Complex> a0,a1;
	for( int i=0; i<a.size(); i++)
	{
		if( (i%2)== 0 )
			a0.push_back(a[i]);
		else
			a1.push_back(a[i]);
	}
	vector<Complex> y0= recur_FFT(a0);
	vector<Complex> y1= recur_FFT(a1);
	int k;
	for( k = 0 ; k< (a.size()/2) ; k++ )
	{
		out[k] = y0[k]+omega*y1[k];
		out[k+a.size()/2] = y0[k]-omega*y1[k];
		omega = omega*omega_n;
	}
	return out;
}

vector<Complex> un_recur_FFT(vector<Complex> a)
{
	level++;
	vector<Complex> out;
	out.resize(a.size(),Complex(0.0,0.0));
	int i;
	if( a.size() == 1 )   // if only the constatn element
	{
		out.clear();
		out.push_back(a[0]);
		level--;
		return out;
	}
	Complex omega_n( cos( -2*M_PI/a.size() ),sin( -2*M_PI/a.size() ) );  // A change on this line
	Complex omega( 1,0 );
	vector<Complex> a0,a1;
	for( int i=0; i<a.size(); i++)
	{
		if( (i%2)== 0 )
			a0.push_back(a[i]);
		else
			a1.push_back(a[i]);
	}
	vector<Complex> y0= un_recur_FFT(a0);
	vector<Complex> y1= un_recur_FFT(a1);
	int k;
	for( k = 0 ; k< (a.size()/2) ; k++ )
	{
		out[k] = y0[k]+omega*y1[k];
		out[k+a.size()/2] = y0[k]-omega*y1[k];
		omega = omega*omega_n;
	}
	return out;
}
 
vector<Complex> rev_FFT(vector<Complex> a)
{
	vector<Complex> out;
	out = un_recur_FFT(a);
	// now subtract n
	for( int i=0 ; i<a.size() ; i++ )
	{
		out[i]=out[i]/Complex(a.size(),0);
	}
	return out;
}

	
// multiply using the fast fourier transform method
polynomial multiply_fft(polynomial a,polynomial b)
{
	int i;
	int n1=a.get_degree();
	int n2=b.get_degree();
	int n=max(n1,n2)*2;
	a.set_degree(n);
	b.set_degree(n);
	vector<Complex> v1= recur_FFT(get_coeff(a));
	vector<Complex> v2= recur_FFT(get_coeff(b));
	vector<Complex> ans;
	for( i=0 ; i<n; i++)
	{
		ans.push_back(v1[i]*v2[i]);
	}
	vector<Complex> ans2= rev_FFT(ans);
	polynomial tmp(n);
	for( i=0 ; i<n;i++)
	{
		tmp.set_coeff(i,ans2[i].re());
	}
	return tmp;
}
