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
#include "BST.h"
/* 
Lastly, define a class DataAnalysis, which encapsulates the following:
Data members:
          - mTreeSold : BST
          - mTreePurchased : BST
          - mCsvStream : ifstream
 
Member functions:
- A function that opens data.csv // yes, it¡¯s private, and must use mCsvStream to open the file
          - A function that reads one line from the file and splits the line into units, type, and transaction fields
          - A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs; use inOrderTraversal () to display the trees
          - A function that compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased) // note with the way the data.csv file is organized the trees will be fairly balanced
          - A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least purchased and sold, and the most purchased and sold
          + runAnalysis (), which is the only public function in the class, aside from possibly a constructor and/or destructor; this function calls the other private functions
 
What should go in main ()?
          DataAnalysis obj;
          obj.runAnalysis ();*/
class DataAnalysis
{
public:

	void runAnalysis();


private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	//A function that opens data.csv // yes, it¡¯s private, and must use mCsvStream to open the file
	void openCSV();
	void readOneLine(int *units, char type[], char transaction[]);
	void readLooplyAndPrint();
	void compareAndInsert(int *units, char type[], char transaction[]);
	void trend();
};