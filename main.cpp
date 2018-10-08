#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SUDOKU.h"

using namespace std;

int main(){
    sudoku sudotab;//sudotab=su
    int cant=0, dificultad=0;
    bool repite=false;
    string nivel;

    sudotab.num= new int*[TAMANIO]; //con esto le asigno 9 vectores a mi variable num doble puntero
    sudotab.ocu= new bool*[TAMANIO]; //con esto le asigno 9 vectores a mi variable num doble puntero

    for(int i=0;i<TAMANIO;i++){
        sudotab.num[i]= new int [TAMANIO]; //asigno 9 posiciones a cada una de los 9 para crear mi matriz 9*9
        sudotab.ocu[i]= new bool [TAMANIO];
    }

    inicializar_cero(sudotab); //inizializo mi matriz con puros ceros y que todas las pociciones esta libres

    mostrar(sudotab);// muestro la matriz

    crearSudokualeatorio(sudotab);//crea sudoku aleatorio

    verificarLlenado(sudotab,repite);//valida sudoku valido

    //LIBERAR MEMORIA DINAMICA
    for (int i=0;i<TAMANIO;i++){
        delete [] sudotab.num[i];
        delete [] sudotab.ocu[i];
    }

    delete [] sudotab.num;
    delete [] sudotab.ocu;

}