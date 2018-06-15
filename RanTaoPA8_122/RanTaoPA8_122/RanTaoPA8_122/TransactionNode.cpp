#include "TransactionNode.h"
/*************************************************************
* Function: ~TransactionNode()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: Destructor
* Return: NONE
*************************************************************/
TransactionNode::~TransactionNode()
{
}
/*************************************************************
* Function: TransactionNode(const string & newData, const int & newUnits) : Node (newData)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: copy Constructor
* Return: NONE
*************************************************************/
TransactionNode::TransactionNode(const string & newData, const int & newUnits) : Node (newData)
{
	mUnits = newUnits;
}
/*************************************************************
* Function: setUnits(const int & newUnits)
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: set units
* Return: NONE
*************************************************************/
void TransactionNode::setUnits(const int & newUnits)
{
	mUnits = newUnits;
}
/*************************************************************
* Function: getUnits()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: get units
* Return: int
*************************************************************/
int TransactionNode::getUnits()
{
	return mUnits;
}
/*************************************************************
* Function: printData()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: print data
* Return: NONE
*************************************************************/
void TransactionNode::printData()
{
	cout << "Data: " << getData() << endl <<
		 "Unit: " << mUnits << endl;
}
