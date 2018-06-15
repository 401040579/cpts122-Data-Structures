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
int main() {
	
		char maze[8][8] = {
			{ "x xxxxxx" },
			{ "x xxx xx" },
			{ "x xxx xx" },
			{ "x      x" },
			{ "x xxxxxx" },
			{ "x   xx x" },
			{ "xxx    x" },
			{ "xxxxxx  " } };
		char maze_no_path[8][8] = {
			{ "x xxxxxx" },
			{ "x xxx xx" },
			{ "x xxx xx" },
			{ "x      x" },
			{ "x xxxxxx" },
			{ "xx  xx x" },
			{ "xxx    x" },
			{ "xxxxxx  " } };

		int success = 0, input = 0,
			i = 0, j = 0;

		
		printf("-----PART 2-----\n\n1, have path\n2, no path\n3, exit\n");
		scanf("%d", &input);
		getchar();//take the enter key.
		switch (input)
		{
		case 1:
		{
			printf("show maze£º\n");
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					if (maze[i][j] == 'x')
						printf("x");
					else
						printf(" ");
				}
				printf("\n");
			}
			//Starting at position (0, 1), and using pointer to modify success
			if (find_path(0, 1, maze, &success) == 0)
			{
				printf("\nthere is no path£¡\n");
			}
			else
			{
				printf("\nexit found£º\n");
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j++)
					{
						if (maze[i][j] == 'x')
							printf("x");
						else if (maze[i][j] == '*')
							printf("*");
						else
							printf(" ");
					}
					printf("\n");
				}
			}
		}
		break;
		case 2:
		{
			printf("show maze£º\n");
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					if (maze_no_path[i][j] == 'x')
						printf("x");
					else
						printf(" ");
				}
				printf("\n");
			}
			//Starting at position (0, 1), and using pointer to modify success
			if (find_path(0, 1, maze_no_path, &success) == 0)
			{
				printf("\nthere is no path£¡\n");
			}
			else
			{
				printf("\nexit found£º\n");
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j++)
					{
						if (maze_no_path[i][j] == 'x')
							printf("x");
						else if (maze_no_path[i][j] == '*')
							printf("*");
						else
							printf(" ");
					}
					printf("\n");
				}
			}
		}
		break;
		default:
			break;
		}
		system("pause");
		system("cls");
	return 0;
}
