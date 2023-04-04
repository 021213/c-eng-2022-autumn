/*
ios

istream  ostream

fstream - ifstream ofstream
*/

#include<iostream>
#include<fstream>

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt", std::ios_base::app);

	int a = 0;
	int b = 0;
	fin >> a >> b;
	fout << a << " + " << b << " = " << a + b << std::endl;
	fout << a << " - " << b << " = " << a - b << std::endl;

	fout.close();
	fin.close();

	return EXIT_SUCCESS;
}

