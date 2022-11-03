#include<iostream>

int sum(int = 0, int = 0, int = 0, int = 0);

float sum(float, float, float, float);

void calc(int, int, int* = nullptr, int* = nullptr, int* = nullptr, int* = nullptr);

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

int main(int argc, char* argv[])
{
	std::cout << sum(4, 2, 43) << std::endl;
	std::cout << sum(0, 2, 0, 43) << std::endl;
	int res[4];
	calc(5, 8, res, res + 1, nullptr, &res[3]);
	swap(res[0], res[1]);
	return EXIT_SUCCESS;
}

int sum(int a, int b, int c, int d)
{
	return a + b + c + d;
}

float sum(float a, float b, float c, float d)
{
	return a + b + c + d;
}

void calc(int a, int b, int* summ, int* diff, int* mult, int* divs)
{
	if (summ != nullptr) { *summ = a + b; }
	if (diff != nullptr) { *diff = a - b; }
	if (mult != nullptr) { *mult = a * b; }
	if (divs != nullptr) { *divs = a / b; }
}
