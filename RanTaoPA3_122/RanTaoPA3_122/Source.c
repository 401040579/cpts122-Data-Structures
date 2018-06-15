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
/*************************************************************
* Function: QueueNode * makeNode(int customerNumber, int serviceTime, int totalTime)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: make a Node for malloc
* Return: address of the node
*************************************************************/
QueueNode * makeNode(int customerNumber, int serviceTime, int totalTime)
{
	QueueNode *pMem = (QueueNode *)malloc(sizeof(QueueNode));

	if (pMem != NULL)
	{
		pMem->customerNumber = customerNumber;
		pMem->serviceTime = serviceTime;
		pMem->totalTime = totalTime;
		pMem->pNext = NULL;
		pMem->pList = NULL;
	}

	return pMem;
}
/*************************************************************
* Function: int enqueue(Queue *pQ, int customerNumber, int serviceTime, int totalTime)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: inserts a node to the tail of the queue; the node is allocated dynamically
* Return: returns true if the memory was allocated for a node, false otherwise
*************************************************************/
int enqueue(Queue *pQ, int customerNumber, int serviceTime, int totalTime)
{
	QueueNode *pMem = makeNode(customerNumber, serviceTime, totalTime);
	int success = 0;

	if (pMem != NULL)
	{
		// we allocate memory successfully
		success = 1;
		if (pQ->pHead != NULL)
		{
			// queue is not empty
			pQ->pTail->pNext = pMem;
			pQ->pTail = pMem;
		}
		else
		{
			// queue is empty
			pQ->pHead = pQ->pTail = pMem;
		}
	}

	return success;
}
/*************************************************************
* Function: int dequeue(Queue *pQ)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: deletes a node from the head of the queue; returns the data in the node
* Return: returns true if the memory was allocated for a node, false otherwise
* Precondition: queue is not empty (isEmpty () must be called before dequeue () is called)
*************************************************************/
int dequeue(Queue *pQ)
{
	QueueNode *pCur = pQ->pHead;
	int totalTime = 0;

	if (pQ->pHead == pQ->pTail)
	{
		pQ->pHead = pQ->pTail = NULL;
	}
	else
	{
		// more then one node in queue
		pQ->pHead = pQ->pHead->pNext;
	}
	totalTime = pCur->totalTime;
	free(pCur);
	return totalTime;
}
/*************************************************************
* Function: void printQueue(Queue pQ)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: prints out the data in the queue
* Return: void
*************************************************************/
void printQueue(Queue pQ)
{
	if (pQ.pHead == NULL)
	{
		printf("no one in line\n");
	}
	while (pQ.pHead != NULL)
	{
		printf("       |\n");
		printf("       V\n");
		printf("*********************\n");
		printf("*Customer Number: %d *\n", pQ.pHead->customerNumber);
		printf("*Service Time: %d    *\n", pQ.pHead->serviceTime);
		printf("*Total Time: %d      *\n", pQ.pHead->totalTime);
		printf("*********************\n");
		pQ.pHead = pQ.pHead->pNext;
	}

}
/*************************************************************
* Function: int isEmpty(Queue pQ)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: a predicate function which checks to see if the queue is empty
* Return:  returns true if the queue is empty; false otherwise
*************************************************************/
int isEmpty(Queue pQ)
{
	if (pQ.pHead == NULL) return 1;
	return 0;
}
/*************************************************************
* Function: void countTotalTime(Queue *pQ)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: count the total time of every node in the queue
* Return: void
*************************************************************/
void countTotalTime(Queue *pQ)
{
	QueueNode *pCur = NULL, *pTemp = NULL;
	int totalTime = 0;
	if (pQ->pHead != NULL)
	{
		pTemp = pQ->pHead;
		pCur = pQ->pHead;
		while (pCur != NULL)
		{
			while (pTemp != pCur->pNext)
			{
				totalTime = totalTime + pTemp->serviceTime;
				pTemp = pTemp->pNext;
			}
			pCur->totalTime = totalTime;
			pCur = pCur->pNext;
		}
	}
	

}
/*************************************************************
* Function: void run()
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: run the main function
* Return: void
*************************************************************/
void run()
{
	Queue pQ_ex = { NULL, NULL }, pQ_no = { NULL, NULL };
	int userTime = 0;
	int ArrivalTime = 0, serviceTime = 0, totalTime_ex = 0, totalTime_no = 0;
	int realTime = 0, tempTime = 0, custNum = 0;
	int hour = 8, minu = 0, temp_minu = 0, go_express_line = 0;
	srand((unsigned)(time(NULL)));

	printf("Set the timer (in mins): ");
	scanf("%d", &userTime); getchar();

	printf("This store open at 8:00\n");
	while (realTime <= userTime)// run loop
	{
		custNum++;//custmer come
		go_express_line = rand() % 2; // choose line randomly 

		if (go_express_line == 1) { // go to express line
			//Generate a random number between 1 每 5 and 3 每 8 for express and normal lanes
			ArrivalTime = rand() % 5 + 1;
			serviceTime = rand() % 5 + 1;
			realTime = ArrivalTime + realTime; //record the real time
			tempTime = ArrivalTime + tempTime; //record the real time for print out the entire queue
			if (minu + ArrivalTime >= 60) // let time looks like normal
			{
				hour = hour + 1;
				minu = minu - 60 + ArrivalTime;
			}
			else
			{
				minu = minu + ArrivalTime;
			}
			printf("Customer: %d. Arrival Time: %d:%.2d. Chosen Express Line. Service Time: %d \n", custNum, hour, minu, serviceTime);


			if (isEmpty(pQ_ex) == 0)// if queue is not empty
			{
				if (pQ_ex.pHead->serviceTime > ArrivalTime) // when a person arrived, there are some people in the line
				{
					enqueue(&pQ_ex, custNum, serviceTime, totalTime_ex); // so, enqueue to the tail
					pQ_ex.pHead->serviceTime = pQ_ex.pHead->serviceTime - ArrivalTime; //service time running
				}
				else
				{
					while (pQ_ex.pHead != NULL && pQ_ex.pHead->serviceTime <= ArrivalTime) // when a person arrived, there is person done checking out
					{
						ArrivalTime = ArrivalTime - (pQ_ex.pHead->serviceTime);
						printf("Customer: %d. done checking out in Express Line. \n", pQ_ex.pHead->customerNumber);
						dequeue(&pQ_ex);// the dequeue the head
					}
					enqueue(&pQ_ex, custNum, serviceTime, totalTime_ex);// then someone enqueue
				}
			}
			else
			{
				enqueue(&pQ_ex, custNum, serviceTime, totalTime_ex);//frist coustmer
			}

		}
		else// go to normal line
		{
			//Generate a random number between 1 每 5 and 3 每 8 for express and normal lanes
			ArrivalTime = rand() % 6 + 3;
			serviceTime = rand() % 6 + 3;
			realTime = ArrivalTime + realTime; //record the real time
			tempTime = ArrivalTime + tempTime; //record the real time for print out the entire queue
			if (minu + ArrivalTime >= 60) // let time looks like normal
			{
				hour = hour + 1;
				minu = minu - 60 + ArrivalTime;
			}
			else
			{
				minu = minu + ArrivalTime;
			}
			printf("Customer: %d. Arrival Time: %d:%.2d. Chosen Normal Line. Service Time: %d \n", custNum, hour, minu, serviceTime);


			if (isEmpty(pQ_no) == 0)// if queue is not empty
			{
				if (pQ_no.pHead->serviceTime > ArrivalTime)  // when a person arrived, there are some people in the line
				{
					enqueue(&pQ_no, custNum, serviceTime, totalTime_no);// so, enqueue to the tail
					pQ_no.pHead->serviceTime = pQ_no.pHead->serviceTime - ArrivalTime; //service time running
				}
				else
				{
					while (pQ_no.pHead != NULL && pQ_no.pHead->serviceTime <= ArrivalTime) // when a person arrived, there is person done checking out
					{
						ArrivalTime = ArrivalTime - (pQ_no.pHead->serviceTime);
						printf("Customer: %d. done checking out in Normal Line. \n", pQ_no.pHead->customerNumber);
						dequeue(&pQ_no);// the dequeue the head
					}
					enqueue(&pQ_no, custNum, serviceTime, totalTime_no);// then someone enqueue
				}
			}
			else
			{
				enqueue(&pQ_no, custNum, serviceTime, totalTime_no);//frist coustmer
			}
		}
		countTotalTime(&pQ_ex);
		countTotalTime(&pQ_no);
		if (tempTime >= 10) {
			tempTime -= 10;
			printf("*****************************Express Line*********************************\n");
			printQueue(pQ_ex);//print out express line
			printf("*****************************Normal Line**********************************\n");
			printQueue(pQ_no);//print out normal line
			printf("**************************************************************************\n\n");
			system("pause");
		}
	}
}
//////////////////////////Bonus///////////////////////////////////////////////
/*************************************************************
* Function: ListNode * makeListNode(char food[100])
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: make a Node for malloc
* Return: address of the node
*************************************************************/
ListNode * makeListNode(char food[100])
{
	ListNode *pMem = (ListNode *)malloc(sizeof(ListNode));

	strcpy(pMem->food, food);
	pMem->pNext = NULL;
	return pMem;
}
/*************************************************************
* Function: int insertFoodAtFront(ListNode ** pHead, char food[100])
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: inserts a node to the front list
* Return: returns true if the memory was allocated for a node, false otherwise
*************************************************************/
int insertFoodAtFront(ListNode ** pHead, char food[100])
{
	ListNode *pMem = makeListNode(food);
	int success = 0;
	if (pMem != NULL)
	{
		if (*pHead != NULL)
		{
			success = 1;
			pMem->pNext = *pHead;
		}
		*pHead = pMem;
	}
	return success;
}
/*************************************************************
* Function: int randomFood(ListNode **pHead)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: random food
* Return: return Quantity of Food
*************************************************************/
int randomFood(ListNode **pHead)
{
	int randNum = 0;
	int i = 0;
	int countFood = 0;

	randNum = rand() % 2 + 1;
	for (i = 0; i < randNum; i++) {
		insertFoodAtFront(pHead, "cereal");
		countFood = countFood + 1;
	}

	randNum = rand() % 2 + 1;
	for (i = 0; i < randNum; i++) {
		insertFoodAtFront(pHead, "milk");
		countFood = countFood + 1;
	}

	randNum = rand() % 2;
	for (i = 0; i < randNum; i++) {
		insertFoodAtFront(pHead, "steak");
		countFood = countFood + 1;
	}
	return countFood;
}
/*************************************************************
* Function: void printList(ListNode *pHead)
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: print list
*************************************************************/
void printList(ListNode *pHead)
{
	while (pHead != NULL) {
		printf("->");
		printf("%s", pHead->food);
		pHead = pHead->pNext;
	}
}
/*************************************************************
* Function: void run_BONUS()
* Date Created: February 5, 2016
* Date Last Modified: February 12, 2016
* Description: run the main function
* Return: void
*************************************************************/
void run_BONUS()
{
	Queue pQ_ex = { NULL, NULL }, pQ_no = { NULL, NULL };
	ListNode *pList = NULL;
	int userTime = 0;
	int ArrivalTime = 0, serviceTime = 0, totalTime_ex = 0, totalTime_no = 0;
	int realTime = 0, tempTime = 0, custNum = 0;
	int hour = 8, minu = 0, temp_minu = 0, go_express_line = 0;
	srand((unsigned)(time(NULL)));

	printf("Set the timer (in mins): ");
	scanf("%d", &userTime); getchar();

	printf("This store open at 8:00\n");
	while (realTime <= userTime)// run loop
	{
		//pList = NULL;
		custNum++;//custmer come
		go_express_line = rand() % 2; // choose line randomly 

		if (go_express_line == 1) { // go to express line
									//Generate a random number between 1 每 5 and 3 每 8 for express and normal lanes
			ArrivalTime = rand() % 5 + 1;
			realTime = ArrivalTime + realTime; //record the real time
			tempTime = ArrivalTime + tempTime; //record the real time for print out the entire queue

			serviceTime = randomFood(&pList) * 2;
			printf("Customer: %d. Arrival Time: %d:%.2d. Chosen Express Line. Quantity of Food: %d Service Time: %d. \n", custNum, hour, minu, serviceTime / 2, serviceTime);
			
			if (minu + ArrivalTime >= 60) // let time looks like normal
			{
				hour = hour + 1;
				minu = minu - 60 + ArrivalTime;
			}
			else
			{
				minu = minu + ArrivalTime;
			}
			if (isEmpty(pQ_ex) == 0)// if queue is not empty
			{
				pQ_ex.pHead->pList = pList;// it contains a pointer to the start of a dynamic singly linked list. 
				if (pQ_ex.pHead->serviceTime > ArrivalTime) // when a person arrived, there are some people in the line
				{
					enqueue(&pQ_ex, custNum, serviceTime, totalTime_ex); // so, enqueue to the tail
					pQ_ex.pHead->serviceTime = pQ_ex.pHead->serviceTime - ArrivalTime; //service time running
				}
				else
				{
					while (pQ_ex.pHead != NULL && pQ_ex.pHead->serviceTime <= ArrivalTime) // when a person arrived, there is person done checking out
					{
						ArrivalTime = ArrivalTime - (pQ_ex.pHead->serviceTime);
						printf("Customer: %d. done checking out in Express Line. \n", pQ_ex.pHead->customerNumber);
						dequeue(&pQ_ex);// the dequeue the head
					}
					enqueue(&pQ_ex, custNum, serviceTime, totalTime_ex);// then someone enqueue
				}
			}
			else
			{
				enqueue(&pQ_ex, custNum, serviceTime, totalTime_ex);//frist coustmer
				
			}

		}
		else// go to normal line
		{
			//Generate a random number between 1 每 5 and 3 每 8 for express and normal lanes
			ArrivalTime = rand() % 6 + 3;
			realTime = ArrivalTime + realTime; //record the real time
			tempTime = ArrivalTime + tempTime; //record the real time for print out the entire queue
			if (minu + ArrivalTime >= 60) // let time looks like normal
			{
				hour = hour + 1;
				minu = minu - 60 + ArrivalTime;
			}
			else
			{
				minu = minu + ArrivalTime;
			}

			serviceTime = randomFood(&pList) * 2;
			printf("Customer: %d. Arrival Time: %d:%.2d. Chosen Normal Line. Quantity of Food: %d. Service Time: %d \n", custNum, hour, minu, serviceTime/2, serviceTime);

			if (isEmpty(pQ_no) == 0)// if queue is not empty
			{
				pQ_no.pHead->pList = pList;// it contains a pointer to the start of a dynamic singly linked list. 
				if (pQ_no.pHead->serviceTime > ArrivalTime)  // when a person arrived, there are some people in the line
				{
					enqueue(&pQ_no, custNum, serviceTime, totalTime_no);// so, enqueue to the tail
					pQ_no.pHead->serviceTime = pQ_no.pHead->serviceTime - ArrivalTime; //service time running
				}
				else
				{
					while (pQ_no.pHead != NULL && pQ_no.pHead->serviceTime <= ArrivalTime) // when a person arrived, there is person done checking out
					{
						ArrivalTime = ArrivalTime - (pQ_no.pHead->serviceTime);
						printf("Customer: %d. done checking out in Normal Line. \n", pQ_no.pHead->customerNumber);
						dequeue(&pQ_no);// the dequeue the head
					}
					enqueue(&pQ_no, custNum, serviceTime, totalTime_no);// then someone enqueue
				}
			}
			else
			{
				enqueue(&pQ_no, custNum, serviceTime, totalTime_no);//frist coustmer
			}
		}
		countTotalTime(&pQ_ex);
		countTotalTime(&pQ_no);
		if (tempTime >= 10) {
			tempTime -= 10;
			printf("*****************************Express Line*********************************\n");
			printQueue(pQ_ex);//print out express line
			printf("*****************************Normal Line**********************************\n");
			printQueue(pQ_no);//print out normal line
			printf("**************************************************************************\n\n");
			printf("All Sold Items: ");
			printList(pList);
			printf("\n");
			system("pause");
		}
	}
}


