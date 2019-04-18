#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
	char character;
} Occurrences;

void my_str_n_cat(char *source, char *destination, int n);
int binary_search(int sorted_arr[], int target_val, int length);
void bubble_sort(char *words[], int length);
int is_palindrome(char word[], int start, int end);
int sum_primes(unsigned int n);
int is_prime(unsigned int n);
void maximum_occurrences(char test_string[], Occurrences occurrences[], int *max_occurrences, char *character);
int contains_char(Occurrences occurrences[], int occurrences_size, char current_char);
void increment_occurrence(Occurrences occurrences[], int occurrences_size, char current_char);