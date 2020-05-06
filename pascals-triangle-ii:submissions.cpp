#include "./com/header.h"
/*

https://leetcode.com/problems/pascals-triangle-ii/

使用O（K）空间 输出Pascals三角形的第K行的元素

*/

// 总结
// 1. i, j 都从0开始索引，对于 i 行， 存在 i + 1 个元素
// 1. 对于第i行第j元素: Rows[i][j] = Rows[i-1][j-1] + Rows[i-1][j]
//      所以，只用限定好边间情况，在第层时候，访问上层元素时候元素边界是[0, i - 1]
//      而对于第i行，只能选取[1, i - 1] 区间来读取上一层元素 求和
//
/* 
for i < row_index:
    row(i+1, 1); // initialize 
    for j=1; j < i; j++:
        row[j] = rows[i-1][j] + row[i-1][j-1];
*/

// 如果使用O(K)空间，需要注意的地方：rows[2][1] 这个元素需要参与rows[3][1] 和 rows[3][2]位置的计算
// 所以，如果以index = 3取申请4个元素的数组，i = 2 的元素存存储情况就是 {1,2,1,1}, 后两个1 对于i = 2这行是用不上的
// 再来算i = 3, 如果正序算就是{1,3,3,1} 但是算到第二个元素的时候第二个元素已经被覆盖了，会影响到第三个元素的值
// 所以 倒序算：{1,2,3,1} => {1,3,3,1}
vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1, 1);
    // vector<vector<int>> rows;
    for (int i = 0; i < rowIndex + 1; i++)
    {
        // vector<int>row(i+1, 1);
        for (int j = i - 1; j > 0; j--)
        {
            row[j] += row[j - 1];
        }
        // rows.push_back(row);
    }
    return row;
}