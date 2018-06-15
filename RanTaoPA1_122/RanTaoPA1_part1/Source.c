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

/*************************************************************
* Function: bubble_sort(char *arr, int num, int order)
* Date Created: 1/17/2016
* Date Last Modified:  1/22/2016
* Description: sorts strings into descending or ascending order
*************************************************************/
void bubble_sort(char *arr, int num, int order) {
	int marker_u, marker_c, buffer;
	// get values for n and the n list items (n represents the number of records in the file, list is an array of records)
	marker_u = num;
	//while the unsorted section has more than one element do steps 4 through 8
	while (marker_u > 1) {
		//set the current element marker C at the second element of the list (C is an integer index value)
		marker_c = 1;
		//while C has not passed U 
		while (marker_c < marker_u) {
			//if the item at position C is less than the item to its left then exchange these two items
			//descending or ascending order (determined by the user of the program)
			if (order == 2 ? *(arr + marker_c) < *(arr + marker_c - 1) : *(arr + marker_c) > *(arr+marker_c - 1)) {
				buffer = *(arr+marker_c);
				*(arr+marker_c) = *(arr+marker_c - 1);
				*(arr + marker_c - 1) = buffer;
			}
			//move C to the right one position
			marker_c++;
		}
		//move U left one position
		marker_u--;
	}
}