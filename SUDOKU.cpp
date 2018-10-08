//
// Created by Alberto Julian Lara on 30/09/2018.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SUDOKU.h"

using namespace std;


//EL CUERPO VA ABAJO

void inicializar_cero( sudoku &tablero){
    for(int fila=0;fila<TAMANIO;fila++){
        for(int columna=0;columna<TAMANIO;columna++){
            //recorre toda la matriz y coloca en todas las pocisiones 0 y que todas son libres
            tablero.num[fila][columna] =0;
            tablero.ocu[fila][columna] =true;
        }
    }
}

void mostrar(sudoku &tablero){

    cout<<" \      0   1   2     3   4   5     6   7   8"<<endl;  //coordenadas de las columnas

    for(int fila=0;fila<TAMANIO;fila++){
        if( fila==0 || fila==3 || fila==6 ){ //si la fila es 0, 3 o 6 hago una linia para remarcar las regiones de 3x3
            cout<<"      -----------------------------------------"<<endl;
        }

        cout<<fila<<"   |"; //cada vez que inicie una fila me muestrar el numero de la coordenada y colocar una |


        for(int columna=0;columna<TAMANIO;columna++){

            if(columna==0 || columna==3 || columna==6){
                cout<<"| "; //si estoy comenzando en una region de 3x3 coloca uba barra
            }
            if(!tablero.ocu[fila][columna]){//si esta ocupada me encierra el numero entre corchetes
                cout<<"["<<tablero.num[fila][columna]<<"] ";
            }

            else{ //Si no está ocupada procede lo siguiente

                if(tablero.num[fila][columna]!=0){  //si es un numero diferente de 0 muestra el numero
                    cout<<" "<<tablero.num[fila][columna]<<"  ";
                }
                else{ //si no es diferente de 0 muestra la casilla con un punto, eso querrá decir que esta libre
                    cout<<" .  ";
                }
            }
            //una vez muestro el valor de la casilla
            if(columna==8) cout<<"||"; //si columna==8 es dicir al final de la casilla coloco una doble barra para que se vea mejor el cuadro
        }
        cout<<endl;
    }
    cout<<"      -----------------------------------------"<<endl<<endl;
}

void crearSudokualeatorio(sudoku &tablero){

    srand(time(NULL));
    cout<<"***#####  INICIALIZANDO CASILLAS OCUPADAS  #####***"<<endl<<endl;

//Impresión de nuevo sudoku aleatorio
    cout<<" \      0   1   2     3   4   5     6   7   8"<<endl;  //coordenadas de las columnas

    for(int fila=0;fila<TAMANIO;fila++){
        if( fila==0 || fila==3 || fila==6 ){ //si la fila es 0, 3 o 6 hago una linia para remarcar las regiones de 3x3
            cout<<"      -----------------------------------------"<<endl;
        }

        cout<<fila<<"   |"; //cada vez que inicie una fila me muestrar el numero de la coordenada y colocar una |

        for(int columna=0;columna<TAMANIO;columna++){

            tablero.num[fila][columna]=(rand()%(9))+1;
            if(columna==0 || columna==3 || columna==6){
                cout<<"| "; //si estoy comenzando en una region de 3x3 coloca uba barra
            }
            if(!tablero.ocu[fila][columna]){//si esta ocupada me encierra el numero entre corchetes
                cout<<"["<<tablero.num[fila][columna]<<"] ";
            }
            else{ //si no es ocupada es decir que es un valor de cuando ya esta jugando el usuario
                if(tablero.num[fila][columna]!=0){  //si es un numero diferente de 0 muestra el numero
                    cout<<" "<<tablero.num[fila][columna]<<"  ";
                }
                else{ //si no es diferente de 0 es decir que es un cero muestra la casilla en blanco
                    cout<<" .  ";
                }
            }
            //una vez muestro el valor de la casilla
            if(columna==8) cout<<"||"; //si j==8 es decir al final de la casilla coloco una doble barra para que se vea mejor el cuadro
        }
        cout<<endl;
    }
    cout<<"      -----------------------------------------"<<endl<<endl;
}

void verificarLlenado(sudoku &tablero, bool &repi){

    cout<<"***#####  VALIDACION SUDOKU  #####***"<<endl<<endl;

    for (int numvalido=1;numvalido<10;numvalido++){
        int contf=0, contc=0,contsub=0;
        for (int fil=0;fil<TAMANIO;fil++){
            for (int col=0;col<TAMANIO;col++){
                if (numvalido==tablero.num[fil][col]){
                    contf++;
                }
                if (numvalido==tablero.num[col][fil]){
                    contc++;
                }
                if (contf>=2 || contc>=2){
                    repi=true;
                }
                if (repi==true)
                    break;
            }
            if (repi==true)
                break;
        }
        for (int subfi=0;subfi<TAMANIO/3;subfi++){
            for (int subco=0;subco<TAMANIO/3;subco++){
                for (int fil=0;fil<TAMANIO/3;fil++){
                    for (int col=0;col<TAMANIO/3;col++){
                        if (numvalido==tablero.num[subfi*3+fil][subco*3+col]){
                            contsub++;
                        }
                        if (contsub>=2){
                            repi=true;
                        }
                        if (repi==true)
                            break;
                    }
                    if (repi==true)
                        break;
                }
                if (repi==true)
                    break;
            }
            if (repi==true)
                break;
        }
        if (repi==true)
            break;
    }
    if (repi==true)
        cout<<"El Sudoku no es valido D= sorry v;";
    else
        cout<<"El Sudoku es valido =D Yeah!";
}