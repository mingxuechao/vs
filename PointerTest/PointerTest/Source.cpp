#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void change(int *a, int *b)
{
b = a; //修改这个变量不会更改地址内的内容，这个变量已经成了局部变量，在
int tmp = *a;
*a = *b;
*b = tmp;  //这是一个地址的引用

}
int main()
{
int t1 = 1;
int t2 = 2;
change(&t1, &t2);
printf("%d\n",sizeof(t1));
return 0;
}*/
class mString{
public:
	mString(const char *str);
	~mString();
	mString(const mString &other);
	mString & operator=(const mString &other);
	char *m_data;
};
mString::mString(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
	}
}
mString::~mString()
{
	delete[] m_data;
}
mString::mString(const mString &other)
{
	int length = strlen(other.m_data);
	m_data = new char[length + 1];
	strcpy(m_data, other.m_data);
}
mString & mString::operator=(const mString &other)
{
	if (this != &other)
	{
		char *temp = new char[strlen(other.m_data) + 1];
		strcpy(temp, other.m_data);
		delete[] m_data;
		m_data = temp;
	}
	return *this;
}