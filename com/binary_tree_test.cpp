#include <iostream>
#include "./header.h"

int main()
{
	vector<int> source{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	TreeNode *root = composeTreeFromArray(source);
	visitTree(root);
	Bfs(root);
	Bfs_With_Wrap(root);
	return 0;
}
