/* 
 * File:   FuncionLista.cpp
 * Author: USUARIO
 * 
 * Created on 2 de mayo de 2025, 11:56 PM
 */

#include "FuncionLista.hpp"
#include "Estructura.hpp"
using namespace std;

void construir(struct Lista &tad){
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

bool esListaVacia(const struct Lista &tad){
    return (tad.cabeza == nullptr);
}

int longitud(const struct Lista &tad){
    return tad.longitud;
}

struct Nodo *CrearNodo(struct Pedido elemento, struct Nodo *sig){
    struct Nodo* nuevoNodo = new struct Nodo;
    nuevoNodo->Elemento = elemento;
    nuevoNodo->sig = sig;
    return nuevoNodo;
}

void insertarEnOrden(struct Lista &tad, struct Pedido pedido){
    struct Nodo *NodoAnterior = ObtenerNodoAnterior(tad, pedido);
    struct Nodo *NuevoNodo = CrearNodo(pedido, nullptr);
    if(NodoAnterior == nullptr){
        NuevoNodo->sig = tad.cabeza;
        tad.cabeza = NuevoNodo;
        if(tad.cabeza->sig == nullptr)tad.cola = NuevoNodo;
    }else{
        NuevoNodo->sig = NodoAnterior->sig;
        NodoAnterior->sig = NuevoNodo;
        if(NuevoNodo->sig == nullptr)tad.cola =NuevoNodo;
    }
    tad.longitud++;
}

struct Nodo*ObtenerNodoAnterior(struct Lista &tad, struct Pedido pedido){
    struct Nodo *Anterior = nullptr;
    struct Nodo *recorrido = tad.cabeza;
    while((recorrido != nullptr) and (recorrido->Elemento.hora < pedido.hora)){
        Anterior = recorrido;
        recorrido = recorrido->sig;
    }
    return Anterior;
}

void InsertarFinal(struct Lista &tad, struct Pedido pedido){
    struct Nodo *UltimoNodo = ObtenerUltimoNodo(tad);
    struct Nodo *NuevoNodo = CrearNodo(pedido, nullptr);
    if(UltimoNodo == nullptr){
        
    }
} 
