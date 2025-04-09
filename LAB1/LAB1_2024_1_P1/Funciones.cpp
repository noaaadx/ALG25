/* 
 * File:   Funciones.cpp
 * Author: sebas
 * 
 * Created on 4 de abril de 2025, 08:04 AM
 */

#include "Funciones.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#define MAX_GUERREROS 3
#define MAX_ARMAS 12
using namespace std;


void test01(){
    int Poder[MAX_GUERREROS][MAX_GUERREROS +1] = {{120, 2, 0, 0},{160, 1, 3, 0},
        {80, 3, 0, 0}};
    char armas[MAX_ARMAS][3] = {{'Z', '\0', '\0'},{'P', 'Z', '\0'},
        {'R', '\0', '\0'},{'D', 'R', '\0'},{'E', '\0', '\0'},{'F', '\0', '\0'},
        {'G', '\0', '\0'},{'H', 'Z', 'E'},{'I', 'R', '\0'},{'J', '\0', '\0'},
        {'K', 'Z', '\0'},{'L', '\0', '\0'}};
    int armas_poder[MAX_ARMAS] = {60, 80, 38, 25, 49, 57, 68, 35, 62, 42, 36, 54};
    Guerrero1(Poder[0], armas, armas_poder);
}
void Guerrero1(int PoderFila[MAX_GUERREROS +1], char armas[MAX_ARMAS][3],int armas_poder[MAX_ARMAS]){
    int combinaciones = (int)pow(3, MAX_ARMAS) - 1;
    bool validado;
    for(int i=1; i<combinaciones; i++){
        int cromosoma[MAX_ARMAS]{};
        cargaCromosoma(i, cromosoma);
        validado = evaluarCromosoma( ,cromosoma, armas, armas_poder);
    }
}
int evaluarCromosoma(int cromosoma, char armas[MAX_ARMAS][3], int armas_poder[MAX_ARMAS]) {
    
    
}


void cargaCromosoma(int combinaciones, int *cromosoma){
    for(int i=0; i<MAX_ARMAS; i++){
        cromosoma[i] = combinaciones % 2;
        combinaciones /= 2;
    }
}
