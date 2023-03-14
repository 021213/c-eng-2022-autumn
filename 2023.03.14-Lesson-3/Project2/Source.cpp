#include<iostream>
#include<string>

class BaseClass {
public:
	static int count;
	std::string name;
	int a;
	int b;
	BaseClass(std::string name, int a = 10, int b = 20) :
		name(name), a(a), b(b) {
		std::cout << name << " BASE CONSTRUCTOR INVOKED" << std::endl;
	}
	~BaseClass() {
		std::cout << name << " BASE DISTRUCTOR INVOKED" << std::endl;
	}
	void printA() { std::cout << a << std::endl; }
	void printB() { std::cout << b << std::endl; }
};


class DerivedClass : public BaseClass {
public:
	int b;
	int c;
	DerivedClass(std::string name, int a = 100, int b = 200, int c = 300) :
		BaseClass(name, a), b(b), c(c) {
		std::cout << name << " DERIVED CONSTRUCTOR INVOKED" << std::endl;
	}
	~DerivedClass() {
		std::cout << name << " DERIVED DISTRUCTOR INVOKED" << std::endl;
	}
	void printA() {
		std::cout << "base " << BaseClass::a << " ";
		std::cout << "derived " << a << std::endl;
	}
	void printB() {
		std::cout << "base " << BaseClass::b << " ";
		std::cout << "derived " << b << std::endl;
	}
	void printC() {
		std::cout << c << std::endl;
	}
};



int main(int argc, char* argv[])
{
	BaseClass bClInstance("A");
	bClInstance.printA();
	bClInstance.printB();
	DerivedClass dClInstance("B");
	dClInstance.printA();
	dClInstance.printB();
	dClInstance.printC();
	std::cout << std::endl << "outer calls" << std::endl;
	std::cout << dClInstance.b << std::endl;
	std::cout << ((BaseClass)dClInstance).b << std::endl;
	std::cout << dClInstance.BaseClass::b << std::endl;
	dClInstance.BaseClass::printB();
	dClInstance.printB();

	std::cout << std::endl;
	BaseClass::count = 4;
	dClInstance.count = 8;
	return EXIT_SUCCESS;
}