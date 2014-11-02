#include <iostream>
int count(int *A, int len, int index, int goal, int another)
{
    if (len-1 <= index) return 0;
    if (A[index] > (goal + another))
    {
        A[index + 1] = A[index + 1] + A[index] - goal - another;
        return count(A, len, index+1, goal, 0) + 1;
    }
    else if (A[index] == (goal + another))
    {
        return  count(A, len, index+1, goal, 0);
    }
    else
    {
        if (A[index + 1] + A[index] == goal * 2 + another)
        {
            return  count(A, len, index + 2, goal, another) + 1;
        }
        else if (A[index + 1] + A[index] > goal * 2 + another)
        {
            A[index + 2] = A[index + 1] + A[index] - (goal * 2 + another);
            return  count(A, len, index + 1, goal, another) + 1;
        }
        else
        {
            another = (goal * 2 + another) - (A[index + 1] + A[index]);
            return  count(A, len, index + 2, goal, another) + 2;
        }
    }
}
int main()
{
    //int len;
    //std::cin >> len;
    //int *A = new int[len];
    //int sum = 0;
    //int goal;
    //int tmp;
    //for (int i = 0; i < len; i++)
    //{
    //    std::cin >> tmp;
    //    sum = sum + tmp;
    //}
    //goal = sum / len;
    int A[4] = { 4, 1, 11, 24 };
    int len = 4;
    int goal = 10;
    int res = count(A, len, 0, goal, 0);
    return 0;

}