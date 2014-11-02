#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define LEN 9
int main(void)
{
    int data[LEN] = { 2, 3, 4, 5,6,7,8,9,10};
    int right[LEN];
    int left[LEN];
    copy(data, data + LEN, ostream_iterator<int>(cout, "\t"));
    right[0] = 1;
    for (int i = 1; i < LEN; i++)
    {
        right[i] = right[i - 1] * data[i - 1];
    }
    left[LEN-1] = 1;
    for (int i = LEN - 2; i >= 0; i--)
    {
        left[i] = left[i + 1] * data[i + 1];
    }
    for (int i = 0; i < LEN; i++)
    {
        data[i] = right[i] * left[i];
    }
    for (int i = 0; i < LEN; i++)
    {
        cout << data[i] << "\t";
    }
    cout << endl;
    unsigned short i, j;
    int co = 0;
    for (i = 0, j = 2; j != i; i += 5, j += 7)
    {
        co++;
    }
    cout << co << endl;
     return 0;
}