/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 1
* Date: Jan 22, 2015
* Description:Write a C program that recursively determines if a path exists in a maze.
You must also write a function that accepts an 8 by 8 array of characters that represents a maze.
Each position can contain either an X or a blank. Starting at position (0, 1), list any path
through the maze to get to location (7, 7). Only horizontal and vertical moves are allowed.
If no path exists, write a message indicating there is no path. Moves can be made only to
locations that contain a blank. If an X is encountered, that path is blocked and another
must be chosen. ¨C-Source Hanly & Koffman, Problem Solving and Program Design in C.
*******************************************************************************************/
#pragma once
#ifndef RanTaoPA1_part2
#define RanTaoPA1_part2

#include <stdio.h>
#include <stdlib.h>

int find_path(int x, int y, char maze[8][8], int *success);

#endif