#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "TreeNode.hpp"


//using namespace std;
class AVLTree
{
	private:
		TreeNode *insertRecursion(TreeNode *r, TreeNode *new_node, bool &success);
		TreeNode *rightRotate(TreeNode * y);
		TreeNode *leftRotate(TreeNode * x);
		TreeNode *maxValueNode(TreeNode * node);
		TreeNode *succesorSearch(TreeNode *r, int val, bool &find, int &succesvalue);
		TreeNode *predecesorSearch(TreeNode *r, int val, bool &find, int &succesvalue);
		void k_elementSearch(TreeNode *r, unsigned int k, unsigned int &count, int &result);
		int nodes;
	public:
		TreeNode * root;
		AVLTree();
		bool isTreeEmpty();
		int height(TreeNode * r);
		int getBalanceFactor(TreeNode * n);
		bool insert(int x);
		int min();
		int max();
		int succesor(int val);
		int predecesor(int val);
		int este_in(int val);
		bool sterge(int v);
		int cardinal();
		int k_element(unsigned int k);
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
