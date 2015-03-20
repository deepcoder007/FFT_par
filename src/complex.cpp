

Complex::Complex(int a=0,int b=0)
{
	real = a;
	img = b;
}

float Complex::re()
{
	return real;
}

float Complex::im()
{
	return img;
}

void Complex::set_re(float a)
{
	real=a;
}

void Complex::set_im(float a)
{
	img = a;
}

Complex Complex::operator + (A a)
{
	return Complex(real+a.re(),img+a.im());
}

Complex Complex::operator - (A a)
{
	return Complex(real-a.re(),img-a.im());
}

Complex Complex::operator - ()
{
	return Complex(-real,-img)
}

Complex Complex::operator * (A a)
{
	return Complex( real*a.re() - img*a.im(), real*a.im() + img*a.re() );
}

