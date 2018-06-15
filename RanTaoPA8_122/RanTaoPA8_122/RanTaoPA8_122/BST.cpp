#include "BST.h"
/*************************************************************
* Function: BST()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: Constructor
* Return: NONE
*************************************************************/
BST::BST()
{
	mpRoot = nullptr;
}
/*************************************************************
* Function: BST(const BST & rhs)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: copy Constructor
* Return: NONE
*************************************************************/
BST::BST(const BST & rhs)
{
	this->mpRoot = rhs.mpRoot;
}
/*************************************************************
* Function: ~BST()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: Destructor
* Return: NONE
*************************************************************/
BST::~BST()
{
	destroyTree(mpRoot);
}
/*************************************************************
* Function: destroyTree(Node * n)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: destroy tree
* Return: NONE
*************************************************************/
void BST::destroyTree(Node * n)
{
	if (n != nullptr)
	{
		// this is peforming a postorder traversal to delete the nodes!
		destroyTree(n->getLeft()); // 1. go left
		destroyTree(n->getRight()); // 2. go right
		delete(n); // 3. process node
	}
}
/*************************************************************
* Function: getRoot()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: get root point
* Return: Node * 
*************************************************************/
Node * BST::getRoot() const
{
	return mpRoot;
}
/*************************************************************
* Function: setRoot(Node * const newRoot)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: set Root
* Return: NONE
*************************************************************/
void BST::setRoot(Node * const newRoot)
{
	mpRoot = newRoot;
}
/*************************************************************
* Function: makeNode(const string newData, const int newUnits)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: make a dynamically allocates
* Return: TransactionNode *
*************************************************************/
TransactionNode * BST::makeNode(const string newData, const int newUnits)
{
	TransactionNode *pMem = new TransactionNode(newData, newUnits);
	return pMem;
}
/*************************************************************
* Function: insert(const string newData,const int newUnits)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: insert a node
* Return: NONE
*************************************************************/
void BST::insert(const string newData, const int newUnits)
{
	insert(mpRoot, newData, newUnits);
}
/*************************************************************
* Function: insert(Node *& pTree, const string newData, const int newUnits)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: insert
* Return: NONE
*************************************************************/

void BST::insert(Node *& pTree, const string newData, const int newUnits)
{
	if (pTree == nullptr) // checking to see if tree is empty, or if the subtree is empty
	{
		// insert TransactionNode
		TransactionNode *pMem = makeNode(newData, newUnits); // we have a node on heap
		pTree = pMem;
	}
	else
	{
		if (newUnits < (pTree)->getUnits())
		{
			insert((pTree)->getLeft(), newData, newUnits);
		}
		else if (newUnits >(pTree)->getUnits())
		{
			insert((pTree)->getRight(), newData, newUnits);
		}
	}
}
/*************************************************************
* Function: inorderTraversal()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: inorder traversal
* Return: NONE
*************************************************************/
void BST::inorderTraversal()
{
	inorderTraversal(mpRoot);
}
/*************************************************************
* Function: findSmallest()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: find Smallest
* Return: TransactionNode &
*************************************************************/
TransactionNode & BST::findSmallest()
{
	return findSmallest(mpRoot);
}
/*************************************************************
* Function: findLargest()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: find Largest
* Return: TransactionNode &
*************************************************************/
TransactionNode & BST::findLargest()
{
	return findLargest(mpRoot);
}
/*************************************************************
* Function: inorderTraversal(Node * pTree)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: inorder traversal
* Return: NONE
*************************************************************/
void BST::inorderTraversal(Node * pTree)
{
	if (pTree != nullptr)
	{
		// 1. go left
		inorderTraversal(pTree->getLeft());
		// 2. process node
		pTree->printData();
		// 3. go right
		inorderTraversal(pTree->getRight());
	}
}
/*************************************************************
* Function: findSmallest()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: find Smallest
* Return: TransactionNode &
*************************************************************/
TransactionNode & BST::findSmallest(Node * pT)
{
	while (pT->getLeft() != nullptr)
	{
		pT = pT->getLeft();
	}
	return *(TransactionNode*)pT;
}
/*************************************************************
* Function: findLargest()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: find Largest
* Return: TransactionNode &
*************************************************************/
TransactionNode & BST::findLargest(Node * pT)
{
	while (pT->getRight() != nullptr)
	{
		pT = pT->getRight();
	}
	return *(TransactionNode*)pT;
}
