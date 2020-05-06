#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-array-by-parity/

// 问题：将非负整数数组 输出位 偶数在前 奇数在后
// 主要思想：双指针,原地交换

vector<int> sortArrayByParity(vector<int> &A)
{
    int len = A.size();
    for (int l = 0, r = len - 1; l <= r;)
    {
        if (A[l] % 2 == 0)
        {
            l++;
            continue;
        }

        if (A[r] % 2 != 0)
        {
            r--;
            continue;
        }

        // 使用vector内置交换
        // int tmp = A[l];
        // A[l] = A[r];
        // A[r] = tmp;
        iter_swap(A.begin() + l, A.begin() + r);
    }
    return A;
}

vector<int> sortArrayByParity_Optimize(vector<int> &A)
{
    int l = 0, r = A.size() - 1;
    // 使用while 使代码更简洁，len变量后面没用
    while (l <= r)
    {

        if (A[l] % 2 == 0)
        {
            l++;
            continue;
        }

        if (A[r] % 2 != 0)
        {
            r--;
            continue;
        }

        // 使用vector内置交换
        iter_swap(A.begin() + l, A.begin() + r);
    }
    return A;
}

// 使用相同方向的快慢指针也能实现：
// 快指针的任务是寻找符合条件的元素，慢指针任务是寻找不符合条件的元素，等待快指针找到与之交换
vector<int> sortArrayByParity_V2(vector<int> &A)
{
    int slow = 0, quick = 0;
    while (quick < A.size())
    {
        // 如果当前元素为偶数 继续向后寻找
        if (A[slow] % 2 == 0)
        {
            slow++;
        }
        else
        {
            // 当前元素为奇数，停下等待快指针找到偶数 与之交换
            if (A[quick] % 2 == 0)
            {
                iter_swap(A.begin() + slow, A.begin() + quick);
                slow++;
            }
        }

        quick++;
    }
    return A;
}

// 上面这个代码可以简化：
vector<int> sortArrayByParityV21(vector<int> &A)
{
    // slow 与 quick是从同一起点出发的
    // 那么slow走过的地方quick应该同时或者先走过，quick奇数的时候 slow停下
    // quick 找到偶数的时候交换，这时候quick与slow之间的区域全是奇数
    int slow = 0, quick = 0;
    while (quick < A.size())
    {

        if (A[quick] % 2 == 0)
        {
            iter_swap(A.begin() + slow, A.begin() + quick);
            slow++;
        }

        quick++;
    }
    return A;
}

int main()
{
    int a[] = {3, 1, 2, 4};
    vector<int> A(a, a + 4);
    vector<int> r = sortArrayByParity_V2(A);
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << '\t';
    }
}