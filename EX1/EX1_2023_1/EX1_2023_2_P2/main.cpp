/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 23 de mayo de 2025, 07:28 PM
 */

#include <iostream>
#include <iomanip>
#include "Estructura.h"
#include "funcionCola.h"
#include "funcionPila.h"
#define N 13
using namespace std;
void ImprimirFases(const Cola &cola, const Pila &pila1, const Pila &pila2){
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1:";
    imprimir(pila1);
    cout<<"Pila 2:";
    imprimir(pila2);
}
void reclasificarAPilas(Cola &regIncidentes, Pila &pila1, Pila &pila2){
    while(!esColaVacia(regIncidentes)){
        int num = desencolar(regIncidentes);
        int prioridad = num/100;
        if(prioridad == 1)apilar(pila1, num);
        else if(prioridad == 2)apilar(pila2, num);
        
        int longPila1 = longitud(pila1);
        int longPila2 = longitud(pila2);
        if(longPila1 == 3 or longPila2 == 3)break;
    }
}
void reiniciarCola(struct Cola &regIncidentes, Pila &pila1, Pila &pila2){
    
}


int main(int argc, char** argv) {
    int ArrDatos[N] = {101, 102, 203, 204, 105, 206, 107, 208, 109, 210, 211, 112, 113};
    Cola regIncidentes;
    construir(regIncidentes);
    for(int i=0; i<N; i++){
        encolar(regIncidentes, ArrDatos[i]);
    }
    //Colocarlo en las pilas por niveles
    Pila pila1, pila2;
    construir(pila1);
    construir(pila2);            
    
    reclasificarAPilas(regIncidentes, pila1, pila2);
    cout<<"INICIAL: "<<endl;
    ImprimirFases(regIncidentes, pila1, pila2);
    
    reiniciarCola(regIncidentes, pila1, pila2);
    cout<<endl<<"REINICIAR COLA"<<endl;
    
    return 0;
}

