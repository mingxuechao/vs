/*#include <iostream>
#include <string>
int main()
{
std::cout << "Please enter your first name:";
std::string name;
std::cin >> name;
int i = 1;

const std::string greeting = "Hello, " + name + "!";

const std::string spaces(greeting.size(), ' ');
const std::string second = "* " + spaces + " *";

const std::string first(second.size(), '*');

std::cout << std::endl;
std::cout << first << std::endl;
std::cout << second << std::endl;
std::cout << "* " << greeting << " *" << std::endl;
std::cout << second << std::endl;
std::cout << first << std::endl;

std::cout << i++ << i++ << i;
return 0;
}
*/
#include <iostream>
#include <string>
using namespace std;
int fa()
{
	cout << "fa()" << endl;
	return 1;
}
int fb()
{
	cout << "fb()" << endl;
	return 2;
}
int fc()
{
	cout << "fc()" << endl;
	return 3;
}
int main()
{
	int i = 1;
	cout << i++ << i++ << i << endl;
	cout << fa() << fb() << fc() << endl;
	return 0;
}