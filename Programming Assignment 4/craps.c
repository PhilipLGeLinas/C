/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 4
*  Date: February 13, 2019
*  Description: This program delegates a game of craps, conversing with the user
*				and keeping track of relevant information, such as the score and cash.
*/

#include "craps.h"

// Prints out the rules of the game of craps
void print_game_rules(void) {
	printf("\nWelcome to the game of craps! The rules of the game are as follows:\n");
	printf("\nA player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\" To win, you must continue rolling the dice until you \"make your point\". The player loses by rolling a 7 before making the point.\n");
}

// Prompts the user for an initial bank balance from which wagering will 
// be added or substracted and returns the player entered bank balance
double get_bank_balance(void) {
	double initial_balance = 0.0;
	printf("\nEnter an initial bank balance: $");
	scanf("%lf", &initial_balance);
	return initial_balance;
}

// Prompts the player for a wager on a particular roll and returns the wager
double get_wager_amount(void) {
	double wager_amount = 0.0;
	printf("\nEnter a wager amount: $");
	scanf("%lf", &wager_amount);
	return wager_amount;
}

// Checks to see if the wager is within the limits of the player's available balance. 
// If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.
int check_wager_amount(double wager, double balance) {
	return (wager <= balance) ? 1 : 0;
}

// Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. 
// Returns the value of the die.
int roll_die(void) {
	srand(time(NULL));
	int die = rand() % 6 + 1;
	printf("You rolled a %d!\n", die);
	return die;
}

// Sums together the values of the two dice and returns the result.
int calculate_sum_dice(int die1_value, int die2_value) {
	return die1_value + die2_value;
}

// Determines the result of the first dice roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned. 
// If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins) and 0 is returned. 
// If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.
int is_win_loss_or_point(int sum_dice) {
	if (sum_dice == 7 || sum_dice == 11) {
		return 1;
	} else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
		return 0;
	} else {
		return -1;
	}
}

// Determines the result of any successive roll after the first roll. If the sum of the roll is the point_value, then 1 is returned. 
// If the sum of the roll is a 7, then 0 is returned. Otherwise, -1 is returned.
int is_point_loss_or_neither(int sum_dice, int point_value) {
	if (sum_dice == point_value) {
		return 1;
	} else if (sum_dice == 7) {
		return 0;
	} else {
		return -1;
	}
}

// If add_or_subtract is 1, then the wager amount is added to the bank_balance. If add_or_subtract is 0, then the wager amount 
// is subtracted from the bank_balance. Otherwise, the bank_balance remains the same. The bank_balance result is returned.
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	if (add_or_subtract == 1)
		bank_balance += wager_amount;
	if (add_or_subtract == 0)
		bank_balance -= wager_amount;
	return bank_balance;
}

// Prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance, 
// and whether or not the player just won his roll. The parameter win_loss_neither indicates the result of the previous roll.
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	if (number_rolls == 1 && win_loss_neither == 1)
		printf("\nWow, you won in a single roll!\n");
	if (number_rolls == 1 && win_loss_neither == 0)
		printf("\nYou lost on your first roll!? Pathetic!\n");
}