/*
void run_BONUS()
{
	Queue pQ_ex = { NULL, NULL }, pQ_no = { NULL, NULL };
	int userTime = 250;
	int ArrivalTime = 0, serviceTime = 0, totalTime = 0;
	int realTime = 0, custNum = 0, n = 0; //n = 0 is FALSE
	int hour = 8, minu = 0, go_express_line = 0;
	srand((unsigned)(time(NULL)));
	printf("This store open at 8:00\n");
	while (realTime <= userTime)
	{
		printf("Time: %d:%.2d\n\ntime lapses\n~~~~~~~~~~~~~~\n", hour, minu);
		n = 0; //Reset each add
		custNum++;
		go_express_line = rand() % 2;

		if (go_express_line == 1) {
			ArrivalTime = rand() % 5 + 1;
			realTime = ArrivalTime + realTime; //Keeps track of customer number based on available service time.
			serviceTime = rand() % 5 + 1;
			totalTime = serviceTime + totalTime;
			if (minu + ArrivalTime >= 60)
			{
				hour = hour + 1;
				minu = minu - 60 + ArrivalTime;
			}
			else
			{
				minu = minu + ArrivalTime;
			}
			printf("Customer: %d arrival Time: %d:%.2d ", custNum, hour, minu);

			printf("Chosen Express Line\n");

			if (!isEmpty(pQ_ex))
			{
				if (pQ_ex.pHead->serviceTime > ArrivalTime) //Person in front not standing long enough to leave yet
				{
					enqueue(&pQ_ex, custNum, serviceTime, totalTime);
					n = 1; //Node was added
					pQ_ex.pHead->serviceTime = pQ_ex.pHead->serviceTime - ArrivalTime; //denotes realTime while being serviced but not done
				}
				else //Person in front serviced before next addition
				{
					while (pQ_ex.pHead != NULL && pQ_ex.pHead->serviceTime <= ArrivalTime) //Keep servicing guy in front till new guy arrives
					{
						ArrivalTime = ArrivalTime - (pQ_ex.pHead->serviceTime); //Time less guy already served
						dequeue(&pQ_ex);
					}
				}

				if (n != 1) //No Node added so add next guy
				{
					enqueue(&pQ_ex, custNum, serviceTime, totalTime);
				}
			}
			else
			{
				enqueue(&pQ_ex, custNum, serviceTime, totalTime);
			}
			printQueue(pQ_ex);
			printf("\n***Express Line above***\n");

			system("PAUSE");
			system("cls");
		}
		else
		{
			ArrivalTime = rand() % 6 + 3;
			realTime = ArrivalTime + realTime; //Keeps track of customer number based on available service time.
			serviceTime = rand() % 6 + 3;
			totalTime = serviceTime + totalTime;
			if (minu + ArrivalTime >= 60)
			{
				hour = hour + 1;
				minu = minu - 60 + ArrivalTime;
			}
			else
			{
				minu = minu + ArrivalTime;
			}
			printf("Customer: %d arrival Time: %d:%.2d ", custNum, hour, minu);

			printf("Chosen Normal Line\n");

			if (!isEmpty(pQ_no))
			{
				if (pQ_no.pHead->serviceTime > ArrivalTime) //Person in front not standing long enough to leave yet
				{
					enqueue(&pQ_no, custNum, serviceTime, totalTime);
					n = 1; //Node was added
					pQ_no.pHead->serviceTime = pQ_no.pHead->serviceTime - ArrivalTime; //denotes realTime while being serviced but not done
				}
				else //Person in front serviced before next addition
				{
					while (pQ_no.pHead != NULL && pQ_no.pHead->serviceTime <= ArrivalTime) //Keep servicing guy in front till new guy arrives
					{
						ArrivalTime = ArrivalTime - (pQ_no.pHead->serviceTime); //Time less guy already served
						dequeue(&pQ_no);
					}
				}

				if (n != 1) //No Node added so add next guy
				{
					enqueue(&pQ_no, custNum, serviceTime, totalTime);
				}
			}
			else
			{
				enqueue(&pQ_no, custNum, serviceTime, totalTime);
			}

			printQueue(pQ_no);
			printf("\n***Normal Line above***\n");
			system("PAUSE");
			system("cls");
		}
	}
}
*/

