/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 6
* Created: March 19, 2016
* Last Revised: March 23, 2016
* Description:  a Binary Search Tree (BST) data structure is a nonlinear data structure.
A BST is traversed by starting at the root pointer. The root node is the first node inserted
into the tree. Nodes are inserted into the tree such that all items to the left of the root
node are less than, and all items to the right of the root are greater than its item. Also,
this property holds true for any particular node in the tree.
*******************************************************************************************/
#include "BST.h"

int main(void) 
{
	BST<char, string> tree;

	tree.inorderTraversal(); //alphabetically
	tree.convert();

	return 0;
	//cout << tree.search('Z');
}