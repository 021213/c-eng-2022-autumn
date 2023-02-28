#pragma once
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

	void printInfo();

	AnimalType getType();

	int getAge();

	void setAge(int age);
};


