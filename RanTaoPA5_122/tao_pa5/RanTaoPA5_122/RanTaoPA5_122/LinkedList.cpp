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
#include "LinkedList.h"

/*************************************************************
* Function: Node
* Date Created:3/15/2016
* Description: Constructor
* Input parameters: const int string
* Returns: NONE
*************************************************************/
Node::Node(const int &newRecord, const int &newId,
	const string &newName, const string &newEMail, const string &newUnit, const string &newMajor, const string &newLevel,
	const int &newNumAbs, const string &newAbsDate)
{
	mRecord = newRecord;
	mId = newId;
	mName = newName;
	mEMail = newEMail;
	mUnit = newUnit;
	mMajor = newMajor;
	mLevel = newLevel;
	mNumAbs = newNumAbs;
	mAbsDate = newAbsDate;
	mpNext = nullptr;
}

/*************************************************************
* Function: Node
* Date Created:3/15/2016
* Description: Destructor
* Input parameters: NONE
* Returns: NONE
*************************************************************/ 
Node::~Node()
{
	//cout << "Inside Node's destructor!" << endl;
}

/*************************************************************
* Function: setdata
* Date Created:3/15/2016
* Description: setter for all data
* Input parameters: int string
* Returns: NONE
*************************************************************/
void Node::setData(int &newRecord, int &newId,
	string &newName, string &newEMail, string &newUnit, string &newMajor, string &newLevel,
	int &newNumAbs, string &newAbsDate)
{
	mRecord = newRecord;
	mId = newId;
	mName = newName;
	mEMail = newEMail;
	mUnit = newUnit;
	mMajor = newMajor;
	mLevel = newLevel;
	mNumAbs = newNumAbs;
	mAbsDate = newAbsDate;
}
/*************************************************************
* Function: setNext
* Date Created:3/15/2016
* Description: setter for pNext
* Input parameters: Node*
* Returns: NONE
*************************************************************/
void Node::setNext(Node * const newNext)
{
	mpNext = newNext;
}
/*************************************************************
* Function: setNumAbs
* Date Created:3/15/2016
* Description: setter for MNumAbs
* Input parameters: int
* Returns: NONE
*************************************************************/
void Node::setNumAbs(int &newNumAbs)
{
	mNumAbs = newNumAbs;
}
/*************************************************************
* Function: setAbsDate
* Date Created:3/15/2016
* Description: setter for AbsDate
* Input parameters: string
* Returns: NONE
*************************************************************/
void Node::setAbsDate(string & newAbsDate)
{
	mAbsDate = newAbsDate;
}
/*************************************************************
* Function: getRecord
* Date Created:3/15/2016
* Description: getter for Record
* Input parameters: NONE
* Returns: mecord
*************************************************************/
int Node::getRecord() const
{
	return mRecord;
}

/*************************************************************
* Function: getId
* Date Created:3/15/2016
* Description: getter for student id
* Input parameters: NONE
* Returns: mId
*************************************************************/
int Node::getId() const
{
	return mId;
}

/*************************************************************
* Function: getName
* Date Created:3/15/2016
* Description: getter for Name
* Input parameters: NONE
* Returns: Mname
*************************************************************/
string Node::getName() const
{
	return mName;
}

/*************************************************************
* Function: getEMail
* Date Created:3/15/2016
* Description: getter for email
* Input parameters: NONE
* Returns: mEMail
*************************************************************/
string Node::getEMail() const
{
	return mEMail;
}

/*************************************************************
* Function: getUnit
* Date Created:3/15/2016
* Description: getter for unit
* Input parameters: NONE
* Returns: mUnit
*************************************************************/
string Node::getUnit() const
{
	return mUnit;
}

/*************************************************************
* Function: getMajor
* Date Created:3/15/2016
* Description: getter for major
* Input parameters: NONE
* Returns: mMajor
*************************************************************/
string Node::getMajor() const
{
	return mMajor;
}

