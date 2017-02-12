FILE* create_ppm(char* name, int width, int height, int max) {
    FILE* out = fopen(name, "w");
    fprintf(out, "P3\n");
    fprintf(out, "%d\n", width);
    fprintf(out, "%d\n", height);
    fprintf(out, "%d\n", max);
    
    return out;
    
}


void write_pixel(int r, int g, int b, FILE* file) {
    fprintf(file, "%d %d %d\n", r, g, b);
    
}
