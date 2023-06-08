#include <stdio.h>
#include <stdlib.h>
#define INDEF -9999;FILA


typedef int ITEM;
typedef struct ELEMENTO{
    ITEM dato;
    struct ELEMENTO * siguiente;
}ELEMENTO;

typedef struct FILA{
    struct ELEMENTO * frente;
    int altura;
}FILA;


// OPERACIONES
FILA FILAVACIA(); // FILA *P
FILA ENFILA(FILA P, ITEM I);
FILA PUSHF(FILA P, ITEM I);
ITEM FRENTE(FILA P);
ITEM TOP(FILA P);
FILA POP(FILA P);
FILA DEFILA(FILA *P);
FILA DEFILAX(FILA *P, ITEM I);
int ESSIMETRICA(FILA P);
FILA INVERTIRLISTA(FILA P); // como usuario
int INCLUIDA(FILA P1, FILA P2); // como usuario
int ESFILAVACIA(FILA P);
void MOSTRAR(FILA P);
int LONGITUD(FILA P);
int PERTENECE(FILA P, ITEM I);
int IGUALF(FILA F1, FILA F2);

int IGUALF(FILA F1, FILA F2){
    if(F1.frente != NULL && F2.frente != NULL){
        if(LONGITUD(F1) != LONGITUD(F2)){
            return 1;
        }else{
            printf("sx");
            return 0;
        }
    }else{
        printf("s");
        return 0;
    }
}

int PERTENECE(FILA P, ITEM I){

    while (P.frente != NULL){
        if(P.frente->dato == I){
            return 0;
        }
        P.frente = P.frente->siguiente;
    }
    return 1;
}

int LONGITUD(FILA P){
    int cont = 0;

    while (P.frente != NULL){
        cont ++;
        P.frente = P.frente->siguiente;
    }
    return cont;
}


// SEMANTICA
int ESFILAVACIA(FILA P){
    return P.frente == NULL;// ? 1 : 0;
}

void MOSTRAR(FILA P){
    printf("\n");
    while (P.frente != NULL)
    {
        printf("[%d]", P.frente->dato);
        P.frente = P.frente->siguiente;
    }
    
}

int INCLUIDA(FILA P1, FILA P2){
    int respuesta = 1;
    
    while (ESFILAVACIA(P2) != 1){
        if (TOP(P1) == TOP(P2)){
            P1 = POP(P1);
            P2 = POP(P2);
            respuesta = 0;
        }else{
            respuesta = 1;
            P2 = POP(P2);
        }
    }

    if(ESFILAVACIA(P1) != 1){
        return 1;
    }
    

    return respuesta;
}

FILA INVERTIRLISTA(FILA P){ // recibe una lista enlazada y, con la ayuda de una pila auxiliar, retorna la lista construida en orden inverso. 
    FILA PAUX = FILAVACIA();

    while (ESFILAVACIA(P) != 1)
    {
        PAUX = ENFILA(PAUX, TOP(P));
        P = POP(P);
    }   

    return PAUX;

}

FILA POP(FILA P){
    ELEMENTO *AUX;
    
    AUX = P.frente;
    P.frente = P.frente->siguiente;
    free(AUX);
    return P;
}

int ESSIMETRICA(FILA P){
    return 1;
}

FILA DEFILA(FILA *P){
    ELEMENTO * AUX, *ANT;
    AUX = P->frente;
    while (AUX->siguiente != NULL){
        ANT = AUX;
        AUX = ANT->siguiente;
    }
    ANT->siguiente = NULL;
    free(AUX);
    return *P;
}

FILA DEFILAX(FILA *P, ITEM I){
    ELEMENTO * ACT, *ANT;
    ACT = P->frente;

    if(ACT != NULL && ACT->dato == I){        
        P->frente = P->frente->siguiente;
        free(ACT);
    }else{

        while (ACT != NULL){
        if(ACT->dato == I){            
            printf("ANT:%d, ACT:%d", ANT->dato, ACT->dato);
            ANT->siguiente = ACT->siguiente;
            ACT = NULL;
            free(ACT);
        }else{
            ANT = ACT;
        }        
        ACT = ANT->siguiente;
    }

    }

    
    return *P;
}

ITEM TOP(FILA P){
    return P.frente->dato;
}

ITEM FRENTE(FILA P){

    while (P.frente->siguiente != NULL){
        P.frente = P.frente->siguiente;
    }
    return P.frente->dato;

}

FILA ENFILA(FILA P, ITEM I){
    ELEMENTO * nuevo = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    nuevo->dato = I;
    nuevo->siguiente = P.frente;
    P.frente = nuevo;
    P.altura++;
    return P;
}
FILA PUSHF(FILA P, ITEM I){
    ELEMENTO * AUX, *ANT;
    ELEMENTO * N = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    N->siguiente = NULL; N->dato = I;
    AUX = P.frente;
    while (AUX->siguiente != NULL){
        ANT = AUX;
        AUX = ANT->siguiente;
    }
    //ANT->siguiente = NULL;
    AUX->siguiente = N;
    return P;
}

FILA FILAVACIA(){
    FILA P;
    P.altura = 0; P.frente = NULL;
    return P;
}



