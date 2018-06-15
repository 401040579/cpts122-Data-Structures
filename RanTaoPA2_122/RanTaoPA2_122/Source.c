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

#include "Header.h"
/*************************************************************
* Function: Record * makeNode(char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating) 
* Date Created:1/27/2016		                             
* Date Last Modified:  2/3/2016                            
* Description:make a dynamic Node
* Returns:	address		                     
*************************************************************/
Record * makeNode(char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
{
	Record *pMem = NULL;

	pMem = (Record *)malloc(sizeof(Record));

	pMem->pNext = NULL;
	pMem->pBefore = NULL;

	strcpy(pMem->artist, artist);
	strcpy(pMem->album_Title, album_Title);
	strcpy(pMem->song_Title, song_Title);
	strcpy(pMem->genre, genre);
	pMem->duration.minute = minute;
	pMem->duration.second = second;
	pMem->num_Times_Played = num_Times_Played;
	pMem->rating = rating;
	
	return pMem;
}
/*************************************************************
* Function: void loadFile(FILE *infile, Record *pHead)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description:read file
* Returns: NONE
*************************************************************/
void loadFile(FILE *infile, Record *pHead)
{
	char artist[100], album_Title[100], song_Title[100], genre[100];
	char space[1];
	int minute, second, num_Times_Played, rating;
	
	while (!feof(infile)){
		fgets(artist, 100, infile);
		artist[strlen(artist) - 1] = 0;
		fgets(album_Title, 100, infile);
		album_Title[strlen(album_Title) - 1] = 0;
		fgets(song_Title, 100, infile);
		song_Title[strlen(song_Title) - 1] = 0;
		fgets(genre, 100, infile);
		genre[strlen(genre) - 1] = 0;
		fscanf(infile, "%d", &minute);
		fscanf(infile, "%d", &second);
		fscanf(infile, "%d", &num_Times_Played); 
		fscanf(infile, "%d", &rating); fscanf(infile, "%c", &space[0]);
		fscanf(infile, "%c", &space[0]);
		insertInArtist(&(*pHead), &artist, &album_Title, &song_Title, &genre, minute, second, num_Times_Played, rating);
	}
}
/*************************************************************
* Function: void loadFile(FILE *infile, Record *pHead)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description:write to a file
* Returns: NONE
*************************************************************/
void writeFile(FILE *outfile, Record **pHead)
{
	Record *pCur = *pHead;

	while (pCur != NULL)
	{
		fprintf(outfile, "%s\n", pCur->artist);
		fprintf(outfile, "%s\n", pCur->album_Title);
		fprintf(outfile, "%s\n", pCur->song_Title);
		fprintf(outfile, "%s\n", pCur->genre);
		fprintf(outfile, "%d\n", pCur->duration.minute); 
		fprintf(outfile, "%d\n", pCur->duration.second); 
		fprintf(outfile, "%d\n", pCur->num_Times_Played); 
		fprintf(outfile, "%d\n\n", pCur->rating);
		pCur = pCur->pNext;
	}
}
/*************************************************************
* Function: void printList(Record *pHead)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: print lists.
* Returns: NONE
*************************************************************/
void printList(Record *pHead)
{
	while (pHead != NULL)
	{
		printf("       |\n");
		printf("       V\n");
		printf("Artist: %s\n", pHead->artist);
		printf("Album Title: %s\n", pHead->album_Title);
		printf("Song Title: %s\n", pHead->song_Title);
		printf("Genre: %s\n", pHead->genre);
		printf("Minute: %d Second: %d\n", pHead->duration.minute, pHead->duration.second);
		printf("Num Times Played: %d\n", pHead->num_Times_Played);
		printf("Rating: %d\n", pHead->rating);
		pHead = pHead->pNext;
	}
}
/*************************************************************
* Function: insertInArtist(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※insert§ option collects information for 
each new song record and attributes from the user. The new song 
record must be placed into the list based on a selected sort option. 
By default, songs are inserted into the list alphabetically (＆a＊ 每 ＆z＊)
according to artist.
* Returns: NONE
*************************************************************/
int insertInArtist(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
{
	Record *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	int success = 0;

	pMem = makeNode(artist, album_Title, song_Title, genre, minute, second, num_Times_Played, rating);

	if (pMem != NULL)
	{
		// we allocated space for a node
		success = 1;

		pCur = *pHead; // set pCur to the front of the list

		while ((pCur != NULL) && (strcmp(pMem->artist, pCur->artist) > 0))
		{
			// walk through list to find correct place to insert
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		// found the position to insert the node
		if (pPrev != NULL)// && pCur != NULL)
		{
			// we're not at the front of the list
			pMem->pNext = pCur;
			pMem->pBefore = pPrev;
			pPrev->pNext = pMem;
		}
		else
		{
			if (pCur != NULL) 
			{
				pMem->pNext = pCur;
				pCur->pBefore = pMem;
				*pHead = pMem;
			}
			else 
			{
				pMem->pNext = pCur;
				*pHead = pMem;
			}
		}
	}

	return success; // return 1 if allocated space for a node; 0 otherwise
}
/*************************************************************
* Function: insertInGenre(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※insert§ option collects information for
each new song record and attributes from the user. The new song
record must be placed into the list based on a selected sort option.
By default, songs are inserted into the list alphabetically (＆a＊ 每 ＆z＊)
according to artist.
* Returns: NONE
*************************************************************/
int insertInGenre(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
{
	Record *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	int success = 0;

	pMem = makeNode(artist, album_Title, song_Title, genre, minute, second, num_Times_Played, rating);

	if (pMem != NULL)
	{
		// we allocated space for a node
		success = 1;

		pCur = *pHead; // set pCur to the front of the list

		while ((pCur != NULL) && (strcmp(pMem->genre, pCur->genre) > 0))
		{
			// walk through list to find correct place to insert
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		// found the position to insert the node
		if (pPrev != NULL)// && pCur != NULL)
		{
			// we're not at the front of the list
			pMem->pNext = pCur;
			pMem->pBefore = pPrev;
			pPrev->pNext = pMem;
		}
		else
		{
			if (pCur != NULL)
			{
				pMem->pNext = pCur;
				pCur->pBefore = pMem;
				*pHead = pMem;
			}
			else
			{
				pMem->pNext = pCur;
				*pHead = pMem;
			}
		}
	}

	return success; // return 1 if allocated space for a node; 0 otherwise
}
/*************************************************************
* Function: insertInRating(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※insert§ option collects information for
each new song record and attributes from the user. The new song
record must be placed into the list based on a selected sort option.
By default, songs are inserted into the list alphabetically (＆a＊ 每 ＆z＊)
according to artist.
* Returns: NONE
*************************************************************/
int insertInRating(Record **pHead, char *artist, char *album_Title, char *song_Title, char *genre, int *minute, int *second, int *num_Times_Played, int *rating)
{
	Record *pMem = NULL, *pCur = NULL, *pPrev = NULL;
	int success = 0;

	pMem = makeNode(artist, album_Title, song_Title, genre, minute, second, num_Times_Played, rating);

	if (pMem != NULL)
	{
		// we allocated space for a node
		success = 1;

		pCur = *pHead; // set pCur to the front of the list

		while ((pCur != NULL) && (pMem->rating < pCur->rating))
		{
			// walk through list to find correct place to insert
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		// found the position to insert the node
		if (pPrev != NULL)// && pCur != NULL)
		{
			// we're not at the front of the list
			pMem->pNext = pCur;
			pMem->pBefore = pPrev;
			pPrev->pNext = pMem;
		}
		else
		{
			if (pCur != NULL)
			{
				pMem->pNext = pCur;
				pCur->pBefore = pMem;
				*pHead = pMem;
			}
			else
			{
				pMem->pNext = pCur;
				*pHead = pMem;
			}
		}
	}

	return success; // return 1 if allocated space for a node; 0 otherwise
}
/*************************************************************
* Function: void sortArtist(Record **pHead)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: ※sort§ options include alphabetical ordering based on genre, or increasing numeric value based on rating.
for next three all most same staff
* Returns: NONE
*************************************************************/
void sortArtist(Record **pHead)
{
	int n = 0;
	Record *pCur = *pHead, *ptr = NULL, *tmp = NULL;
	//only one item. dont need to sort
	if (pCur == NULL) return;
	if (pCur->pNext == NULL)
		return;

	pCur = pCur->pNext; //set pCur to next
	while (pCur != NULL)
	{
		ptr = pCur;
		tmp = pCur->pBefore;
		pCur = pCur->pNext;
		//use srtrcmp for string. pCur->pBefore should not be NULL
		while (tmp != NULL && strcmp(tmp->artist, ptr->artist) > 0)
		{
			n++;
			tmp = tmp->pBefore;
		}
		if (n)
		{
			//set prev to pCur->pNext
			ptr->pBefore->pNext = ptr->pNext;
			if (ptr->pNext != NULL)//if no more node on right
				ptr->pNext->pBefore = ptr->pBefore;

			if (tmp == NULL)//when tmp is null
			{//change they are pointers
				tmp = *pHead;
				ptr->pBefore = NULL;
				ptr->pNext = tmp;
				ptr->pNext->pBefore = ptr;
				*pHead = ptr;
			}
			else
			{
				tmp = tmp->pNext;
				tmp->pBefore->pNext = ptr;
				ptr->pBefore = tmp->pBefore;
				tmp->pBefore = ptr;
				ptr->pNext = tmp;
			}
		}
	}
}
/*************************************************************
* Function: void sortGenre(Record **pHead)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: ※sort§ options include alphabetical ordering based on genre, or increasing numeric value based on rating.
* Returns: NONE
*************************************************************/
void sortGenre(Record **pHead)
{
	int n = 0;
	Record *pCur = *pHead, *ptr = NULL, *tmp = NULL;
	//only one item. dont need to sort
	if (pCur == NULL) return;
	if (pCur->pNext == NULL)
		return;

	pCur = pCur->pNext;
	while (pCur != NULL)
	{
		ptr = pCur;
		tmp = pCur->pBefore;
		pCur = pCur->pNext;
		while (tmp != NULL && strcmp(tmp->genre, ptr->genre) > 0)
		{
			n++;
			tmp = tmp->pBefore;
		}
		if (n)
		{
			ptr->pBefore->pNext = ptr->pNext;
			if (ptr->pNext != NULL)
				ptr->pNext->pBefore = ptr->pBefore;

			if (tmp == NULL)
			{
				tmp = *pHead;
				ptr->pBefore = NULL;
				ptr->pNext = tmp;
				ptr->pNext->pBefore = ptr;
				*pHead = ptr;
			}
			else
			{
				tmp = tmp->pNext;
				tmp->pBefore->pNext = ptr;
				ptr->pBefore = tmp->pBefore;
				tmp->pBefore = ptr;
				ptr->pNext = tmp;
			}
		}
	}
}
/*************************************************************
* Function: void sortRating(Record **pHead)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: ※sort§ options include alphabetical ordering based on genre, or increasing numeric value based on rating.
* Returns: NONE
*************************************************************/
void sortRating(Record **pHead)
{
	int n = 0;
	Record *pCur = *pHead, *ptr = NULL, *tmp = NULL;
	//only one item. dont need to sort
	if (pCur == NULL) return;
	if (pCur->pNext == NULL)
		return;

	pCur = pCur->pNext;
	while (pCur != NULL)
	{
		ptr = pCur;
		tmp = pCur->pBefore;
		pCur = pCur->pNext;
		while (tmp != NULL && tmp->rating < ptr->rating)
		{
			n++;
			tmp = tmp->pBefore;
		}
		if (n)
		{
			ptr->pBefore->pNext = ptr->pNext;
			if (ptr->pNext != NULL)
				ptr->pNext->pBefore = ptr->pBefore;

			if (tmp == NULL)
			{
				tmp = *pHead;
				ptr->pBefore = NULL;
				ptr->pNext = tmp;
				ptr->pNext->pBefore = ptr;
				*pHead = ptr;
			}
			else
			{
				tmp = tmp->pNext;
				tmp->pBefore->pNext = ptr;
				ptr->pBefore = tmp->pBefore;
				tmp->pBefore = ptr;
				ptr->pNext = tmp;
			}
		}
	}
}
/*************************************************************
* Function: int deleteNode(Record **pHead, char *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: ※Delete§ removes a record from the list.
Deletion is based on song title.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int deleteNode(Record **pHead, char *searchData)
{
	Record *pPrev = NULL, *pCur = *pHead;// , *pNext = pCur->pNext;
	int success = 1;

	while ((pCur != NULL) && (strcmp(pCur->song_Title, searchData) != 0))
	{
		pPrev = pCur;
		pCur = pCur->pNext;
		//pNext = pNext->pNext;
	}

	// Check to see if deleting the first node
	if (pPrev == NULL)
	{
		// deleting first node
		*pHead = (*pHead)->pNext;
		free(pCur);
	}
	else
	{
		if (pCur->pNext != NULL)
		{
			// found node to delete
			// reconnect list to ensure no memory leaks
			pPrev->pNext = pCur->pNext;
			pCur->pNext->pBefore = pCur->pBefore;
			free(pCur);
		}
		else if (pCur != NULL) {
			pPrev->pNext = pCur->pNext;
			free(pCur);
		}
		else
		{
			printf("no node to delete");
			success = 0;
		}
	}

	return success;
}
//
//int sortArtist2(Record **pHead)
//{
//	Record *pCur = *pHead, *pPrev = NULL;
//	int success = 0;
//	if (pCur->pNext != NULL) 
//	{
//		while (pCur != NULL && strcmp(pCur->artist, pCur->pNext->artist) > 0)
//		{
//			pPrev = pCur;
//			pCur = pCur->pNext;
//		}
//
//		if (pPrev->pBefore == NULL)
//		{
//			(*pHead)->pNext = pCur;
//			pPrev->pNext = pCur->pNext;
//			pCur->pNext = pPrev;
//
//			pCur->pBefore = pPrev->pBefore;
//			pPrev->pBefore = pCur;
//		}
//		else
//		{
//			if (pCur->pNext == NULL)
//			{
//
//			}
//		}
//	}
//	else
//	{
//		return success;
//	}
//
//
//
//
//		
//		if(pPrev->pBefore == NULL && pCur->pNext == NULL)// && pPrev != NULL && pCur != NULL && pCur->pNext != NULL)
//		{
//			(*pHead)->pNext = pCur;
//			pPrev->pNext = pCur->pNext;
//			pCur->pNext = pPrev;
//
//			pCur->pBefore = pPrev->pBefore;
//			pPrev->pBefore = pCur;
//		}
//		else if (pPrev->pBefore == NULL && pCur->pNext != NULL)
//		{
//			(*pHead)->pNext = pCur;
//			pPrev->pNext = pCur->pNext;
//			pCur->pNext = pPrev;
//
//			pCur->pNext->pBefore = pPrev;
//			pCur->pBefore = pPrev->pBefore;
//			pPrev->pBefore = pCur;
//		}
//		else
//		{
//			pPrev->pBefore->pNext = pCur;
//			pPrev->pNext = pCur->pNext;
//			pCur->pNext = pPrev;
//
//			pCur->pNext->pBefore = pPrev;
//			pCur->pBefore = pPrev->pBefore;
//			pPrev->pBefore = pCur;
//		}
//	
//	return success;
//}
//int sortArtist(Record **pHead)
//{
//	Record *pCur = *pHead, *pPrev = NULL;
//	char temp_artist[100], temp_album_Title[100], temp_song_Title[100], temp_genre[100];
//	int temp_minute, temp_second, temp_num_Times_Played, temp_rating;
//	int success = 0;
//
//	pPrev = pCur;
//	pCur = pCur->pNext;
//
//	if (pPrev != NULL) {
//		for (; pPrev != NULL; pPrev = pPrev->pNext) {
//			for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext)
//				if (strcmp(pPrev->artist, pCur->artist) > 0) {
//					temp_artist[100], temp_album_Title[100], temp_song_Title[100], temp_genre[100];
//					temp_minute, temp_second, temp_num_Times_Played, temp_rating;
//					strcpy(temp_artist, pPrev->artist);
//					strcpy(temp_album_Title, pPrev->album_Title);
//					strcpy(temp_song_Title, pPrev->song_Title);
//					strcpy(temp_genre, pPrev->genre);
//					temp_minute = pPrev->duration.minute;
//					temp_second = pPrev->duration.second;
//					temp_num_Times_Played = pPrev->num_Times_Played;
//					temp_rating = pPrev->rating;
//
//					strcpy(pPrev->artist, pCur->artist);
//					strcpy(pPrev->album_Title, pCur->album_Title);
//					strcpy(pPrev->song_Title, pCur->song_Title);
//					strcpy(pPrev->genre, pCur->genre);
//					pPrev->duration.minute = pCur->duration.minute;
//					pPrev->duration.second = pCur->duration.second;
//					pPrev->num_Times_Played = pCur->num_Times_Played;
//					pPrev->rating = pCur->rating;
//
//					strcpy(pCur->artist, temp_artist);
//					strcpy(pCur->album_Title, temp_album_Title);
//					strcpy(pCur->song_Title, temp_song_Title);
//					strcpy(pCur->genre, temp_genre);
//					pCur->duration.minute = temp_minute;
//					pCur->duration.second = temp_second;
//					pCur->num_Times_Played = temp_num_Times_Played;
//					pCur->rating = temp_rating;
//				}
//		}
//		success = 1;
//	}
//	return success;
//}
//
//int sortGenre(Record **pHead)
//{
//	Record *pCur = *pHead, *pPrev = NULL;
//	char temp_artist[100], temp_album_Title[100], temp_song_Title[100], temp_genre[100];
//	int temp_minute, temp_second, temp_num_Times_Played, temp_rating;
//	int success = 0;
//
//	pPrev = pCur;
//	pCur = pCur->pNext;
//
//	if (pPrev != NULL) {
//		for (; pPrev != NULL; pPrev = pPrev->pNext) {
//			for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext)
//				if (strcmp(pPrev->genre, pCur->genre)>0) {
//					temp_artist[100], temp_album_Title[100], temp_song_Title[100], temp_genre[100];
//					temp_minute, temp_second, temp_num_Times_Played, temp_rating;
//					strcpy(temp_artist, pPrev->artist);
//					strcpy(temp_album_Title, pPrev->album_Title);
//					strcpy(temp_song_Title, pPrev->song_Title);
//					strcpy(temp_genre, pPrev->genre);
//					temp_minute = pPrev->duration.minute;
//					temp_second = pPrev->duration.second;
//					temp_num_Times_Played = pPrev->num_Times_Played;
//					temp_rating = pPrev->rating;
//
//					strcpy(pPrev->artist, pCur->artist);
//					strcpy(pPrev->album_Title, pCur->album_Title);
//					strcpy(pPrev->song_Title, pCur->song_Title);
//					strcpy(pPrev->genre, pCur->genre);
//					pPrev->duration.minute = pCur->duration.minute;
//					pPrev->duration.second = pCur->duration.second;
//					pPrev->num_Times_Played = pCur->num_Times_Played;
//					pPrev->rating = pCur->rating;
//
//					strcpy(pCur->artist, temp_artist);
//					strcpy(pCur->album_Title, temp_album_Title);
//					strcpy(pCur->song_Title, temp_song_Title);
//					strcpy(pCur->genre, temp_genre);
//					pCur->duration.minute = temp_minute;
//					pCur->duration.second = temp_second;
//					pCur->num_Times_Played = temp_num_Times_Played;
//					pCur->rating = temp_rating;
//				}
//		}
//		success = 1;
//	}
//
//	return success;
//}
//
//int sortRating(Record **pHead)
//{
//	Record *pCur = *pHead, *pPrev = NULL;
//	char temp_artist[100], temp_album_Title[100], temp_song_Title[100], temp_genre[100];
//	int temp_minute, temp_second, temp_num_Times_Played, temp_rating;
//	int success = 0;
//
//	pPrev = pCur;
//	pCur = pCur->pNext;
//
//	if (pPrev != NULL) {
//		for (; pPrev != NULL; pPrev = pPrev->pNext) {
//			for (pCur = pPrev->pNext; pCur != NULL;pCur = pCur->pNext )
//				if (pPrev->rating < pCur->rating) {
//					temp_artist[100], temp_album_Title[100], temp_song_Title[100], temp_genre[100];
//					temp_minute, temp_second, temp_num_Times_Played, temp_rating;
//					strcpy(temp_artist, pPrev->artist);
//					strcpy(temp_album_Title, pPrev->album_Title);
//					strcpy(temp_song_Title, pPrev->song_Title);
//					strcpy(temp_genre, pPrev->genre);
//					temp_minute = pPrev->duration.minute;
//					temp_second = pPrev->duration.second;
//					temp_num_Times_Played = pPrev->num_Times_Played;
//					temp_rating = pPrev->rating;
//
//					strcpy(pPrev->artist, pCur->artist);
//					strcpy(pPrev->album_Title, pCur->album_Title);
//					strcpy(pPrev->song_Title, pCur->song_Title);
//					strcpy(pPrev->genre, pCur->genre);
//					pPrev->duration.minute = pCur->duration.minute;
//					pPrev->duration.second = pCur->duration.second;
//					pPrev->num_Times_Played = pCur->num_Times_Played;
//					pPrev->rating = pCur->rating;
//
//					strcpy(pCur->artist, temp_artist);
//					strcpy(pCur->album_Title, temp_album_Title);
//					strcpy(pCur->song_Title, temp_song_Title);
//					strcpy(pCur->genre, temp_genre);
//					pCur->duration.minute = temp_minute;
//					pCur->duration.second = temp_second;
//					pCur->num_Times_Played = temp_num_Times_Played;
//					pCur->rating = temp_rating;
//				}
//		}
//		success = 1;
//	}
//
//	return success;
//}
/*************************************************************
* Function: int editArtist(Record **pHead, char *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find 
a record in the list with any search field. The user may 
modify any of the attributes in the record. 
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editArtist(Record **pHead, char *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (strcmp(pCur->artist, searchData) != 0))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

		if (pCur != NULL)
		{
			// found node to edit
			// reconnect list to ensure no memory leaks
			printf("Enter which one you want to edit: \n");
			printf("1. Artist\n");
			printf("2. Album title\n");
			printf("3. Song title\n");
			printf("4. Genre\n");
			printf("5. Minute\n");
			printf("6. Second\n");
			printf("7. Number times played\n");
			printf("8. Rating\n");
			printf("Enter: ");
			scanf("%d", &input); getchar();
			switch (input)
			{
			case 1:
				printf("Artist %s edit to: ", pCur->artist);
				gets(userInput);
				strcpy(pCur->artist, userInput);
				break;
			case 2:
				printf("Album title %s edit to: ", pCur->album_Title);
				gets(userInput);
				strcpy(pCur->album_Title, userInput);
				break;
			case 3:
				printf("Song title %s edit to: ", pCur->song_Title);
				gets(userInput);
				strcpy(pCur->song_Title, userInput);
				break;
			case 4:
				printf("Genre %s edit to: ", pCur->genre);
				gets(userInput);
				strcpy(pCur->genre, userInput);
				break;
			case 5:
				printf("Minute %d edit to: ", pCur->duration.minute);
				scanf("%d", &input); getchar();
				pCur->duration.minute = input;
				break;
			case 6:
				printf("Second %d edit to: ", pCur->duration.second);
				scanf("%d", &input); getchar();
				pCur->duration.second = input;
				break;
			case 7:
				printf("Number times played %d edit to: ", pCur->num_Times_Played);
				scanf("%d", &input); getchar();
				pCur->num_Times_Played = input;
				break;
			case 8:
				do {
					printf("Rating %d edit to: ", pCur->rating);
					scanf("%d", &input); getchar();
					if (input < 1 || input > 5) printf("wrong enter!\n");
				} while (input < 1 || input > 5);
				pCur->rating = input;
				break;
			default:
				break;
			}
		}
		else
		{
			printf("did not find node to edit");
			success = 0;
		}

	return success;

}
/*************************************************************
* Function: int editAlbum_Title(Record **pHead, char *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editAlbum_Title(Record **pHead, char *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (strcmp(pCur->album_Title, searchData) != 0))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %d edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %d edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %d edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %d edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int editSong_Title(Record **pHead, char *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editSong_Title(Record **pHead, char *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (strcmp(pCur->song_Title, searchData) != 0))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %d edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %d edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %d edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %d edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int editGenre(Record **pHead, char *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editGenre(Record **pHead, char *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (strcmp(pCur->genre, searchData) != 0))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %d edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %d edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %d edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %d edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int editMinute(Record **pHead, int *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editMinute(Record **pHead, int *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (pCur->duration.minute != searchData))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %D edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %D edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %D edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %D edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int editSecond(Record **pHead, int *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editSecond(Record **pHead, int *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (pCur->duration.second != searchData))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %d edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %d edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %d edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %d edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int editNum_Times_Played(Record **pHead, int *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editNum_Times_Played(Record **pHead, int *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (pCur->num_Times_Played != searchData))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %d edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %d edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %d edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %d edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int editRating(Record **pHead, int *searchData)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※edit§ option must allow the user to find
a record in the list with any search field. The user may
modify any of the attributes in the record.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int editRating(Record **pHead, int *searchData)
{
	Record *pCur = *pHead;// *pPrev = NULL,
	int success = 1, input = 0;
	char userInput[100];

	while ((pCur != NULL) && (pCur->rating != searchData))
	{
		//pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		// found node to edit
		// reconnect list to ensure no memory leaks
		printf("Enter which one you want to edit: \n");
		printf("1. Artist\n");
		printf("2. Album title\n");
		printf("3. Song title\n");
		printf("4. Genre\n");
		printf("5. Minute\n");
		printf("6. Second\n");
		printf("7. Number times played\n");
		printf("8. Rating\n");
		printf("Enter: ");
		scanf("%d", &input); getchar();
		switch (input)
		{
		case 1:
			printf("Artist %s edit to: ", pCur->artist);
			gets(userInput);
			strcpy(pCur->artist, userInput);
			break;
		case 2:
			printf("Album title %s edit to: ", pCur->album_Title);
			gets(userInput);
			strcpy(pCur->album_Title, userInput);
			break;
		case 3:
			printf("Song title %s edit to: ", pCur->song_Title);
			gets(userInput);
			strcpy(pCur->song_Title, userInput);
			break;
		case 4:
			printf("Genre %s edit to: ", pCur->genre);
			gets(userInput);
			strcpy(pCur->genre, userInput);
			break;
		case 5:
			printf("Minute %d edit to: ", pCur->duration.minute);
			scanf("%d", &input); getchar();
			pCur->duration.minute = input;
			break;
		case 6:
			printf("Second %d edit to: ", pCur->duration.second);
			scanf("%d", &input); getchar();
			pCur->duration.second = input;
			break;
		case 7:
			printf("Number times played %d edit to: ", pCur->num_Times_Played);
			scanf("%d", &input); getchar();
			pCur->num_Times_Played = input;
			break;
		case 8:
			do {
				printf("Rating %d edit to: ", pCur->rating);
				scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			pCur->rating = input;
			break;
		default:
			break;
		}
	}
	else
	{
		printf("did not find node to edit");
		success = 0;
	}

	return success;

}
/*************************************************************
* Function: int ratingSong(Record **pHead, char *searchData, int *userInput)
* Date Created:1/27/2016
* Date Last Modified:  2/3/2016
* Description: The ※rate§ action must allow the user to 
assign a value of 1 每 5 to a song; 1 is the lowest rating and 5 is the highest rating.
* Returns: 1 if edit success, 0 otherwise.
*************************************************************/
int ratingSong(Record **pHead, char *searchData, int *userInput)
{
	Record *pCur = *pHead;// , *pNext = pCur->pNext;
	int success = 1;

	while ((pCur != NULL) && (strcmp(pCur->song_Title, searchData) != 0))
	{
		pCur = pCur->pNext;
		//pNext = pNext->pNext;
	}

	// Check to see if deleting the first node
	if (pCur != NULL) {

			pCur->rating = *userInput;
	}
	else
	{
			// did not find node to rate
			success = 0;
	}
	

	return success;
}
