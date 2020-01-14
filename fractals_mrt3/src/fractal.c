#include <math.h>
#include "fractal.h"
#include <stdio.h>

complex_t next_z(complex_t c, complex_t z){

	complex_t z_new;
    z_new.x = c.x + (pow(z.x,2) - pow(z.y,2));
    z_new.y = c.y + 2*z.x*z.y;
    return z_new;
};

int in_circle(complex_t z, int radius_2) {
    if ( (z.x*z.x + z.y*z.y) > radius_2) {
        return 0;
    }
    return 1;
}

int get_iter(complex_t c, complex_t z, int radius_sqr, int imax) {

    int i = 0;
    complex_t z_1 = z;

    while(i < imax){
        i ++;

        z_1 = next_z(c, z_1);
        if (!in_circle(z_1, radius_sqr)) {
           	   break;
        };
    };

    return i;
};

color_name_t get_color_from_all(int iter, int iter_max){

    // calculate index, 0 -> black, 32 -> 
    
    //OLD
    //int color_index = (int) (((float) iter ) / ((float) iter_max)) * 32;

    //NEW
    int color_index = iter%32;

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

void draw_point(complex_t c, complex_t z, enum fractal_t fractal_t, int radius_2, int imax){

    int iter = get_iter(c, z, radius_2, imax);
    color_name_t color = get_color_from_all(iter, imax);
    
    if (fractal_t == JULIA) grafik_paint_point(z.x, z.y, color);
    if (fractal_t == MANDELBROT) grafik_paint_point(c.x, c.y, color);


}

void fractal(parameters_t *p, complex_t constant){

    grafik_lock_for_painting();

    double x[p->xpoints];
    double y[p->ypoints];

    int width = (p->xmax) - (p->xmin);
    int height = (p->ymax) - (p->ymin);

    // calculate point raster
    for( int i=0; i < (p->xpoints); i++ ){
        x[i] = (p->xmin) + ((float) width / (p->xpoints)) *i;
    }
    for( int i=0; i < (p->ypoints); i++ ){
        y[i] = (p->ymin) + ((float) height / (p->ypoints)) *i;
    }

    // draw each point of point raster
    for( int i=0; i < (p->xpoints); i++){
        for(int j=0; j < (p->ypoints); j++){
            complex_t changing = {x[i], y[j]};
            
            if(p->fractal_t == JULIA) draw_point(constant, changing, p->fractal_t, (p->radius_2), (p->imax));
            if(p->fractal_t == MANDELBROT) draw_point(changing, constant, p->fractal_t, (p->radius_2), (p->imax));
        }
    }

    grafik_unlock_and_show();
}



