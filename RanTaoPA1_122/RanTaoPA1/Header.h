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
#pragma once

#ifndef RanTaoPA1_part3
#define RanTaoPA1_part3

#include <stdio.h>
#include <stdlib.h>

void lower_to_upper(char str[100], char str_upper[100]);
void encrypts_and_decrypts(char str[100], int shift_num);

#endif
