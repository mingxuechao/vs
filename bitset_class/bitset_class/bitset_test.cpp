#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#define LENGTH 10
#define FILENAME "D:\\Documents\\test.dat4"
int bit_find(const char * src_filepath)
{
	std::ifstream out;
	out.open(FILENAME);
	bool test = out.is_open();
	std::cerr << "error";
	perror("tst:");
	std::cout << errno << std::endl;
	std::bitset<10> bset1;
	std::bitset<10> bset("0");
	int des;
	char qu;
	out >> des;
	while (!(out.eof()))
	{
		bset.set(des - 1);
		out >> qu;
		out >> des;
	}
	bset.set(des - 1);
	out.close();
	return 	0;
}
int main()
{
	bit_find(FILENAME);
	return 0;
}