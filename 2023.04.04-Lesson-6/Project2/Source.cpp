#include<iostream>
#include<fstream>

struct Point {
	int x = 0;
	int y = 0;
};

int main(int argc, char* argv[])
{
	std::ofstream ofile("file.bin", std::ios::binary);
	Point p1;
	p1.x = 110; p1.y = 20;
	ofile.write((char*)&p1, sizeof(Point));
	ofile.close();

	std::ifstream ifile("file.bin", std::ios::binary);
	Point p2;
	ifile.read((char*)&p2, sizeof(Point));
	std::cout << p2.x << " " << p2.y;
	ifile.close();

	return EXIT_SUCCESS;
}