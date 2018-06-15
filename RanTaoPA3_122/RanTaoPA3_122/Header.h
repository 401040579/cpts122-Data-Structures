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
#ifndef RANTAOPA3
#define RANTAOPA3

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct queueNode
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
	struct queueNode *pNext;

	struct listNode *pList;//for bouns

} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
}Queue;

typedef struct listNode
{
	char food[100];
	struct listNode *pNext;
}ListNode;

QueueNode * makeNode(int customerNumber, int serviceTime, int totalTime);

int enqueue(Queue *pQ, int customerNumber, int serviceTime, int totalTime);

int dequeue(Queue *pQ);

void printQueue(Queue pQ);

int isEmpty(Queue pQ);

void countTotalTime(Queue *pQ);

void run();
/////////////////////////////////////////BONUS
ListNode * makeListNode(char food[100]);

int insertFoodAtFront(ListNode **pHead, char food[100]);

int randomFood(ListNode **pHead);

//void printQueueAndFood(Queue pQ);

void printList(ListNode *pHead);

void run_BONUS();


#endif