#include"polynomial.h"
#include"Complex.h"
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
using namespace std;

extern polynomial multiply(polynomial a,polynomial b);
extern vector<Complex> get_coeff(polynomial p);
extern vector<Complex> recur_FFT(vector<Complex> v);
extern polynomial multiply_fft(polynomial a,polynomial b);

void prn(vector<Complex> v)
{
	int i;
	for(i=0;i<v.size();i++)
	{
		v[i].print();
		cout<<endl;
	}
}

int main(int argc,char* argv[])
{
	cout<<"Program started : "<<endl;
	int n=atoi(argv[1]);
	polynomial a(n);
	polynomial b(n);
	a.set_coeff(0,11);
	a.set_coeff(1,14);
	a.set_coeff(2,16);
	a.set_coeff(3,1);
	b.set_coeff(0,10);
	b.set_coeff(1,10);
	b.set_coeff(2,10);
	b.set_coeff(3,10);
//	a.print();
//	b.print();
	cout<<"-------------------------"<<endl;
	cout<<"Naive: "<<endl;
//	multiply(a,b).print();
	cout<<"-------------------------"<<endl;
	cout<<"FFT: "<<endl;
	multiply_fft(a,b).print();
	cout<<"-------------------------"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"-------------------------"<<endl;
}


