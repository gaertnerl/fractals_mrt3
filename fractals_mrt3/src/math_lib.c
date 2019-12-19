#include <math.h>
#include "math_lib.h"

parameters_t parameters = {
		.radius = 2,
		.radius_2 = 4,
		.imax = 75,
		.fraktal_t = MANDELBROT,
		.xmin = -2,
		.xmax = 2,
		.ymin = -2,
		.ymax = 2,
		.xpoints = 400,
		.ypoints = 300
};

int get_iter(complex_t c, complex_t z_0) {

    int i = 0;
    complex_t z_1 = z_0;

    while(i < 75){
        i ++;
        z_1 = next_z(c, z_1);
        if (!in_circle_slow(z_1, parameters.radius_2)) {
           	   break;
        };
    };

    return i;
};

complex_t next_z(complex_t c, complex_t z){

	complex_t z_new;
    z_new.x = c.x + (pow(z.x,2) - pow(z.y,2));
    z_new.y = c.y + 2*z.x*z.y;
    return z_new;
};

int in_circle_quick(complex_t z, int radius) {
    return 0;
};

int in_circle_slow(complex_t z, int radius_2) {
    if ( (z.x*z.x + z.y*z.y) > radius_2) {
        return 0;
    }
    return 1;
}


