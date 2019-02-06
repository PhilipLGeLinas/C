// Created by Philip GeLinas on 2019-02-06.

#include "main.h"

double get_average(double one, double two, double three, double four, double five) {

    return (one + two + three + four + five) / 5;
}

double get_high(double one, double two, double three, double four, double five) {

    double high = one;

    if (two > high)
        high = two;
    if (three > high)
        high = three;
    if (four > high)
        high = four;
    if (five > high)
        high = five;

    return high;
}

double get_low(double one, double two, double three, double four, double five) {

    double low = one;

    if (two < low)
        low = two;
    if (three < low)
        low = three;
    if (four < low)
        low = four;
    if (five < low)
        low = five;

    return low;
}
