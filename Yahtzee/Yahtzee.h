/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 5
*  Date: February 25, 2019
*  Description: This program delegates a 2-player game of Yahtzee,
				conversing with the users and keeping track of the score.
*/

#include <stdio.h>
#include <time.h>

void prompt_user (char player_1[69], char player_2[69]);
void initialize_scorecards (int scorecard_1[13], int scorecard_2[13]);
void reroll_dice (int die_values[5]);
int validate_choice (int die_values[5], int scorecard[13], int choice);
void update_scorecard (int scorecard[13], int die_values[5], int choice);
void upper_section (int scorecard_1[13], int scorecard_2[13], int *score_1, int *score_2);
void print_results (int score_1, int score_2, char player_1[69], char player_2[69]);