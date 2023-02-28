#include<iostream>
#include<string>

enum AnimalType {
	None,
	Dog,
	Cat,
	Bird,
	Fish
};

class Animal {
private:
	AnimalType type;
	int age;

public:
	std::string name;

	Animal(std::string name = "Bob", AnimalType type = None, int age = 0) :
		name(name), type(type), age(age) {}

	Animal(const Animal& animal) :
		name(animal.name), type(animal.type), age(animal.age) {}

	~Animal() {}

	void printInfo()
	{
		std::cout << name << " " << type << " " << age << std::endl;
	}

	AnimalType getType()
	{
		return type;
	}

	int getAge()
	{
		return age;
	}
	
	void setAge(int age)
	{
		if (age < 0)
		{
			return;
		}
		this->age = age;
	}
};


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