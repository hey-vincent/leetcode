#include "com/header.h"

// https://leetcode.com/problems/self-dividing-numbers/
// 如果一个数能被这个数的每一位整除它就是self-deviding number
// 求  [left, right] 之间的self-devided number

// 1.暴力法
vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> ret;
    for (int i = left; i <= right; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (j % 10 == 0 || i % (j % 10) != 0)
                break;
            j = j / 10;
        }
        if (j == 0)
            ret.push_back(i);
    }
    return ret;
}

int main()
{
    vector<int> ret = selfDividingNumbers(0, 22);
    printVector(ret);
}