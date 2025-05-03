/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 2 de mayo de 2025, 10:31 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <cmath>
#define FILA 5
#define COLUMNA 5
using namespace std;
void imprimirMtz(int matriz[FILA][COLUMNA]){
    cout<<"Se imprime la matriz: "<<endl;
    for(int i=0; i<FILA; i++){
        cout<<"{";
        for(int j=0; j<COLUMNA; j++){
            cout<<setw(2)<<matriz[i][j];
            if(j < COLUMNA -1)cout<<", ";
        }
        cout<<"}"<<endl;
    }
}

int hallarMaxValor(int matriz[FILA][COLUMNA], int i=0, int j=0){
    
    if(i >= FILA)return INT_MIN;
    
    int actual = matriz[i][j];
    int siguiente;
    
    if(j< COLUMNA - 1){
        siguiente = hallarMaxValor(matriz, i, j+1);
    }else{
        siguiente = hallarMaxValor(matriz, i+1, 0);
    }
    return max(actual, siguiente);
}

void actualizarMtz(int matriz[FILA][COLUMNA], int max){
    for(int i=0; i<FILA; i++){
        for(int j=0; j<COLUMNA; j++){
            int antiguo = matriz[i][j];
            matriz[i][j] = max - antiguo;
        }
    }
}
int main(int argc, char** argv) {
    //declaro la matriz
    int matriz[FILA][COLUMNA] ={
    {4, 3, 6, 8, 7},
    {6, 3, 8, 4, 10},
    {2, 15, 1, 2, 13},
    {5, 1, 10, 11, 2},
    {10, 4, 7, 9, 4}};
    
    //imprimirMtz(matriz);
    int max = hallarMaxValor(matriz);
    
    actualizarMtz(matriz, max);
    imprimirMtz(matriz);

    return 0;
}

