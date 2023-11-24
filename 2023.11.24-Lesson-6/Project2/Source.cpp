#include<iostream>
#include<cstdarg>

int sum(int a, int b)
{
	return a + b;
}
int diff(int a, int b)
{
	return a - b;
}
int mult(int a, int b)
{
	return a * b;
}
int frac(int a, int b)
{
	return a / b;
}

int sum_ellipsis(int count, ...)
{
	int res = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i)
	{
		res += va_arg(args, int);
	}
	va_end(args);
	return res;
}

int main(int argc, char* argv[])
{
	int (*ptr)(int, int);
	ptr = sum;
	std::cout << ptr(3, 2) << std::endl;

	std::cout << sum_ellipsis(5, 1, 2, 3, 4, 5) << std::endl;
	printf("%d + %d = %d\n", 3, 5, ptr(3, 5));

	int (*operation[4])(int, int) {sum, diff, mult, frac};
	for (int i = 0; i < 4; ++i)
	{
		std::cout << operation[i](1, 2) << std::endl;
	}
	return EXIT_SUCCESS;
}