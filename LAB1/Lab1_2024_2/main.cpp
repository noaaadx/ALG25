/* 
 * File:   main.cpp
 * Author: sebas
 *
 * Created on 2 de abril de 2025, 08:10 AM
 */

#include <iostream>
#include <cmath>
using namespace std;
//definimos headers
void llenarCromosoma(int *cromosoma, int nLetras, int combinacion);
bool validarCromosoma(int *cromosoma,char *arrLetras,char *patron,int nLetras);
void test01(char *arrLetras, int nLetras);

int main(int argc, char** argv) {
    
    //definimos arrLetras
    char arrLetras[8] = {'G', 'A', 'L', 'A', 'O', 'G', 'L', 'M'};
    int nLetras = 8;
    test01(arrLetras, nLetras);
    
    return 0;
}

void test01(char *arrLetras, int nLetras){
    //cantidad de combinaciones
    char patron[3] = {'G', 'O', 'L'};
    int cantCombinaciones = ((int)pow(2, nLetras)) - 1;
    //crear cromosoma
    bool validado;
    int cromosoma[nLetras]{}, posible=0;
    for(int i=1; i<cantCombinaciones; i++){
        llenarCromosoma(cromosoma, nLetras, i);
        
        //validarCromosomaCorrecto
        validado =validarCromosoma(cromosoma,arrLetras, patron, nLetras);
        if(validado)posible++;
    }
    cout<<posible;
    
}

void llenarCromosoma(int *cromosoma, int nLetras, int combinacion){
    int residuo;
    for(int i=0; i<nLetras; i++){
        residuo = combinacion % 2;
        cromosoma[i] = residuo;
        combinacion = combinacion/2;
    }
}

bool validarCromosoma(int *cromosoma, char *arrLetras, char *patron, int nLetras){
    int cantLetras = 0, cant = 0;
    for(int i=0; i<nLetras ; i++){
        if(cromosoma[i] == 1) cantLetras++;
    }
    if(cantLetras != 3)return false;
    if(cantLetras == 3){
        for(int i=0; i<nLetras; i++){
            if(cromosoma[i] == 1){
                for(int j=0; j<3; j++){
                    if(arrLetras[i] == patron[j]){
                        validado = true;
                        break;
                    }
                }
                validado = false;
            }
            if(!validado) return false;
        }
    }
    return true; 
}
