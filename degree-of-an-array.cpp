#include "./com/header.h"
/*

https://leetcode.com/problems/degree-of-an-array/

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

## Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
    The input array has a degree of 2 because both elements 1 and 2 appear twice.
    Of the subarrays that have the same degree:
    [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
    The shortest length is 2. So return 2.

## Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6


# Solution:
An array that has degree d, must have some element x occur d times. If some subarray has the same degree, then some element x (that occured d times), still occurs d times. The shortest such subarray would be from the first occurrence of x until the last occurrence.

For each element in the given array, let's know left, the index of its first occurrence; and right, the index of its last occurrence. For example, with nums = [1,2,3,2,5] we have left[2] = 1 and right[2] = 3.

Then, for each element x that occurs the maximum number of times, right[x] - left[x] + 1 will be our candidate answer, and we'll take the minimum of those candidates.

*/

// left, right 分别存储 某个元素E出现的最左最右位置 x,y
// count 存储E出现的次数T:  {E : T}
// 所以D==T时，最小的 y-x+1 就是最小的带度子串长度

int findShortestSubArray(vector<int> &nums)
{
    map<int, int> left, right, count;
    int degree = 0, length = nums.size();
    for (int i(0); i < nums.size(); ++i)
    {
        int elem = nums[i];
        right[elem] = i;
        degree = max(++count[elem], degree);
        if (left.find(elem) == left.end())
            left[elem] = i;
    }

    map<int, int>::iterator it = count.begin();
    for (; it != count.end(); it++)
    {
        if (it->second < degree)
            continue;
        length = min(length, right[it->first] - left[it->first] + 1);
    }

    return length;
}

int main()
{
    int a[] = {1, 2, 2, 3, 1, 4, 2};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    int n = findShortestSubArray(v);
    cout << n;
}