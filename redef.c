#include <stdio.h>
#include <math.h>

float square(float, float);

float x1, y1, z1;
float x2, y2, z2;

float distance = 0;

int main(int argc, const char * argv[]) {

    printf("Enter coordinates of Point 1: ");
    scanf("%f, %f, %f", &x1, &y1, &z1);

    printf("Enter coordinates of Point 2: ");
    scanf("%f, %f, %f", &x2, &y2, &z2);

    distance = sqrtf(square (x2, x1) + square (y2, y1) + square (z2, z1));

    printf("Distance between the 2 points is %.3f\n\n", distance);

    return 0;
}

float square(float a, float b)
{
    float c = a - b;
    c = c * c;
    return c;
}
