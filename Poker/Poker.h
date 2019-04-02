#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct card {
	int face, suit;
} Card;

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand_1[5], Card hand_2[5]);
void sort_hand(Card hand[5]);
int contains_pair(Card hand[5]);
int contains_two_pairs(Card hand[5]);
int contains_three_of_a_kind(Card hand[5]);
int contains_four_of_a_kind(Card hand[5]);
int contains_flush(Card hand[5]);
int contains_straight(Card hand[5]);
void evaluate_hands(Card hand_1[5], Card hand_2[5], int result[2]);
void exchange_cards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5], int exchange, int player);
int determine_exchange_cards(Card hand[5]);
void print_hand(Card hand[5], const char *wFace[], const char *wSuit[]);