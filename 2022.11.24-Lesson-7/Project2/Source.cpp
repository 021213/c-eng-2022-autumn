#include<iostream>
#include<cstdarg>

void printSum(int count, ...)
{
	int sum = 0;

	int* p = &count + 1;
	for (int i = 0; i < count; ++i)
	{
		std::cout << *p << (i < count - 1 ? " + " : " = ");
		sum += *p;
		void* pp = (void*)p;
		pp = (void*)(((int*)pp) + 1);
		p = (int*)pp;
	}

	std::cout << sum << std::endl;
}

void printSumP(int count, ...)
{
	va_list params;
	va_start(params, count);
	int sum = 0;
	for(int i = 0; i < count; ++i)
	{
		int val = va_arg(params, int);
		std::cout << val << (i < count - 1 ? " + " : " = ");
		sum += val;
	}
	std::cout << sum << std::endl;
	va_end(params);
}


int main(int argc, char* argv[])
{
	printSum(5, 1, 2, 3, 4, 5);
	printSum(3, 1, 2, 3);
	printSumP(4, 1, 2, 3, 4);
	printSumP(2, 1, 2);
	printf("%d + %c = %s\n", 3, '2', "5");

	return EXIT_SUCCESS;
}
