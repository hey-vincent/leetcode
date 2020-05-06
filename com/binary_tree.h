#include <vector>
#include <queue>
#include <stack>

typedef struct _TreeNode
{
      int val;
      _TreeNode *left;
      _TreeNode *right;
      _TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

TreeNode *composeTreeFromArray(vector<int> source)
{
      TreeNode *root = NULL;
      vector<TreeNode *> nodes;
      for (int i(0); i < source.size(); ++i)
      {
            nodes.push_back(new TreeNode(source[i]));
      }
      for (int i(0); i < nodes.size(); ++i)
      {
            if (i == 0)
                  root = nodes.at(i);
            int left = 2 * i + 1, right = left + 1;
            if (left < nodes.size())
                  nodes[i]->left = nodes.at(left);
            if (right < nodes.size())
                  nodes[i]->right = nodes.at(right);
      }
      return root;
}

void visitTree(TreeNode *root)
{
      if (root == NULL)
            return;
      visitTree(root->left);
      cout << root->val << endl;
      visitTree(root->right);
}

void outOrder(TreeNode *root)
{
      if (root == NULL)
            return;
      outOrder(root->left);
      outOrder(root->right);
      cout << root->val << "\t";
}

inline void Bfs(TreeNode *root)
{
      queue<TreeNode *> wait_nodes;
      wait_nodes.push(root);
      while (!wait_nodes.empty())
      {
            TreeNode *p = wait_nodes.front();
            wait_nodes.pop();

            cout << p->val << "\t";
            if (NULL != p->left)
                  wait_nodes.push(p->left);
            if (NULL != p->right)
                  wait_nodes.push(p->right);
      }
      cout << endl;
}

// BFS 层带换行
inline void Bfs_With_Wrap(TreeNode *root)
{
      queue<TreeNode *> wait_nodes;
      wait_nodes.push(root);
      int level_nodes_count = wait_nodes.size();
      while (!wait_nodes.empty())
      {
            TreeNode *p = wait_nodes.front();
            wait_nodes.pop();

            cout << p->val << "\t";
            if (NULL != p->left)
                  wait_nodes.push(p->left);
            if (NULL != p->right)
                  wait_nodes.push(p->right);

            if (--level_nodes_count == 0)
            {
                  cout << endl;
                  level_nodes_count = wait_nodes.size();
            }
      }
      cout << endl;
}

inline void Dfs(TreeNode *root)
{
      stack<TreeNode *> nodes;
      if (root == NULL)
            return;
      nodes.push(root);
      while (!nodes.empty())
      {
            TreeNode *node = nodes.top();
            cout << node->val << "\t";
            nodes.pop();
            if (NULL != node->right)
                  nodes.push(node->right);
            if (NULL != node->left)
                  nodes.push(node->left);
      }
      cout << endl;
}