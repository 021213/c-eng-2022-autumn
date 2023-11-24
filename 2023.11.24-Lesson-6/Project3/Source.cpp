#include<iostream>
#include<functional>
#include<map>
#include<vector>
#include<string>

struct CommandManager
{
	std::vector<int> vect;
	CommandManager(std::vector<int> vect) : vect(vect) {}
	void printSum()
	{
		int res = 0;
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

int main(int argc, char* argv[])
{
	CommandManager manager(std::vector<int>{ 1, 2, 3, 4, 5 });
	std::map < std::string, std::function< void() > > cmd =
	{
		{
			{"ELS", std::bind(&CommandManager::printEls, manager)},
			{"SUM", std::bind(&CommandManager::printSum, manager)},
		}
	};

	cmd["ELS"]();
	cmd["SUM"]();

	return EXIT_SUCCESS;
}