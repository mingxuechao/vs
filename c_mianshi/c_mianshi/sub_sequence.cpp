#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#define MAXLEN 200
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

int LCS(char *a, char*b, int lena, int lenb, int map[MAXLEN][MAXLEN])
{
	int max = 0;
	if (lena != 0 && lenb != 0)
	{
		if (map[lena][lenb] != 0)
		{
			max = map[lena][lenb];
		}
		else
		{
			if (a[lena] == b[lenb])
			{
				max = 1 + LCS(a, b, lena - 1, lenb - 1, map);
			}
			else
			{
				int tmpmax1, tmpmax2;
				tmpmax1 = LCS(a, b, lena - 1, lenb, map);
				tmpmax2 = LCS(a, b, lena, lenb - 1, map);
				if (tmpmax1 > tmpmax2)
				{
					max = tmpmax1;
				}
				else
				{
					max = tmpmax2;
				}
			}
		}
	}
	map[lena][lenb] = max;
	return max;
}
int LCS(char *a, char *b, int lena, int lenb, int map[MAXLEN][MAXLEN],char mapdata[MAXLEN][MAXLEN])
{
	int max = 0;
	if (lena != 0 && lenb != 0)
	{
		if (map[lena][lenb] != 0)
		{
			max = map[lena][lenb];
		}
		else
		{
			if (a[lena] == b[lenb])
			{
				max = 1 + LCS(a, b, lena - 1, lenb - 1, map);
			}
			else
			{
				int tmpmax1, tmpmax2;
				tmpmax1 = LCS(a, b, lena - 1, lenb, map);
				tmpmax2 = LCS(a, b, lena, lenb - 1, map);
				if (tmpmax1 > tmpmax2)
				{
					max = tmpmax1;
				}
				else
				{
					max = tmpmax2;
				}
			}
		}
	}
	map[lena][lenb] = max;
	return max;
}
int LCS2(char *a, char*b, int lena, int lenb)
{
	int max = 0;
	if (lena != 0 && lenb != 0)
	{
		if (a[lena] == b[lenb])
		{
			max = 1 + LCS2(a, b, lena - 1, lenb - 1);
		}
		else
		{
			int tmpmax1, tmpmax2;
			tmpmax1 = LCS2(a, b, lena - 1, lenb);
			tmpmax2 = LCS2(a, b, lena, lenb - 1);
			if (tmpmax1 > tmpmax2)
			{
				max = tmpmax1;
			}
			else
			{
				max = tmpmax2;
			}
		}
	}

	return max;
}
/*
void main()
{
	char *str = "123456789";
	char *str3 = "2697894";
	char *str1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	char *str2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	//std::vector<char *> res;
	int map[MAXLEN][MAXLEN] = {};
	int max;
	/*	res = SubSequen(str, strlen(str));
		for (std::vector<char *>::iterator it = res.begin(); it != res.end(); it++)
		{
		std::cout << *it << std::endl;
		}	*/ /*
	int max1 = LCS(str1, str2, strlen(str1), strlen(str2), map);
	max = LCS2(str1, str2, strlen(str1), strlen(str2));
	std::cout << max << std::endl;
	//return 0;
}	*/
