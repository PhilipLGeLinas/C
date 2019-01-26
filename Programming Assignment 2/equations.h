/*
*  Programmer: Philip L. GeLinas
*  Class: CptS 121, Spring 2019; Lab Section 16
*  Programming Assignment 2
*  Date: January 25, 2019
*  Description: This program prompts the user for a variety of numerical quantities
*               in order to calculate and print the result of various equations.
*/

#include <stdio.h>
#include <math.h>
#define PI 3.14

double calculate_newtons_2nd_law(double mass, double acceleration);

double calculate_volume_cylinder(double radius, double height);

char perform_character_encoding(char plaintext_character, int shift);

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);

double calculate_tangent_theta(double theta);

double total_parallel_resistance(int r1, int r2, int r3);

double general_equation(int a, double x, double y, double z);