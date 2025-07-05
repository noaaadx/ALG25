/* 
 * File:   NodoArbol.h
 * Author: USUARIO
 *
 * Created on 4 de julio de 2025, 07:33 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "Elemento.hpp"

struct NodoArbol{
    struct Elemento elemento;
    struct NodoArbol *izquierda;
    struct NodoArbol *derecha;
};

#endif /* NODOARBOL_H */

