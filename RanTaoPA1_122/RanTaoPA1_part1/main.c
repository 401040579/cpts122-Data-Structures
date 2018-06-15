/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 1
* Date: Jan 22, 2015
* Description:Write a C program that sorts strings into descending or ascending order
(determined by the user of the program). For this program you must declare an array of
pointers to the strings, and perform the sorting without using strcpy ( ).
*******************************************************************************************/
#include "Header.h"

int main(void) {
	//driver
	char str[100] = "qwertyuiopasdfghjklzxcvbnm";
	char str_user[100] = "\0";
	int order = 0, loop = 1, input = 0;

	do {
		printf("-----PART 1-----\n\n1, test driver\n2, input your stuff\n3, exit\n");
		scanf("%d", &input);
		getchar();
		switch (input)
		{
			//test driver
		case 1: {
			printf("before sort: %s\n", str);
			bubble_sort(str, 26, 1);
			printf("after sort(descending order): %s\n\n", str);

			strcpy(str, "qwertyuiopasdfghjklzxcvbnm");
			printf("before sort: %s\n", str);
			bubble_sort(str, 26, 2);
			printf("after sort(ascending order): %s\n\n", str);
		}
			break;
				//input
		case 2: {
			do {
				memset(str_user, 0, sizeof(str_user));
				printf("enter string you want to sort: ");
				gets(str_user);
				printf("1. descending order\n"
					"2. ascending order\n");
				//if shift_num is not int, scanf will return 0
				if (scanf("%d", &order) == 0 || order < 1 || order > 2) { 
					getchar();
					printf("wrong input! try again.\n");
				}
				else loop = 0;// loop is to end the loop
			} while (loop != 0);

			bubble_sort(str_user, strlen(str_user), order);

			printf("after sort: %s\n\n", str_user);
		}
			break;

		default:
			break;
		}
		system("pause");
		system("cls");
	} while (input != 3);
	return 0;
}