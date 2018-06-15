#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExcercisePlan
{
public:
	// constructor with default arguments - when a ExcercisePlan is constructed or 
	// instantiated we can supply values for each of the member variables or 
	// leave them as the default ones
	ExcercisePlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalCalories = 0);

	// copy constructor - invoked during the construction of an object, when the object is 
	// set to another object of same type; invoked when passing-by-value (making a copy)
	ExcercisePlan(const ExcercisePlan &copy);

	// destructor - invoked when an object leaves scope or is destroyed - if the object was 
	// created on the heap (dynamic), then a call to delete the object (using delete operator)
	// will implicitly invoke the constructor
	~ExcercisePlan();

	// overloaded assignment - always a member function
	ExcercisePlan & operator= (const ExcercisePlan &rhs);

	// getters - allows us to return a copy of the private data members to outside the object
	string getPlanName() const; // const member function - should not modify data in object - 
								// if try to, compiler will provide error!
	string getDate() const;
	int getGoalSteps() const;

	// setters - allows us to modify the private data members with values from 
	// outside the object
	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalSteps(const int &newGoalSteps);

	void editGoal(); // prompt the user for a different goal - display plan with 
					 // changes to screen


private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

// nonmember functions
ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs);
fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs);
fstream & operator>> (fstream &lhs, ExcercisePlan &rhs); 