// Created by Philip GeLinas on 2019-02-06.

#include "main.h"

int main(void) {

    double one = 0.0, two = 0.0, three = 0.0, four = 0.0, five = 0.0;
    char answer = '\0';

    FILE *infile = fopen("file.txt", "r");

    one = fscanf(infile, "%lf", &one);
    two = fscanf(infile, "%lf", &two);
    three = fscanf(infile, "%lf", &three);
    four = fscanf(infile, "%lf", &four);
    five = fscanf(infile, "%lf", &five);

    printf("What do you want from me? Type 'a' for Average, 'h' to get High, or 'l' to get low.");
    scanf(" %c", &answer);

    if (answer == 'a') {

        printf("The average is %lf.", get_average(one, two, three, four, five));

    } else if (answer == 'h') {

        printf("You are high is %lf.", get_high(one, two, three, four, five));

    } else if (answer == 'l') {

        printf("Low is %lf.", get_low(one, two, three, four, five));

    } else {
        exit(1);
    }

    fclose(infile);

    return 0;
}