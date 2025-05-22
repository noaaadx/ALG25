/* 
 * File:   main.cpp
 * Author: Sebastian Noa Castro
 *
 * Created on 16 de mayo de 2025, 04:46 PM
 */

#include <iostream>
#include <cstring>
#define FILA 3
#define COLUMNA 3
using namespace std;

void imprimeMtz(int matriz[FILA][COLUMNA]){
    for(int i=0; i<FILA; i++){
        for(int j=0; j<COLUMNA; j++){
            cout<<matriz[i][j];            
            if(j<COLUMNA-1)cout<<", ";
        }
        cout<<endl;
    }
}

void pintarZonaContigua(int matriz[FILA][COLUMNA], int i, int j, int valorOriginal, int valor){
    //validar limites
    if(i < 0 || i >= FILA || j < 0 || j >= COLUMNA)return;
    
    //solo pintas las casillas cuyos valores son iguales al original
    if(matriz[i][j] != valorOriginal)return;
    
    matriz[i][j] = valor;
    
    pintarZonaContigua(matriz, i+1, j, valorOriginal, valor);    
    pintarZonaContigua(matriz, i-1, j, valorOriginal, valor);    
    pintarZonaContigua(matriz, i, j+1, valorOriginal, valor);    
    pintarZonaContigua(matriz, i, j-1, valorOriginal, valor);    
}

void cambioRecursivo(int matriz[FILA][COLUMNA], int filaDat, int columnaDat, int valor){
    //hallamos el valor de la casilla seleccionada
    int valorOriginal = matriz[filaDat][columnaDat];
    if(valorOriginal == valor)return;
    
    pintarZonaContigua(matriz, filaDat, columnaDat, valorOriginal, valor);
}

int main(int argc, char** argv) {
    int matriz[FILA][COLUMNA] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int filaDat, columnaDat, valor;
    cout<<"Introduzca la posicion del pixel: ";
    cin>>filaDat>>columnaDat;
    cout<<"Nuevo valor: "; cin>>valor;
    //filaDat = 1, columnaDat = 1, valor = 2;
    imprimeMtz(matriz);
    cambioRecursivo(matriz, filaDat, columnaDat, valor);
    cout<<"--------------------------------------------"<<endl;
    imprimeMtz(matriz);

    return 0;
}

