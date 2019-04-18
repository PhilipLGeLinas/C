#include "Interview.h"

// Appends n characters of source to destination
void my_str_n_cat(char *source, char *destination, int n)
{
	while (*destination != NULL)
	{
		*destination++;
	}

	while (n > 0 && *source != NULL)
	{
		*destination = *source;
		*destination++;
		*source++;
		n--;
	}
}

// Searches an array of sorted integers and returns
// the index of a target value if found and -1 otherwise
int binary_search(int sorted_arr[], int target_val, int length)
{
	int left = 0, right = length - 1, found = 0, target_index = 0, mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sorted_arr[mid] == target_val)
		{
			return mid;
		}
		else if (sorted_arr[mid] < target_val)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

// Sorts the strings passed through an array
void bubble_sort(char *words[], int length)
{
	int c = 1, u = length - 1;

	while (u != 1)
	{
		while (c != u)
		{
			if (compare(words[c - 1], words[c]) == 1)
			{
				char *temp = words[c];
				words[c] = words[c - 1];
				words[c - 1] = temp;
			}
			c++;
		}
		if (compare(words[c - 1], words[c]) == 1)
		{
			char *temp = words[c];
			words[c] = words[c - 1];
			words[c - 1] = temp;
		}
		u--;
		c = 1;
	}
	if (compare(words[c - 1], words[c]) == 1)
	{
		char *temp = words[c];
		words[c] = words[c - 1];
		words[c - 1] = temp;
	}
}

int compare(char *word_1, char *word_2)
{
	while (*word_1 != NULL && *word_2 != NULL)
	{
		if (*word_1 < *word_2)
		{
			return 2;
		}
		else if (*word_1 > *word_2)
		{
			return 1;
		}
		else
		{
			*word_1++;
			*word_2++;
		}
	}
	if (*word_1 == NULL)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

// Determines whether a word is a palindrome
int is_palindrome(char word[], int start, int end)
{
	if (end - start == 1)
		if (word[start] == word[end])
			return 1;

	if (start == end)
		return 1;

	if (word[start] != word[end])
		return 0;

	return is_palindrome(word, start + 1, end - 1);
}

// Adds all primes from 2 to n
int sum_primes(unsigned int n)
{
	if (n == 2)
		return 2;

	while (is_prime(n) == 0)
		n--;

	return n + sum_primes(n - 1);
}

// Determines if a number if prime
int is_prime(unsigned int n)
{
	int result = 0;

	for (int i = n - 1; i > 1; i--)
		if (n % i == 0)
			return 0;

	return 1;
}

// Determines the frequency of each character found in the array
void maximum_occurrences(char test_string[], Occurrences occurrences[], int *max_occurrences, char *character)
{
	int occurrences_index = 0, occurrences_size = 0, current_char = 'a', string_index = 0;

	while (test_string[string_index] != NULL)
	{
		current_char = test_string[string_index];
		if (!contains_char(occurrences, occurrences_size, current_char))
		{
			occurrences[occurrences_index] = (Occurrences) { 1, 0.0, current_char };
			occurrences_size++;
			occurrences_index++;
		}
		else
		{
			increment_occurrence(occurrences, occurrences_size, current_char);
		}
		string_index++;
	}
	for (int i = 0; i < occurrences_size; i++)
	{
		occurrences[i].frequency = (double)occurrences[i].num_occurrences / (double)string_index;
		if (occurrences[i].num_occurrences > *max_occurrences)
		{
			*max_occurrences = occurrences[i].num_occurrences;
			*character = occurrences[i].character;
		}
	}
}

// Determines if an occurrence has been generated for any given character
int contains_char(Occurrences occurrences[], int occurrences_size, char current_char)
{
	for (int i = 0; i < occurrences_size; i++)
		if (occurrences[i].character == current_char)
			return 1;

	return 0;
}

void increment_occurrence(Occurrences occurrences[], int occurrences_size, char current_char)
{
	for (int i = 0; i < occurrences_size; i++)
		if (occurrences[i].character == current_char)
			occurrences[i].num_occurrences++;
}