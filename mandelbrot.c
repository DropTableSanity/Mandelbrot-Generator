#include <complex.h>
#include <math.h>
#include <stdio.h>
#include "ppm.h"

// desc: iterates through given coordinates and checks for divergence in the Mandelbrot set
// args:
//      x, y: x/y-coordinate
//      magnitude: max amount of iterations allowed
// return: int value for amount of iterations done before divergence. Will be magnitude if
//         the coordinates converge
int compute(double x, double y, int magnitude) {
    double complex a, b;
    // set up starting number
    a = x + (y * I);
    b = 0;
    int iterations = 0;
    
    // iterate through set, if b ever goes over 2, it diverges
    while(cabs(b) < 2 && iterations < magnitude) {
        b = (b * b) + a;
        iterations++;
        
    }
    
    return iterations;
    
}


int main(int argc, char* argv) {
    long double delta = .001;   // difference in each xy pair
    long double xStart = -3;    // starting x coordinate
    long double xEnd = 3;       // enidng x coordinate
    long double yStart = -3;    // staring y coordinate
    long double yEnd = 3;       // ending y coordinate
    int max = 20;               // max rgb digit to be written to the output file
    
    FILE* output = create_ppm("output.ppm", 6000, 6000, max);  // get file handle for output ppm
    
    // nested loops for moving through xy coordinates
    // moves from max y value to min y value, iterating via delta
    for(long double y = yEnd; y >= yStart; y -= delta) {
        
        // moves from min x value to max x value, iterating via delta
        for(long double x = xStart; x <= xEnd; x += delta) {
            int temp = compute(x, y, 0xFFFFFF);                                             // get amount of iterations before divergence
            
            // take the temp value and mask the bits to get the RGB value
            // 0xFF FF FF
            //   R  G  B
            write_pixel((temp >> 16) & 0xFF, (temp >> 8) & 0xFF, (temp) & 0xFF, output);

        }
        
        printf("%Lf\n", y);  // print finished y value. Icky debug stuff
        
    }

    printf("\n%Lf pixels written\n", i);
    return 0;
    
}
