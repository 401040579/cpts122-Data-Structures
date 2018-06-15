/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 3
* Created: February 5, 2016
* Last Revised: February 12, 2016
* Description: For this assignment you will need to simulate two lines using queues. This will
*	require that you develop enqueue ( ) (insert), dequeue ( ) (delete), and printQueue ( )
*	operations for a queue. Although you will instantiate two queues, each one of these will
*	consist of the same kind of queue nodes. One of your queues will represent the express
*	lane and the other a normal lane. You will randomly generate arrival times and service
*	times of customers into each lane. The express lane has customers arrive every one to five
*	minutes, and customers arrive every three to eight minutes in the normal lane. Service times
*	vary from one to five minutes, and three to eight minutes, for express and normal lane customers,
*	respectively. As customers arrive into each line print out a messageindicating in which line
*	each customer arrives, along with the overall corresponding arrival time and customer number. When
*	customers have finished checking out, print out a message indicating which line the customer was in,
*	along the corresponding customer number and totalTimein the line. Allow for the simulation to
*	run for n number of minutes, where n is inputted by the user.
*******************************************************************************************/
#include "Header.h"

int main()
{
	int input = 0;
	do {
		printf("1. run main\n"
			"2. run main + BONUS\n"
			"3. exit\n");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			system("cls");
			run();
			break;
		case 2:
			system("cls");
			run_BONUS();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (input != 3);



	return 0;
}