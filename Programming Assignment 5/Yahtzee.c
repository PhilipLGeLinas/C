/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 5
*  Date: February 25, 2019
*  Description: This program delegates a 2-player game of Yahtzee,
				conversing with the users and keeping track of the score.
*/

#include "Yahtzee.h"

void prompt_user (char player_1[69], char player_2[69]) {

	int option = 0;

	do 
	{
		printf ("1. Print game rules\n2. Start a game of Yahtzee\n3. Exit\n\n");
		scanf ("%d", &option);

		if (option == 1) 
		{
			system("cls");
			printf ("The Rules of Yahtzee:\n\nThe scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n\n");
		} 
		else if (option != 2) 
		{
			system ("cls");
			printf ("Sorry to see you go!\n\n");
			exit (0);
		}
	} 
	while (option != 2);
	system ("cls");

	// Get to know the players
	printf("Player 1, please enter your name: ");
	scanf("%s", player_1);
	printf("\nPlayer 2, please enter your name: ");
	scanf("%s", player_2);
}

void initialize_scorecards (int scorecard_1[13], int scorecard_2[13]) 
{
	for (int i = 0; i < 13; i++)
	{
		scorecard_1[i] = -1;
		scorecard_2[i] = -1;
	}
}

void roll_dice (int die_values[5])
{
	srand (time (NULL));

	for (int i = 0; i < 5; i++)
	{
		die_values[i] = rand() % 6 + 1;
	}
}

void reroll_dice (int die_values[5])
{
	int reroll_values;
	printf ("\nEnter the numerical values of each die that you would like to reroll (no spaces between): ");
	scanf ("%d", &reroll_values);
	srand( time (NULL));

	while (reroll_values != 0)
	{
		int die_index = reroll_values % 10 - 1;
		if (die_index >= 0 && die_index <= 5)
			die_values[die_index] = rand() % 6 + 1;
		reroll_values /= 10;
	}
	system ("cls");
	printf ("Die 1: %d | Die 2: %d | Die 3: %d | Die 4: %d | Die 5: %d\n\n", die_values[0], die_values[1], die_values[2], die_values[3], die_values[4]);
}

int validate_choice (int die_values[5], int scorecard[13], int choice)
{
	if (choice == 12 && scorecard[11] > 0)
		return choice;
	while (choice < 1 || choice > 13 || scorecard[choice - 1] != -1)
	{
		system ("cls");
		printf ("You have entered a choice that has already been used or that is invalid. Please try again.\n");
		printf ("\nDie 1: %d | Die 2: %d | Die 3: %d | Die 4: %d | Die 5: %d\n", die_values[0], die_values[1], die_values[2], die_values[3], die_values[4]);
		printf ("\n1.  Sum of 1's\n2.  Sum of 2's\n3.  Sum of 3's\n4.  Sum of 4's\n5.  Sum of 5's\n6.  Sum of 6's\n7.  Three-of-a-kind\n8.  Four-of-a-kind\n9.  Full House\n10. Small straight\n11. Large straight\n12. Yahtzee\n13. Chance\n\n");
		printf ("Input the numerical value for the combination that you would like to use: ");
		scanf ("%d", &choice);
	}
	return choice;
}

void update_scorecard (int scorecard[13], int die_values[5], int choice)
{
	int points = 0, sum = 0, doubles = 0, triples = 0, counts[6] = { 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 5; i++)
	{
		sum += die_values[i];
		counts[die_values[i] - 1]++;
	}

	switch (choice)
	{
		case 1:
			for (int i = 0; i < 5; i++)
				if (die_values[i] == 1)
					points++;
			scorecard[0] = points;
			break;
		case 2:
			for (int i = 0; i < 5; i++)
				if (die_values[i] == 2)
					points += 2;
			scorecard[1] = points;
			break;
		case 3:
			for (int i = 0; i < 5; i++)
				if (die_values[i] == 3)
					points += 3;
			scorecard[2] = points;
			break;
		case 4:
			for (int i = 0; i < 5; i++)
				if (die_values[i] == 4)
					points += 4;
			scorecard[3] = points;
			break;
		case 5:
			for (int i = 0; i < 5; i++)
				if (die_values[i] == 5)
					points += 5;
			scorecard[4] = points;
			break;
		case 6:
			for (int i = 0; i < 5; i++)
				if (die_values[i] == 6)
					points += 6;
			scorecard[5] = points;
			break;
		case 7:
			if (counts[0] > 2 || counts[1] > 2 || counts[2] > 2 || counts[3] > 2 || counts[4] > 2 || counts[5] > 2)
				points = sum;
			scorecard[6] = points;
			break;
		case 8:
			if (counts[0] > 3 || counts[1] > 3 || counts[2] > 3 || counts[3] > 3 || counts[4] > 3 || counts[5] > 3)
				points = sum;
			scorecard[7] = points;
			break;
		case 9:
			for (int i = 0; i < 5; i++)
			{
				if (counts[i] == 2)
					doubles++;
				if (counts[i] == 3)
					triples++;
			}
			if (doubles == 1 && triples == 1)
				points = 25;
			scorecard[8] = points;
			break;
		case 10:
			if (counts[0] > 0 && counts[1] > 0 && counts[2] > 0 && counts[3] > 0 || counts[1] > 0 && counts[2] > 0 && counts[3] > 0 && counts[4] > 0 || counts[2] > 0 && counts[3] > 0 && counts[4] > 0 && counts[5] > 0)
				points = 30;
			scorecard[9] = points;
			break;
		case 11:
			if (counts[0] > 0 && counts[1] > 0 && counts[2] > 0 && counts[3] > 0 && counts[4] > 0 || counts[1] > 0 && counts[2] > 0 && counts[3] > 0 && counts[4] > 0 && counts[5] > 0)
				points = 40;
			scorecard[10] = points;
			break;
		case 12:
			if (counts[0] == 5 || counts[1] == 5 || counts[2] == 5 || counts[3] == 5 || counts[4] == 5 || counts[5] == 5)
			{
				// Check for Yahtzee bonus
				if (scorecard[11] > 0)
				{
					points = 100;
				}
				else 
				{
					points = 50;
				}
			}
			if (scorecard[11] == -1)
				scorecard[11]++;
			scorecard[11] += points;
			break;
		case 13:
			points = sum;
			scorecard[12] = points;
			break;
	}
	printf ("\nYou scored %d points for your roll!\n\n", points);
	system ("pause");
}

void upper_section (int scorecard_1[13], int scorecard_2[13], int *score_1, int *score_2)
{
	int sum_1 = 0, sum_2 = 0;

	for (int i = 0; i < 6; i++)
	{
		sum_1 += scorecard_1[i];
		sum_2 += scorecard_2[i];
	}
	if (sum_1 >= 63)
		*score_1 += 35;
	if (sum_2 >= 63)
		*score_2 += 35;
}

void print_results (int score_1, int score_2, char player_1[69], char player_2[69])
{
	system ("cls");
	printf ("%s scored %d points and %s scored %d points!\n", player_1, score_1, player_2, score_2);
	if (score_1 > score_2)
	{
		printf ("\nCongratulations %s, you win!\n\n", player_1);
	}
	else if (score_1 < score_2)
	{
		printf ("\nCongratulations %s, you win!\n\n", player_2);
	}
	else 
	{
		printf ("\nYou scored the same points, so it's a tie game!\n\n");
	}
	system ("pause");
}