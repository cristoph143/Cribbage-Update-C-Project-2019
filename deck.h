#ifndef DECK_H
#define DECK_H

#define SHOW_CARDS 1
#define SHOW_SCORE 1

struct Card{
  char ID;
  char suit;
  int val;
  int score;
};

struct Deck_52{
  struct Card contents[52];
};

struct Deck_46{
  struct Card contents[46];
};

struct Deck_40{
  struct Card contents[40];
};

struct Deck_39{
  struct Card contents[39];
};

struct Hand_4{
  struct Card contents[4];
};

struct Hand_6{
  struct Card contents[6];
};

//game
void maingame();
void pickcard(struct Deck_52 deck[52]);

//cribbage deck
void deck_copy(struct Deck_52* dst_deck, struct Deck_52* src_deck, int index_map[52]);
void fill_shuffle_map(int shuffle_map[52]);
void deal_hand_6(struct Deck_52 deck, struct Deck_46* dst_deck, struct Hand_6* dst_hand);
void deal_hand_6_2(struct Deck_52 deck, struct Deck_46* dst_deck, struct Hand_6* dst_hand);
void score_6(struct Hand_6 hand);
void hand_copy_4_6(struct Hand_6 src_hand, struct Hand_4* dst_hand, int index_map[4]);
int ID_to_index(char index);
void sort_4(int value_array[4], int index_array[4]);
void sort_3(int value_array[3], int index_array[3]);

//Scoring functions
int find_15_4(struct Hand_4 hand);
int find_multi_4(struct Hand_4 hand);
int find_run_4(struct Hand_4 hand);
int find_flush_4(struct Hand_4 hand);
void totalpoints(struct Card tot_points);

//cribbage deck
void askforcrib(struct Deck_40 handful);
void askforcrib1(struct Deck_40 handful);
void putcrib_deck(struct Deck_40 hand);

#endif