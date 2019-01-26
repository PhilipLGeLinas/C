/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 2
*  Date: January 25, 2019
*  Description: This program prompts the user for a variety of numerical quantities
*               in order to calculate and print the result of various equations.
*/

// A method which takes user input, calculates the result
// to a variety of equations, and prints the result

#include "equations.h"

int main(void) {

	// Instantiation of variables
	double mass = 0, acceleration = 0, force = 0, radius = 0, height = 0, volume = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0,
		distance = 0, theta = 0, tangent = 0, total_resistance = 0, x = 0, y = 0, z = 0, result = 0;
	int a = 0, shift = 0, r1 = 0, r2 = 0, r3 = 0;
	char plaintext_character = 'a', encoded_character;

	// Newton's Second Law of Motion
	printf("Please enter the mass for use in Newton's Second Law: ");
	scanf("%lf", &mass);
	printf("Please enter the acceleration for use in Newton's Second Law: ");
	scanf("%lf", &acceleration);
	force = calculate_newtons_2nd_law(mass, acceleration);
	printf("Newton's Second Law: Force = Mass * Acceleration = %.2lf * %.2lf = %.2lf\n\n", mass, acceleration, force);

	// Volume of a cylinder
	printf("Please enter the radius for use in the calculation of the volume of a cylinder: ");
	scanf("%lf", &radius);
	printf("Please enter the height for use in the calculation of the volume of a cylinder: ");
	scanf("%lf", &height);
	volume = calculate_volume_cylinder(radius, height);
	printf("Volume of a cylinder: Volume = PI * Radius^2 * Height = %.2lf * %.2lf^2 * %.2lf = %.2lf\n\n", PI,
		radius, height, volume);

	// Character encoding
	printf("Please enter a plain-text character for use in character encoding: ");
	scanf(" %c", &plaintext_character);
	printf("Please enter an integer value for use in shifting your plain-text character: ");
	scanf("%d", &shift);
	encoded_character = perform_character_encoding(plaintext_character, shift);
	printf("Character encoding: Encoded Character = (%c - 'A') + 'a' - %d = %c\n\n",
		plaintext_character, shift, encoded_character);

	// Distance between two points
	printf("Please enter point x1 for use in the calculate of the distance between two points: ");
	scanf("%lf", &x1);
	printf("Please enter point x2 for use in the calculate of the distance between two points: ");
	scanf("%lf", &x2);
	printf("Please enter point y1 for use in the calculate of the distance between two points: ");
	scanf("%lf", &y1);
	printf("Please enter point y2 for use in the calculate of the distance between two points: ");
	scanf("%lf", &y2);
	distance = calculate_distance_between_2pts(x1, x2, y1, y2);
	printf("Distance between two points: Distance = sqrt((%.2lf - %.2lf)^2 + (%.2lf - %.2lf)^2) = %.2lf\n\n",
		x1, x2, y1, y2, distance);

	// Tangent
	printf("Please enter the angle theta for use in the calculation of the tangent of said angle: ");
	scanf("%lf", &theta);
	tangent = calculate_tangent_theta(theta);
	printf("Tangent: Tangent(%.2lf) = sin(%.2lf) / cos(%.2lf) = %.2lf\n\n", theta, theta, theta, tangent);

	// Total resistance of resistors in parallel
	printf("Please enter the value for resistor 1 for use in the calculation of total resistance: ");
	scanf("%d", &r1);
	printf("Please enter the value for resistor 2 for use in the calculation of total resistance: ");
	scanf("%d", &r2);
	printf("Please enter the value for resistor 3 for use in the calculation of total resistance: ");
	scanf("%d", &r3);
	total_resistance = total_parallel_resistance(r1, r2, r3);
	printf("Total resistance: Resistance = 1 / (1 / %d + 1 / %d + 1 / %d) = %.2lf\n\n", r1, r2, r3, total_resistance);

	// General equation
	printf("Please enter an integer value for a in the calculation of a general equation: ");
	scanf("%d", &a);
	printf("Please enter a floating-point value for x in the calculation of a general equation: ");
	scanf("%lf", &x);
	printf("Please enter a floating-point value for y in the calculation of a general equation: ");
	scanf("%lf", &y);
	printf("Please enter a floating-point value for z in the calculation of a general equation: ");
	scanf("%lf", &z);
	result = general_equation(a, x, y, z);
	printf("General equation: y = (2 / 3) - %.2lf + %.2lf * %.2lf / (%d mod 2) + PI = %.2lf\n\n", y, z, x, a, result);

	return 0;
}
