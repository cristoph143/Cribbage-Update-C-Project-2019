#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
#include "deck.h"


//pick card
//void computer1(struct Deck_52 &shuffled_deck, struct Deck_46 &final_deck)
//{
//
//	struct Hand_6 hand_1;
//	int rands[52];
//	//deal_hand_6(shuffled_deck, &final_deck, &hand_1);//the dealer gives 6 deck in which the cards are being shuffled
//	//printf("%d", final_deck.contents);
//	
//
//	printf("%d", rand()%51);
//}
//void you1(struct Deck_52 &shuffled_deck, struct Deck_46 &final_deck)
//{
//	struct Hand_6 hand_1;
//
//	printf("Ex Enter 1 card: 5\nEnter 1 card: ");
//	scanf("%d", &hand_1);
//	if(hand_1 == final_deck);
//	printf("%d", final_deck);
//
//}



void computer2(struct Deck_52 &shuffled_deck, struct Deck_46 &final_deck){

	struct Hand_6 hand_6;

	 deal_hand_6(shuffled_deck, &final_deck, &hand_6);//the dealer gives 6 deck in which the cards are being shuffled

}
void you2(struct Deck_52 &shuffled_deck, struct Deck_46 &final_deck)
{
	struct Hand_6 hand_6;

	deal_hand_6(shuffled_deck, &final_deck, &hand_6);//the dealer gives 6 deck in which the cards are being shuffled

}
//void you(struct Card hand[6])
//{
//	  int *hand15[6], i = 0 ;
//		int cardNum = 0;
//
//	printf("Enter the numerical value of card %d where Ace = 1, Jack = 11, Queen = 12 and King = 13\n", i + 1);
//	scanf("%d", &cardNum);
//
//	//Check for input validity
//	while (cardNum < 1 || cardNum > 13) {
//		
//		printf("Invalid card number\n");
//		printf("Enter the numerical value of card %d where Ace = 1, Jack = 11, Queen = 12 and King = 13\n", i + 1);
//		scanf("%d", &cardNum);
//
//	}
//
//	hand[i].val = cardNum;
//
//	//Set face value cards to 10 in the hand15 array (used for calculating 15s)
//	if (cardNum > 10) {
//		*hand15[i] = 10;
//	}
//	else {
//		*hand15[i] = cardNum;
//	}
//
//		char cardSuit;
//
//	printf("Enter the first letter of the suit of card %d\n", i + 1);
//	scanf(" %c", &cardSuit);
//	cardSuit = toupper(cardSuit);
//
//	//Check for input validity
//	while (!(cardSuit == 'D' || cardSuit == 'H' || cardSuit == 'S' || cardSuit == 'C')) {
//
//		printf("Invalid card suit\n");
//		printf("Enter the first letter of the suit of card %d\n", i + 1);
//		scanf(" %c", &cardSuit);
//		cardSuit = toupper(cardSuit);
//
//	}
//
//	hand[i].suit = cardSuit;
//}