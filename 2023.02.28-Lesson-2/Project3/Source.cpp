#include<iostream>
#include<string>
#include "Animal.h"

int main(int argc, char* argv[])
{
	Animal animal1("Banana", Dog, 4);
	Animal animal2("Kitty", Cat, 3);

	animal1.printInfo();
	animal2.printInfo();

	std::cout << animal1.getType() << std::endl;

	animal2.setAge(11);

	animal1.printInfo();
	animal2.printInfo();

	Animal* animal3;
	animal3 = new Animal("Bananoid", Bird, 32);

	(*animal3).name = "Bananoidov";
	animal3->name = "Bananoidov";

	delete animal3;

	return EXIT_SUCCESS;
}