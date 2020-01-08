/* BOF DIALOG_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#include "fractal.h"
#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char input_char(void)
{
        char s[80];
        fgets(s,sizeof(s), stdin);
        return s[0];
}

int input_0_to_10(void){
        char s[80];
        fgets(s,sizeof(s), stdin);
        int c = (int) (s[0] - '0');
        if(c >= 0 && c <= 9){
                return c;
        }
        return -1;
}

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void input_double(double *value)
{
        char *endptr;
        char s[80];
        fgets(s,sizeof(s), stdin);
        if (s[0]!=10) *value=strtod (s, &endptr);
}


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void input_int(int *value)
{
        char s[80];
        fgets(s,sizeof(s), stdin);
        if (s[0]!=10) *value=atoi (s);
}


/*--- Parameter Dialog -----------------------------------------------------*/

void print_parameters(parameters_t *p){

        printf( "\n1: radius          %f", p->radius);
        printf( "\n2: max. iteration  %d", p->imax);
        printf( "\n3: fraktal typ     ");
        if(p->fractal_t == JULIA) printf("JULIA");
        if(p->fractal_t == MANDELBROT) printf("MANDELBROT");
        printf( "\n4: x Bildpunkte    %d", p->xpoints);
        printf( "\n5: y Bildpunkte    %d", p->ypoints);
        printf( "\n6: x max., x min.  %f, %f", p->xmax, p->xmin);
        printf( "\n7: y max., y min.  %f, %f\n", p->ymax, p->ymin);
}

void edit_parameters(parameters_t *p){

        print_parameters(p);
        printf("\n8 um zurueck zum menue zu gelangen.\n");

        printf("\nwelcher parameter soll bearbeitet werden?\n");
        int input = input_0_to_10();
        switch (input)
        {
        case 1: 
                printf("\nneuen radius eingeben: ");
                double radius = 0;
                input_double(&radius);
                double radius_2 = radius * radius;
                p->radius = radius;
                p->radius_2 = radius_2;
                printf("\nneuer radius ist %f\n", radius);
                printf("\nneuer radius^2 ist %f\n", radius_2);
                break;
        case 2: 
                printf("\nneues iterationsmaximum: \n");
                input_int(&(p->imax));
        break;
        case 3:
                printf( "\n"
                        "\n1: JULIA"
                        "\n2: MANDELBROT\n"
                        "\nneuer fraktal typ:\n");
                int fraktal_typ = input_0_to_10();
                if(fraktal_typ == 1) p->fractal_t = JULIA;
                if(fraktal_typ == 2) p->fractal_t = MANDELBROT;
                else printf("\nfraktaltyp nicht erkannt :(\n");
                break;
        case 4: 
                printf("\nneue anzahl an x Bildpunkten: \n");
                input_int(&(p->xpoints));
                break;
        case 5: 
                printf("\nneue anzahl an y Bildpunkten: \n");
                input_int(&(p->ypoints));
                break;     
        case 6: 
                printf("\nneues max. x: \n");
                input_double(&(p->xmax));
                printf("\nneues min. x: \n");
                input_double(&(p->xmin));
                break;
        case 7: 
                printf("\nneues max. y: \n");
                input_double(&(p->ymax));
                printf("\nneues min. y: \n");
                input_double(&(p->ymin));
                break;
        case 8:
                break;
        default:
                printf("\neingabe ungueltig\n");
                break;
        }

        printf("\ngehe zurueck zum menu\n");
}

int show_mssg(char *message){

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                "User Dialog",
                                message,
                                NULL);
}


/* EOF DIALOG_C */
