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
extern polynomial multiply_fft_par(polynomial a,polynomial b);

void prn(vector<Complex> v)
{
	int i;
	for(i=0;i<v.size();i++)
	{
		v[i].print();
		cout<<endl;
	}
}

vector<int> power2;   // a vector to store the powers of 2

void print_file(FILE* ptr, polynomial p)
{
	int n=p.get_degree();
	for(int i=0;i<n;i++)
		if( p.get_coeff(i)>0.001 )
			fprintf(ptr,"%lf\n",p.get_coeff(i));
}



int main(int argc,char* argv[])
{
	cout<<"Program started : "<<endl;
	srand(time(NULL));
	int i;
	for(i=0;i<50;i++)
		power2.push_back(1<<i);
		/*
	int tmp=atoi(argv[1]);
	int n;
	for(i=0;i<50;i++)
	{
		if( power2[i]>=tmp )   
		{
			n=power2[i];
			break;
		}
	}
	*/
	vector<int>::iterator it;
	FILE* ptr;
	time_t t1,t2;
	cout<<"Naive\t\tFFT\t\tFFT(parallel)"<<endl;
	for( it = power2.begin() ; it!=power2.end() ; it++)
	{
		polynomial a(*it),a1(*it),a2(*it);
		polynomial b(*it),b1(*it),b2(*it);
		for(i=0;i<(*it);i++)
		{
			a.set_coeff(i,rand()%10000);
			a1.set_coeff(i,a.get_coeff(i));
			a2.set_coeff(i,a.get_coeff(i));
			b.set_coeff(i,rand()%10000);
			b1.set_coeff(i,b.get_coeff(i));
			b2.set_coeff(i,b.get_coeff(i));
		}
		polynomial out(100);
		t1=clock();
	   	out= multiply(a1,b1);
		t2=clock();
		cout<<t2-t1<<"\t\t";
		t1=clock();
		out =multiply_fft(a,b);
		t2=clock();
		cout<<t2-t1<<"\t\t";
		t1=clock();
		out= multiply_fft_par(a2,b2);
		t2=clock();
		cout<<t2-t1<<endl;
	}
}


