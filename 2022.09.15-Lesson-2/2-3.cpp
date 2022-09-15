#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	a %= 7; //a = a % 7;
	if (a == 0)
	{
		std::cout << "SUN" << std::endl;
	}
	if (a == 1)
	{
		std::cout << "MON" << std::endl;
	}
	if (a == 2)
	{
		std::cout << "TUE" << std::endl;
	}
	if (a == 3)
	{
		std::cout << "WED" << std::endl;
	}
	if (a == 4)
	{
		std::cout << "THU" << std::endl;
	}
	if (a == 5)
	{
		std::cout << "FRI" << std::endl;
	}
	if (a == 6)
	{
		std::cout << "SAT" << std::endl;
	}
	
	std::cout << (a == 0 ? "SUN" : a == 1 ? "MON" :
				  a == 2 ? "TUE" : a == 3 ? "WED" :
				  a == 4 ? "THU" : a == 5 ? "FRI" : "SAT") << std::endl;
	
	switch(a)
	{
	case 1:
		std::cout << "MON" << std::endl;
		break;
	case 2:
		std::cout << "TUE" << std::endl;
		break;
	case 3:
		std::cout << "WED" << std::endl;
		break;
	case 4:
		std::cout << "THU" << std::endl;
		break;
	case 5:
		std::cout << "FRI" << std::endl;
		break;
	case 6:
		std::cout << "SAT" << std::endl;
		break;
	default:
		std::cout << "SUN" << std::endl;
		break;
	}
	
	string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	std::cout << days[a % 7] << std::endl;
	
	return EXIT_SUCCESS;
}