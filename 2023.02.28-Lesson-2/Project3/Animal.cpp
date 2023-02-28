#include "Animal.h"

void Animal::printInfo()
{
	std::cout << name << " " << type << " " << age << std::endl;
}

AnimalType Animal::getType()
{
	return type;
}

int Animal::getAge()
{
	return age;
}

void Animal::setAge(int age)
{
	if (age < 0)
	{
		return;
	}
	this->age = age;
}