/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 5
*  Date: February 25, 2019
*  Description: This program delegates a 2-player game of Yahtzee, 
				conversing with the users and keeping track of the score.
*/

#include "Yahtzee.h"

int main () 
{
	int choice = 0, player = 1, round = 1, score_1 = 0, score_2 = 0, die_values[5], scorecard_1[13], scorecard_2[13];
	char key = 'a', player_1[69], player_2[69];

	// Continue playing the game until the user exits
	while (1)
	{
		// Clear info from prior game
		system ("cls");

		// Initial prompt
		printf("Welcome to Yahtzee: Console Edition!\n\n");
		prompt_user(player_1, player_2);

		// Game initialization
		initialize_scorecards(scorecard_1, scorecard_2);

		// 13 rounds of gameplay
		while (round < 14)
		{
			system("cls");
			if (player == 1)
			{
				printf("%s, it's your turn!\n", player_1);
			}
			else
			{
				printf("%s, it's your turn!\n", player_2);
			}

			// Initial roll
			printf("\nPress any key to roll your dice.\n\n");
			scanf(" %c", &key);
			roll_dice(die_values);
			system("cls");
			printf("Die 1: %d | Die 2: %d | Die 3: %d | Die 4: %d | Die 5: %d\n\n", die_values[0], die_values[1], die_values[2], die_values[3], die_values[4]);

			// Optional rolls
			for (int i = 0; i < 2; i++)
			{
				printf("Would you like to use this roll for one of your combinations? (Y/N): ");
				scanf(" %c", &key);
				if (key == 'Y' || key == 'y')
				{
					break;
				}
				else
				{
					reroll_dice(die_values);
				}
			}

			printf("\n1.  Sum of 1's\n2.  Sum of 2's\n3.  Sum of 3's\n4.  Sum of 4's\n5.  Sum of 5's\n6.  Sum of 6's\n7.  Three-of-a-kind\n8.  Four-of-a-kind\n9.  Full House\n10. Small straight\n11. Large straight\n12. Yahtzee\n13. Chance\n\n");
			printf("Input the numerical value for the combination that you would like to use: ");
			scanf("%d", &choice);

			// Validate choice, switch players, and update round
			if (player == 1)
			{
				choice = validate_choice(die_values, scorecard_1, choice);
				update_scorecard(scorecard_1, die_values, choice);
				player = 2;
			}
			else
			{
				choice = validate_choice(die_values, scorecard_2, choice);
				update_scorecard(scorecard_2, die_values, choice);
				player = 1;
				round++;
			}
		}

		// Sum the scores
		for (int i = 0; i < 13; i++)
		{
			score_1 += scorecard_1[i];
			score_2 += scorecard_2[i];
		}

		// Add a bonus 35 points if the upper section total is 63 or more
		upper_section(scorecard_1, scorecard_2, &score_1, &score_2);

		// Print the results and display the winner
		print_results(score_1, score_2, player_1, player_2);
	}

    return 0;
}