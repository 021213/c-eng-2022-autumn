#pragma once
#include<exception>
#include<ostream>

class ListUnderflowException : public std::exception
{
public:
	const char* what() const throw() override
	{
		return "List is too small";
	}
};

class ListOverflowException : public std::exception
{
public:
	const char* what() const throw() override
	{
		return "Not enough space";
	}
};

class ListSizeException : public std::exception
{
public:
	const char* what() const throw() override
	{
		return "Wrong size of list";
	}
};

template<class T>
class List
{
public:
	virtual ~List() {};
	virtual void PushForward(const T& e) = 0;
	virtual void PushBackward(const T& e) = 0;
	virtual void Insert(const T& e, int pos) = 0;
	virtual T PopForward() = 0;
	virtual T PopBackward() = 0;
	virtual T Extract(int pos) = 0;
	virtual size_t Size() = 0;
	virtual bool IsEmpty() = 0;
};