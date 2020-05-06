#include "com/header.h"

/*
https://leetcode.com/problems/maximum-product-of-three-numbers/

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/


// 排序： 两个负数相乘 可能大于两个正数的积
int maximumProduct_Sort(vector<int>& nums){
    sort(nums.begin(), nums.end() );
    vector<int>::iterator it = nums.end(), bt = nums.begin();
    return max(*(it - 1) *(*bt) * (*(bt+1)), *(it - 1) * (*(it-2)) * (*(it - 3)) );
}

// O(N) 做法 只存储 最大的三个 和 最小的两个数
int maximumProduct_Onepass(vector<int>& nums) {
    // 因为和数组里面可能同时存在正负数，初值很重要
    int m1 = INT_MIN, m2 = m1, m3 = m1, l1 = INT_MAX, l2 = l1;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it){
        if(*it > m1){
            m3 = m2;
            m2 = m1;
            m1 = *it;
        }else if(*it > m2){
            m3 = m2;
            m2 = *it;
        }else if(*it > m3){
            m3 = *it;
        }

        if(*it < l1){
            l2 = l1;
            l1 = * it;
        }else if(*it < l2){
            l2 = *it;
        }
    }
    
    return max(m1 * m2 * m3 , m1 * l1 * l2);
}

int maximumProduct_Onepass_B(vector<int>& nums) {
    // 因为和数组里面可能同时存在正负数，初值很重要
    int m1 = INT_MIN, m2 = m1, m3 = m1, l1 = INT_MAX, l2 = l1;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it){
        if(*it > m1){
            m3 = m2;
            m2 = m1;
            m1 = *it;
        }else if(*it > m2){
            m3 = m2;
            m2 = *it;
        }else if(*it > m3){
            m3 = *it;
        }

        if(*it < l1){
            l2 = l1;
            l1 = * it;
        }else if(*it < l2){
            l2 = *it;
        }
    }
    
    return max(m1 * m2 * m3 , m1 * l1 * l2);
}


int main(){
    vector<int> case1{-1, -10, 4, 1,2,3};
    vector<int> case2{-1,-2,-3};
    cout << maximumProduct_Sort(case1) << '\t' << maximumProduct_Sort(case2) << endl;
    cout << maximumProduct_Onepass(case1) << '\t' << maximumProduct_Onepass(case2) << endl;
}