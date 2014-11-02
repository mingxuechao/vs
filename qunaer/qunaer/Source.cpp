#include <iostream>
#include <String>
using namespace std;
string padString(string str, int minLength, char padChar)
{
    string res = str;
    if (str.length() < minLength)
    {
        string extr = string(minLength - str.length(), padChar);
        res = extr + res;
    }
    return res;
}
int main()
{
    cout << padString("7", 3, '0') << endl;
    cout << padString("", 0, '0') << endl;
}