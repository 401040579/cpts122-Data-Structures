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
#ifndef BST_H
#define BST_H

#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;

template <class C, class S>
class BST
{
public:
	BST();
	BST(const BST<C, S> &rhs);
	~BST();

	Node<C, S> *getRoot() const;

	void setRoot(Node<C, S> * const newRoot);

	// will call on private insert (), pass through the data
	void insert(const C newText, const S newMorse); // newData - value to insert in tree
	void inorderTraversal();
	void preorderTraversal();

	//void readMorseCode();

	S search(const C text);

	void convert();

private:
	Node<C, S> *mpRoot;

	Node<C, S> * makeNode(const C newText, const S newMorse);
	void destroyTree(Node<C, S> * n);

	// this will be a recursive implementation!
	void insert(Node<C, S> *& pTree, const C newText, const S newMorse); // helper to insert (), so

	void inorderTraversal(Node<C, S> *pTree);
	void preorderTraversal(Node<C, S> *pTree);// we can hide pointer info

	S search(Node<C, S> * pTree, const C text);
};
/////////////////////////////////////////////
/*************************************************************
* Function: BST()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: Constructor
* Return: NONE
*************************************************************/
template <class C, class S>
BST<C, S>::BST()
{
	ifstream input;
	char text;
	char morseCode[10];
	mpRoot = nullptr;

	input.open("MorseTable.txt", ios::in);
	while (!input.eof())
	{
		input >> text;
		input.getline(morseCode, 10);
		morseCode[strlen((morseCode)-1)] = NULL;
		insert(text, morseCode);
	}
	input.close();
}
/*************************************************************
* Function: BST(const BST<C,S> &rhs)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: copy Constructor
* Return: NONE
*************************************************************/
template <class C, class S>
BST<C, S>::BST(const BST<C, S> &rhs)
{
	this->mpRoot = rhs.mpRoot;
}
/*************************************************************
* Function: ~BST()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: Destructor
* Return: NONE
*************************************************************/
template <class C, class S>
BST<C, S>::~BST()
{
	destroyTree(mpRoot);
}
/*************************************************************
* Function: makeNode(const C newText, const S newMorse)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: make node
* Return: Node<C, S> *
*************************************************************/
template <class C, class S>
Node<C, S> * BST<C, S>::makeNode(const C newText, const S newMorse)
{
	Node<C, S> *pMem = new Node<C, S>(newText, newMorse);     // constructing a Node on the heap

	return pMem;
}
/*************************************************************
* Function: getRoot()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: return the mpRoot
* Return: Node<C, S> *
*************************************************************/
template <class C, class S>
Node<C, S> * BST<C, S>::getRoot() const
{
	return mpRoot;
}

// read the parameter type from right-to-left;
// newRoot is a constant pointer to a Node. This means
// the contents of newRoot can't be modified, but
// the Node can be modified!
/*************************************************************
* Function: setRoot(Node<C, S> * const newRoot)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: setter for root
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::setRoot(Node<C, S> * const newRoot)
{
	mpRoot = newRoot;
}
//void BST::readMorseCode()
//{
//
//}

/*************************************************************
* Function: convert()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: convert from txt
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::convert()
{
	ifstream input;
	char buffer[100];
	input.open("Convert.txt", ios::in);

	while (!input.eof())
	{
		input.getline(buffer, 100);
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] >= 97 && buffer[i] <= 122)
			{
				buffer[i] = buffer[i] - 32;
			}
		}

		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == 32)
			{
				cout << "  ";
			}
			else
			{
				cout << search(buffer[i]) << " ";
			}
		}
		cout << endl;
	}
	input.close();
}
/*************************************************************
* Function: search(const C text)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: search
* Return: template C
*************************************************************/
template <class C, class S>
S BST<C, S>::search(const C text)
{
	return search(mpRoot, text);
}
/*************************************************************
* Function: search(Node<C, S> * pTree, const C text)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: search ( ) function that will return the Morse code string for each English character searched for. 
* Return: template class C (may be char)
*************************************************************/
template <class C, class S>
S BST<C, S>::search(Node<C, S> * pTree, const C text)
{
	if (pTree == nullptr)
	{
		return "";
	}
	else if (text < pTree->getText())
	{
		return search(pTree->getLeft(), text);
	}
	else if (text > pTree->getText())
	{
		return search(pTree->getRight(), text);
	}
	else
	{
		return pTree->getMorse();
	}
}
/*************************************************************
* Function: insert(const C newText, const S newMorse)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: insert
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::insert(const C newText, const S newMorse)
{
	insert(mpRoot, newText, newMorse);
}

/*************************************************************
* Function: insert(Node<C, S> *& pTree, const C newText, const S newMorse)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: insert
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::insert(Node<C, S> *& pTree, const C newText, const S newMorse) // private member function
{
	//Node *pMem = makeNode(newData); // we have a node on heap

	if (pTree == nullptr) // checking to see if tree is empty, or if the subtree is empty
	{
		// insert a node into the tree
		Node<C, S> *pMem = makeNode(newText, newMorse); // we have a node on heap
		pTree = pMem;
	}
	else // recursive step
	{
		if (newText < (pTree)->getText()) // pTree points to current node
		{
			// How do we solve the issue of returning the address of
			// a value that is copied? Where is the copied value? Should
			// we pass the pointer back by reference? We'll address
			// these questions in lecture 3/7
			insert((pTree)->getLeft(), newText, newMorse);
		}
		else if (newText >(pTree)->getText()) // pTree points to current node
		{
			// How do we solve the issue of returning the address of
			// a value that is copied? Where is the copied value? Should
			// we pass the pointer back by reference? We'll address
			// these questions in lecture 3/7
			insert((pTree)->getRight(), newText, newMorse);
		}
	}

}
/*************************************************************
* Function: inorderTraversal()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: print tree in inorder
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::inorderTraversal()
{
	inorderTraversal(mpRoot); // private member function
}

/*************************************************************
* Function: inorderTraversal(Node<C, S> *pTree)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: print tree
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::inorderTraversal(Node<C, S> *pTree)
{
	if (pTree != nullptr)
	{
		// 1. go left
		inorderTraversal(pTree->getLeft());
		// 2. process node
		cout << "Data: " << pTree->getText() << endl;
		// 3. go right
		inorderTraversal(pTree->getRight());
	}
}
/*************************************************************
* Function: preorderTraversal()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: print tree in preorder
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::preorderTraversal()
{
	preorderTraversal(mpRoot);
}

// preorder traversal
/*************************************************************
* Function: preorderTraversal(Node<C, S> *pTree)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: print tree in preorder
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::preorderTraversal(Node<C, S> *pTree)
{
	if (pTree != nullptr)
	{
		// 1. process node
		cout << "Data: " << pTree->getText() << endl;
		// 2. go left
		preorderTraversal(pTree->getLeft());
		// 3. go right
		preorderTraversal(pTree->getRight());
	}
}
/*************************************************************
* Function: destroyTree(Node<C, S> * n)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: destroy tree
* Return: NONE
*************************************************************/
template <class C, class S>
void BST<C, S>::destroyTree(Node<C, S> * n)
{
	if (n != nullptr)
	{
		// this is peforming a postorder traversal to delete the nodes!
		destroyTree(n->getLeft()); // 1. go left
		destroyTree(n->getRight()); // 2. go right
		delete(n); // 3. process node
	}
}

#endif // !BST_H