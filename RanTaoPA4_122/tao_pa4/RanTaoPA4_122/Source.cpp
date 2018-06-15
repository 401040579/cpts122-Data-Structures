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

#include "Header.h"

/*************************************************************
* Function: DietPlan
* Date Created:2/25/2016
* Description: Constructor
* Input parameters: string int string
* Returns: NONE
*************************************************************/
DietPlan::DietPlan(int newCalories, string newPlanName, string newDate)
{
	calories = newCalories;
	plan_name = newPlanName;
	date = newDate;
}

/*************************************************************
* Function: DietPlan
* Date Created:2/25/2016
* Description: CP function
* Input parameters: string int string
* Returns: NONE
*************************************************************/

DietPlan::DietPlan(DietPlan &rhs)
{
	calories = rhs.calories;
	plan_name = rhs.plan_name;
	date = rhs.date;
}
/*************************************************************
* Function: ~DietPlan
* Date Created:2/25/2016
* Description: Destructor
* Input parameters:NONE
* Returns: NONE
*************************************************************/

DietPlan::~DietPlan()
{
}
/*************************************************************
* Function: getCalories
* Date Created:2/25/2016
* Description: gain calories
* Input parameters:
* Returns: return the value of calories
*************************************************************/

int DietPlan::getCalories() const
{
	return calories;
}

/*************************************************************
* Function: GetPlanName
* Date Created:2/25/2016
* Description: gain planName
* Input parameters:
* Returns: return string
*************************************************************/

string DietPlan::getPlanName() const
{
	return plan_name;
}
/*************************************************************
* Function: GetDate
* Date Created:2/25/2016
* Description: gain date
* Input parameters:
* Returns: return string
*************************************************************/

string DietPlan::getDate() const
{
	return date;
}
/*************************************************************
* Function: setCalories
* Date Created:2/25/2016
* Description: gain calories
* Input parameters:int
* Returns: void
*************************************************************/

void DietPlan::setCalories(int newCalories)
{
	calories = newCalories;
}
/*************************************************************
* Function: setPlanName
* Date Created:2/25/2016
* Description: gain planName
* Input parameters:string
* Returns: void
*************************************************************/

void DietPlan::setPlanName(string newPlan_name)
{
	plan_name = newPlan_name;
}
/*************************************************************
* Function: setDate
* Date Created:2/25/2016
* Description: set Date
* Input parameters:string
* Returns: void
*************************************************************/

void DietPlan::setDate(string newDate)
{
	date = newDate;
}

/*************************************************************
* Function: editGoal
* Date Created:2/25/2016
* Description: edit Goal
* Input parameters: none
* Returns: void
*************************************************************/

void DietPlan::editGoal()
{
	int newCalories;
	cout << "enter the new goal(number): ";
	cin >> newCalories;
	setCalories(newCalories);
}
/*************************************************************
* Function: editGoal
* Date Created:2/25/2016
* Description: edit Goal as set
* Input parameters: int 
* Returns: NONE
*************************************************************/

void DietPlan::editGoal(int newGoal)
{
	setCalories(newGoal);
}
/*************************************************************
* Function: ExercisePlan
* Date Created:2/25/2016
* Description: constructor
* Input parameters: int string string
* Returns: NONE
*************************************************************/

//////////////////////////////////////////////////////////////////////////
ExercisePlan::ExercisePlan(int newCalories, string newPlanName, string newDate)
{
	steps = newCalories;
	plan_name = newPlanName;
	date = newDate;
}
/*************************************************************
* Function: ExercisePlan
* Date Created:2/25/2016
* Description: CP constructor
* Input parameters: ExercisePlan
* Returns: NONE
*************************************************************/

ExercisePlan::ExercisePlan(ExercisePlan &rhs)
{
	steps = rhs.steps;
	plan_name = rhs.plan_name;
	date = rhs.date;
}

/*************************************************************
* Function: ~ExercisePlan
* Date Created:2/25/2016
* Description: destructor
* Input parameters: NONE
* Returns: NONE
*************************************************************/

