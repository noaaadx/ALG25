/* 
 * File:   main.cpp
 * Author: Sebastian Noa Castro
 * Codigo 20213281
 * Created on 3 de mayo de 2025, 08:11 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;    
#define FILA 3
#define COLUMNA 3

bool NumeroGuardado(int numero, int *arrOpciones, int cant){
    for(int i=0; i<cant; i++){
        if(numero == arrOpciones[i])return true;
    }
    return false;
}

void imprimirMtz(int matriz[FILA][COLUMNA]){
    cout<<"Impresion de la matriz es : "<<endl;
    for(int i=0; i<FILA; i++){
        cout<<"{";
        for(int j=0; j<COLUMNA; j++){
            cout<<matriz[i][j];
            if(j < COLUMNA - 1)cout<<",";
        }
        cout<<"}"<<endl;
    }
}

void opcionesColores(int matriz[FILA][COLUMNA]){
    int arrOpciones[FILA * COLUMNA]{}, cant = 0;
    for(int i=0; i<FILA; i++){
        for(int j=0; j<COLUMNA; j++){
            int numero = matriz[i][j];
            //si no lo tengo en el arreglo
            if(!NumeroGuardado(numero,arrOpciones, cant)){
                arrOpciones[cant] = numero;
                cant++;
            }
        }
    }
    cout<<"Opciones: "<<endl;
    for(int i=0; i<cant; i++){
        cout<<arrOpciones[i]<<endl;
    }
}
void actRecursivoMatriz(int matriz[FILA][COLUMNA], int valor, int cambio, int filaActual= 0, int columnaActual = 0){
    //caso base
    if(filaActual >= FILA)return;
    
    if(matriz[filaActual][columnaActual] == valor)matriz[filaActual][columnaActual] = cambio;
    
    if(columnaActual >= COLUMNA){
        actRecursivoMatriz(matriz, valor, cambio, filaActual +1, 0);
    }else{
        actRecursivoMatriz(matriz, valor, cambio, filaActual, columnaActual + 1);
    }
}

int main(int argc, char** argv) {
    int matriz[FILA][COLUMNA] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int valor, cambio;
    imprimirMtz(matriz);
    
    opcionesColores(matriz);
    cout<<"que opciones quiere cambiar "<<endl;
    cin>>valor;
    cout<<"a que opcion quiere colorearlo"<<endl;
    cin>>cambio;
    actRecursivoMatriz(matriz, valor, cambio);
    cout<<endl;
    imprimirMtz(matriz);
    return 0;
}

