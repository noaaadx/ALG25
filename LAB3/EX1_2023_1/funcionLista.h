/* 
 * File:   funcionLista.h
 * Author: USUARIO
 *
 * Created on 17 de mayo de 2025, 06:20 AM
 */

#ifndef FUNCIONLISTA_H
#define FUNCIONLISTA_H
using namespace std;

void construir(struct Lista & tad);
bool esListaVacia(const struct Lista & tad);
int longitud(const struct Lista  & tad);
struct Nodo *crearNodo(int dato);
void insertaAlFinal(struct Lista &tad, int elemento);
void imprimirLista(struct Lista &tad);

#endif /* FUNCIONLISTA_H */
