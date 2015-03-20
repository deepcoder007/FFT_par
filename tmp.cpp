#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class A
{
public:
	void operator ^ (A a);
};

void A::operator ^(A a)
{
	cout<<"Operator overloading"<<endl;
}



int main()
{
	A a,b;
	a^b;
	return 0;
}

