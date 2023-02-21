#include<iostream>
#include<string>

struct Student {
	//fields of structure
	std::string name;
	int age;
	int course;

	//constructors
	//default constructor
	Student()
	{
		name = "Bob";
		age = 18;
		course = 1;
	}
	
	//parametrised constructor
	Student(std::string name, int age, int course)
	{
		this->name = name;
		this->age = age;
		this->course = course;
	}

	////parametrised and default constructor with initializers
	//Student(std::string name = "Bob", int age = 18, int course = 1)
	//	: name(name), age(age), course(course)
	//{
	//	//this->name = name;
	//	//this->age = age;
	//	//this->course = course;
	//}

	//copy constructor
	Student(const Student& st)
		: name(st.name), age(st.age), course(st.course)
	{
		//copy all dynamic arrays
	}

	//destructor
	~Student()
	{
		//delete all dynamic fields
	}
};

void printStudent(Student st)
{
	std::cout << st.name;
	std::cout << " (";
	std::cout << st.age;
	std::cout << ", ";
	std::cout << st.course;
	std::cout << ")";
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	Student st1; //st1 - object of Student
	st1.name = "Nick";
	st1.age = 25;
	st1.course = 2;

	Student st2("John", 21, 1);
	st2.name = "Bill";
	printStudent(st1);
	printStudent(st2);

	Student *st3 = new Student("Bob", 32, 4);
	Student *st4 = new Student[5];

	printStudent(st4[1]);
	printStudent(*st3);

	delete st3;
	delete[] st4;

	return EXIT_SUCCESS;
}