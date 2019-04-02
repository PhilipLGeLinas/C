/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 6
*  Date: March 8, 2019
*  Description: This program delegates a 2-player game of Battleship,
				conversing with the users and keeping track of the score.
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

void welcome_message();
void print_board(char board[10][10], int player);
void initialize_boards(char board_1[10][10], char board_2[10][10]);
void manually_place_ships(char board[10][10]);
void randomly_place_ships(char board[10][10]);
void rand_coords(int coords[10]);
int check_coordinates(char board[10][10], int coords[10], int ship_length, char ship_type);
int select_starter();
char check_shot(char board[10][10], int shot[2], int *lives);