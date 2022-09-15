#include <iostream>

int main(int argc, char* argv[])
{
	int i = 0;
	
anchorBanana:
	std::cout << "Banana" << std::endl;
	i++; //i += 1; i = i + 1;
	if (i < 10)
	{
		goto anchorBanana;
anchorNotBanana:
		std::cout << "Nice" << std::endl;
	}
	else
	{
		goto anchorNotBanana;			
	}
	
	return EXIT_SUCCESS;
}