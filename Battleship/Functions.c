/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 6
*  Date: March 8, 2019
*  Description: This program delegates a 2-player game of Battleship,
				conversing with the users and keeping track of the score.
*/

#include "Functions.h"

void welcome_message()
{
	printf("Welcome to Battleship!\n\nThe object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his/her board. You try to hit them by calling out the coordinates of one of the squares on the board. The other player also tries to hit your ships by calling out coordinates. Neither you nor the other player can see the other's board, so you must try to guess where they are.\n\n");
}

void print_board(char board[10][10], int player)
{
	if (player == 1)
	{
		printf("     Your Board\n---------------------\n  0 1 2 3 4 5 6 7 8 9\n");
	}
	else 
	{
		printf("    Enemy's Board\n---------------------\n  0 1 2 3 4 5 6 7 8 9\n");
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] != '-' && board[i][j] != '*' && board[i][j] != 'm' && player == 2)
			{
				printf("- ");
			}
			else 
			{
				printf("%c ", board[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void initialize_boards(char board_1[10][10], char board_2[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board_1[i][j] = '-';
			board_2[i][j] = '-';
		}
	}
}

void manually_place_ships(char board[10][10])
{
	system("cls");
	printf("You will now be prompted for the coordinates of your ships. Please specify a row and column value (0 - 9) corresponding to each unit length of your ship. Every value should be separated by a space. For example, if you were prompted for the coordinates of your cruiser (length 3), you might type: 3 4 3 5 3 6.\n\n");
	system("pause");

	for (int i = 0; i < 5; i++)
	{
		int coords[10];

		system("cls");
		switch (i)
		{
			case 0: 
				print_board(board, 1);
				printf("Please enter the coordinates for your carrier (length 5): ");
				scanf("%d %d %d %d %d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5], &coords[6], &coords[7], &coords[8], &coords[9]);
				while (check_coordinates(board, coords, 10, 'c') == 1)
				{
					system("cls");
					print_board(board, 1);
					printf("The coordinates you have entered are invalid or a ship already exists at this location. Please try again.");
					printf("\n\nPlease enter the coordinates for your carrier (length 5): ");
					scanf("%d %d %d %d %d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5], &coords[6], &coords[7], &coords[8], &coords[9]);
				}
				break;
			case 1:
				print_board(board, 1);
				printf("Please enter the coordinates for your battleship (length 4): ");
				scanf("%d %d %d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5], &coords[6], &coords[7]);
				while (check_coordinates(board, coords, 8, 'b') == 1)
				{
					system("cls");
					print_board(board, 1);
					printf("The coordinates you have entered are invalid or a ship already exists at this location. Please try again.");
					printf("\n\nPlease enter the coordinates for your battleship (length 4): ");
					scanf("%d %d %d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5], &coords[6], &coords[7]);
				}
				break;
			case 2:
				print_board(board, 1);
				printf("Please enter the coordinates for your cruiser (length 3): ");
				scanf("%d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5]);
				while (check_coordinates(board, coords, 6, 'r') == 1)
				{
					system("cls");
					print_board(board, 1);
					printf("The coordinates you have entered are invalid or a ship already exists at this location. Please try again.");
					printf("\n\nPlease enter the coordinates for your cruiser (length 3): ");
					scanf("%d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5]);
				}
				break;
			case 3:
				print_board(board, 1);
				printf("Please enter the coordinates for your submarine (length 3): ");
				scanf("%d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5]);
				while (check_coordinates(board, coords, 6, 's') == 1)
				{
					system("cls");
					print_board(board, 1);
					printf("The coordinates you have entered are invalid or a ship already exists at this location. Please try again.");
					printf("\n\nPlease enter the coordinates for your submarine (length 3): ");
					scanf("%d %d %d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3], &coords[4], &coords[5]);
				}
				break;
			case 4:
				print_board(board, 1);
				printf("Please enter the coordinates for your destroyer (length 2): ");
				scanf("%d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3]);
				while (check_coordinates(board, coords, 4, 'd') == 1)
				{
					system("cls");
					print_board(board, 1);
					printf("The coordinates you have entered are invalid or a ship already exists at this location. Please try again.");
					printf("\n\nPlease enter the coordinates for your destroyer (length 2): ");
					scanf("%d %d %d %d", &coords[0], &coords[1], &coords[2], &coords[3]);
				}
				break;
		}
	}
}

void randomly_place_ships(char board[10][10])
{
	for (int i = 0; i < 5; i++)
	{
		int coords[10];

		system("cls");
		rand_coords(coords);
		switch (i)
		{
		case 0:
			while (check_coordinates(board, coords, 10, 'c') == 1)
				rand_coords(coords);
			break;
		case 1:
			while (check_coordinates(board, coords, 8, 'b') == 1)
				rand_coords(coords);
			break;
		case 2:
			while (check_coordinates(board, coords, 6, 'r') == 1)
				rand_coords(coords);
			break;
		case 3:
			while (check_coordinates(board, coords, 6, 's') == 1)
				rand_coords(coords);
			break;
		case 4:
			while (check_coordinates(board, coords, 4, 'd') == 1)
				rand_coords(coords);
			break;
		}
	}
}

void rand_coords(int coords[10])
{
	int same = rand() % 10, start = rand() % 10;

	if (rand() % 2)
	{
		for (int i = 0; i < 10; i += 2)
		{
			if (start > 9)
				start %= 10;
			coords[i] = same;
			coords[i + 1] = start;
			start++;
			
		}
	}
	else 
	{
		for (int i = 0; i < 10; i += 2)
		{
			if (start > 9)
				start %= 10;
			coords[i + 1] = same;
			coords[i] = start;
			start++;

		}
	}
}

int check_coordinates(char board[10][10], int coords[10], int ship_length, char ship_type)
{
	// Check for invalid indexes
	for (int i = 0; i < ship_length; i++)
	{
		if (coords[i] < 0 || coords[i] > 9)
			return 1;
	}

	// Evens or odds must all be equal and the other must increment or decrement sequentially
	if (coords[0] == coords[2])
	{
		for (int i = 3; i < ship_length; i += 2)
		{
			if (coords[i - 3] != coords[i - 1])
				return 1;
			if (abs(coords[i - 2] - coords[i]) != 1)
				return 1;
		}
	}
	else 
	{
		for (int i = 3; i < ship_length; i += 2)
		{
			if (coords[i - 2] != coords[i])
				return 1;

			if (abs(coords[i - 3] - coords[i - 1]) != 1)
				return 1;
		}
	}

	// Check for overlapping ships
	for (int i = 0; i < ship_length; i += 2)
	{
		if (board[coords[i]][coords[i + 1]] != '-')
			return 1;
	}

	// Place ship
	for (int i = 0; i < ship_length; i += 2)
	{
		switch (ship_type)
		{
		case 'c':
			board[coords[i]][coords[i + 1]] = 'c';
			break;
		case 'b':
			board[coords[i]][coords[i + 1]] = 'b';
			break;
		case 'r':
			board[coords[i]][coords[i + 1]] = 'r';
			break;
		case 's':
			board[coords[i]][coords[i + 1]] = 's';
			break;
		case 'd':
			board[coords[i]][coords[i + 1]] = 'd';
			break;
		}
	}
	return 0;
}

int select_starter()
{
	return rand() % 2 + 1;
}

char check_shot(char board[10][10], int shot[2], int *lives)
{
	if (shot[0] > 9 || shot[0] < 0 || shot[1] > 9 || shot[1] < 0)
		return 'x';

	char tile = board[shot[0]][shot[1]];

	if (tile == 'm' || tile == '*')
		return 'x';

	// All good. Procede to shot.
	if (tile == '-')
	{
		board[shot[0]][shot[1]] = 'm';
		printf("\nIt's a miss!\n\n");
		return 'm';
	}
	else 
	{
		char result = board[shot[0]][shot[1]];
		board[shot[0]][shot[1]] = '*';
		*lives -= 1;
		printf("\nIt's a hit!\n\n");
		return result;
	}
}