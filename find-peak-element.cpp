#include "com/header.h"
/*
https://leetcode.com/problems/find-peak-element/
找顶峰元素,多个顶峰返回任意一个

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.

*/

// 太神奇了!
// 如果一个数大于后一个数 它就是顶峰
// [1,3,2]
// [4,3,2]

int findPeakElement(vector<int>& nums) {
    for(int i = 0; i < nums.size() - 1; i++){
       if( nums[i] > nums[i+ 1]  ){
            return i;
        }
    }
    return nums.size() - 1;
}

// 2分查找
int search(vector<int> nums, int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    // 如果中间元素大于右侧元素: 继续搜索mid左侧部分的元素，找左侧有没有更大的元素
    // 否则搜索mid右侧部分的元素
    if (nums[mid] > nums[mid + 1])
        return search(nums, l, mid);
    return search(nums, mid + 1, r);
}
int findPeakElement_Binary(vector<int> nums) {
    return search(nums, 0, nums.size() - 1);
}

int main(){
    vector<int>x{2,3};
    cout << findPeakElement_Binary(x);

}

