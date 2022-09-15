#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	//Ctrl + K + D;
	//Ctr + L;
	int a = 0;
	int b = 0;

	scanf("%d", &a);
	std::cin >> b;

	std::cout << a + b << std::endl;

	float f = 0;
	cout << sizeof(float) << endl;
	double d = 0;
	cout << sizeof(double) << endl;

	int i = 0;
	cout << sizeof(int) << endl;
	long l = 0;
	cout << sizeof(long) << endl;
	long long ll = 0;
	cout << sizeof(long long) << endl;
	unsigned int ui = 0;
	cout << sizeof(unsigned int) << endl;
	char c = 0;
	cout << sizeof(char) << endl;
	c = '0';

	return 0;
}