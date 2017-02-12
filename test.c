#include <complex.h>
#include <math.h>
#include <stdio.h>

int main() {
    int temp = 167772;
    int r = ((temp >> 16) & 0xFF);
    int g = ((temp >> 8) & 0xFF);
    int b = ((temp) & 0xFF);  

    printf("%i %i %i", r, g, b);

}