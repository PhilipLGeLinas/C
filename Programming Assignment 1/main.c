/*
 *  Programmer: Philip L. GeLinas
 *  Class: CptS 121, Spring 2019; Lab Section 16
 *  Programming Assignment 1
 *  Date: January 16, 2019
 *  Description: This program prompts the user for a variety of numerical quantities
 *               in order to calculate and print the result of various equations.
 */

#include <stdio.h>
#include <math.h>
#define PI 3.14

// A method which takes user input, calculates the result
// to a variety of equations, and prints the result
int main(void) {

    // Instantiation of variables
    double mass = 0, acceleration = 0, force = 0, radius = 0, height = 0, volume = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0,
           distance = 0, theta = 0, tangent = 0, total_resistance = 0, x = 0, y = 0, z = 0, result = 0;
    int a = 0, shift = 0, R1 = 0, R2 = 0, R3 = 0;
    char plaintext_character = 'a', encoded_character;

    // Newton's Second Law of Motion
    printf("Please enter the mass for use in Newton's Second Law: ");
    scanf("%lf", &mass);
    printf("Please enter the acceleration for use in Newton's Second Law: ");
    scanf("%lf", &acceleration);
    force = mass * acceleration;
    printf("Newton's Second Law: Force = Mass * Acceleration = %lf * %lf = %lf\n\n", mass, acceleration, force);

    // Volume of a cylinder
    printf("Please enter the radius for use in the calculation of the volume of a cylinder: ");
    scanf("%lf", &radius);
    printf("Please enter the height for use in the calculation of the volume of a cylinder: ");
    scanf("%lf", &height);
    volume = PI * radius * radius * height;
    printf("Volume of a cylinder: Volume = PI * Radius^2 * Height = %lf * %lf^2 * %lf = %lf\n\n", PI,
            radius, height, volume);

    // Character encoding
    printf("Please enter a plain-text character for use in character encoding: ");
    scanf(" %c", &plaintext_character);
    printf("Please enter an integer value for use in shifting your plain-text character: ");
    scanf("%d", &shift);
    encoded_character = (plaintext_character - 'A') + 'a' - shift;
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
    distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("Distance between two points: Distance = sqrt((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n\n",
            x1, x2, y1, y2, distance);

    // Tangent
    printf("Please enter the angle theta for use in the calculation of the tangent of said angle: ");
    scanf("%lf", &theta);
    tangent = sin(theta) / cos(theta); // Note: there also exists a tan(double) function
    printf("Tangent: Tangent(%lf) = sin(%lf) / cos(%lf) = %lf\n\n", theta, theta, theta, tangent);

    // Total resistance of resistors in parallel
    printf("Please enter the value for resistor 1 for use in the calculation of total resistance: ");
    scanf("%d", &R1);
    printf("Please enter the value for resistor 2 for use in the calculation of total resistance: ");
    scanf("%d", &R2);
    printf("Please enter the value for resistor 3 for use in the calculation of total resistance: ");
    scanf("%d", &R3);
    total_resistance = 1 / (1 / (double) R1 + 1 / (double) R2 + 1 / (double) R3);
    printf("Total resistance: Resistance = 1 / (1 / %d + 1 / %d + 1 / %d) = %lf\n\n", R1, R2, R3, total_resistance);

    // General equation
    printf("Please enter an integer value for a in the calculation of a general equation: ");
    scanf("%d", &a);
    printf("Please enter a floating-point value for x in the calculation of a general equation: ");
    scanf("%lf", &x);
    printf("Please enter a floating-point value for y in the calculation of a general equation: ");
    scanf("%lf", &y);
    printf("Please enter a floating-point value for z in the calculation of a general equation: ");
    scanf("%lf", &z);
    result = ((double) 2 / 3) - y + z * x / (a % 2) + PI;
    printf("General equation: y = (2 / 3) - %lf + %lf * %lf / (%d mod 2) + PI = %lf\n\n", y, z, x, a, result);

    return 0;
}
