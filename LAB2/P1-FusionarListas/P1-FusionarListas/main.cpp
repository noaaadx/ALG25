#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"

struct Lista fusionarListasIterativa(struct Lista &lista1, struct Lista &lista2) {
    // Caso base: si una de las listas es nula, devolver la otra
    if (esListaVacia(lista1)) return lista2;
    if (esListaVacia(lista2)) return lista1;

    Nodo* actual = nullptr;
    Nodo* temp1 = lista1.cabeza;
    Nodo* temp2 = lista2.cabeza;
    
    struct Lista fusionada; 
    fusionada.longitud = lista1.longitud + lista2.longitud;
    
    // Determinar el primer nodo de la lista fusionada        
    if (temp1->elemento <= temp2->elemento) {
        fusionada.cabeza = temp1;
        temp1 = temp1->siguiente;
    } else {
        fusionada.cabeza = temp2;
        temp2 = temp2->siguiente;
    }    
    actual = fusionada.cabeza;

    // Mientras ambas listas tengan elementos
    while (temp1 != nullptr && temp2 != nullptr) {        
        if (temp1->elemento <= temp2->elemento) {
            actual->siguiente = temp1;
            temp1 = temp1->siguiente;
        } else {
            actual->siguiente = temp2;
            temp2 = temp2->siguiente;
        }
        actual = actual->siguiente;  // Avanzar en la lista fusionada
    }

    // Agregar el resto de la lista no vacía (si la hubiera)
    if (temp1 != nullptr) {
        actual->siguiente = temp1;
    } else {
        actual->siguiente = temp2;
    }    
    
    return fusionada;
}

// Función recursiva para fusionar dos listas ordenadas
Nodo* fusionarListasRec(Nodo* plista1, Nodo* plista2) {
    // Caso base: Si una de las listas es nula, devolver la otra
    if (plista1 == nullptr) return plista2;
    if (plista2 == nullptr) return plista1;

    // Determinar cuál lista tiene el pedido con menor hora y continuar fusionando recursivamente
    if (plista1->elemento <= plista2->elemento) {
        plista1->siguiente = fusionarListasRec(plista1->siguiente, plista2);
        return plista1;
    } else {
        plista2->siguiente = fusionarListasRec(plista1, plista2->siguiente);
        return plista2;
    } 
}

struct Lista fusionarListas(struct Lista &lista1, struct Lista &lista2){
    struct Lista fusionada; 
    fusionada.longitud = lista1.longitud + lista2.longitud;
    fusionada.cabeza = fusionarListasRec(lista1.cabeza, lista2.cabeza);
    return fusionada;
}

int main(int argc, char** argv) {
    
    struct Lista lunes;
    struct Lista martes;
    struct Lista miercoles;
    struct Lista jueves;
    struct Lista viernes;
    
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
   
    insertarAlFinal(lunes, 8);
    insertarAlFinal(lunes, 10);
    insertarAlFinal(lunes, 12);
    
    insertarAlFinal(martes, 9);
    insertarAlFinal(martes, 11);
    
    insertarAlFinal(miercoles, 8);
    insertarAlFinal(miercoles, 9);
    insertarAlFinal(miercoles, 10);
    
    insertarAlFinal(jueves, 14);
    insertarAlFinal(jueves, 15);
    insertarAlFinal(jueves, 16);
    
    insertarAlFinal(viernes, 17);
    insertarAlFinal(viernes, 18);
    insertarAlFinal(viernes, 19);
    
    // Fusionar las listas
    struct Lista fusionada;
    fusionada = fusionarListas(lunes, martes);
    fusionada = fusionarListas(fusionada, miercoles);
    fusionada = fusionarListas(fusionada, jueves);
    fusionada = fusionarListas(fusionada, viernes);
    
    // imprimir lista
    imprime(fusionada);    
    
    return 0;
}

