#include "./listnode.h"
#include "./binary_tree.h"
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;

inline void printVector(vector<int> v)
{
    int i = 0;
    while (i < v.size())
    {
        cout << v[i++] << '\t';
    }
    cout << endl;
}