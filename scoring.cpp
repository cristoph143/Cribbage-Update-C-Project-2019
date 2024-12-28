#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"
#include "deck.h"


//Calculate all possible scores from hand of 6 
void score_6(struct Hand_6 hand){
	struct Card tot_score, faces, suits;
	struct Hand_6 cribdeck, feel[10];
	//struct Hand_6 faces, suits;
	char face;
	int suit;
  //Now split into all possible hands of 4, there should be 15 of them
  //I have not indexed from 0 here! Needs changing (and in hand_copy_4_6)
  int combinations[15][4] = 
  { {1,2,3,4}, {1,2,3,5}, {1,2,3,6},	
	{1,2,4,5}, {1,2,4,6}, {1,2,5,6},	
	{1,3,4,5}, {1,3,4,6}, {1,3,5,6},	
	{1,4,5,6}, {2,3,4,5}, {2,3,4,6},	
	{2,3,5,6}, {2,4,5,6}, {3,4,5,6} 
  };
  int index_array[4] = {0,0,0,0};
  struct Hand_4 sub_hand;
  int points_hand = 0;

  (SHOW_CARDS) ? (print_hand_6(hand)) : 0;
  printf("\n");
  //printf("Enter 2 Card to the Crib\nEx 5H: ");
  //scanf("%d%s", &suit,&face);

  //if(feel[faces.suit == suit || faces.ID == face){
	 // putcrib_deck(hand);
  //}
  for(int hand_index = 0; hand_index < 15; hand_index++){
    for(int i = 0; i < 4; i++){
      index_array[i] = combinations[hand_index][i];
    }
    hand_copy_4_6(hand, &sub_hand, index_array);
    (SHOW_CARDS) ? (print_hand_4(sub_hand)) : 0;
    points_hand = find_15_4(sub_hand);
    points_hand += find_multi_4(sub_hand);
    points_hand += find_run_4(sub_hand);
    points_hand += find_flush_4(sub_hand);
	//totalpoints(tot_score);
    if(SHOW_SCORE){
      printf("->%d Points\n\n", points_hand);
    } else {
      printf("%d\n", points_hand);
    }
  }
}
//void totalpoints(struct Card *tot_points)
//{
//	struct Card *totalpointss = NULL;
//	int add = 0;
//	totalpointss->score = tot_points;
//}



void hand_copy_4_6(struct Hand_6 src_hand, struct Hand_4* dst_hand, int index_map[4]){
  for(int i = 0; i < 4; i++){
    dst_hand->contents[i] = src_hand.contents[index_map[i] - 1];
  }
}

//Now I need to write the score_4 function, this may call a score 3 and score 2 function
//or something like that, to check for doubles, triples ECT....
//This needs to be planned out well on paper
//Flowchart with all scoring routes

int find_15_4(struct Hand_4 hand){
  //This checks all the subsets of minimum size 2
  int combinations_2[6][2] = { {1,2}, {1,3}, {1,4},	
			       {2,3}, {2,4}, {3,4} };

  int combinations_3[4][3] = { {1,2,3}, {1,2,4},	
			       {1,3,4}, {2,3,4} };

  int combinations_4[4] = {1,2,3,4};

  int temp_sum = 0;
  int total_points = 0;
  for(int i = 0; i < 4; i++){
    temp_sum += hand.contents[combinations_4[i] - 1].val;
  }

  if(temp_sum == 15){
    (SHOW_SCORE) ? (printf("All cards sum to 15\n")) : 0;
    return 2;
  } else {
    temp_sum = 0;
  }

  for(int j = 0; j < 4; j++){
    for(int i = 0; i < 3; i++){
      temp_sum += hand.contents[combinations_3[j][i] - 1].val;
    }
    if(temp_sum == 15){
      total_points += 2;
      (SHOW_SCORE) ? (printf("15 found from: ")) : 0;
      for(int i = 0; i < 3; i++){
	(SHOW_SCORE) ? (printf(" %c%c", hand.contents[combinations_3[j][i] - 1].ID, hand.contents[combinations_3[j][i] - 1].suit)) : 0;
      }
      (SHOW_SCORE) ? (printf("\n")) : 0;
    }
    temp_sum = 0;
  }

  for(int j = 0; j < 6; j++){
    for(int i = 0; i < 2; i++){
      temp_sum += hand.contents[combinations_2[j][i] - 1].val;
    }
    if(temp_sum == 15){
      total_points += 2;
      (SHOW_SCORE) ? (printf("15 found from: ")) : 0;
      for(int i = 0; i < 2; i++){
	(SHOW_SCORE) ? (printf(" %c%c", hand.contents[combinations_2[j][i] - 1].ID, hand.contents[combinations_2[j][i] - 1].suit)) : 0;
      }
      (SHOW_SCORE) ? (printf("\n")) : 0;
    }
    temp_sum = 0;
  }

  return total_points;
}

