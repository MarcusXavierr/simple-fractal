#include <stdlib.h>
#include <stddef.h>
#include "fractal.h"
#include <complex.h>
#include <stdio.h>

Mandelbrotset make_struct(size_t width, size_t height, size_t max_iter) {
    Mandelbrotset set = {
        .REAL_MIN = -2,
        .REAL_MAX = 2,
        .IMAG_MIN = -1.5,
        .IMAG_MAX = 1.5,
        .width = width,
        .height = height,
        .max_iter = max_iter
    };
    return set;
}

FractalImageBitMap render_fractal(Mandelbrotset object) {
    size_t num_of_pixels = object.height * object.width;
    FractalImageBitMap bitmap = malloc(sizeof(double*) * num_of_pixels);

    // Fill the bitmap, pixel per pixel
    for (size_t y = 0; y < object.height; y++) {
        for (size_t x = 0; x < object.width; x++) {
            // The fractal formula is f(z) = z^2 + C, where C is a tiny complex number
            double complex C = (
                (object.REAL_MIN + (object.REAL_MAX - object.REAL_MIN) * x / object.width) + // Real part of the coordinate, the X axis
                (object.IMAG_MIN + (object.IMAG_MAX - object.IMAG_MIN) * y / object.height) * I // Imaginary Part, the Y axis
            );

            double complex z = 0;
            size_t iterations = 0;

            while(cabs(z) <= 2 && iterations < object.max_iter) {
                z = z * z + C;
                iterations++;
            }

            // Save the numbers of iterations on bitmap. Here, I'm using this array as a matrix,
            // so `y * width` says at what row whe're in, and the `+ x` sets the right column
            bitmap[y * object.width + x] = iterations;
        }
    }

    return bitmap;
}


void save_fractal(Mandelbrotset object, FractalImageBitMap bitmap, const char* filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write the header for a PPM file (P6 format). This way we can create images with color 😎
    fprintf(file, "P6\n%zu %zu\n255\n", object.width, object.height);

    for (size_t i = 0; i < object.width * object.height; i++) {
        double num_of_iterations = bitmap[i];
        unsigned char color[3];

        if (num_of_iterations == object.max_iter) {
            color[0] = 0; // Red
            color[1] = 0; // Green
            color[2] = 0; // Blue
        } else {
            // Apply a color gradient. Here to learn more about: https://dev.to/ndesmic/linear-color-gradients-from-scratch-1a0e
            double t = num_of_iterations / object.max_iter;
            color[0] = (unsigned char)(9 * (1 - t) * t * t * t * 255); // Red
            color[1] = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255); // Green
            color[2] = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Blue
        }

        fwrite(color, sizeof(unsigned char), 3, file);
    }

    fclose(file);
}

