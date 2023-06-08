#include <stdio.h>
#include <stdlib.h>
#include "headers/fila.h"

int main(){// FILA: [final]...[frente]
    FILA F1 = FILAVACIA(); FILA F2 = FILAVACIA();

    F1 = ENFILA(F1, 2); F1 = ENFILA(F1, 3); F1 = ENFILA(F1, 4);
    F2 = ENFILA(F2, 2); F2 = ENFILA(F2, 3); //F2 = ENFILA(F2, 4);    
    F1 = DEFILAX(&F1,4);
    MOSTRAR(F1); // 4,3,2

}