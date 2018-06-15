#include "Node.h"
/*************************************************************
* Function: Node(const string &newData)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: copy Constructor
* Return: NONE
*************************************************************/
Node::Node(const string &newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}
/*************************************************************
* Function: ~Node()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: Destructor
* Return: NONE
*************************************************************/
Node::~Node()
{
	///
}
/*************************************************************
* Function: getData()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: get data
* Return: string
*************************************************************/
string Node::getData() const
{
	return mData;
}
/*************************************************************
* Function: getLeft()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: get left point
* Return: Node *&
*************************************************************/
Node *& Node::getLeft()
{
	return mpLeft;
}
/*************************************************************
* Function: getRight()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: get right point
* Return: Node *&
*************************************************************/
Node *& Node::getRight()
{
	return mpRight;
}
/*************************************************************
* Function: setData(const string &newData)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: set data
* Return: NONE
*************************************************************/
void Node::setData(const string &newData)
{
	mData = newData;
}
/*************************************************************
* Function: setLeft(Node * const newLeft)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: set left
* Return: NONE
*************************************************************/
void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}
/*************************************************************
* Function: setRight(Node * const newRight)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: set right point
* Return: NONE
*************************************************************/
void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}
