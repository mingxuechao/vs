/*URLfind.cpp*/
#include "URLfind.h"
#include <cctype>
#include <algorithm>
using namespace std;
//判断一个字符不是URL字符
bool NotURLchar(char c)
{
    return !(isalnum(c) || find(OTHER_URL_CHAR.begin(), OTHER_URL_CHAR.end(), c) != OTHER_URL_CHAR.end());
}
//找到第一个不是URL符号的字符位置。或者末尾。保持尾部半开性质。
string::iterator URLEnd(string::iterator s, string::iterator e)
{
    return find_if(s, e, NotURLchar);
}
string::iterator UTLBegin(string::iterator s, string::iterator e)
{
    string::iterator i;
    i = s;
    while ((i = search(s, e, URLSIGN.begin(), URLSIGN.end())) != e)
    {
        if (i != s && i + URLSIGN.size() != e)
        {
            string::iterator beg = i;
            while (beg != s && isalpha(*(beg-1)))
            {
                beg--;
            }

            if (beg != i && !NotURLchar(*(i + URLSIGN.size())))
            {
                return beg;
            }
        }
        i = i + URLSIGN.size();
    }
    return e;
}