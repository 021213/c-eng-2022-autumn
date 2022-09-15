#include<stdio.h> // C-style
#include<cstdio> // C++ style
#include<iostream> // C++

int main(int argc, char* argv[])
{
	printf("\targc: %d\n\targv[0]:%s\t\n\n", argc, argv[0]); //C-style output

	std::cout << "\targc: " << argc << std::endl;
	std::cout << "\targv[0]: " << argv[0] << std::endl;
	
	int a = 10;
	int b = 42;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	printf("%d + %d = %d\n", a, b, a + b);

	float f1 = 3.1415926535;
	float f2 = 2.7182818285;
	printf("%f + %f = %f\n", f1, f2, f1 + f2);

	return EXIT_SUCCESS; //0	

//	return EXIT_FAILURE; //1
}

//void main()
//{
//	
//}
