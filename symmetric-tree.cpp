#include "com/header.h"
// https://leetcode.com/problems/symmetric-tree/

bool isMirror(TreeNode *child1, TreeNode *child2)
{
    if (child1 == NULL && child2 == NULL)
        return true;
    if (child1 == NULL || child2 == NULL)
        return false;
    return (child1->val == child2->val) && isMirror(child1->left, child2->right) && isMirror(child1->right, child2->left);
}

bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

// 非递归法，借助一个队列，将每层互为镜像的节点放在一起
// 就是说，对于一对兄弟节点A，B： 入队顺序为 A->left, B->right, A->right, B->left
bool isSymmetric_Iterate(TreeNode *root)
{
    if (root == NULL)
        return true;
    queue<TreeNode *> nodes_queue;
    nodes_queue.push(root);
    nodes_queue.push(root);
    while (!nodes_queue.empty())
    {
        TreeNode *child1 = nodes_queue.front();
        nodes_queue.pop();
        TreeNode *child2 = nodes_queue.front();
        nodes_queue.pop();

        if (child1 == NULL && child2 == NULL)
            continue;

        if (child1 == NULL || child2 == NULL)
            return false;

        if (child1->val != child2->val)
            return false;
        nodes_queue.push(child1->left);
        nodes_queue.push(child2->right);
        nodes_queue.push(child1->right);
        nodes_queue.push(child2->left);
    }
    return true;
}