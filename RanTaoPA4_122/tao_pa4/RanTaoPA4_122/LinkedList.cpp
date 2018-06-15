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

NodeDietPlan::NodeDietPlan(DietPlan & Plan, NodeDietPlan * pNext)
{
	this->Plan = Plan;
	this->pNext = NULL;
}

NodeDietPlan::NodeDietPlan(const NodeDietPlan * pN)
{
	Plan = pN->Plan;
	pNext = pN->pNext;
}

NodeDietPlan::~NodeDietPlan()
{
	free(pNext);
}

NodeExercisePlan::NodeExercisePlan(ExercisePlan & Plan, NodeExercisePlan * pNext)
{
	this->Plan = Plan;
	this->pNext = NULL;
}

NodeExercisePlan::NodeExercisePlan(const NodeExercisePlan * pN)
{
	Plan = pN->Plan;
	pNext = pN->pNext;
}

NodeExercisePlan::~NodeExercisePlan()
{
	free(pNext);
}


