#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define PATH "D:/Documents/Visual Studio 2013/Projects/fstreamtest/fstreamtest/test.txt"
int main1()
{
    std::fstream fs;
    fs.open(PATH, std::ios::out);
    string  in;
    while (getline(cin,in))
    {
        fs << in;
        fs << endl;
    }
    fs.close();
    return 0;
}
int main()
{
    fstream fs;
    fs.open(PATH,ios::in);
    string out;
    while (getline(fs,out))
    {
        cout << out << endl;
    }
    fs.close();
    return 0;
}