/*************************************************************
* Function: getLevel
* Date Created:3/15/2016
* Description: getter for level
* Input parameters: NONE
* Returns: mLevel
*************************************************************/
string Node::getLevel() const
{
	return mLevel;
}

/*************************************************************
* Function: getNumAbs
* Date Created:3/15/2016
* Description: getter for NUmber of absent
* Input parameters: NONE
* Returns: mNumAbs
*************************************************************/
int Node::getNumAbs() const
{
	return mNumAbs;
}

/*************************************************************
* Function: getAbsDate
* Date Created:3/15/2016
* Description: getter for date of absent
* Input parameters: NONE
* Returns: mAbsDate
*************************************************************/
string Node::getAbsDate() const
{
	return mAbsDate;
}

/*************************************************************
* Function: getNext
* Date Created:3/15/2016
* Description: getter for pNext
* Input parameters: NONE
* Returns: mpNext
*************************************************************/
Node * Node::getNext() const
{
	return mpNext;
}

///////////////// List ////////////////////////////

/*************************************************************
* Function: List
* Date Created:3/15/2016
* Description: Costructor
* Input parameters: NONE
* Returns: NONE
*************************************************************/
List::List()
{
	mpHead = nullptr;
}

/*************************************************************
* Function: makeNode
* Date Created:3/15/2016
* Description: make a Node for list
* Input parameters: const int string
* Returns: pMem
*************************************************************/
Node * List::makeNode(const int &newRecord, const int &newId,
const string &newName,const string &newEMail, const string &newUnit, const string &newMajor, const string &newLevel,
const int &newNumAbs, const string &newAbsDate)
{
	Node *pMem = new Node(newRecord, newId,newName,newEMail,newUnit,newMajor,newLevel,newNumAbs,newAbsDate);
	
	return pMem;

}

/*************************************************************
* Function: ~List
* Date Created:3/15/2016
* Description: destructor
* Input parameters: NONE
* Returns: NONE
*************************************************************/
List::~List()
{
	//cout << "Inside List's destructor!" << endl;
	Node *pCur = mpHead;
	
	while (pCur != nullptr)
	{
		mpHead = pCur->getNext();
		//cout << "name: " << pCur->getName() << endl;
		delete pCur;
		pCur = mpHead;
	}
}

/*************************************************************
* Function: insertAtFront
* Date Created:3/15/2016
* Description: insert node at front
* Input parameters: int  string
* Returns: success
*************************************************************/
bool List::insertAtFront(const int &newRecord, const int &newId,
	const string &newName, const string &newEMail, const string &newUnit, const string &newMajor, const string &newLevel,
	const int &newNumAbs, const string &newAbsDate)
{
	bool success = false;
	Node *pMem = makeNode(newRecord, newId, newName, newEMail, newUnit, newMajor, newLevel, newNumAbs, newAbsDate);

	if (pMem != nullptr)
	{
		success = true; // allocated memory on heap
		pMem->setNext(mpHead);
		mpHead = pMem;
	}

	return success;
}

/*************************************************************
* Function: deleteList
* Date Created:3/15/2016
* Description: deleter a list
* Input parameters: NONE
* Returns: NONE
*************************************************************/
void List::deleteList()
{
	Node *pCur = mpHead;

	while (pCur != nullptr)
	{
		mpHead = pCur->getNext();
		delete pCur;
		pCur = mpHead;
	}
}

