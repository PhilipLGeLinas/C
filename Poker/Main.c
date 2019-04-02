#include "Poker.h"

int main()
{
	// Initialize suit array
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	// Initialize face array
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	// Initialize combinations array
	const char *combinations[6] = { "pair", "two pair", "three of a kind", "four of a kind", "flush", "straight" };

	// Initialize score array
	int score[2] = { 0 };
	char winner[69] = "You ";

	// Run ten rounds
	for (int i = 0; i < 10; i++)
	{
		// Initalize deck array
		int deck[4][13] = { 0 }, result[2] = { 0, 0 }, exchange = 0;
		Card hand_1[5], hand_2[5];
		char choice;
		srand((unsigned)time(NULL)); // Seed random-number generator

		printf("ROUND %d\n\n", i+1);
		shuffle(deck);
		deal(deck, face, suit, hand_1, hand_2);
		printf("Your hand: ");
		print_hand(hand_1, face, suit);

		printf("Would you like to exchange any cards? (Y/N): ");
		scanf(" %c", &choice);
		
		if (choice == 'Y' || choice == 'y')
		{
			printf("\nEnter the numerical values (1-5) of up to 3 cards you want to exchange, with no spaces between numbers: ");
			scanf("%d", &exchange);
			exchange_cards(deck, face, suit, hand_1, exchange, 1);
			printf("\nYour hand: ");
			print_hand(hand_1, face, suit);
		}
		else
		{
			printf("\n");
		}
		exchange = determine_exchange_cards(hand_2);
		exchange_cards(deck, face, suit, hand_2, exchange, 2);
		evaluate_hands(hand_1, hand_2, result);

		switch (result[0])
		{
		case 0:
			printf("It's a tie!\n\n");
			break;
		case 1:
			printf("You win with a %s!\n\n", combinations[result[1]]);
			score[0]++;
			break;
		case 2:
			printf("Your opponent wins with a %s!\n\n", combinations[result[1]]);
			score[1]++;
			break;
		}
		system("pause");
		system("cls");
	}
	if (score[0] > score[1])
	{
		strcat(winner, "win!");
	}
	else if (score[0] == score[1])
	{
		strcat(winner, "tied!");
	}
	else 
	{
		strcat(winner, "lose!");
	}
	printf("%s The final score was %d to %d. Thanks for playing!\n\n", winner, score[0], score[1]);

	return 0;
}