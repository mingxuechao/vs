#include <iostream>
#include <ostream>
#include <string.h>
class myString
{
public:
    myString(const char *str = NULL);
    myString(const myString &other);
    myString();
    ~myString();
    myString& operator=(const myString &other);
    myString& operator=(const char *str);
    bool operator==(const myString &other);
private:
    char *m_data;
};
inline myString::myString(const char *str = NULL)
{
    if (str == NULL)
    {
        m_data = (char *)malloc(1);
        *m_data = '\0';
    }
    else
    {
        m_data = (char *)malloc(strlen(str) + 1);
        strcpy(m_data, str);
    }
}
inline myString::myString(const myString &other)
{
    m_data = (char *)malloc(strlen(other.m_data) + 1);
    strcpy(m_data, other.m_data);
}
inline myString & myString::operator=(const myString &other)
{
    if (this != &other)
    {
        free(m_data);
        m_data = (char *)malloc(strlen(other.m_data) + 1);
        strcpy(m_data,other.m_data);
    }
    *this;
}
inline myString& myString::operator=(const char * str)
{
    if (str == NULL)
    {
        free(m_data);
        m_data = (char *)malloc(1);
        *m_data = '\0';
    }
    else
    {
        free(m_data);
        m_data = (char *)malloc(strlen(str));
        strcpy(m_data,str);
    }
    return *this;
}
inline bool myString::operator==(const myString &other)
{
    if (this == &other)
    {
        return true;
    }
    else
    {
        return strcpy(m_data, other.m_data) == 0;
    }
}
inline myString::~myString()
{
    free(m_data);
}
