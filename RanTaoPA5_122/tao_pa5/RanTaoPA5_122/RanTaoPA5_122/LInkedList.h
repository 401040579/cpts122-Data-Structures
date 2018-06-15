/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 5
* Date: March 15, 2016
* Description:Let us create an application that manages attendance for a course. This application has four major requirements:
Requirement 1 (Import records): The application must import records pertaining to each student registered for the course from a course list.
Requirement 2 (Mark absences): The application must allow the user to mark each student in the course as present or absent on any given day.
Requirement 3 (Generate reports): The application must generate reports based on criteria.
Requirement 4 (Menu): The application must support a user interface to the attendance tracker.
*******************************************************************************************/
#pragma once

#include <iostream> // cout, cin
#include <string> // allows for us to use string operations
#include <fstream>
#include <ctime>

using std::string;
using std::cin;
using std::cout; // std::cout << int --> cout << int
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

/*You are required to use a dynamic singly linked list to store student records. 
As each record is imported from the file, the record must be inserted at the front
of the list. Inserting at the front of a dynamic linked list is very efficient (c
-onstant time). You are required to implement two classes for the list. One class 
is the node class, which stores the fields acquired from each record. In addition 
to the fields in the file, you are required to add two extra fields in your node. 
These fields include number of absences and an array for storing the dates of abse
-nces. The second class is the List class, which is a container for the nodes. The 
List class will be considered your master list.*/
class Node
{
public:
	Node(const int &newRecord = 0, const int &newId = 0,
		const string &newName = "", const string &newEMail = "", const string &newUnit = "", const string &newMajor = "", const string &newLevel = "", 
		const int &newNumAbs = 0, const string &newAbsDate = "");

	~Node();

	void setData(int &newRecord, int &newId,
		string &newName, string &newEMail, string &newUnit, string &newMajor, string &newLevel, 
		int &newNumAbs, string &newAbsDate);
	void setNext(Node * const newNext);

	void setNumAbs(int &newNumAbs);
	void setAbsDate(string &newAbsDate);

	int getRecord() const;
	int getId() const;
	string getName() const;
	string getEMail() const;
	string getUnit() const;
	string getMajor() const;
	string getLevel() const;
	int getNumAbs() const;
	string getAbsDate() const;

	Node *getNext() const;

private:
	int mRecord, mId, mNumAbs;
	string mName, mEMail, mUnit, mMajor, mLevel, mAbsDate;
	Node *mpNext;
};

class List // linked list
{
public:
	List();
	~List();

	bool insertAtFront(const int &newRecord, const int &newId,
		const string &newName, const string &newEMail, const string &newUnit, const string &newMajor, const string &newLevel,
		const int &newNumAbs, const string &newAbsDate);

	void deleteList();

	void mark_absences();

	void edit_absences();

	void generateReports(ofstream &fver1, ofstream &fver2, ofstream &fver3);

	Node * getFront() const;

private:
	Node *mpHead;

	Node * makeNode(const int &newRecord, const int &newId,
		const string &newName, const string &newEMail, const string &newUnit, const string &newMajor, const string &newLevel,
		const int &newNumAbs, const string &newAbsDate);
};
/*You are required to define a class for your menu.*/
class Menu 
{
public:
	void displayMenu();
	void run();

private:
};
//overload operator
ofstream & operator<< (ofstream &output, List &rhs);
ifstream & operator>> (ifstream &input, List &rhs);
fstream & operator>> (fstream &input, List &rhs);
