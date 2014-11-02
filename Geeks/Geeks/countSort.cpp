#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void PrintArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << *(arr + i) << "\t";
    }
    cout << endl;
}
void countSort(int *arr, int len, int max)
{
    int *counts = new int[max + 1];
    int *output = new int[len];
    for (int i = 0; i <= max; i++)
    {
        counts[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        counts[arr[i]] += 1;
    }
    for (int i = 1; i <= max; i++)
    {
        counts[i] = counts[i - 1] + counts[i];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        output[counts[arr[i]] - 1] = arr[i];
        counts[arr[i]]--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = output[i];
    }
    delete[] counts;
    delete[] output;
}
void countSort1(int *arr, int len, int exp)
{
    int *counts = new int[10];
    int *output = new int[len];
    int radix = pow(10, exp);
    for (int i = 0; i <= 9; i++)
    {
        counts[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        counts[(arr[i] / radix) % 10] += 1;
    }
    for (int i = 1; i <= 9; i++)
    {
        counts[i] = counts[i - 1] + counts[i];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        output[counts[(arr[i] / radix) % 10] - 1] = arr[i];
        counts[(arr[i] / radix) % 10]--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = output[i];
    }
    delete[] counts;
    delete[] output;
}
auto lambda = [](const vector<int> data1, const vector<int> data2)
{
    data1[1] < data2[1];
};
bool ComPare(const vector<int> data1 ,const vector<int> data2)
{
    return (data1)[1] < (data2)[1];
}
int LongIncreaseSub(int Array[],int start,int &max)
{
    if (start == 0)
    {
        max = Array[start];
        return 1;
    }
    max = Array[start];
    int maxhere = 0;
    int len = 1;
    for (int i = 0; i < start; i++)
    {
        int lentmp = LongIncreaseSub(Array, i, maxhere);
        if (max > maxhere && (lentmp + 1) > len)
        {
            len = lentmp + 1;
        }
    }
    return len;
}

int main()
{
    auto lambda = [](const vector<int> data1, const vector<int> data2)-> bool
    {
        return data1[1] < data2[1];
    };
    int a[] = { 30,52,80,50,51,60,90,100};
    int max = 0;
    int res = LongIncreaseSub(a, 7, max);
    char ab = 255;
    cout << ab + 1 << endl;
    return 0;
}