/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 20 de junio de 2025, 09:14 PM
 */

#include <iostream>
#include <iomanip>
#define FILA 10
#define COLUMNA 7
using namespace std;


void HallarPotenciaMax(int matriz[FILA][COLUMNA], int inicio, int fin, int &potenciaMax, int &columnaMax){
    if(inicio > fin) return;
    int medio = FILA / 2;
    
    int maxFila = matriz[medio][0];
    int colMax = 0;
    for(int j = 1; j < COLUMNA; j++){
        if(matriz[medio][j] > maxFila){
            maxFila = matriz[medio][j];
            colMax = j;
        }
    }
|
    int izquierda, derecha;
    if(medio - 1 >= inicio){
        izquierda = matriz[filaMax][medio - 1];
    }else{
        izquierda = -1;
    }
}

int main(int argc, char** argv) {
    int matriz[FILA][COLUMNA]= {{0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 1, 1},
                                {0, 0, 0, 0, 1, 2, 2}, 
                                {0, 0, 0, 0, 1, 2, 3},
                                {0, 0, 0, 0, 1, 2, 2},
                                {0, 0, 0, 0, 1, 1, 1},
                                {0, 0, 0, 0, 0, 0, 0}};
    //inciso a
    int inicio = 0, fin = 0, potenciaMax = 0, columnaMax = 0;
    HallarPotenciaMax(matriz, inicio, fin, potenciaMax, columnaMax);
    
    return 0;
}

