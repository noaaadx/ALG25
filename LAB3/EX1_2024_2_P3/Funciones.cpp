/* 
 * File:   Funciones.cpp
 * Author: USUARIO
 * 
 * Created on 16 de mayo de 2025, 10:55 PM
 */

#include "Funciones.hpp"
#include "Estructuras.h"
#include <iostream>
using namespace std;

Nodo *crearNodo(int dato){
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->elemento = dato;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

bool esNodoVacio(Nodo *nodo){
    return nodo == nullptr;
}

void construir(struct Lista &tad){
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

bool esListaVacia(struct Lista &tad){
    return tad.cabeza == nullptr;
}

void insertarAlInicio(struct Lista &tad, int elemento){
    Nodo *NuevoNodo = crearNodo(elemento);
    
    if(esListaVacia(tad)){
        tad.cabeza = NuevoNodo;
        tad.cola = NuevoNodo;
    }else{
        Nodo *aux;
        aux = NuevoNodo;
        NuevoNodo->siguiente = tad.cabeza;
        tad.cabeza = aux;
    }
    tad.longitud++;
}

void insertaAlFinal(struct Lista &tad, int elemento){
    Nodo *NuevoNodo = crearNodo(elemento);
    
    if(esListaVacia(tad)){
        tad.cabeza = NuevoNodo;
        tad.cola = NuevoNodo;
    }else{
        tad.cola->siguiente = NuevoNodo;
        tad.cola = NuevoNodo;
    }
    tad.longitud++;
}

void eliminarDatoLista(struct Lista &tad, int elemento){
    Nodo *recorrido = tad.cabeza;
    Nodo *nodoPrevio = nullptr;
    if(esListaVacia(tad)){
        return ;
    }else{
        while(!esNodoVacio(recorrido)){
            if(recorrido->elemento == elemento)break;
            nodoPrevio = recorrido;
            recorrido = recorrido->siguiente;
        }
        //eliminas
        if(nodoPrevio == nullptr){
            tad.cabeza = recorrido->siguiente;
            if(tad.cabeza == nullptr){
                tad.cola == nullptr;
            }else{
                nodoPrevio->siguiente = recorrido->siguiente;
                if(recorrido ==tad.cola){
                    tad.cola = nodoPrevio;
                }
            }
            delete recorrido;
            tad.longitud--;
       }
    }
}

void imprime(struct Lista &tad){
    Nodo *recorrido = tad.cabeza;
    while(!esNodoVacio(recorrido)){
        cout<<" -> "<<recorrido->elemento;
        recorrido = recorrido->siguiente;
    }
    cout<<endl;
}

void agregarConexion(struct Lista &tad,  int elemento){
    insertaAlFinal(tad, elemento);
}

void eliminarConexion(struct Lista &tad, int elemento){
    eliminarConexion(tad, elemento);
}

void imprimirRed(Lista *arregloListas, int n_computadoras){
    for(int i=0; i<n_computadoras; i++){
        cout<<"Computadora "<<i +1<<": ";
        imprime(arregloListas[i]);
    }
}

bool hayEscalaPrivilegiosRec(Lista *arregloListas, int compA, int elemento){
    bool hayEscala = false;
    Nodo *recorrido = arregloListas[compA - 1].cabeza;
    while(!esNodoVacio(recorrido)){
        if(recorrido->elemento == elemento){
            hayEscala = true;
            break;
        }else{
            if(hayEscalaPrivilegiosRec(arregloListas, recorrido->elemento, elemento)){
                return true;
            }
        }
        recorrido = recorrido->siguiente;
    }
    return hayEscala;
}