/*
void run1()
{
	Queue pQ_ex = { NULL, NULL };
	Queue pQ_no = { NULL, NULL };
	int express_num = 0, normal_num = 0, customerNumber = 0,
		serviceTime_ex = 0, totalTime_ex = 0,
		temp_serviceTime_ex = 0;
	int n = 0;
	//normal_num = rand() / 6 + 3;

	int hour = 8, minu = 0;
	int arrival_times = 0;
	int go_express_line = 0;

	srand((unsigned)(time(NULL)));
	printf("Time: %d: %d\n", hour, minu);
	n++;
	arrival_times = rand() / 5 + 1;
	if (minu + arrival_times >= 60)
	{
		hour = hour + 1;
		minu = minu - 60 + arrival_times;
	}
	else
	{
		minu = minu + arrival_times;
	}
	printf("customer: %d\narrival Time: %d: %d\n", n, hour, minu);
	go_express_line = rang() / 2;
	if (go_express_line == 1)
	{
		printf("chosen express line\n");

		if (isEmpty(pQ_ex) == 1)
		{

			if (someone_in_server == 1)
			{

			}
			else
			{
				serviceTime_ex = rand() / 5 + 1;
				totalTime_ex = totalTime_ex + serviceTime_ex;
				enqueue(&pQ_ex, n, serviceTime_ex, totalTime_ex);
				printQueue(pQ_ex);
			}
		}
		else
		{
			serviceTime_ex = rand() / 5 + 1;
			if (temp_serviceTime_ex < serviceTime_ex)
			{
				serviceTime_ex = serviceTime_ex - serviceTime_ex;
			}
		}

	}
	else // go mormal line;
	{

	}



}*/