#include "graphic.h"
#include "fractal.h"
#include "dialog.h"
#include <stdio.h>

int main(){

    /*--- Parametet festlegen ---*/

    parameters_t parameters = {
            .radius = 3,
            .radius_2 = 9,
            .imax = 75,
            .xmin = -2,
            .xmax = 2,
            .ymin = -2,
            .ymax = 2,
            .xpoints = 400,
            .ypoints = 300,
    };

    complex_t julia_c = {0.4, 0.4};
    complex_t mandelbrot_z = {0,0};


    /*-- Benutzerdialog Hauptschleife--*/

    printf( "\n"
            "PRAKTIKUM MRT VERSUCH 3 \n"
            "-------------------------------\n"
            "Thema: Berechnung von Fraktalen\n");
    printf( "\n"
            "Die Steuerung erfolgt ueber Konsoleneingaben.\n");

    enum boolean exit = FALSE;

    while(exit == FALSE){

            int key_pressed = 0;
            printf( "\n"
                    "1 : Parameter bearbeiten\n"
                    "2 : Zeichnen\n"
                    "3 : Programm beenden\n");

            printf("\nWas ist zu tun?\n");
            
            key_pressed = input_0_to_10();
            switch (key_pressed)
            {
            case 1: 
                edit_parameters(&parameters); 
                break;
            case 2: 
                printf("\nBeginne zeichnen von ");
                grafik_init_window();
                grafik_create_paint_area(
                    parameters.xmin,
                    parameters.xmax,
                    parameters.ymin,
                    parameters.ymax,
                    parameters.xpoints,
                    parameters.ypoints
                );
                if(parameters.fractal_t == JULIA){
                    printf("JUALIAMENGE\n");
                    fractal(&parameters, julia_c);
                }
                else{
                    printf("MANDELBROTMENGE\n");
                    fractal(&parameters, mandelbrot_z);
                } 
                grafik_close_window();
                break;
            case 3: 
                exit = TRUE;
                break;
            default: 
                printf("\nEINGABE FEHLERHAFT\n"); 
                break;
            }
            key_pressed = 0;
    }
    printf("\nProgramm wird beendet.\n");
};


