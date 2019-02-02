/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 3
*  Date: February 1, 2019
*  Description: This program processes a file of student numerical records, performs various operations
*               on the statistical information, and prints the result to an output file.
*/

#include "functions.h"

int main() {

	int class1, class2, class3, class4, class5;
	double gpa1, gpa2, gpa3, gpa4, gpa5, age1, age2, age3, age4, age5, dev1, dev2, dev3, dev4, dev5,
		gpa_sum, class_sum, age_sum, gpa_mean, class_mean, age_mean, variance, standard_deviation, min_gpa, max_gpa;

	// File declarations
	FILE *infile = fopen("input.dat", "r");
	FILE *outfile = fopen("output.dat", "w");

	// File reading and variable assignment
	read_integer(infile); gpa1 = read_double(infile); class1 = read_integer(infile); age1 = read_double(infile);
	read_integer(infile); gpa2 = read_double(infile); class2 = read_integer(infile); age2 = read_double(infile);
	read_integer(infile); gpa3 = read_double(infile); class3 = read_integer(infile); age3 = read_double(infile);
	read_integer(infile); gpa4 = read_double(infile); class4 = read_integer(infile); age4 = read_double(infile);
	read_integer(infile); gpa5 = read_double(infile); class5 = read_integer(infile); age5 = read_double(infile);

	// Sum calculations
	gpa_sum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	class_sum = calculate_sum(class1, class2, class3, class4, class5);
	age_sum = calculate_sum(age1, age2, age3, age4, age5);

	// Mean calculations
	gpa_mean = calculate_mean(gpa_sum, 5);
	print_double(outfile, gpa_mean);
	class_mean = calculate_mean(class_sum, 5);
	print_double(outfile, class_mean);
	age_mean = calculate_mean(age_sum, 5);
	print_double(outfile, age_mean);

	// Deviation calculations
	dev1 = calculate_deviation(gpa1, gpa_mean);
	dev2 = calculate_deviation(gpa1, gpa_mean);
	dev3 = calculate_deviation(gpa1, gpa_mean);
	dev4 = calculate_deviation(gpa1, gpa_mean);
	dev5 = calculate_deviation(gpa1, gpa_mean);

	// Variance calculation
	variance = calculate_variance(dev1, dev2, dev3, dev4, dev5, 5);

	// Standard deviation calculation
	standard_deviation = calculate_standard_deviation(variance);
	print_double(outfile, standard_deviation);

	// Minimum and maximum GPA calculations
	min_gpa = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	print_double(outfile, min_gpa);
	max_gpa = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	print_double(outfile, max_gpa);

	// Close input and output files
	fclose(infile);
	fclose(outfile);

	// Indicates success
	return 0;
}
