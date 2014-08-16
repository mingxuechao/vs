#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
