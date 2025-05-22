/* 
 * File:   funcionLista.cpp
 * Author: USUARIO
 * 
 * Created on 17 de mayo de 2025, 06:20 AM
 */

#include "funcionLista.h"
#include "Estructuras.h"
#include <iostream>
using namespace std;

void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
    tad.sumaPesos = 0;
}

bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

int longitud(const struct Lista  & tad){
    return tad.longitud;
}

struct Nodo *crearNodo(int dato){
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->peso = dato;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void insertaAlFinal(struct Lista &tad, int elemento){
    Nodo *NuevoNodo = crearNodo(elemento);
    
    if(esListaVacia(tad)){
        tad.cabeza = NuevoNodo;
        tad.cola = NuevoNodo;
    }else{
        tad.cola->siguiente = NuevoNodo;
        tad.cola = NuevoNodo;
    }
    tad.sumaPesos += elemento;
    tad.longitud++;
}

void imprimirLista(struct Lista &tad){
    Nodo *actual = tad.cabeza;
    while(actual != nullptr){
        cout<<actual->peso<<"   ";
        actual = actual->siguiente;
    }
}