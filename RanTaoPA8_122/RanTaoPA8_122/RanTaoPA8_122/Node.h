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

/*Class Design:
For this assignment you are required to implement a dynamically linked binary search tree. You will first need to start by defining an abstract base class Node, which encapsulates the following:
          Data members:
          # mData : std::string // # denotes protected
          # mpLeft : Node *
          # mpRight : Node *
 
          Member functions:
          + virtual destructor // + denotes public
          + constructor which accepts a string to set the data in the node; each pointer in the node is set to NULL
          + setters ¨C one for each data member (3 total should be defined)
          + getters ¨C one for each data member (3 total should be defined, the 2 defined to get the pointers should return a reference to the pointer, i.e. Node *&)
          + pure virtual printData () function, which must be overridden in class TransactionNode*/


class Node
{
public:

	Node(const string &newData = "");
	virtual ~Node();

	//int getData() const; // can't call non const functions
	void setData(const string &newData);
	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);

	string getData() const;
	Node *& getLeft();
	Node *& getRight();

	virtual int getUnits() = 0;
	virtual void printData() = 0;
private:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};