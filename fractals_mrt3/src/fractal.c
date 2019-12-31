#include <math.h>
#include "fractal.h"
#include "graphic.h"
#include <stdio.h>

parameters_t parameters = {
		.radius = 3,
		.radius_2 = 9,
		.imax = 75,
		.fraktal_t = MANDELBROT,
		.xmin = -2,
		.xmax = 2,
		.ymin = -2,
		.ymax = 2,
		.xpoints = 400,
		.ypoints = 300,
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

color_name_t get_color_from_all(int iter, int iter_max){

    // calculate index, 0 -> black, 32 -> 
    int color_index = (((float) iter ) / ((float) iter_max)) * 32;

    // cast integer value to enum value
    color_name_t color = (color_name_t) color_index;
    return color;
}

color_name_t get_color_from_selection(int iter, int iter_max){

    int color_index = ( (((float)iter)/((float)iter_max))* 5);

    switch (color_index)
    {
    case 5: return White;
    case 4: return Light_Steel_Blu;
    case 3: return Heather;
    case 2: return Valhalla;
    default: return Black;
    }
}

void draw_point(complex_t c, complex_t z){

    int iter = get_iter(c, z);
    color_name_t color = get_color_from_all(iter, parameters.imax);
    grafik_lock_for_painting();
    if (parameters.fraktal_t == JULIA) grafik_paint_point(z.x, z.y, color);
    if (parameters.fraktal_t == MANDELBROT) grafik_paint_point(c.x, c.y, color);
    grafik_unlock_and_show();

}

void draw_all_points(complex_t constant){

    double x[parameters.xpoints];
    double y[parameters.ypoints];

    int width = parameters.xmax - parameters.xmin;
    int height = parameters.ymax - parameters.ymin;

    // calculate point raster
    for( int i=0; i < parameters.xpoints; i++ ){
        x[i] = (double) parameters.xmin + ((double)width /parameters.xpoints) *i;
    }
    for( int i=0; i < parameters.ypoints; i++ ){
        y[i] = (double) parameters.ymin + ((double)height /parameters.ypoints) *i;
    }

    // draw each point of point raster
    for( int i=0; i < parameters.xpoints; i++){
        for(int j=0; j < parameters.ypoints; j++){
            complex_t changing = {x[i], y[j]};
            
            if(parameters.fraktal_t == JULIA) draw_point(constant, changing);
            if(parameters.fraktal_t == MANDELBROT) draw_point(changing, constant);
        }
    }
}

