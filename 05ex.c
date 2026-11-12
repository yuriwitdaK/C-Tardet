/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.
Wenn Teile der Linie außerhalb der Canvas liegen, dann sollen diese Teile ignoriert werden. Alles was in die Canvas passt, muss aber gezeichnet werden.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!_

*/
Canvas recursive_line(Canvas c, int x, int y, int width){
    if(width <= 0){//stop 
       return c;
    }
    if(y < canvas_height(c) && y >= 0){//go
    if(x >= 0 && x < canvas_width(c)){//go
    c = canvas_set_black(c , x, y);
   
}
     
}
    c = recursive_line(c , x + 1 , y, width - 1);//carryover width to x
    return c;
}
/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.
Wenn Teile des Rechtecks außerhalb der Canvas liegen, dann sollen diese Teile ignoriert werden. Alles was in die Canvas passt, muss aber gezeichnet werden.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
    if( height <= 0){//platz für überfölüssiges semikolon
    return c;
    }
    c = recursive_line(c, x, y,width);
    c = recursive_rectangle(c,x,y + 1, width,height -1);{
    return c;
    }

}

/*
Aufgabe 2:
Die Fibonaccizahlen sind wie folgt definiert:

- die nullte Fibonaccizahl ist 1,
- die erste Fibonaccizahl ist ebenfalls 1, und
- jede weitere Fibonaccizahl ist die Summe der zwei vorigen Fibonaccizahlen.

Berechne die `n`-te Fibonaccizahl.
*/
int fibonacci(int n) {
   // {n = n - 1;} memorial for bug that almost drove me insane
    if ( n <= 1){//don't make the stop condition 2 if it'S supposed to be one might lead to miscalculation
        return 1;
    
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

/*
Aufgabe 3:
Implementieren Sie einen schwarzen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/
Canvas bucket_fill(Canvas c, int x, int y){
    printf("x=%d y=%d\n", x, y);
    if(x >= canvas_width(c)){
        return c;
    }
    if(x < 0){
        return c;
    }
    if(y >= canvas_height(c)){
        return c;
    }
    if(y < 0){
    return c;
    }
    if(pixel_is_black(c ,x, y)){
        return c;
    }
    c = canvas_set_black(c ,x ,y);//middle pixel
    printf("schwarz? %d\n", pixel_is_black(c, x, y));

    c = bucket_fill(c ,x + 1, y);//right
    c = bucket_fill(c , x - 1, y);//left
    c = bucket_fill(c ,x , y + 1);//up
    c = bucket_fill(c , x,y - 1);//down
    return c;
    //erst gucken ob ich in canvas bin wenn nicht abbrechen
    //checken ob pixel schwarz ist wenn ja breche ich ab
    //wenn pixel weiß ist färbe ich ihn schwarz
    //dann rufe ich die funktion 4 mal auf mit parametern (x+1,y)(x-1,y)(x,y+1)(x y-1)
    // dann endet die funktion
    
}
    