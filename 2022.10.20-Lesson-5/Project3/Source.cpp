#include<iostream>

int main(int argc, char* argv[])
{
	int* a = nullptr;
	a = new int;
	*a = 5;
	delete a;
	void* b = (void*)a;
	std::cout << *(int*)b;

	/*C style*/
	a = (int*)malloc(sizeof(int)); //a = new int;
	free(a); //delete a;
	return EXIT_SUCCESS;
}