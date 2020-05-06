// https://leetcode.com/problems/leaf-similar-trees/
#include "com/header.h"

// if two tree have the same leafs , they are leaf similar tree
void dfs(TreeNode *root, vector<int> &nodes)
{
    if (root == NULL)
        return;
    dfs(root->left, nodes);
    dfs(root->right, nodes);
    if (root->left == NULL && root->right == NULL)
        nodes.push_back(root->val);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> leafs1, leafs2;
    dfs(root1, leafs1);
    dfs(root2, leafs2);
    return leafs1 == leafs2;
}

int main()
{
    vector<int> s{1, 2, 3, 4, 5, 6};
    TreeNode *root = composeTreeFromArray(s);
    outOrder(root);
    vector<int> leafs;
    cout << endl;
    dfs(root, leafs);
    printVector(leafs);
}