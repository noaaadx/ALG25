/* 
 * File:   FuncionLista.h
 * Author: USUARIO
 *
 * Created on 2 de mayo de 2025, 06:55 PM
 */

#ifndef FUNCIONLISTA_H
#define FUNCIONLISTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void construir(Lista &tad);
const bool esListaVacia(const struct Lista &tad);
int longitud(struct Lista &tad);
void insertaEnCola(struct Lista &tad, struct Paciente elemento);
struct Nodo *crearNodo(struct Paciente elemento, struct Nodo *siguiente);
int retornaCabeza(const struct Lista  &tad);
void eliminaCabeza(struct Lista &tad);
void eliminaCola(struct Lista &tad);
void destruir(struct Lista &tad);
void imprimir(const struct Lista &tad);
void imprimirFecha(struct Nodo *recorrido);
int obtenerEdad(struct Nodo *paciente);

#endif /* FUNCIONLISTA_H */
