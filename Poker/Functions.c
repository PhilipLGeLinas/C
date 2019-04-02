#include "Poker.h"

// Shuffle cards in deck
void shuffle(int wDeck[][13])
{
	int row = 0;    // Row number
	int column = 0; // Column number
	int card = 0;   // Card counter

	// For each of the 52 cards, choose slot of deck randomly
	for (card = 1; card <= 52; card++)
	{
		// Choose new random location until unoccupied slot found
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		// Place card number in chosen slot of deck
		wDeck[row][column] = card;
	}
}

// Deal cards in deck
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand_1[5], Card hand_2[5])
{
	int row = 0;    // Row number
	int column = 0; // Column number
	int card = 0;   // Card counter

	// Deal each of the 5 cards
	for (card = 1; card <= 10; card++)
	{
		// Loop through rows of wDeck
		for (row = 0; row <= 3; row++)
		{
			// Loop through columns of wDeck for current row
			for (column = 0; column <= 12; column++)
			{
				// If slot contains current card, display card
				if (wDeck[row][column] == card && card <= 5)
				{
					hand_1[card - 1].face = column;
					hand_1[card - 1].suit = row;
				}
				else if (wDeck[row][column] == card)
				{
					// printf("%s of %-s%s", wFace[column], wSuit[row], card % 5 == 0 ? "\n\n" : " | ");
					hand_2[card - 6].face = column;
					hand_2[card - 6].suit = row;
				}
			}
		}
	}
}

// Determines if the given hand contains a pair
int contains_pair(Card hand[5])
{
	int counts[13] = { 0 };

	for (int i = 0; i < 5; i++)
		counts[hand[i].face]++;

	for (int i = 0; i < 13; i++)
		if (counts[i] > 1)
			return 1;

	return 0;
}

// Determines if the given hand contains two pairs
int contains_two_pairs(Card hand[5])
{
	int counts[13] = { 0 };
	int pairs_count = 0;

	for (int i = 0; i < 5; i++)
		counts[hand[i].face]++;

	for (int i = 0; i < 13; i++)
		if (counts[i] > 1)
			pairs_count++;

	if (pairs_count > 1)
		return 1;

	return 0;
}

// Determines if the given hand contains a three-of-a-kind
int contains_three_of_a_kind(Card hand[5])
{
	int counts[13] = { 0 };

	for (int i = 0; i < 5; i++)
		counts[hand[i].face]++;

	for (int i = 0; i < 13; i++)
		if (counts[i] > 2)
			return 1;

	return 0;
}

// Determines if the given hand contains a four-of-a-kind
int contains_four_of_a_kind(Card hand[5])
{
	int counts[13] = { 0 };

	for (int i = 0; i < 5; i++)
		counts[hand[i].face]++;

	for (int i = 0; i < 13; i++)
		if (counts[i] > 3)
			return 1;

	return 0;
}

// Determines if the given hand contains a flush
int contains_flush(Card hand[5])
{
	int suit = hand[0].suit;
	
	for (int i = 1; i < 5; i++)
		if (hand[i].suit != suit)
			return 0;

	return 1;
}

// Determines if the given hand contains a straight
int contains_straight(Card hand[5])
{
	sort_hand(hand);

	for (int i = 0; i < 4; i++)
		if (hand[i + 1].face - hand[i].face != 1)
			return 0;

	return 1;
}

// Sorts the given hand by suit
void sort_hand(Card hand[5])
{
	int count = 0;
	Card temp;

	do
	{
		count = 0;
		for (int i = 0; i < 4; i++)
		{
			if (hand[i].face > hand[i+1].face)
			{
				temp = hand[i];
				hand[i] = hand[i + 1];
				hand[i + 1] = temp;
				count++;
			}
		}

	} while (count != 0);
}

// Returns 1 if hand_1 is better, 2 if hand_2 is better, and 0 otherwise
void evaluate_hands(Card hand_1[5], Card hand_2[5], int result[2])
{
	int combinations_1[6] = { contains_pair(hand_1), contains_two_pairs(hand_1), contains_three_of_a_kind(hand_1), contains_four_of_a_kind(hand_1), contains_flush(hand_1), contains_straight(hand_1) };
	int combinations_2[6] = { contains_pair(hand_2), contains_two_pairs(hand_2), contains_three_of_a_kind(hand_2), contains_four_of_a_kind(hand_2), contains_flush(hand_2), contains_straight(hand_2) };

	for (int i = 5; i >= 0; i--)
	{
		if (combinations_1[i] != combinations_2[i])
		{
			result[0] = (combinations_1[i] == 1) ? 1 : 2;
			result[1] = i;
		}
	}
}

int determine_exchange_cards(Card hand[5])
{
	int exchange = 0, combo = -1, temp[3] = { 0 }, index = 0, counts[13] = { 0 }, combinations[4] = { contains_pair(hand), contains_two_pairs(hand), contains_three_of_a_kind(hand), contains_four_of_a_kind(hand) };

	for (int i = 0; i < 5; i++)
		counts[hand[i].face]++;

	for (int i = 3; i >= 0; i--)
	{
		if (combinations[i] == 1)
		{
			combo = i;
			break;
		}
	}

	switch (combo)
	{
		case 3:
			for (int i = 0; i < 13; i++)
			{
				if (counts[i] == 1)
				{
					temp[index] = i;
					index++;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (hand[i].face == temp[0])
				{
					exchange *= 10;
					exchange += i;
				}
			}
			break;
		case 2:
			for (int i = 0; i < 13; i++)
			{
				if (counts[i] == 1)
				{
					temp[index] = i;
					index++;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (hand[i].face == temp[0] || hand[i].face == temp[1])
				{
					exchange *= 10;
					exchange += i;
				}
			}
			break;
		case 1:
			for (int i = 0; i < 13; i++)
			{
				if (counts[i] == 1)
				{
					temp[index] = i;
					index++;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (hand[i].face == temp[0])
				{
					exchange *= 10;
					exchange += i;
				}
			}
			break;
		case 0:
			for (int i = 0; i < 13; i++)
			{
				if (counts[i] == 1)
				{
					temp[index] = i;
					index++;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (hand[i].face == temp[0] || hand[i].face == temp[1] || hand[i].face == temp[2])
				{
					exchange *= 10;
					exchange += i;
				}
			}
			break;
		case -1:
			exchange += 123;
			break;
	}
	return exchange;
}

// Exchange cards manually or automatically (computer only)
void exchange_cards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5], int exchange, int player)
{
	int card = (player == 1) ? 11 : 14, exchange_index;
	while (exchange != 0)
	{
		exchange_index = exchange % 10 - 1;
		exchange /= 10;

		// Loop through rows of wDeck
		for (int row = 0; row <= 3; row++)
		{
			// Loop through columns of wDeck for current row
			for (int column = 0; column <= 12; column++)
			{
				// If slot contains current card, display card
				if (wDeck[row][column] == card)
				{
					hand[exchange_index].face = column;
					hand[exchange_index].suit = row;
				}
			}
		}
		card++;
	}
}

// Print the contents of a hand
void print_hand(Card hand[5], const char *wFace[], const char *wSuit[])
{
	for (int i = 1; i <= 5; i++)
		printf("%s of %-s%s", wFace[hand[i-1].face], wSuit[hand[i-1].suit], i % 5 == 0 ? "\n\n" : " | ");
}