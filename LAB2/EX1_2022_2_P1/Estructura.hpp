/* 
 * File:   Estructura.hpp
 * Author: USUARIO
 *
 * Created on 2 de mayo de 2025, 11:52 PM
 */

#ifndef ESTRUCTURA_HPP
#define ESTRUCTURA_HPP

struct Pedido{
    int hora;
    int sucursal;
};

struct Nodo{
    struct Pedido Elemento;
    struct Nodo *sig;
};

struct Lista{
    struct Nodo *cabeza;
    struct Nodo *cola;
    int longitud;
};

#endif /* ESTRUCTURA_HPP */

