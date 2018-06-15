/*******************************************************************************************
* Programmer: Ran Tao
* Class: CptS 122, Spring  2016
* Programming Assignment: PA 1
* Date: Jan 22, 2015
* Description: Write a C program that encrypts and decrypts strings using the Caesar Shift
Cipher. The shift value must be an integer, but may be positive or negative. If the shift
value is 4, then an ¡®A¡¯ becomes ¡®E¡¯. If the shift value is -4, then ¡®A¡¯ becomes ¡®W¡¯. Note,
the plaintext messages are encrypted using alphabetic characters only. Also, all characters
in the messages must first be converted to uppercase before encrypting or decrypting them.
Develop your own program driver to illustrate that your program works. You may use any
library functions you wish.
*******************************************************************************************/
#include "Header.h"

int main() {
	char str[100] = { "\0" }, str_upper[100] = { "\0" };
	int shift_num = 0, loop = 1, lenth = 0, input = 0;

	do {
		printf("-----PART 3-----\n\n1, test driver\n2, input your stuff\n3, exit\n");
		scanf("%d", &input);
		getchar();
		switch (input)
		{
			//test driver
		case 1: {
			printf("-----------encrypts-----------\n");
			strcpy(str, "ThE QUiCK BRoWN FoX JUmPS OveR ThE LaZY DoG");
			printf("input: ");
			puts(str);
			shift_num = -3;
			printf("shift value: %d\n", shift_num);
			memset(str_upper, 0, sizeof(str_upper));
			lower_to_upper(str, str_upper);
			printf("converted to uppercase: ");
			puts(str_upper);
			encrypts_and_decrypts(str_upper, shift_num);
			//output the result
			printf("output: ");
			puts(str_upper);
			printf("\n\n");

			printf("-----------decrypts-----------\n");
			strcpy(str, "qeb&*(^ NrfzH YOLTK CLU123 GRJMP LSBO Q!@EB Ixwv*%1 ALD");
			printf("input: ");
			puts(str);
			shift_num = 3;
			printf("shift value: %d\n", shift_num);
			memset(str_upper, 0, sizeof(str_upper));
			lower_to_upper(str, str_upper);
			printf("converted to uppercase: ");
			puts(str_upper);
			encrypts_and_decrypts(str_upper, shift_num);
			//output the result
			printf("output: ");
			puts(str_upper);
			printf("\n\n");
		}
				break;
				//input
		case 2: {
			printf("encrypts and decrypts sentence: ");
			gets(str);//user input
			memset(str_upper, 0, sizeof(str_upper));
			lower_to_upper(str, str_upper);
			printf("converted to uppercase: ");
			puts(str_upper);
			//input error check
			do {
				printf("shift value: ");
				if (scanf("%d", &shift_num) == 0) { //if shift_num is not int, scanf will return 0
					getchar();
					printf("wrong input! try again.\n");
				}
				else loop = 0;
			} while (loop != 0);

			encrypts_and_decrypts(str_upper, shift_num);

			//output the result
			printf("output: ");
			puts(str_upper);
		}
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (input != 3);
	return 0;
}