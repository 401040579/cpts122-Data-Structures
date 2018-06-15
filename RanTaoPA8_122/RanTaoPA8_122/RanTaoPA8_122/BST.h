/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 8
* Created: April 9, 2016
* Last Revised: April 13, 2016
* Description:  For this assignment you are implementing a system for detecting trends in
consumer products over a 48 hour period. We are interested in knowing which products are
purchased and sold, the least and most, by various retail stores throughout the United States.
When a product is tagged as purchased it indicates that a certain retail store bought units
of the product from a supplier. When a product is tagged as sold it indicates that a certain
retail store sold that many units of a product. Your system must read product data from a .csv
file, and store the data in a way that inserts data in better than linear time (O(n)) in most
cases. Since, a binary search tree (BST) is a reasonably efficient data structure for inserting
and searching data (O (log n) for balanced trees), you must create two BSTs; one tree represents
the products that were sold and the other tree represents the products that were bought.
The system must leverage the organization of the trees to display, which products were least
bought and sold, and which were most bought and sold for that 48 hour period. Your system is
only required to output the following to the screen:
-      The contents of the two BSTs, which will be printed in order
-      The product that type and number of units that sold the most
-      The product that type and number of units that sold the least
-      The product that type and number of units that were purchased the most
-      The product that type and number of units that were purchased the least
*******************************************************************************************/
#pragma once
#include "TransactionNode.h"

/*Now define a class BST, which encapsulates the following:
Data members:
- mpRoot : Node * // yes, we want a pointer to a Node, not TransactionNode here!
 
          Member functions:
          + destructor // calls destroyTree ()
          - destroyTree () // yes, it¡¯s private, and it should visit each node in postOrder to delete them
          + default constructor
          + setter
          + getter
          + insert () // public used to hide pointer information, i.e. won¡¯t pass in the root of the tree into this function, only the private insert () function
- insert () // yes, it¡¯s private, and it dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on mUnits; should pass in a reference to a pointer (i.e. Node *& pT)
+ inOrderTraversal () // yes, once again it¡¯s private to hide pointer information
          - inOrderTraversal (), which recursively visits and prints the contents (mData and mUnits) of each node in the tree in order; each node¡¯s printData () should be called
  contents should be printed on a separate line; must call the printData () function associated with the TransactionNode
          + findSmallest (), which returns a reference to a TransactionNode (i.e TransactionNode &)  with the smallest mUnits
          + findLargest (), which returns a reference to a TransactionNode with the largest mUnits*/
class BST
{
public:
	BST();
	BST(const BST &rhs);
	~BST();

	Node *getRoot() const;

	void setRoot(Node * const newRoot);

	// will call on private insert (), pass through the data
	void insert(const string newData, const int newUnits); // newData - value to insert in tree
	void inorderTraversal();

	TransactionNode & findSmallest();
	TransactionNode & findLargest();
private:
	//Data members
	Node *mpRoot;

	//private function
	TransactionNode * makeNode(const string newData, const int newUnits);
	void destroyTree(Node * n);

	// this will be a recursive implementation!
	void insert(Node *& pTree, const string newData, const int newUnits); // helper to insert (), so

	void inorderTraversal(Node *pTree);

	TransactionNode& findSmallest(Node* pT);
	TransactionNode& findLargest(Node* pT);
};
