#include "fractal.h"
#include "graphic.h"
#include <stdio.h>

int main(){
    complex_t julia_c = {0.4, 0.4};
    complex_t mandelbrot_z = {0,0};

    printf("start...\n");
    grafik_init_window();
    grafik_create_paint_area(
        parameters.xmin,
        parameters.xmax,
        parameters.ymin,
        parameters.ymax,
        parameters.xpoints,
        parameters.ypoints
    );

    printf("drawing points... \n");
    if(parameters.fraktal_t == JULIA) draw_all_points(julia_c);
    if(parameters.fraktal_t == MANDELBROT) draw_all_points(mandelbrot_z);
    printf("finished... \n");

    int t;
    scanf("%d", &t);
    printf("the end ...\n");
    grafik_close_window();

    return 0;
};


