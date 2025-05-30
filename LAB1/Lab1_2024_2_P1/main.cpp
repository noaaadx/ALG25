/* 
 * File:   main.cpp
 * Author: sebas
 *
 * Created on 2 de abril de 2025, 08:10 AM
 */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define cantBuscada 4

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
<<<<<<< HEAD:LAB1/Lab1_2024_2_P1/main.cpp
    char patron[cantBuscada] = {'G', 'A', 'L', 'A'};
=======
    char patron[cantBuscada] = {'G', 'O', 'L'};
>>>>>>> 7d8114a0e5db02a3c9fdeca1b364c9151e489784:LAB1/Lab1_2024_2/main.cpp
    int cantCombinaciones = ((int)pow(2, nLetras)) - 1;
    //crear cromosoma
    bool validado;
    int cromosoma[nLetras]{}, posible=0;
    for(int i=1; i<cantCombinaciones; i++){
        llenarCromosoma(cromosoma, nLetras, i);
        
        //validarCromosomaCorrecto
        validado =validarCromosoma(cromosoma,arrLetras, patron, nLetras);
        //encontró la combinacion con la palabra GOL
        if(validado){
            posible++;
        }
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
    int cantLetras = 0, posicion = 0;
    char palabra[4] = {}, buffer[cantBuscada] = {};
    for(int i=0; i<nLetras ; i++){
        if(cromosoma[i] == 1)cantLetras++;
    }
    if(cantLetras != cantBuscada){
        return false;
    }else{
        for(int i=0; i<nLetras; i++){
            if(cromosoma[i] == 1){
                //meter las combinaciones de 1 en un char especifico
                palabra[posicion] = arrLetras[i];
                posicion++;
            }
        }
        //realizamos la comparativa con el patron
        //va a jugar con cada posicion del patron
        for(int h=0; h<cantBuscada; h++){
            bool letraEncontrada = false;
            for(int i=0; i<posicion; i++){
                if(patron[h] == palabra[i]){
<<<<<<< HEAD:LAB1/Lab1_2024_2_P1/main.cpp
                    palabra[i] = i;
=======
                    palabra[i] = '*';
>>>>>>> 7d8114a0e5db02a3c9fdeca1b364c9151e489784:LAB1/Lab1_2024_2/main.cpp
                    letraEncontrada = true;
                    break;
                }
            }
            if(!letraEncontrada)return false;
        }
    }
    return true; 
}
