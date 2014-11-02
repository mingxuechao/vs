/*URLfind.h*/
#ifndef URLFIND
#define URLFIND
#include <string>
const std::string OTHER_URL_CHAR = "~!@#$%^&*()_+,./'\""; //������ĸ֮���������ַ���
const std::string URLSIGN = "://";
bool NotURLchar(char c);
std::string::iterator URLEnd(std::string::iterator, std::string::iterator);
std::string::iterator UTLBegin(std::string::iterator, std::string::iterator);
#endif