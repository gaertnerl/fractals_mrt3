#include "fractal.h"
#include "graphic.h"
#include <stdio.h>

int main(){



    complex_t julia_c = {0.4, 0.4};
    complex_t mandelbrot_z = {0,0};

    parameters.fraktal_t = JULIA;
    printf("start Julia...\n");
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
    draw_all_points(julia_c);
    printf("finished julia ... wait for input \n");
    int t;
    scanf("%d", &t);
    grafik_close_window();

    parameters.fraktal_t = MANDELBROT;
    printf("start Mandelbrot...\n");
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
    draw_all_points(mandelbrot_z);
    printf("finished Mandelbrot ... wait for input \n");
    scanf("%d", &t);
    grafik_close_window();

    return 0;
};


