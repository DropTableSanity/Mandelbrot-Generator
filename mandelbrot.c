#include <complex.h>
#include <math.h>
#include <stdio.h>
#include "ppm.h"


int compute(double x, double y, int magnitude) {
    double complex a, b;
    a = x + (y * I);
    b = 0;
    int iterations = 0;
    
    while(cabs(b) < 2 && iterations < magnitude) {
        b = (b * b) + a;
        iterations++;
        
    }
    
    return iterations;
    
}


int main(int argc, char* argv) {
    long double delta = .001;
    long double i = 0;    
    long double xStart = -3;
    long double xEnd = 3;
    long double yStart = -3;
    long double yEnd = 3;
    int max = 20;
    FILE* output = create_ppm("output.ppm", 6000, 6000, max);
    
    
    for(long double y = yEnd; y >= yStart; y -= delta) {
        i++;
        
        for(long double x = xStart; x <= xEnd; x += delta) {
            int temp = compute(x, y, 0xFFFFFF);
            write_pixel((temp >> 16) & 0xFF, (temp >> 8) & 0xFF, (temp) & 0xFF, output);  

        }
        
        printf("%Lf\n", y);
        
        /*
        if(i / 6000 > .1) {
            printf("=");
            fflush(stdout);
            i = 0;
            
        }
        */
        
    }

    printf("\n%Lf pixels written\n", i);
    return 0;
    
}
