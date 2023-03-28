#include<iostream>

template<typename T, typename K>
K sum(T a, T b)
{
	return a + b;
}

int main(int argc, char* argv[])
{
	std::cout << sum<int, long long>(3, 5) << std::endl;
	std::cout << sum<double, float>(3.2, 5.5) << std::endl;
	return 0;
}