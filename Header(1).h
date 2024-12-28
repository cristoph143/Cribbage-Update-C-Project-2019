#ifndef HEADER_H
#define HEADER_H


//struct nodeGame
//{
//	char choice;
//	struct node *next;
//};


//display
int main();
void mainmenu();
void instructions();
void gotoxy(int x,int y);
void loadingBar();
void backquit();

/**Prototypes**/
void print_card(struct Card card);
void print_deck_52(struct Deck_52 deck);
void print_hand_6(struct Hand_6 hand);
void print_hand_4(struct Hand_4 hand);
void fill_deck_52(struct Deck_52* deck);

//instructions


//Discard Statistics
void maindiscard();
void chooseDiscard(void);
int promptForHand(char hand[]);
int evalFive(int hand[]);
void rankFour(char hand[], int handVal[], double bestHands[15][5], double unseen);

#endif