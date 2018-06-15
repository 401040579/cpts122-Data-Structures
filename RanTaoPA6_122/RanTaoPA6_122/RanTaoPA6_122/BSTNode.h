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
#ifndef BSTNode_H
#define BSTNode_H

#include <iostream>
#include <string> // allows for us to use string operations
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

template <class C, class S>
class Node
{
public:
	Node();
	Node(C newText = NULL, S newMorse = "");
	~Node();
	// we will implement a copy constructor and destructor later...

	//int getData() const; // can't call non const functions
	C getText() const;
	S getMorse() const;


	Node<C, S> *& getLeft();
	Node<C, S> *& getRight();

	// setData ("literal string");
	//void setData(const int newData); // setData (string newData);
	void setText(const C newText);
	void setMorse(const S newMorse);
	void setLeft(Node<C, S> * const newLeft);
	void setRight(Node<C, S> * const newRight);

private:
	//int mData;
	C mText;
	S mMorse;
	Node<C, S> *mpLeft;
	Node<C, S> *mpRight;
};

/*************************************************************
* Function: Node()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: Constructor
* Return: NONE
*************************************************************/
template<class C, class S>
Node<C, S>::Node()
{

}
/*************************************************************
* Function: Node(C newText, S newMorse)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: copy Constructor
* Return: NONE
*************************************************************/
template <class C, class S>
Node<C, S>::Node(C newText, S newMorse)
{
	mText = newText;
	mMorse = newMorse; // will be on heap
	mpLeft = nullptr;
	mpRight = nullptr;
}
/*************************************************************
* Function: ~Node()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: Destructor
* Return: NONE
*************************************************************/
template <class C, class S>
Node<C, S>::~Node()
{
	//cout << "Inside Node's destructor!" << endl;
	//cout << "Deleting node with data: " << mText << endl;
}

//int Node::getData() const // can't call non const functions
//{
//	return mData;
//}
/*************************************************************
* Function: getText()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: get text
* Return: template class C
*************************************************************/
template <class C, class S>
C Node<C, S>::getText() const
{
	return mText;
}
/*************************************************************
* Function: getMorse()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: get morse code
* Return: template class S
*************************************************************/
template <class C, class S>
S Node<C, S>::getMorse() const
{
	return mMorse;
}
/*************************************************************
* Function: getLeft()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: get left pointer
* Return: Node<C, S> *&
*************************************************************/
template <class C, class S>
Node<C, S> *& Node<C, S>::getLeft()
{
	return mpLeft;
}
/*************************************************************
* Function: getRight()
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: get right pointer
* Return: Node<C, S> *&
*************************************************************/
template <class C, class S>
Node<C, S> *& Node<C, S>::getRight()
{
	return mpRight;
}

// setData ("literal string");
//void Node::setData(const int newData) // setData (string newData);
//{
//	mData = newData;
//}
/*************************************************************
* Function: setText(const C newText)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: set text
* Return: NONE
*************************************************************/
template <class C, class S>
void Node<C, S>::setText(const C newText)
{
	mText = newText;
}
/*************************************************************
* Function: setMorse(const S newMorse)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: set morse
* Return: NONE
*************************************************************/
template <class C, class S>
void Node<C, S>::setMorse(const S newMorse)
{
	mMorse = newMorse;
}
/*************************************************************
* Function: setLeft(Node<C, S> * const newLeft)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: set left pointer
* Return: NONE
*************************************************************/
template <class C, class S>
void Node<C, S>::setLeft(Node<C, S> * const newLeft)
{
	mpLeft = newLeft;
}
/*************************************************************
* Function: setRight(Node<C, S> * const newRight)
* Date Created: March 19, 2016
* Date Last Modified: March 23, 2016
* Description: set right pointer
* Return: NONE
*************************************************************/
template <class C, class S>
void Node<C, S>::setRight(Node<C, S> * const newRight)
{
	mpRight = newRight;
}

#endif // !BSTNode_H