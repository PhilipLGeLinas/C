#include "Interview.h"

int main()
{
	char source[100] = "source", destination[100] = "destination", *words[5] = { "crocodile", "elephant", "dogfish", "bear", "animal" }, test_string[100] = "test string", character = 'a';
	int n = 10, sorted_arr[5] = { 1, 2, 3, 4, 5 }, *max_occurrences = 0;
	Occurrences occurrences[100] = { 0 };

	// Test my_str_n_cat
	my_str_n_cat(source, destination, n);
	printf("TEST OF MY_STR_N_CAT\n%s\n\n", destination);

	// Test binary_search
	printf("TEST OF BINARY_SEARCH\n%s\n\n", binary_search(sorted_arr, 5, 5) == -1 ? "Does NOT Contain" : "Does Contain");

	// Test bubble sort
	bubble_sort(words, 5);
	printf("TEST OF BUBBLE_SORT\n%s | %s | %s | %s | %s\n\n", words[0], words[1], words[2], words[3], words[4]);

	// Test is_palindrome
	printf("TEST OF IS_PALINDROME\n%s\n\n", is_palindrome("racecar", 0, 6) == 0 ? "Is NOT Palindrome" : "Is Palindrome");

	// Test sum_primes
	printf("TEST OF SUM_PRIMES\n%d\n\n", sum_primes(15));

	// Test maximum_occurrences
	printf("TEST OF MAXIMUM_OCCURRENCES\n");
	maximum_occurrences(test_string, occurrences, &max_occurrences, &character);
	printf("The most occurring character is %c, which appears %d times.\n\n", character, max_occurrences);

	return 0;
}