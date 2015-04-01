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
	srand(time(NULL));
	int i;
	for(i=0;i<50;i++)
		power2.push_back(1<<i);
	cout<<"Program started : "<<endl;
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
	polynomial a(n),a1(n),a2(n);
	polynomial b(n),b1(n),b2(n);
	for(i=0;i<n;i++)
	{
		a.set_coeff(i,rand()%10000);
		a1.set_coeff(i,a.get_coeff(i));
		a2.set_coeff(i,a.get_coeff(i));
		b.set_coeff(i,rand()%10000);
		b1.set_coeff(i,b.get_coeff(i));
		b2.set_coeff(i,b.get_coeff(i));
	}
	FILE* ptr;
	polynomial out(100);
	time_t t1,t2;
	cout<<"-------------------------"<<endl;
	cout<<"Naive: "<<endl;
	t1=clock();
   	out= multiply(a1,b1);
	t2=clock();
	ptr=fopen("naive.txt","w");
	print_file(ptr,out);
	fclose(ptr);
	//out.print();
	cout<<"Time taken by naive method : "<<t2-t1<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"FFT: "<<endl;
	t1=clock();
	out =multiply_fft(a,b);
	t2=clock();
	ptr=fopen("fft.txt","w");
	print_file(ptr,out);
	fclose(ptr);
	//out.print();
	cout<<"Time taken by FFT :  "<<t2-t1<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"FFT(parallel):  "<<endl;
	t1=clock();
	out= multiply_fft_par(a2,b2);
	t2=clock();
	ptr=fopen("fft_par.txt","w");
	print_file(ptr,out);
	fclose(ptr);
	//out.print();
	cout<<"Time taken by FFT in parallel: "<<t2-t1<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"-------------------------"<<endl;
}


