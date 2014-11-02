#include <iostream>
#include <vector>
using namespace std;
int bestReplace(vector<int> &data, int cards)
{
    if (cards >= data.size() - 2) return data.back() - data[0];
    int max = 0;
    if (cards == 0)
    {
        for (int i = 1; i< data.size() - 1; i++)
        {
            int tmp = data[i] - data[i - 1];
            if (tmp > max)
            {
                max = tmp;
            }
        }
        return max;
    }
    for (int i = 1; i + cards < data.size(); i++)
    {
        int tmp = data[i + cards] - data[i - 1] - 1;
        if (tmp > max)
        {
            max = tmp;
        }
    }
    return max;
}
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void bubleSort(int A[], int len)
{
    bool change = true;
    int i = 0;
    while (i < len && change)
    {
        change = false;
        for (int j = 1; j < len - i; j++)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                change = true;
            }
        }
        i++;
    }
}
class X{
    //short len;
    //int test;
    //char array[];
};
class Y :public virtual X{};
class Z :public virtual X{};
class A :public Z, public Y{};
int main(void)
{
    cout << sizeof(X)<<endl;
    cout << sizeof(Y) << endl;
    cout << sizeof(Z) << endl;
    cout << sizeof(A) << endl;
}