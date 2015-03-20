#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	float real;
	float img;
public:
	Complex(int a,int b);
	float re();
	float im();
	void set_re(float a);
	void set_im(float a);
	Complex operator + (A a);
	Complex operator * (A a);
	Complex operator - (A a);
	Complex operator - ();
	Complex operator / (A a);
	Complex pow(int n);    // return the integer power
};


#endif
