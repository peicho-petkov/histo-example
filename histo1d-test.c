#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "histgram1d.h"
#include "utils.h"
int main(int argc, char *argv[]) {
    int Nbins = 100;
    float Xmin = 1.0;
    float Xmax = 10.0;

    int Nevents = 1000000;
    
    float random_seed = time(NULL);
    float r_min = -15;
    float r_max = 15;
    
    // Print welcome message that explains the program
    printf("Welcome to the 1D histogram generator!\n");
    printf("This program will generate a random 1D histogram with %d bins.\n", Nbins);
    printf("The range of the histogram is from %f to %f.\n", Xmin, Xmax);
    printf("Number of events to generate: %d\n", Nevents);
    printf("Random seed: %f\n", random_seed);
    printf("Random range for events: [%f, %f]\n", r_min, r_max);
    printf("\n");

    // Initialize and fill the histogram
    hist1d *h1 = hist1d_create("h1", Xmin, Xmax, Nbins);
    
    srand(random_seed);
        
    for(int i = 0; i < Nevents; i++) {
        float x = rand_uniform(r_min, r_max);  // Generate a random number in the given range
        hist1d_fill(h1, x);
    }

    hist1d_print(h1);
 
    hist1d_write(h1, "histogram1d-test.txt");
 
    hist1d_normalize(h1);
    
    hist1d_write(h1, "histogram1d-test-normalized.txt");
 
    hist1d_destroy(h1);

    return 0;
}