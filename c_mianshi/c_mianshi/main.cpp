#include <iostream>
#include <cstdlib>
using namespace std;
class parent
{
public:
	virtual void output();
};
void parent::output()
{
	printf("parent!\n");
}
class son : public parent
{
public:
	virtual void output();
};
void son::output()
{
	printf("son!\n");
}
//int main()
//{
//	son s;
//	::memset(&s,0,sizeof(s));
//	parent &p = s;
//	p.output();
//	return 0;
//}