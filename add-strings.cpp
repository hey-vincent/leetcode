#include "com/header.h"

// https://leetcode.com/problems/buddy-strings/

// 字符串代表的数字相加
// 跟int 数组一样，处理进位就行

string addStrings(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size(),slen = max(l1,l2) + 1, carry = 0, index = slen-1;
    string sum(slen, '0');
    l1--;
    l2--;
    while(l1 >= 0 || l2 >= 0 || carry != 0){
        int s = carry;
        if(l1 >= 0){
            s += num1[l1] - '0'; 
            l1--;
        }

        if(l2 >= 0){
            s += num2[l2] - '0'; 
            l2--;
        }

        sum[index--] = (s % 10) + '0';
        carry = s / 10;
    }

    // if (carry != 0) {
    //      sum[index--] =  carry + '0';
    // }

    return index < 0 ? sum : sum.substr(index + 1);
    
}

int main(){
    cout << addStrings("123", "456") << endl;
    cout << addStrings("123", "0") << endl;

    cout << addStrings("1", "999") << endl;

    cout << addStrings("1", "1") << endl;

}