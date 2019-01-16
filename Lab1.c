#include <stdio.h>
#define PI 3.14

void ohmsLaw();
void joulesLaw();
void polynomialEquation();
void circumference();

void main() {

    int int1 = 0, int2 = 0, sum = 0, difference = 0, product = 0, modulus = 0;
    double double1 = 0, double2 = 0, quotient = 0;

    printf("Enter two integer values: ");
    scanf("%d%d", &int1, &int2);
    printf("Enter two decimal values: ");
    scanf("%lf%lf", &double1, &double2);

    sum = int1 + int2;
    printf("The sum is %d.\n", sum);

    difference = int1 - int2;
    printf("The difference is %d.\n", difference);

    product = int1 * (int) double1;
    printf("The product of is %d.\n", product);

    quotient = (double) int1 / (double) int2;
    printf("The quotient as an integer is %d and as a double is %lf.\n", (int) quotient, quotient);

    quotient = int1 / double2;
    printf("The quotient as an integer is %d and as a decimal is %lf.\n", (int) quotient, quotient);

    quotient = (double) int1 / int2;
    printf("The quotient is %lf.\n", quotient);

    modulus = (int) double1 % (int) double2;
    printf("The modulus is %d.\n", modulus);

    printf("The first integer mod 2 is %d and second is %d.\n", int1 % 2, int2 % 2);

    ohmsLaw();
    joulesLaw();
    polynomialEquation();
    circumference();
}

void ohmsLaw()
{
    int current = 0, resistance = 0;

    printf("Enter the current value: ");
    scanf("%d", &current);
    printf("Enter the resistance value: ");
    scanf("%d", &resistance);

    printf("The voltage is %d.\n", current * resistance);
}

void joulesLaw() {
    int power = 0, voltage = 0, resistance = 0;

    printf("Enter the voltage value: ");
    scanf("%d", &voltage);
    printf("Enter the resistance value: ");
    scanf("%d", &resistance);

    power = (voltage * voltage) / resistance;
    printf("The power is %d.\n", power);
}

void polynomialEquation()
{
    int a = 0, b = 0, c = 0, d = 0, x = 0, y = 0;
    printf("Enter values for a, b, c, d, and x: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &x);

    y = (3 * a * x * x * x) + (0.25 * b * x * x) + (10 * c * x) + (-0.5 * d);
    printf("The y value is %d.\n", y);
}

void circumference()
{
    double radius = 0.0, circumference;
    printf("Enter a radius value: ");
    scanf("%lf", &radius);

    circumference = 2.0 * PI * radius;
    printf("The circumference is %lf.", circumference);
}