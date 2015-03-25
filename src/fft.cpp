#include"polynomial.h"
#include"Complex.h"
#include<vector>
#include<set>
#include<cmath>


vector<Complex> recur_FFT(vector<Complex> a)
{
	vector<Complex> out;
	int i;
	if( a.size() == 1 )
	{
		out.push_back(a[0]);
		return 0;
	}
	Complex omega_n( cos( 2*M_PI/a.size() ),sin( 2*M_PI/a.size() ) );
	Complex omega( 1,0 );
	vector<Complex> a0,a1;
	for( i=0; i<a.size(); i++)
	{
		if( i%2== 0 )
			a0.push_back(a[i]);
		else
			a1.push_back(a[i]);
	}
	vector<Complex> y0= recur_FFT(a0);
	vector<Complex> y1= recur_FFT(a1);
	vecotr<Complex> y(a.size());
	int k;
	for( k = 0 ; k< (a.size()/2-1) ; k++ )
	{
		y[k] = y0[k]+omega*y1[k];
		y[k+a.size()/2] = y0[k]-omega*y1[k];
		omega = omega*omega_n;
	}
	return y;
}


	





// multiply using the fast fourier transform method
polynomial multiply_fft(polynomial a,polynomial b)
{
	int n1=a.get_degree();
	int n2=b.get_degree();
	int n=max(n1,n2)*2;




}
