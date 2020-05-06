#include "com/header.h"
/*

Given a string S, 
return the "reversed" string where all characters that are not a letter stay in the same place,
 and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

*/

// 双指针：原地交换，只翻转字母，也就是说非字母的位置不能改变

bool isLetter(char c)
{
    if (65 <= c && c <= 90)
        return true;
    if (97 <= c && c <= 122)
        return true;
    return false;
}
string reverseOnlyLetters(string S)
{
    int left = 0, right = S.size() - 1;
    while (left < right)
    {
        if (!isLetter(S[left]))
        {
            left++;
            continue;
        }
        if (!isLetter(S[right]))
        {
            right--;
            continue;
        }
        char temp = S[left];
        S[left] = S[right];
        S[right] = temp;
        left++;
        right--;
    }
    return S;
}

string reverseOnlyLetters_Stack(string S)
{
    stack<char> letters;
    for (int i = 0; i < S.size(); i++)
    {
        if (isLetter(S[i]))
            letters.push(S[i]);
    }

    for (int i = 0; i < S.size(); i++)
    {
        if (isLetter(S[i]))
        {
            S[i] = letters.top();
            letters.pop();
        }
    }
    return S;
}

int main()
{
    cout << reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
    cout << reverseOnlyLetters_Stack("Test1ng-Leet=code-Q!") << endl;
    cout << reverseOnlyLetters_Stack("Ni Hao Hello World !") << endl;
    cout << int('A') << "\t" << int('Z') << "\t" << int('a') << "\t" << int('z') << endl;
}