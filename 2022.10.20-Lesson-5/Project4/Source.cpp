#include<iostream>

int main(int argc, char* argv[])
{
	int n = 10;
	int* a = new int[n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	delete[] a;
	
	//      a[i] == *(a + i)
	//new int[n] == (int*)malloc(n * sizeof(int))
	//  delete[] == free(a)

	/*C style*/
	a = (int*)malloc(n * sizeof(int));//a = (int*)calloc(n, sizeof(int));
	if (a != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			*(a + i) = i;
		}
		for (int i = 0; i < n; ++i)
		{
			std::cout << *(a + i) << " "; 
		}
		free(a);
	}

	return EXIT_SUCCESS;
}