#pragma once
#include<cmath>
#include<ostream>
class Complex {
private:
	double re;
	double im;
	Complex fromAbsArg(double abs, double arg) const
	{
		return Complex(abs * cos(arg), abs * sin(arg));
	}
	double abs2() const
	{
		return re * re + im * im;
	}

	char signIm() const
	{
		return (im >= 0 ? '+' : '-');
	}
	double absIm() const
	{
		return (im >= 0 ? im : -im);
	}

public:
	Complex(double re = 0, double im = 0)
		: re(re), im(im) {}
	Complex(const Complex& c)
		: re(c.re), im(c.im) {}
	~Complex() {};

	Complex conj()
	{
		return Complex(re, -im);
	}
	double arg() const
	{
		return atan2(im, re);
	}
	double abs() const 
	{
		return sqrt(abs2());
	}

	Complex operator+(double d)
	{
		return Complex(re + d, im);
	}
	Complex operator-(double d)
	{
		return Complex(re - d, im);
	}
	Complex operator/(double d)
	{
		return Complex(re / d, im / d);
	}
	Complex operator*(double d)
	{
		return Complex(re * d, im * d);
	}

	friend Complex operator+(double d, Complex c)
	{
		return Complex(c.re + d, c.im);
	}
	friend Complex operator-(double d, Complex c)
	{
		return Complex(c.re - d, c.im);
	}
	friend Complex operator*(double d, Complex c)
	{
		return Complex(c.re / d, c.im / d);
	}
	friend Complex operator/(double d, Complex c)
	{
		return Complex(c.re * d, c.im * d);
	}

	Complex operator+(Complex c)
	{
		return Complex(re + c.re, im + c.im);
	}
	Complex operator-(Complex c)
	{
		return Complex(re - c.re, im - c.im);
	}
	Complex operator*(Complex c)
	{
		return fromAbsArg(abs() * c.abs(), arg() + c.arg());
	}
	Complex operator/(Complex c)
	{
		return *this * c.conj() / c.abs2();
	}

	friend std::ostream& operator<<(std::ostream& stream, const Complex& c)
	{
		stream << c.re << " " << c.signIm() << " " << c.absIm() << " * i = ";
		stream << c.abs() << " * e ^ (" << c.arg() << " * i)";
		return stream;
	}
};