ExercisePlan::~ExercisePlan()
{

}
/*************************************************************
* Function: getSteps
* Date Created:2/25/2016
* Description: get goal
* Input parameters: NONE
* Returns: NONE
*************************************************************/

int ExercisePlan::getSteps() const
{
	return steps;
}
/*************************************************************
* Function: getPlanName
* Date Created:2/25/2016
* Description: get Plan Name
* Input parameters: NONE
* Returns: NONE
*************************************************************/

string ExercisePlan::getPlanName() const
{
	return plan_name;
}
/*************************************************************
* Function: getDate
* Date Created:2/25/2016
* Description: get date
* Input parameters: NONE
* Returns: NONE
*************************************************************/

string ExercisePlan::getDate() const
{
	return date;
}

/*************************************************************
* Function: setSteps
* Date Created:2/25/2016
* Description: set step
* Input parameters: int
* Returns: NONE
*************************************************************/

void ExercisePlan::setSteps(int newSteps)
{
	steps = newSteps;
}

/*************************************************************
* Function: setPlanName
* Date Created:2/25/2016
* Description: set plan name
* Input parameters: string
* Returns: NONE
*************************************************************/

void ExercisePlan::setPlanName(string newPlan_name)
{
	plan_name = newPlan_name;
}
/*************************************************************
* Function: setDate
* Date Created:2/25/2016
* Description: set date
* Input parameters: string
* Returns: NONE
*************************************************************/

void ExercisePlan::setDate(string newDate)
{
	date = newDate;
}
/*************************************************************
* Function: editGoal
* Date Created:2/25/2016
* Description: edit Goal
* Input parameters: None
* Returns: NONE
*************************************************************/

void ExercisePlan::editGoal()
{
	int newSteps;
	cout << "enter the new goal(number): ";
	cin >> newSteps;
	setSteps(newSteps);
}
/*************************************************************
* Function: editGoal
* Date Created:2/25/2016
* Description: edit Goal as set
* Input parameters: int
* Returns: NONE
*************************************************************/

