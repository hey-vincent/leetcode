#include <iostream>
#include <string>
using namespace std;

// https://leetcode.com/problems/add-binary/
// 与add链表一样

string addBinary(string a, string b) {
  int la = a.size() - 1, lb = b.size() - 1;
  int carry = 0;

  string res;
  while (la >= 0 || lb >= 0) {
    int sum = carry;
    sum += (la >= 0) ? (a.at(la--) - '0') : 0;
    sum += (lb >= 0) ? (b.at(lb--) - '0') : 0;
    carry = sum / 2;
    sum = sum % 2;
    res = char(sum + '0') + res;
  }

  if (carry > 0) {
    res = '1' + res;
  }
  return res;
}
