#include "com/header.h"
/*

Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

*/

// My thought while got this problem is the brote force
// the demand is to find how much contiguous substrings;
// that is maybe I should get all substrings at first,and then filter un-contiguous substrings
int countBinarySubstrings_mine(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = s.size() - 1; j > i; j--)
        {
            // cout << s.substr(i, j - i + 1) << endl;
            // then: how to filter the contiguous substring?
            //  we can't store the occurences of 0 and 1,that is kind of fool
            // I begin to find the main feature of contiguous string. A contiguous string means that the occurence of  0 shoud be equavilent to 1
            // so that I think a contiguous shoud meet these requirements:
            // 1. its length must be even
            // 2. the sum of all the characters must be even; But this feature seems like make no sense here,
            // cuz if i want to sum a substring, I have to travel all the characters of it
            // I try to solve it based on these two requirements.
            if ((j - i + 1) % 2 != 0)
                continue;
            int sum = 0;
            for (int n = i; n <= j; n++)
            {
                sum += s.at(n) - '0';
            }
            if (sum == (j - i + 1) / 2)
            {
                count++;
                cout << s.substr(i, j - i + 1) << endl;
            }
        }
    }
    return count;
}

int countBinarySubstrings(string s)
{
}

int main()
{
    // countBinarySubstrings_mine("10101");
    countBinarySubstrings_mine("00110");
}