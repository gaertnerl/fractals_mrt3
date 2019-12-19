#include "math_lib.h"
#include "test_math_lib.h"

int *test_get_iter(){

    complex_t data[4][2];

    data[0][0].x = 0;
    data[0][0].y = 0;
    data[0][1].x = 0;
    data[0][1].y = 0;

    data[1][0].x = 0.4;
    data[1][0].y = 0.5;
    data[1][1].x = 0.7;
    data[1][1].y = 0.9;

    data[2][0].x = 1;
    data[2][0].y = 2;
    data[2][1].x = 3;
    data[2][1].y = 4;

    data[3][0].x = 1.4;
    data[3][0].y = 0;
    data[3][1].x = 1.1;
    data[3][1].y = 1.1;

    int n_tests = sizeof(data)/sizeof(data[0]);

    int iterations[n_tests];

    while(n_tests > 0){
        n_tests --;
        int iter = get_iter(data[n_tests][0], data[n_tests][1]);
        iterations[n_tests] = iter;
    };

    return iterations;
};