void ExercisePlan::editGoal(int newGoal)
{
	setSteps(newGoal);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//read and write///
/*************************************************************
* Function: operator<<
* Date Created:2/25/2016
* Description: overload operator <<
* Input parameters: ostream DietPlan
* Returns: ostream
*************************************************************/

ostream & operator<< (ostream &output, DietPlan &rhs)
{
	output << rhs.getPlanName() << endl << rhs.getCalories() << endl << rhs.getDate() << endl;
	return output;
}
/*************************************************************
* Function: operator<<
* Date Created:2/25/2016
* Description: overload operator <<
* Input parameters: ostream DietPlan
* Returns: fstream
*************************************************************/

fstream & operator<< (fstream &output, DietPlan &rhs)
{
	output << rhs.getPlanName() << endl;
	output << rhs.getCalories() << endl;
	output << rhs.getDate() << endl << endl;
	return output;
}
/*************************************************************
* Function: operator>>
* Date Created:2/25/2016
* Description: overload operator >>
* Input parameters: ostream DietPlan
* Returns: fstream
*************************************************************/

fstream & operator>> (fstream &input, DietPlan &rhs)
{
	char name[100],space[1];
	char date[100];
	int goal;

	input.getline(name, 100);
	rhs.setPlanName(name);
	input >> goal;
	rhs.setCalories(goal);
	input.getline(space, 1);
	input.getline(date, 100);
	rhs.setDate(date);
	input.getline(space, 1);
	return input;
}
/*************************************************************
* Function: operator<<
* Date Created:2/25/2016
* Description: overload operator <<
* Input parameters: ostream ExercisePlan
* Returns: ostream
*************************************************************/

ostream & operator<< (ostream &output, ExercisePlan &rhs)
{
	output << rhs.getPlanName() << endl << rhs.getSteps() << endl << rhs.getDate() << endl;
	return output;
}
/*************************************************************
* Function: operator<<
* Date Created:2/25/2016
* Description: overload operator <<
* Input parameters: fstream ExercisePlan
* Returns: fstream
*************************************************************/

fstream & operator<< (fstream &output, ExercisePlan &rhs)
{
	output << rhs.getPlanName() << endl;
	output << rhs.getSteps() << endl;
	output << rhs.getDate() << endl << endl;
	return output;
}
/*************************************************************
* Function: operator>>
* Date Created:2/25/2016
* Description: overload operator <<
* Input parameters: fstream ExercisePlan
* Returns: fstream
*************************************************************/

fstream & operator>> (fstream &input, ExercisePlan &rhs)
{
	char name[100], space[1];
	char date[100];
	int goal;

	input.getline(name, 100);
	rhs.setPlanName(name);
	input >> goal;
	rhs.setSteps(goal);
	input.getline(space, 1);
	input.getline(date, 100);
	rhs.setDate(date);
	input.getline(space, 1);
	return input;
}
/*************************************************************
* Function: displayMenu
* Date Created:2/25/2016
* Description: display menu
* Input parameters: none
* Returns: void
*************************************************************/

void FitnessAppWrapper::displayMenu()
{
	cout << "Welcome to Fitness Application:" << endl << endl<<
		"1.    Load weekly diet plan from file." << endl <<
		"2.    Load weekly exercise plan from file." << endl <<
		"3.    Store weekly diet plan to file." << endl <<
		"4.    Store weekly exercise plan to file." << endl <<
		"5.    Display weekly diet plan to screen." << endl <<
		"6.    Display weekly exercise plan to screen." << endl <<
		"7.    Edit daily diet plan." << endl <<
		"8.    Edit daily exercise plan." << endl <<
		"9.    Sort diet plan by goal(high to low)" << endl <<
		"10.   Sort exercise plan by goal(high to low)" <<endl<<
		"11.   Sort diet plan by goal(low to high)" << endl <<
		"12.   Sort exercise plan by goal(low to high)" << endl <<
		"0.    Exit." << endl;
}
/*************************************************************
* Function: FitnessAppWrapper
* Date Created:2/25/2016
* Description: Constructor
* Input parameters: DietPlan ExercisePlan
* Returns: void
*************************************************************/

FitnessAppWrapper::FitnessAppWrapper()
{
//	pHead_diet = NULL;
//	pHead_exerise = NULL;
}

/*************************************************************
* Function: FitnessAppWrapper
* Date Created:2/25/2016
* Description: cp Constructor
* Input parameters: DietPlan ExercisePlan
* Returns: void
*************************************************************/

FitnessAppWrapper::FitnessAppWrapper(FitnessAppWrapper & rhs)
{
//	pHead_diet = rhs.pHead_diet;
//	pHead_exerise = rhs.pHead_exerise;
}

/*************************************************************
* Function: ~FitnessAppWrapper
* Date Created:2/25/2016
* Description: destructor
* Input parameters: none
* Returns: void
*************************************************************/

FitnessAppWrapper::~FitnessAppWrapper()
{
//	delete(pHead_diet); //free the pointer
//	delete(pHead_exerise);//free the pointer
}

/*************************************************************
* Function: runApp
* Date Created:2/25/2016
* Description: run app
* Input parameters: none
* Returns: void
*************************************************************/

void FitnessAppWrapper::runApp()
{
	NodeExercisePlan *Plist_Exercise = NULL;
	NodeExercisePlan *Plist_Diet = NULL;
	fstream fDiet("dietPlans.txt");
	fstream fExercise("exercisePlans.txt");
	DietPlan arrDiet[7];
	ExercisePlan arrExercise[7];
	int input_number = -1;
	while (input_number != 0) 
	{
		displayMenu();
		cout << "Enter: ";
		cin >> input_number;

		switch (input_number)
		{
		case 1:
			loadWeeklyPlan(fDiet, arrDiet);
			break;
		case 2:
			loadWeeklyPlan(fExercise, arrExercise);
			break;
		case 3:
			fDiet.close();
			fDiet.open("dietPlans.txt");
			storeWeeklyPlan(fDiet, arrDiet);
			break;
		case 4:
			fExercise.close();
			fExercise.open("exercisePlans.txt");
			storeWeeklyPlan(fExercise, arrExercise);
			break;
		case 5:
			displayWeeklyPlan(arrDiet);
			break;
		case 6:
			displayWeeklyPlan(arrExercise);
			break;
		case 7:
			fDiet.close();
			fDiet.open("dietPlans.txt");
			editDaily(fDiet, arrDiet);
			displayWeeklyPlan(arrDiet);
			system("pause");
			break;
		case 8:
			fExercise.close();
			fExercise.open("exercisePlans.txt");
			editDaily(fExercise, arrExercise);
			displayWeeklyPlan(arrExercise);
			system("pause");
			break;
		case 9:
			fDiet.close();
			fDiet.open("dietPlans.txt");
			sortByGoalHtL(fDiet, arrDiet);
			break;
		case 10:
			fExercise.close();
			fExercise.open("exercisePlans.txt");
			sortByGoalHtL(fExercise, arrExercise);
			break;
		case 11:
			fDiet.close();
			fDiet.open("dietPlans.txt");
			sortByGoalLtH(fDiet, arrDiet);
			break;
		case 12:
			fExercise.close();
			fExercise.open("exercisePlans.txt");
			sortByGoalLtH(fExercise, arrExercise);
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	fDiet.close();
	fDiet.open("dietPlans.txt");
	storeWeeklyPlan(fDiet, arrDiet);
	fExercise.close();
	fExercise.open("exercisePlans.txt");
	storeWeeklyPlan(fExercise, arrExercise);
	fDiet.close(); fExercise.close();
	system("pause");
	system("cls");
}
/*************************************************************
* Function: loadDaily
* Date Created:2/25/2016
* Description: load Daily
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::loadDaily(fstream & fileStream, DietPlan & plan)
{
	fileStream >> plan;
}

/*************************************************************
* Function: loadDaily
* Date Created:2/25/2016
* Description: load Daily
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::loadDaily(fstream & fileStream, ExercisePlan & plan)
{
	fileStream >> plan;
}
/*************************************************************
* Function: loadWeeklyPlan
* Date Created:2/25/2016
* Description: load Weekly Plan
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDaily(fileStream, weeklyPlan[i]);
	}
	cout << "loading sccessful!" << endl;
}
/*************************************************************
* Function: loadWeeklyPlan
* Date Created:2/25/2016
* Description: load Weekly Plan
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDaily(fileStream, weeklyPlan[i]);
	}
	cout << "loading sccessful!" << endl;
}
/*************************************************************
* Function: displayDailyPlan
* Date Created:2/25/2016
* Description: display Daily Plan
* Input parameters: DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::displayDailyPlan(DietPlan & plan)
{
	cout << plan;
}
/*************************************************************
* Function: displayDailyPlan
* Date Created:2/25/2016
* Description: display Daily Plan
* Input parameters: ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::displayDailyPlan(ExercisePlan & plan)
{
	cout << plan;
}
/*************************************************************
* Function: displayWeeklyPlan
* Date Created:2/25/2016
* Description: display Weekly Plan
* Input parameters: DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::displayWeeklyPlan(DietPlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		cout << plan[i] << endl;
	}
}
/*************************************************************
* Function: displayWeeklyPlan
* Date Created:2/25/2016
* Description: display Weekly Plan
* Input parameters: ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		cout << plan[i] << endl;
	}
}
/*************************************************************
* Function: storeDailyPlan
* Date Created:2/25/2016
* Description: store Daily Plan
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::storeDailyPlan(fstream & fileStream, DietPlan & plan)
{
	fileStream << plan;
}
/*************************************************************
* Function: storeDailyPlan
* Date Created:2/25/2016
* Description: store Daily Plan
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::storeDailyPlan(fstream & fileStream, ExercisePlan & plan)
{
	fileStream << plan;
}

/*************************************************************
* Function: storeWeeklyPlan
* Date Created:2/25/2016
* Description: store Weekly Plan
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::storeWeeklyPlan(fstream & fileStream, DietPlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, plan[i]);
	}
	cout << "storing sccessful!" << endl;
}
/*************************************************************
* Function: storeWeeklyPlan
* Date Created:2/25/2016
* Description: store Weekly Plan
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::storeWeeklyPlan(fstream & fileStream, ExercisePlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, plan[i]);
	}
	cout << "storing sccessful!" << endl;
}
/*************************************************************
* Function: editDaily
* Date Created:2/25/2016
* Description: edit Daily
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::editDaily(fstream & fileStream, DietPlan plan[])
{
	int input;
	displayWeeklyPlan(plan);
	cout << "which one do you want to edit?(number 1-7 from up to down): ";
	cin >> input;

	if (input >= 1 && input <= 7)
	{
		plan[input - 1].editGoal();
	}
	else
	{
		cout << "wrong input!" << endl;
	}
}
/*************************************************************
* Function: editDaily
* Date Created:2/25/2016
* Description: edit Daily
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::editDaily(fstream & fileStream, ExercisePlan plan[])
{
	int input;
	displayWeeklyPlan(plan);
	cout << "which one do you want to edit?(number 1-7 from up to down): ";
	cin >> input;

	if (input >= 1 && input <= 7)
	{
		plan[input - 1].editGoal();
	}
	else
	{
		cout << "wrong input!" << endl;
	}
}

/*************************************************************
* Function: sortByGoalHtL
* Date Created:2/25/2016
* Description: sort By Goal high to low
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::sortByGoalHtL(fstream & fileStream, DietPlan plan[])
{
	int temp = plan[0].getCalories();
	DietPlan temp_diet;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (plan[j].getCalories() < plan[j+1].getCalories())
			{
				temp_diet = plan[j];
				plan[j] = plan[j + 1];
				plan[j + 1]= temp_diet;
			}
		}
	}
	cout << "sorting sccessful!" << endl;
}
/*************************************************************
* Function: sortByGoalHtL
* Date Created:2/25/2016
* Description: sort By Goal high to low
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::sortByGoalHtL(fstream & fileStream, ExercisePlan plan[])
{
	int temp = plan[0].getSteps();
	ExercisePlan temp_exercise;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (plan[j].getSteps() < plan[j + 1].getSteps())
			{
				temp_exercise = plan[j];
				plan[j] = plan[j + 1];
				plan[j + 1] = temp_exercise;
			}
		}
	}
	cout << "sorting sccessful!" << endl;
}
/*************************************************************
* Function: sortByGoalLtH
* Date Created:2/25/2016
* Description: sort By Goal low to high
* Input parameters: fstream DietPlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::sortByGoalLtH(fstream & fileStream, DietPlan plan[])
{
	int temp = plan[0].getCalories();
	DietPlan temp_diet;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (plan[j].getCalories() > plan[j + 1].getCalories())
			{
				temp_diet = plan[j];
				plan[j] = plan[j + 1];
				plan[j + 1] = temp_diet;
			}
		}
	}
	cout << "sorting sccessful!" << endl;
}
/*************************************************************
* Function: sortByGoalLtH
* Date Created:2/25/2016
* Description: sort By Goal low to high
* Input parameters: fstream ExercisePlan
* Returns: void
*************************************************************/

void FitnessAppWrapper::sortByGoalLtH(fstream & fileStream, ExercisePlan plan[])
{
	int temp = plan[0].getSteps();
	ExercisePlan temp_exercise;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			if (plan[j].getSteps() > plan[j + 1].getSteps())
			{
				temp_exercise = plan[j];
				plan[j] = plan[j + 1];
				plan[j + 1] = temp_exercise;
			}
		}
	}
	cout << "sorting sccessful!" << endl;
}