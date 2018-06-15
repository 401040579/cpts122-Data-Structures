#include "ExcercisePlan.h"

ExcercisePlan::ExcercisePlan(const string &newPlanName, const string &newDate, const int &newGoalCalories)
{
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalSteps = newGoalCalories;
	cout << "Inside ExcercisePlan's constructor!" << endl;
}

ExcercisePlan::ExcercisePlan(const ExcercisePlan &copy)
{
	this->mPlanName = copy.mPlanName;  // this is copy a std::string to another one; std::string is an object, 
									   // so the overloaded assignment for one is called here!
	this->mDate = copy.mDate;  // calls std::string overloaded assignment operator!
	this->mGoalSteps = copy.mGoalSteps;  // simple assignment between integers
}

ExcercisePlan::~ExcercisePlan()
{
	// the ExcercisePlan objects will be stored in an array in the 
	// fitnessAppWrapper class
	cout << "Inside of ExcercisePlan's destructor!" << endl;
}

ExcercisePlan & ExcercisePlan::operator= (const ExcercisePlan &rhs)
{
	// check for self assignment
	if (this != &rhs) // the & here is the "address of" operator
	{
		// we are not peforming self-assignment if inside here
		this->mPlanName = rhs.mPlanName;  // this is copy a std::string to another one; std::string is an object, 
										  // so the overloaded assignment (=) for one is called here!
		this->mDate = rhs.mDate;  // calls std::string overloaded assignment (=) operator!
		this->mGoalSteps = rhs.mGoalSteps;  // simple assignment between integers
	}

	return (*this);
}

// getters - allows us to return a copy of the private data members to outside the object
string ExcercisePlan::getPlanName() const // const member function - should not modify data in object - if try to, compiler will provide error!
{
	return this->mPlanName;
}

string ExcercisePlan::getDate() const
{
	return this->mDate;
}

int ExcercisePlan::getGoalSteps() const
{
	return this->mGoalSteps;
}

// setters - allows us to modify the private data members with values from outside the object
void ExcercisePlan::setPlanName(const string &newPlanName)
{
	this->mPlanName = newPlanName; // calls std::string overloaded assignment (=) operator
}

void ExcercisePlan::setDate(const string &newDate)
{
	this->mDate = newDate; // calls std::string overloaded assignment (=) operator
}

void ExcercisePlan::setGoalSteps(const int &newGoalCalories)
{
	this->mGoalSteps = newGoalCalories;
}

void ExcercisePlan::editGoal() // prompt the user for a different goal - display plan with changes to screen
{
	cout << "Please enter a new calories goal: ";
	cin >> this->mGoalSteps;

	cout << (*this) << endl; // can use "*this" here because we've overloaded the stream insertion << (ostream, ExcercisePlan) 
							 // and we want to see the current object's plan details
}



///////////////////////// nonmember functions /////////////////////////////////////

// format: Plan Name
//         Goal steps
//         Date

ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs)  // will allow cout << ExcercisePlan object1 << ExcercisePlan object2...
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions cout << ExcercisePlan object1 << ExcercisePlan object2...
}

// format: Plan Name
//         Goal steps
//         Date

fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs) // will allow fstr << ExcercisePlan object1 << ExcercisePlan object2... 
{
	// cast lhs to ofstream so can easily output std::string (plan name)
	((ofstream &)(lhs)) << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions fstr << ExcercisePlan object1 << ExcercisePlan object2...
}

// format: Plan Name
//         Goal steps
//         Date

// Note: "rhs" can't be const because we are modifying the object
// when we peform a stream extraction operation.
fstream & operator>> (fstream &lhs, ExcercisePlan &rhs) // will allow fstr >> ExcercisePlan object1 >> ExcercisePlan object2...
{
	char tempString[100] = "";
	lhs.getline(tempString, 100); // read the plan name, including the newline in the file
	rhs.setPlanName(tempString); // when the char * is passed into setPlanName a std::string is constructed and
								 // initialized with the char * value 
	int goalCalories = 0;
	lhs.getline(tempString, 100);  // read the goal calories line as a string, then convert to an integer, this way we can read in the newline
	goalCalories = atoi(tempString); // convert the char * string representation to its corresponding integer, i.e. "42" to 42 int
	rhs.setGoalSteps(goalCalories);
	lhs.getline(tempString, 100);  // read the date from the file, also reads newline
	rhs.setDate(tempString);

	return lhs; // allows for chaining of stream extractions fstr >> ExcercisePlan object1 >> ExcercisePlan object2...
}