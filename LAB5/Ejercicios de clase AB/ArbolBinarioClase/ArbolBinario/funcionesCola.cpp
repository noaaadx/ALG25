/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * 
 * Created on 5 de mayo de 2025, 10:55
 */

#include <iostream>
#include "Elemento.h"
#include "Cola.h"
#include "NodoArbol.h"
#include "funcionesLista.h"
#include "funcionesCola.h"

using namespace std;

/*constructor de Cola*/
void construir(struct Cola & cola){
    construir(cola.lista); //se inicializa el puntero cola
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, struct NodoArbol * nodo){
    //cout <<"Encolando... " <<elemento.numero << endl;
    insertarAlFinal(cola.lista, nodo); // se utiliza el puntero cola
}

struct NodoArbol * desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    struct NodoArbol * nodo = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return nodo;
}

void imprimir(const struct Cola & cola){
    imprimir(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}
