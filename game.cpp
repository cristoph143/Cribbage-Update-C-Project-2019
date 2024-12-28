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
  fill_deck_52(&plain_deck);//fill the deck with corresponding ascending value from the suit from Heart, Diamond, Card, Spades
  fill_shuffle_map(shuffle_map);//it randomizes the outcome which shuffles the value from plain deck like arr[0] = 1H, arr[2] = 2H, ... , arr[51] = KS
  deck_copy(&shuffled_deck, &plain_deck, shuffle_map);//it copy the cards from the source to the shuffled deck so it means that the values are now randomized 
  /*print_deck_52(shuffled_deck);*/

  struct Card hands_6[6], player1_cards[6], player2_card[6];
  struct Deck_46 final_deck[46];
  struct Hand_6 hand_6, hands_1;
  int hand = 0, i = 0,hand_1 = 0;
  //int totscore = 0;
  //int score = 31;

  //pick card;
	
		hand = rand()%51;
		print_hand_1(i, hand, shuffled_deck);
		printf("Enter Number: ");
		scanf("%d",&hand_1);
		print_hand_1(i, hand_1, shuffled_deck);
		printf("\n");

	//comparing the card
			printf("Enemy Card\n==\n==\n==\n==\n==\n==\n");
			deal_hand_6(shuffled_deck, final_deck, &hand_6);//the dealer gives 6 deck in which the cards are being shuffled
			printf("Your ");
			deal_hand_6_2(shuffled_deck, final_deck, &hand_6);//the dealer gives 6 deck in which the cards are being shuffled
			//print_card(hand_6.contents[hand_6]);
			printf("\n");
		//	struct Deck_40 handful, handful1;
		//if(player1_cards[hand].ID < player2_card[hand_1].val)
		//	askforcrib(handful);
		//else if (player1_cards[hand].ID == player2_card[hand_1].ID)
		//{
		//	if(player1_cards[hand].suit == player2_card[hand_1].suit)
		//	{
		//		system("cls");
		//		hand = rand()%51;
		//		print_hand_1(i, hand, shuffled_deck);
		//		printf("Enter Number: ");
		//		scanf("%d",&hand_1);
		//		print_hand_1(i, hand_1, shuffled_deck);
		//	}
		//	else
		//	{
		//		if((player1_cards[hand].suit == hands_6->suit == 'H') < player2_card[hand_1].suit  == hands_6->suit == 'D')//H<D
		//		{
		//			askforcrib(handful);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'D') > player2_card[hand_1].suit  == hands_6->suit == 'H')//D>H
		//		{
		//			askforcrib1(handful1);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'H') < player2_card[hand_1].suit  == hands_6->suit == 'C')//H<C
		//		{
		//			askforcrib(handful);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'C') > player2_card[hand_1].suit  == hands_6->suit == 'H')//C>H
		//		{
		//			askforcrib1(handful1);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'H') < player2_card[hand_1].suit  == hands_6->suit == 'S')//H<S
		//		{
		//			askforcrib(handful);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'S') > player2_card[hand_1].suit  == hands_6->suit == 'H')//S>H
		//		{
		//			askforcrib1(handful1);
		//		}
		//		if((player1_cards[hand].suit == hands_6->suit == 'D') < player2_card[hand_1].suit  == hands_6->suit == 'C')//D<C
		//		{
		//			askforcrib(handful);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'C') > player2_card[hand_1].suit  == hands_6->suit == 'D')//C>D
		//		{
		//			askforcrib1(handful1);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'D') < player2_card[hand_1].suit  == hands_6->suit == 'S')//D<S
		//		{
		//			askforcrib(handful);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'S') > player2_card[hand_1].suit  == hands_6->suit == 'D')//S>D
		//		{
		//			askforcrib1(handful1);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'C') < player2_card[hand_1].suit  == hands_6->suit == 'S')//C<S
		//		{
		//			askforcrib(handful);
		//		}
		//		else if((player1_cards[hand].suit == hands_6->suit == 'S') < player2_card[hand_1].suit  == hands_6->suit == 'C')//S>C
		//		{
		//			askforcrib1(handful1);
		//		}
		//	}
		//}
		//else
		//	deal_hand_6(shuffled_deck, final_deck, &hand_6);

  //computer1(shuffled_deck, *final_deck);
  //you1(shuffled_deck, *final_deck);

  //Deal the hand of 6(PC)
  //while(totscore != 121 || totscore <= 121)
  //{
	 // while(score <= 31)
	 // {
		//  if(player1_cards->ID < player2_card->ID)
		//  {
		//	  computer2(shuffled_deck, *final_deck);
		//  }
		//  else if(player1_cards->ID == player2_card->ID)
		//  {
		//	  if(player1_cards->suit == player2_card->suit)
		//		  printf("Taken\n");
		//	  //else
		//  }
		//  else
		//  {
		//	   you2(shuffled_deck, *final_deck);
		//  }
	 // }
  //}
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
		system("color 04");
		printf("Invalid Input");
		Sleep(1000);
		system("color 01");
		system("cls");
		maindiscard();
		}
  getch();
}

//void checkOrder(struct Deck_52 hands)
//{
//	int check;
//	switch(hands.contents)
//	{
//
//	}
//}