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

/*************************************************************
* Function: lower_to_upper(char str[100], char str_upper[100])
* Date Created: 1/17/2016
* Date Last Modified:  1/22/2016
* Description: let letter to upper case
*************************************************************/
void lower_to_upper(char str[100], char str_upper[100])
{
	int lenth = 0, j = 0;
	//get lenth of the string
	lenth = strlen(str);

	for (int i = 0; i < lenth; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		// accepting space
		if (((str[i] >= 'A' && str[i] <= 'Z') || str[i] == 32))
		{
			str_upper[j++] = str[i];
		}
	}
}

/*************************************************************
* Function: encrypts_and_decrypts(char str[100], int shift_num)
* Date Created: 1/17/2016
* Date Last Modified:  1/22/2016
* Description: encrypts and decrypts strings using the Caesar Shift Cipher
*************************************************************/
void encrypts_and_decrypts(char str[100], int shift_num)
{
	//char s[] = { "\0" };
	//scanf("%s", &s);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != 32) {
			//encryption
			if (shift_num >= 0) {
				str[i] = 65 + ((str[i] - 65 + shift_num) % 26);
			}
			//decryption
			else {
				//when str[i]<'a'
				if (str[i] + shift_num % 26 < 65) {
					str[i] = str[i] + (shift_num % 26 + 26);
				}
				//when str[i] between 'a' and 'z'
				else {
					str[i] = str[i] + shift_num;
				}
			}
		}
	}
}