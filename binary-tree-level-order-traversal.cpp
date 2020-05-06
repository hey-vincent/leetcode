#include "com/header.h"

// https://leetcode.com/problems/binary-tree-level-order-traversal/
// 按层遍历二叉树

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Accepted
359,246
Submissions
750,897
*/

// 总体思路： 队列初始化为头结点
// 访问队列，拿到节点，将子节点放到对列尾部，子节点个数增加
// 直到队列中无元素
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> layer;
    vector<vector<int>> ret;
    if (root == NULL)
        return ret;
    layer.push(root);
    int nodes_count = 1;

    while (nodes_count > 0)
    {
        int tmp = 0;
        vector<int> l;
        for (int i = 0; i < nodes_count; i++)
        {
            TreeNode *node = layer.front();
            layer.pop();
            l.push_back(node->val);
            if (node->left != NULL)
            {
                layer.push(node->left);
                tmp += 1;
            }
            if (node->right != NULL)
            {
                layer.push(node->right);
                tmp += 1;
            }
        }
        ret.push_back(l);
        nodes_count = tmp;
    }
    return ret;
}