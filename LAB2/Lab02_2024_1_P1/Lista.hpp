/* 
 * File:   Lista.hpp
 * Author: USUARIO
 *
 * Created on 2 de mayo de 2025, 06:49 PM
 */

#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"

struct Lista{
    struct Nodo *cabeza;
    struct Nodo *cola;
    struct Nodo *colaMay;
    struct Nodo *colaMen;
    int longitud;
};
#endif /* LISTA_HPP */

