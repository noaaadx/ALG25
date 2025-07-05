/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Elemento.h"
#include "ArbolBinario.h"

using namespace std;
#include "funcionesArbolesBinarios.h"

void construir(struct ArbolBinario & arbol) {
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoArbol * nodo) {
    return nodo == nullptr;
}

bool esArbolVacio(const struct ArbolBinario & arbol) {
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodo(struct NodoArbol * izquierda, const struct Elemento & elemento,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    return nuevo;
}

//nodos en nullptr
void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * izquierda, 
                          const struct Elemento & elemento, struct NodoArbol * derecha) {
    
    struct NodoArbol * nuevoNodo = crearNuevoNodo(izquierda, elemento, derecha);
    arbol.raiz = nuevoNodo;
}

//con dos árboles
void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario & arbolIzquierda, 
                         const struct Elemento & elemento, struct ArbolBinario & arbolDerecha) {
    struct NodoArbol * nuevoNodo = crearNuevoNodo(arbolIzquierda.raiz, elemento,
            arbolDerecha.raiz);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario & arbolIzquierdo,
        const struct Elemento & elemento, struct NodoArbol * derecho) {

    struct NodoArbol * nuevoNodo = crearNuevoNodo(arbolIzquierdo.raiz, elemento, derecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * izquierdo,
        const struct Elemento & elemento, struct ArbolBinario & arbolDerecho) {

    struct NodoArbol * nuevoNodo = crearNuevoNodo(izquierdo, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

char raiz(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo)) {
        cout << "No se puede obtener ra�z de un �rbol vacio" << endl;
        exit(1);
    }
    return nodo->elemento.elemento;
}

struct NodoArbol * hijoDerecho(const struct ArbolBinario & arbol) {
    if (esArbolVacio(arbol)) {
        cout << "No se puede obtener ra�z de un �rbol vacio" << endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct NodoArbol * hijoIzquierdo(const struct ArbolBinario & arbol) {
    if (esArbolVacio(arbol)) {
        cout << "No se puede obtener ra�z de un �rbol vacio" << endl;
        exit(1);
    }

    return arbol.raiz->izquierda;
}

void imprimeNodo(struct NodoArbol * nodo) {
    cout << setw(5) << nodo->elemento.elemento << " ";
}

void imprimeRaiz(const struct ArbolBinario & arbol) {
    imprimeNodo(arbol.raiz);
}



void recorrerEnOrdenRecursivo(struct NodoArbol * nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(const struct ArbolBinario & arbol) {
    /*Imprime en orden*/
    recorrerEnOrdenRecursivo(arbol.raiz);

}


void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo, char palabra[], int indice) {

    if (not esNodoVacio(nodo)) {
        palabra[indice] = nodo->elemento.elemento; // Agrega el valor del nodo a la palabra
        indice++;
        if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha)) {
            palabra[indice] = '\0';
            cout << palabra << endl;
            //imprimePalabra(palabra, indice); // Imprime la palabra al llegar a una hoja
        }
        recorrerEnPreOrdenRecursivo(nodo->izquierda, palabra, indice);
        recorrerEnPreOrdenRecursivo(nodo->derecha, palabra, indice);
    }

}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(const struct ArbolBinario & arbol) {
    char palabra[50]{};
    recorrerEnPreOrdenRecursivo(arbol.raiz, palabra, 0);
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo) {
    if (not esNodoVacio(nodo)) {
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
        cout << endl;

    }
}

///*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
// luego todos los restantes, comenzando por la raíz*/
//void recorrerPreOrden(const struct ArbolBinario & arbol){
//    recorrerEnPreOrdenRecursivo(arbol.raiz);   
//}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo) {
    if (not esNodoVacio(nodo)) {

        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
        
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(const struct ArbolBinario & arbol) {
  
    recorrerEnPostOrdenRecursivo(arbol.raiz);

}

int maximo(int a, int b) {
    return a >= b ? a : b;
}

int alturaRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(const struct ArbolBinario & arbol) {
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a nullptr
}

int numeroNodosRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

/*Determina el número de elementos del árbol*/
int numeroNodos(const struct ArbolBinario & arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(const struct ArbolBinario & arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo) {
    if (esNodoVacio(nodo))
        return 1;
    else {
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <= 1 and
                esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }
}

int esEquilibrado(const struct ArbolBinario & arbol) {
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(const struct ArbolBinario & arbol) {
    if (esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirArbolBinario(struct ArbolBinario & arbol) {
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbol * nodo) {
    if (not (esNodoVacio(nodo))) {
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}


