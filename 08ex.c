/*
Willkommen zum achten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Pointer und Arrays.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "turtlecanvas.h"

/*
Aufgabe 1a:
Lesen Sie das Headerfile `turtlecanvas.h`. Diese Funktion soll die Turtle `d` Schritte vorwärts machen lassen.
*/
void turtle_advance_by(TurtleCanvas *c, uint32_t d) {


    for(int i = 0 ; i < d; i++){
    turtle_advance(c);
    }
    return;
}

/*
Aufgabe 1b:
Füllen Sie die Turtlecanvas mit horizontalen, abwechselnd schwarzen und weißen Linien (die unterste Zeile soll
schwarz gefärbt werden). Die Turtle ist anfangs an Position (0, 0), ist nach rechts orientiert, und zeichnet schwarz.
*/
void turtle_stripes(TurtleCanvas *c) {
for(int y = 0; y < turtle_canvas_height(c) ;y++){

    if(y == turtle_canvas_height(c)-1){
         if (y % 2 == 0) {
                for (int i = 0; i < turtle_canvas_width(c); i++) {
                    turtle_advance(c);
                }
            }
        return;
    }
    if(y % 2 == 0){
    for(int i = 0; i < turtle_canvas_width(c); i++){
        turtle_advance(c);
    }
}
    if(y % 2 == 0){
    turtle_rotate_left(c);
    turtle_advance(c);
    turtle_rotate_left(c);
    }else{
turtle_toggle_color(c);

        turtle_rotate_right(c);
        turtle_advance(c);
        turtle_rotate_right(c);

        turtle_toggle_color(c);
    }
    
}

}

/*
Aufgabe 1c:
Lesen Sie die Implementierungen der Turtlecanvas-Funktionen weiter unten in der "turtlecanvas.h".
Der Quellcode sollte vollständig verständlich und unüberraschend sein.
Hinweis: Diese Aufgabe wird nicht bewertet.
*/

/*
Aufgabe 2a:
Geben Sie einen Pointer auf das erste Vorkommen der größten Zahl im Eingabearray zurück.
*/
uint16_t *find_maximal_number(uint16_t numbers[], size_t numbers_len) {
    if(numbers_len == 0){
        return NULL;
    }
    uint16_t *bigPointer = &numbers[0];// pointer auf ersten wert das arrays

    for(int i = 0; i < numbers_len;i++){//solange index kleiner als größe des index ist
        if(numbers[i] > *bigPointer){//wenn nummer an stelle des arrays größer ist als aktueller pointer
            bigPointer = &numbers[i];//ewrsetze pointer
        }
    }
    return bigPointer;// gib stelle an die pointer zeigt zurück 
}

/*
Aufgabe 2b:
Geben Sie (einen Pointer auf) das Teilarray zurück, welches ab dem ersten Vorkommen der größten Zahl im Eingabearray beginnt.
*/
uint16_t *find_subarray_starting_at_maximal_number(uint16_t numbers[], size_t numbers_len) {
    uint16_t *arrayPart = find_maximal_number(numbers,numbers_len);
    return arrayPart;
    
}

/*
Aufgabe 2c:
Geben Sie die größtmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die größte Distanz die zwischen 1 und 7, und beträgt damit `6`.
*/
    uint16_t find_maximum_distance(uint16_t numbers[], size_t numbers_len) {
        if(numbers_len == 0){
            return 0;
        }
        uint16_t *minuend = find_maximal_number(numbers,numbers_len);
        
        uint16_t *subtrahent = &numbers[0];
        for(int i = 1; i < numbers_len;i++){//solange index kleiner als größe des index ist
            if(numbers[i] < *subtrahent){//wenn nummer an stelle des arrays kleiner ist als aktueller pointer
            subtrahent = &numbers[i];//ewrsetze pointer
            }
        }
        int solution = *minuend - *subtrahent;
        // pointer zu kleinstem wert im Arry(funktion von oben invertieren)
        //kleinen von großem pointer subtrahieren und differenz ausgeben
        return solution;
    }


/*
Aufgabe 2d:
Geben Sie die kleinstmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die kleinste Distanz die zwischen 3 und 4, und beträgt damit `1`.
*/
uint16_t find_minimum_distance(uint16_t numbers[], size_t numbers_len) {

    if(numbers_len < 2){
        return 0;
    }

    int differenz = 0; 
    int solution = 65535;
    for(int i = 0;i< numbers_len;i++){
        for(int j = i+1;j < numbers_len; j++){
        differenz = numbers[i] - numbers[j];
        if(differenz < 0){
            differenz = -differenz;
        }
        if(differenz == 0){
            return 0;
        }
        if(differenz < solution){
            solution = differenz;
        }
    }
    }
       return solution;

    //Ich muss alle zahlen im array voneinander subtrahieren und die kleinste differenz finden
    //eine zahl in variable speichern und von jeder variable abziehen in neuer variable speichern
    //neue variable mit zwischenergebnis vergleichen und wenn nues zwischenergebnis kleiner als bestehende variable ist ersetzen
    //abbruch bei differenz 0

}

/*
Aufgabe 2e:
Schreiben Sie die ersten `numbers_len` Quadratzahlen aufsteigend in das gegebene Array `numbers`.
Hinweis: Wir starten bei `1`. Sollte numbers_len also `5` sein, sind die ersten 5 Quadratzahlen bis
einschließlich die von 5 gemeint: 1, 4, 9, 16, 25.
*/
void square_ascending(uint16_t numbers[], size_t numbers_len) {

    int basis = 0;//hilfsvariable

    for(int i = 0;i < numbers_len;i++){//for loop
        basis = i + 1;//bsasis schritt mqchem
        numbers[i] = basis * basis;//quadrieren

    }
    
}

/*
Aufgabe 2f:
Füllen Sie das Array `out` mit den aufsteigend sortierten Zahlen aus dem `in` Array. Beide Arrays haben die Länge `len`.
Beispiel: Ist `in` {1, 4, 3, 7, 4}, so soll `out` am Ende {1, 3, 4, 4, 7} sein.
*/
void sort_ascending(uint16_t in[], uint16_t out[], size_t len) {

    if(len == 0){
        return;
    }

    for(int i = 0; i < len; i++){//LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP
        int zähler = 0;
        
               for(int j = 0; j < len;j++){
                   if(in[i] > in[j]){
                    zähler++;//zähler gibt stelle im index an
                   }
                   if(in[i] == in[j]&& j < i){
                    zähler++;
                   }
               }
               out[zähler] = in[i];
            }
            return;
}
