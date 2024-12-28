#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
#include "deck.h"


void maingame()
{
	char choice;
  srand(time(NULL)); //Initiate random number generator
  int shuffle_map[52];
  struct Deck_52 plain_deck;
  struct Deck_52 shuffled_deck;
  fill_deck_52(&plain_deck);
  fill_shuffle_map(shuffle_map);
  deck_copy(&shuffled_deck, &plain_deck, shuffle_map);
  /*print_deck_52(shuffled_deck);*/
  
  struct Deck_46 final_deck[52];
  struct Hand_6 hand_6;

  //Deal the hand of 6
  deal_hand_6(shuffled_deck, final_deck, &hand_6);
  score_6(hand_6);
  backquit();
  Sleep(100);
	fflush(stdin);
	choice = toupper(_getch());
  if(choice == 'B')
  {
	  system("cls");
	  main();
  }
  else if(choice == 'T')
  {
	  system("cls");
	  maingame();
  }
  else if(choice == 'Q')
  {
	  exit(0);
  }
  else
	{
		gotoxy(75,30);
		system("color 74");
		printf("Invalid Input");
		Sleep(1000);
		system("color 71");
		system("cls");
		}
  getch();
}
