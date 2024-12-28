#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
#include "deck.h"


int main()
{
	Hand_6 hand;
	char choice, choose, choose1;
	int num = 0;
	//loadingBar();
	mainmenu();
	Sleep(100);
	fflush(stdin);
	choice = toupper(_getch());
	while(1)
	{
	if(choice == 'N')
	{
		system("cls");
		maingame();
	}
	else if(choice == 'H')
	{
		system("cls");
		/*instructions();*/
	}
	else if(choice == 'S')
	{
		system("cls");
		/*score_6(hand);*/
	}
	else if(choice == 'D')
	{
		system("cls");
		maindiscard();
		fflush(stdin);
		choose1 = toupper(_getch());
		if(choose1 == 'B')
		{
			system("cls");
			main();
		}
		else if(choose1 == 'Q'){
			exit(0);
		}
		else
		{
		gotoxy(75,30);
		system("color 04");
		printf("Invalid Input");
		Sleep(1000);
		system("color 01");
		system("cls");
		maindiscard();
		}
	}
	else if(choice == 'Q')
	{
		exit(0);
	}
	else
	{
		gotoxy(75,30);
		system("color 04");
		printf("Invalid Input");
		Sleep(1000);
		system("color 01");
		system("cls");
		main();
	}
	}
	system("cls");
	_getch();
}