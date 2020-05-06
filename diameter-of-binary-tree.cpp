#include "com/header.h"

//diameter - of - binary - tree

// https: //leetcode.com/problems/diameter-of-binary-tree/

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

*/

int depth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

int diameterOfBinaryTree(TreeNode *root)
{
    int n = 0;
    if (root == NULL)
        return n;
    if (NULL != root->left)
        ++n;
    if (NULL != root->right)
        ++n;
    return n + depth(root->left) + depth(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << depth(root);
    cout << "done" << endl;
    cout << diameterOfBinaryTree(root);
}
