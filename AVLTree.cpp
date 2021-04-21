#include <iostream>
#include "AVLTree.hpp"
#include "TreeNode.hpp"

#define SPACE 10

using namespace std;

AVLTree::AVLTree() {
	this->root = nullptr;
	this->nodes = 0;
}


int AVLTree::cardinal()
{
	return this->nodes;
}

bool AVLTree::isTreeEmpty() {
	if (this->root == nullptr)
		return true;
	
	return false;
}
// Get Height
int AVLTree::height(TreeNode * r) {
	if (r == nullptr)
		return -1; // iesirea din recursiva
	else {
		/* compute the height of each subtree */
		int lheight = height(r -> left);
		int rheight = height(r -> right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1); // pt ca se returneaza -1
		else 
			return (rheight + 1); // pt ca se returneaza -1
	}
}

// Get Balance factor of node N
int AVLTree::getBalanceFactor(TreeNode * n) {
	if (n == nullptr)
		return -1;
	return height(n->left) - height(n->right);
}

TreeNode *AVLTree::rightRotate(TreeNode * y) {
	TreeNode * x = y -> left;
	TreeNode * T2 = x -> right;

	// Perform rotation
	x -> right = y;
	y -> left = T2;

	return x;
}

TreeNode *AVLTree::leftRotate(TreeNode * x) {
	TreeNode * y = x -> right;
	TreeNode * T2 = y -> left;

	// Perform rotation
	y -> left = x;
	x -> right = T2;

	return y;
}

bool AVLTree::insert(int x)
{
	TreeNode *new_node = new TreeNode(x);
	bool success;
	this->root = this->insertRecursion(this->root, new_node, success);
	if(success)
		this->nodes++;
	return success;
}

/*
 * Se primeste mereu nodul unde este mai potrivit pentru inserare
 * functia balanseaza copacul dupa inserarea nodului, adica cand primul if se indeplineste
 * sfarsitul functie se returneaza nodul nemodificat, exceptand ultimul nod unde se face inserarea
 * functi returneaza nodul tata al copacului
 */ 
TreeNode *AVLTree::insertRecursion(TreeNode * r, TreeNode *new_node, bool &success) {
	if (r == nullptr) { // oprirea functiei recursive
		r = new_node;
		success = true;
		return r;
	}

	if (new_node->value < r->value) 									// daca nodul curent este mai mare decat noul nod
		r->left = this->insertRecursion(r->left, new_node, success); 	// mergem la stanga
	else if (new_node->value > r->value)
		r->right = this->insertRecursion(r->right, new_node, success);
	else {
		success = false; // nu putem avea aceeasi valoare intr-o multime
		return r;
	}

	int bf = this->getBalanceFactor(r);
	// Left Left Case
	if (bf > 1 && new_node->value < r->left->value)
		return this->rightRotate(r);

	// Right Right Case
	if (bf < -1 && new_node->value > r->right->value)
		return this->leftRotate(r);

	// Left Right Case
	if (bf > 1 && new_node -> value > r->left->value) {
		r -> left = this->leftRotate(r->left);
		return this->rightRotate(r);
	}

	// Right Left Case
	if (bf < -1 && new_node->value < r ->right->value) {
		r->right = this->rightRotate(r -> right);
		return this->leftRotate(r);
	}

	// returnam nodul root fara al schimba
	return r;

}

int AVLTree::min()
{
	TreeNode *n = this->minValueNode(this->root);
	return n->value;
}

int AVLTree::max()
{
	TreeNode *n = this->maxValueNode(this->root);
	return n->value;
}


TreeNode *AVLTree::minValueNode(TreeNode * node) {
	TreeNode * current = node;
	/* loop down to find the leftmost leaf */
	while (current -> left != nullptr) {
		current = current -> left;
	}
	return current;
}


TreeNode *AVLTree::maxValueNode(TreeNode * node) {
	TreeNode * current = node;
	/* loop down to find the leftmost leaf */
	while (current -> right != nullptr) {
		current = current -> right;
	}
	return current;
}

bool AVLTree::sterge(int v)
{
	TreeNode *temp = this->recursiveSearch(this->root, v);
	if(temp != nullptr)
	{
		this->root = this->deleteNode(this->root, v);
		this->nodes--;
		return true;
	}
	
	return false;
}