/*************************************************************
* Function: mark_absences
* Date Created:3/15/2016
* Description: mark a absences for a student
* Input parameters: NONE
* Returns: NONE
*************************************************************/
void List::mark_absences()
{
	Node *pCur = mpHead;
	int input,i;
	string date, year_str, month_str, day_str;
	char year[10], month[10], day[10];
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	while (pCur != nullptr)
	{
		cout << "name: " << pCur->getName() << endl;
		cout << "is the student absent? (1 for yes, 0 for no)" << endl;
		cout << "Enter: ";
		cin >> input; getchar();
		if (input == 1)
		{
			i = pCur->getNumAbs() + 1;
			pCur->setNumAbs(i);
		//	pCur->setData(pCur->getRecord(), pCur->getId(), pCur->getName(), pCur->getEMail(), pCur->getUnit(), pCur->getMajor(), pCur->getLevel(), i, pCur->getAbsDate());

			itoa((now->tm_year + 1900), year, 10);
			itoa(now->tm_mon + 1, month, 10);
			itoa(now->tm_mday, day, 10);

			year_str = year;
			month_str = month;
			day_str = day;

			date = pCur->getAbsDate() + year_str + "-" + month_str + "-" + day_str + " ";

			pCur->setAbsDate(date);
		}
		pCur = pCur->getNext();
	}
}

/*************************************************************
* Function: edit_absences
* Date Created:3/15/2016
* Description: edit absences
* Input parameters: NONE
* Returns: NONE
*************************************************************/
void List::edit_absences()
{
	Node *pCur = mpHead;
	int sid, i;
	string date;
	while (pCur != nullptr)
	{
		cout << "Record: " << pCur->getRecord() << endl;
		cout << "ID: " << pCur->getId() << endl;
		cout << "Name: " << pCur->getName() << endl;
		cout << "Email: " << pCur->getEMail() << endl;
		cout << "Units: " << pCur->getUnit() << endl;
		cout << "Program: " << pCur->getMajor() << endl;
		cout << "Level: " << pCur->getLevel() << endl;
		cout << "Number_of_absences: " << pCur->getNumAbs() << endl;
		cout << "Dates: " << pCur->getAbsDate() << endl << endl;
		pCur = pCur->getNext();
	}

	cout << "which student's absence do you want to remove?(enter SID)" << endl;
	cout << "Enter: ";
	cin >> sid; getchar();
	pCur = mpHead;

	while (pCur != nullptr && pCur->getId() != sid)
	{
		pCur = pCur->getNext();
	}
	if (pCur != nullptr)
	{
		i = pCur->getNumAbs() - 1;
		pCur->setNumAbs(i);

		date = pCur->getAbsDate();
		for (int j = 0; j < 10; j++) 
		{
			date.pop_back();
		}
		pCur->setAbsDate(date);
	}
	else
	{
		cout << "can't find him/her" << endl;
	}

}

