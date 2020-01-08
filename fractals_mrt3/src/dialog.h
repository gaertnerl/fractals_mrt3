/* BOF DIALOG_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#ifndef DIALOG_H
#define DIALOG_H

/*--- Parameter Dialog Prototyp --------------------------------------------*/

/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
enum boolean {FALSE, TRUE};

char input_char();

int input_0_to_10(void);

void print_parameters(parameters_t *p);

void edit_parameters(parameters_t *p);

#endif /* DIALOG_H */

/* EOF DIALOG_H */
