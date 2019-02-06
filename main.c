#include <stdio.h>

int main(void) {

    double x1 = 0, x2 = 0, y1 = 0, y2 = 0, slope = 0, xMid = 0, yMid = 0, mp = 0, b = 0;

    printf("Enter the x1 value for calculation of the slope: ");
    scanf("%lf\n", &x1);
    printf("Enter the x2 value for calculation of the slope: ");
    scanf("%lf\n", &x2);
    printf("Enter the y1 value for calculation of the slope: ");
    scanf("%lf\n", &y1);
    printf("Enter the y2 value for calculation of the slope: ");
    scanf("%lf\n", &y2);

    slope = (y2 - y1) / (x2 - x1);
    xMid = (x1 + x2) / 2;
    yMid = (y1 + y2) / 2;
    mp = -1 / slope;
    b = yMid + ((1 / slope) * xMid);
    printf("The slope-intercept form of the perpendicular bisector is y = %lfx + %lf.", mp, b);

    return 0;
}
