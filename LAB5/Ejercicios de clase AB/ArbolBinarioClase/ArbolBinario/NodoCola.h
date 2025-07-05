/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "NodoArbol.h"

/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct NodoCola {
    struct NodoArbol * nodo; /*Dato que cambia por double, char, struct */
    struct NodoCola * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODOCOLA_H */

