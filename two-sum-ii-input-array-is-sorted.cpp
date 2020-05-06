
#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
// 给定升序数组numbers 和 一个数target
// 求哪两个数的和是target

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> res;
    int i = 0, j = numbers.size() - 1;
    while (i < j)
    {
        int nsum = numbers[j] + numbers[i];
        if (nsum == target)
        {
            return vector<int>{i + 1, j + 1};
        }

        if (nsum > target)
        {
            j--;
        }
        else
            i++;
    }
    return res;
}