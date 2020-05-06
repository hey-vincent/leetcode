
#include <iostream>
#include <vector>
using namespace std;

// 解决思路： 平方后，正数部分右侧最大，负数部分左侧最大
vector<int> squareArray(vector<int> nums)
{
    int len = nums.size();
    vector<int> sq(len, 0);

    int left = 0;
    int right = len - 1;
    int index = right;
    for (; right > left; index--)
    {
        int rn = abs(nums[right]);
        int ln = abs(nums[left]);
        if (rn > ln)
        {
            sq[index] = rn * rn;
            right--;
        }
        else
        {
            sq[index] = ln * ln;
            left++;
        }
    }
    return sq;
}

// High votes answer:
vector<int> sortedSquares(vector<int> &A)
{
    int len = A.size();
    vector<int> res(len, 0);
    int i = 0, j = len - 1;
    for (int k = len - 1; k >= 0; k--)
    {
        if (abs(A[i]) > abs(A[j]))
            res[k] = pow(A[i++], 2);
        else
            res[k] = pow(A[j--], 2);
    }
    return res;
}

int main()
{
    int arr[] = {-4, -1, 0, 1, 2, 9};
    vector<int> i(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> sq = squareArray(i);
    for (vector<int>::iterator it = sq.begin(); it != sq.end(); it++)
    {
        cout << *it << '\t';
    }
    return 0;
}
