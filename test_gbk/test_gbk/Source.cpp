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
	std::string str = "�ҽ��ռ�Ŀռ�Ŀռ�ĵĿռ�ռ�Ŀռ�򿪵Ľ����Ľ����Ľ����ȼ��϶����ռ�Ŀռ�Ŀռ�Ŀռ��C";
	std::cout<< str.substr(0, get_buf(str,5))<<std::endl;
	return 0;
}
