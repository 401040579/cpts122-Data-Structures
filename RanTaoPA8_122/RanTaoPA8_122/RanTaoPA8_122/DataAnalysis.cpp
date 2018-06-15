#include "DataAnalysis.h"
/*************************************************************
* Function: readOneLine(int *units, char type[], char transaction[])
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: A function that reads one line from the file and splits the line into units, type, and transaction fields
* Return: NONE
*************************************************************/
void DataAnalysis::readOneLine(int *units, char type[], char transaction[])
{
	char temp[100];
	mCsvStream.getline(temp, 100, ',');
	*units = atoi(temp);
	mCsvStream.getline(temp, 100, ',');
	strcpy(type, temp);
	mCsvStream.getline(temp, 100, '\n');
	strcpy(transaction, temp);
	//remove the \n
}
/*************************************************************
* Function: readLooplyAndPrint()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs; use inOrderTraversal () to display the trees
* Return: NONE
*************************************************************/
void DataAnalysis::readLooplyAndPrint()
{
	char temp[100];
	int units;
	char type[100], transaction[100];
	mCsvStream.getline(temp, 100);
	while (!mCsvStream.eof()) 
	{
		readOneLine(&units, type, transaction);
		compareAndInsert(&units, type, transaction);
	}
	cout << "Sold Tree: " << endl;
	mTreeSold.inorderTraversal();
	cout << endl;
	cout << "Purchased Tree: " << endl;
	mTreePurchased.inorderTraversal();
}
/*************************************************************
* Function: compareAndInsert(int *units, char type[], char transaction[])
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: A function that compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased) // note with the way the data.csv file is organized the trees will be fairly balanced
* Return: NONE
*************************************************************/
void DataAnalysis::compareAndInsert(int *units, char type[], char transaction[])
{
	if (strcmp(transaction, "Purchased") == 0)
	{
		mTreePurchased.insert(type, *units);
	}
	else
	{
		mTreeSold.insert(type, *units);
	}
}
/*************************************************************
* Function: trend()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description: A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least purchased and sold, and the most purchased and sold
* Return: NONE
*************************************************************/
void DataAnalysis::trend()
{
	//Node *temp = nullptr;
	cout << endl;
	cout << "Most Sold Type:";
	cout << mTreeSold.findLargest().getData() << endl;
	cout << "Most Sold Units:";
	cout << mTreeSold.findLargest().getUnits() << endl;

	cout << "Least Sold Type:";
	cout << mTreeSold.findSmallest().getData() << endl;
	cout << "Least Sold Units:";
	cout << mTreeSold.findSmallest().getUnits() << endl;

	cout << "Most Purchased Type:";
	cout << mTreePurchased.findLargest().getData() << endl;
	cout << "Most Purchased Units:";
	cout << mTreePurchased.findLargest().getUnits() << endl;

	cout << "Least Purchased Type:";
	cout << mTreePurchased.findSmallest().getData() << endl;
	cout << "Least Purchased Units:";
	cout << mTreePurchased.findSmallest().getUnits() << endl;
}
/*************************************************************
* Function: runAnalysis()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description:  runAnalysis (), which is the only public function in the class, aside from possibly a constructor and/or destructor; this function calls the other private functions
* Return: NONE
*************************************************************/
void DataAnalysis::runAnalysis()
{
	openCSV();
	readLooplyAndPrint();
	trend();
}
/*************************************************************
* Function: openCSV()
* Date Created: April 9, 2016
* Date Last Modified: April 13, 2016
* Description:  A function that opens data.csv // yes, it¡¯s private, and must use mCsvStream to open the file
* Return: NONE
*************************************************************/
void DataAnalysis::openCSV()
{
	mCsvStream.open("data.csv", ios::in);
}
