/* 
 * File:   Estructuras.h
 * Author: USUARIO
 *
 * Created on 22 de mayo de 2025, 06:42 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <iostream>
#include <iomanip>
using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

struct Lista{
    struct Nodo *cabeza;
    struct Nodo *cola;
    int longitud;
};


#endif /* ESTRUCTURAS_H */

