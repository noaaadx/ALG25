/* 
 * File:   Funciones.hpp
 * Author: Sebastian
 * Codigo: 20213281
 * Created on 16 de mayo de 2025, 10:55 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>

#include "Estructuras.h"

Nodo *crearNodo(int dato);
bool esNodoVacio(struct Nodo);

void construir(struct Lista &tad);
bool esListaVacia(struct Lista &tad);
void insertarAlInicio(struct Lista &tad, int elemento);
void insertaAlFinal(struct Lista &tad, int elemento);
void eliminarDatoLista(struct Lista &tad, int elemento);
void imprime(struct Lista &tad);
void agregarConexion(struct Lista &tad,  int elemento);
void eliminarConexion(struct Lista &tad, int elemento);
void imprimirRed(Lista *arregloListas, int n_computadoras);
bool hayEscalaPrivilegiosRec(Lista *arregloListas, int compA, int elemento);
    
#endif /* FUNCIONES_HPP */