/*************************************************************
* Function: generateReports
* Date Created:3/15/2016
* Description: generate three reports for request
* Input parameters: ofstream
* Returns: NONE
*************************************************************/
void List::generateReports(ofstream &fver1, ofstream &fver2, ofstream &fver3)
{
	Node *pCur = mpHead;
	string date;
	string year, month, day,
		year_st, month_st, day_st;
	int input;
	cout << "which version do you want?" << endl;
	cout << "1. shows all of the students in the class and the number of times they have been absent" << endl;
	cout << "2. provides only the students that have been absent greater than some threshold set" << endl;
	cout << "3. provides the students that were absent on a certain date. " << endl;
	cout << "Enter: ";
	cin >> input; getchar();

	switch (input)
	{
	case 1:

		fver1.open("Version 1.txt", ios::out);
		pCur = mpHead;

		while (pCur != nullptr)
		{
			fver1 << "Record: " << pCur->getRecord() << endl;
			fver1 << "ID: " << pCur->getId() << endl;
			fver1 << "Name: " << pCur->getName() << endl;
			fver1 << "Email: " << pCur->getEMail() << endl;
			fver1 << "Units: " << pCur->getUnit() << endl;
			fver1 << "Program: " << pCur->getMajor() << endl;
			fver1 << "Level: " << pCur->getLevel() << endl;
			fver1 << "Number_of_absences: " << pCur->getNumAbs() << endl;
			fver1 << "Dates: " << pCur->getAbsDate() << endl << endl;
			pCur = pCur->getNext();
		}

		break;
	case 2:

		fver2.open("Version 2.txt", ios::out);
		pCur = mpHead;
		cout << "set a threshold:";
		cin >> input; getchar();

		while(pCur != nullptr)
		{
			if (input < pCur->getNumAbs())
			{
				fver2 << "Record: " << pCur->getRecord() << endl;
				fver2 << "ID: " << pCur->getId() << endl;
				fver2 << "Name: " << pCur->getName() << endl;
				fver2 << "Email: " << pCur->getEMail() << endl;
				fver2 << "Units: " << pCur->getUnit() << endl;
				fver2 << "Program: " << pCur->getMajor() << endl;
				fver2 << "Level: " << pCur->getLevel() << endl;
				fver2 << "Number_of_absences: " << pCur->getNumAbs() << endl;
				fver2 << "Dates: " << pCur->getAbsDate() << endl << endl;
			}
			pCur = pCur->getNext();
		}

		break;
	case 3:

		fver3.open("Version 3.txt", ios::out);
		pCur = mpHead;
		int count;
		char arr[9];// year[4], month[2], day[2], date_arr[100];
		cout << "enter a date you want to see (yyyymdd): ";
		cin >> arr;
		year += arr[0]; year += arr[1]; year += arr[2]; year += arr[3];
		month = arr[4];
		day += arr[5]; day += arr[6];
		while (pCur != nullptr)
		{
			date = pCur->getAbsDate();
			
			count = date.length() / 10;

			for (int i = 0; i < count; i++)
			{
				year_st = ""; month_st = ""; day_st = "";
				year_st += date[0 + i * 10]; year_st += date[1 + i * 10]; year_st += date[2 + i * 10]; year_st += date[3 + i * 10];
				month_st = date[5 + i * 10];
				day_st += date[7 + i * 10]; day_st += date[8 + i * 10];
				if (year_st == year && month_st == month &&  day_st == day)
				{
					fver3 << "Name: " << pCur->getName() << endl;
					fver3 << "Email: " << pCur->getEMail() << endl;
					fver3 << "Number_of_absences: " << pCur->getNumAbs() << endl;
					fver3 << "Dates: " << pCur->getAbsDate() << endl << endl;
				}
			}
			pCur = pCur->getNext();
		}
		break;
	default:
		break;
	}
}

/*************************************************************
* Function: getFront
* Date Created:3/15/2016
* Description: get Header's address
* Input parameters: NONE
* Returns: address of mpHead
*************************************************************/
Node * List::getFront() const
{
	return mpHead;
}

// nonmember

/*************************************************************
* Function: operatir<<
* Date Created:3/15/2016
* Description: overload the operator<<
* Input parameters: ofstream, List
* Returns: ofstream
*************************************************************/
ofstream & operator<< (ofstream &output, List &rhs)
{
	Node *pCur = rhs.getFront();

	while (pCur != nullptr)
	{
		output << "Record: " << pCur->getRecord() << endl;
		output << "ID: " << pCur->getId() << endl;
		output << "Name: " << pCur->getName() << endl;
		output << "Email: " << pCur->getEMail() << endl;
		output << "Units: " << pCur->getUnit() << endl;
		output << "Program: " << pCur->getMajor() << endl;
		output << "Level: " << pCur->getLevel() << endl;
		output << "Number_of_absences: " << pCur->getNumAbs() << endl;
		output << "Dates: " << pCur->getAbsDate() << endl << endl;
		pCur = pCur->getNext();
	}

	return output;
}

