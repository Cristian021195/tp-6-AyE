#include <stdio.h>
#include <stdlib.h>
#include "headers/fila.h"

int main(){// FILA: [final]...[frente]
    FILA F1 = FILAVACIA(); FILA F2 = FILAVACIA(); FILA F3 = FILAVACIA();

    F1 = ENFILA(F1, 2); F1 = ENFILA(F1, 2);
    F1 = ENFILA(F1, 5); F1 = ENFILA(F1, 2);
    F1 = ENFILA(F1, 1); F1 = ENFILA(F1, 2);
    F1 = ENFILA(F1, 3); // F1: [2][2][5][2][1][2][3]
    F1 = DEFILAX(&F1,2);

    F2 = ENFILA(F2, 7); F2 = ENFILA(F2, 5);



    //MOSTRAR(F1); // 5,1,3
    //MOSTRAR(F2); // 7,5
    //DEFILAV(&F2);//DEFILAV(&F2);
    //printf("\nFTE: (%d)\n", F2.final->dato);
    //MOSTRAR(F2);
    F3 = CONCATN(F1,&F2,4);
    MOSTRAR(F3); // 5,1,3,7,7
    //printf("%d", FRENTE(F1)); 
    //printf("%d", FONDO(F1)); 
    // [5,1,3] [7,5] n=2, = [7,5,5,1,3] | [FTE-FND]
}