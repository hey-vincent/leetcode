#include "com/header.h"

/*
https://leetcode.com/problems/add-to-array-form-of-integer/

for a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

*/

// 1分解法： 将A转为数字，再将A+K转为数组
// 问题：1. num 可能溢出
// 2. 将数字转为数组的时候，从低位到高位，每次都朝前插入效率低
vector<int> addToArrayForm_ToInt(vector<int> &A, int K)
{
    int len = A.size();
    int num = K, carry = 1;
    for (int i = len - 1; i >= 0; --i)
    {
        num += A[i] * carry;
        carry *= 10;
    }
    // 结果数组的长度？
    vector<int> res;
    while (num != 0)
    {
        res.insert(res.begin(), num % 10);
        num = num / 10;
    }
    return res;
}

// 2points solution: resolved overflow, but still very mechanism
vector<int> addToArrayForm_ArrayMerge(vector<int> &A, int K)
{
    vector<int> k_arr;
    while (K != 0)
    {
        k_arr.insert(k_arr.begin(), K % 10);
        K = K / 10;
    }

    vector<int> res;
    int x = A.size() - 1, y = k_arr.size() - 1, carry = 0;
    while (x >= 0 || y >= 0)
    {
        int sum = carry;
        if (x >= 0)
        {
            sum += A[x];
            x--;
        }

        if (y >= 0)
        {
            sum += k_arr[y];
            y--;
        }

        res.insert(res.begin(), sum % 10);
        carry = sum / 10;
    }

    if (carry > 0)
    {
        res.insert(res.begin(), carry);
    }

    return res;
}

// Thinking: why should convert int to array or array to int ?
// Do A and K should be the same type? I convernt them to the same type to be easy to add every pos
// But it's not necessary to get every postion from an array! You can also get it from integer.
// Briefly, just keep what yout want to do: get every positon's number.
// PERFECT SOLUTION:
vector<int> addToArrayForm(vector<int> &A, int K)
{
    int carry = 0, i = A.size() - 1;
    vector<int> res;
    while (K != 0 || i >= 0)
    {
        int sum = carry;
        if (K != 0)
            sum += K % 10;
        if (i >= 0)
            sum += A[i--];
        K = K / 10;
        carry = sum / 10;
        res.push_back(sum % 10);
    }
    if (carry > 0)
        res.push_back(carry);
    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> A{1, 2, 0, 0};
    int K = 34;
    printVector(addToArrayForm(A, K));
    printVector(addToArrayForm_ArrayMerge(A, K));
}