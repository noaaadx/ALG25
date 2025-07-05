
/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 1 de julio de 2025, 11:47 PM
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
using namespace std;

struct NodoArbol * c_crearNuevoNodo(struct NodoArbol *izquierda, int elemento, struct NodoArbol *derecha){
    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    return nuevo;            
}

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda arbol_paquetes;
    construir(arbol_paquetes);
    insertar(arbol_paquetes, 5);
    insertar(arbol_paquetes, 3);
    insertar(arbol_paquetes, 9);
    
    //cout<< "En orden: "<< endl;
    //enOrden(arbol_paquetes);
    
    struct ArbolBinario arbol_sistema;
    construir(arbol_sistema);
    plantarArbolBinario(arbol_sistema.raiz, nullptr, 1, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->izquierda, nullptr, 7, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->derecha, nullptr, 8, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->izquierda->izquierda, nullptr, 2, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->izquierda->derecha, nullptr, 3, nullptr);
    cout<< "\n Orden del arbol_ sistema: "<<endl;
    recorrerEnOrden(arbol_sistema);
    
    struct ArbolBinarioBusqueda arbol_resultado;
    return 0;
}

