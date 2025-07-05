/* 
 * File:   main.cpp
 * Author: Sebastian Noa
 * 
 * Created on 4 de julio de 2025, 07:25 PM
 */

#include <iostream>
#include <cstring>
#include "Arbol.hpp"
#include "cola.hpp"
#include "funcionesAB.hpp"
#include "Elemento.hpp"
using namespace std;

void c_insertarCromosoma(NodoArbol* &nodo, int valor, int bit = 0){
    if(nodo == nullptr){
        nodo = crearNuevoNodo(nullptr, {valor, bit}, nullptr);
        return;
    }
    c_insertarCromosoma(nodo->izquierda, valor, 0);
    c_insertarCromosoma(nodo->derecha, valor, 1);
}

ArbolBinario c_construirArbol(int array[], int n){
    ArbolBinario arbol;
    arbol.raiz = crearNuevoNodo(nullptr, {0, 0}, nullptr);
    for(int i=0; i<n ; i++)
        c_insertarCromosoma(arbol.raiz, array[i]);
    return arbol;
}

bool esHoja(NodoArbol *nodo){
    return nodo->izquierda == nullptr && nodo->derecha == nullptr;
}

int c_contarCombinacionesRec(NodoArbol* &nodo, int peso){
    if(nodo == nullptr) return 0;
    if(nodo->elemento.bit == 1) peso -= nodo->elemento.numero;
    if(esHoja(nodo) && peso == 0)return 1;
    return c_contarCombinacionesRec(nodo->izquierda, peso) + 
            c_contarCombinacionesRec(nodo->derecha, peso);
}

int c_contarCombinaciones(ArbolBinario &arbol, int peso){
    return c_contarCombinacionesRec(arbol.raiz, peso);
}

void c_imprimirArbol(ArbolBinario &arbol){
    Cola cola;
    encolar(cola, arbol.raiz);
    while(!estaVacia(cola)){
        NodoArbol *nodo = desencolar(cola);
        cout<<"("<<nodo->elemento.bit<<" , "<<nodo->elemento.numero<< ") ";
        if(nodo->izquierda != nullptr) encolar(cola, nodo->izquierda);
        if(nodo->derecha != nullptr) encolar(cola, nodo->derecha);
    }
}

void c_imprimirArbol_niveles(ArbolBinario &arbol){
    Cola cola;
    encolar(cola, arbol.raiz);
    while(!estaVacia(cola)){
        int n = longitud(cola);
        for(int i=0; i<n; ++i){
            NodoArbol *nodo = desencolar(cola);
            cout<< "(" << nodo->elemento.bit<< ", "<< nodo->elemento.numero << ")";
            if(nodo->izquierda != nullptr) encolar(cola, nodo->izquierda);
            if(nodo->derecha != nullptr) encolar(cola, nodo->derecha);
        }
        cout<<endl;
    }
}

int main(int argc, char** argv) {
    int array[] = {10, 50, 20};
    int peso = 30;
    
    int n = sizeof(array)/ sizeof(array[0]);
    ArbolBinario arbol = c_construirArbol(array, n);
    c_imprimirArbol_niveles(arbol);
    
    int conteo = c_contarCombinaciones(arbol, peso);
    cout<<" Número de combinaciones: "<<conteo << endl;
    return 0;
}

