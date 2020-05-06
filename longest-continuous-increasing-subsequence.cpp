#include "com/header.h"

/*
https://leetcode.com/problems/longest-continuous-increasing-subsequence/

Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.
*/

int findLengthOfLCIS(vector<int> &nums)
{
    int i = 0, j = 0, len = 0, count = nums.size();
    while (j < count)
    {
        if (j == count - 1 || nums[j] >= nums[j + 1])
        {
            len = max(j - i + 1, len);
            i = j + 1;
        }
        j++;
    }
    return len;
}

int findLengthOfLCIS_OnePass(vector<int> &nums)
{
    int res = 1, len = nums.size(), inc = 1;
    if (len <= 0)
        return 0;
    for (int i = 0; i <= len - 2; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            res = max(res, ++inc);
        }
        else
        {
            inc = 1;
        }
    }
    return res;
}

int main()
{
    vector<int> case1{1, 3, 5, 7};
    vector<int> case2;
    vector<int> case3{1, 3, 5, 4};
    vector<int> case4{2, 2, 2, 2};

    cout << findLengthOfLCIS(case1) << '\t' << findLengthOfLCIS_OnePass(case1) << endl;
    cout << findLengthOfLCIS(case2) << '\t' << findLengthOfLCIS_OnePass(case2) << endl;
    cout << findLengthOfLCIS(case3) << '\t' << findLengthOfLCIS_OnePass(case3) << endl;
    cout << findLengthOfLCIS(case4) << '\t' << findLengthOfLCIS_OnePass(case4) << endl;
}