int find_multi_4(struct Hand_4 hand){
  int total_points = 0;
  int combinations_2[6][2] = { {1,2}, {1,3}, {1,4},	
			       {2,3}, {2,4}, {3,4} };

  char ID_1;
  char ID_2;
  
  for(int j = 0; j < 6; j++){
    ID_1 = hand.contents[combinations_2[j][0] - 1].ID;
    ID_2 = hand.contents[combinations_2[j][1] - 1].ID;

    if(ID_1 == ID_2){
      total_points += 2;
      (SHOW_SCORE) ? (printf("Pair found from: ")) : 0;
      for(int i = 0; i < 2; i++){
	(SHOW_SCORE) ? (printf(" %c%c", hand.contents[combinations_2[j][i] - 1].ID, hand.contents[combinations_2[j][i] - 1].suit)) : 0;
      }
      (SHOW_SCORE) ? (printf("\n")) : 0;
    }
  }
  return total_points;
}

int find_run_4(struct Hand_4 hand){
  int value_array[4];
  int index_array[4];
  int value_array_3[3];
  int index_array_3[3];
  int total_points = 0;
  for(int i = 0; i < 4; i++){
    value_array[i] = ID_to_index(hand.contents[i].ID);
    index_array[i] = i;
  }

  sort_4(value_array, index_array);
  
  if(value_array[1] == (value_array[0] + 1)){
    if(value_array[2] == (value_array[1] + 1)){
      if(value_array[3] == (value_array[2] + 1)){
	(SHOW_SCORE) ? (printf("Run of 4\n")) : 0;
	return 4;
      }
    }
  }

  //Now check all possible runs of 3
  int combinations_3[4][3] = { {1,2,3}, {1,2,4},	
			       {1,3,4}, {2,3,4} };

  for(int j = 0; j < 4; j++){
    for(int i = 0; i < 3; i++){
      value_array_3[i] = ID_to_index(hand.contents[combinations_3[j][i] - 1].ID);
      index_array_3[i] = combinations_3[j][i] - 1;
    }
    sort_3(value_array_3, index_array_3);
    if(value_array_3[1] == (value_array_3[0] + 1)){
      if(value_array_3[2] == (value_array_3[1] + 1)){
	(SHOW_SCORE) ? (printf("Run of 3:")) : 0;
	for(int x = 0; x < 3; x++){
	  (SHOW_SCORE) ? (printf(" %c%c", hand.contents[index_array_3[x]].ID, hand.contents[index_array_3[x]].suit)) : 0;
	}
	(SHOW_SCORE) ? (printf("\n")) : 0;
	total_points += 3;
      }
    }
  }
  
  return total_points;
}

//Sort the array and preserve original indexes
void sort_4(int value_array[4], int index_array[4]){
  int changes = 1;
  int temp = 0;
  while(changes){
    changes = 0;
    if(value_array[0] > value_array[1]){
      changes++;
      temp = value_array[0];
      value_array[0] = value_array[1];
      value_array[1] = temp;

      temp = index_array[0];
      index_array[0] = index_array[1];
      index_array[1] = temp;
    }
    if(value_array[1] > value_array[2]){
      changes++;
      temp = value_array[1];
      value_array[1] = value_array[2];
      value_array[2] = temp;

      temp = index_array[1];
      index_array[1] = index_array[2];
      index_array[2] = temp;
    }
    if(value_array[2] > value_array[3]){
      changes++;
      temp = value_array[2];
      value_array[2] = value_array[3];
      value_array[3] = temp;

      temp = index_array[2];
      index_array[2] = index_array[3];
      index_array[3] = temp;
    }
  }
}

void sort_3(int value_array[3], int index_array[3]){
  int changes = 1;
  int temp = 0;
  while(changes){
    changes = 0;
    if(value_array[0] > value_array[1]){
      changes++;
      temp = value_array[0];
      value_array[0] = value_array[1];
      value_array[1] = temp;

      temp = index_array[0];
      index_array[0] = index_array[1];
      index_array[1] = temp;
    }
    if(value_array[1] > value_array[2]){
      changes++;
      temp = value_array[1];
      value_array[1] = value_array[2];
      value_array[2] = temp;

      temp = index_array[1];
      index_array[1] = index_array[2];
      index_array[2] = temp;
    }
  }
}

int find_flush_4(struct Hand_4 hand){
  char base_suit = hand.contents[0].suit;
  if(base_suit == hand.contents[1].suit){
    if(hand.contents[1].suit == hand.contents[2].suit){
      if(hand.contents[2].suit == hand.contents[3].suit){
	if(SHOW_SCORE){
	  printf("Flush of ");
	  (base_suit == 'H') ? (printf("Hearts\n")) : 0;
	  (base_suit == 'C') ? (printf("Clubs\n")) : 0;
	  (base_suit == 'D') ? (printf("Diamonds\n")) : 0;
	  (base_suit == 'S') ? (printf("Spades\n")) : 0;
	}
	return 4;
      }
    }
  }
  return 0;
}