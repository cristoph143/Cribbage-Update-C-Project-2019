#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
#include "deck.h"

int ID_to_index(char index){
  int val = 0;
  (index == '1') ? (val = 1) : 0;
  (index == '2') ? (val = 2) : 0;
  (index == '3') ? (val = 3) : 0;
  (index == '4') ? (val = 4) : 0;
  (index == '5') ? (val = 5) : 0;
  (index == '6') ? (val = 6) : 0;
  (index == '7') ? (val = 7) : 0;
  (index == '8') ? (val = 8) : 0;
  (index == '9') ? (val = 9) : 0;
  (index == 'T') ? (val = 10) : 0;
  (index == 'J') ? (val = 11) : 0;
  (index == 'Q') ? (val = 12) : 0;
  (index == 'K') ? (val = 13) : 0;
  return val;
}



//Fills up a 52 card deck
void fill_deck_52(struct Deck_52* deck){
  char suit_current = 'H';
  int card_count = 0;
  int card_val = 0;
  char index_to_ID[14] = {'0', '1','2','3','4','5','6','7','8','9','T','J','Q','K'};
  for(int i = 1; i <= 13; i++){
    deck->contents[card_count].suit = suit_current;
    deck->contents[card_count].ID = index_to_ID[i];
    (i > 10) ? (card_val = 10) : (card_val = i);
    deck->contents[card_count].val = card_val;
    card_count++;
  }

  suit_current = 'D';
  for(int i = 1; i <= 13; i++){
    deck->contents[card_count].suit = suit_current;
    deck->contents[card_count].ID = index_to_ID[i];
    (i > 10) ? (card_val = 10) : (card_val = i);
    deck->contents[card_count].val = card_val;
    card_count++;
  }

  suit_current = 'C';
  for(int i = 1; i <= 13; i++){
    deck->contents[card_count].suit = suit_current;
    deck->contents[card_count].ID = index_to_ID[i];
    (i > 10) ? (card_val = 10) : (card_val = i);
    deck->contents[card_count].val = card_val;
    card_count++;
  }

  suit_current = 'S';
  for(int i = 1; i <= 13; i++){
    deck->contents[card_count].suit = suit_current;
    deck->contents[card_count].ID = index_to_ID[i];
    (i > 10) ? (card_val = 10) : (card_val = i);
    deck->contents[card_count].val = card_val;
    card_count++;
  }

}

//Used to produce the shuffle map randomly
void fill_shuffle_map(int shuffle_map[52]){
  int MAX_ROLLS = 10000;
  int swap_s_index = 0;
  int swap_d_index = 0;
  int temp_s = 0;
  int temp_d = 0;

  for(int i = 0; i < 52; i++){
    shuffle_map[i] = i;
  }

  for(int i = 0; i < MAX_ROLLS; i++){
    swap_s_index = rand() % 52;
    swap_d_index = rand() % 52;
    temp_s = shuffle_map[swap_s_index];
    temp_d = shuffle_map[swap_d_index];
    shuffle_map[swap_d_index] = temp_s;
    shuffle_map[swap_s_index] = temp_d;
  }
}


//Used to copy across a deck, and can randomise
void deck_copy(struct Deck_52* dst_deck, struct Deck_52* src_deck, int index_map[52]){
  for(int i = 0; i < 52; i++){
    dst_deck->contents[index_map[i]] = src_deck->contents[i];
  }
}

//Deal a hand of 6 from the a deck
void deal_hand_6(struct Deck_52 deck, struct Deck_46* dst_deck, struct Hand_6* dst_hand){
  for(int i = 0; i < 6; i++){
    dst_hand->contents[i] = deck.contents[i];
  }

  for(int i = 6; i < 52; i++){
    dst_deck->contents[i] = deck.contents[i];
  }
}
void deal_hand_6_2(struct Deck_46 deck, struct Deck_40* dst_deck, struct Hand_6* dst_hand){
 
  for(int i = 0; i < 6; i++){
    dst_hand->contents[i] = deck.contents[i];
  }

  for(int i = 6; i < 46; i++){
    dst_deck->contents[i] = deck.contents[i];
  }
}


//Deal a hand of 6 from the a deck
void deal_hand_6_2(struct Deck_52 deck, struct Deck_46* dst_deck, struct Hand_6* dst_hand){
  for(int i = 0; i < 6; i++){
    dst_hand->contents[i] = deck.contents[i];
  }
  print_card(*dst_hand->contents);
  for(int i = 6; i < 52; i++){
    dst_deck->contents[i] = deck.contents[i];
  }

}