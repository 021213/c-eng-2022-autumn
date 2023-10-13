#include<iostream>
#include<stdexcept>
#include<string>

class StackUnderflowException : public std::exception {
public:
	const char* what() const throw() override {
		return "Stack Underflow";
	}
};

class StackOverflowException : public std::exception {
public:
	const char* what() const throw() override {
		return "Stack Overflow";
	}
};

class WrongStackSizeException : public std::exception {
public:
	int size;
	WrongStackSizeException(int size) : size(size) { }

	const char* what() const throw() override {
		return "Stack cannot be of given size";
	}
};

template<class T>
class Stack {
public:
	virtual ~Stack() {};
	virtual void push(const T& e) = 0;
	virtual T top() const = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

template<class T>
class ArrayStack : public Stack<T> {
public:
	ArrayStack(int size = 10) : count(0), capacity(size) {
		if (size <= 0) {
			throw WrongStackSizeException(size);
		}
		elements = new T[size];
	}

	virtual ~ArrayStack() {
		delete[] elements;
	}

	void push(const T& e) override {
		if (count >= capacity) {
			throw StackOverflowException();
		}
		elements[count] = e;
		++count;
	}
	T top() const override {
		if (count <= 0) {
			throw StackUnderflowException();
		}
		return elements[count - 1];
	}
	T pop() override {
		if (count <= 0) {
			throw StackUnderflowException();
		}
		--count;
		return elements[count];
	}
	bool isEmpty() override {
		return count <= 0;
	}
	int size() {
		return count;
	}

private:
	T* elements;
	int count;
	int capacity;
};

void STACK_TEST() {
	try {
		ArrayStack<int> stack(5);
		stack.push(5);
		stack.push(4);
		stack.push(3);
		stack.push(2);
		stack.push(1);
		std::cout << "POP " << stack.pop() << std::endl;
		std::cout << "POP " << stack.pop() << std::endl;
		std::cout << "POP " << stack.pop() << std::endl;
		std::cout << "POP " << stack.pop() << std::endl;
		std::cout << "POP " << stack.pop() << std::endl;
	}
	catch (WrongStackSizeException& e) {
		std::cout << e.what() << e.size << std::endl;
	}
	catch (StackUnderflowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (StackOverflowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}

void QUEUE_TEST() {

}

int EvalPostfix(const std::string& expr, const size_t stackSize) {
	ArrayStack<int> stack(stackSize);
	for (int i = 0; i < expr.size(); ++i)
	{
		if ('0' <= expr[i] && expr[i] <= '9') {
			int digit = expr[i] - '0';
			stack.push(digit);
		}
		else {
			int a = 0;
			int b = 0;
			if (stack.size() < 2) {
				throw std::logic_error("I can't perform the action. There should be at least 2 operands.");
			}

			b = stack.pop();
			a = stack.pop();
			switch (expr[i]) {
			case '+': stack.push(a + b); break;
			case '-': stack.push(a - b); break;
			case '*': stack.push(a * b); break;
			case '/': stack.push(a / b); break;
			default: throw std::logic_error("Unknown operation");
			}
		}
	}
	if (stack.size() != 1) {
		throw std::logic_error("Unexpected end");
	}
	return stack.pop();
}

void EvalPostfix_TEST() {
	std::string expr = "43+5*24*-";
	int res = 27;
	try {
		std::cout << "Test 1: ";
		if (EvalPostfix(expr, 4) == res) {
			std::cout << "OK!" << std::endl;
		}
		else {
			std::cout << "FAILED!" << std::endl;
		}

		try {
			std::cout << "Test 2: ";
			if (EvalPostfix(expr, 2) == res) {
				std::cout << "OK!" << std::endl;
			}
			else {
				std::cout << "FAILED!" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "FAILED! " << e.what() << std::endl;
		}

		try {
			std::cout << "Test 3: ";
			expr = "3+5*24*-";
			if (EvalPostfix(expr, 2) == res) {
				std::cout << "OK!" << std::endl;
			}
			else {
				std::cout << "FAILED!" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "FAILED! " << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << "FAILED! " << e.what() << std::endl;
	}
}

int main(int argc, char* argv[])
{
	STACK_TEST();
	QUEUE_TEST();
	EvalPostfix_TEST();
	return EXIT_SUCCESS;
}