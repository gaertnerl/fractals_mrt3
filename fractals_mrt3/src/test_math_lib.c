#include "math_lib.h"
#include "test_math_lib.h"
#include <stdio.h>

int * test_get_iter(){

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

    int *results_ptr = malloc(n_tests * sizeof(int));
    int i = 0;

    while(i < n_tests){
        *results_ptr = get_iter(data[i][0], data[i][1]);
        i++;
        results_ptr += sizeof(int);
    };
    results_ptr -= n_tests * sizeof(int);

    return results_ptr;
};

void run_tests_get_iter(){
    int *results_ptr = test_get_iter();
}
