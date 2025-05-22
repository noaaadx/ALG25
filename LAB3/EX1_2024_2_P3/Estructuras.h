/* 
 * File:   Estructuras.h
 * Author: USUARIO
 *
 * Created on 16 de mayo de 2025, 10:53 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Nodo{
    int elemento;
    Nodo *siguiente;
};

struct Lista{
    Nodo *cabeza;
    Nodo *cola;
    int longitud;
};

#endif /* ESTRUCTURAS_H */

