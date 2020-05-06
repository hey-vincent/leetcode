#include "com/header.h"
#include <math.h>
// https://leetcode.com/problems/happy-number/
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
// 难点：暴力法，如何设定循环终止条件？如果循环地按位平方求和，什么时候循环结束？
// 如下暴力法 如果传入的不是happy nunber就会死循环
bool isHappy_force(int n)
{
    int sum = n;
    if (sum == 1)
        return true;

    while (sum != 1)
    {
        int tmp = 0;
        for (int num = sum; num != 0; num = num / 10)
        {
            tmp += (num % 10) * (num % 10);
        }
        sum = tmp;
    }

    return true;
}

// 解法，没明白是什么原理；跟链表找环问题类似，可以用相同的两种解法
bool isHappy_Mem(int n)
{
    int sum = n;
    if (sum == 1)
        return true;

    map<int, bool> hash;

    while (sum != 1)
    {
        int tmp = 0;
        for (int num = sum; num != 0; num = num / 10)
            tmp += pow((num % 10), 2);
        sum = tmp;
        if (hash[sum] == true)
            return false;
        hash[sum] = true;
    }

    return true;
}

// 也可以类似快慢指针那样，判断getSum(getSum(num)) == num; 这样内存空间少；

int main()
{
    cout << isHappy_Mem(19);
}