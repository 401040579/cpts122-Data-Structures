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
#include "Header.h"

/*************************************************************
* Function: find_path(int x, int y, char maze[8][8], int *success)
* Date Created: 1/17/2016
* Date Last Modified:  1/22/2016
* Description: recursively determines if a path exists in a maze
*************************************************************/
int find_path(int x, int y, char maze[8][8], int *success) {
	//pass the point, set '*'
	maze[x][y] = '*';
	//exit found
	if (x == 7 && y == 7) *success = 1;

	//go around
	if (*success != 1 && maze[x][y + 1] == ' ') find_path(x, y + 1, maze, success);
	if (*success != 1 && maze[x + 1][y] == ' ') find_path(x + 1, y, maze, success);
	if (*success != 1 && maze[x][y - 1] == ' ') find_path(x, y - 1, maze, success);
	if (*success != 1 && maze[x - 1][y] == ' ') find_path(x - 1, y, maze, success);

	//passed the point£¬but success == 0£¬reset the point to ' '
	if (*success != 1) maze[x][y] = ' ';

	return *success;
}