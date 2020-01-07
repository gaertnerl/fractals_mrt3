/*
 * math_lib.h
 *
 *  Created on: 19.12.2019
 *      Author: gaert
 */
#include "graphic.h"

#ifndef SRC_MATH_LIB_H_
#define SRC_MATH_LIB_H_

enum fractal_t {MANDELBROT, JULIA};

typedef struct paramaters_t{
    double radius;
    double radius_2;
    int imax;
    enum fractal_t fractal_t;
    double xmin, xmax;
    double ymin, ymax;
    int xpoints;
    int ypoints;
} parameters_t;

typedef struct{
    double x,y; 
} complex_t;

void fractal(parameters_t *p, complex_t constant);

#endif /* SRC_MATH_LIB_H_ */
