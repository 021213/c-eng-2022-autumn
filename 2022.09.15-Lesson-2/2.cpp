#include <iostream>

int main(int argc, char* argv[])
{
	int a = 15;
	int b = 10;
	
	if(a > b)
	{
		std::cout << "BANANA" << std::endl;
	}
	
	if(
		(a > b) || (a <= b) || (a >= b) || (a < b)
		&& (a == b) && (a != b) && (a = b) && 5
		);
	
	if(a > b)
	{
		std::cout << a << std::endl;
	}
	else
	{
		std::cout << b << std::endl;		
	}
	
	std::cout << (a > b ? a : b) << std::endl;
	
	int c = 0;
	c = a & b; //and
	//a 	 = 13_10 = 1101_2
	//b 	 =  6_10 = 0110_2
	//a & b  =  4_10 = 0100_2
	
	c = a && b; //and
	//a 	 = 13_10 = 1101_2
	//b 	 =  6_10 = 0110_2
	//a && b =  true =    1_2
	
	c = a | b; //or
	//a 	 = 13_10 = 1101_2
	//b 	 =  6_10 = 0110_2
	//a | b  = 15_10 = 1111_2
	
	c = a || b; //or
	//a 	 = 13_10 = 1101_2
	//b 	 =  6_10 = 0110_2
	//a || b = true  =    1_2
	
	c = a ^ b; //xor
	//a 	 = 13_10 = 1101_2
	//b 	 =  6_10 = 0110_2
	//a ^ b  = 11_10 = 1011_2
	
	c = !a; //not
	//a 	 = 13_10 = 1101_2
	//!a 	 = false =    0_2
	c = ~a; //inverse
	//a 	 = 13_10 = 1101_2
	//~a     =  2_10 = 0010_2
	
	c = a >> 2; //right bit shift
	//a 	 = 13_10 = 0000 1101_2
	//a >> 2 =  3_10 = 0000 0011_2
	
	c = a << 2; //left bit shift
	//a 	 = 13_10 = 0000 1101_2
	//a << 2 = 52_10 = 0011 0100_2
	
	return EXIT_SUCCESS;
}