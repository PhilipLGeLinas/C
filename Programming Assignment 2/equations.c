/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 2
*  Date: January 25, 2019
*  Description: This program prompts the user for a variety of numerical quantities
*               in order to calculate and print the result of various equations.
*/

#include "equations.h"

double calculate_newtons_2nd_law(double mass, double acceleration) {
	return mass * acceleration;
}

double calculate_volume_cylinder(double radius, double height) {
	return PI * pow(radius, 2) * height;
}

char perform_character_encoding(char plaintext_character, int shift) {
	return (plaintext_character - 'A') + 'a' - shift;
}

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double calculate_tangent_theta(double theta) {
	return sin(theta) / cos(theta); // Note: there also exists a tan(double) function
}

double total_parallel_resistance(int r1, int r2, int r3) {
	return 1 / (1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3);
}

double general_equation(int a, double x, double y, double z) {
	return ((double)2 / 3) - y + z * x / (a % 2) + PI;
}
