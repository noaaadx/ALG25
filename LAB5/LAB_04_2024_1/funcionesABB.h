/* 
 * File:   funcionesABB.h
 * Author: USUARIO
 *
 * Created on 2 de julio de 2025, 01:05 AM
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H

void construir(struct ArbolBinarioBusqueda & arbol);

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento);
void insertarRecursivo(struct NodoArbol *& raiz, int elemento);

void enOrden(const struct ArbolBinarioBusqueda & arbol);

bool buscar(const struct ArbolBinarioBusqueda & arbol, int dato);
bool buscarRecursivo(struct NodoArbol * nodo, int dato);
int comparaABB(int elementoA, int elementoB);


void eliminar(struct ArbolBinarioBusqueda & arbol, int dato);
struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, int elemento);
struct NodoArbol * minimoArbol(struct NodoArbol * nodo);

#endif /* FUNCIONESABB_H */
