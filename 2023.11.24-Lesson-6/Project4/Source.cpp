#include<iostream>
#include<functional>
#include<map>
#include<vector>
#include<string>
#include<fstream>

struct Point {
	double x;
	double y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	Point(const Point& point) : x(point.x), y(point.y) {}
	~Point() {}

	Point& operator+=(Point p)
	{
		x += p.x;
		y += p.y;
		return *this;
	}

	friend std::istream& operator>>(std::istream& stream, Point& point)
	{
		char c = 0;
		stream >> c >> point.x >> c >> point.y >> c;
		return stream;
	}

	friend std::ostream& operator<<(std::ostream& stream, Point& point)
	{
		stream << "(" << point.x << " ; " << point.y << ")";
		return stream;
	}
};

template<class T>
struct CommandManager
{
	std::vector<T> vect;
	CommandManager(std::vector<T> vect) : vect(vect) {}
	void printSum()
	{
		T res = T();
		for (auto el : vect)
		{
			res += el;
		}
		std::cout << res << std::endl;
	}
	void printEls()
	{
		std::cout << "{ ";
		for (auto el : vect)
		{
			std::cout << el << " ";
		}
		std::cout << "}" << std::endl;
	}
};

int main1(int argc, char* argv[])
{
	CommandManager<int> manager(std::vector<int>{ 1, 2, 3, 4, 5 });
	std::map < std::string, std::function< void() > > cmd =
	{
		{
			{"ELS", std::bind(&CommandManager<int>::printEls, manager)},
			{"SUM", std::bind(&CommandManager<int>::printSum, manager)},
		}
	};

	cmd["ELS"]();
	cmd["SUM"]();

	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	std::vector<Point> points;

	std::ifstream in("in.txt");
	if (!in)
	{
		return EXIT_FAILURE;
	}

	while (!in.eof())
	{
		in.clear();
		std::copy(
			std::istream_iterator<Point>(in),
			std::istream_iterator<Point>(),
			std::back_inserter(points)
		);
	}
	in.close();
	
	CommandManager<Point> manager(points);
	std::map < std::string, std::function< void() > > cmd =
	{
		{
			{"ELS", std::bind(&CommandManager<Point>::printEls, manager)},
			{"SUM", std::bind(&CommandManager<Point>::printSum, manager)},
		}
	};

	cmd["ELS"]();
	cmd["SUM"]();

	return EXIT_SUCCESS;
}