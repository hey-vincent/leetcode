#include "./com/header.h"

// https://leetcode.com/problems/path-sum/

// 判断从一棵树的根节点出发，是否存在经过节点和

bool hasPathSum(TreeNode *root, int sum)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL && root->val == sum)
        return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

// case [1,2] sum = 1 结果应该为false 因为路径没有到叶子节点
// case [1] sum = 1 结果应该为 true 因为root 同时是 leaf
