#include "com/header.h"

// 哥们儿字符串：如果A可以通过交换两个字符就能得到B 那么AB就是buddy string

bool buddyStrings(string A, string B) {
    int len_a = A.size(), len_b = B.size();
    if (len_a != len_b) return false;
    for(int i = 0; i < len_a - 1; i++){
        if(A[i] == B[i]) continue;
        if(A[i] == B[i+1] && A[i+1] == B[i]) return true;
    }

    return false;
}