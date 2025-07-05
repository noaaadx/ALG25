/* 
 * File:   funcionesCola.h
 * Author: anaro
 *
 * Created on 5 de mayo de 2025, 10:55
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H
void construir(struct Cola & );       
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, struct NodoArbol *);
void imprimir(const struct Cola & cola);
struct NodoArbol * desencolar(struct Cola & cola);
void destruirCola(struct Cola & cola);
#endif /* FUNCIONESCOLA_H */
