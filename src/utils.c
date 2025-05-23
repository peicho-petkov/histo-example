#include <stdlib.h>
float rand_uniform(float r_min, float r_max) {
    return r_min + (double)rand() / (double)RAND_MAX * (r_max - r_min);
}