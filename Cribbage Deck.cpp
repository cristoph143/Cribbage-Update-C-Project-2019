#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
#include "deck.h"


void askforcrib(struct Deck_40 handful)
{
	int card;
	printf("Enter 2 Cards in the Crib: ");
	scanf("%d", &card);
	putcrib_deck(handful);
}

void askforcrib1(struct Deck_40 handful)
{
	int card;
	printf("Enter 2 Cards in the Crib: ");
	scanf("%d", &card);
	putcrib_deck(handful);
}


void putcrib_deck(struct Deck_40 hand)
{
	int i = 0;
	printf("Card %d %c\n", i+1, hand);
}