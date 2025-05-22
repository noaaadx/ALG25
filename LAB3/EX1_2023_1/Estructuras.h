
/* 
 * File:   Estructuras.h
 * Author: USUARIO
 *
 * Created on 17 de mayo de 2025, 06:10 AM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <iostream>
#include <string>

struct Nodo{
    int peso;
    Nodo *siguiente;
};

struct Lista{
    Nodo* cabeza;
    Nodo* cola;
    int sumaPesos;
    int longitud;
};

struct TortuNinja{
    char *nombre; 
    int capacidadMaxima;
    Lista* camiones[2];
    int cantidadCamiones = 0;
};
#endif /* ESTRUCTURAS_H */

