/*
#include <iostream>
#include <vector>
class mydata
{
public:
	mydata(int data);
	~mydata();
	int k;
private:

};

mydata::mydata(int data)
{
	k = data;
	std::cout << "create: " << k << std::endl;
}

mydata::~mydata()
{
	std::cout << "delete: " << k << std::endl;
}
std::vector<mydata> function(int data)
{
	mydata *my = new mydata(5);
	mydata &myre = *my;
	std::vector<mydata> tmp;
	tmp.push_back(*my);
	return tmp;
}
*/
//vector只是用了变量的一个引用，删掉这个引用时，删除引用时，是不会删除该变量的。

/*
int main_test()
{
	std::vector<mydata> ttt = function(6);
	return 0;
}*/