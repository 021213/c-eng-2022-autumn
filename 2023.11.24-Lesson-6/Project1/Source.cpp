#include<iostream>
#include<functional>
#include<map>

int sum(int a, int b)
{
	return a + b;
}
int diff(int a, int b)
{
	return a - b;
}
int mult(int a, int b)
{
	return a * b;
}
int frac(int a, int b)
{
	return a / b;
}

void example()
{
	using namespace std::placeholders;
	std::map < std::string, std::function< int(int, int) > > commands = {
		{
		{"SUM", std::bind(sum, _1, _2)},
		{"DIFF", std::bind(diff, _1, _2)},
		{"MULT", std::bind(mult, _1, _2)},
		{"DIV", std::bind(frac, _1, _2)},
		}
	};

	std::cout << commands["SUM"](3, 2);

	while (true)
	{
		int op1 = 0;
		int op2 = 0;
		std::cin >> op1;

		std::string cmd;
		std::cin >> cmd;
		if (commands.find(cmd) == commands.end())
		{
			break;
		}

		std::cin >> op2;

		std::cout << "RESULT = " << commands[cmd](op1, op2) << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::function< int(int, int) > f_sum =
		std::bind(sum, std::placeholders::_1, std::placeholders::_2);

	auto f_diff = std::bind(diff, 50, std::placeholders::_2);

	example();
	return EXIT_SUCCESS;
}