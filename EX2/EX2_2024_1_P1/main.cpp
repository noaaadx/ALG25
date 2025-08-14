/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 11 de julio de 2025, 03:05 PM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionPila.h"
using namespace std;

void ClonarPila(Pila &origen, Pila &clon);

int main(int argc, char** argv) {
    
    
    return 0;
}

void ClonarPila(Pila &origen, Pila &clon){
    if(esPilaVacia(origen))return;
    
    int elemento = desapilar(origen);
    ClonarPila(origen, clon);
    
    apilar(clon, elemento);
    apilar(origen, elemento);
}