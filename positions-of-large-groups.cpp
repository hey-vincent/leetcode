#include "./com/header.h"

/*
https://leetcode.com/problems/positions-of-large-groups/

In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
*/

// 双指针：i 保存起始位置。 j 用于遍历：
// 对比j 和 j+1如果不等 计算间距， 刷新i位置, 相等时 i停下

vector<vector<int> > largeGroupPositions(string S)
{
   vector<vector<int> > res;
    int i = 0, j = 0;
    while(j < S.size()){
        if(S[j] != S[j+1] || j == S.size() - 1){
            if(j - i + 1 >= 3){
                res.push_back(vector<int>{i, j});
            }
            i = j+1;
        }
        j++;
    }
    return res;
}


// * 对比 i 和 j 不可取，会被结尾处搞疯
// 正常情况下 i 如果不等于j，说明 ij之前是重复串
// 但是结尾的时候：也跳进去了，这时候i和j位置的元素是不一定相同的
vector<vector<int> > largeGroupPositions_bad(string S)
{
    vector<vector<int> > res;
    int i = 0, j = 1;
    while (j < S.size())
    {
        // 每次不同的时候设置前一位
        if ( (j != S.size() - 1 && S[i] != S[j]) || (j == S.size() - 1 && S[j] == S[i]) )
        {
            int start = i;
            int end = (j == S.size() - 1) ? j : j - 1;
            // i, j-1 之间是相同的
            if(end - start + 1 >= 3){
                cout << "found i = " << start << "j=" << end << endl;
                vector<int> p;
                p.push_back(start);
                p.push_back(end);
                res.push_back(p);
            }

            i = j;
        }
        j++;
    }
    return res;
}



int main(){
    string s = "abbxxxxzzy";
    largeGroupPositions(s);
}