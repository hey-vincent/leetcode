#include "com/header.h"
/*
https://leetcode.com/problems/plus-one/

// 给定一个代表整数的，数组，给整数加1，输出结果
// 相加问题，主要需要解决的就是进位
// 初步两种思路：1. 从尾部相加，进位向前插 2.从尾部相加，push_back, 然后 reverse
// 1. 进位 2.空数组
*/

vector<int> plusOne(vector<int> &digits)
{
    int len = digits.size(), carry = 0;
    for (int i(len - 1); i >= 0; --i)
    {
        digits[i] = digits[i] + (i == len - 1 ? 1 : carry) ;
        carry = digits[i] / 10;
        digits[i] = digits[i] % 10;
    }

    if (carry != 0){
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main(){
    vector<int> case1{1,2,3};
    vector<int> case2{1,2,9};
    vector<int> case3{9,9,9,9};

    printVector(plusOne(case1));
    printVector(plusOne(case2));
    printVector(plusOne(case3));

}