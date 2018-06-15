/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 4
* Date: Feb 29, 2016
* Description:You are to write a basic fitness application, in C++, that allows the user of the application to manually edit ¡°diet¡± and ¡°exercise¡± plans. For this application you will need to create three classes: DietPlan, ExercisePlan, and FitnessAppWrapper.

Diet Plan Attributes:
 
The class DietPlan is used to represent a daily diet plan. Your class must include three data members to represent your goal calories (an integer), plan name (a std::string), and date for which the plan is intended (a std::string). The maximum intake of calories for a day is stored in the goal calories.
 
Exercise Plan Attributes:
 
The class ExercisePlan is used to represent a daily exercise plan. Your class must include three data members to represent your goal steps (an integer), plan name (a std::string), and date for which the plan is intended (a std::string). Your goal steps represent the number of desired steps for a day.
 
Diet and Exercise Plan Operations:
 
Both the DietPlan and ExercisePlan should provide several member functions including: a constructor, copy constructor, and destructor. Remember that you will have to think about other appropriate member functions (think about setter and getter functions!). Member function editGoal () should prompt the user for a new goal, and use the value to change the goal in the plan. Each time a plan is changed, the plan must be displayed to the screen, using an overloaded stream insertion operator (see below).
 
In the same file in which each class declaration exists, three nonmember functions must be declared. Note: an overloaded operator is considered an overloaded function. The overloaded stream insertion (<<) for both displaying a plan to the screen and for writing a plan to a file, and the extraction (>>) operator for reading a plan from a file.
*******************************************************************************************/
#pragma once
#include <iostream>
#include <fstream> // files
#include <string>

using std::cin; // if we don't include, then we must use std::cin >> number
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

class DietPlan 
{
public:
	//constructor, copy constructor, destructor
	DietPlan(int newCalories = 0, string newPlanName = "", string newDate = "");
	DietPlan(DietPlan &rhs);
	~DietPlan();
	//getter
	int getCalories() const;
	string getPlanName() const;
	string getDate() const;
	//setter
	void setCalories(int newCalories);
	void setPlanName(string newPlan_name);
	void setDate(string newDate);
	//editGoal
	void editGoal();
	//other 
	//overloading editGoal
	void editGoal(int newGoal);

private:

	int calories;
	string plan_name;
	string date;
};
class ExercisePlan
{
public:
	//constructor, copy constructor, destructor
	ExercisePlan(int newSteps = 0, string newPlanName = "", string newDate = "");
	ExercisePlan(ExercisePlan &rhs);
	~ExercisePlan();
	//getter
	int getSteps() const;
	string getPlanName() const;
	string getDate() const;
	//setter
	void setSteps(int newSteps);
	void setPlanName(string newPlan_name);
	void setDate(string newDate);
	//editGoal
	void editGoal();
	//other 
	//overloading editGoal
	void editGoal(int newGoal);

private:
	int steps;
	string plan_name;
	string date;
};
class FitnessAppWrapper
{
public:
	////constructor, copy constructor, destructor
	FitnessAppWrapper();
	FitnessAppWrapper(FitnessAppWrapper &rhs);
	~FitnessAppWrapper();
	
	// void runApp (void): starts the main application.
	void runApp();
	
	// void loadDailyPlan (fstream &fileStream, DietPlan &plan): must define two of these functions; one for a DietPlan and one for an ExercisePlan. This function reads one record from the given stream. These will be considered overloaded functions! Precondition: file is already open!
	void loadDaily(fstream &fileStream, DietPlan &plan);
	void loadDaily(fstream &fileStream, ExercisePlan &plan);
	
	//void loadWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[ ]): must define two of these functions; one for a DietPlan and one for an ExercisePlan. This function must read in all seven daily plans from the given stream. Note: the array parameter would change if using a vector or linked list! This function should call loadDailyPlan () directly. Precondition: file is already open!
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);

	//displayDailyPlan() : writes a daily plan to the screen.You must apply the overloaded stream insertion operator here!Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
	void displayDailyPlan(DietPlan &plan);
	void displayDailyPlan(ExercisePlan &plan);

	// displayWeeklyPlan (): writes a weekly plan to the screen. This function must call displayDailyPlan (). Note: you must determine the appropriate parameters and return type. Once again you must define two of these!
	void displayWeeklyPlan(DietPlan plan[]);
	void displayWeeklyPlan(ExercisePlan plan[]);

	// storeDailyPlan (): writes a daily plan to a file. You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate parameters and return type. Once again you must define two of these!
	void storeDailyPlan(fstream & fileStream, DietPlan & plan);
	void storeDailyPlan(fstream & fileStream, ExercisePlan & plan);

	// storeWeeklyPlan (): writes a weekly plan to a file. This function must call storeDailyPlan (). You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate parameters and return type. Once again you must define two of these!
	void storeWeeklyPlan(fstream & fileStream, DietPlan plan[]);
	void storeWeeklyPlan(fstream & fileStream, ExercisePlan plan[]);

	//7.    Edit daily diet plan.
	//8.    Edit daily exercise plan.
	void editDaily(fstream & fileStream, DietPlan plan[]);
	void editDaily(fstream & fileStream, ExercisePlan plan[]);
	
	/*    displayMenu (): displays nine menu options. These include:
	1.    Load weekly diet plan from file.
	2.    Load weekly exercise plan from file.
	3.    Store weekly diet plan to file.
	4.    Store weekly exercise plan to file.
	5.    Display weekly diet plan to screen.
	6.    Display weekly exercise plan to screen.
	7.    Edit daily diet plan.
	8.    Edit daily exercise plan.
	9.    Exit.   // Note: this must write the most recent weekly plans to the corresponding files.
	*/	
	void displayMenu();

	//others
	void sortByGoalHtL(fstream & fileStream, DietPlan plan[]);
	void sortByGoalHtL(fstream & fileStream, ExercisePlan plan[]);

	void sortByGoalLtH(fstream & fileStream, DietPlan plan[]);
	void sortByGoalLtH(fstream & fileStream, ExercisePlan plan[]);
	////////////////////////////////////////////////////////////////////////////////////////////////////
	
private:
	DietPlan dArr[7];
	ExercisePlan eArr[7];
	
//	NodeDietPlan *pHead_diet;
//	NodeExercisePlan *pHead_exerise;
};
//the nonmember overloaded stream extraction and stream insertion operators (4 total stream insertion operators, 2 total stream extraction operators)
ostream & operator<< (ostream &output, DietPlan &rhs); // cout << r1; insertion
fstream & operator<< (fstream &output, DietPlan &rhs); // cout << r1; insertion
fstream & operator>> (fstream &input, DietPlan &rhs); // cin >> r1; extraction

ostream & operator<< (ostream &output, ExercisePlan &rhs); // cout << r1; insertion
fstream & operator<< (fstream &output, ExercisePlan &rhs); // cout << r1; insertion
fstream & operator>> (fstream &input, ExercisePlan &rhs); // cin >> r1; extraction

//(4 stream insertion operators, 2 stream extraction operators)


class NodeDietPlan
{

public:
	NodeDietPlan(DietPlan& Plan, NodeDietPlan *pNext);
	NodeDietPlan(const NodeDietPlan *pN);
	virtual ~NodeDietPlan();

	DietPlan Plan;
	NodeDietPlan *pNext;
};

class NodeExercisePlan
{

public:
	NodeExercisePlan(ExercisePlan& Plan, NodeExercisePlan *pNext);
	NodeExercisePlan(const NodeExercisePlan *pN);
	virtual ~NodeExercisePlan();

	ExercisePlan Plan;
	NodeExercisePlan *pNext;
};