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

int main()
{
	char userInput[100], searchData[100], artist[100], album_Title[100], song_Title[100], genre[100];
	int input, int_searchData, minute, second, num_Times_Played, rating;

	Record *pHead = NULL;
	FILE *infile = NULL, *outfile = NULL;
	
	do {
		printf("Welcome to Digital Music Manager\n\n"
			"1. load from a file\n"
			"2. store to a file\n"
			"3. display\n"
			"4. insert\n"
			"5. delete\n"
			"6. edit\n"
			"7. sort\n"
			"8. rate\n"
			"9. exit\n");
		do{
			printf("Enter: ");
			scanf("%d", &input); getchar();
		if (input < 1 || input > 9) printf("wrong enter!\n");
	} while (input < 1 || input > 9);
		switch (input)
		{
		case 1:
			infile = fopen("infile.txt", "r");
			loadFile(infile, &pHead);//By default, songs are inserted into the list alphabetically (＆a＊ 每 ＆z＊) according to artist.
			printf("successful!\n");
			fcloseall();
			break;
		case 2:
			outfile = fopen("oufile.txt", "w");
			writeFile(outfile, &pHead);
			printf("successful!\n");
			fcloseall();
			break;
		case 3:
			printList(pHead);
			break;
		case 4:
			printf("artist: "); gets(artist);
			printf("Album Title: "); gets(album_Title);
			printf("Song Title: "); gets(song_Title);
			printf("Genre: "); gets(genre);
			printf("Minute: "); scanf("%d", &minute); getchar();
			printf("Second: "); scanf("%d", &second); getchar();
			printf("Num_Times_Played: "); scanf("%d", &num_Times_Played); getchar();
			printf("Rating: "); scanf("%d", &rating); getchar();
			printf("insert by\n1. alphabetical artist\n2. alphabetical genre\n3. increasing numeric value based on rating\n");
			do{
			printf("Enter: ");
			scanf("%d", &input); getchar();
			if (input < 1 || input > 3) printf("wrong enter!\n");
		} while (input < 1 || input > 3);
			switch (input)
			{
			case 1:
				//sortArtist(&pHead);
				insertInArtist(&pHead, artist, album_Title, song_Title, genre, minute, second, num_Times_Played, rating);
				break;
			case 2:
				//sortGenre(&pHead);
				insertInGenre(&pHead, artist, album_Title, song_Title, genre, minute, second, num_Times_Played, rating);
				break;
			case 3:
				//sortRating(&pHead);
				insertInRating(&pHead, artist, album_Title, song_Title, genre, minute, second, num_Times_Played, rating);
				break;
			default:
				break;
			}
			break;
		case 5:
			printf("Enter the song title that you want to delete: ");
			gets(searchData);//scanf("%s", &searchData);
			deleteNode(&pHead, searchData);
			break;
		case 6:
			printf("Enter which search field you want: \n");
			printf("1. Artist\n");
			printf("2. Album title\n");
			printf("3. Song title\n");
			printf("4. Genre\n");
			printf("5. Minute\n");
			printf("6. Second\n");
			printf("7. Number times played\n");
			printf("8. Rating\n");
			do{
			printf("Enter: ");
			scanf("%d", &input); getchar();
			if (input < 1 || input > 8) printf("wrong enter!\n");
		} while (input < 1 || input > 8);
			switch (input)
			{
			case 1:
				printf("Enter the Artist that you want to edit: ");
				gets(searchData);
				editArtist(&pHead, searchData);
				break;
			case 2:
				printf("Enter the Album title that you want to edit: ");
				gets(searchData);
				editAlbum_Title(&pHead, searchData);
				break;
			case 3:
				printf("Enter the Song title that you want to edit: ");
				gets(searchData);
				editSong_Title(&pHead, searchData);
				break;
			case 4:
				printf("Enter the Genre that you want to edit: ");
				gets(searchData);
				editGenre(&pHead, searchData);
				break;
			case 5:
				printf("Enter the Minute that you want to edit: ");
				scanf("%d", &int_searchData);
				editMinute(&pHead, int_searchData);
				break;
			case 6:
				printf("Enter the Second that you want to edit: ");
				scanf("%d", &int_searchData);
				editSecond(&pHead, int_searchData);
				break;
			case 7:
				printf("Enter the Number times played that you want to edit: ");
				scanf("%d", &int_searchData);
				editNum_Times_Played(&pHead, int_searchData);
				break;
			case 8:
				printf("Enter the Rating that you want to edit: ");
				scanf("%d", &int_searchData);
				editRating(&pHead, int_searchData);
				break;
			default:
				break;
			}
			break;
		case 7:
			do {
				printf("sort by\n1. alphabetical artist\n2. alphabetical genre\n3. increasing numeric value based on rating\n");
				printf("Enter: ");
				scanf("%d", &input); getchar();
				if (input < 1 || input > 3) printf("wrong enter!\n");
			} while (input < 1 || input > 3);
			switch (input)
			{
			case 1:
				sortArtist(&pHead);
				printf("successful!\n");
				break;
			case 2:
				sortGenre(&pHead);
				printf("successful!\n");
				break;
			case 3:
				sortRating(&pHead);
				printf("successful!\n");
				break;
			default:
				break;
			}
			break;
		case 8:
				printf("Enter the song title that you want to rate: ");
				gets(searchData);//scanf("%s", &searchData);
				do {
				printf("rating to(1-5): "); scanf("%d", &input); getchar();
				if (input < 1 || input > 5) printf("wrong enter!\n");
			} while (input < 1 || input > 5);
			ratingSong(&pHead, searchData, &input);
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (input >= 1 && input <= 8);
	return 0;
}