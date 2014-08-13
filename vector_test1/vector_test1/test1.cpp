#include <iostream>
#include <vector>
int main()
{
	int arr[10] = { 0, 1, 2, 4, 5, 6, 7, 8, 9 };
	std::vector<int> vec1;
	for (int i = 1; i < 10; i++)
	{
		vec1.push_back(arr[i]);
	}
	std::vector<int>::size_type jx;
	for (std::vector<int>::size_type ix = 0; ix < (vec1.size() - 1); ix++)
	{	
		jx = ix + 1;
		std::cout << vec1[ix] + vec1[jx] << std::endl;
	}
	return 0;
}