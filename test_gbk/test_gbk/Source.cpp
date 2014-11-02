#include <iostream>
#include <string>

int get_buf(std::string str, int len)
{
	int index = 0;
	while (len != 0)
	{
		if (str.at(index) & 0x80)
		{
			index += 2;
		}
		else
		{
			index += 1;
		}
		len--;
	}
	return index;
}
int main()
{
	std::string str = "我进空间的空间的空间的的空间空间的空间打开的健康的健康的健康等级肯定进空间的空间的空间的空间打开C";
	std::cout<< str.substr(0, get_buf(str,5))<<std::endl;
	return 0;
}
