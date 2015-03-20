#ifndef POLY_H
#define POLY_H


class polynomial
{
private:
	int degree;
	double* coeff;    // store coefficient according to the power of x
public:
	polynomial(int n);
	float get_coeff(int n);   // returns the coeff. to the corresponding power
	void set_coeff(int n,float v);     // set the coefficient
};

#endif
