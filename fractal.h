#ifndef FRACTAL_H
#define FRACTAL_H
#include <stddef.h>

typedef struct Mandelbrotset {
    const double REAL_MIN;
    const double REAL_MAX;
    const double IMAG_MIN;
    const double IMAG_MAX;

    const size_t width;
    const size_t height;
    const size_t max_iter;
} Mandelbrotset;

typedef double* FractalImageBitMap;

Mandelbrotset make_struct(size_t width, size_t height, size_t max_iter);
FractalImageBitMap render_fractal(Mandelbrotset object);
void save_fractal(Mandelbrotset object, FractalImageBitMap bitmap, const char* filename);
#endif
