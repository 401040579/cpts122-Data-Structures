/*******************************************************************************************
* Programmer: Ran Tao                                                                       
* Class: CptS 122, Spring  2016																
* Programming Assignment: PA 2                                                              
* Date: Feb 3, 2016                                                                         
* Description:	Many of us have large digital music collections that are not always very well organized. It would be nice to have a program that would arrange our music collection based attributes such as artist, album title, song title, genre, song length, number times played, and rating. For this assignment you will write a digital music manager (DMM).
 
Your DMM program must have a text-based interface which allows the user to select from a menu of options including: load, store, display, insert, delete, edit, sort, rate, and exit. The ※load§ option reads records from a file into a dynamic doubly linked list. The ※store§ command writes records, in a dynamic doubly linked list, to a file. ※Display§ prints records, and its attributes to the screen. This command must print either all records or a single record based on a search field. A search field may be any of the attributes belonging to a record. If a search field matches multiple records, then print the first match to the screen. The ※insert§ option collects information for each new song record and attributes from the user. The new song record must be placed into the list based on a selected sort option. By default, songs are inserted into the list alphabetically (＆a＊ 每 ＆z＊) according to artist. Other possible ※sort§ options include alphabetical ordering based on genre, or increasing numeric value based on rating. ※Delete§ removes a record from the list. Deletion is based on song title. The ※edit§ option must allow the user to find a record in the list with any search field. The user may modify any of the attributes in the record. The ※rate§ action must allow the user to assign a value of 1 每 5 to a song; 1 is the lowest rating and 5 is the highest rating. Lastly, ※exit§ saves the most recent list to a file.
 
A record is a struct type which consists of the following attributes:
*       Artist 每 a string
*       Album title 每 a string
*       Song title 每 a string
*       Genre 每 a string
*       Song length 每 a struct type consisting of seconds and minutes, both integers
*       Number times played 每 an integer
*       Rating 每 an integer (1 每 5)														
*******************************************************************************************/
#ifndef RanTaoPA2_122
#define RanTaoPA2_122

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
	char artist[100];
	char album_Title[100];
	char song_Title[100];
	char genre[100];
	struct length
	{
		int minute;
		int second;
	} duration;
	//Length duration;
	int num_Times_Played;
	int rating;
	struct record *pNext;
	struct record *pBefore;
}Record;

//typedef struct length
//{
//	int minute;
//	int second;
//}Length;
//make Node
Record * makeNode(char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating);
//read and write file
void loadFile(FILE *infile, Record *pHead);
void writeFile(FILE *outfile, Record **pHead);
//print lists
void printList(Record *pHead);
//insert
int insertInArtist(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating);
int insertInGenre(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating);
int insertInRating(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating);
//void insertAtFront(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating);

//sort
void sortArtist(Record **pHead);
void sortGenre(Record **pHead);
void sortRating(Record **pHead);
//delete node
int deleteNode(Record **pHead, char *searchData);
//edit
int editArtist(Record **pHead, char *searchData);
int editAlbum_Title(Record **pHead, char *searchData);
int editSong_Title(Record **pHead, char *searchData);
int editGenre(Record **pHead, char *searchData);
int editMinute(Record **pHead, int *searchData);
int editSecond(Record **pHead, int *searchData);
int editNum_Times_Played(Record **pHead, int *searchData);
int editRating(Record **pHead, int *searchData);
//rate
int ratingSong(Record **pHead, char *searchData, int *userInput);
#endif // !RanTaoPA2_122

