#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "TreeNode.hpp"


//using namespace std;
class AVLTree
{
	public:
		TreeNode * root;
		AVLTree();
		bool isTreeEmpty();
		int height(TreeNode * r);
		int getBalanceFactor(TreeNode * n);
		TreeNode *rightRotate(TreeNode * y);
		TreeNode *leftRotate(TreeNode * x);
		TreeNode *insert(TreeNode * r, TreeNode * new_node);
		TreeNode *minValueNode(TreeNode * node) ;
		TreeNode * deleteNode(TreeNode * r, int v);
		void print2D(TreeNode * r, int space);
		void printPreorder(TreeNode * r);
		void printInorder(TreeNode * r);
		void printPostorder(TreeNode * r);
		void printGivenLevel(TreeNode * r, int level);
		void printLevelOrderBFS(TreeNode * r);
		TreeNode *iterativeSearch(int v);
		TreeNode *recursiveSearch(TreeNode * r, int val);
		~AVLTree();

};

#endif // AVLTREE_HPP