TreeNode *AVLTree::deleteNode(TreeNode * r, int v)
{
    // arboele nu are niciun nod ||
    if (r == nullptr)
    {
        return nullptr;
    }
    // daca valoarea nodului de sters este < decat valoarea nodului radacina
    // stergerea se face din subarborele stang
    else if (v < r -> value)
    {
        // apel recursiv subarborele stang
        r -> left = deleteNode(r -> left, v);
    }
    // daca valoarea nodului de sters este > decat valoarea nodului radacina
    // stergerea se face din subarborele drept
    else if (v > r -> value)
    {
        // apel recursiv pentru subarborele drept
        r -> right = deleteNode(r -> right, v);
    }
        // daca valoarea nodului este aceeasi cu valoarea radacinii, atunci a fost gasit nodul  de sters
    else
    {
        // stergere nod frunza || nod cu un sigur fiu
        if (r -> left == nullptr) // are doar fiu drept
        {
            TreeNode * temp = r -> right; // "radacina" subarborelui drept
            delete r; // stergere pointer pentru nodul cu valoarea de sters
            return temp;
        }
        else if (r -> right == nullptr) // are doar fiu stang
        {
            TreeNode * temp = r -> left; // "radacina" subarborelui stang
            delete r; // stergere pointer pentru nodul cu valoarea de sters
            return temp;
        }
        else
        {
            // stergere nod cu doi fii
            // se considera cea mai mica valoarea din subarborele drept
            TreeNode * temp = minValueNode(r -> right); // pointer catre nodul cu valoarea minima din subarborele drept
            // retine valoarea ascestui succesor in nodul curent
            r -> value = temp -> value;
            // stergere succesor
            r -> right = deleteNode(r -> right, temp -> value);
 
        }
    }
    // se verifica balance factor pentru nodul curent
    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Right rotation
    if (bf == 2 && getBalanceFactor(r -> left) >= 0)
        return rightRotate(r);
    // Left Right Imbalance/LR rotation
    else if (bf == 2 && getBalanceFactor(r -> left) == -1) {
        r -> left = leftRotate(r -> left);
        return rightRotate(r);
    }
        // Right Right Imbalance/Left rotation
    else if (bf == -2 && getBalanceFactor(r -> right) <= -0)
        return leftRotate(r);
        // Right Left Imbalance/RL rotation
    else if (bf == -2 && getBalanceFactor(r -> right) == 1) {
        r -> right = rightRotate(r -> right);
        return leftRotate(r);
    }
 
    return r;
}

void AVLTree::print2D(TreeNode * r, int space) {
	if (r == nullptr) // Base case  1
		return;
	space += SPACE; // Increase distance between levels   2
	print2D(r -> right, space); // Process right child first 3
	cout << endl;
	for (int i = SPACE; i < space; i++) // 5
		cout << " "; // 5.1
	cout << r -> value << "\n"; // 6
	print2D(r -> left, space); // Process left child  7
}
void AVLTree::printPreorder(TreeNode * r) //(current node, Left, Right)
{
	if (r == nullptr)
		return;
	/* first print data of node */
	cout << r -> value << " ";
	/* then recur on left sutree */
	printPreorder(r -> left);
	/* now recur on right subtree */
	printPreorder(r -> right);
}


int AVLTree::k_element(unsigned int k)
{
	int result = 0;
	unsigned int count = 0;
	this->k_elementSearch(this->root, k, count, result);
	return result;
}

void AVLTree::k_elementSearch(TreeNode *r, unsigned int k, unsigned int &count, int &result)
{
	if (r == nullptr)
		return;
	
	this->k_elementSearch(r -> left, k, count, result);
	
	count++;
	if(k == count)
		result = r->value;
	
	this->k_elementSearch(r -> right, k, count, result);
}


void AVLTree::printInorder(TreeNode * r) //  (Left, current node, Right)
{
	if (r == nullptr)
		return;
	/* first recur on left child */
	printInorder(r -> left);
	/* then print the data of node */
	cout << r -> value << " ";
	/* now recur on right child */
	printInorder(r -> right);
}
void AVLTree::printPostorder(TreeNode * r) //(Left, Right, Root)
{
	if (r == nullptr)
		return;
	// first recur on left subtree
	printPostorder(r -> left);
	// then recur on right subtree
	printPostorder(r -> right);
	// now deal with the node
	cout << r -> value << " ";
}

