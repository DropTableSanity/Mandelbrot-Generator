// Implementation of ppm.h
// Handles the creation and editing of ppm files for other programs


// desc: creates a ppm file with required header
// args:
//      name: name of ppm file
//      width, height: dimensions of image
//      max: max integer value for any RGB elements written
// return: handle for created ppm file
FILE* create_ppm(char* name, int width, int height, int max) {
    FILE* out = fopen(name, "w");
    fprintf(out, "P3\n");
    fprintf(out, "%d\n", width);
    fprintf(out, "%d\n", height);
    fprintf(out, "%d\n", max);
    
    return out;
    
}

// desc: writes a pixel to a ppm file
// args:
//      r, g, b: RGB values for the pixel
//      file:    file handle for the pm file
void write_pixel(int r, int g, int b, FILE* file) {
    fprintf(file, "%d %d %d\n", r, g, b);
    
}
