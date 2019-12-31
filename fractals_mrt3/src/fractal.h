/*
 * math_lib.h
 *
 *  Created on: 19.12.2019
 *      Author: gaert
 */

#ifndef SRC_MATH_LIB_H_
#define SRC_MATH_LIB_H_


typedef struct paramaters_t{
    int radius;
    int radius_2;
    int imax;
    enum {JULIA, MANDELBROT} fraktal_t;
    double xmin, xmax;
    double ymin, ymax;
    int xpoints;
    int ypoints;
} parameters_t;

typedef struct{
    double x,y; 
} complex_t;

parameters_t parameters;

int get_iter(complex_t, complex_t);

complex_t next_z(complex_t, complex_t);

int in_circle_slow(complex_t, int);

void draw_point(complex_t c, complex_t z);

void draw_all_points(complex_t c);

#endif /* SRC_MATH_LIB_H_ */
