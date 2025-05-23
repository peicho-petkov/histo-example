#include "histgram1d.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

hist1d * hist1d_create(const char *name, float xmin, float xmax, int nbins)
{
    hist1d *h = (hist1d*)malloc(sizeof(hist1d));
    h->name = strdup(name);
    h->xmin = xmin;
    h->xmax = xmax;
    h->nbins = nbins;
    h->binwidth = (xmax - xmin) / nbins;
    h->counts = (float*)calloc(nbins+2, sizeof(float));
}

void hist1d_destroy(hist1d *h)
{
    free(h->counts);
    free(h->name);
    free(h);
}

bool hist1d_fill(hist1d *h, float x)
{
    if (x < h->xmin ) {
        h->counts[0]++;
        return false;
    }
    if (x >= h->xmax ) {
        h->counts[h->nbins+1]++;
        return false;
    }
    int bin = (x - h->xmin) / h->binwidth + 1;
    h->counts[bin]++;
    return true;
}

float hist1d_integral(hist1d *h)
{
    float bsum = 0.0;
    for(int i = 1; i <= h->nbins; i++) {
        bsum += h->counts[i];
    }
    return bsum * h->binwidth;
}

void hist1d_scale(hist1d *h, float scale)
{
    for(int i = 1; i <= h->nbins; i++) {
        h->counts[i]*=scale;
    }
}

void hist1d_normalize(hist1d *h)
{
    hist1d_scale(h,1.0/hist1d_integral(h));
    h->counts[0] = h->counts[h->nbins+1] = 0.0;
}

void hist1d_print(hist1d *h) {
    printf("Histogram: %s\n", h->name);
    printf("Bin width: %f\n", h->binwidth);
    printf("Integral: %f\n", hist1d_integral(h));
    for(int i = 1; i <= h->nbins; i++) {
        printf("Bin %d, bin center %f: %f\n", i, h->xmin + ((float)i-0.5)*h->binwidth, h->counts[i]);
    }
}

void hist1d_write(hist1d *h, const char *filename) {
    FILE *fp = fopen(filename, "w");
    
    if(fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
    
    fprintf(fp, "# Histogram: %s, underflow %d, overflow %d\n", 
            h->name, (int)h->counts[0], (int)h->counts[h->nbins+1]);
    
    for(int i = 1; i <= h->nbins; i++) {
        fprintf(fp,"%f %f\n", h->xmin + ((float)i-0.5)*h->binwidth, h->counts[i]);
    }
    
    fclose(fp);
}