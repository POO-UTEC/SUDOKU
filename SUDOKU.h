//
// Created by Alberto Julian Lara on 30/09/2018.
//

#ifndef SUDOKUPROJECT2_SUDOKU_H
#define SUDOKUPROJECT2_SUDOKU_H
//HASTA STRUCT VA ARRIBA


const int TAMANIO=9;//Tamaño en fila y columna ya que es una "matriz cuadrada"

typedef struct{
    int **num;  //va a ser mi matriz de numeros
    bool **ocu;  //va a ser una matriz bool determina pieza esta libre o esta ocupada
    // (con la que dijo el profe me servira probablemente para escoger la cantidad de números a eliminar del sudoku)
} sudoku;

void mostrar(sudoku &tablero);  //se encarga de mostrar el sudoku
void inicializar_cero( sudoku &tablero );  //inicializa las casillas en cero y que estan libres
void crearSudokualeatorio(sudoku &tablero);//Dibuja SUDOKU aleatorio
void verificarLlenado(sudoku &tablero, bool &repi);//Verifica que sea un SUDOKU valido


#endif //SUDOKUPROJECT2_SUDOKU_H
