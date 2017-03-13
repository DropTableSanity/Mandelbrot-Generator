// PPM helper library

#include <stdio.h>
#include "ppm.c"


FILE* new_ppm(char* name, int width, int height, int max);           // creates and prepares a new ppm file
void write_pixel(int r, int g, int b, FILE* file);                   // writes a pixel to a ppm file
