#include "com/header.h"
/*
https://leetcode.com/problems/multiply-strings/

两个字符串 分别代表两个非负整数 求乘积

仍然是处理进位的问题; 但是这个处理起来要比加法复杂些；
“123” *  “111” , 对于长度为 x和y的两个数相乘，其结果最长为 x+ y
            1   2   3
        1   2   3
    1   2   3

申请x+y 长度的字符串M存放结果，将每位的字符初始化为’0‘
i1,i2 分别表示num1,num2的下标，将num[i1] * num[i2]的结果放入 M[i1 + i2 + 1] 的位置，并处理 M[i1 + i2]的进位
分别从两个数的低位开始，相乘： 3 * 1， 2 * 1， 1* 1, 将结果从尾部开始放入，每次放入的时候读取该位置当前值cur，
结算cur + 各位相乘结果， 然后处理进位
*/

string multiply(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size();
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    
    string mult(l1 + l2, '0');
    for(int i = l1 - 1; i >= 0; --i){
        for(int j = l2 - 1; j >= 0; --j){
            int m = (num1[i] - '0') * (num2[j] - '0'), cur = mult[i + j + 1] - '0', last = mult[i + j ] - '0';
            // 当前这一位
            mult[i + j + 1] = (cur + m) % 10 + '0';
            // 前一位（进位）
            mult[i + j] = (cur + m) / 10  + last + '0';
        }
    }
    int r = mult.find_first_not_of('0');
    if (string::npos != r) {
        return mult.substr(r);
    }
    return mult;
}


int main()
{

    string num1 = "123", num2 = "456";
    string n =  multiply(num1, num2);
	cout << n << endl;

    
	
	cout << 123 * 456 << endl;
}
