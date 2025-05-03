/* 
 * File:   Estructura.hpp
 * Author: USUARIO
 *
 * Created on 2 de mayo de 2025, 06:39 PM
 */

#ifndef NODO_HPP
#define NODO_HPP

struct Paciente{
    int fecha;
    char codigo[7];
};

struct Nodo{
    struct Paciente Elemento;
    struct Nodo *siguiente;
};


#endif /* NODO_HPP */