/* Print nodes at a given level */
void AVLTree::printGivenLevel(TreeNode * r, int level) {
	if (r == nullptr)
		return;
	else if (level == 0)
		cout << r -> value << " ";
	else // level > 0
	{
		printGivenLevel(r -> left, level - 1);
		printGivenLevel(r -> right, level - 1);
	}
}
void AVLTree::printLevelOrderBFS(TreeNode * r) {
	int h = height(r);
	for (int i = 0; i <= h; i++)
		printGivenLevel(r, i);
}

TreeNode *AVLTree::iterativeSearch(int v) {
	if (root == nullptr) {
		return root;
	} else {
		TreeNode * temp = root;
		while (temp != nullptr) {
			if (v == temp -> value) {
				return temp;
			} else if (v < temp -> value) {
				temp = temp -> left;
			} else {
				temp = temp -> right;
			}
		}
		return nullptr;
	}
}

int AVLTree::succesor(int val)
{
	bool found;
	int result;
	this->succesorSearch(this->root, val, found, result);
	if(found)
		return result;
	
	return this->root->value;
}

int AVLTree::predecesor(int val)
{
	bool found;
	int result;
	this->predecesorSearch(this->root, val, found, result);
	if(found)
		return result;
	
	return this->root->value;
}

TreeNode *AVLTree::succesorSearch(TreeNode *r, int val, bool &find, int &succesvalue)
{
	if (r == nullptr) //daca radacina e nula sau valoarea este in radacina returnam r
	{
		find = false;
		return r;
	}
	else
	if(r->value == val)
	{
		if(r->right != nullptr)
		{
			TreeNode *min = this->minValueNode(r->right);
			succesvalue = min->value;
			find = true;
		}
		else
		{
			find = false;
		}
		return r;
	}
	else if (val < r -> value) //cautam in stanga daca val e mai mica
	{
		TreeNode *temp = this->succesorSearch(r -> left, val, find, succesvalue);
		if(!find)
		{
			if(r->value > val)
			{
				find = true;
				succesvalue = r->value;
			}
		}
		return temp;
	}
	else //cautam in dreapta daca val e mai mare
	{
		TreeNode *temp = this->succesorSearch(r -> right, val, find, succesvalue);  
		if(!find)
		{
			if(r->value > val)
			{
				find = true;
				succesvalue = r->value;
			}
		}
		return temp;
	} 
}


TreeNode *AVLTree::predecesorSearch(TreeNode *r, int val, bool &find, int &succesvalue)
{
	if (r == nullptr) //daca radacina e nula sau valoarea este in radacina returnam r
	{
		find = false;
		return r;
	}
	else
	if(r->value == val)
	{
		if(r->left != nullptr)
		{
			TreeNode *min = this->maxValueNode(r->left);
			succesvalue = min->value;
			find = true;
		}
		else
		{
			find = false;
		}
		return r;
	}
	else if (val < r -> value) //cautam in stanga daca val e mai mica
	{
		TreeNode *temp = this->predecesorSearch(r -> left, val, find, succesvalue);
		if(!find)
		{
			if(r->value < val)
			{
				find = true;
				succesvalue = r->value;
			}
		}
		return temp;
	}
	else //cautam in dreapta daca val e mai mare
	{
		TreeNode *temp = this->predecesorSearch(r -> right, val, find, succesvalue);  
		if(!find)
		{
			if(r->value < val)
			{
				find = true;
				succesvalue = r->value;
			}
		}
		return temp;
	} 
}


int AVLTree::este_in(int val)
{
	TreeNode *n = this->recursiveSearch(this->root, val);
	if(n != nullptr)
		return 1;
	
	return 0;
}


TreeNode *AVLTree::recursiveSearch(TreeNode * r, int val) 
{
	if (r == nullptr || r -> value == val) //daca radacina e nula sau valoarea este in radacina returnam r
		return r;
	else if (val < r -> value) //cautam in stanga daca val e mai mica
	{
		TreeNode *temp = recursiveSearch(r -> left, val);
		return temp;
	}
	else //cautam in dreapta daca val e mai mare
	{
		TreeNode *temp = recursiveSearch(r -> right, val);   
		return temp;
		
	} 
}




AVLTree::~AVLTree()
{
	
}
