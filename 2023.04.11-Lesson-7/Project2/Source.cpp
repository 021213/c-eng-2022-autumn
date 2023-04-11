#include<iostream>

class A
{
public:
	int a;
};

class B : public A {
public:
	int b;
};

int sum(A a1, A a2)
{
	return a1.a + a2.a;
}

int sum(B b1, B b2)
{
	return b1.a + b2.a;
}

int main(int argc, char* argv[])
{
	A a1; A a2; B b1; B b2;
	std::cout << sum(a1, a2);
	std::cout << sum(b1, b2);
	std::cout << sum(a1, b2);
	return 0;
}