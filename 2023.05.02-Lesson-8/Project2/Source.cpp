#include<iostream>
#include<stack>
#include<string>

int openType(char c)
{
	switch (c) {
	case '[':
		return 1;
	case '(':
		return 2;
	case '{':
		return 3;
	default:
		return 0;
	}
}

int closeType(char c)
{
	switch (c) {
	case ']':
		return 1;
	case ')':
		return 2;
	case '}':
		return 3;
	default:
		return 0;
	}
}

bool stringValid(std::string str)
{
	std::stack<int> brackets;
	for (int i = 0; i < str.length(); ++i)
	{
		if (openType(str[i]) > 0)
		{
			brackets.push(openType(str[i]));
		}
		if (closeType(str[i]) > 0)
		{
			if (brackets.empty() ||
				closeType(str[i]) != brackets.top())
			{
				return false;
			}
			brackets.pop();
		}
	}
	return brackets.empty();
}

int main()
{
	std::string str1 = "dfgh[sdfj[dfgh{asdfg}sdfgsdsdfghfh{dfj(dfgj)sdfh}adfjd(jsfg)dfg]sdfh]";
	std::cout << stringValid(str1) << " " << str1 << std::endl;
	std::string str2 = "[[{{((}))]}]";
	std::cout << stringValid(str2) << " " << str2 << std::endl;
	std::string str3 = "[{}{()}()]]";
	std::cout << stringValid(str3) << " " << str3 << std::endl;
	std::string str4 = "[[{}{()}()]";
	std::cout << stringValid(str4) << " " << str4 << std::endl;
	return 0;
}