#include "com/header.h"

/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.



*/

// 跟前面那个找峰值的那个比较像

// 1. 扫描
int peakIndexInMountainArray(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > A[i + 1])
            return i;
    }
    return A.size() - 1;
}

// 2. 二分查找
int Bs_PeakIndexInMountainArray(vector<int> &A)
{
    int l = 0, r = A.size() - 1;
    while (l != r)
    {
        int mid = (l + r) / 2;
        if (A[mid] > A[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> case1{0, 1, 0};
    vector<int> case2{0, 2, 1, 0};
    cout << peakIndexInMountainArray(case1) << endl;
    cout << peakIndexInMountainArray(case2) << endl;
    cout << Bs_PeakIndexInMountainArray(case2) << endl;
}