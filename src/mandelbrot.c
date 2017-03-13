#include <complex.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "ppm.h"


// struct that holds all argument values for sanity's sake
struct args {
    long double delta, xStart, xEnd, yStart, yEnd, max;

};

struct args args;

// desc: checks program arguments to make sure they're legal, and places them in the args struct
// args:
//      argc, argv: argument values from main()
// return: int value. Either 0 for successful parsing, or -1 for unsuccessful parsing
int check_args(int argc, char** argv) {
    if(argc != 7) return -1;

    sscanf(argv[1], "%Lf", &args.xStart);   // starting X digit   
    sscanf(argv[2], "%Lf", &args.xEnd);     // ending X digit
    sscanf(argv[3], "%Lf", &args.yStart);   // starting Y digit
    sscanf(argv[4], "%Lf", &args.yEnd);     // ending Y digit
    sscanf(argv[5], "%Lf", &args.delta);    // difference in each XY pair
    sscanf(argv[6], "%Lf", &args.max);      // max RGB value

    return 0;

}


// desc: iterates through given coordinates and checks for divergence in the Mandelbrot set
// args:
//      x, y:      x/y-coordinate
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
        b = cpow(b, 2) + a;
        iterations++;
        
    }
    
    return iterations;
    
}


int main(int argc, char** argv) {
    if(check_args(argc, argv) != 0) {     // check and parse args
        return 0;   

    }

    int width = (args.xEnd - args.xStart) / args.delta;
    int height = (args.yEnd - args.yStart) / args.delta;

    FILE* output = create_ppm("output.ppm", width, height, args.max);       // get file handle for output ppm
    
    if(output == NULL) return 0;
    
    printf("drawing a %d x %d ppm to output.ppm...\n", width, height);

    // nested loops for moving through xy coordinates
    // moves from max y value to min y value, iterating via delta
    for(long double y = args.yEnd; y > args.yStart; y -= args.delta) {
        
        // moves from min x value to max x value, iterating via delta
        for(long double x = args.xStart; x < args.xEnd; x += args.delta) {
            int temp = compute(x, y, 0xFFFFFF);                            // get amount of iterations before divergence
            
            // take the temp value and mask the bits to get the RGB value
            // 0xFF FF FF
            //   R  G  B
            write_pixel((temp >> 16) & 0xFF, (temp >> 8) & 0xFF, (temp) & 0xFF, output);

        }
        
        
    }
 
    return 0;
    
}
