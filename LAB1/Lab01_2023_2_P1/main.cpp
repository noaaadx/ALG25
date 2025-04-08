/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 4 de abril de 2025, 05:12 PM
 */

#include <iostream>
#include <cstring>
#include <cmath>
#define PESO_MAX 100
#define n 4
using namespace std;
//declarando los headers
void cargaCromosoma(int i, int *cromosoma, int cromoCant);
void evaluarCromosoma(int *cromosoma, int cromoCant, int pesos[n][n], int valores[n][n], int &mejorValor,
    int mejorCromosoma[]);

void analizarBarco();


int main(int argc, char** argv) {
    //declaro las arreglos con los valores
    int pesos[n][n] = {{20, 20, 20, 20}, {10, 30, 10, 30}, {10, 10, 10, 10}, 
        {15, 15, 15, 15}};
    int valores[n][n] = {{10, 10, 10, 50}, {80, 10, 10, 20}, {20, 20, 20, 20},
        {50, 50, 50, 50}};
    
    int cromoCant = n * n;
    int combinaciones = (int)pow(2, cromoCant), mejorValor = 0;
    int mejorCromosoma[cromoCant]{};
    
    for(int i=0; i<combinaciones; i++){
        int cromosoma[cromoCant]{};
        cargaCromosoma(i, cromosoma, cromoCant);
        evaluarCromosoma(cromosoma, cromoCant, pesos, valores, mejorValor, mejorCromosoma);
    }
    
//    cout<<"Mejor valor "<< mejorValor<<endl;
//    cout<<"Mejor cromosoma: "<<endl;
//    for(int i=0; i<cromoCant; i++){
//        cout<<mejorCromosoma[i];
//        if((i+1)% n == 0) cout<<endl;
//    }
//    
    analizarBarco();
    
    return 0;
}

void cargaCromosoma(int i, int *cromosoma, int cromoCant){
    for(int j=0; j<cromoCant; j++){
        cromosoma[j] = i %2;
        i /= 2;
    }
}

void evaluarCromosoma(int *cromosoma, int cromoCant, int pesos[n][n], int valores[n][n], int &mejorValor,
    int mejorCromosoma[]){
    
    int totalPeso = 0;
    int totalValor = 0;
    
    for(int i=0; i<cromoCant; i++){
        if(cromosoma[i] == 1){
            int fila = i/n;
            int columna = i%n;
            totalPeso += pesos[fila][columna];
            totalValor += valores[fila][columna];
        }
    }
    
    if(totalPeso <= PESO_MAX && totalValor > mejorValor){
        mejorValor = totalValor;
        for(int i=0; i<cromoCant; i++){
            mejorCromosoma[i] = cromosoma[i];
        }
    }
}

void analizarBarco(){
    int fila = 4, columna = 10;
    char barco[fila][columna] = {{'H', 'C', 'H', 'B', 'Y', 'S', 'O', 'S', 'O', 'H'},
                                 {'S', 'C', 'S', 'S', 'Y', 'Q', 'O', 'S', 'Z', 'K'}, 
                                 {'O', 'P', 'N', 'Y', 'O', 'K', 'F','H', 'C', 'K'},
                                 {'O', 'B', 'N', 'I', 'Y', 'S', 'P', 'O', 'O', 'K'}};
    
    int cantFilaXColumna = fila * columna;  
    int combinaciones = (int)pow(2, cantFilaXColumna);
    cout<<"Primares 10 combinaciones posibles: ";
    for(int i=0; i<10; i++){
        int cromosoma[cantFilaXColumna]{};  
        cargaCromosoma(i, cromosoma, cantFilaXColumna);
        for(int j=0; j<cantFilaXColumna; j++){
            cout<<cromosoma[j];
        }
        cout<<endl;
    }
}