/*************************************************************
* Function: operator>>
* Date Created:3/15/2016
* Description: overload the operatr>>
* Input parameters: ifstream, List
* Returns: ifstream
*************************************************************/
ifstream & operator>>(ifstream & input, List & rhs)
{
	char firstSentence[100];
	//int record, id;
	int record, id;
	char buffer[100], name[300], lastName[100], firstName[100], email[100], unit[100], major[100], level[100];
	string a,b,c;
	input.getline(firstSentence, 100);
	for (int i = 0; i < 10; i++)
	//while (!input.eof())
	{
		input.getline(buffer, 100, ',');
		record = atoi(buffer);
		input.getline(buffer, 100, ',');
		id = atoi(buffer);
		input.getline(lastName, 100, ',');
		input.getline(firstName, 100, ',');
		a = lastName;
		b = firstName;
		c = a +", "+ b;
		input.getline(email, 100, ',');
		input.getline(unit, 100, ',');
		input.getline(major, 100, ',');
		input.getline(level, 100);
		rhs.insertAtFront(record, id, c, email, unit, major, level, 0, "");
	
	}
	return input;
}

/*************************************************************
* Function: operator>>
* Date Created:3/15/2016
* Description: overload the operator>>>
* Input parameters: fstream, List
* Returns: fstream input
*************************************************************/
fstream & operator>> (fstream & input, List & rhs)
{
	int record, id, numAbs;
	char buffer[100], name[300], email[100], unit[100], major[100], level[100],
		AbsDate[100];
	for (int i = 0; i < 10; i++)
//	while (!input.eof())
	{
		input.getline(buffer, 100, ': ');
		input.getline(buffer, 100);
		record = atoi(buffer);
		input.getline(buffer, 100, ': ');
		input.getline(buffer, 100);
		id = atoi(buffer);
		input.getline(buffer, 100, ': ');
		input.getline(name, 100);
		input.getline(buffer, 100, ': ');
		input.getline(email, 100);
		input.getline(buffer, 100, ': ');
		input.getline(unit, 100);
		input.getline(buffer, 100, ': ');
		input.getline(major, 100);
		input.getline(buffer, 100, ': ');
		input.getline(level, 100);
		input.getline(buffer, 100, ': ');
		input.getline(buffer, 100);
		numAbs = atoi(buffer);
		input.getline(buffer, 100, ': ');
		input.getline(AbsDate, 100);
		input.getline(buffer, 100);
		rhs.insertAtFront(record, id, name, email, unit, major, level, numAbs, AbsDate);
	}

	return input;
}

/*************************************************************
* Function: displayMenu
* Date Created:3/15/2016
* Description: display menu
* Input parameters: NONE
* Returns: NONE
*************************************************************/
void Menu::displayMenu()
{
	cout << "1.    Import course list" << endl <<
		"2.    Load master list" << endl <<
		"3.    Store master list" << endl <<
		"4.    Mark absences" << endl <<
		"5.    BONUS: Edit absences" << endl <<
		"6.    Generate report" << endl <<
		"7.    Exit" << endl;
}

/*************************************************************
* Function: run
* Date Created:3/15/2016
* Description: run main
* Input parameters: NONE
* Returns: NONE
*************************************************************/
void Menu::run()
{
	ofstream fout;
	ifstream fin_csv;
	fstream fin_txt;

	ofstream fver1, fver2, fver3;

	List list;
	int option = -1;
	

	while (option != 7)
	{
		displayMenu();
		cout << "Enter: ";
		cin >> option;
		getchar();

		switch (option)
		{
		case 1:
			fin_csv.open("classList.csv", ios::in);
			list.deleteList();
			fin_csv >> list;
			cout << "successful" << endl;
			fin_csv.close();
			system("pause");
			system("cls");
			break;
		case 2:
			fin_txt.open("master.txt", ios::in);
			list.deleteList();
			fin_txt >> list;
			cout << "successful" << endl;
			fin_txt.close();
			system("pause");
			system("cls");
			break;
		case 3:
			fout.open("master.txt", ios::out);
			fout << list;
			cout << "successful" << endl;
			fout.close();
			system("pause");
			system("cls");
			break;
		case 4:
			list.mark_absences();
			system("pause");
			system("cls");
			break;
		case 5:
			list.edit_absences();
			cout << "successful" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			list.generateReports(fver1,fver2,fver3);
			fver1.close();
			fver2.close();
			fver3.close();
			cout << "successful" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "unsaved file will be lost" << endl;
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}

}



