#include <stdio.h>
#include <stdlib.h>
#include "headers/fila.h"

int main(){// FILA: [final]...[frente]
    FILA F1 = FILAVACIA();

    F1 = ENFILA(F1, 2);
    F1 = ENFILA(F1, 2);
    F1 = ENFILA(F1, 5); //fte
    F1 = ENFILA(F1, 2); F1 = ENFILA(F1, 1); F1 = ENFILA(F1, 2);
    F1 = ENFILA(F1, 3); // final
    F1 = DEFILAX(&F1,2);
    MOSTRAR(F1); // 4,3,2
    
    //printf("%d", F1.frente->dato); // da fondo, ultimo agregado
    //printf("%d", F1.final->dato); // da fondo, ultimo agregado

}