#include<iostream>
#include<string>
//Inheritance. Use inheritance if you can not avoid using it.
//	- Constructor
//	- Methods

enum AnimalType {
	NONE,
	GROUND,
	WATER,
	AIR
};

class Animal{ //base class
public:
	std::string name;
	void sound();
	void migrate();
	Animal(AnimalType type = NONE)
	{

	}
protected:
	AnimalType type; //deprecated
};

class AirAnimal : Animal { //derived class
public:
	void changeAltitude();
	void sound(); //override method of the base class. Base method is SEALED
	//Animal::sound();
};

class WaterAnimal: Animal{
public:
	void changeDepth();
};

class  GroundAnimal{
private:
	Animal animal;
public:
	void migrate() { return animal.migrate(); }
	Animal toAnimal() { return animal; }
};


int main()
{
	return EXIT_SUCCESS;
}