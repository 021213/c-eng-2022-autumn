#include<iostream>
#include<string>

enum AnimalType {
	None,
	Dog,
	Cat,
	Bird,
	Fish
};

enum AnimalAbility {
	Walk = 1,
	Fly = 2,
	Swim = 4,
	Sound = 8
};

union AnimalInfo {
	AnimalType type;
	AnimalAbility ability;
};

struct Animal {
	std::string name;
	AnimalType type;
	int abilities;
	int age;

	Animal(std::string name = "Bob", AnimalType type = None, int age = 0) :
		name(name), type(type), age(age) {
		abilities = Walk | Swim | Sound; // 0000 0000 0000 1101
	}

	Animal(const Animal& animal) :
		name(animal.name), type(animal.type), age(animal.age), abilities(animal.abilities) {}

	~Animal() {}
};

bool CanDo(Animal animal, AnimalAbility ability)
{
	return (ability & animal.abilities) != 0;
}

int main(int argc, char* argv[])
{
	Animal animal("Banana");
	std::cout << CanDo(animal, Swim) << std::endl;
	std::cout << CanDo(animal, Fly) << std::endl;

	AnimalInfo info;
	info.type = None;
	std::cout << info.ability << std::endl;

	info.ability = Sound;
	std::cout << info.type << std::endl;


	return EXIT_SUCCESS;
}