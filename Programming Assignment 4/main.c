/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 4
*  Date: February 13, 2019
*  Description: This program delegates a game of craps, conversing with the user
*				and keeping track of relevant information, such as the score and cash.
*/

#include "functions.h"

int main(void) {

	int die1 = 0, die2 = 0, sum_dice = 0, point_value = 0, status = 0, number_rolls = 0;
	double initial_balance = 0.0, current_balance = 0.0, wager_amount = 0.0;
	char replay = 'y', roll = 'r';

	while (replay == 'y' || replay == 'Y') {

		//  Game initialization
		print_game_rules();
		initial_balance = get_bank_balance();
		current_balance = initial_balance;

		while (current_balance > 0.0) {
			wager_amount = get_wager_amount();
			while (check_wager_amount(wager_amount, current_balance) == 0) {
				wager_amount = get_wager_amount();
			}

			// Roll the dice and find the sum
			printf("\nReady to roll? Type 'r' to roll your first die: ");
			scanf(" %c", &roll);
			die1 = roll_die();
			printf("\nType 'r' to roll again: ");
			scanf(" %c", &roll);
			die2 = roll_die();
			sum_dice = calculate_sum_dice(die1, die2);
			number_rolls++;

			point_value = sum_dice;
			status = is_win_loss_or_point(sum_dice);
			while (status == -1) {
				chatter_messages(number_rolls, status, initial_balance, current_balance);
				printf("\nLooks like you rolled for a sum of %d. Keep rolling until you hit %d or 7!\n", sum_dice, point_value);
				printf("\nReady to roll? Type 'r' to roll your first die: ");
				scanf(" %c", &roll);
				die1 = roll_die();
				printf("\nType 'r' to roll again: ");
				scanf(" %c", &roll);
				die2 = roll_die();
				sum_dice = calculate_sum_dice(die1, die2);
				number_rolls++;

				// Determine if the player has won or lost with each roll
				status = is_point_loss_or_neither(sum_dice, point_value);
			}
			if (status == 1) {
				printf("\nYou rolled for a sum of %d, so you won!\n", sum_dice);
			} else {
				printf("\nYou rolled for a sum of %d, you loser!\n", sum_dice);
			}
			chatter_messages(number_rolls, status, initial_balance, current_balance);
			current_balance = adjust_bank_balance(current_balance, wager_amount, status);
			printf("\nYour current balance is now $%.2lf.\n", current_balance);
			number_rolls = 0;
		}

		// Prompts the user to replay
		printf("\nLooks like you're out of money! Would you like to play again? (Y / N): ");
		scanf(" %c", &replay);
	}
	printf("\nThanks for playing!\n\n");
	return 0;
}