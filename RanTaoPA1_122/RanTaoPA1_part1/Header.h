/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 1
* Date: Jan 22, 2015
* Description:Write a C program that sorts strings into descending or ascending order
(determined by the user of the program). For this program you must declare an array of
pointers to the strings, and perform the sorting without using strcpy ( ).
*******************************************************************************************/
#pragma once

#ifndef RanTaoPA1_part1
#define RanTaoPA1_part1

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(char *arr, int num, int order);

#endif
