#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
std::vector<char *> SubSequen(char *str, int len)
{
	std::vector<char *> subseq;
	std::vector<char *>	tmpvec;
	if (len <= 1)
	{
		char *tmp = (char *)malloc(sizeof(char)* 2);
		char *tmp1 = (char *)malloc(sizeof(char)* 1);
		tmp1[0] = '\0';
		subseq.push_back(tmp1);
		tmp[0] = str[len - 1];
		tmp[1] = '\0';
		subseq.push_back(tmp);

	}
	else
	{
		tmpvec = SubSequen(str + 1, len - 1);
		//char tmp1[1024];
		for (std::vector<char *>::iterator it = tmpvec.begin(); it != tmpvec.end(); it++)
		{
			subseq.push_back(*it);
		}
		for (std::vector<char *>::iterator it = tmpvec.begin(); it != tmpvec.end(); it++)
		{
			char *tmp = (char *)malloc(len + 1);
			int tmplen;
			//subseq.push_back(*it);
			strcpy(tmp, *it);
			tmplen = strlen(tmp);
			tmp[tmplen] = str[0];
			tmp[tmplen + 1] = '\0';
			subseq.push_back(tmp);
		}
	}
	return subseq;
}


int main_test(void)
{
	char *str = "123456789";
	std::vector<char *> res;
	res = SubSequen(str, strlen(str));
	for (std::vector<char *>::iterator it = res.begin(); it != res.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}