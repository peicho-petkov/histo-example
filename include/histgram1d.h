#ifndef HISTOGRAM1D_H
#define HISTOGRAM1D_H
#include <stdbool.h>

struct hist1d_s {
    float xmin, xmax;
    int nbins;
    float binwidth;
    float *counts;
    char *name;
};

typedef struct hist1d_s hist1d;

/**
 * @brief Creates a 1D histogram with specified parameters.
 * 
 * @param name The name of the histogram.
 * @param xmin The minimum value of the histogram range.
 * @param xmax The maximum value of the histogram range.
 * @param nbins The number of bins in the histogram.
 * @return A pointer to the created histogram structure, or NULL if creation fails.
 */
hist1d *hist1d_create(const char *name, float xmin, float xmax, int nbins);

bool hist1d_fill(hist1d *h, float x);
void hist1d_destroy(hist1d *h);
float hist1d_integral(hist1d *h);
void hist1d_scale(hist1d *h, float scale);
void hist1d_normalize(hist1d *h);
void hist1d_print(hist1d *h);
void hist1d_write(hist1d *h, const char *filename);

#endif // HISTOGRAM1D_H