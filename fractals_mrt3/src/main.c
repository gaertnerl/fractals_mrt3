#include "fractal.h"
#include "graphic.h"
#include <stdio.h>

int main(){
    complex_t c = {1, 1};

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
    draw_all_points(c);
    printf("finished... \n");

    int t;
    scanf("%d", &t);
    printf("the end ...\n");
    grafik_close_window();

    return 0;
};


