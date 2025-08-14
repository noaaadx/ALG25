/* 
 * File:   funcionesPila.cpp
 * Author: ANA RONCAL
 * 
 * Created on 20 de abril de 2025, 19:56
 */

#include <iostream>
#include "Elemento.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
using namespace std;


/*constructor de Pila*/
void construir(struct Pila & pila) {
    construir(pila.lista);
}

/*Determina si la pila estÃ¡ vacÃ­a*/
bool esPilaVacia(const struct Pila & pila) {
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(const struct Pila & pila) {
    return longitud(pila.lista);
}

/* Push, aÃ±ade un elemento a la parte superior de la pila */
void apilar(struct Pila & pila, const struct Elemento & elemento) {
    insertarAlInicio(pila.lista, elemento);
    cout << "Apilando: " << elemento.numero << endl;
}

/* Pop, elimina un elemento de la parte superior de la pila*/
struct Elemento desapilar(struct Pila & pila) {

    if (esPilaVacia(pila)) {
        cout << "La pila está vací­a, por lo tanto no se puede desapilar" << endl;
        exit(11); // valor de salida que indica que existe un error
    }

    struct Elemento elemento = cima(pila);
    eliminaCabeza(pila.lista);
    return elemento;

}

/*examina un elemento situado en la parte superior de la pila*/
struct Elemento cima(const struct Pila & pila) {

    if (esPilaVacia(pila)) {
        cout << "La pila está vací­a por lo tanto no posee cima" << endl;
        exit(12); // valor de salida que indica que existe un error
    }
    return retornaCabeza(pila.lista);
}

/*destruye la pila*/
void destruirPila(struct Pila & pila) {
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/

/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila) {
    if (esPilaVacia(pila)) {
        cout << "La pila está vacía no se puede mostrar" << endl;
    } else
        imprime(pila.lista);
}

/*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    struct Elemento elemento;
//    while(not esPilaVacia(pila)){
//        elemento = cima(pila);
//        cout << elemento.numero << " ";
//        desapilar(pila);
//    }
//}
