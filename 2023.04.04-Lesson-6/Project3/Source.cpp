#include<iostream>

class Point {
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point(const Point& point) : x(point.x), y(point.y) {}
	~Point() {}
	Point& operator=(const Point& point)
	{
		this->x = point.x;
		this->y = point.y;
		return *this;
	}
	Point operator-(const Point& point)
	{
		Point res(this->x - point.x, this->y - point.y);
		return res;
	}
	Point operator*(const int& mult)
	{
		Point res(this->x * mult, this->y * mult);
		return res;
	}
	friend Point operator*(const int& mult, const Point& point)
	{
		Point res(point.x * mult, point.y * mult);
		return res;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Point& point)
	{
		stream << "(" << point.x << "; " << point.y << ")";
		return stream;
	}
};

int main(int argc, char* argv[])
{
	Point p1(3, 2);
	Point p2 = p1;
	Point p3;
	p3 = p1 * 3 - 6 * p2;
	std::cout << "p3 = " << p3 << std::endl;
	return EXIT_SUCCESS;
}