/*
 * math_lib.h
 *
 *  Created on: 19.12.2019
 *      Author: gaert
 */

#ifndef SRC_MATH_LIB_H_
#define SRC_MATH_LIB_H_

typedef struct{
    int radius;
    int radius_2;
    int imax;
    enum {JULIA, MANDELBROT} fraktal_t;
    int xmin, xmax;
    int ymin, ymax;
    int xpoints;
    int ypoints;
}parameters_t;

typedef struct{
    double x,y;
} complex_t;

int get_iter(complex_t, complex_t);

complex_t next_z(complex_t, complex_t);

int in_circle_slow(complex_t, int);

#endif /* SRC_MATH_LIB_H_ */
