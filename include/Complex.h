#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double real;
	double img;
public:
	Complex(double a,double b);
//	Complex(Complex& a);    // the copy constructor
	double re();
	double im();
	void set_re(double a);
	void set_im(double a);
	Complex operator + (Complex a);
	Complex operator * (Complex a);
	Complex operator - (Complex a);
	Complex operator - ();
	Complex operator / (Complex a);
	Complex pow(int n);    // return the integer power
	void print();
};


#endif
