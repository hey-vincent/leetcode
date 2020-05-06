#include "com/header.h"

// https://leetcode.com/problems/path-sum-iii/

// 返回一棵树中节点和为sum的路径数量
// 对于根节点root，和为sum的可能性有三种
// 1. 算上root， 然后向下找 和为sum的情况
// 2. 不算root， 从左子树找 和为sum的情况
// 3. 不算root， 从右子树找 何为sum的情况

// 从node开始向下找和为sum的路径数
int findFrom(TreeNode *node, int sum)
{
    if (node == NULL)
        return 0;
    sum -= node->val;
    return (sum == 0 ? 1 : 0) + findFrom(node->left, sum) + findFrom(node->right, sum);
}

int pathSum(TreeNode *root, int sum)
{
    if (root == NULL)
        return 0;
    // 找从root出发的情况 + 从 left 出发的情况 + 从right出发的情况： 这个地方不是很好理解
    return findFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}
