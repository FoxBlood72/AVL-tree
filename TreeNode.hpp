#ifndef TREENODE_HPP
#define TREENODE_HPP

class TreeNode
{
	public:
		int value;
		TreeNode *left;
		TreeNode *right;
		TreeNode();
		TreeNode(int v);
		~TreeNode();

};

#endif // TREENODE_HPP
