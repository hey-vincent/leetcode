#include "com/header.h"
/*
https://leetcode.com/problems/pascals-triangle/

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> rows;
    for(int i(0); i < numRows; i++){
        vector<int> row(i+1,1);
        for(int k = 0; i != 0 && k < i+1; k++){
            // 对于某一行i，其上一行下标空间，[0, i-1]
           if (k >= 1 && k <= i - 1)
                row[k] = rows[i-1][k-1] + rows[i-1][k];
        }
        rows.push_back(row);
    }
    return rows;
}

int main(){
    vector<vector<int>> rows = generate(6);
    for(int i = 0; i < rows.size(); i++){
        for(int k = 0; k < rows[i].size(); k++){
            cout << rows[i][k] << '\t';
        }
        cout << endl;
    }
}