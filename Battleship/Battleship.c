/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 6
*  Date: March 8, 2019
*  Description: This program delegates a 2-player game of Battleship,
				conversing with the users and keeping track of the score.
*/

#include "Functions.h"

struct Stats
{
	int total_hits, total_misses, total_shots;
	double hit_miss_ratio;
	char win_or_loss[4];
};

struct Stats record_1, record_2;

int main()
{
	// Variable declarations
	char board_1[10][10], board_2[10][10], choice, check_result;
	int player, lives_1 = 17, lives_2 = 17, ships_1[5] = { 5, 4, 3, 3, 2 }, ships_2[5] = { 5, 4, 3, 3, 2 };

	// Game initialization
	FILE *log = fopen("battleship.log", "w");
	fprintf(log, "GAME FLOW\n");
	srand(time(NULL));
	player = select_starter();
	welcome_message();
	initialize_boards(board_1, board_2);

	printf("Would you like to manually place your ships? (Y/N): ");
	scanf(" %c", &choice);

	if (choice == 'Y' || choice == 'y')
	{
		manually_place_ships(board_1);
	}
	else 
	{
		randomly_place_ships(board_1);
	}
	randomly_place_ships(board_2);

	// Play game until someone runs out of lives
	while (lives_1 > 0 && lives_2 > 0)
	{
		int shot[2];
		system("cls");

		if (player == 1)
		{
			printf("Player 1's Turn\n\n");
			print_board(board_2, 2);
			printf("Please enter the coordinates for your shot, separated by a space: ");
			scanf("%d %d", &shot[0], &shot[1]);
			system("cls");
			printf("Player 1's Turn\n");
			check_result = check_shot(board_2, shot, &lives_2);
			while (check_result == 'x')
			{
				system("cls");
				printf("Player 1's Turn\n\n");
				print_board(board_2, 2);
				printf("The coordinates you entered were invalid or already used.\n\nPlease enter the coordinates for your shot, separated by a space: ");
				scanf("%d %d", &shot[0], &shot[1]);
				system("cls");
				printf("Player 1's Turn\n");
				check_result = check_shot(board_2, shot, &lives_2);
			}
			if (check_result != 'm')
			{
				record_1.total_hits += 1;
				record_1.total_shots += 1;
				fprintf(log, "Player 1 targeted [%d][%d] for a hit.\n", shot[0], shot[1]);
				switch (check_result)
				{
					case 'c':
						ships_2[0] -= 1;
						if (ships_2[0] == 0)
							fprintf(log, "Player 2's carrier has been sunk!\n");
						break;
					case 'b':
						ships_2[1] -= 1;
						if (ships_2[1] == 0)
							fprintf(log, "Player 2's battleship has been sunk!\n");
						break;
					case 'r':
						ships_2[2] -= 1;
						if (ships_2[2] == 0)
							fprintf(log, "Player 2's cruiser has been sunk!\n");
						break;
					case 's':
						ships_2[3] -= 1;
						if (ships_2[3] == 0)
							fprintf(log, "Player 2's submarine has been sunk!\n");
						break;
					case 'd':
						ships_2[4] -= 1;
						if (ships_2[4] == 0)
							fprintf(log, "Player 2's destroyer has been sunk!\n");
						break;
				}
			}
			else 
			{
				record_1.total_misses += 1;
				record_1.total_shots += 1;
				fprintf(log, "Player 1 targeted [%d][%d] for a miss.\n", shot[0], shot[1]);
			}
			print_board(board_2, 2);
			system("pause");
			player = 2;
		}
		else 
		{
			printf("Player 2's Turn\n");
			shot[0] = rand() % 10;
			shot[1] = rand() % 10;
			check_result = check_shot(board_1, shot, &lives_1);
			while (check_result == 'x')
			{
				shot[0] = rand() % 10;
				shot[1] = rand() % 10;
				check_result = check_shot(board_1, shot, &lives_1);
			}
			if (check_result != 'm')
			{
				record_2.total_hits += 1;
				record_2.total_shots += 1;
				fprintf(log, "Player 2 targeted [%d][%d] for a hit.\n", shot[0], shot[1]);
				switch (check_result)
				{
				case 'c':
					ships_1[0] -= 1;
					if (ships_1[0] == 0)
						fprintf(log, "Player 1's carrier has been sunk!\n");
					break;
				case 'b':
					ships_1[1] -= 1;
					if (ships_1[1] == 0)
						fprintf(log, "Player 1's battleship has been sunk!\n");
					break;
				case 'r':
					ships_1[2] -= 1;
					if (ships_1[2] == 0)
						fprintf(log, "Player 1's cruiser has been sunk!\n");
					break;
				case 's':
					ships_1[3] -= 1;
					if (ships_1[3] == 0)
						fprintf(log, "Player 1's submarine has been sunk!\n");
					break;
				case 'd':
					ships_1[4] -= 1;
					if (ships_1[4] == 0)
						fprintf(log, "Player 1's destroyer has been sunk!\n");
					break;
				}
			}
			else
			{
				record_2.total_misses += 1;
				record_2.total_shots += 1;
				fprintf(log, "Player 2 targeted [%d][%d] for a miss.\n", shot[0], shot[1]);
			}
			print_board(board_1, 1);
			system("pause");
			player = 1;
		}
	}
	system("cls");

	// Print game results
	if (lives_1 == 0)
	{
		strcpy(record_1.win_or_loss, "Loss");
		strcpy(record_2.win_or_loss, "Win");
		printf("Uh oh, you lose!\n\n");
	}
	else 
	{
		strcpy(record_1.win_or_loss, "Win");
		strcpy(record_2.win_or_loss, "Loss");
		printf("Congrats, you win!\n\n");
	}
	printf("Take a look at the game summary in the battleship.log file!\n\nThanks for playing!\n\n");
	record_1.hit_miss_ratio = (double) record_1.total_hits / record_1.total_shots;
	record_2.hit_miss_ratio = (double) record_2.total_hits / record_2.total_shots;

	// Print results to battleship.log
	fprintf(log, "\nPLAYER 1 STATS\nTotal Hits: %d\nTotal Misses: %d\nTotal Shots: %d\nHit-Miss Ratio: %lf\nGame Result: %s\n", record_1.total_hits, record_1.total_misses, record_1.total_shots, record_1.hit_miss_ratio, record_1.win_or_loss);
	fprintf(log, "\nPLAYER 2 STATS\nTotal Hits: %d\nTotal Misses: %d\nTotal Shots: %d\nHit-Miss Ratio: %lf\nGame Result: %s", record_2.total_hits, record_2.total_misses, record_2.total_shots, record_2.hit_miss_ratio, record_2.win_or_loss);

	// Display battleship.log
	fclose(log);
	system("battleship.log");

    return 0;
}