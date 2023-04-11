#include<iostream>
#include<cmath>
#include<ctime>

struct Shape {
	int x;
	int y;
	Shape(int x = 0, int y = 0) : x(x), y(y) {}
	Shape(const Shape& shape) : x(shape.x), y(shape.y) {}
	~Shape() {}
	void print()
	{
		printName();
		printCoords();
		printSquare();
		std::cout << std::endl;
	}
	void printCoords()
	{
		std::cout << "(" << x << "; " << y << ")";
	}
	virtual void printName() = 0;
	virtual void printSquare() = 0;
};

struct Circle : public Shape {
	int r;
	Circle(int x = 0, int y = 0, int r = 0) :
		Shape(x, y), r(r) {}
	void printName() override
	{
		std::cout << "CIRCLE ";
	}
	void printSquare() override
	{
		std::cout << " S = " << 3.1415926535 * r * r;
	}
};

struct Square : public Shape {
	int a;
	Square(int x = 0, int y = 0, int a = 0) :
		Shape(x, y), a(a) {}
	void printName() override
	{
		std::cout << "SQUARE ";
	}
	void printSquare() override
	{
		std::cout << " S = " << a * a;
	}

};

void printShape(Shape& sh)
{
	sh.print();
}

int main(int argc, char* argv[])
{	
	srand(time(0));
	Shape** shapes = new Shape*[10];
	for (int i = 0; i < 10; ++i)
	{
		int xx = rand() % 10;
		int yy = rand() % 10;
		int p = rand() % 10;
		if (rand() % 2 == 0)
		{
			shapes[i] = new Circle(xx, yy, p);
		}
		else
		{
			shapes[i] = new Square(xx, yy, p);
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		shapes[i]->print();
	}

	for (int i = 0; i < 10; ++i)
	{
		delete shapes[i];
	}
	delete[] shapes;
	return EXIT_SUCCESS;
}