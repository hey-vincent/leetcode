#include "./com/header.h"
//https://leetcode.com/problems/monotonic-array/
// 单调数列：如果一个数列是单调递增或递减的，它就是单调数列
// [1,2,2,3,4]
// 思路： 忽略掉相同的元素，任何时候相同的元素都对结果没有任何影响

bool isMonotonic(vector<int> &A)
{

    int trend = INT_MIN;

    for (int i = 0; i < A.size() - 1; i++)
    {
        int cmp = A[i] - A[i + 1];
        // 相等不比较
        if (cmp == 0)
        {
            continue;
        }

        // 设置当前的趋势
        if (trend == INT_MIN)
        {
            trend = cmp;
            continue;
        }

        // 如果当前的趋势与总趋势一致
        if (trend * cmp > 0)
            continue;

        return false;
    }

    return true;
}

int main()
{
    int x[] = {2, 2, 2, 1, 4, 5};
    vector<int> A(x, x + sizeof(x) / sizeof(int));
    int y[] = {1, 3, 2};
    vector<int> B(y, y + sizeof(y) / sizeof(int));
    printf("%d", isMonotonic(A));
    printf("%d", isMonotonic(B));
}
