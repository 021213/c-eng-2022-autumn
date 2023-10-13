#include<iostream>

enum ErrCode {
	DIV_BY_ZERO
};

ErrCode err[10];

int divide(int a, int b, int& result) {
	if (b == 0) {
		err[0] = DIV_BY_ZERO;
		result = 0;
		return 1;
	}
	else {
		result = a / b;
		return 0;
	}
}


int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	int res = 0;
	if (divide(a, b, res) == 1) {
		return EXIT_FAILURE;
	}
	else {
		std::cout << res << std::endl;
	}

	return EXIT_SUCCESS;
}