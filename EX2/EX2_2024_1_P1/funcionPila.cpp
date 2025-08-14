#include <iostream>
#include "Pila.h"
#include "funcionPila.h"
#include "funcionLista.h"
using namespace std;

/*constructor de Pila*/
void construir(struct Pila & pila) {
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(const struct Pila & pila) {
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(const struct Pila & pila) {
    return longitud(pila.lista);
}

/*Push, añade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, const int &elemento) {
    insertarAlInicio(pila.lista, elemento);
    cout << "Apilando: " << elemento << endl;
}

/*Pop, elimina un elemento de la parte superior de la pila*/
int desapilar(struct Pila & pila) {
    if (esPilaVacia(pila)) {
        cout << "La pila está vacía, no se puede desapilar" << endl;
        exit(11);
    }

    int elemento = cima(pila);
    eliminaCabeza(pila.lista);
    return elemento;
}

/*Examina un elemento situado en la parte superior de la pila*/
int cima(const struct Pila & pila) {
    if (esPilaVacia(pila)) {
        cout << "La pila está vacía, no posee cima" << endl;
        exit(12);
    }
    return retornaCabeza(pila.lista); // asumimos que retornaCabeza ahora devuelve int
}

/*Destruye la pila*/
void destruirPila(struct Pila & pila) {
    destruir(pila.lista);
}

/*Mostrar los valores de la pila (sin modificarla)*/
void imprimir(const struct Pila & pila) {
    if (esPilaVacia(pila)) {
        cout << "La pila está vacía, no se puede mostrar" << endl;
    } else {
        imprime(pila.lista); // asumimos que imprime() puede mostrar una lista de enteros
    }
}
