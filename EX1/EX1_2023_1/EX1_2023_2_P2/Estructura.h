
/* 
 * File:   Estructura.h
 * Author: USUARIO
 *
 * Created on 23 de mayo de 2025, 07:28 PM
 */

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

struct Lista{
    struct Nodo *cabeza;
    struct Nodo *cola;
    int longitud;
};

struct Cola{
    struct Lista lista;
};

struct Pila{
    struct Lista lista;
};
#endif /* ESTRUCTURA_H */

