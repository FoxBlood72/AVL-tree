#include "TreeNode.hpp"


TreeNode::TreeNode() 
{
	this->value = 0;
	this->left = nullptr;
	this->right = nullptr;
}
TreeNode::TreeNode(int v) 
{
	this->value = v;
	this->left = nullptr;
	this->right = nullptr;
}


TreeNode::~TreeNode()
{
	
}